//DOM_BGR_Model 12/08/22
//Andre Cavacanti, Marcello Linard, Thiago amaral

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#ifndef Model_H_
#define Model_H_

//estrutura das pecas do jogo
struct Pc
{
	int lado1;
	int lado2;
	char status;
	
} Pec[28], aux;

//estrutura da mesa no jogo
struct Tmesa
{
	int lado1;
	int lado2;
	char status;
	
}Mesa[28];

int mesap; //contagem de pecas na mesa 
char z;	//vez do jogador 
int comp;	//pecas compradas 
int emp; //caso tenha um empate 
int bot; //separar quando o jogo e iniciado com bot ou 2 jogadores
int ladD; //extremo direito da mesa 
int ladE; //exttremo esquerdo da mess

#endif 

