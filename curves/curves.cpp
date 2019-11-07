/* 2018 ReVoL Primer Template */
/* curves.cpp */
#include "curves.h"

// размер графика
#define GX (double)7
#define GY (double)2
// шаг по X
#define DX 5

// размер устр-ва вывода
int WX = 0, WY = 0;
// масштаб осей
double CX = 0, CY = 0;

/* параметры вывода */
void setview() {
	RECT rc;
	GetClientRect(hWndGDE, &rc);
	WX = rc.right - rc.left;
	WY = rc.bottom - rc.top;
	// Центр системы координат
	CX = 0; CY = WY / 2;
	CX = 0; CY = WY / 2;
}

/* контекст устройства GDC */
void draw() {
	setview();
	// Оси координат
	MoveToEx(GDC, 0, CY, NULL);
	LineTo(GDC, WX, CY);
	MoveToEx(GDC, CX, 0, NULL);
	LineTo(GDC, CX, WY);
}
