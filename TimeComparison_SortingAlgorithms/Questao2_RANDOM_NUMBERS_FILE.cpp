#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int main()
{
	FILE *arquivo;
	int numero;
	int i;
	
	
	printf("insira um numero: ");
	scanf("%d", &numero);
	
	arquivo = fopen("arquivoq2.txt" , "wt");
	
	if (arquivo == NULL) 
{
   printf("POISE MEU PARSERIN PARECE QUE ALGUMA COISA DEU ERRADA AQUI HEIN\n");
}
	
	srand ( time(NULL) );	
	
	
	for( i = 0 ; i < numero ; i++ ) 
	{
      fprintf (arquivo, "%d \n",  rand() % 1000);
    }

	fclose(arquivo);	
	
	return 0;
}



