#include <stdio.h>
#include <stdlib.h>

void bubblesort( int vetor[], int qtd );

int main()
{
    int i;
    int vet[10]={413,210,780,28,345,610,21,6,1050,500};
    
	bubblesort(vet,10);

    for(i=0;i<10;i++)
    {
        printf(" %d ",vet[i]);
    }
    return 0;
}

void bubblesort( int vetor[], int qtd )
{
  int i;
  int j;
  int aux;
  int k = qtd - 1 ;

  for(i = 0; i < qtd; i++)
  {
     for(j = 0; j < k; j++)
     {
        if(vetor[j] > vetor[j+1])
        {
            aux = vetor[j];
        vetor[j] = vetor[j+1];
        vetor[j+1]=aux;
        }
     }
     k--;
  }
}
