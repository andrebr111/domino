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
void fInicializarMenu()
{
	int opr, test;
	bot = 0;
	
	do
	{
		opr = fMenuGeral(opr);
		switch (opr)
		{
			case 1:
				bot = 1;
				fIniciarjogo(Pec);
				break;
			case 2:	
				bot = 2;
				computador();
				break;
			case 3:
				if(bot == 1)
				{
					continuarjogo();
				}	
				else if(bot == 2)
				{
					continuarjogoBOT();	
				}	
				else if(bot != 1 && bot != 2)
				{
					naohajogo();	
				}	
				break;
			case 4:	
				Regras();
				break;
			case 5:
				test = salvajogo();
	            if (test == 0)
	                salvo();
	            else if(test == 1)
	                falhasalvar();
				break;
			case 6:	
				test = retornajogo();
				if (test == 0)
	            {
	                jogorecuperado();
	            }
	            else
	            {
	                falharecuperarjogo();
	            }
				break;
			case 0:
				break;
			default:
				fmsgopinvalida();
				break;							 
			}
	}while( opr != 0);
}

//inicia o jogo
void fIniciarjogo(struct Pc Pec[28])
{
	int i, u,loc,cont,cont2,fim,N,lado;
    int opr;
    char ops;
	
	bot = 1;
    aux.status = ' ';
    aux.lado1 = 0;
    aux.lado2 = 1;
    comp=13;
    mesap=1;
    lado=0;
    emp=0;
    for(i = 0; i <28; i++)
    {
        Pec[i].status = ' ';
    }
    
    fGerarPecas(Pec);
    fEmbaralharPecas(Pec);
    
    for(i = 0; i < 7; i++)
    {
        Pec[i].status = '1';
    }
	
    for(i = 7; i < 14; i++)
    {
        Pec[i].status = '2';
    }

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
    
    fprimeiro(Pec, u);
    
    Mesa[0].lado1 = aux.lado1;
    Mesa[0].lado2 = aux.lado2;
    ladE = Mesa[0].lado1;
    ladD = Mesa[0].lado2;


    if(Pec[u].status=='1')
    {
        z='2';
    }
    else
    {
        z='1';
    }
    Pec[u].status = 'm';
    
    do
    {
    	fMesa(Mesa);
    	fApresentar(Pec);
    	
    	ops = fjogar(ops, ladD, ladE);
    	
    	cont = 0;
    	switch(ops)
    	{
    		case 1:
        		loc = fescpec(loc);

	            if(loc==0)
	            {
	                break;
	            }

	            for(i=0; i<28; i++)
	            {
	                if(Pec[i].status==z)
	                {
	                    cont++;
	                }
	                if(cont==loc)
	                {
	                    if(Pec[i].lado1 == ladE || Pec[i].lado1 ==ladD || Pec[i].lado2 == ladE || Pec[i].lado2 == ladD)
	                    {
	                        emp=0;
	                        if(((Pec[i].lado1 == ladE ||  Pec[i].lado1 ==ladD ) && (Pec[i].lado2== ladE || Pec[i].lado2==ladD)) || ladE == ladD)
	                        {
	                            lado = fladmesa(lado);
	
	                            if( lado==1)
	                            {
	                                if(Pec[i].lado1 == ladE || Pec[i].lado2 == ladE)
	                                {
	
	                                    for(N=mesap; N>=0; N--)
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
	                                        else
	                                        {
	                                            z='1';
	                                        }
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
	                                        else
	                                        {
	                                            z='1';
	                                        }
	                                        break;
	                                    }
	
	                                }
	                                else
	                                {
	                                	ladoErrado();
	                                }
	
	                            }
	                            if(lado==2 )
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
	                                        else
	                                        {
	                                            z='1';
	                                        }
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
	                                        else
	                                        {
	                                            z='1';
	                                        }
	                                        break;
	                                    }
	
	                                }
	                            }
	                            if(lado == 3)
	                            {
	                                
	                                
	                                    fnumeracaoErrada();
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
	                                else
	                                {
	                                    z='1';
	                                }
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
	                                else
	                                {
	                                    z='1';
	                                }
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
	                                else
	                                {
	                                    z='1';
	                                }
	                                break;
	                            }
	                            if(Pec[i].lado2 == ladD)
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
	                                else
	                                {
	                                    z='1';
	                                }
	                                break;
	                            }
	
	
	                        }
	
	                    }
	                    else
	                    {
	                        fnumeracaoErrada();
	                        break;
	                    }
	
	
	                }
	            }
	            if(cont<loc)
	            {
	            	fmsgopinvalida();	
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
	            if(comp==27 )
	            {
	                for(i=0; i<28; i++)
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
	                    fpassou();
	                    emp++;
	                    if(z=='1')
	                    {
	                        z='2';
	                    }
	                    else
	                    {
	                        z='1';
	                    }
	
	                }
	                else if(cont != 0)
	                {
	                    fcontinuajogo();
	                }
	            }
	            else if(comp != 27)
	            {
	                fcontinuajogo();
	           	}
	            
	            break;
			case 4:
				fim = 3;
				ops = 4;
				break;
			default:
				fmsgopinvalida();
				break;				
		}
		
		cont=0;
        cont2=0;

        if(emp == 2)
        {
            for(i=0; i<27; i++)
            {
                if(Pec[i].status=='1')
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
                ops = 4;
                fsemjoagadas();
                fcontagem();
            }
            if(cont2<cont)
            {
                fim=2;
                ops = 4;
                fsemjoagadas();
                fcontagem();
            }
            if(cont==cont2)
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
                    if(Pec[i].status=='2')
                    {
                        cont2 = cont2 + Pec[i].lado1;
                        cont2 = cont2 + Pec[i].lado2;
                    }
                }
                if(cont<cont2)
                {
                    fim=1;
                    ops = 4;
                    fsemjoagadas();
                	fcontagem();
                }
                if(cont2<cont)
                {
                    fim=2;
                    ops = 4;
                    fsemjoagadas();
                	fcontagem();
                }
                if(cont==cont2)
                {
                    fim=4;
                    ops = 4;
                    fsemjoagadas();
                	fcontagem();
                }

            }
        }
        
        //ganhador em caso de empate
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

        if(cont==0 && comp==27)
        {
            fim=1;
            ops = 4;
        }
        else if(cont2==0 && comp==27)
        {
            fim=2;
            ops = 4;
        }
    	
    	
	}while(ops != 4);
	
	fmsgfimjogo(fim);
    
}

