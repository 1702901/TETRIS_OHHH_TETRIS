#pragma once
#include<iostream>
#include<string>
#include "Joc.h"
#include "struct.h"
#include "testLlista.h"
using namespace std;

void modeTest(const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments);

class ModoTest {
public:
	void llegirFitxerFigures(const string& nomFitxer, NodeFigura* nodeFigura);

private:
	//puede guardar figura y moviments
	TextInfo m_modTest;
};