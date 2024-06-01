#include "modeTest.h"


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
			//a�ade los valores y crea el nodo
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
			//a�ade los valores y crea el nodo
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

#include "Joc.h"


ModoTest::ModoTest()
{
	// genera numeros random 
	// https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
	srand((unsigned)time(0));
	int randomNumber;
	randomNumber = (rand() % 7);
	m_figura.cambiaFigura(randomNumber);
	m_figura.setX(COLUMNESATAULER / 2);
	m_figura.setY(0);
	m_time = 0;
	posarFigura();
	fiPartida = false;
	puntosPartida = 0;
}
// regenera la figura amb les mateixe coordenades x pero posa la y = 0 per possarla assobre


int posCentroAEsquinaY(int pos)
{
	pos -= 1;
	return pos;
}

int posCentroAEsquinaX(int pos, const int tamany, int cuantitatDeGirs)
{
	if (tamany == 16)
	{
		if (cuantitatDeGirs == 3)
			pos -= 2;
		else
		{
			if (cuantitatDeGirs != 1)
				pos -= 1;
		}
	}
	else
		pos -= 1;
	return pos;
}

void ModoTest::inicialitza(const string& nomFitxer)
{
	ifstream fitxer;
	ColorFigura color;
	int value;
	fitxer.open(nomFitxer);
	int tipusFigura, posX, posY, cuantitatDeGirsHoraris;
	// Columnes X // Files Y
	if (fitxer.is_open())
	{
		fitxer >> tipusFigura >> posY >> posX >> cuantitatDeGirsHoraris;
		m_figura.cambiaFigura(tipusFigura - 1);
		// Cal tenir en compte que pensem que la esquina de tots es a la pos +1 +1 de la esquina excepte 
		// el cuadrat, sino es asi, si haura de cambiar la funcio posCentroAEsquina
		m_figura.setY(posCentroAEsquinaY(posY));
		m_figura.setX(posCentroAEsquinaX(posX, m_figura.getTamany(), cuantitatDeGirsHoraris));
		for (int i = 0; i < cuantitatDeGirsHoraris; i++)
			m_figura.girHorari();
		for (int y = 0; y < FILESTAULER; y++)
		{
			for (int x = 0; x < COLUMNESATAULER; x++)
			{
				fitxer >> value;
				color = ColorFigura(value);
				m_tauler.setPosition(x, y, color);
			}
		}
		if (mirarSiHaColisionsFigura())
			cout << "Has perdut la partida" << endl;
		else
			posarFigura();
	}
	else
		cout << "Error al obrir l'arxiu";
	fitxer.close();

}



void ModoTest::mostrarTualer()
{
	
	cout << m_tauler;
	cout << endl;
}

void ModoTest::mostrarFigura()
{
	cout << m_figura;
}

void ModoTest::borrarFigura()
{

	for (int fila = m_figura.getY(); fila < m_figura.getY() + m_figura.getLenghLine(); fila++)
	{
		for (int columna = m_figura.getX(); columna < m_figura.getX() + m_figura.getLenghLine(); columna++)
		{
			if (ColorFigura(m_figura.getValuePos(columna - m_figura.getX(), fila - m_figura.getY())) != COLOR_NEGRE)
				m_tauler.setPosition(columna, fila, COLOR_NEGRE);
		}
	}
}

void ModoTest::posarFigura()
{
	for (int fila = m_figura.getY(); fila < m_figura.getY() + m_figura.getLenghLine(); fila++)
	{
		for (int columna = m_figura.getX(); columna < m_figura.getX() + m_figura.getLenghLine(); columna++)
		{
			if (ColorFigura(m_figura.getValuePos(columna - m_figura.getX(), fila - m_figura.getY())) != COLOR_NEGRE)
				m_tauler.setPosition(columna, fila, ColorFigura(m_figura.getColor()));
		}
	}
}