//salva o jogo 
int salvajogo()
{
	int i;

    FILE*fp;
    if ((fp = fopen("ARQPECAS", "w")) == NULL)
    {
        ARQPECASerro1();
        return 1;
    }

    for (i = 0; i < 28; i++)
    {
        if (fwrite(&Pec[i], sizeof(struct Pc), 1, fp) != 1)
        {
            ARQPECASerro2();
            break;
        }
    }

    fclose(fp);

    if ((fp = fopen("ARQMESA", "w")) == NULL)
    {
        ARQMESAerro1();
        return 1;
    }

    for (i = 0; i < mesap; i++)
    {
        if (fwrite(&Mesa[i], sizeof(struct Tmesa), 1, fp) != 1)
        {
            ARQMESAerro2();
            break;
        }
    }

    fclose(fp);

    if ((fp = fopen("ARQJogador", "w")) == NULL)
    {
        ARQJogdorerro1();
        return 1;
    }

    if (fwrite(&z, sizeof(z), 1, fp) != 1)
    {
        ARQJogdorerro2();
        return 1;
    }

    fclose(fp);

    if ((fp = fopen("ARQmesap", "w")) == NULL)
    {
    	ARQmesaperro1();
        return 1;
    }

    if (fwrite(&mesap, sizeof(mesap), 1, fp) != 1)
    {
        ARQmesaperro2();
        return 1;
    }

    fclose(fp);

    if ((fp = fopen("ARQTcomp", "w")) == NULL)
    {
        ARQTcomperro1();
        return 1;
    }

    if (fwrite(&comp, sizeof(comp), 1, fp) != 1)
    {
        ARQTcomperro2();
        return 1;
    }
    fclose(fp);

    if ((fp = fopen("ARQempate", "w")) == NULL)
    {
        ARQempateerro1();
        return 1;
    }

    if (fwrite(&emp, sizeof(emp), 1, fp) != 1)
    {
        ARQempateerro2();
        return 1;
    }
    fclose(fp);
    
    if ((fp = fopen("ARQbot", "w")) == NULL)
    {
        ARQboterro1();
        return 1;
    }

    if (fwrite(&bot, sizeof(bot), 1, fp) != 1)
    {
        ARQboterro2();
        return 1;
    }
    fclose(fp);

    return 0;
}

