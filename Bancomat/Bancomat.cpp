#include <sys\stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <e:\mouse.h>
#include <dos.h>
#include <iostream.h>
#include <io.h>

struct date d;
void costr_graph_banc();
void reg();
int gdriver = DETECT, gmode, errorcode;
int op;
int i,nprem=0;
int px,py,clk,xtext;
char *path,*string,*nome,*cognome,*luognas,*nick;
void open_file(char *path);

void main()
{
	clrscr();
	cout<<"Premi Invio per accedere...."<<endl;
	getch();
	clrscr();
	cout<<"Operazioni:"<<endl;
	cout<<"1: Registrati"<<endl;
	cout<<"2: Deposito"<<endl;
	cout<<"3: Prelievo"<<endl;
	cout<<"4: Estratto conto"<<endl;
	scanf("%d",&op);
	switch(op)
	{
		case 1: reg();
			path="E:\\Reg_ut.dat";
			open_file(path);
			break;
		case 2:	costr_graph_banc();
			closegraph();
			break;
		case 3:	costr_graph_banc();
			closegraph();
			break;
		case 4:	costr_graph_banc();
			closegraph();
			break;
	}
	exit(1);
}

void costr_graph_banc()
{
	initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Errore caricamento finestra grafica: \n%s\n", grapherrormsg(errorcode));
		printf("Premi un tasto per uscire");
		getch();
		exit(1);
	}
	start_mouse();
	rectangle(30,30,230,135);
	setfillstyle(4,8);
	bar(0,0,getmaxx(),15);
	bar(0,0,15,getmaxy());
	bar(0,getmaxy(),getmaxx(),getmaxy()-15);
	bar(getmaxx(),getmaxy(),getmaxx()-15,0);
	setfillstyle(1,15);
	bar(30,30,230,55);
	setfillstyle(1,7);
	bar(30,60,90,75);
	bar(100,60,160,75);
	bar(170,60,230,75);
	bar(30,80,90,95);
	bar(100,80,160,95);
	bar(170,80,230,95);
	bar(30,100,90,115);
	bar(100,100,160,115);
	bar(170,100,230,115);
	setfillstyle(1,6);
	bar(30,120,90,135);
	bar(170,120,230,135);
	setfillstyle(1,7);
	bar(100,120,160,135);
	outtextxy(300,30,"Banca Di Puglia & Basilicata");
	setcolor(4);
	outtextxy(55,65,"1");outtextxy(125,65,"2");outtextxy(195,65,"3");
	outtextxy(55,85,"4");outtextxy(125,85,"5");outtextxy(195,85,"6");
	outtextxy(55,105,"7");outtextxy(125,105,"8");outtextxy(195,105,"9");
	outtextxy(125,125,"0");
	setcolor(0);
	outtextxy(48,125,"Canc");outtextxy(188,125,"Ok");
	xtext=215;
	do{
		px=pos_mouse_x();
		py=pos_mouse_y();
		clk=ctrl_click();
		if ((((px>=30) && (px<=90)) && ((py>=60) && (py<=75))) && clk==1)
		{
			setfillstyle(1,15);
			nprem=1;
			itoa(nprem,string,10);
			setcolor(0);
			outtextxy(xtext,45,string);
			xtext-=10;
		}
		if ((((px>=100) && (px<=160)) && ((py>=60) && (py<=75))) && clk==1)
		{
			setfillstyle(1,15);
			bar(30,30,230,55);
			nprem=2;
			itoa(nprem,string,10);
			setcolor(0);
			outtextxy(215,45,string);
		}
		if ((((px>=170) && (px<=230)) && ((py>=60) && (py<=75))) && clk==1)
		{
			setfillstyle(1,15);
			bar(30,30,230,55);
			nprem=3;
			itoa(nprem,string,10);
			setcolor(0);
			outtextxy(215,45,string);
		}
		if ((((px>=30) && (px<=90)) && ((py>=80) && (py<=95))) && clk==1)
		{
			setfillstyle(1,15);
			bar(30,30,230,55);
			nprem=4;
			itoa(nprem,string,10);
			setcolor(0);
			outtextxy(215,45,string);
		}
		if ((((px>=100) && (px<=160)) && ((py>=80) && (py<=95))) && clk==1)
		{
			setfillstyle(1,15);
			bar(30,30,230,55);
			nprem=5;
			itoa(nprem,string,10);
			setcolor(0);
			outtextxy(215,45,string);
		}
		if ((((px>=170) && (px<=230)) && ((py>=80) && (py<=95))) && clk==1)
		{
			setfillstyle(1,15);
			bar(30,30,230,55);
			nprem=6;
			itoa(nprem,string,10);
			setcolor(0);
			outtextxy(215,45,string);
		}
		if ((((px>=30) && (px<=90)) && ((py>=100) && (py<=115))) && clk==1)
		{
			setfillstyle(1,15);
			bar(30,30,230,55);
			nprem=7;
			itoa(nprem,string,10);
			setcolor(0);
			outtextxy(215,45,string);
		}
		if ((((px>=100) && (px<=160)) && ((py>=100) && (py<=115))) && clk==1)
		{
			setfillstyle(1,15);
			bar(30,30,230,55);
			nprem=8;
			itoa(nprem,string,10);
			setcolor(0);
			outtextxy(215,45,string);
		}
		if ((((px>=170) && (px<=230)) && ((py>=100) && (py<=115))) && clk==1)
		{
			setfillstyle(1,15);
			bar(30,30,230,55);
			nprem=9;
			itoa(nprem,string,10);
			setcolor(0);
			outtextxy(215,45,string);
		}
		if ((((px>=100) && (px<=160)) && ((py>=120) && (py<=135))) && clk==1)
		{
			setfillstyle(1,15);
			bar(30,30,230,55);
			nprem=0;
			itoa(nprem,string,10);
			setcolor(0);
			outtextxy(215,45,string);
		}
		i+=1;
		setcolor(i);
		outtextxy(215,450,"PoWeReD By LeOnE & VeNtUrA");
		delay(100);
	}while(!kbhit());
}

void reg()
{
	clrscr();
	cout<<"Inserisci Nick da utilizzare"<<endl;
	scanf("%s",nick);
	cout<<"Inserisci Nome"<<endl;
	scanf("%s",nome);
	cout<<"Inserisci Cognome"<<endl;
	scanf("%s",cognome);
	cout<<"Inserisci Data Di Nascita"<<endl;
	cout<<"Giorno:";
	scanf("%d",d.da_day);
	cout<<"Mese:";
	scanf("%d",d.da_mon);
	cout<<"Anno:";
	scanf("%d",d.da_year);
	cout<<"Inserisci Luogo di Nascita"<<endl;
	scanf("%s",luognas);
}


void open_file(char *path)
{
	char *dest;
	FILE *file;
	file=fopen(path,"a+");
	dest="Nick: ";
	strcat(dest,nick);
	strcat(dest,"\n");
	fprintf(file,dest);
	fclose(file);
	/*int handle;
	handle = open(path, O_CREAT,S_IREAD | S_IWRITE);
	stream = fdopen(handle, "w");
	if (stream == NULL)
		printf("fdopen failed\n");
	else
	{
		fprintf(stream, "Hello world\n");
		fclose(stream);
	}*/
}