/*Écrivez un programme en C qui crée un nouveau processus fils à
l'aide de la fonction fork() et il affiche des informations spécifiques à
chaque processus (parent et fils) :

✓ Le processus parent récupère son propre PID, UID, et GID ainsi
que le PID de son processus fils.
✓ Le processus fils affiche son propre PID, UID, et GID.*/
#include<stio.h>
#include<unistd.h>
#include<sys/types.h>
int main (){
int P_fils=fork();
if(P_fils == 0){
  printf("=======Je susi le preocessus fils=======");
   printf("mon PID est : %d \n mon PPID est:%d \n mon UID est : \n et mon GID est %d /n ", getpid(), getppid() , getuid() , getgid() );
}else if(P_fils > 0 ){
   printf("=======Je susi le preocessus parent=======");
printf("mon PID est : %d \n mon PPID est:%d \n mon UID est : \n et mon GID e GID est %d /n ", getpid(), getppid() , getuid() , getgid() );
}else{
   printf("erreur");
} return 0 ;