//carega o jogo salvo
int retornajogo()
{
	int i;

    FILE*fp;

    if ((fp = fopen("ARQmesaP", "r")) == NULL)
    {
        recARQmesaperro1();
        return 1;
    }

    if (fread(&mesap, sizeof(mesap), 1, fp) != 1)
    {
        recARQmesaperro2();
        return 1;
    }
    fclose(fp);

    if ((fp = fopen("ARQPECAS", "r")) == NULL)
    {
        recARQPECASerro1();
        return 1;
    }

    for (i = 0; i < 28; i++)
    {
        if (fread(&Pec[i], sizeof(struct Pc), 1, fp) != 1)
        {
            recARQPECASerro2();
            return 1;
        }
    }
    fclose(fp);

    if ((fp = fopen("ARQMESA", "r")) == NULL)
    {
        recARQMESAerro1();
        return 1;
    }

    for (i = 0; i < mesap; i++)
    {
        if (fread(&Mesa[i], sizeof(struct Tmesa), 1, fp) != 1)
        {
            recARQMESAerro2();
            break;
        }
    }
    fclose(fp);

    if ((fp = fopen("ARQJogador", "r")) == NULL)
    {
        recARQJogadorerro1();
        return 1;
    }
    if (fread(&z, sizeof(z), 1, fp) != 1)
    {
        recARQJogadorerro2();
        return 1;
    }
    fclose(fp);

    if ((fp = fopen("ARQTcomp", "r")) == NULL)
    {
        recARQTcomperro1();
        return 1;
    }
    if (fread(&comp, sizeof(comp), 1, fp) != 1)
    {
        recARQTcomperro2();
        return 1;
    }
    fclose(fp);

    if ((fp = fopen("ARQempate", "r")) == NULL)
    {
        recARQempateerro1();
        return 1;
    }
    if (fread(&emp, sizeof(emp), 1, fp) != 1)
    {
        recARQempateerro2();
        return 1;
    }
    fclose(fp);
    
     if ((fp = fopen("ARQbot", "r")) == NULL)
    {
        recARQboterro1();
        return 1;
    }
    if (fread(&bot, sizeof(bot), 1, fp) != 1)
    {
        recARQboterro2();
        return 1;
    }
    fclose(fp);

    return 0;
    
}

void continuarjogo()
{
	int i, u,loc,cont,cont2,fim,N,lado;
    int opr;
    char ops;
    
	ladE = Mesa[0].lado1;
    ladD = Mesa[mesap - 1].lado2;
    
	do
    {
    	fMesa(Mesa);
    	fApresentar(Pec);
    	
    	ops = fjogar(ops, ladD, ladE);
    	
    	cont = 0;
    	switch(ops)
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
	                        emp=0;
	                        if(((Pec[i].lado1 == ladE ||  Pec[i].lado1 ==ladD ) && (Pec[i].lado2== ladE || Pec[i].lado2==ladD)) || ladE == ladD)
	                        {
	                            lado = fladmesa(lado);
	
	                            if( lado==1)
	                            {
	                                if(Pec[i].lado1 == ladE || Pec[i].lado2 == ladE)
	                                {
	
	                                    for(N=mesap; N>=0; N--)
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
	                                        else
	                                        {
	                                            z='1';
	                                        }
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
	                                        else
	                                        {
	                                            z='1';
	                                        }
	                                        break;
	                                    }
	
	                                }
	                                else
	                                {
	                                	ladoErrado();
	                                }
	
	                            }
	                            if(lado==2 )
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
	                                        else
	                                        {
	                                            z='1';
	                                        }
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
	                                        else
	                                        {
	                                            z='1';
	                                        }
	                                        break;
	                                    }
	
	                                }
	                            }
	                            if(lado == 3)
	                            {
	                                
	                                
	                                    fnumeracaoErrada();
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
	                                else
	                                {
	                                    z='1';
	                                }
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
	                                else
	                                {
	                                    z='1';
	                                }
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
	                                else
	                                {
	                                    z='1';
	                                }
	                                break;
	                            }
	                            if(Pec[i].lado2 == ladD)
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
	                                else
	                                {
	                                    z='1';
	                                }
	                                break;
	                            }
	
	
	                        }
	
	                    }
	                    else
	                    {
	                        fnumeracaoErrada();
	                        break;
	                    }
	
	
	                }
	            }
	            if(cont<loc)
	            {
	            	fmsgopinvalida();	
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
	            if(comp==27 )
	            {
	                for(i=0; i<28; i++)
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
	                    fpassou();
	                    emp++;
	                    if(z=='1')
	                    {
	                        z='2';
	                    }
	                    else
	                    {
	                        z='1';
	                    }
	
	                }
	                else if(cont != 0)
	                {
	                    fcontinuajogo();
	                }
	            }
	            else if(comp != 27)
	            {
	                fcontinuajogo();
	           	}
	            
	            break;
			case 4:
				fim = 3;
				ops = 4;
				break;
			default:
				fmsgopinvalida();
				break;				
		}
		
		cont=0;
        cont2=0;

        if(emp == 2)
        {
            for(i=0; i<27; i++)
            {
                if(Pec[i].status=='1')
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
                ops = 4;
                fsemjoagadas();
                fcontagem();
            }
            if(cont2<cont)
            {
                fim=2;
                ops = 4;
                fsemjoagadas();
                fcontagem();
            }
            if(cont==cont2)
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
                    if(Pec[i].status=='2')
                    {
                        cont2 = cont2 + Pec[i].lado1;
                        cont2 = cont2 + Pec[i].lado2;
                    }
                }
                if(cont<cont2)
                {
                    fim=1;
                    ops = 4;
                    fsemjoagadas();
                	fcontagem();
                }
                if(cont2<cont)
                {
                    fim=2;
                    ops = 4;
                    fsemjoagadas();
                	fcontagem();
                }
                if(cont==cont2)
                {
                    fim=4;
                    ops = 4;
                    fsemjoagadas();
                	fcontagem();
                }

            }
        }
        
        //ganhador em caso de empate
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

        if(cont==0 && comp==27)
        {
            fim=1;
            ops = 4;
        }
        if(cont2==0 && comp==27)
        {
            fim=2;
            ops = 4;
        }
    	
    	
	}while(ops != 4);
	
	fmsgfimjogo(fim);
}

