//DOM_BGR_View.h 12/08/22
//Andre Cavacanti, Marcello Linard, Thiago amaral

#include"Dom_BGR_Model.cpp"
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int fMenuGeral(int opc);
void fApresentar(struct Pc Pec[28]);
void fMesa(struct Tmesa Mesa[]);
void fprimeiro(struct Pc Pec[28],int u);
int fjogar(int opc, int ladD, int ladE);
int fescpec(int loc);
int fladmesa(int lado);
void fmsgop();
void fmsgcomp();
void fmsgfimjogo(int fim);
void fmsgopinvalida();
void ladoErrado();
void fnumeracaoErrada();
void fcontinuajogo();
void fsemjoagadas();
void fcontagem();
void fpassou();
void ARQPECASerro1();
void ARQPECASerro2();
void ARQMESAerro1();
void ARQMESAerro2();
void ARQJogdorerro1();
void ARQJogdorerro2();
void ARQmesaperro1();
void ARQmesaperro2();
void ARQTcomperro1();
void ARQTcomperro2();
void ARQempateerro1();
void ARQempateerro2();
void ARQboterro1();
void ARQboterro2();
void recARQmesaperro1();
void recARQmesaperro2();
void recARQPECASerro1();
void recARQPECASerro2();
void recARQMESAerro1();
void recARQMESAerro2();
void recARQJogadorerro1();
void recARQJogadorerro2();
void recARQTcomperro1();
void recARQTcomperro2();
void recARQempateerro1();
void recARQempateerro2();
void recARQboterro1();
void recARQboterro2();
void salvo();
void falhasalvar();
void jogorecuperado();
void falharecuperarjogo();
void naohajogo();
void pecajogadabot();
void pecacompradabot();
void vezpassadabot();
void Regras();
