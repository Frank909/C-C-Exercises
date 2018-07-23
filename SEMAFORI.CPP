#include <dos.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>

struct time t;
unsigned char val;
void controllo(int,int);
void lampeggia();
void v_r();
void r_v();
void g_r();
void r_g();
void leggi_sensori();

void main()
{
	do{
		clrscr();
		gettime(&t);
		if ((t.ti_hour>=23) || (t.ti_hour<5))
			lampeggia();
		else
		{
			v_r();
			leggi_sensori();
			g_r();
			leggi_sensori();
			r_v();
			leggi_sensori();
			r_g();
			leggi_sensori();
		}
	}while(!kbhit());
}

void lampeggia()
{
	val=18;
	asm{
		mov al,val
		mov dx,925
		out dx,al
	}
	delay(600);
	val=0;
	asm{
		mov al,val
		mov dx,925
		out dx,al
	}
	delay(600);
}

void v_r()
{
	val=33;
	asm{
		mov al,val
		mov dx,925
		out dx,al
	}
	controllo(5000,1);
}

void r_v()
{
	val=12;
	asm{
		mov al,val
		mov dx,925
		out dx,al
	}
	controllo(2500,1);
}

void g_r()
{
	val=17;
	asm{
		mov al,val
		mov dx,925
		out dx,al
	}
	controllo(5000,3);
}

void r_g()
{
	val=10;
	asm{
		mov al,val
		mov dx,925
		out dx,al
	}
	controllo(2500,3);
}

void leggi_sensori()
{
	asm{
		mov dx,925
		in al,dx
		mov val,al
	}
	val=val>>6;
}

void controllo(int n, int ingr)
{
	int i;
	n=n/50;
	for(i=0;i<n;i++)
	{
		asm{
			mov dx,925
			in al,dx
			mov val,al
		}
		val=val>>6;
		if (val==ingr)
			printf("Sei passato con il rosso!");
		delay(50);
	}

}














