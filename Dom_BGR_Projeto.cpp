//DOM_BGR_Projeto 12/08/22
//Andre Cavacanti, Marcello Linard, Thiago amaral


#include "Dom_BGR_Model.cpp"
#include "Dom_BGR_Controller.cpp"
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
	struct Pc Pecas[28];
	int opca;
	
	fGerarPecas(Pecas);
	fEmbaralharPecas(Pecas);
	fInicializarMenu(opca, Pecas);
	
}
