/* 2018 ReVoL Primer Template */
/* curves.cpp */
#include "curves.h"

//

/* контекст устройства GDC */
void draw() {
    MoveToEx(GDC, 300, 0, 0);
    LineTo(GDC, 0, 0);
    LineTo(GDC, 0, 300);
}
