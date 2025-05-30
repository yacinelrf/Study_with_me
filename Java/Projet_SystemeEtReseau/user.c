/*  yacine LARFI 12308716
Je déclare qu'il s'agit de mon propre travail.
Ce travail a été réalisé intégralement par un être humain. */

#include "user.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>


/** accepter une connection TCP depuis la socket d'écoute sl et retourner un
 * pointeur vers un struct user, dynamiquement alloué et convenablement
 * initialisé */
struct user *user_accept(int sl)
{

	struct user *us = malloc(sizeof(struct user));
	if(us==NULL){
		perror("malloc user");
		return NULL;
	}

	us->address = malloc(sizeof(struct sockaddr_in));
	if (us->address == NULL) {
		perror("malloc address");
		free(us);
		return NULL;
	}


	us->addr_len = sizeof(struct sockaddr_in);


	us->sock = accept(sl, (struct sockaddr *) us->address, &us->addr_len);
	if(us->sock<0){
		perror("sock");
		free(us->address);
		free(us);
		return NULL;
	}
	
	return us;

}

/** libérer toute la mémoire associée à user */
void user_free(struct user *user)
{
	free(user->address);
	close(user->sock); 
	free(user);
}