void computador()
{
	int i, u,loc,cont,cont2,fim,N,lado;
    int opr, marca;
    char ops;

	bot = 2;
    aux.status = ' ';
    aux.lado1 = 0;
    aux.lado2 = 1;
    comp=13;
    mesap=1;
    lado=0;
    emp=0;
    
    for(i = 0; i <28; i++)
    {
        Pec[i].status = ' ';
    }
    
    fGerarPecas(Pec);
    fEmbaralharPecas(Pec);
    
    for(i = 0; i < 7; i++)
    {
        Pec[i].status = '1';
    }
	
    for(i = 7; i < 14; i++)
    {
        Pec[i].status = '2';
    }

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
    
    fprimeiro(Pec, u);
    
    Mesa[0].lado1 = aux.lado1;
    Mesa[0].lado2 = aux.lado2;
    ladE = Mesa[0].lado1;
    ladD = Mesa[0].lado2;


    if(Pec[u].status=='1')
    {
        z='2';
    }
    else
    {
        z='1';
    }
    Pec[u].status = 'm';
    
    do
    {
    	if(z == '1')
    	{
    		fMesa(Mesa);
	    	fApresentar(Pec);
	    	
	    	ops = fjogar(ops, ladD, ladE);
	    	
	    	cont = 0;
	    	switch(ops)
	    	{
	    		case 1:
	        		loc = fescpec(loc);
	
		            if(loc==0)
		            {
		                break;
		            }
	
		            for(i=0; i<28; i++)
		            {
		                if(Pec[i].status==z)
		                {
		                    cont++;
		                }
		                if(cont==loc)
		                {
		                    if(Pec[i].lado1 == ladE || Pec[i].lado1 ==ladD || Pec[i].lado2 == ladE || Pec[i].lado2 == ladD)
		                    {
		                        emp=0;
		                        if(((Pec[i].lado1 == ladE ||  Pec[i].lado1 ==ladD ) && (Pec[i].lado2== ladE || Pec[i].lado2==ladD)) || ladE == ladD)
		                        {
		                            lado = fladmesa(lado);
		
		                            if( lado==1)
		                            {
		                                if(Pec[i].lado1 == ladE || Pec[i].lado2 == ladE)
		                                {
		
		                                    for(N=mesap; N>=0; N--)
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
		                                        else
		                                        {
		                                            z='1';
		                                        }
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
		                                        else
		                                        {
		                                            z='1';
		                                        }
		                                        break;
		                                    }
		
		                                }
		                                else
		                                {
		                                	ladoErrado();
		                                }
		
		                            }
		                            if(lado==2 )
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
		                                        else
		                                        {
		                                            z='1';
		                                        }
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
		                                        else
		                                        {
		                                            z='1';
		                                        }
		                                        break;
		                                    }
		
		                                }
		                            }
		                            if(lado == 3)
		                            {
		                                
		                                
		                                    fnumeracaoErrada();
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
		                                else
		                                {
		                                    z='1';
		                                }
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
		                                else
		                                {
		                                    z='1';
		                                }
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
		                                else
		                                {
		                                    z='1';
		                                }
		                                break;
		                            }
		                            if(Pec[i].lado2 == ladD)
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
		                                else
		                                {
		                                    z='1';
		                                }
		                                break;
		                            }
		
		
		                        }
		
		                    }
		                    else
		                    {
		                        fnumeracaoErrada();
		                        break;
		                    }
		
		
		                }
		            }
		            if(cont<loc)
		            {
		            	fmsgopinvalida();	
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
		            if(comp==27 )
		            {
		                for(i=0; i<28; i++)
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
		                    fpassou();
		                    emp++;
		                    if(z=='1')
		                    {
		                        z='2';
		                    }
		                    else
		                    {
		                        z='1';
		                    }
		
		                }
		                else if(cont != 0)
		                {
		                    fcontinuajogo();
		                }
		            }
		            else if(comp != 27)
		            {
		                fcontinuajogo();
		           	}
		            
		            break;
				case 4:
					fim = 3;
					ops = 4;
					break;
				default:
					fmsgopinvalida();
					break;				
			}
			
			cont=0;
	        cont2=0;
	
	        if(emp == 2)
	        {
	            for(i=0; i<27; i++)
	            {
	                if(Pec[i].status=='1')
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
	                ops = 4;
	                fsemjoagadas();
	                fcontagem();
	            }
	            if(cont2<cont)
	            {
	                fim=2;
	                ops = 4;
	                fsemjoagadas();
	                fcontagem();
	            }
	            if(cont==cont2)
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
	                    if(Pec[i].status=='2')
	                    {
	                        cont2 = cont2 + Pec[i].lado1;
	                        cont2 = cont2 + Pec[i].lado2;
	                    }
	                }
	                if(cont<cont2)
	                {
	                    fim=1;
	                    ops = 4;
	                    fsemjoagadas();
	                	fcontagem();
	                }
	                if(cont2<cont)
	                {
	                    fim=2;
	                    ops = 4;
	                    fsemjoagadas();
	                	fcontagem();
	                }
	                if(cont==cont2)
	                {
	                    fim=4;
	                    ops = 4;
	                    fsemjoagadas();
	                	fcontagem();
	                }
	
	            }
	        }
	        
	        //ganhador em caso de empate
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
	
	        if(cont==0 && comp==27)
	        {
	            fim=1;
	            ops = 4;
	        }
	        else if(cont2==0 && comp==27)
	        {
	            fim=2;
	            ops = 4;
	        }
		}
		
		if(z == '2' && ops != 4)
		{
			do
            {
                marca = 0;
                for (i = 0; i < 28; i++)
                {
                    if (Pec[i].status == '2')
                    {
                        if (Pec[i].lado1 == ladE || Pec[i].lado1 == ladD || Pec[i].lado2 == ladE || Pec[i].lado2 == ladD)
                        {
                            marca = 1;
                            emp = 0;
                            pecajogadabot();
                            if (Pec[i].lado1 == ladE)
                            {
                                for (N = mesap; N >= 0; N--)
                                {
                                    Mesa[N].lado1 = Mesa[N - 1].lado1;
                                    Mesa[N].lado2 = Mesa[N - 1].lado2;
                                }
                                Mesa[0].lado1 = Pec[i].lado2;
                                Mesa[0].lado2 = Pec[i].lado1;
                                mesap++;
                                ladE = Mesa[0].lado1;
                                Pec[i].status = 'm';
                                if (z == '1')
                                {
                                    z = '2';
                                }
                                else
                                {
                                    z = '1';
                                }
                                break;
                            }
                            else if(Pec[i].lado2 == ladE)
                            {
                                for (N = mesap; N >= 0; N--)
                                {
                                    Mesa[N].lado1 = Mesa[N - 1].lado1;
                                    Mesa[N].lado2 = Mesa[N - 1].lado2;
                                }
                                Mesa[0].lado1 = Pec[i].lado1;
                                Mesa[0].lado2 = Pec[i].lado2;
                                mesap++;
                                ladE = Mesa[0].lado1;
                                Pec[i].status = 'm';
                                if (z == '1')
                                {
                                    z = '2';
                                }
                                else
                                {
                                    z = '1';
                                }
                                break;
                            }
                            else if(Pec[i].lado1 == ladD)
                            {
                                Mesa[mesap].lado1 = Pec[i].lado1;
                                Mesa[mesap].lado2 = Pec[i].lado2;
                                ladD = Mesa[mesap].lado2;
                                mesap++;
                                Pec[i].status = 'm';
                                if (z == '1')
                                {
                                    z = '2';
                                }
                                else
                                {
                                    z = '1';
                                }
                                break;
                            }
                            else if (Pec[i].lado2 == ladD)
                            {
                                Mesa[mesap].lado1 = Pec[i].lado2;
                                Mesa[mesap].lado2 = Pec[i].lado1;
                                ladD = Mesa[mesap].lado2;
                                mesap++;
                                Pec[i].status = 'm';
                                if (z == '1')
                                {
                                    z = '2';
                                }
                                else
                                {
                                    z = '1';
                                }
                                break;
                            }
                        }
                    }
                }
                if (marca == 0)
                {
                    if (comp == 27)
                    {
                        marca = 0;
                    }
                    else
                    {
                        comp++;
                        marca = 1;
                        pecacompradabot();
                        Pec[comp].status = z;
                    }
                }
                if(marca == 0)
                {
                    z = '1';
                    emp++;
                    vezpassadabot();
                }

                cont = 0;
                cont2 = 0;

                if (emp == 2)
                {
                    for (i = 0; i < 27; i++)
                    {
                        if (Pec[i].status == '1')
                        {
                            cont++;
                        }
                        if (Pec[i].status == '2')
                        {
                            cont2++;
                        }
                    }
                    if (cont < cont2)
                    {
                        fim = 1;
                        ops = 4;
                        fsemjoagadas();
	                	fcontagem();
                    }
                    if (cont2 < cont)
                    {
                        fim = 2;
                        ops = 4;
                        fsemjoagadas();
	                	fcontagem();
                    }
                    if (cont == cont2)
                    {
                        cont = 0;
                        cont2 = 0;

                        for (i = 0; i < 27; i++)
                        {
                            if (Pec[i].status == '1')
                            {
                                cont = cont + Pec[i].lado1;
                                cont = cont + Pec[i].lado2;
                            }
                            if (Pec[i].status == '2')
                            {
                                cont2 = cont2 + Pec[i].lado1;
                                cont2 = cont2 + Pec[i].lado2;
                            }
                        }
                        if (cont < cont2)
                        {
                            fim = 1;
                            ops = 4;
                            fsemjoagadas();
	                		fcontagem();
                        }
                        if (cont2 < cont)
                        {
                            fim = 2;
                            ops = 4;
                            fsemjoagadas();
	                		fcontagem();
                        }
                        if (cont == cont2)
                        {
                            fim = 4;
                            ops = 4;
                            fsemjoagadas();
	                		fcontagem();
                        }
                    }
                }

                cont = 0;
                cont2 = 0;

                // loop para descborir quem ganhara o jogo em caso de empate
                for (i = 0; i < 28; i++)
                {
                    if (Pec[i].status == '1')
                    {
                        cont++;
                    }
                    if (Pec[i].status == '2')
                    {
                        cont2++;
                    }
                }

                if (cont == 0 && comp == 27)
                {
                    fim = 1;
                    ops = 4;
                }
                if (cont2 == 0 && comp == 27)
                {
                    fim = 2;
                    ops = 3;
                }

            } while (z != '1');
		}
		
	}while(ops != 4);
	
	fmsgfimjogo(fim);
}

