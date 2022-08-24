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
		while (op != 0)
			{
			printf("\n             -domino- ");	
			printf("\n--------------------------------------\n");	
			printf("|1 - Iniciar jogo (2 jogadores)        |\n");
			printf("|2 - Iniciar jogo (contra o computador)|\n");
			printf("|3 - Retornar ao jogo interrompido     |\n");
			printf("|4 - Regras gerais do jogo             |\n");
			printf("|5 - Salvar jogo                       |\n");
			printf("|6 - Recuperar o jogo salvo            |\n");
			printf("|0 - sair                              |\n");
			printf("----------------------------------------\n");
			printf("\nDigite a sua opcao: ");
			scanf("%d", &op);
			if( op != 1 && op != 2 && op != 3 && op != 4 && op != 5 && op != 6 && op != 0)
			 {
			 	printf("opcao invalida\n");
			 	op = -1;
			 }
			 return op;
			}
		
	}while (op = - 1);
	
}

//mostra as pecas do domino
void fApresentar(struct Pc Pec[28], int u, char z)
{
	int i, h;
	
	if(z=='1')
	{
		printf("\njogador 1:\n ");
		printf("Pecas: ");
		for(i = 0; i < 28; i++)
		{
			if(Pec[i].status == '1')
			{
				h = i + 1;
				printf("%d.[%d|%d]\t", h, Pec[i].lado1, Pec[i].lado2);
			}
	 	}
 	}
 	else
 	{
	 	printf("jogador 2:\n ");
	 	printf("Pecas: ");
	 	for(i = 0; i < 28; i++)
	 	{
	 		if(Pec[i].status == '2')
			{
				h = i + 1;
				printf("[%d|%d]\t", h, Pec[i].lado1, Pec[i].lado2);
			}
		}
	}
	printf("\n");
}

// gerar mesa
void fMesa(struct Pc Pec[28], int u)
{
	int i;
	if(Pec[u].status == '1')
	{
		printf("\njogador 1 comecou ");
	}
	else
	{
		printf("\njogador 2 comecou ");
	}
	
	printf("\n =============\n");
	printf(" |MESA: [%d|%d]|\n ", Pec[u].lado1, Pec[u].lado2);
	printf("=============\n");
}
//opcoes do jogador 
int fjogar(struct Pc Pec[28],char opc, int u)
{
	char op;
	
	do
	{
		op = 'V';
		while (op != 'S' && op != 's')
		{
			printf("\n----------------------------------------------\n");	
			printf("|J - Jogar (possiveis %d ou %d)                 |\n",Mesa[0].lado1, Mesa[0].lado2);
			printf("|C - Comprar                                   |\n");
			printf("|P - Passar                                    |\n");
			printf("|S - Sair (interrorper o jogo)                 |\n");
			printf("------------------------------------------------\n");
			printf("\nDigite a sua opcao: ");
			scanf("%s", &op);
			
			if(op != 'J' &&  op != 'j' && op != 'C' &&  op != 'c' && op != 'P' &&  op != 'p' && op != 'S' &&  op != 's' )
			{
		 		printf("opcao invalida\n");
		 		op = 'V';
		 	}
		 	return op;
		}
	}while( op = 'V');
}