bool ModoTest::mirarSiHaColisionsFigura()
{

	bool colisio = false;
	int fila = m_figura.getX(), columna = m_figura.getY();
	ColorFigura colorDeLaPos;
	while (!colisio && fila < m_figura.getX() + m_figura.getLenghLine())
	{
		while (!colisio && columna < m_figura.getY() + m_figura.getLenghLine())
		{
			colorDeLaPos = ColorFigura(m_figura.getValuePos(fila - m_figura.getX(), columna - m_figura.getY()));
			if ((columna >= FILESTAULER || fila >= COLUMNESATAULER) && colorDeLaPos != COLOR_NEGRE)
				colisio = true;

			else
			{
				if ((columna < 0 || fila < 0) && colorDeLaPos != COLOR_NEGRE)
				{
					colisio = true;

				}
				else
				{
					if (colorDeLaPos != COLOR_NEGRE && m_tauler.getPosition(columna, fila) != COLOR_NEGRE)
					{
						colisio = true;
					}

				}
			}
			//miramos que no sea los marcos del tauler o que sea la ultima fila
			if ((colisio) && (columna >= FILESTAULER || (colorDeLaPos != COLOR_NEGRE && fila <= COLUMNESATAULER - 1 && fila > 0))) {
				puntosPartida += 10;
			}
			columna++;
		}
		fila++;
		columna = m_figura.getY();
	}

	return colisio;
}

bool ModoTest::giraFigura(DireccioGir direccio)
{
	// presuposem que hem posat un codi al inici de crear la figura
	bool colisions;
	// Borrar figura del mapa
	borrarFigura();
	// Girar figura per veure com es posaria al tauler 
	if (direccio == GIR_HORARI)
		m_figura.girHorari();
	else
		m_figura.antiHorari();
	colisions = mirarSiHaColisionsFigura();
	// Refer figura en el mapa en cas de haber colisio
	if (colisions)
	{
		if (direccio == GIR_HORARI)
			m_figura.antiHorari();
		else
			m_figura.girHorari();
	}
	// Posar la figura cuan sabem que es pot girar
	posarFigura();
	return !colisions;
};




bool ModoTest::mouFigura(int dirX)
{
	bool colisions;
	mostrarTualer();
	borrarFigura();
	mostrarTualer();
	m_figura.setX(m_figura.getX() + dirX);
	colisions = mirarSiHaColisionsFigura();
	if (colisions)
		m_figura.setX(m_figura.getX() - dirX);
	posarFigura();
	return !colisions;
}


int ModoTest::eliminarLineasCompletesBaixada()
{
	bool lineCompleta;
	int columna, fila;
	int filesEliminades = 0;
	int maxValueLine = m_figura.getY() + m_figura.getLenghLine();
	// Como valor mas bajo solo comprovamos la linea 0
	// El caso es que hay figuras que su array puede salir, pero no la figura en si
	// Por tanto de ahi la existencia de este if
	fila = m_figura.getY();
	if (fila < 0)
		fila = 0;
	if (maxValueLine > MAX_FILA)
		maxValueLine = MAX_FILA;
	for (fila; fila < maxValueLine; fila++)
	{
		lineCompleta = true;
		columna = 0;
		while (lineCompleta&& columna < COLUMNESATAULER)
		{
			if (m_tauler.getPosition(fila, columna) == COLOR_NEGRE)
				lineCompleta = false;
			columna++;
		}
		if (lineCompleta)
		{
			// -1 ja que l'ultima el seu valor es tot negre
			// el que fem es posar las dades de la fila superior de forma que es borrin unicament les
			// dades de la fila que volem eliminar
			for (int filaEliminar = fila; filaEliminar > 0; filaEliminar--)
			{
				for (int columnasEliminar = 0; columnasEliminar < COLUMNESATAULER; columnasEliminar++)
					// filaEliminar - 1 per cargar el valor de la fila de sobre
					m_tauler.setPosition(columnasEliminar, filaEliminar, ColorFigura(m_tauler.getPosition(filaEliminar - 1, columnasEliminar)));
			}
			// Posem la linea superior en negra 
			for (int columnasEliminar = 0; columnasEliminar < COLUMNESATAULER; columnasEliminar++)
				m_tauler.setPosition(columnasEliminar, 0, COLOR_NEGRE);
			filesEliminades++;
		}
	}
	punts(filesEliminades);

	return filesEliminades;
}


