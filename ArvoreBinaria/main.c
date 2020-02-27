/*
 * main.c
 *
 *  Created on: Nov 16, 2008
 *      Author: gabriel
 */
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "geraArquivo.h"
#include <string.h>

int nrrPagina=-1;
FILE *arqReg;
FILE *arqTree;
FILE *arqRaiz;

void main(){
	//geraArquivoReg();
	//createBtree();
	procuraRegistro();
	printf("PROGRAMA EXECUTADO COM SUUUUCESSO.");
	getchar();
	getchar();
}


int createBtree(){

	int i,chave,nrr;
	pagina p1,p2,p3;
	registro usuario;

	arqReg=fopen("arquivoregistros.bin","rb");
	arqTree=fopen("arquivoTree.bin","w+b");
	i=0;
	arqRaiz=fopen("nrrRaiz.bin","w+b");
	fwrite(&i,sizeof(int),1,arqRaiz);
	p1=InicializaPagina();


	printf("\nP1 INICIALIZA!!!!");
				printf("\n Chaves: ");
					for (i=0;i<=ORDEM-2;i++){
						printf(" %d",p1.quadrado[i].chave);
					}
					printf("\n NRR PRINCIPAIS: ");
									for (i=0;i<=ORDEM-2;i++){
										printf(" %d",p1.quadrado[i].nrrPrincipal);
									}
					printf("\nNrr Filhas: ");
					for (i=0;i<=ORDEM-1;i++){
							printf(" %d",p1.nrrFilha[i]);
						}
					printf("\nPai %d",p1.nrrPai);
					printf("\nContador %d",p1.contador);
					printf("\nNRR propria: %d",p1.nrrPropria);

					getchar();
					getchar();





	if(fwrite(&p1,sizeof(pagina),1,arqTree)!=1){
		printf("ERRO NA ESCRITA!");
		getchar();
		getchar();
	}
	i=0;
	while(!feof(arqReg)){
		__fpurge(stdin);
		if(fread(&usuario,sizeof(registro),1,arqReg)!=1){
			printf("ERRO NA LEITURA DO REGISTRO.");
			getchar();
			getchar();
			return 0;
		}
		chave=atoi(usuario.matricula);
		printf("\nChave: %d",chave);
		printf("\nNrrPrincipal: %d",i);
		getchar();
		getchar();
		Insere(chave,i);
		i=i+1;
	}
	fclose(arqRaiz);
	fclose(arqTree);
	fclose(arqReg);
	printf("ARVORE CRIADA!");
	getchar();
	getchar();
	return 0;

}

