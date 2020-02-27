/*
 * arvore.h
 *
 *  Created on: Nov 14, 2008
 *      Author: gabriel
 */

#ifndef ARVORE_H_
#define ARVORE_H_

#define ORDEM 4

typedef struct Conjunto{
	int chave;
	int nrrPrincipal;
}tipo_conjunto;
typedef struct Pagina{

	int nada2[ORDEM];
	tipo_conjunto quadrado[(ORDEM-1)];
	int nada[ORDEM+ORDEM];

	int nrrPai;
	int nrrPropria;
	int contador;
	int nrrFilha[(ORDEM)];
}pagina;

typedef struct PaginaSplit{
	int nada2[ORDEM+1];
	tipo_conjunto quadrado[(ORDEM)];
	int nada[ORDEM+1];

	int nrrFilha[(ORDEM+1)];
	int nrrPai;
}paginaSplit;

typedef struct Associa{
	int chave;
	int nrrPrincipal;
}associa;




pagina InicializaPagina(void);
int OrdenaPagina(tipo_conjunto *);

#endif /* ARVORE_H_ */
