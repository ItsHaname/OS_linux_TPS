#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
printf("bonjour de PPID %d\n",getppid());
printf("Fin de PPID %d\n",getppid());
return 0;}

