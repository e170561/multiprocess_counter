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
    for(i=2;i<=a/2;i++)
	if(a%i==0)

    	    return 0;
    return 1;
	}

int main() { 
   int v[1000];    /*vetor que armazana os numeros*/	
   int i,n,N;


    while(scanf("%d\n", &v[i])==1){             /*loop de armazenamento*/
	i++;
    	}
   n=i;

for (i=0;i<n-1&&i<3; i++) /*determina quantos processos filhos criar*/
	;
N=i-1;
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
 
for(i=0;i<=N;i++){ /*cria processos filhos*/ 
   filho[i] = fork();
   
   if(filho[i]==0){
	while(*c<n){
	
	if(eh_primo(v[*c])){
	(*b)++;}
	(*c)++;
	sleep(1);}
	exit(0);}}
	
	

for (i=0; i<=N; i++) 
    waitpid(filho[i], NULL, 0);

while(*c<n){
	if(eh_primo(v[(*c)++]))
   	(*b)++;
	}
    
printf("%d\n",*b);

return 0;

}

