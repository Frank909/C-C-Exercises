/*PROGRAMMA REALIZZATO DA VENTURA
PER IL FUNZIONAMENTO DELLA LIBRERIA MOUSE.H
� NECESSARIO SPOSTARE IL FILE NELLA CARTELLA
DELLE LIBRERIE DEL C++ */

#include <stdio.h>
#include <iostream>
#include <dos.h>
#include "graphics.h"
#include <conio.h>
#include <mouse.h>
#include <stdlib.h>

void mot_back();
void mot_off();
void mot_on();
int ctrl_sensor();
void costr_graph();

int gd = DETECT, gm, errorcode;
int ingr=0,clk,i=0,px,py,y=200,mot=0,x,npezzi,ncont=0,lung,ndif=0,nbuon=0;
char* s;
void freccette();
void main()
{
	mot_off();
	costr_graph();
	do{
		px=pos_mouse_x();
		py=pos_mouse_y();
		i++;
		setcolor(i);
		delay(80);
		outtextxy(getmaxx()-450,450,"PoWeReD by Ventura");
		clk=ctrl_click();
		if ((clk==1) && ((px>=getmaxx()-120) && (px<=getmaxx()-30)) && ((py>=240) && (py<=260)))
		{
			costr_graph();
		}
		if ((clk==1) && ((px>=10) && (px<=50)) && ((py>=30) && (py<=40)))
		{
				setfillstyle(1,8);
				npezzi+=1;
				bar(100,50,270,30);
				setcolor(15);
				itoa(npezzi,s,10);
				outtextxy(130,40,s);
		}
		if ((clk==1) && ((px>=10) && (px<=50)) && ((py>=45) && (py<=55)))
		{
				if (npezzi>0)
				{
					setfillstyle(1,8);
					npezzi-=1;
					bar(100,50,270,30);
					setcolor(15);
					itoa(npezzi,s,10);
					outtextxy(130,40,s);
				}
		}
		if ((clk==1) && ((px>=10) && (px<=50)) && ((py>=130) && (py<=140)))
		{
				setfillstyle(1,8);
				lung+=1;
				bar(100,150,270,130);
				setcolor(15);
				itoa(lung,s,10);
				outtextxy(130,140,s);
				outtextxy(160,140,"mm");
		}
		if ((clk==1) && ((px>=10) && (px<=50)) && ((py>=145) && (py<=155)))
		{
				if (lung>0)
				{
					setfillstyle(1,8);
					lung-=1;
					bar(100,150,270,130);
					setcolor(15);
					itoa(lung,s,10);
					outtextxy(130,140,s);
					outtextxy(160,140,"mm");
				}
		}
		if ((clk==1) && ((px<=getmaxx()-45) && (px>=getmaxx()-115)) && ((py>=15) && (py<=85)))
		{
			//spegne il motore
			if (mot==0)
			{
				setcolor(4);
				y+=10;
				if(y>390)
				{
					y=200;
					setfillstyle(1,1);
					bar(80,190,500,400);
				}
				outtextxy(85,y,"Il motore non � stato ancora avviato!");
			}
			else
			{
				setcolor(7);
				y+=10;
				if(y>390)
				{
					y=200;
					setfillstyle(1,1);
					bar(80,190,500,400);
				}
				outtextxy(85,y,"Il motore � stato arrestato...");
				mot=0;
				mot_off();
			}
		}
		if ((clk==1) && ((px<=getmaxx()-45) && (px>=getmaxx()-115)) && ((py>=115) && (py<=185)))
		{
			//accende il motore
			if ((lung>0) && (npezzi>0))
			{
				setfillstyle(1,1);
				bar(80,190,500,400);
				mot=1;
				setcolor(7);
				outtextxy(85,y,"Motore pronto");
				delay(400);
				outtextxy(85,y,"Motore pronto.");
				delay(400);
				outtextxy(85,y,"Motore pronto..");
				delay(400);
				outtextxy(85,y,"Motore pronto...");
				y+=10;
				outtextxy(85,y,"N�Pezzi da controllare:");
				itoa(npezzi,s,10);
				delay(250);
				outtextxy(300,y,s);
				y+=10;
				delay(250);
				outtextxy(85,y,"Lunghezza:");
				itoa(lung,s,10);
				outtextxy(180,y,s);
				outtextxy(195,y,"mm");
				y+=10;
				delay(250);
				x=320;
				for (ncont=1;ncont<=npezzi;ncont++)
				{
					clk=ctrl_click();
					px=pos_mouse_x();
					py=pos_mouse_y();
					if ((clk==1) && ((px<=getmaxx()-45) && (px>=getmaxx()-115)) && ((py>=15) && (py<=85)))
					{
						outtextxy(85,y,"Arresto in corso");
						delay(150);
						outtextxy(85,y,"Arresto in corso.");
						delay(150);
						outtextxy(85,y,"Arresto in corso..");
						delay(150);
						outtextxy(85,y,"Arresto in corso...");
						mot_off();
						y+=10;
						outtextxy(85,y,"Premi Invio per continuare...");
						getch();
						costr_graph();
						npezzi=ncont;
						mot=1;
					}
					else
					{
						outtextxy(85,y,"Premi Invio dopo aver inserito il pezzo...");
						getch();
						mot_on();
						mot=1;
						y+=10;
						if(y>390)
						{
							y=200;
							setfillstyle(1,1);
							bar(80,190,500,400);
						}
						outtextxy(85,y,"Motore avviato!");
						y+=10;
						if(y>390)
						{
							y=200;
							setfillstyle(1,1);
							bar(80,190,500,400);
						}
						itoa(ncont,s,10);
						outtextxy(85,y,s);
						outtextxy(95,y," � pezzo: controllo in corso");
						do{
							ctrl_click();
							px=pos_mouse_x();
							py=pos_mouse_y();
							if ((clk==1) && ((px<=getmaxx()-45) && (px>=getmaxx()-115)) && ((py>=15) && (py<=85)))
							{
								y+=10;
								outtextxy(85,y,"Arresto in corso");
								delay(150);
								outtextxy(85,y,"Arresto in corso.");
								delay(150);
								outtextxy(85,y,"Arresto in corso..");
								delay(150);
								outtextxy(85,y,"Arresto in corso...");
								mot_off();
								y+=10;
								outtextxy(85,y,"Premi Invio per continuare...");
								getch();
								costr_graph();
								ingr=4;
								ncont=npezzi;
								mot=1;
							}
							else
							{
								ingr=ctrl_sensor();
								switch (ingr)
								{
									case 0:
										mot=0;
										delay(150);
										outtextxy(x,y,".");
										x+=5;
										if(x==490)
										{
										y+=10;
										x=85;
										}
										if(y>390)
										{
											y=200;
											setfillstyle(1,1);
											bar(80,190,500,400);
										}
										break;
									case 1:
										mot=0;
										delay(150);
										outtextxy(x,y,".");
										x+=5;
										if (x==490)
										{
											y+=10;
											x=85;
										}
										if(y>390)
										{
											y=200;
											setfillstyle(1,1);
											bar(80,190,500,400);
										}
										break;
									case 2:
										nbuon++;
										mot_off();
										mot=1;
										y+=10;
										if(y>390)
										{
											y=200;
											setfillstyle(1,1);
											bar(80,190,500,400);
										}
										outtextxy(85,y,"Pezzo Buono!");
										break;
									case 3:
										ndif++;
										mot_back();
										y+=10;
										if(y>390)
										{
											y=200;
											setfillstyle(1,1);
											bar(80,190,500,400);
										}
										outtextxy(85,y,"Controllo Pezzo Terminato....");
										y+=10;
										if(y>390)
										{
											y=200;
											setfillstyle(1,1);
											bar(80,190,500,400);
										}
										outtextxy(85,y,"Premi Invio per fermare il motore...");
										getch();
										mot_off();
										mot=1;
										itoa(ndif,s,10);
										y+=10;
										if(y>390)
										{
											y=200;
											setfillstyle(1,1);
											bar(80,190,500,400);
										}
										outtextxy(85,y,s);
										if (ndif>0)
										{
											if (ndif>1)
												outtextxy(95,y," pezzi difettosi");
											else
												outtextxy(95,y," pezzo difettoso");
										}
										break;
								}
								if(y>390)
								{
									y=200;
									setfillstyle(1,1);
									bar(80,190,500,400);
								}
							}
						}while((ingr==1) || (ingr==0) || ((ndif==0) && (nbuon==0)));
						setfillstyle(1,8);
						bar(100,100,270,80);
						itoa(ncont,s,10);
						outtextxy(130,90,s);
						delay(250);
						y+=10;
						if(y>390)
						{
							y=200;
							setfillstyle(1,1);
							bar(80,190,500,400);
						}
						if ((mot==0) || (ncont==npezzi))
						{
							outtextxy(85,y,"Premi Invio per continuare...");
							getch();
							y+=10;
							if(y>390)
							{
								y=200;
								setfillstyle(1,1);
								bar(80,190,500,400);
							}
							outtextxy(86,y,"--------------------STATISTICHE--------------------");
							y+=10;
							if(y>390)
							{
								y=200;
								setfillstyle(1,1);
								bar(80,190,500,400);
							}
							outtextxy(85,y,"Pezzi Totali:");
							itoa(npezzi,s,10);
							outtextxy(250,y,s);
							y+=10;
							if(y>390)
							{
								y=200;
								setfillstyle(1,1);
								bar(80,190,500,400);
							}
							outtextxy(85,y,"Pezzi difettosi:");
							itoa(ndif,s,10);
							outtextxy(250,y,s);
							y+=10;
							if(y>390)
							{
								y=200;
								setfillstyle(1,1);
								bar(80,190,500,400);
							}
							outtextxy(85,y,"Pezzi accettabili:");
							itoa(nbuon,s,10);
							outtextxy(250,y,s);
							y+=10;
							if(y>390)
							{
								y=200;
								setfillstyle(1,1);
								bar(80,190,500,400);
							}
							outtextxy(86,y,"-------------------FINE SESSIONE-------------------");
							setfillstyle(1,8);
							setcolor(15);
							npezzi=0;
							bar(100,50,270,30);
							itoa(npezzi,s,10);
							outtextxy(130,40,s);
							ncont=0;
							bar(100,100,270,80);
							itoa(ncont,s,10);
							outtextxy(130,90,s);
							lung=0;
							bar(100,150,270,130);
							itoa(lung,s,10);
							outtextxy(130,140,s);
							ndif=0;
							if (y>390)
							{
								setfillstyle(1,1);
								bar(80,190,500,400);
								y=200;
							}
						}
					}
				}
			}
			else
			{
				setcolor(4);
				y+=10;
				if (y>390)
				{
					setfillstyle(1,1);
					bar(80,190,500,400);
					y=200;
				}
				outtextxy(85,y,"Inserire i dati prima dell'accensione!");
			}
		}
		if (y>390)
		{
			setfillstyle(1,1);
			bar(80,190,500,400);
			y=200;
		}
	}while(!kbhit());
	closegraph();
}