int ModoTest::baixaFigura()
{
	// Part on es mira si hi ha colisions
	bool colisions;
	int filesEliminades = 0;
	borrarFigura();
	m_figura.setY(m_figura.getY() + 1);
	colisions = mirarSiHaColisionsFigura();
	if (colisions)
	{
		m_figura.setY(m_figura.getY() - 1);
		posarFigura();
		filesEliminades = eliminarLineasCompletesBaixada();
	}
	// Part on hem de mirar si hem de eliminar una linea o lineas etc
	else
		posarFigura();
	// entenem segons els nostres companys que sempre hem de posar la figura, sino es el cas eliminar
	// aquesta �linea
	return filesEliminades;
}
int ModoTest::hardDrop()
{
	int filesEliminades = 0;
	borrarFigura();
	// baixa la figura fins que doni colisio
	while (!mirarSiHaColisionsFigura())
		m_figura.setY(m_figura.getY() + 1);
	// desfa el moviment que causa la colisio 
	m_figura.setY(m_figura.getY() - 1);
	// posa la figura on no fa colisio i fa el procediment vist a baixaFigura
	posarFigura();
	filesEliminades = eliminarLineasCompletesBaixada();
	return filesEliminades;
}


void ModoTest::escriuTauler(const string& nomFitxer)
{
	ofstream fitxer;
	fitxer.open(nomFitxer);
	// Columnes Y// Files X
	if (fitxer.is_open())
	{
		string lineaMostrar;
		int colum = 0;
		int y;
		for (int x = 0; x < FILESTAULER; x++)
		{
			lineaMostrar = "";
			for (y = 0; y < COLUMNESATAULER - 1; y++)
				lineaMostrar = lineaMostrar + to_string(m_tauler.getPosition(x, y)) + " ";
			lineaMostrar = lineaMostrar + to_string(m_tauler.getPosition(x, y));
			fitxer << lineaMostrar << endl;
		}
	}
	else
		cout << "Error al obrir l'arxiu";
	fitxer.close();
}

void ModoTest::inicialitzaFigura(const int tipusFiguraNova)
{
	m_figura.cambiaFigura(tipusFiguraNova);
}

void ModoTest::getFiguraPosActual(int& fila, int& columna) {
	fila = m_figura.getX();
	columna = m_figura.getY();
}

void ModoTest::punts(int nFilesEliminades)
{
	int puntos = 0;
	if (nFilesEliminades != 0) {
		switch (nFilesEliminades)
		{
		case 1:
			puntos = 100;
			break;

		case 2:
			puntos = 150;
			break;

		case 3:
			puntos = 175;
			break;
		default:
			puntos = 200;
			break;
		}
	}

	puntosPartida += puntos;
}

void ModoTest::posarFiguraDeTxt()
{
	FiguraTest figuraTest = m_infoModTest.getFigura()->getValor();
	m_figura.cambiaFigura(figuraTest.getTipusFigura()-1);
	m_figura.setY(posCentroAEsquinaY(figuraTest.getPosY()));
	m_figura.setX(posCentroAEsquinaX(figuraTest.getPosX(), m_figura.getTamany(), figuraTest.getNGirsHoraris()));
	for (int i = 0; i < figuraTest.getNGirsHoraris(); i++)
		m_figura.girHorari();
	if (mirarSiHaColisionsFigura())
		cout << "Has perdut la partida" << endl;
	else
		posarFigura();
	m_infoModTest.eliminaFirstFigura();
}

int ModoTest::getMoviment() 
{
	int moviment = m_infoModTest.getMoviment()->getValor();
	m_infoModTest.nextMov();
	return moviment;
}
