/* 2018 ReVoL Primer Template */
/* curves.cpp */
#include "curves.h"

// ������ �������
#define GX (double)7
#define GY (double)2
// ��� �� X
#define DX 5

// ������ ����-�� ������
int WX = 0, WY = 0;
// ������� ����
double CX = 0, CY = 0;

/* ��������� ������ */
void setview() {
	RECT rc;
	GetClientRect(hWndGDE, &rc);
	WX = rc.right - rc.left;
	WY = rc.bottom - rc.top;
	// ����� ������� ���������
	CX = 0; CY = WY / 2;
	CX = 0; CY = WY / 2;
}

/* �������� ���������� GDC */
void draw() {
	setview();
	// ��� ���������
	MoveToEx(GDC, 0, CY, NULL);
	LineTo(GDC, WX, CY);
	MoveToEx(GDC, CX, 0, NULL);
	LineTo(GDC, CX, WY);
}
