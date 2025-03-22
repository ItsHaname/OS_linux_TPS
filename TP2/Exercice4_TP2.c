#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    // 1) Affiche un message de la forme "Bonjour UID", où UID est l’identifiant (UID) du processus courant.
    char msg[100];
    int len = sprintf(msg, "Bonjour UID %d\n", getuid());
    write(STDOUT_FILENO, msg, len);

    // 2) Crée un nouveau processus grâce à l’appel système fork().
    pid_t processus = fork();

    // 3) Dans chaque processus (parent et enfant), affiche un second message de la forme "Fin de UID" pour indiquer la fin de l’exécution dans ce processus.
    if (processus == 0) {
        // Code exécuté par le processus enfant
        char msg_enfant[100];
        int len_enfant = sprintf(msg_enfant, "Fin de UID %d (je suis l'enfant)\n", getuid());
        write(STDOUT_FILENO, msg_enfant, len_enfant);
    } else if (processus > 0) {
        // Code exécuté par le processus parent
        char msg_parent[100];
        int len_parent = sprintf(msg_parent, "Fin de UID %d (je suis le parent)\n", getuid());
        write(STDOUT_FILENO, msg_parent, len_parent);
    } else {
        // Gestion d'erreur en cas d'échec de fork()
        printf("ERREUR DE CREATION DE PROCESSUS\n");
        return -1;
    }

    return 0;
}
