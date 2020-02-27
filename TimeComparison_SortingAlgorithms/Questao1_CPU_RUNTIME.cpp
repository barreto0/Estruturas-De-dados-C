//rand, lacço de repetiçao ate N, fwrite

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
//teste com hora do sistema

/*
int main()
{
int i;

printf("Hora:%s\n\n",__TIME__);

for(i=0;i<1000;i++)  //teste pra gastar tempo
{
	printf("%d", i);
}

printf("Hora:%s\n\n",__TIME__);


}
*/

// teste com quantos pulsos de clock levou


int main () {


     struct timeval st , et;
     gettimeofday(&st , NULL);
     
     sleep(2);	//função que será cronometrada
     
     gettimeofday(&et , NULL);
     printf("\nTEMPO TOTAL GASTO : %lu SEGUNDOS e  %lu MICROSEGUNDOS\n",(et.tv_sec - st.tv_sec),(et.tv_usec - st.tv_usec));
     return 0;


   return(0);
}
