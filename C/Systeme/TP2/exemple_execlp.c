#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <chemin>\n", argv[0]);
        return 1;
    }

    // Premier enfant : ls argv[1]
    pid_t pid1 = fork();
    if (pid1 == -1) {
        perror("fork");
        return 1;
    } else if (pid1 == 0) {
        execlp("ls", "ls", argv[1], NULL);
        perror("execlp ls");
        return 1;
    }

    wait(NULL); // Attendre la fin de ls

    // Deuxième enfant : du -sh argv[1]
    pid_t pid2 = fork();
    if (pid2 == -1) {
        perror("fork");
        return 1;
    } else if (pid2 == 0) {
        execlp("du", "du", "-sh", argv[1], NULL);
        perror("execlp du");
        return 1;
    }

    wait(NULL); // Attendre la fin de du

    // Le parent devient df argv[1]
    execlp("df", "df", argv[1], NULL);
    perror("execlp df");
    return 1;
}
