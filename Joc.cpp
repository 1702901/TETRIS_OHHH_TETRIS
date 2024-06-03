#include "Joc.h"


Joc::Joc()
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
	m_puntsPartida = 0;
	m_timeDown = 1; // 1 segon de baixada 
	llegirPuntuacions();
}

void Joc::llegirPuntuacions()
{
	ifstream fitxer;
	int puntsJugador;
	string noms;
	fitxer.open("../../1. Resources/data/Punts/puntiacions.txt");
	fitxer >> puntsJugador >> noms;
	if (!fitxer.eof())
	{
		while (!fitxer.eof())
		{
			m_dataPunts.push_front(puntsJugador);
			m_dataNoms.push_front(noms);
			fitxer >> puntsJugador >> noms;
		}
	}
	else
	{
		if (noms != "")
		{
			m_dataPunts.push_front(puntsJugador);
			m_dataNoms.push_front(noms);
		}
	}
	
	fitxer.close();
}

void Joc::escriuPuntuacions(const string& nomNouJugador)
{
	ofstream fitxer;
	fitxer.open("../../1. Resources/data/Punts/puntiacions.txt");
	m_dataPunts.push_front(m_puntsPartida);
	m_dataNoms.push_front(nomNouJugador);
	forward_list<int> copyData  = m_dataPunts;

	m_dataPunts.sort();
	forward_list<int>::iterator dataJugador = m_dataPunts.begin();
	forward_list<int>::iterator dataJugadorCercat;
	forward_list<string>::iterator dataJugadorCercatNom;
 
	int posNom;
	bool *arrayOfUsedPos = new bool[m_dataPunts.max_size()];
	for (int i = 0; i < distance(m_dataPunts.begin(), m_dataPunts.end()); i++)
		arrayOfUsedPos[i] = false;
	while (dataJugador != m_dataPunts.end() && !copyData.empty())
	{
		posNom = 0;
		dataJugadorCercat = copyData.begin();
		dataJugadorCercatNom = m_dataNoms.begin();
		// cicle de cerca de la dada amb el la mateixa puntuacio
		
		while (*dataJugador != *dataJugadorCercat || arrayOfUsedPos[posNom])
		{
			posNom++;
			dataJugadorCercat++;
		}
		for (int i = 0; i < posNom; i++)
			dataJugadorCercatNom++;
		// part de escritura de les dades ordenades al fitxer
		fitxer << *dataJugador << " " << *dataJugadorCercatNom << endl;
		arrayOfUsedPos[posNom] = true;
		dataJugador++;
	}
	delete[] arrayOfUsedPos;
	fitxer.close();
}


// regenera la figura amb les mateixe coordenades x pero posa la y = 0 per possarla assobre
void Joc::novaFigura()
{
	srand((unsigned)time(0));
	int randomNumber;
	randomNumber = (rand() % 7);
	int lenghLine = m_figura.getLenghLine();
	m_figura.cambiaFigura(randomNumber);
	m_figura.setY(0);
	if (m_figura.getX() < 0)
		m_figura.setX(0);
	else
	{
		// posiciona la figura fins que no es surti del tauler
		while (m_figura.getLenghLine() + m_figura.getX() > COLUMNESATAULER)
			m_figura.setX(m_figura.getX() - 1);
	}

	fiPartida = mirarSiHaColisionsFigura();

	if(!fiPartida)
		posarFigura();
}

int static posCentroAEsquinaY(int pos)
{
	pos -= 1;
	return pos;
}

int static posCentroAEsquinaX(int pos, const int tamany, int cuantitatDeGirs)
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

void Joc::inicialitza(const string& nomFitxer)
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
				m_tauler.setPosition(x,y,color);
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


void Joc::punts(const int nFilesEliminades)
{
	int puntos = 10;
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
	m_puntsPartida += puntos;
	m_timeDown = double(-(m_puntsPartida / 1000) + 20) / 20;
}

void Joc::mostrarTualer()
{
	cout << m_tauler;
}

void Joc::mostrarFigura()
{
	cout << m_figura;
}

void Joc::borrarFigura()
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

void Joc::posarFigura()
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

bool Joc::mirarSiHaColisionsFigura()
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
			columna++;
		}
		fila++;
		columna = m_figura.getY();
	}
	
	return colisio;
}

bool Joc::giraFigura(DireccioGir direccio)
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




bool Joc::mouFigura(int dirX)
{
	bool colisions;
	borrarFigura();
	m_figura.setX(m_figura.getX() + dirX);
	colisions = mirarSiHaColisionsFigura();
	if (colisions)
		m_figura.setX(m_figura.getX() - dirX);
	posarFigura();
	return !colisions;
}


int Joc::eliminarLineasCompletesBaixada()
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
	for(fila;fila < maxValueLine; fila++)
	{
		lineCompleta = true;
		columna = 0;
		while (lineCompleta && columna < COLUMNESATAULER)
		{
			if (m_tauler.getPosition(fila, columna) == COLOR_NEGRE )
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
				m_tauler.setPosition(columnasEliminar,0 , COLOR_NEGRE);
			filesEliminades++;
		}
	}
	punts(filesEliminades);

	return filesEliminades;
}


int Joc::baixaFigura()
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
		novaFigura();
	}
	// Part on hem de mirar si hem de eliminar una linea o lineas etc
	else
		posarFigura();
	// entenem segons els nostres companys que sempre hem de posar la figura, sino es el cas eliminar
	// aquesta ´linea
	return filesEliminades;
}
int Joc::hardDrop()
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
	novaFigura();
	return filesEliminades;
}


void Joc::escriuTauler(const string& nomFitxer)
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

void Joc::inicialitzaFigura(const int tipusFiguraNova)
{
	m_figura.cambiaFigura(tipusFiguraNova);
}

void Joc::getFiguraPosActual(int &fila, int &columna) {
	fila = m_figura.getX();
	columna = m_figura.getY();
}




void Joc::posarFiguraDeTxt(int tipusFigura, int posY, int posX, int cantidadDeGirosHorarios)
{
	m_figura.cambiaFigura(tipusFigura - 1);
	m_figura.setY(posCentroAEsquinaY(posY));
	m_figura.setX(posCentroAEsquinaX(posX, m_figura.getTamany(), cantidadDeGirosHorarios));
	for (int i = 0; i < cantidadDeGirosHorarios; i++)
		m_figura.girHorari();
	if (mirarSiHaColisionsFigura())
		cout << "Has perdut la partida" << endl;
	else
		posarFigura();
}
