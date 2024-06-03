#ifndef STRUCT_H
#define STRUCT_H

#include "math.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib> 
#include <fstream>


using namespace std;

const int COLUMNESATAULER = 11;
const int FILESTAULER = 21;
const int DIMENSIONS = 2;
const int MAX_FILA = FILESTAULER ;
const int MAX_COL = COLUMNESATAULER;
const int MAX_GIRS = 3;
const int MAX_VIDA_MAGO = 3;
const int MAX_SLIMES = 5;
const int TAMANY_SLIME = 1;
const int PENALITZACIO = 2;

typedef enum
{
    FIGURA_O_TAMANY = 4,
    FIGURA_I_TAMANY = 16,
    FIGURA_OTHERS_TAMANY=9,
    NO_FIGURA_TAMANY = 0
} TamanyFigura;

typedef enum
{ 
    FIGURA_O = 0,
    FIGURA_I,
    FIGURA_T,
    FIGURA_L,
    FIGURA_J,
    FIGURA_Z,
    FIGURA_S,
    NO_FIGURA
} TipusFigura;

// Color negre = posicio vuida
typedef enum
{
    COLOR_NEGRE,
    COLOR_BLAUCEL,
    COLOR_GROC,
    COLOR_MAGENTA,
    COLOR_TARONJA,
    COLOR_BLAUFOSC,
    COLOR_VERD,
    COLOR_VERMELL,
    NO_COLOR,
    SLIME
} ColorFigura;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

//modo test
typedef enum
{
    MOVIMENT_ESQUERRA = 0,
    MOVIMENT_DRETA = 1,
    MOVIMENT_GIR_HORARI = 2,
    MOVIMENT_GIR_ANTI_HORARI = 3,
    MOVIMENT_BAIXA = 4,
    MOVIMENT_BAIXA_FINAL = 5,
} TipusMoviment;


=======
#ifndef STRUCT_H
#define STRUCT_H

#include "math.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib> 
#include <fstream>
#include <forward_list>
#include <windows.h>
#include <mmsystem.h>
#include <thread>
#pragma comment(lib, "Winmm.lib")
using namespace std;

const int COLUMNESATAULER = 11;
const int FILESTAULER = 21;
const int DIMENSIONS = 2;
const int MAX_FILA = FILESTAULER ;
const int MAX_COL = COLUMNESATAULER;
const int MAX_GIRS = 3;
const int MAX_VIDA_MAGO = 3;
const int MAX_SLIMES = 5;
const int TAMANY_SLIME = 1;
const int PENALITZACIO = 2;

 
typedef enum
{
    TETRIS = 1,
    TEST = 2,
    PUNTIACIONS = 3,
    TOWER_TETRIS = 4,
    MUSICA = 5,
    SORTIR = 6, 
    TEST_BASIC = 7
} TipusDeOpcio;

typedef enum
{
    TETRISMUSIC = 1,
    BESTIEBOYS = 2,
    MOZART1 = 3,
    MOZART2 = 4,
    SORTIRMUSIC = 6
} MUSICAJOC;

typedef enum
{
    FIGURA_O_TAMANY = 4,
    FIGURA_I_TAMANY = 16,
    FIGURA_OTHERS_TAMANY=9,
    NO_FIGURA_TAMANY = 0
} TamanyFigura;

typedef enum
{ 
    FIGURA_O = 0,
    FIGURA_I,
    FIGURA_T,
    FIGURA_L,
    FIGURA_J,
    FIGURA_Z,
    FIGURA_S,
    NO_FIGURA
} TipusFigura;

// Color negre = posicio vuida
typedef enum
{
    COLOR_NEGRE,
    COLOR_BLAUCEL,
    COLOR_GROC,
    COLOR_MAGENTA,
    COLOR_TARONJA,
    COLOR_BLAUFOSC,
    COLOR_VERD,
    COLOR_VERMELL,
    NO_COLOR,
    SLIME
} ColorFigura;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

//modo test
typedef enum
{
    MOVIMENT_ESQUERRA = 0,
    MOVIMENT_DRETA = 1,
    MOVIMENT_GIR_HORARI = 2,
    MOVIMENT_GIR_ANTI_HORARI = 3,
    MOVIMENT_BAIXA = 4,
    MOVIMENT_BAIXA_FINAL = 5,
} TipusMoviment;


struct JugadorData
{
    int punts;
    string nom;
};

#endif