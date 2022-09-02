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
	
	fGerarPecas(Pec);
	
	for(i = 0; i < 28; i++)
	{
		Pec[i].status =' ';
	}
	
	for(i = 0; i < 28; i++)
	{
		Mesa[i].status = ' ';
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
	int i, k, u, x, loc, mesap, fim, cont, cont2, compr, N, lado, opr, comp;
	char z, test;
	int Tmesa, empate;
	int ladD, ladE;
	
	aux.status = ' ';
	aux.lado1 = 0; 
	aux.lado2 = 1;
	mesap=1;
	compr=13;
	lado=0;
    empate=0;
    Tmesa=5;
	
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
	Tmesa = Tmesa+7;
	
	fprimeiro(Pec,u);
	
	Mesa[0].lado1 = aux.lado1;
	Mesa[0].lado2 = aux.lado2;
	ladD = Mesa[0].lado2;
	ladE = Mesa[0].lado1;

	
	if(Pec[u].status=='1')
	{
    	z='2';
    } 
    else if(Pec[u].status=='2')
    {
    	z='1';
    }
    
	Pec[u].status = 'm';
	do
	{
		i = 0;
		do
		{
			fMesa(Mesa, i);
			i++;
		}while(i<mesap);
		
	    fApresentar(Pec, z);
	    
	    //inicia as opcoes do jogador
	    
	    opr = fjogar(opr, ladD, ladE);
	    
	    cont = 0;
	    
	    switch(opr)
	    {
	    	case 1:
	    		loc = fescpec(loc);
	    		
	    		if(loc==0)
	           	{
	                break;
	            }
	            
	            for(i=0; i<27; i++)
	            {
	            	if(Pec[i].status==z)
					{
						cont++;
			    	}
				    if(cont==loc)
				    {
				    	if(Pec[i].lado1 == ladE || Pec[i].lado1 ==ladD || Pec[i].lado2 == ladE || Pec[i].lado2 == ladD)
				    	{
				    		empate = 0;
				    		if(((Pec[i].lado1 == ladE ||  Pec[i].lado1 ==ladD ) && (Pec[i].lado2==ladE || Pec[i].lado2==ladD)) || ladE == ladD)
				    		{
				    			lado = fladmesa(lado);
				    			
				    			if( lado=='E' || lado=='e')
				    			{
				    				if(Pec[i].lado1 == ladE || Pec[i].lado2 == ladE)
				    				{
				    					for(N=mesap;N>=0;N--)
								   		{
				                    		Mesa[N].lado1 = Mesa[N-1].lado1;  
				                    		Mesa[N].lado2 = Mesa[N-1].lado2; 
							        	}
							        	if(Pec[i].lado1==ladE)
									    {
									    	Mesa[0].lado1 = Pec[i].lado2 ;
									    	Mesa[0].lado2 = Pec[i].lado1;
									    	mesap++;
									    	ladE=Mesa[0].lado1;
									    	Pec[i].status = 'm';
									    	if(z=='1')
	                                        {
	                                            z='2';
	                                        }
	                                        else if(z == '2')
	                                        {
	                                            z='1';
	                                        }
	                                        Tmesa = Tmesa+6;
									    	break;
									    }	
									    else if(Pec[i].lado2==ladE)
									    {
									    	Mesa[0].lado1 = Pec[i].lado1;
									    	Mesa[0].lado2 = Pec[i].lado2;
									    	mesap++;
									    	ladE=Mesa[0].lado1;
									    	Pec[i].status = 'm';
									    	if(z=='1')
	                                        {
	                                            z='2';
	                                        }
	                                        else if(z == '2')
	                                        {
	                                            z='1';
	                                        }
	                                        Tmesa = Tmesa+6;
							            	break;
									    }
									}
									else
									{
										ladoErrado();
									}
								}
								else if(lado=='D' || lado=='d')
								{
									if(Pec[i].lado1 == ladD || Pec[i].lado2 == ladD)
									{
										if(Pec[i].lado1 == ladD)
										{
										    Mesa[mesap].lado1=Pec[i].lado1;
										    Mesa[mesap].lado2=Pec[i].lado2;
								            ladD=Mesa[mesap].lado2;
								            mesap++;
								            Pec[i].status = 'm';
								            if(z=='1')
	                                        {
	                                            z='2';
	                                        }
	                                        else if(z == '2')
	                                        {
	                                            z='1';
	                                        }
	                                        Tmesa = Tmesa+6;
								        	break;
								        }
							            else if(Pec[i].lado2 == ladD)
									    {
										    Mesa[mesap].lado1=Pec[i].lado2;
										    Mesa[mesap].lado2=Pec[i].lado1;
								            ladD=Mesa[mesap].lado2;
								            mesap++;
								            Pec[i].status = 'm';
								            if(z=='1')
	                                        {
	                                            z='2';
	                                        }
	                                        else if(z == '2')
	                                        {
	                                            z='1';
	                                        }
	                                        Tmesa = Tmesa+6;
								        	break;
										}
									}
								}
								else
								{
									ladoErrado();
								}  
							}
							else
							{
								if(Pec[i].lado1==ladE)
	                            {
	                                for(N=mesap; N>=0; N--)
	                                {
	                                    Mesa[N].lado1 = Mesa[N-1].lado1;
	                                    Mesa[N].lado2 = Mesa[N-1].lado2;
	                                }
	                                Mesa[0].lado1 = Pec[i].lado2 ;
	                                Mesa[0].lado2 = Pec[i].lado1;
	                                mesap++;
	                                ladE=Mesa[0].lado1;
	                                Pec[i].status = 'm';
	                                if(z=='1')
	                                {
	                                    z='2';
	                                }
	                                else if(z == '2')
	                                {
	                                    z='1';
	                                }
	                                Tmesa = Tmesa+6;
	                                break;
	                            }
	                            else if(Pec[i].lado2==ladE)
	                            {
	                                for(N=mesap; N>=0; N--)
	                                {
	                                    Mesa[N].lado1 = Mesa[N-1].lado1;
	                                    Mesa[N].lado2 = Mesa[N-1].lado2;
	                                }
	                                Mesa[0].lado1 = Pec[i].lado1;
	                                Mesa[0].lado2 = Pec[i].lado2;
	                                mesap++;
	                                ladE=Mesa[0].lado1;
	                                Pec[i].status = 'm';
	                                if(z=='1')
	                                {
	                                    z='2';
	                                }
	                                else if(z == '2')
	                                {
	                                    z='1';
	                                }
	                                Tmesa = Tmesa+6;
	                                break;
	                            }
	                            else if(Pec[i].lado1 == ladD)
	                            {
	                                Mesa[mesap].lado1=Pec[i].lado1;
	                                Mesa[mesap].lado2=Pec[i].lado2;
	                                ladD=Mesa[mesap].lado2;
	                                mesap++;
	                                Pec[i].status = 'm';
	                                if(z=='1')
	                                {
	                                    z='2';
	                                }
	                                else if(z == '2')
	                                {
	                                    z='1';
	                                }
	                                Tmesa = Tmesa+6;
	                                break;
	                            }
	                            else if(Pec[i].lado2 == ladD)
	                            {
	                                Mesa[mesap].lado1=Pec[i].lado2;
	                                Mesa[mesap].lado2=Pec[i].lado1;
	                                ladD=Mesa[mesap].lado2;
	                                mesap++;
	                                Pec[i].status = 'm';
	                                if(z=='1')
	                                {
	                                    z='2';
	                                }
	                                else if(z == '2')
	                                {
	                                    z='1';
	                                }
	                                Tmesa = Tmesa+6;
	                                break;
	                            }
							}
						}
						else
						{
							fnumeracaoErrada();
						}
					}
				}
				break;
			case 2:
				if(comp==27)
				{
					fmsgcomp();
				}
				else
				{
					comp++;
					Pec[comp].status=z;	
				}
				break;
			case 3:
				cont=0;
           		if(comp==26 )
				{
					for(i=0; i<27; i++)
					{
						if(Pec[i].status == z)
                    	{
                        	if(Pec[i].lado1 == ladE || Pec[i].lado1 ==ladD || Pec[i].lado2 == ladE || Pec[i].lado2 == ladD)
                        	{
                            	cont++;
                        	}
                    	}	
					}
					if( cont == 0)
	                {
	                    empate++;
	                    if(z=='1')
	                    {
	                        z='2';
	                    }
	                    else if(z == '2')
	                    {
	                        z='1';
	                    }
	                }
	                else
	                {
	                	fcontinuajogo();
					}
				}
				else
				{
					fcontinuajogo();
				}
				break;
			case 0:
				fim=3;

            	break;

        	default:
				fmsgopinvalida();
            	break;			
		}
		cont=0;
        cont2=0;

        if(empate == 2)
        {
        	for(i=0; i<27; i++)
            {
				if (Pec[i].status=='1')
                {
                    cont++;
                }
                if(Pec[i].status=='2')
                {
                    cont2++;
                }
            }
            if(cont<cont2)
            {
                fim=1;
                fsemjoagadas();
                fcontagem();
            }
            else if(cont2<cont)
            {
                fim=2;
                fsemjoagadas();
                fcontagem();
            }
            else if(cont==cont2)
            {
                cont=0;
                cont2=0;

                for(i=0; i<27; i++)
                {
                    if(Pec[i].status=='1')
                    {
                        cont = cont + Pec[i].lado1;
                        cont = cont + Pec[i].lado2;
                    }
                    else if(Pec[i].status=='2')
                    {
                        cont2 = cont2 + Pec[i].lado1;
                        cont2 = cont2 + Pec[i].lado2;
                    }
                }
                if(cont<cont2)
                {
                    fim=1;
                    fsemjoagadas();
                	fcontagem();
                }
                if(cont2<cont)
                {
                    fim=2;
                    fsemjoagadas();
               		fcontagem();
                }
                if(cont==cont2)
                {
                    fim=4;
                    fsemjoagadas();
                	fcontagem();
                }

            }
		}
		cont=0;
        cont2=0;
        for(i=0; i<28; i++)
        {
        	if (Pec[i].status =='1')
            {
                cont++;
            }
            if(Pec[i].status == '2')
            {
                cont2++;
            }
		}
		if(cont==0 && comp==26)
        {
            fim=1;
        }
        if(cont2==0 && comp==26)
        {
            fim=2;
        }
	    
	   
	}while (fim == 0 );
	
	fmsgfimjogo(fim);
	
}
