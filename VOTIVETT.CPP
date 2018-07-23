
#include <stdlib.h>
#include <iostream.h>
#include <conio.h>
#include <stdio.h>

int n,i,somma,num,sc,inf=0;
float media;
void num_input_media(float,int*);
int voti[11];

void main()
{
	clrscr();
	cout<<"Programma realizzato da Ventura e Leone G."<<endl;
	cout<<""<<endl;
	do{
		cout<<"Inserisci il numero di voti da inserire (MAX 10)"<<endl;
		scanf("%d",&n);
	}while ((n<2) || (n>10));
	num_input_media(media,voti);
	clrscr();
	cout<<""<<endl;
	cout<<""<<endl;
	cout<<""<<endl;
	cout<<"Programma terminato"<<endl;
	cout<<""<<endl;
	cout<<"Premi un tasto per uscire..."<<endl;
	while (!kbhit());
}

void num_input_media(float med,int* v)
{
	for (i=0;i<n;i++)
	{
		cout<<"Inserisci il voto"<<endl;
		scanf("%d",&v[i]);
		if ((v[i]<1) || (v[i]>10))
		{
			do{
				cout<<"Reinserisci il voto correttamente"<<endl;
				scanf("%d",&v[i]);
			}while ((v[i]<1) || (v[i]>10));
		}
		if ((v[i]>=1) && (v[i]<=10))
			somma=somma+v[i];
		if (v[i]<6)
			inf++;
	}
	clrscr();
	while (sc!=4)
	{
		clrscr();
		do{
			cout<<"Scegli un'operazione da effettuare"<<endl;
			cout<<"1:Visualizzare la media"<<endl;
			cout<<"2:Visualizzare se l'alunno Š stato promosso"<<endl;
			cout<<"3:Visualizzare il numero delle insufficienze"<<endl;
			cout<<"4:Uscita dal programma"<<endl;
			scanf("%d",&sc);
			if ((sc<1) || (sc>4))
			{
				clrscr;
				cout<<"Scelta errata!"<<endl;
				getch();
			}
		}while ((sc<1) || (sc>4));
		med=(float)somma/n;
		switch (sc)
			{
			case 1: {
				cout<<""<<endl;
				printf("La media Š=%2.1f",med);
				}
			break;
			case 2: {
				if (med<6)
					cout<<"L'alunno Š stato rimandato"<<endl;
				else
					cout<<"L'alunno Š stato ammesso alla classe successiva"<<endl;
				}
				break;
			case 3: {
				printf("Il numero delle insufficienze Š = %d",inf);
				}
				break;
			case 4: break;
			}
		getch();
	}
}
