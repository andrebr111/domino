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
	do {
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
			//fclear();
			if( op != 1 && op != 2 && op != 3 && op != 4 && op != 5 && op != 6 && op != 0)
			{
				printf("opcao invalida\n");
				op = -1;
			}
			return op;
		}

	} while (op = - 1);

}

//mostra as pecas do domino
void fApresentar(struct Pc Pec[28], char z)
 {
	int i, k ;
	k = 1;
	if(z=='1') 
	{
		printf("\njogador 1:\n ");
	}
	else 
	{
		printf("jogador 2:\n ");
	}
	printf("Pecas: ");
	for(i = 0; i < 28; i++) 
	{
		if(Pec[i].status == z) 
		{
			printf("%d.[%d|%d]\t",k , Pec[i].lado1, Pec[i].lado2);
			k++;
		}
	}
	printf("\n");
}

void fprimeiro(struct Pc Pec[28],int u)
{
	if(Pec[u].status == '1')
	{
		printf("\njogador 1 comecou ");
	} else 
	{
		printf("\njogador 2 comecou ");
	}
}

// gerar mesa
void fMesa(struct Tmesa Mesa[], int i)
 {
	printf("\n ===========================\n");
	printf(" MESA:");
		printf("[%d|%d] ", Mesa[i].lado1, Mesa[i].lado2);
	
	printf("\t\n===========================\n");
}

//opcoes do jogador
int fjogar(int opc,int ladD, int ladE)
 {
	int op;
			printf("\n-----------------------------------------------\n");
			printf("|1 - Jogar (possiveis %d ou %d)                  |\n",ladE, ladD);
			printf("|2 - Comprar                                   |\n");
			printf("|3 - Passar                                    |\n");
			printf("|0 - Sair (interrorper o jogo)                 |\n");
			printf("------------------------------------------------\n");
			printf("\nDigite a sua opcao: ");
			scanf("%d", &op);
			return op;
}

//peca que ira selecionar
int fescpec(int opc)
{
	int op;
	printf("Escolha a peca para jogar (0 para desistir): ");
	scanf("%d",&op);
	return op;
}

//lado que ira jogar
int fladmesa(char opr)
{
	char op;
	
	printf("Escolha o lado da Mesa: Esquerdo/Direito (E/D): ");
	scanf("%s",&op);
	return op;
}

void fmsgopinvalida()
{
	printf("opcao invalida\n");
}

void fmsgop()
{
	printf("Peca com numeracao errada");
}

void fmsgcomp()
{
	printf("nao ha mais pecas para compra");
}

void fmsgfimjogo(int fim)
{
	if(fim==1)
    {
       printf("Jogador 1 venceu");
	}
	else if(fim==2)
	{
		printf("Jogador 2 venceu");
	}
	else if(fim==3)
	{
		printf("Interrrompeu o jogo");
	}
	else if(fim == 4)
	{
		printf("Empate (jogadores tem o mesmo numero de pecas e somatorias)\n");
	}
}

void ladoErrado()
{
	
	printf("Opcao invalida de lado na mesa\n");
	
}

void fnumeracaoErrada()
{
	
	printf("Peca com numeracao errada\n");
	
}

void fcontinuajogo()
{
	printf("Ainda ha pecas para serem compradas ou jogadas\n");
}

void fsemjoagadas()
{
	printf("nao ha mais jogadas possiveis\n");
}

void fcontagem()
{
	printf("pela contagem:\n");
}

void fclear() 
{
	char carac;
	while( (carac = fgetc(stdin)) != EOF && carac != '\n') {}
}