void continuarjogoBOT()
{
	
	int i, u,loc,cont,cont2,fim,N,lado;
    int opr, marca;
    char ops;
    
    ladE = Mesa[0].lado1;
    ladD = Mesa[mesap - 1].lado2;

    do
    {
    	if(z == '1')
    	{
    		fMesa(Mesa);
	    	fApresentar(Pec);
	    	
	    	ops = fjogar(ops, ladD, ladE);
	    	
	    	cont = 0;
	    	switch(ops)
	    	{
	    		case 1:
	        		loc = fescpec(loc);
	
		            if(loc==0)
		            {
		                break;
		            }
	
		            for(i=0; i<28; i++)
		            {
		                if(Pec[i].status==z)
		                {
		                    cont++;
		                }
		                if(cont==loc)
		                {
		                    if(Pec[i].lado1 == ladE || Pec[i].lado1 ==ladD || Pec[i].lado2 == ladE || Pec[i].lado2 == ladD)
		                    {
		                        emp=0;
		                        if(((Pec[i].lado1 == ladE ||  Pec[i].lado1 ==ladD ) && (Pec[i].lado2== ladE || Pec[i].lado2==ladD)) || ladE == ladD)
		                        {
		                            lado = fladmesa(lado);
		
		                            if( lado==1)
		                            {
		                                if(Pec[i].lado1 == ladE || Pec[i].lado2 == ladE)
		                                {
		
		                                    for(N=mesap; N>=0; N--)
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
		                                        else
		                                        {
		                                            z='1';
		                                        }
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
		                                        else
		                                        {
		                                            z='1';
		                                        }
		                                        break;
		                                    }
		
		                                }
		                                else
		                                {
		                                	ladoErrado();
		                                }
		
		                            }
		                            if(lado==2 )
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
		                                        else
		                                        {
		                                            z='1';
		                                        }
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
		                                        else
		                                        {
		                                            z='1';
		                                        }
		                                        break;
		                                    }
		
		                                }
		                            }
		                            if(lado == 3)
		                            {
		                                
		                                
		                                    fnumeracaoErrada();
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
		                                else
		                                {
		                                    z='1';
		                                }
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
		                                else
		                                {
		                                    z='1';
		                                }
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
		                                else
		                                {
		                                    z='1';
		                                }
		                                break;
		                            }
		                            if(Pec[i].lado2 == ladD)
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
		                                else
		                                {
		                                    z='1';
		                                }
		                                break;
		                            }
		
		
		                        }
		
		                    }
		                    else
		                    {
		                        fnumeracaoErrada();
		                        break;
		                    }
		
		
		                }
		            }
		            if(cont<loc)
		            {
		            	fmsgopinvalida();	
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
		            if(comp==27 )
		            {
		                for(i=0; i<28; i++)
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
		                    fpassou();
		                    emp++;
		                    if(z=='1')
		                    {
		                        z='2';
		                    }
		                    else
		                    {
		                        z='1';
		                    }
		
		                }
		                else if(cont != 0)
		                {
		                    fcontinuajogo();
		                }
		            }
		            else if(comp != 27)
		            {
		                fcontinuajogo();
		           	}
		            
		            break;
				case 4:
					fim = 3;
					ops = 4;
					break;
				default:
					fmsgopinvalida();
					break;				
			}
			
			cont=0;
	        cont2=0;
	
	        if(emp == 2)
	        {
	            for(i=0; i<27; i++)
	            {
	                if(Pec[i].status=='1')
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
	                ops = 4;
	                fsemjoagadas();
	                fcontagem();
	            }
	            if(cont2<cont)
	            {
	                fim=2;
	                ops = 4;
	                fsemjoagadas();
	                fcontagem();
	            }
	            if(cont==cont2)
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
	                    if(Pec[i].status=='2')
	                    {
	                        cont2 = cont2 + Pec[i].lado1;
	                        cont2 = cont2 + Pec[i].lado2;
	                    }
	                }
	                if(cont<cont2)
	                {
	                    fim=1;
	                    ops = 4;
	                    fsemjoagadas();
	                	fcontagem();
	                }
	                if(cont2<cont)
	                {
	                    fim=2;
	                    ops = 4;
	                    fsemjoagadas();
	                	fcontagem();
	                }
	                if(cont==cont2)
	                {
	                    fim=4;
	                    ops = 4;
	                    fsemjoagadas();
	                	fcontagem();
	                }
	
	            }
	        }
	        
	        //ganhador em caso de empate
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
	
	        if(cont==0 && comp==27)
	        {
	            fim=1;
	            ops = 4;
	        }
	        else if(cont2==0 && comp==27)
	        {
	            fim=2;
	            ops = 4;
	        }
		}
		
		if(z == '2' && ops != 4)
		{
			do
            {
                marca = 0;
                for (i = 0; i < 28; i++)
                {
                    if (Pec[i].status == '2')
                    {
                        if (Pec[i].lado1 == ladE || Pec[i].lado1 == ladD || Pec[i].lado2 == ladE || Pec[i].lado2 == ladD)
                        {
                            marca = 1;
                            emp= 0;
                            pecajogadabot();
                            if (Pec[i].lado1 == ladE)
                            {
                                for (N = mesap; N >= 0; N--)
                                {
                                    Mesa[N].lado1 = Mesa[N - 1].lado1;
                                    Mesa[N].lado2 = Mesa[N - 1].lado2;
                                }
                                Mesa[0].lado1 = Pec[i].lado2;
                                Mesa[0].lado2 = Pec[i].lado1;
                                mesap++;
                                ladE = Mesa[0].lado1;
                                Pec[i].status = 'm';
                                if (z == '1')
                                {
                                    z = '2';
                                }
                                else
                                {
                                    z = '1';
                                }
                                break;
                            }
                            else if(Pec[i].lado2 == ladE)
                            {
                                for (N = mesap; N >= 0; N--)
                                {
                                    Mesa[N].lado1 = Mesa[N - 1].lado1;
                                    Mesa[N].lado2 = Mesa[N - 1].lado2;
                                }
                                Mesa[0].lado1 = Pec[i].lado1;
                                Mesa[0].lado2 = Pec[i].lado2;
                                mesap++;
                                ladE = Mesa[0].lado1;
                                Pec[i].status = 'm';
                                if (z == '1')
                                {
                                    z = '2';
                                }
                                else
                                {
                                    z = '1';
                                }
                                break;
                            }
                            else if(Pec[i].lado1 == ladD)
                            {
                                Mesa[mesap].lado1 = Pec[i].lado1;
                                Mesa[mesap].lado2 = Pec[i].lado2;
                                ladD = Mesa[mesap].lado2;
                                mesap++;
                                Pec[i].status = 'm';
                                if (z == '1')
                                {
                                    z = '2';
                                }
                                else
                                {
                                    z = '1';
                                }
                                break;
                            }
                            else if (Pec[i].lado2 == ladD)
                            {
                                Mesa[mesap].lado1 = Pec[i].lado2;
                                Mesa[mesap].lado2 = Pec[i].lado1;
                                ladD = Mesa[mesap].lado2;
                                mesap++;
                                Pec[i].status = 'm';
                                if (z == '1')
                                {
                                    z = '2';
                                }
                                else
                                {
                                    z = '1';
                                }
                                break;
                            }
                        }
                    }
                }
                if (marca == 0)
                {
                    if (comp == 27)
                    {
                        marca = 0;
                    }
                    else
                    {
                        comp++;
                        marca = 1;
                        pecacompradabot();
                        Pec[comp].status = z;
                    }
                }
                if(marca == 0)
                {
                    z = '1';
                    emp++;
                    vezpassadabot();
                }

                cont = 0;
                cont2 = 0;

                if (emp == 2)
                {
                    for (i = 0; i < 27; i++)
                    {
                        if (Pec[i].status == '1')
                        {
                            cont++;
                        }
                        if (Pec[i].status == '2')
                        {
                            cont2++;
                        }
                    }
                    if (cont < cont2)
                    {
                        fim = 1;
                        ops = 4;
                        fsemjoagadas();
	                	fcontagem();
                    }
                    if (cont2 < cont)
                    {
                        fim = 2;
                        ops = 4;
                        fsemjoagadas();
	                	fcontagem();
                    }
                    if (cont == cont2)
                    {
                        cont = 0;
                        cont2 = 0;

                        for (i = 0; i < 27; i++)
                        {
                            if (Pec[i].status == '1')
                            {
                                cont = cont + Pec[i].lado1;
                                cont = cont + Pec[i].lado2;
                            }
                            if (Pec[i].status == '2')
                            {
                                cont2 = cont2 + Pec[i].lado1;
                                cont2 = cont2 + Pec[i].lado2;
                            }
                        }
                        if (cont < cont2)
                        {
                            fim = 1;
                            ops = 4;
                            fsemjoagadas();
	                		fcontagem();
                        }
                        if (cont2 < cont)
                        {
                            fim = 2;
                            ops = 4;
                            fsemjoagadas();
	                		fcontagem();
                        }
                        if (cont == cont2)
                        {
                            fim = 4;
                            ops = 4;
                            fsemjoagadas();
	                		fcontagem();
                        }
                    }
                }

                cont = 0;
                cont2 = 0;

                // loop para descborir quem ganhara o jogo em caso de empate
                for (i = 0; i < 28; i++)
                {
                    if (Pec[i].status == '1')
                    {
                        cont++;
                    }
                    if (Pec[i].status == '2')
                    {
                        cont2++;
                    }
                }

                if (cont == 0 && comp == 27)
                {
                    fim = 1;
                    ops = 4;
                }
                if (cont2 == 0 && comp == 27)
                {
                    fim = 2;
                    ops = 4;
                }

            } while (z != '1');
		}
		
	}while(ops != 4);
	
	fmsgfimjogo(fim);
	
}


