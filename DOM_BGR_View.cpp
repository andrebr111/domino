//DOM_BGR_View 12/08/22
//Andre Cavacanti, Marcello Linard, Thiago amaral

#include"Dom_BGR_Model.cpp"
#include"Dom_BGR_View.h"
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

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
	
			}
		
	}while (op = - 1);
	return op;
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