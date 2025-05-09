#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main() {
    // PID (Process ID) : Identifiant unique du processus.
    pid_t PID = getpid();
    char msg1[100];
    int len1 = sprintf(msg1, "L’identifiant du processus en cours (PID) est : %d\n", PID);
    write(1, msg1, len1);

    // PPID (Parent Process ID) : Identifiant du processus parent.
    pid_t PPID = getppid();
    char msg2[100];
    int len2 = sprintf(msg2, "L’identifiant du processus parent est : %d\n", PPID);
    write(1, msg2, len2);

    // UID (User ID) : Identifiant de l'utilisateur propriétaire du processus.
    uid_t UID = getuid();
    char msg3[100];
    int len3 = sprintf(msg3, "L’identifiant d'utilisateur est : %d\n", UID);
    write(1, msg3, len3);

    // GID (Group ID) : Identifiant du groupe associé au processus.
    gid_t GID = getgid();
    char msg4[100];
    int len4 = sprintf(msg4, "L’identifiant de groupe est : %d\n", GID);
    write(1, msg4, len4);

    return 0;
}
