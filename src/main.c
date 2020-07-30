#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>


int eh_primo(int a){
    int i;
    if(a==1||a==0)
	return 0;
    for(i=2;i<a/2;i++)
	if(a%i==0)

    	    return 0;
    return 1;
	}

int main() { 
   int v[1000];    /*vetor que armazana os numeros*/	
   int i,n,N;


    while(scanf("%d\n", &v[i])==1){             /*loop de armazenamento*/
    	printf("o numero armazanado e %d   \n",v[i]);
	i++;
    	}
   n=i-1;
printf("n = %d\n",n);

for (i=0;i<3&&i<n; i++) /*determina quantos processos filhos criar*/
	;
N=i;
printf("N = %d\n",N);
pid_t filho[N];


  int protection = PROT_READ | PROT_WRITE;
  int visibility = MAP_SHARED | MAP_ANON;
  
  int *b,*c;
  b = (int*) mmap(NULL, sizeof(int)*100, protection, visibility, 0, 0);
  if ((long int)b==-1) printf("Erro de alocacao!\n");
  (*b)=0;/*variavel compartilhada que conta os numeros primos*/
   c = (int*) mmap(NULL, sizeof(int)*100, protection, visibility, 0, 0);
  if ((long int)c==-1) printf("Erro de alocacao!\n");
  (*c)=0;/*variavel que faz o vetor de nuemros andar*/
 

for (i=0;i<N; i++){ /*cria processos filhos*/
    filho[i] = fork();}



    do{      /*loop de contagem*/
 	if(filho[0]==0){
		printf("Processo filho[0] analisa %d e c = %d\n",v[*c],*c);
		 if(eh_primo(v[*c]))
      		(*b)++;
                (*c)++;}
	if(filho[1]==0){
		printf("Processo filho[1] analisa %d c = %d\n",v[*c],*c);
		 if(eh_primo(v[*c]))
      		(*b)++;
                (*c)++;}
	if(filho[2]==0){
		printf("Processo filho[2] analisa %d e c =%d \n",v[*c],*c);
		 if(eh_primo(v[*c]))
      		(*b)++;
                (*c)++;}
      
 	if(filho[i]!=0){
	printf("Processo pai analisa %d e c = %d\n",v[*c],*c);
	sleep(1);
	if(eh_primo(v[*c]))
        	(*b)++;
        (*c)++;
  	} 

 } while((*c)<n);   /*encerra os processos filhos*/
  for (int i=0; i<=N; i++) 
	if(filho[i]==0)
		exit(0);

for (int i=0; i<N; i++) 
    waitpid(filho[i], NULL, 0);


 printf("Temos %d numeros primos\n",*b);

  return 0;

}













