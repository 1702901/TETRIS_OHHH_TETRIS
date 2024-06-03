#ifndef DIFERENT_JOCS_H
#define DIFERENT_JOCS_H
#include "Joc.h"
#include "modeTest.h"

void tetris();

void towerTetris();

void modoTest(const string& fitxerInicial, const string& fitxerFigura, const string& fitxerMoviments);



=======
#ifndef DIFERENT_JOCS_H
#define DIFERENT_JOCS_H
#include "Joc.h"
#include "modeTest.h"
#include "JocTower.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined  (_WIN64)

#include <iostream>
//Definicio necesaria per poder incloure la llibreria i que trobi el main
#define SDL_MAIN_HANDLED
#include <windows.h>
//Llibreria grafica
#include "../../Graphic Lib/libreria.h"
#include "../../Graphic Lib/NFont/NFont.h"
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

#include "../Partida.h"
#include "../InfoJoc.h"
#include "../GraphicManager.h"

void tetris(Screen& pantalla);

void towerTetris(Screen& pantalla);

void modoTest(const string& fitxerInicial, const string& fitxerFigura, const string& fitxerMoviments, Screen& pantalla);

int menuPerSeleccionar(Screen& pantalla);

int testMenu(Screen& pantalla);

int musicaMenu(Screen& pantalla);

void mostrarPuntiacions(Screen& pantalla);

void getTxtName(string& fitxerInicial, string& fitxerFigura, string& fitxerMoviments, Screen& pantalla);

#endif