#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main (){
pid_t  PID =getpid();
pid_t PPID=getppid();
uid_t UID=getuid();
uid_t GID=getgid();

printf("Identifiant unique du processus est %d\n",PID );
printf("Identifiant du processus parent %d\n",PPID);
printf("Identifiant de l'utilisateur propriétaire du processus %d\n",UID);
printf("Identifiant du groupe associé au processus %d\n ",GID);

return 0; 
}

