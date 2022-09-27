//DOM_BGR_Controller.h 12/08/22
//Andre Cavacanti, Marcello Linard, Thiago amaral

#include "DOM_BGR_Model.cpp"
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void fGerarPecas(struct Pc Pec[28]);
void fEmbaralharPecas(struct Pc Pec[28]);
void fInicializarMenu();
void fIniciarjogo(struct Pc Pec[28]);
void fprimeirapeca(struct Pc Pec[28]);
int salvajogo();
int retornajogo();
void continuarjogo();
void computador();
void continuarjogoBOT();

