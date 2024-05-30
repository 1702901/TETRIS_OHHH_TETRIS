//
//  main.cpp
//
//  Copyright � 2018 Compiled Creations Limited. All rights reserved.
//

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined  (_WIN64)

#include <iostream>
//Definicio necesaria per poder incloure la llibreria i que trobi el main
#define SDL_MAIN_HANDLED
#include <windows.h>
//Llibreria grafica
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"
#include <conio.h>      /* getch */ 

#elif __APPLE__
//Llibreria grafica
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#include <SDL2/SDL.h>
#pragma clang diagnostic pop

#endif



#include "./Partida.h"
#include "./InfoJoc.h"
#include "E:\programacion\TETRIS_OHHH_TETRIS\0. C++ Code\Logic Game\ownCode\test.h"
int main(int argc, const char* argv[])
{
    string datos= "data\/Games\/datos.txt";
    ferLlegirFiguraTest(datos);
    
    //tetris();
    return 0;
}



