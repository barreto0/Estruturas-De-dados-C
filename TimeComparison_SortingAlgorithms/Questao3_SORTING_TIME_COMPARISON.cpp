#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#define MAX 100000

void quicksort(int vetor[], int ini, int fim);
void bubblesort( int vetor[], int qtd );
void merge(int vetor[], int l, int m, int r);
void mergeSort(int vetor[], int l, int r);


int main()
{
	FILE *arquivo;
	char nome[20];
	int i =0 , n =0 ,j=0 ,k=0;
	
	int numero;
	int vetor[MAX];
	
	
	printf("Insira o nome do arquivo a ser aberto: ");
	gets(nome);	
	
	arquivo = fopen(nome ,"rt");
  	
	  if (arquivo == NULL)
    {
      printf("POISE MEU PARSERIN PARECE QUE ALGUMA COISA DEU ERRADA AQUI HEIN\n");
      system("pause"); 
      
    }
    
//    while( fscanf(arquivo, "%d\n", &k) > 0 ) 
//    {
//       j++;
//    }
//	printf("QUANTIDADE: %d\n\n", j);
//	fscanf( arquivo , "%d", &tamanho);

	
	/*
	for (i = 0; i < tamanho; i++){
		
        fscanf(arquivo, "%d,", &numero );
        vetor[numero];
    }
	*/
	
//	fseek(arquivo, 4 , SEEK_SET);
	
	 while( fscanf(arquivo, "%d\n", &n) > 0 ) 
    {
        vetor[i++] = n;
    }
    
  //  for (i = 0; i < 10; i++)
//	{
  //      printf("Numeros: %d\n\n", vetor[i]);
 //   }
    
    int op;
    char op2;
    clock_t start_t, end_t, total_t;
    
    
    
	do
	{
	system("cls");
	printf(" GABRIEL ANTONIO DE VASCONCELLOS BARRETO - 1622082022       \n");
	printf(" -------------------- MENU DE ORDENACAO --------------------\n\n");
	printf(" -------------------- 1) BUBBLE SORT    --------------------\n");
	printf(" -------------------- 2) QUICK  SORT    --------------------\n");
	printf(" -------------------- 3) MERGE  SORT    --------------------\n");
	printf(" 4) IMPRIMIR VETOR ORDENADO (SOMENTE SE JA TIVER USADO UMA DAS OPCOES ACIMA!)\n");
	printf("          SENAO SERA IMPRIMIDO O VETOR AINDA DESORDENADO                     \n\n");
	printf(" -------------------- 5) SAIR           --------------------\n");
	scanf("%d", &op);
		
		
		switch(op)
		{
					case 1:
			
			printf("Ordenando por bubblesort...\n");
			
			 
			    struct timeval st , et;
     			gettimeofday(&st , NULL);
			
			 bubblesort(vetor, MAX );
			    /*
			     for(i=0;i<MAX;i++)
    				{
        			printf("%d, ", vetor[i]);
					}
				*/
				gettimeofday(&et , NULL);
    			 printf("\nTEMPO TOTAL GASTO : %lu SEGUNDOS e  %lu MICROSEGUNDOS\n",(et.tv_sec - st.tv_sec),(et.tv_usec - st.tv_usec));
			
					
			break;
			case 2:
				printf("Ordenando por quicksort...\n");
				
				
     			gettimeofday(&st , NULL);
				
				quicksort(vetor,0,MAX);
				   	
    			 gettimeofday(&et , NULL);
    			 printf("\nTEMPO TOTAL GASTO : %lu SEGUNDOS e  %lu MICROSEGUNDOS\n",(et.tv_sec - st.tv_sec),(et.tv_usec - st.tv_usec));
    				    /*				
					for(i=0;i<MAX;i++)
    				{
        			printf("%d, ",vetor[i]);
    				}
					*/
		
				break;
				case 3:
					printf("Ordenado por mergesort\n");
					
					gettimeofday(&st , NULL);
					
					mergeSort(vetor, 0, MAX - 1); 
					/*
					for(i=0;i<MAX;i++)
    				{
        			printf("%d, ",vetor[i]);
    				}
    				*/
    				gettimeofday(&et , NULL);
    			    printf("\nTEMPO TOTAL GASTO : %lu SEGUNDOS e  %lu MICROSEGUNDOS\n",(et.tv_sec - st.tv_sec),(et.tv_usec - st.tv_usec));
    				
					
					break;
					case 4:
						for(i=0;i<MAX;i++)
    					{
        				printf("%d, ",vetor[i]);
    					}	
						break;
						case 5:
							printf("Saindo...");
							
							break;
						default:
							printf("Opcao invalida");
							break;
		
		}	
	
		system("pause");
	}while(op!=5);	
	
	fclose(arquivo);
	return 0;
	
}

void quicksort(int vetor[], int ini, int fim)
{
    int pivo, aux,temp;

    if (ini==fim)
    {
        return ;
    }

    pivo = ini;
    aux  = fim;
    while(pivo!=aux)
    {
        if (pivo<aux)
        {
            if (vetor[pivo]> vetor[aux])
            {
                temp = vetor[pivo];
                vetor[pivo] = vetor[aux];
                vetor[aux] = temp;
                temp=pivo;
                pivo=aux;
                aux=temp;
            }


        }
        else
        {
            if (vetor[pivo]< vetor[aux])
            {
                temp = vetor[pivo];
                vetor[pivo] = vetor[aux];
                vetor[aux] = temp;
                temp=pivo;
                pivo=aux;
                aux=temp;
            }



        }
        if (pivo<aux)
        {
             aux--;
        }
        else
        {
            aux++;
        }

    }

    if (aux!=fim)
    {
        quicksort(vetor,aux+1,fim);
    }

    if (aux !=ini)
    {
        quicksort(vetor,ini,aux-1);
    }

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


/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */


/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
void mergeSort(int vetor[], int l, int r)
{
   if (l < r)
   {
      int m = l+(r-l)/2; //Same as (l+r)/2 but avoids overflow for large l & h
      mergeSort(vetor, l, m);
      mergeSort(vetor, m+1, r);
      merge(vetor, l, m, r);
   }
}

/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int vetor[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = vetor[l + i];
    for (j = 0; j < n2; j++)
        R[j] = vetor[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            vetor[k] = L[i];
            i++;
        }
        else
        {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        vetor[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        vetor[k] = R[j];
        j++;
        k++;
    }
}

