#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream.h>

int d,m,y;
char mes[20]=" ";
trasf_data(int);

void main(void)
{
	clrscr();
	cout<<"Inserisci il giorno"<<endl;
	scanf("%d",&d);
	cout<<"Inserisci il mese"<<endl;
	scanf("%d",&m);
	cout<<"Inserisci l'anno "<<endl;
	scanf("%d",&y);
	printf("La data inserita Š = %d %s %d ",d,trasf_data(m),y);
	while(!kbhit());
}

trasf_data(int mese)
{
	switch (mese)
	{
		case 1:
		       /*	{
			mes= "Gennaio";
			break;
			}*/
		case 2:printf("Febbraio");
			break;
		case 3:printf("Marzo");
			break;
		case 4:printf("Aprile");
			break;
		case 5:printf("Maggio");
			break;
		case 6:printf("Giugno");
			break;
		case 7:printf("Luglio");
			break;
		case 8:printf("Agosto");
			break;
		case 9:printf("Settembre");
			break;
		case 10:printf("Ottobre");
			break;
		case 11:printf("Novembre");
			break;
		case 12:printf("Dicembre");
			break;
		default:cout<<"Mese inesistente!"<<endl;
			break;
	}
}

