#pragma once

#include "Joc.h"
#include "struct.h"
#include "testLlista.h"
using namespace std;


class ModoTest {
public:
	ModoTest() { ; };
	void inicialitzaTabler(const string& fitxerInicial);
	void llegirFitxerFigures(const string& nomFitxer);
	void llegirFitxerMoviments(const string& nomFitxer);
	TextInfo getInfoMod() const { return m_infoModTest; };
	Joc getJoc() const { return m_gameModoTest; };

private:
	//puede guardar figura y moviments
	Joc m_gameModoTest;
	TextInfo m_infoModTest;
};