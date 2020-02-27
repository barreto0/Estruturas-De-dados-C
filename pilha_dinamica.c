#include <stdio.h>
#include <stdlib.h>


typedef struct{

   int quant;
   int *elemento;

}pilha;

pilha*aloca();
void push(pilha*p, int x);
int pop(pilha*p, int x);
void mostrar(pilha*p);

int main()
{
    pilha * p;
    p = aloca();
    push(p,10);
    push(p,20);
    push(p,30);
    printf("%d\n", p->quant);
    mostrar(p);

    return 0;
}

pilha *aloca(){

    pilha *aux;
    aux = (pilha*)malloc(sizeof(pilha));
    aux-> quant=0;
    aux-> elemento=NULL;
    return aux;

}


void push(pilha*p, int x)
{
    int * aux;
    if(p->quant==0){
        p->elemento = (int*)malloc(sizeof(int));

    }else{

        aux = (int*)realloc(p->elemento, (p->quant+1)*sizeof(int));
        p->elemento=aux;

    }
    p->elemento[p->quant]=x;
    p->quant++;

}


int pop(pilha*p, int x)
{
    int retornado;
    int *aux;
    if(p-> quant==0){
        printf("Pilha Vazia/n");
        retornado = 0;
    }
    else{
        retornado=p->elemento[p->quant-1];
        if(p->quant==1)
        {
            free(p->elemento);

        }else{
            aux = (int*)realloc(p->elemento, (p->quant-1)*sizeof(int));

        }
        p->elemento=aux;
        p->quant--;
    }
    return retornado;
}

void mostrar(pilha*p){
    int i;
    if(p->quant==0){
        printf("Pilha Vazia\n");
    }else{
        printf("Mostrando...\n");
        for(i=p->quant;i>=0;i--){

            printf("%d\n", p->elemento[i]);
        }


    }


}