int ctrl_sensor()
{
	unsigned char val;
	asm{
		mov dx,925
		in al,dx
		mov val,al
	}
	val=val>>6;
	//randomize;val=random(4);
	return(val);
}

void mot_off()
{
	asm{
		mov al,0
		mov dx,925
		out dx,al
	}
}

void mot_on()
{
	asm{
		mov al,1
		mov dx,925
		out dx,al
	}
}

void mot_back()
{
	asm{
		mov al,2
		mov dx,925
		out dx,al
	}
}

void costr_graph()
{
	clrscr();
	initgraph(&gd,&gm,"C:\\TC\\BGI\\");
	start_mouse();
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Errore caricamento della grafica \n%s\n\n\n", grapherrormsg(errorcode));
		printf("Premi un qualsiasi tasto per uscire...");
		getch();
		exit(1);
	}
	setcolor(4);
	circle(getmaxx()-80,50,35);
	setfillstyle(1,4);
	pieslice(getmaxx()-80,50,0,360,35);
	setcolor(58);
	circle(getmaxx()-80,150,35);
	setfillstyle(1,58);
	pieslice(getmaxx()-80,150,0,360,35);
	setcolor(7);
	outtextxy(getmaxx()-40,150,"Start");
	outtextxy(getmaxx()-40,50,"Off");
	setfillstyle(1,8);
	setcolor(7);
	outtextxy(99,10,"N� pezzi");
	bar(100,50,270,30);
	outtextxy(99,60,"Contatore");
	bar(100,100,270,80);
	outtextxy(99,110,"Lunghezza");
	bar(100,150,270,130);
	setfillstyle(1,1);
	bar(80,190,500,400);
	freccette();
	setfillstyle(1,4);
	bar(getmaxx()-120,240,getmaxx()-30,260);
	outtextxy(getmaxx()-117,247,"Ripristina");
	setcolor(15);
	setcolor(7);
	outtextxy(130,40,"0");
	outtextxy(130,90,"0");
	outtextxy(130,140,"0");
	outtextxy(160,140,"mm");
	outtextxy(getmaxx()-450,420,"Premi un qualsiasi tasto per uscire...");
	ncont=0;
	lung=0;
	ndif=0;
	nbuon=0;
	y=200;
}

void freccette()
{
	setcolor(2);
	line(10,45,50,45);
	line(30,55,50,45);
	line(30,55,10,45);
	line(10,40,50,40);
	line(30,30,50,40);
	line(30,30,10,40);
	line(10,145,50,145);
	line(30,155,50,145);
	line(30,155,10,145);
	line(10,140,50,140);
	line(30,130,50,140);
	line(30,130,10,140);
}

