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
void fInicializarMenu(int oper)
{
	int opr;
	do
	{
		opr = fMenuGeral(opc);
		switch (opr)
		{
			case 1:
				fApresentar(Pecas);
				break;
			case 2:	
				break; 
			}
	}while( opr != 2)
}
