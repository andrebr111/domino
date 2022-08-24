//DOM_BGR_Controller 12/08/22
//Andre Cavacanti, Marcello Linard, Thiago amaral

#include"DOM_BGR_Controller.h"
#include"DOM_BGR_View.cpp"
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

//gera as pecas do domino
void fGerarPecas(struct Pc Pec[28]) 
{
	int i,j, count = 0;
	for(i = 0; i <= 6; i++)
		for(j = i; j <= 6; j++)
		{
			Pec[count].lado1 = i;
			Pec[count].lado2 = j;
			count++;
		}	
}

//embaralha as pecas do domino
void fEmbaralharPecas(struct Pc Pec[28])
{
	srand(time(0));
	int i,j;
	int random = 0;
	struct Pc aux ;
	
	for(i = 0; i < 28; i++)
	{
		random = rand() % 28;
		aux = Pec[i] ;
		Pec[i] = Pec[random];
		Pec[random] = aux;
	}
}

//inicializa o menu
void fInicializarMenu(int oper, struct Pc Pec[28])
{
	int opr;
	
	do
	{
		opr = fMenuGeral(opr);
		switch (opr)
		{
			case 1:
				fIniciarjogo(Pec);
				break;
			case 2:	
				break;
			case 3:
				break;
			case 4:	
				break;
			case 5:
				break;
			case 6:	
				break;
			case 0:
				break;					 
			}
	}while( opr != 0);
}

//inicia o jogo
void fIniciarjogo(struct Pc Pec[28])
{
	int i;
	char opr;
	
	fGerarPecas(Pec);
	
	for(i = 0; i < 28; i++)
	{
		Pec[i].status =' ';
	}
	
	fEmbaralharPecas(Pec);
	
	for(i = 0; i < 7; i++)
	{
		Pec[i].status = '1';
	}
	for(i = 7; i < 14; i++)
	{
		Pec[i].status = '2';	
	}

	fprimeirapeca(Pec);
}

//seleciona a primeira peca que vai na mesa 
void fprimeirapeca(struct Pc Pec[28])
{
	int i, u;
	char z;
	char opr;
	
	aux.status = ' ';
	aux.lado1 = 0; 
	aux.lado2 = 1;
	
	for(i=0; i<=13; i++)
	{
		if(Pec[i].lado1 == Pec[i].lado2)
		{	
			if(aux.lado1 <= Pec[i].lado1)
			{
				aux = Pec[i];
				u = i;
			}
	
			else
			{
        		if(aux.lado1 + aux.lado2 <= Pec[i].lado1 + Pec[i].lado2)
            	{
            		if(aux.lado1 || aux.lado2 > Pec[i].lado1 || Pec[i].lado2 )
                	{
                		aux = Pec[i];
                		u = i;
                 	}
				}
			}
		}	
	}
	Mesa[0].lado1 = aux.lado1;
	Mesa[0].lado2 = aux.lado2;
	
	fMesa(Pec,u);
	
	if(Pec[u].status=='1')
	{
    z='2';
    } 
    else
    {
    z='1';
    }
    Pec[u].status = 'm';
    fApresentar(Pec, u, z);
    fmenujogar(Pec, opr);
}

//inicia as opcoes do jogador
void fmenujogar(struct Pc Pec[28], char oper)
{
	char opr;
	int u;
	do
	{
		char opr;
		opr = fjogar(Pec, u, opr);
		switch (opr)
		{
			case 'J':
			case 'j':	
				break;
			case 'C':
			case 'c':	
				break;
			case 'P':
			case 'p':
				break;
			case 'S':
			case 's':
				break;				 
		}
	}while( opr != 'S' && opr != 's');
}
