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
#include "./ownCode/test.h"



#include"ownCode/music.h"



int main(int argc, const char* argv[])
{
    ///*
    string fitxerInicial = "../../1. Resources/data/Games/partida.txt";
    string figuresTxt= "../../1. Resources/data/Games/figures.txt";
    string movimentsTxt = "../../1. Resources/data/Games/moviments.txt";
    //modoTest(fitxerInicial,figuresTxt,movimentsTxt);
    //*/
    //tetris();
    Screen pantalla(SCREEN_SIZE_X, SCREEN_SIZE_Y);
    SDL_SetMainReady();
    SDL_Init(SDL_INIT_VIDEO);
    PlaySound("../../1. Resources/data/music/Tetris.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    int selectedOperation = menuPerSeleccionar(pantalla);
    while (selectedOperation != 6 && !Keyboard_GetKeyTrg(KEYBOARD_ESCAPE))
    {
        switch (selectedOperation)
        {
        case TETRIS:
            tetris(pantalla);
            break;
        case TEST:
            switch (testMenu(pantalla))
            {
            case TEST:
                getTxtName(fitxerInicial, figuresTxt, movimentsTxt, pantalla);
                modoTest(fitxerInicial, figuresTxt, movimentsTxt, pantalla);
                break;
            case TEST_BASIC:
                modoTest(fitxerInicial, figuresTxt, movimentsTxt, pantalla);
                break;
            default:
                break;
            }
            break;
        case PUNTIACIONS:
            mostrarPuntiacions(pantalla);
            break;
        case TOWER_TETRIS:
            towerTetris(pantalla);
            break;
        case MUSICA:
            PlaySound(NULL, 0, 0);
            musicaMenu(pantalla);
            
            break;
        default:
            break;
        }
        pantalla.processEvents();

        selectedOperation = menuPerSeleccionar(pantalla);
    }
    SDL_Quit();
  
 
    return 0;
}



