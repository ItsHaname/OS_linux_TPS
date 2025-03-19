#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
 int main (){
 pid_t PID =fork();
if (PID==0){
 printf("je suis le processus enfant mon id est %d et user id est %d et et groupe id est %d\n",getpid(),getuid(),getgid());
fflush(stdout);  // Forcer l'affichage immédiat
}else if(PID>0){
 //wait(NULL);//
waitpid(PID, NULL, 0); // Le parent attend spécifiquement que l'enfant avec PID soit terminé
printf("je suis le processus parent mon id est %d et user id est %d et groupe id est %d et le processus fils id est %d\n",getppid(),getuid(),getgid(),getpid());
fflush(stdout);  // Forcer l'affichage immédiat
} else{
 printf("ERREUR FORK !!!");
return -1;
}
return 0 ;
}
/*L'affichage simultané des deux blocs (printf pour le processus parent et enfant) dans ton programme est probablement dû à la rapidité d'exécution des processus et au fait qu'ils ne sont pas synchronisés de manière optimale. Même si tu appelles wait() dans le processus parent, cela n'empêche pas l'exécution rapide des deux blocs dans le terminal, surtout si le processus enfant termine très rapidement.*/
/*L'appel à wait() dans le processus parent permet d'attendre la fin du processus enfant, mais cela ne garantit pas que les sorties de printf s'affichent dans un ordre spécifique. L'ordonnancement des processus est géré par le système d'exploitation, et il peut arriver que le processus parent affiche son message avant ou après le processus enfan*/

//fflush(stdout) : Cela force le vidage du buffer de sortie de stdout, assurant que le texte est effectivement imprimé immédiatement, plutôt que d'attendre la fin de l'exécution du programme.
//Oui, c'est tout à fait normal que les deux blocs s'affichent presque en même temps dans ce genre de programme. Cela s'explique par la manière dont les processus sont gérés par le système d'exploitation.
