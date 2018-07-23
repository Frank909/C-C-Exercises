#ifndef _MOUSE_H
#define _MOUSE_H

void start_mouse()
{
	asm{
		mov ax,0
		int 33h
		mov ax,1
		int 33h
	}
}

void lim_interval(int px_start,int px_end)
{
	asm{
		mov ax,7
		mov cx,px_start
		mov dx,px_end
		mov ax,8
		int 33h
	}
}

int ctrl_click()
{
	int click;
	asm{
		mov ax,3
		int 33h
		mov click,bx
	}
	return(click);
}

int pos_mouse_x()
{
	int x;
	asm{
		mov ax,3
		int 33h
		mov x,cx
	}
	return(x);
}

int pos_mouse_y()
{
	int y;
	asm{
		mov ax,3
		int 33h
		mov y,dx
	}
	return(y);
}

#endif