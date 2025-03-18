#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    // Récupération des informations du processus
    pid_t pid = getpid();    // Obtient l'ID du processus
    pid_t ppid = getppid();  // Obtient l'ID du processus parent
    uid_t uid = getuid();    // Obtient l'ID de l'utilisateur
    gid_t gid = getgid();    // Obtient l'ID du groupe

    // Affichage des informations
    printf("Informations du processus en cours :\n");
    printf("📌 PID  : %d\n", pid);
    printf("📌 PPID : %d\n", ppid);
    printf("👤 UID  : %d\n", uid);
    printf("👥 GID  : %d\n", gid);

    return 0;
}