void Insere(int chave, int a){
	int div,divisor,i,k;
	pagina p1,p2,pPai;
	paginaSplit pSplit;
	associa a1[ORDEM-2];
	int nrrRaiz,PRR;
	int pai;

	fseek(arqRaiz,0,0);
	p1.nrrFilha[ORDEM-2];
	__fpurge(stdin);
	fread(&nrrRaiz,sizeof(int),1,arqRaiz);
	PRR=nrrRaiz*sizeof(pagina);
	printf("\nPRR DA RAIZ: %d",PRR);
	getchar();
	getchar();
	__fpurge(stdin);
	fseek(arqTree,PRR,0);
	if(fread(&p1,sizeof(pagina),1,arqTree)!=1){
		printf("ERROOO!!!");
		getchar();
		getchar();
	}

	printf("ANTES WHILE : %d",p1.nrrFilha[0]);
	getchar();
	getchar();
	while(p1.nrrFilha[0]>=0){
		i=0;

		printf("\nP1 'RAIZZZZ' ");
					printf("\n Chaves: ");
						for (i=0;i<=ORDEM-2;i++){
							printf(" %d",p1.quadrado[i].chave);
						}
						printf("\n NRR PRINCIPAIS: ");
										for (i=0;i<=ORDEM-2;i++){
											printf(" %d",p1.quadrado[i].nrrPrincipal);
										}
						printf("\nNrr Filhas: ");
						for (i=0;i<=ORDEM-1;i++){
								printf(" %d",p1.nrrFilha[i]);
							}
						printf("\nPai %d",p1.nrrPai);
						printf("\nContador %d",p1.contador);
						printf("\nNRR propria: %d",p1.nrrPropria);

			pai=p1.nrrPropria;
			i=0;
			while((chave>p1.quadrado[i].chave)&&(i<=ORDEM-2)&&(p1.quadrado[i].chave!=-1)){   //ATENCAO AQUI
			i=i+1;
		}






		if(i==0){
			PRR=p1.nrrFilha[0]*sizeof(pagina);
			printf("\nPRR antes de chamar a prox: %d",PRR);
		}else{
			printf("\nI: %d",i);

			PRR=p1.nrrFilha[i];//AQUIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
			printf("\nNNNNNNRR antes de chamar a prox: %d",PRR);
			PRR=PRR*sizeof(pagina);
		}
		fseek(arqTree,PRR,0);
		__fpurge(stdin);
		__fpurge(stdin);
		fread(&p1,sizeof(pagina),1,arqTree);

		if(p1.nrrPai!=pai){				//ATUALIZA OS PAIS E FILHOS
			p1.nrrPai=pai;
		}


		printf("\nP1 LIDA");
					printf("\n Chaves: ");
					for (i=0;i<=ORDEM-2;i++){
						printf(" %d",p1.quadrado[i].chave);
					}
					printf("\n NRR PRINCIPAIS: ");
					for (i=0;i<=ORDEM-2;i++){
						printf(" %d",p1.quadrado[i].nrrPrincipal);
					}
					printf("\nNrr Filhas: ");
					for (i=0;i<=ORDEM-1;i++){
						printf(" %d",p1.nrrFilha[i]);
					}







					printf("\nPai %d",p1.nrrPai);
					printf("\nContador %d",p1.contador);
					printf("\nNRR propria: %d",p1.nrrPropria);

					getchar();
					getchar();




	}//	GARANTE QUE CHEGOU AS FOLHAS!!!!!

	div=1; //DIV EH UM BOOLEANO QUE INDICA QUANDO A INSERCAO OCORRER SEM NENHUM SPLIT






	k=0;
	while(div==1){
		if(p1.contador<=ORDEM-2){	//HÁ ESPAÇO!
			div=0;
			if(k==1){
				a=nrrRaiz;
				k=0;
			}
			fseek(arqTree,PRR,0);
			p1.quadrado[p1.contador].chave=chave;
			p1.quadrado[p1.contador].nrrPrincipal=a;
			p1.contador=p1.contador+1;
	/*		if(p1.nrrFilha[0]==-1){                     //MEGA ATENCAO AQUI. CAMBIARRA!
				for(i=0;i<=ORDEM-1;i++){
					p1.nrrFilha[i]=-1;
				}
		*/		i=1;
				while(p1.quadrado[i-1].chave!=-1){
					a1[i-1].chave=p1.quadrado[i-1].chave;
					a1[i-1].nrrPrincipal=p1.nrrFilha[i];
					i++;
				}



			printf("\nINSERÇAO FEITA COM SUCESSO.");

			getchar();
			getchar();
			OrdenaPagina(p1.quadrado);
			for(i=0;i<=ORDEM-2;i++){
				for(k=0;k<=ORDEM-2;k++){
					if(a1[i].chave==p1.quadrado[k].chave){
						p1.nrrFilha[k+1]=a1[i].nrrPrincipal;
					}
				}



			}

			printf("\nP1 DEPOIS DE ORDENAR!!!!!");
			printf("\n Chaves: ");
				for (i=0;i<=ORDEM-2;i++){
					printf(" %d",p1.quadrado[i].chave);
				}
				printf("\n NRR PRINCIPAIS: ");
								for (i=0;i<=ORDEM-2;i++){
									printf(" %d",p1.quadrado[i].nrrPrincipal);
								}
				printf("\nNrr Filhas: ");
				for (i=0;i<=ORDEM-1;i++){
						printf(" %d",p1.nrrFilha[i]);
					}
				printf("\nPai %d",p1.nrrPai);
				printf("\nContador %d",p1.contador);
				printf("\nNRR propria: %d",p1.nrrPropria);

				getchar();
				getchar();



			PRR=p1.nrrPropria*sizeof(pagina);



			printf("PRR A SER INSERIDA: %d",PRR);
			getchar();
			getchar();
			fseek(arqTree,PRR,0);
			if (fwrite(&p1,sizeof(pagina),1,arqTree)!=1){
					printf("ERRO NA ESCRITA DURANTE A INSERCAO");
			}
			getchar();
			getchar();
		}else{

			p2=InicializaPagina();




			for(i=0;i<=ORDEM-2;i++){
				pSplit.quadrado[i].chave=p1.quadrado[i].chave;
				pSplit.quadrado[i].nrrPrincipal=p1.quadrado[i].nrrPrincipal;
	//			pSplit.nrrFilha[i]=p1.nrrFilha[i];
			//	p1.quadrado[i].chave=-1;                        //HEEY
				//p1.quadrado[i].nrrPrincipal=-1;
			}
			for(i=0;i<=ORDEM-1;i++){
				pSplit.nrrFilha[i]=p1.nrrFilha[i];
			}

			pSplit.quadrado[ORDEM-1].chave=chave;
			pSplit.quadrado[ORDEM-1].nrrPrincipal=a;



			if(pSplit.nrrFilha[0]<0){                     //MEGA ATENCAO AQUI. CAMBIARRA!
				for(i=1;i<=ORDEM;i++){
						pSplit.nrrFilha[i]=-1;
				}
			}
			OrdenaSplit(pSplit.quadrado);

			if((pSplit.quadrado[0].chave<0)||(pSplit.quadrado[0].nrrPrincipal<0)){ //TIVEMOS VARIOS PROBLEMAS COM LOCACAO DE ESPACO DENTRO DOS REGISTROS.
											//EM ALGUNS CASOS O SPLIT FICAVA UMA POSICAO A FRENTE DO NORMAL, NAO SABEMOS PRECISAR PORQUE.
							for(i=0;i<=ORDEM;i++){
								pSplit.quadrado[i].chave=pSplit.quadrado[i+1].chave;
								pSplit.quadrado[i].nrrPrincipal=pSplit.quadrado[i+1].nrrPrincipal;
							}
						}
			pSplit.nrrFilha[ORDEM]=PRR/sizeof(pagina);
			printf("\nSPLIT");
			printf("\n Chaves SPLIT: ");
							for (i=0;i<=ORDEM-1;i++){
								printf(" %d",pSplit.quadrado[i].chave);
							}
							printf("\n NRR PRINCIPAIS SPLIT: ");
											for (i=0;i<=ORDEM-1;i++){
												printf(" %d",pSplit.quadrado[i].nrrPrincipal);
											}
							printf("\nNrr Filhas SPLIT: ");
							for (i=0;i<=ORDEM;i++){//AQUIIII
									printf(" %d",pSplit.nrrFilha[i]);
								}



							getchar();
							getchar();


			divisor=((ORDEM-1)/2 + (ORDEM-1)%2);


			printf("\nDIVISOR %d",divisor);
			getchar();
			getchar();



			k=0;
			for(i=divisor+1;i<=ORDEM-1;i++){
				p2.nrrFilha[k]=p1.nrrFilha[i];
				k++;
			}



			for(i=0;i<=ORDEM-2;i++){
				p1.quadrado[i].chave=-1;
				p1.quadrado[i].nrrPrincipal=-1;
				p1.nrrFilha[i]=-1;
			}

			for(i=divisor;i<=ORDEM-2;i++){
				p1.quadrado[i].chave=-1;
				p1.quadrado[i].nrrPrincipal=-1;
				p1.nrrFilha[i+1]=-1;
			}

			for(i=0;i<divisor;i++){
							__fpurge(stdin);
							p1.quadrado[i].chave=pSplit.quadrado[i].chave;
							p1.quadrado[i].nrrPrincipal=pSplit.quadrado[i].nrrPrincipal;
							p1.contador=i+1;
						}
			k=0;
			for(i=divisor+1;i<=ORDEM-1;i++){
				p2.quadrado[k].chave=pSplit.quadrado[i].chave;
				p2.quadrado[k].nrrPrincipal=pSplit.quadrado[i].nrrPrincipal;
				p2.nrrFilha[k]=pSplit.nrrFilha[i];
				p2.contador=k+1;
				k=k+1;
			}

			p2.nrrFilha[k]=pSplit.nrrFilha[ORDEM];




			if(p1.nrrFilha[0]<0){                     //MEGA ATENCAO AQUI. CAMBIARRA!
					for(i=1;i<=ORDEM-1;i++){
						p1.nrrFilha[i]=-1;
					}
				}

			for(i=0;i<divisor;i++){
										__fpurge(stdin);
										p1.quadrado[i].chave=pSplit.quadrado[i].chave;
										p1.quadrado[i].nrrPrincipal=pSplit.quadrado[i].nrrPrincipal;
										p1.nrrFilha[i]=pSplit.nrrFilha[i];
										p1.contador=i+1;
									}

			p1.nrrFilha[divisor]=pSplit.nrrFilha[divisor];


			if(p2.nrrFilha[0]<0){                     //MEGA ATENCAO AQUI. CAMBIARRA!
							for(i=1;i<=ORDEM-1;i++){
								p2.nrrFilha[i]=-1;
							}
			}

			for(i=0;i<divisor;i++){
				__fpurge(stdin);
				p1.quadrado[i].chave=pSplit.quadrado[i].chave;
				p1.quadrado[i].nrrPrincipal=pSplit.quadrado[i].nrrPrincipal;
				p1.contador=i+1;
			}



			printf("\nP1 APOS SPLIT");
			printf("\n Chaves: ");
			for (i=0;i<=ORDEM-2;i++){
				printf(" %d",p1.quadrado[i].chave);
			}
			printf("\n NRR PRINCIPAIS: ");
			for (i=0;i<=ORDEM-2;i++){
				printf(" %d",p1.quadrado[i].nrrPrincipal);
			}
			printf("\nNrr Filhas: ");
			for (i=0;i<=ORDEM-1;i++){
				printf(" %d",p1.nrrFilha[i]);
			}
			printf("\nPai %d",p1.nrrPai);
			printf("\nContador %d",p1.contador);
			printf("\nNRR propria: %d",p1.nrrPropria);

			getchar();
			getchar();



			printf("\nP2 APOS SPLIT");
			printf("\n Chaves: ");
			for (i=0;i<=ORDEM-2;i++){
				printf(" %d",p2.quadrado[i].chave);
			}
			printf("\n NRR PRINCIPAIS: ");
			for (i=0;i<=ORDEM-2;i++){
				printf(" %d",p2.quadrado[i].nrrPrincipal);
			}
			printf("\nNrr Filhas: ");
			for (i=0;i<=ORDEM-1;i++){
				printf(" %d",p2.nrrFilha[i]);
			}
			printf("\nPai %d",p2.nrrPai);
			printf("\nContador %d",p2.contador);
			printf("\nNRR propria: %d",p2.nrrPropria);



			getchar();
			getchar();


			if(p1.nrrPai==-1){
				pPai=InicializaPagina();
				pPai.quadrado[0].chave=pSplit.quadrado[divisor].chave;
				pPai.quadrado[0].nrrPrincipal=pSplit.quadrado[divisor].nrrPrincipal;
				pPai.nrrFilha[0]=p1.nrrPropria;
				pPai.nrrFilha[1]=p2.nrrPropria;
				pPai.contador=1;


				printf("\nPPAI");
							printf("\n Chaves: ");
							for (i=0;i<=ORDEM-2;i++){
								printf(" %d",pPai.quadrado[i].chave);
							}
							printf("\n NRR PRINCIPAIS: ");
							for (i=0;i<=ORDEM-2;i++){
								printf(" %d",pPai.quadrado[i].nrrPrincipal);
							}
							printf("\nNrr Filhas: ");
							for (i=0;i<=ORDEM-1;i++){
								printf(" %d",pPai.nrrFilha[i]);
							}
							printf("\nPai %d",pPai.nrrPai);
							printf("\nContador %d",pPai.contador);
							printf("\nNRR propria: %d",pPai.nrrPropria);


				p1.nrrPai=pPai.nrrPropria;
				p2.nrrPai=pPai.nrrPropria;
				fwrite(&p2,sizeof(pagina),1,arqTree);


				fwrite(&pPai,sizeof(pagina),1,arqTree);
				fseek(arqRaiz,0,0);
				fwrite(&pPai.nrrPropria,sizeof(int),1,arqRaiz);
				PRR=p1.nrrPropria*sizeof(pagina);
				fseek(arqTree,PRR,0);
				fwrite(&p1,sizeof(pagina),1,arqTree);
				div=0;

				getchar();
				getchar();



			}else{
				k=1;
				chave=pSplit.quadrado[divisor].chave;
				nrrRaiz=pSplit.quadrado[divisor].nrrPrincipal;
				printf("NRR P vaai: %d",nrrRaiz);

				__fpurge(stdin);
				getchar();
				getchar();


				p2.nrrPai=p1.nrrPai;

				PRR=p1.nrrPropria*sizeof(pagina);
				fseek(arqTree,PRR,0);


				PRR=p1.nrrPai*sizeof(pagina);

				fwrite(&p1,sizeof(pagina),1,arqTree);

				printf("PROMOVIDAA: %d",chave);
				printf("\nNRR PAI: %d",PRR/sizeof(pagina));
				getchar();
				getchar();
				fseek(arqTree,PRR,0);
				fread(&p1,sizeof(pagina),1,arqTree);
				p1.nrrFilha[p1.contador+1]=p2.nrrPropria;
				PRR=p2.nrrPropria*sizeof(pagina);

				printf("NRRRRRRRR PROOOPRIAAAA p2: %d",p2.nrrPropria);
								getchar();
								getchar();




				fseek(arqTree,PRR,0);
				fwrite(&p2,sizeof(pagina),1,arqTree);


				printf("\nP1 'RECURSIVO");
									printf("\n Chaves: ");
									for (i=0;i<=ORDEM-2;i++){
										printf(" %d",p1.quadrado[i].chave);
									}
									printf("\n NRR PRINCIPAIS: ");
									for (i=0;i<=ORDEM-2;i++){
										printf(" %d",p1.quadrado[i].nrrPrincipal);
									}
									printf("\nNrr Filhas: ");
									for (i=0;i<=ORDEM-1;i++){
										printf(" %d",p1.nrrFilha[i]);
									}
									printf("\nPai %d",p1.nrrPai);
									printf("\nContador %d",p1.contador);
									printf("\nNRR propria: %d",p1.nrrPropria);

									getchar();
									getchar();






			}

		}

	}

}


