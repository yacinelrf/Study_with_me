/* Yacine LARFI 12308716
Je déclare qu'il s'agit de mon propre travail.
Ce travail a été réalisé intégralement par un être humain. */

#include "buffer.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct buffer {

	int fd;             
	char *data;			 
	size_t pos;			
	size_t length;		
	size_t size;		
	int oef;			
	int ungot;

};

buffer *buff_create(int fd, size_t buffsz)
{
	struct buffer *buff = malloc(sizeof(struct buffer));
	if (!buff) return NULL;
	buff->fd = fd;
	buff->size = buffsz;
	buff->data = malloc(buffsz);
	if (!buff->data){
		free(buff->data);
		return NULL;
	}
	buff->length = 0;
	buff->pos = 0;
	buff->oef = 0;
	buff->ungot = -2; 
	return buff;
}

int buff_getc(buffer *b)
{
	if (b->ungot != -2){
		int i = b->ungot;
		b->ungot = -2;
		return i;
	}

	if (b->pos >= b->length){
		ssize_t n = read(b->fd, b->data, b->size);
		if (n < 0) return EXIT_FAILURE;
		if (n == 0){
			b->oef = 1;
			return EOF;
		}
		b->length = n;
		b->pos = 0;
	}

	return b->data[b->pos++];

}

int buff_ungetc(buffer *b, int c)
{
	if (b->ungot != -2 || c == EOF) return EOF;
	b->ungot = c;
	return c;
}

void buff_free(buffer *b)
{
	if (!b) return;
	free(b->data);
	free(b);
}

int buff_eof(const buffer *buff)
{
	return buff->oef && buff->pos >= buff->length && buff->ungot == -2;
}

int buff_ready(const buffer *buff)
{
	return (buff->ungot != -2) || (buff->pos < buff->length);
}

char *buff_fgets(buffer *b, char *dest, size_t size)
{
	if (!b || !dest || size < 2) return NULL;
	int i;
	size_t c = 0;
	while (c+1 < size && (i = buff_getc(b)) != EOF){
		dest[c++] = i;
		if (i == '\n') break; 
	}
	if (c==0) return NULL;
	dest[c] = '\0';
	return dest;
}

char *buff_fgets_crlf(buffer *b, char *dest, size_t size) {
	
    if (b == NULL || dest == NULL || size == 0) {
        return NULL;  
    }
    size_t i = 0;
    int prev_c = -1;  
    
    while (i < size - 1) {

        int c = buff_getc(b); 

        if (c == -1) {

            if (i == 0) {
                return NULL;  
            }
            break;  
        }

        dest[i++] = (char)c;

        
        if (prev_c == '\r' && c == '\n') {
            break;
        }

        
        prev_c = c;
    }

    dest[i] = '\0';  

    return dest;
}
