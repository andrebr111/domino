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
			return op;
		}

	} while (op = - 1);

}

//mostra as pecas do domino
void fApresentar(struct Pc Pec[28])
 {
	int i, k ;
	k = 1;
	if(z=='1') 
	{
		printf("\njogador 1:\n ");
	}
	else if(z == '2')
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
void fMesa(struct Tmesa Mesa[28] )
 {
	int i;
	printf("\n ======================================\n");
	printf(" MESA:");
	for(i = 0; i < mesap; i++)	
		printf("[%d|%d] ", Mesa[i].lado1, Mesa[i].lado2);
	
	printf("\n=======================================\n");
}

//opcoes do jogador
int fjogar(int opc,int ladD, int ladE)
 {
	int s;
	char ops;
			printf("\n-----------------------------------------------\n");
			printf("|J - Jogar (possiveis %d ou %d)                  |\n",ladE, ladD);
			printf("|C - Comprar                                   |\n");
			printf("|P - Passar                                    |\n");
			printf("|S - Sair (interrorper o jogo)                 |\n");
			printf("------------------------------------------------\n");
			printf("\nDigite a sua opcao: ");
			scanf("%s", &ops);
			
			if(ops == 'j'  || ops == 'J')
			{
				s = 1;
			}
			if(ops == 'c' || ops == 'C')
			{
				s =2;
			}
			if(ops == 'p' || ops == 'P')
			{
				s =3;
			}
			if(ops =='s' || ops == 'S')
			{
				s =4;
			}
			if(ops != 'j' && ops!= 'J' && ops != 'c' && ops != 'C' && ops != 'p' && ops != 'P' && ops != 's' && ops != 'S')
			{
				s = 5;
			}
			return s;
}

//peca que ira selecionar
int fescpec(int loc)
{
	int op;
	printf("Escolha a peca para jogar (0 para desistir): ");
	scanf("%d",&op);
	return op;
}

//lado que ira jogar
int fladmesa(int lado )
{
	char op;
	int s;
	
	printf("Escolha o lado da Mesa: Esquerdo/Direito (E/D):");
	scanf("%s",&op);
	
	if(op == 'e'|| op == 'E' )
	{
		s = 1;
	}
	if(op == 'd'|| op == 'D' )
	{
		s = 2;
	}
	if(op != 'e' && op != 'E' && op != 'd' && op != 'D' )
	{
		s = 3;
	}
	
	return s;
}

void fmsgopinvalida()
{
	printf("opcao invalida\n");
}

void fmsgop()
{
	printf("Peca com numeracao errada/n");
}

void fmsgcomp()
{
	printf("nao ha mais pecas para compra/n");
}

void fmsgfimjogo(int fim)
{
	if(fim==1)
    {
       printf("Jogador 1 venceu\n");
	}
	else if(fim==2)
	{
		printf("Jogador 2 venceu\n");
	}
	else if(fim==3)
	{
		printf("Interrrompeu o jogo\n");
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

void fpassou()
{
	printf("passou a vez\n");
}

void fcontagem()
{
	printf("pela contagem:\n");
}

void salvo()
{
	printf("O jogo foi salvo\n");
}

void falhasalvar()
{
	printf("Nao foi possivel salvar o jogo\n");
}

void jogorecuperado()
{
	printf("O jogo foi recuperado\n");
}

void falharecuperarjogo()
{
	printf("Nao foi possivel recuperar o jogo\n");
}

// mensagens de salvamento
void ARQPECASerro1()
{
	printf("O arquivo ARQPECAS não pode ser aberto para gravação\n");
}

void ARQPECASerro2()
{
	printf("Erro na gravacaodo arquivo ARQPECAS\n");
}

void ARQMESAerro1()
{
	printf("O arquivo ARQMESA não pode ser aberto para gravação\n");
}

void ARQMESAerro2()
{
	printf("Erro na gravacaodo arquivo ARQMESA\n");
}

void ARQJogdorerro1()
{
	printf("O arquivo ARQJogador não pode ser aberto para gravação\n");
}

void ARQJogdorerro2()
{
	printf("Erro na gravacaodo arquivo ARQJogador\n");
}

void ARQmesaperro1()
{
	printf("O arquivo ARQmesap não pode ser aberto para gravação\n");
}

void ARQmesaperro2()
{
	printf("Erro na gravacaodo arquivo ARQmesap\n");
}

void ARQTcomperro1()
{
	printf("O arquivo ARQcomp não pode ser aberto para gravação\n");
}

void ARQTcomperro2()
{
	printf("Erro na gravacaodo arquivo ARQcomp\n");
}

void ARQempateerro1()
{
	printf("O arquivo ARQempate não pode ser aberto para gravação\n");
}

void ARQempateerro2()
{
	printf("Erro na gravacaodo arquivo ARQempate\n");
}

void ARQboterro1()
{
	printf("O arquivo ARQbot não pode ser aberto para gravação\n");
}

void ARQboterro2()
{
	printf("Erro na gravacaodo arquivo ARQbot\n");
}

// mensagens de recuperacao
void recARQmesaperro1()
{
	printf("O arquivo ARQmesap não pode ser aberto para leitura\n");
}

void recARQmesaperro2()
{
	printf("Erro na leitura do arquivo ARQmesap\n");
}

void recARQPECASerro1()
{
	printf("O arquivo ARQPECAS não pode ser aberto para leitura\n");
}

void recARQPECASerro2()
{
	printf("Erro na leitura do arquivo ARQPECAS\n");
}

void recARQMESAerro1()
{
	printf("O arquivo ARQMESA não pode ser aberto para leitura\n");
}

void recARQMESAerro2()
{
	printf("Erro na leitura do arquivo ARQMESA\n");
}

void recARQJogadorerro1()
{
	printf("O arquivo ARQJogador não pode ser aberto para leitura\n");
}

void recARQJogadorerro2()
{
	printf("Erro na leitura do arquivo ARQJogador\n");
}



void recARQTcomperro1()
{
	printf("O arquivo ARQcomp não pode ser aberto para leitura\n");
}

void recARQTcomperro2()
{
	printf("Erro na leitura do arquivo ARQcomp\n");
}

void recARQempateerro1()
{
	printf("O arquivo ARQemapte não pode ser aberto para leitura\n");
}

void recARQempateerro2()
{
	printf("Erro na leitura do arquivo ARQempate\n");
}

void recARQboterro1()
{
	printf("O arquivo ARQbot não pode ser aberto para leitura\n");
}

void recARQboterro2()
{
	printf("Erro na leitura do arquivo ARQbot\n");
}

void Regras()
{
	printf("Para jogar domino usam-se 28 pecas\n");
	printf("Cada peca esta dividida em 2 lados numerados de 0 a 6\n");
	printf("O objetivo do jogo e utilizar todas as suas pecas antes do oponente e marcar pontos.\n");
	printf("O jogador que tiver menos pecas vence.\n");
}

void naohajogo()
{
	printf("Nao ha jogo para ser continuado\n");
}

void pecajogadabot()
{
	printf("Peca jogada pelo bot\n");
}

void pecacompradabot()
{
	printf("Peca comprada pelo bot\n");
}

void vezpassadabot()
{
	printf("Vez passada pelo bot\n");
}

