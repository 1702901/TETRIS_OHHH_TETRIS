#include "modeTest.h"

void modeTest(const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments) {
	Joc jocTest;
	//inicializa el tablero
	jocTest.inicialitza(fitxerInicial);

}

void ModoTest::llegirFitxerFigures(const string& nomFitxer, NodeFigura* nodeFigura)
{
	ifstream fitxer;

	int tipusFigura, posX, posY, cuantitatDeGirsHoraris;

	fitxer.open(nomFitxer);
	NodeFigura aux;
	aux.setNext(nullptr);
	if (fitxer.is_open())
	{
		fitxer >> tipusFigura >> posY >> posX >> cuantitatDeGirsHoraris;

		while (!fitxer.eof())
		{
			nodeFigura->setValor(tipusFigura, posY, posX, cuantitatDeGirsHoraris);
			fitxer >> tipusFigura >> posY >> posX >> cuantitatDeGirsHoraris;
			aux.setValor(tipusFigura, posY, posX, cuantitatDeGirsHoraris);
			
		}
	}

}

void llegirFitxerMoviments(const string& nomFitxer)
{
	ifstream fitxer;

}

