#ifndef PARTIDA_H
#define PARTIDA_H

#include <stdio.h>
#include <string>
#include "InfoJoc.h"
#include "ownCode/DiferentsJocs.h"
#include "ownCode/modeTest.h"

using namespace std;

class Partida 
{
public:
    Partida();
    
    void actualitza();
private:
    double m_temps;
    // Atributs necessaris nom�s pels exemples d'utilitzaci� de la llibreria. 
    // S'hauran d'eliminar per la implementaci� del projecte
    void inicialitza(int mode);
    static const int MIDA = 4;
    ColorFigura m_forma[MIDA][MIDA];
    int m_fila, m_columna;
};

#endif 
