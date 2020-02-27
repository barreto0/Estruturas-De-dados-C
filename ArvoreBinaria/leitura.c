/*
 * leitura.c
 *
 *  Created on: Nov 17, 2008
 *      Author: gabriel
 */

#include <stdio.h>
#include <string.h>

void limpabuffer(void){
	int ch;
	while((ch=fgetc(stdin))!=EOF && ch != (int)'\n'){}					/*funcao para limpeza de buffer*/
	return;
}

/*O motivo de retornar um char é para a função
 * ter a mesma semântica de fgets que também
 * retorna a string lida*/

char* myfgets(char* str,int size){
	fgets(str,size,stdin);
	if(str[strlen(str)-1]=='\n'){
		str[strlen(str)-1]='\0'; /*trocar o \n por \0 caso exista o \n*/
	}
	else{
		limpabuffer();
	}
	return (str);
}
