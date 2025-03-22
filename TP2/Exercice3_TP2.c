#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    // 1) Affiche un message de la forme "Bonjour PID", où PID est l’identifiant du processus courant.
    pid_t PID = getpid();
    char meg[100]; // Buffer pour stocker le message formaté

    /*
        Utiliser write() au lieu de printf()

        Déclaration du tableau de caractères :
        Tu déclares un tableau de caractères (par exemple, meg[100]), qui va contenir
        la chaîne de caractères formatée.

        Utilisation de sprintf() :
        Tu utilises sprintf() pour formater la chaîne que tu veux afficher et la stocker
        dans le tableau de caractères.

            Retour de sprintf() :
            sprintf() retourne la longueur du texte formaté, c'est-à-dire le nombre
            d'octets écrits dans le tableau (sans compter le caractère nul de fin).

        Utilisation de write() :
        Tu utilises ensuite write() pour afficher le message sur la sortie standard.

            Le descripteur de fichier (STDOUT_FILENO pour la sortie standard).
    */
    int len = sprintf(meg, "Bonjour %d\n", PID);
    write(STDOUT_FILENO, meg, len);

    // 2) Crée un nouveau processus grâce à l’appel système fork().
    pid_t nouveau_processus = fork();

    if (nouveau_processus == 0) {
        // Code exécuté par le processus enfant
        char msg[100];
        int ln = sprintf(msg, "Fin de PID %d (je suis l'enfant)\n", getpid());
        write(STDOUT_FILENO, msg, ln);
    } else if (nouveau_processus > 0) {
        // Code exécuté par le processus parent
        char msg[100];
        int ln = sprintf(msg, "Fin de PID %d (je suis le parent)\n", getpid());
        write(STDOUT_FILENO, msg, ln);
    } else {
        // Gestion d'erreur en cas d'échec de fork()
        perror("fork");
        return 1;
    }

    return 0;
}
