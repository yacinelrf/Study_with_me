#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s n cmd arg1 ... argk\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "Erreur: n doit être un entier positif\n");
        return 1;
    }

    int last_status = 0;  // Stocke le statut de la dernière commande exécutée

    for (int i = 0; i < n; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            return 1;
        } else if (pid == 0) {  // Processus enfant
            execvp(argv[2], &argv[2]);
            perror("execvp"); // Affiche une erreur si exec échoue
            exit(127);
        }
    }

    // Le parent attend tous les enfants
    for (int i = 0; i < n; i++) {
        int status;
        pid_t child_pid = wait(&status);

        if (child_pid > 0) {
            if (WIFEXITED(status)) {
                last_status = WEXITSTATUS(status);
            } else if (WIFSIGNALED(status)) {
                last_status = 128 + WTERMSIG(status);
            }
        }
    }

    return last_status;
}
