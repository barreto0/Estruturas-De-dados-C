/*
 * geraArquivo.c
 *
 *  Created on: Nov 17, 2008
 *      Author: gabriel
 */

#include<stdio.h>
#include<string.h>
#include"geraArquivo.h"
#include "leitura.h"


void geraArquivoReg(){
	FILE *arquivoreg;
	registro usuario;
	char espaco=' ';
	char resposta;
	int size;

	arquivoreg=fopen("arquivoregistros.bin","ab");

	do{

		do{
		__fpurge(stdin);
		printf("\nDigite a matricula do usuario (OBRIGATORIAMENTE 8 DIGITOS): ");
		myfgets(usuario.matricula,TAMANHO_MATRICULA);
		size= strlen(usuario.matricula);
		}while (size!=(TAMANHO_MATRICULA-1));


		__fpurge(stdin);
		printf("\nDigite o nome do usuario: ");
		myfgets(usuario.nome,TAMANHO_MAXIMO_NOME);
		size = strlen(usuario.nome);
		while(size<TAMANHO_MAXIMO_NOME){
			usuario.nome[size] = espaco;
			size=size+1;
		}


		fwrite(&usuario,TAMANHO_REGISTRO,1,arquivoreg);
		__fpurge(stdin);
		printf("Deseja adicionar mais algum usuario? S ou N?");    /*opcao de realizar novas acoes antes do fechamento do programa*/
		scanf("%c",&resposta);
		getchar();

	}while((resposta=='s')||(resposta=='S'));

	fclose(arquivoreg);
	arquivoreg=fopen("arquivoregistros.bin","rb");
	while(!feof(arquivoreg)){
		fread(&usuario,TAMANHO_REGISTRO,1,arquivoreg);
		printf(" %s",usuario.matricula);
		printf(" %s",usuario.nome);
		getchar();
		getchar();
	}


	getchar();
	getchar();


}
