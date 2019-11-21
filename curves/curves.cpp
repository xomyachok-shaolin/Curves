/* 2018 ReVoL Primer Template */
/* curves.cpp */
#include "curves.h"

// ������ �������
#define GX (double)30
#define GY (double)1
// ��� �� X
#define DX 5

// ������ ����-�� ������
int WX = 0, WY = 0;
// ������� ����
double SX = 0, SY = 0;
// ����� ������� ���������
double CX = 0, CY = 0;

/* ��������� ������ */
void setview() {
	RECT rc;
	GetClientRect(hWndGDE, &rc);
	WX = rc.right - rc.left;
	WY = rc.bottom - rc.top;
	// ����� ������� ���������
	CX = 0; CY = WY / 2;
	// ��������� �������
	// ��������� �������� ���. ������ � ��. ������� � �������� ����
	SX = GX / WX; SY = GY / WY;
}
/* ������������� ��� Y */
void pixel(HDC hdc, int X, int Y) {
	SetPixel(hdc, X, CY - Y, RGB(255, 0, 0));
}
/* ������������� ��� Y */
void moveTo(HDC hdc, int X, int Y) {
	MoveToEx(hdc, X, CY - Y, 0);
}
/* ������������� ��� Y */
void lineTo(HDC hdc, int X, int Y) {
	LineTo(hdc, X, CY - Y);
}
/* ������� ������� */
double funca(double x) {
	return sin(x);
}
/* ������ ������ ������� */
void byPoints(HDC hdc) {
	double x, y;
	for (x = 0; x < WX; x++) {
		y = funca(x * SX);
		pixel(hdc, x, y / SY);
	}
}
/* ������ ������ ������� */
void byLines(HDC hdc) {
	double x = 0, 
		   y = funca(x);
	moveTo(hdc, x, y);

	for (x = DX; x < WX; x += DX) {
		y = funca(x * SX);
		lineTo(hdc, x, y / SY);
	}
}
/* �������� ���������� GDC */
void draw() {
	setview();
	// ��� ���������
	MoveToEx(GDC, 0, CY, NULL);
	LineTo(GDC, WX, CY);
	MoveToEx(GDC, CX, 0, NULL);
	LineTo(GDC, CX, WY);

	byPoints(GDC);
	byLines(GDC);

}
