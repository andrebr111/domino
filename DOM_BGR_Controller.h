//DOM_BGR_Controller.h 12/08/22
//Andre Cavacanti, Marcello Linard, Thiago amaral

#include "DOM_BGR_Model.cpp"
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void fGerarPecas(struct Pc Pec[28]);
void fEmbaralharPecas(struct Pc Pec[28]);
void fInicializarMenu(int oper, struct Pc Pec[28]);
void fIniciarjogo(struct Pc Pec[28]);
void fprimeirapeca(struct Pc Pec[28]);
void fmenujogar(struct Pc Pec[28], char z, int ladD, int ladE, int mesap, int fim);
