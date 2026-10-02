#include "pch.h"
#include <iostream>

using namespace System;
using namespace std;

const int cols = 200;
const int rows = 45;

void setConfig() {
    Console::SetBufferSize(cols, rows);
    Console::SetWindowSize(cols, rows);
    Console::CursorVisible = false;
}
void goToXY(int x, int y) {
    Console::SetCursorPosition(x, y);
}
void print(int x, int y) {
    goToXY(x, y);
    cout << "@";
}
void myDelete(int x, int y) {
    goToXY(x, y);
    cout << " ";
}

int main(){
    setConfig();

    const int rebotes = 3;
    int lower_limit = rows - 1;
    int upper_limit = 0;
    int dULimit = 4;
    int xC = cols / 2; int yC = 0;
    int dy = 1;
    int times = 0;


    while (1) {
        //ELMINAR LA POSICIÓN ANTERIOR
        myDelete(xC, yC);


        //=====ACTUALIZAR LAS COORDENADAS======
        yC += dy;

        //VALIDACIÓN DE COLISIÓN CON EL LÍMITE INFERIOR
        if (yC >= lower_limit) {
            dy = -1;
            upper_limit += dULimit;
            times += 1;
        }

        //VALIDACIÓN DE COLISIÓN CON EL LÍMITE SUPERIOR
        if (yC <= upper_limit) {
            dy = 1;
        }

        //VALIDACION DE QUE SE LLEGÓ AL LIMITE DE REBOTES
        if (times >= rebotes) {
            dy = 0;
            break;
        }

        //=====ACTUALIZAR LAS COORDENADAS======


        //IMPRIMIR LA ENTIDAD CON SUS NUEVAS COORDENADAS
        print(xC, yC);

        _sleep(50);
    }

    print(xC, yC);

    cin.get();
    cin.ignore();

    return 0;
}
