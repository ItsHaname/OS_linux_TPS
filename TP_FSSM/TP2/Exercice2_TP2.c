#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
 int main (){
 pid_t PID =fork();
if (PID==0){
 printf("je suis le processus enfant mon id est %d et user id est %d et ;e groupe id est %d",getpid(),getuid(),getgid());
}else if(PID>0){
wait();
printf("je suis le processus parent mon id est %d et user id est %d et groupe id est %d et le processus fils id est %d",getppid(),getuid(),getgid(),getpid());
} else{
 printf("ERREUR FORK !!!");
return -1;
}
return 0 ;
}
// avant d'ajouter la fonction wait j'ai remarque que les deux block s'executent au mem temps c-a-d que PID =0 et PID > 0 au meme temps !!!??
/* mais Fork : Lorsqu'un appel à fork() est effectué, il crée un processus fils, et les deux processus (parent et enfant) exécutent le code après fork(). Cela signifie qu'ils s'exécutent en parallèle
et chacun va entrer dans son propre bloc conditionnel :*/
/*Affichage des résultats : Comme les deux processus s'exécutent presque en même temps, les sorties de leurs printf() peuvent s'intercaler dans l'ordre d'exécution, ce qui peut conduire à un affichage simultané
 dans ton terminal.*/
// la solution//
// il faurt que le  parent attendre jusqu'a cd que le processus enfant termine son affichage //
// don on va utuliser wait ()//

