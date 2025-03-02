#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdio.h>

void ls(const char *pathname);

int main(int argc, char *argv[]){
    
    if (argc == 1) {
        ls(".");
        return 0;
    }
    
    for (++argv; *argv != NULL; ++argv) {
        if (argc > 2) printf("%s:\n", *argv);
        ls(*argv);
        if (*(argv + 1) != NULL)
            printf("\n");
    }
    return 0;
}

    
    
    
    
    
void ls(const char *pathname){
    DIR *dir = opendir(pathname);
    
    if (dir == NULL) {
        perror("opendir");
        return;
    }
    struct dirent *ent;
    
    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_name[0] != '.') printf("%s\n", ent->d_name);
    }
    closedir(dir);
}

