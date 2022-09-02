//DOM_BGR_View.h 12/08/22
//Andre Cavacanti, Marcello Linard, Thiago amaral

#include"Dom_BGR_Model.cpp"
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int fMenuGeral(int opc);
void fApresentar(struct Pc Pec[28], char z);
void fMesa(struct Tmesa Mesa[],int i);
void fprimeiro(struct Pc Pec[28],int u);
int fjogar(int opc, int ladD, int ladE);
int fescpec(int opc);
int fladmesa(char opr);
void fmsgop();
void fmsgcomp();
void fmsgfimjogo(int fim);
void fmsgopinvalida();
void ladoErrado();
void fnumeracaoErrada();
void fcontinuajogo();
void fsemjoagadas();
void fcontagem();
void fclear();
