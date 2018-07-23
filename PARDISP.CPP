#include <stdio.h>
#include <conio.h>
#include <iostream.h>

int par_disp(int n);

main()
{       clrscr();
	int num;
	textcolor(2);
	cout<<"Programma realizzato da Ventura F."<<endl;
	cout<<""<<endl;
	cout<<"Programma che inserito in input un numero verficare"<<endl;
	cout<<"se il numero Š pari o dispari"<<endl;
	cout<<""<<endl;
	cout<<"Inserisci il numero da verificare"<<endl;
	scanf("%d",&num);
	if (par_disp(num))
		cout<<"Il numero inserito Š dispari"<<endl;
	else
		cout<<"Il numero inserito Š pari"<<endl;
		cout<<""<<endl;
	cprintf("Premi un tasto per uscire!");
	while (!kbhit());
	return 0;
}

int par_disp(int n)
{
	return(n%2);
}