void InicializaQuadrado(tipo_conjunto *q1){
    int i;
    for(i=0;i<=(ORDEM-2);i=i+1){
        q1[i].chave=-1;
        q1[i].nrrPrincipal=-1;
    }
}

pagina InicializaPagina() {
    tipo_conjunto q1[ORDEM-2];
    int i,aux2[ORDEM-1];
    pagina pag1;

    InicializaQuadrado(q1);

    for(i=0;i<=(ORDEM-1);i=i+1){//aquiiiiiiii <=
            pag1.nada[i]=-1;
        }

    for(i=0;i<=(ORDEM-1);i=i+1){//aquiiiiiiii <=
        pag1.nrrFilha[i]=-1;
    }

    for(i=0;i<=(ORDEM-2);i=i+1){
        pag1.quadrado[i].chave=q1[i].chave;
        pag1.quadrado[i].nrrPrincipal=q1[i].nrrPrincipal;
    }
    pag1.nrrPai=-1;
    nrrPagina=nrrPagina+1;
    pag1.nrrPropria=nrrPagina;
    pag1.contador=0;

    return pag1;
}

int OrdenaPagina(tipo_conjunto *q1){
    int achou,aux,i;
    achou=1;

    while (achou==1){
        achou=0;

        for (i=0;i<=ORDEM-2;i=i+1){
            if((q1[i].chave>q1[i+1].chave)&&(q1[i+1].chave!=-1)){ // TIREI O IGUAL
            	achou=1;
                aux=q1[i].chave;
                q1[i].chave=q1[i+1].chave;
                q1[i+1].chave=aux;

                aux=q1[i+1].nrrPrincipal;
                q1[i+1].nrrPrincipal=q1[i].nrrPrincipal;
                q1[i].nrrPrincipal=aux;
                printf("q[i] %d",q1[i].chave);
                printf("q[i+1] %d",q1[i+1].chave);
                getchar();
                getchar();
            }
        }
    }
    return 0;
}

