#include <stdlib.h>
#include <iostream.h>
#include <conio.h>
#include <stdio.h>


int n,i,somma,num;
float media;
void num_input(float media);

void main()
{
	clrscr();
	cout<<"Programma realizzato da Francesco Ventura."<<endl;

	do{
		cout<<"Inserisci il numero di voti da inserire (MAX 10)"<<endl;
		scanf("%d",&n);
	}while((n<1) || (n>10));
	num_input(media);
	while (!kbhit());
}

void num_input(float med)
{
	for (i=0;i<n;i++)
	{
		cout<<"Inserisci il voto"<<endl;
		scanf("%d",&num);
		if ((num<1) || (num>10))
		{
			do{
				cout<<"Reinserisci il voto correttamente!"<<endl;
				scanf("%d",&num);
			}while((num<1) || (num>10));
		}
		if ((num>=1) && (num<=10))
		somma=somma+num;
	}
	med=(float)somma/n;
	printf("La media Š = %2.1f",med);
	cout<<""<<endl;
	cout<<""<<endl;
	if (med<6)
		cout<<"L'alunno Š stato rimandato"<<endl;
	else
		cout<<"L'alunno Š stato ammesso alla classe successiva"<<endl;
	cout<<""<<endl;
	cout<<"Programma Terminato"<<endl;
	cout<<""<<endl;
	cout<<"Premi un tasto per uscire"<<endl;
	while(!kbhit());
}