/*
 * geraArquivo.h
 *
 *  Created on: Nov 17, 2008
 *      Author: gabriel
 */

#ifndef GERAARQUIVO_H_
#define GERAARQUIVO_H_

typedef struct Registro{
	char matricula[9];
	char nome[101];
}registro;


void geraArquivoReg(void);

static const int TAMANHO_MAXIMO_NOME=101;
static const int TAMANHO_MATRICULA=9;
static const int TAMANHO_REGISTRO=110;

#endif /* GERAARQUIVO_H_ */
