//DOM_BGR_View 12/08/22
//Andre Cavacanti, Marcello Linard, Thiago amaral

#include"Dom_BGR_Model.cpp"
#include"Dom_BGR_View.h"
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

//apresenta a parte visual do menu
int fMenuGeral(int opc)
{
	int op;
	do
	{
		op = -1;
		while (op != 2)
			{
			printf("\n             -domino- ");	
			printf("\n---------------------------------\n");	
			printf("|1 - mostrar pecas                |\n");
			printf("|2 - sair                         |\n");
			printf("-----------------------------------\n");
			printf("\nDigite a sua opcao: ");
			scanf("%d", &op);
			if( op != 2 && op != 1)
			 {
			 	printf("opcao invalida\n");
			 	op = -1;
			 }
			 return op;
			}
		
	}while (op = - 1);
	
}

//mostra as pecas do domino
void fApresentar(struct Pc Pec[28])
{
	int i, j;
	for(i = 0; i < 28; i++)
	{
		printf("[%d|%d]\t", Pec[i].lado1, Pec[i].lado2);	
	}//DOM_BGR_View 12/08/22
//Andre Cavacanti, Marcello Linard, Thiago amaral

#include"Dom_BGR_Model.cpp"
#include"Dom_BGR_View.h"
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

//apresenta a parte visual do menu
int fMenuGeral(int opc)
{
	int op;
	do
	{
		op = -1;
		while (op != 2)
			{
			printf("\n             -domino- ");	
			printf("\n--------------------------------------\n");	
			printf("|1 - Iniciar jogo (2 jogadores)        |\n");
			printf("|3 - Iniciar jogo (contra o computador)|\n");
			printf("|4 - Retornar ao jogo interrompido     |\n");
			printf("|5 - Salvar jogo                       |\n");
			printf("|6 - Recuperar o jogo salvo            |\n");
			printf("|7 - sair                              |\n");
			printf("----------------------------------------\n");
			printf("\nDigite a sua opcao: ");
			scanf("%d", &op);
			if( op != 2 && op != 1)
			 {
			 	printf("opcao invalida\n");
			 	op = -1;
			 }
			 return op;
			}
		
	}while (op = - 1);
	
}

//mostra as pecas do domino
void fApresentar(struct Pc Pec[28])
{
	int i;
	
	printf("jogador 1:\n ");
	printf("Pecas: ");
	for(i = 0; i < 28; i++)
	{
		if(Pec[i].status == '1')
		{
			printf("[%d|%d]\t", Pec[i].lado1, Pec[i].lado2);
		}
 	}
 	printf("\n\n");
 	
 	printf("jogador 2:\n ");
 	printf("Pecas: ");
 	for(i = 0; i < 28; i++)
 	{
 		if(Pec[i].status == '2')
		{
			printf("[%d|%d]\t", Pec[i].lado1, Pec[i].lado2);
		}
	}
	printf("\n");
}
	printf("\n");	
}

//mostra as pecas do domino
void fApresentar(struct Pc Pec[28])
{
	int i;
	for(i = 0; i < 28; i++)
	{
		printf("[%d|%d]\t", Pec[i].lado1, Pec[i].lado2);	
	}
	printf("\n");	
}