void OrdenaSplit(tipo_conjunto *q1){
    int achou,aux,i;
    achou=1;
    while (achou==1){
        achou=0;
        for (i=0;i<=ORDEM-1;i=i+1){//==
            if((q1[i].chave>=q1[i+1].chave)&&(q1[i+1].chave!=-1)){
                achou=1;
                aux=q1[i].chave;
                q1[i].chave=q1[i+1].chave;
                q1[i+1].chave=aux;

                aux=q1[i+1].nrrPrincipal;
                q1[i+1].nrrPrincipal=q1[i].nrrPrincipal;
                q1[i].nrrPrincipal=aux;
            }
        }
    }
}

int procuraRegistro(){
	int i,raiz,achou,PRR,chave;
	pagina p1;
	char resposta;
	registro usuario;


	arqRaiz=fopen("nrrRaiz.bin","rb");
	fread(&raiz,sizeof(int),1,arqRaiz);
	printf("\nNRR RAIZ: %d",raiz);
	arqTree=fopen("arquivoTree.bin","rb");

	arqReg=fopen("arquivoregistros.bin","rb");


	fseek(arqTree,raiz*sizeof(pagina),0);
	__fpurge(stdin);
	__fpurge(stdin);
	fread(&p1,sizeof(pagina),1,arqTree);



	printf("\nP1 'RAIZZZZ' ");
						printf("\n Chaves: ");
							for (i=0;i<=ORDEM-2;i++){
								printf(" %d",p1.quadrado[i].chave);
							}
							printf("\n NRR PRINCIPAIS: ");
											for (i=0;i<=ORDEM-2;i++){
												printf(" %d",p1.quadrado[i].nrrPrincipal);
											}
							printf("\nNrr Filhas: ");
							for (i=0;i<=ORDEM-1;i++){
									printf(" %d",p1.nrrFilha[i]);
								}
							printf("\nPai %d",p1.nrrPai);
							printf("\nContador %d",p1.contador);
							printf("\nNRR propria: %d",p1.nrrPropria);


	do{
		fseek(arqTree,raiz*sizeof(pagina),0);
		__fpurge(stdin);
		__fpurge(stdin);
			fread(&p1,sizeof(pagina),1,arqTree);
		printf("\nDigite a chave que deseja procurar: ");
		scanf("%d",&chave);
		achou=0;
		while((achou==0)){
			i=0;
			while((chave>=p1.quadrado[i].chave)&&(i<=ORDEM-2)&&(p1.quadrado[i].chave!=-1)){   //ATENCAO AQUI
				if(chave==p1.quadrado[i].chave){
					achou=1;
					fseek(arqReg,p1.quadrado[i].nrrPrincipal*sizeof(registro),0);
					fread(&usuario,sizeof(registro),1,arqReg);

					printf("\nNOMEEE: %s",usuario.nome);


					getchar();
					getchar();
					return 0;
				}
				i=i+1;
			}
					if(i==0){
						PRR=p1.nrrFilha[0]*sizeof(pagina);
						if(p1.nrrFilha[0]<0){
							printf("AUSENTE!!!!");
							getchar();
							getchar();
							return 0;
						}
						printf("\nPRR antes de chamar a prox: %d",PRR);
					}else{
						printf("\nI: %d",i);

						PRR=p1.nrrFilha[i];//AQUIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
						if(p1.nrrFilha[i]<0){
							printf("AUSENTE!!!!");
							getchar();
							getchar();
							return 0;
						}
						printf("\nNNNNNNRR antes de chamar a prox: %d",PRR);
						PRR=PRR*sizeof(pagina);
					}
					fseek(arqTree,PRR,0);
					fread(&p1,sizeof(pagina),1,arqTree);


					printf("\nP1 'LIDA' ");
					printf("\n Chaves: ");
					for (i=0;i<=ORDEM-2;i++){
						printf(" %d",p1.quadrado[i].chave);
					}
					printf("\n NRR PRINCIPAIS: ");
					for (i=0;i<=ORDEM-2;i++){
						printf(" %d",p1.quadrado[i].nrrPrincipal);
					}
						printf("\nNrr Filhas: ");
					for (i=0;i<=ORDEM-1;i++){
						printf(" %d",p1.nrrFilha[i]);
					}
					printf("\nPai %d",p1.nrrPai);
					printf("\nContador %d",p1.contador);
					printf("\nNRR propria: %d",p1.nrrPropria);
					getchar();
					getchar();



		}

		printf("Deseja pesquisar outro nome?(s ou n) ");
		scanf("%c",&resposta);
	}while(resposta=='s');




	return 1;


}




















