#include<stdlib.h>
#include<stdio.h>

typedef struct elemento
{
	int valor;
	struct elemento*prox;
}elemento;

typedef struct pilha
{
	int quant;
	struct elemento * final;
}pilha;

elemento*aloca_elem();
pilha*aloca_pilha();

int main()
{
	pilha*p;
	p = aloca_pilha();
	return 0;
}

elemento*aloca_elem()
{
	elemento*aux;
	aux= (elemento*)malloc(sizeof(int));
	aux->valor=0;
	aux->prox=NULL;
	return aux;
}

pilha*aloca_pilha()
{
	pilha*aux;
	aux= (pilha*)malloc(sizeof(pilha));
	aux->quant=0;
	aux->final=NULL;
	return aux;
}

void push(pilha*p, int x)
{
	elemento*novo;
	novo = aloca_elem();
	novo->valor=x;
	if(p->quant==0)
	{
		p->final = novo;
	}
	else
	{
		novo->prox = p->final;
		p->final = novo;
		
	}
	p->quant++;
}

int pop(pilha*p)
{
	int numero;
	elemento*aux;
	if(p->quant==0)
	{
		printf("Pilha Vazia");
		return 0;
	}
	else
	{
		aux=p->final;
		p->final=aux->prox;
		numero = aux->valor;		
		free(aux);
		p->quant--;
		return numero;
	}
}









