#include "modeTest.h"

void ModoTest::inicialitzaTabler(const string& fitxerInicial) 
{
	//inicializa el tablero
	m_gameModoTest.inicialitza(fitxerInicial);
	
}

void ModoTest::llegirFitxerFigures(const string& nomFitxer)
{
	ifstream fitxer;

	int tipusFigura, posX, posY, cuantitatDeGirsHoraris;

	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		fitxer >> tipusFigura >> posY >> posX >> cuantitatDeGirsHoraris;

		while (!fitxer.eof())
		{
			//añade los valores y crea el nodo
			//orden final : primero->final del txt    ultimo ->primero del txt
			m_infoModTest.afegeixFigura(tipusFigura, posY, posX, cuantitatDeGirsHoraris);

			fitxer >> tipusFigura >> posY >> posX >> cuantitatDeGirsHoraris;
			
		}
		fitxer.close();
	}
	else
	{
		cout << "No s'ha pogut obrir el arxiu" << endl;
	}
	//invertimos porque el ultimo es el primero que queremos
	m_infoModTest.invertirFigura();

}

void ModoTest::llegirFitxerMoviments(const string& nomFitxer)
{
	ifstream fitxer;
	int moviment;
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		fitxer >> moviment;

		while (!fitxer.eof())
		{
			//añade los valores y crea el nodo
			//orden final : primero->final del txt    ultimo ->primero del txt
			m_infoModTest.afegeixMoviment(moviment);
			fitxer >> moviment;

		}
		fitxer.close();

	}
	else
	{
		cout << "No s'ha pogut obrir el arxiu" << endl;
	}
	//invertimos porque el ultimo es el primero que queremos
	m_infoModTest.invertirMoviment();
}

