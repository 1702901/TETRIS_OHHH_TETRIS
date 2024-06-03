#include "DiferentsJocs.h"



int menuPerSeleccionar(Screen& pantalla)
{
	//Instruccions necesaries per poder incloure la llibreria i que trobi el main
	SDL_SetMainReady();
	SDL_Init(SDL_INIT_VIDEO);
	int teclaSeleccionada = 0;
	//Inicialitza un objecte de la classe Screen que s'utilitza per gestionar la finestra grafica
	//Mostrem la finestra grafica
	pantalla.show();
	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
	string msg = "Launcher for TETRIS games:";
	GraphicManager::getInstance()->drawFont(FONT_GREEN_30, 90, POS_Y_TAULER - 50, 1.0, msg);
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 100, POS_Y_TAULER, 1.0, "1 - Joc en mode normal");
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 100, POS_Y_TAULER+50, 1.0, "2 - Joc en mode test");
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 100, POS_Y_TAULER + 100, 1.0, "3 - Puntiacions mode normal");
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 100, POS_Y_TAULER + 150, 1.0, "4 - Mode Tower Tetris ");
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 100, POS_Y_TAULER + 200, 1.0, "5 - Cambiar musica ");
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 100, POS_Y_TAULER + 250, 1.0, "6 - Sortir ");
	pantalla.update();
	while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE) && !teclaSeleccionada)
	{
		pantalla.processEvents();
		if (Keyboard_GetKeyTrg(KEYBOARD_1))
			teclaSeleccionada = TETRIS;
		else if(Keyboard_GetKeyTrg(KEYBOARD_2))
			teclaSeleccionada = TEST;
		else if (Keyboard_GetKeyTrg(KEYBOARD_3))
			teclaSeleccionada = PUNTIACIONS;
		else if (Keyboard_GetKeyTrg(KEYBOARD_4))
			teclaSeleccionada = TOWER_TETRIS;
		else if (Keyboard_GetKeyTrg(KEYBOARD_5))
			teclaSeleccionada = MUSICA;
		else if (Keyboard_GetKeyTrg(KEYBOARD_6))
			teclaSeleccionada = SORTIR;
 
	}
	//Instruccio necesaria per alliberar els recursos de la llibreria 
	return teclaSeleccionada;
}

int testMenu(Screen& pantalla)
{
	//Instruccions necesaries per poder incloure la llibreria i que trobi el main
	SDL_SetMainReady();
	SDL_Init(SDL_INIT_VIDEO);
	int teclaSeleccionada = 0;
	//Inicialitza un objecte de la classe Screen que s'utilitza per gestionar la finestra grafica
	//Mostrem la finestra grafica
	pantalla.show();
	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
	string msg = "Launcher for TETRIS games:";
	GraphicManager::getInstance()->drawFont(FONT_GREEN_30, 90, POS_Y_TAULER - 50, 1.0, msg);
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 100, POS_Y_TAULER, 1.0, "1 - Test basic/anterior test");
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 100, POS_Y_TAULER + 50, 1.0, "2 - Test personalitzat");
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 100, POS_Y_TAULER + 100, 1.0, "3 - Sortir");

 
	pantalla.update();
	while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE) && !teclaSeleccionada)
	{
		pantalla.processEvents();
		if (Keyboard_GetKeyTrg(KEYBOARD_1))
			teclaSeleccionada = TEST_BASIC;
		else if (Keyboard_GetKeyTrg(KEYBOARD_2))
			teclaSeleccionada = TEST;
		else if (Keyboard_GetKeyTrg(KEYBOARD_3))
			teclaSeleccionada = SORTIR;
	}
	//Instruccio necesaria per alliberar els recursos de la llibreria 
	return teclaSeleccionada;
}

void musicaMenu(Screen& pantalla)
{
	//Instruccions necesaries per poder incloure la llibreria i que trobi el main
	SDL_SetMainReady();
	SDL_Init(SDL_INIT_VIDEO);
	int teclaSeleccionada = 0;
	//Inicialitza un objecte de la classe Screen que s'utilitza per gestionar la finestra grafica
	//Mostrem la finestra grafica
	pantalla.show();
	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
	string msg = "Launcher for TETRIS games:";
	GraphicManager::getInstance()->drawFont(FONT_GREEN_30, 90, POS_Y_TAULER - 50, 1.0, msg);
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 100, POS_Y_TAULER, 1.0, "1 - Beastie Boys Sabotage");
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 100, POS_Y_TAULER + 50, 1.0, "2 - Tetris Original");
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 100, POS_Y_TAULER + 100, 1.0, "3 - Requiem - Kyrie");
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 100, POS_Y_TAULER + 150, 1.0, "4 - Sequentia");
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 100, POS_Y_TAULER + 200, 1.0, "5 - Sortir sense musica");

	pantalla.update();
	while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE) && !teclaSeleccionada)
	{
		pantalla.processEvents();
		if (Keyboard_GetKeyTrg(KEYBOARD_1))
			teclaSeleccionada = BESTIEBOYS;
		else if (Keyboard_GetKeyTrg(KEYBOARD_2))
			teclaSeleccionada = TETRISMUSIC;
		else if (Keyboard_GetKeyTrg(KEYBOARD_3))
			teclaSeleccionada = MOZART1;
		else if (Keyboard_GetKeyTrg(KEYBOARD_4))
			teclaSeleccionada = MOZART2;
		else if (Keyboard_GetKeyTrg(KEYBOARD_5))
			teclaSeleccionada = SORTIRMUSIC;
	}
	//Instruccio necesaria per alliberar els recursos de la llibreria 

	switch (teclaSeleccionada)
	{
	case TETRISMUSIC:
		PlaySound("../../1. Resources/data/music/Tetris.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		break;
	case BESTIEBOYS:
		PlaySound("../../1. Resources/data/music/Beastie_Boys_Sabotage.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		break;
	case MOZART1:
		PlaySound("../../1. Resources/data/music/Requiem.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		break;
	case MOZART2:
		PlaySound("../../1. Resources/data/music/2-Sequentia.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		break;
	default:
		break;
	}

}

void mostrarPuntiacions(Screen& pantalla)
{
	SDL_SetMainReady();
	SDL_Init(SDL_INIT_VIDEO);
	ifstream fitxer;
	int puntsJugador;
	string noms;
	fitxer.open("../../1. Resources/data/Punts/puntiacions.txt");
	forward_list<int> m_dataPunts;
	forward_list<string> m_dataNoms;
	int teclaSeleccionada = 0;

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
	 

	// ______________________________________________________________________________________________________________
	// tractament per mostrar les dades

	int distancia = distance(m_dataPunts.begin(), m_dataPunts.end());
	int i = 0;
	int max_puntuacions = 5;
	if (max_puntuacions > distancia)
		max_puntuacions = distancia;

	forward_list<int>::iterator jugadorPuntuacio = m_dataPunts.begin();
	forward_list<string>::iterator jugadorNom = m_dataNoms.begin();

	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
	string msg = "Llistat de puntuacions: ";
	GraphicManager::getInstance()->drawFont(FONT_GREEN_30, 90, POS_Y_TAULER - 50 , 1.0, msg);
	while (i < max_puntuacions)
	{
		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 100, POS_Y_TAULER + i*50, 0.8, to_string(i+1) + ". " + *jugadorNom + " " + to_string(*jugadorPuntuacio));
		jugadorNom++;
		jugadorPuntuacio++;
		i++;
	}
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 100, POS_Y_TAULER + 350, 0.8, "PREM ENTER PER SORTIR AL MENU");

	pantalla.update();
	while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE) && !teclaSeleccionada)
	{
		pantalla.processEvents();
		if (Keyboard_GetKeyTrg(KEYBOARD_RETURN))
			teclaSeleccionada = SORTIR;
	}

	fitxer.close();
}

void reedKeyBoard(Screen& pantalla, string& leterDetected)
{
	pantalla.processEvents();
	if (Keyboard_GetKeyTrg(KEYBOARD_A))
		leterDetected += "a";
	else if (Keyboard_GetKeyTrg(KEYBOARD_B))
		leterDetected += "b";
	else if (Keyboard_GetKeyTrg(KEYBOARD_C))
		leterDetected += "c";
	else if (Keyboard_GetKeyTrg(KEYBOARD_D))
		leterDetected += "d";
	else if (Keyboard_GetKeyTrg(KEYBOARD_E))
		leterDetected += "e";
	else if (Keyboard_GetKeyTrg(KEYBOARD_F))
		leterDetected += "f";
	else if (Keyboard_GetKeyTrg(KEYBOARD_G))
		leterDetected += "g";
	else if (Keyboard_GetKeyTrg(KEYBOARD_H))
		leterDetected += "h";
	else if (Keyboard_GetKeyTrg(KEYBOARD_I))
		leterDetected += "i";
	else if (Keyboard_GetKeyTrg(KEYBOARD_J))
		leterDetected += "j";
	else if (Keyboard_GetKeyTrg(KEYBOARD_K))
		leterDetected += "k";
	else if (Keyboard_GetKeyTrg(KEYBOARD_L))
		leterDetected += "l";
	else if (Keyboard_GetKeyTrg(KEYBOARD_M))
		leterDetected += "m";
	else if (Keyboard_GetKeyTrg(KEYBOARD_N))
		leterDetected += "n";
	else if (Keyboard_GetKeyTrg(KEYBOARD_O))
		leterDetected += "o";
	else if (Keyboard_GetKeyTrg(KEYBOARD_P))
		leterDetected += "p";
	else if (Keyboard_GetKeyTrg(KEYBOARD_Q))
		leterDetected += "q";
	else if (Keyboard_GetKeyTrg(KEYBOARD_R))
		leterDetected += "r";
	else if (Keyboard_GetKeyTrg(KEYBOARD_S))
		leterDetected += "s";
	else if (Keyboard_GetKeyTrg(KEYBOARD_T))
		leterDetected += "t";
	else if (Keyboard_GetKeyTrg(KEYBOARD_U))
		leterDetected += "u";
	else if (Keyboard_GetKeyTrg(KEYBOARD_V))
		leterDetected += "v";
	else if (Keyboard_GetKeyTrg(KEYBOARD_W))
		leterDetected += "w";
	else if (Keyboard_GetKeyTrg(KEYBOARD_X))
		leterDetected += "x";
	else if (Keyboard_GetKeyTrg(KEYBOARD_Y))
		leterDetected += "y";
	else if (Keyboard_GetKeyTrg(KEYBOARD_Z))
		leterDetected += "z";
	else if (Keyboard_GetKeyTrg(KEYBOARD_SPACE))
		leterDetected += ".txt";
	else if (Keyboard_GetKeyTrg(KEYBOARD_BACKSPACE) && leterDetected != "")
		leterDetected.pop_back();
}


string tetrisNameSelection(Screen& pantalla)
{
	SDL_SetMainReady();
	SDL_Init(SDL_INIT_VIDEO);

	pantalla.show();
	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
	string msg = "Nom del jugador";
	string nom = "";
	pantalla.update();

	while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE) && !Keyboard_GetKeyTrg(KEYBOARD_RETURN))
	{
		reedKeyBoard(pantalla, nom);
		GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
		GraphicManager::getInstance()->drawFont(FONT_GREEN_30, 90, POS_Y_TAULER - 50, 1.0, msg);
		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 90, POS_Y_TAULER, 1.0, nom);
		pantalla.update();
	}
	return nom;
}


void getTxtName( string& fitxerInicial,string& fitxerFigura, string& fitxerMoviments, Screen& pantalla)
{
	SDL_SetMainReady();
	SDL_Init(SDL_INIT_VIDEO);

	pantalla.show();
	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
	string msg = "Nom del mapa a data/Games:";
	fitxerInicial = "";
	fitxerFigura = "";
	fitxerMoviments = "";
	pantalla.update();

	while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE) && !Keyboard_GetKeyTrg(KEYBOARD_RETURN))
	{
		reedKeyBoard(pantalla,fitxerInicial);
		GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
		GraphicManager::getInstance()->drawFont(FONT_GREEN_30, 90, POS_Y_TAULER - 50, 1.0, msg);
		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 90, POS_Y_TAULER, 1.0, fitxerInicial);
		GraphicManager::getInstance()->drawFont(FONT_GREEN_30, 90, POS_Y_TAULER + 100, 1.0, "PER POSAR .txt prem spai");

		pantalla.update();
	}
	fitxerInicial = "../../1. Resources/data/Games/" + fitxerInicial;
	while (!Keyboard_GetKeyTrg(KEYBOARD_S))
	{
		pantalla.processEvents();
		GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
		GraphicManager::getInstance()->drawFont(FONT_GREEN_30, 90, POS_Y_TAULER, 1.0, "Tecleja s si ja estas preparat: ");
		pantalla.update();
	}

	msg = "Nom del fitxer figura a data/Games:";

	while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE) && !Keyboard_GetKeyTrg(KEYBOARD_RETURN))
	{
		reedKeyBoard(pantalla, fitxerFigura);
		GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
		GraphicManager::getInstance()->drawFont(FONT_GREEN_30, 90, POS_Y_TAULER - 50, 1.0, msg);
		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 90, POS_Y_TAULER, 1.0, fitxerFigura);
		pantalla.update();

	}
	fitxerFigura = "../../1. Resources/data/Games/" + fitxerFigura;
	while (!Keyboard_GetKeyTrg(KEYBOARD_S))
	{
		pantalla.processEvents();
		GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
		GraphicManager::getInstance()->drawFont(FONT_GREEN_30, 90, POS_Y_TAULER, 1.0, "Tecleja s si ja estas preparat: ");
		pantalla.update();
	}
	
	msg = "Nom del fitxer moviments ";

	while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE) && !Keyboard_GetKeyTrg(KEYBOARD_RETURN))
	{
		reedKeyBoard(pantalla, fitxerMoviments);
		GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
		GraphicManager::getInstance()->drawFont(FONT_GREEN_30, 90, POS_Y_TAULER - 50, 1.0, msg);
		GraphicManager::getInstance()->drawFont(FONT_GREEN_30, 90, POS_Y_TAULER, 1.0, "a data/Games:");

		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 90, POS_Y_TAULER + 50, 1.0, fitxerMoviments);
		pantalla.update();
	}
	fitxerMoviments = "../../1. Resources/data/Games/" + fitxerMoviments;
}



void mostraTauler(Joc& jocAMostrar, Screen& pantalla)
{
	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
	GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
	for (int fila = 0; fila < FILESTAULER; fila++)
	{
		for(int columna = 0; columna < COLUMNESATAULER; columna++)
		{
			if (jocAMostrar.getValuePos(fila,columna) != 0)
			{
				GraphicManager::getInstance()->drawSprite(IMAGE_NAME(jocAMostrar.getValuePos(fila, columna) + 1),
					POS_X_TAULER + ((columna+1) * MIDA_QUADRAT), POS_Y_TAULER + ((fila)*MIDA_QUADRAT), false);
			}
			
		}
	}
	//poner fila columna en la pantalla
	int puntos = jocAMostrar.getPuntosPartida();
	string msg = "Punts: " + to_string(puntos) + " Nivell: " + to_string(puntos/1000);
	GraphicManager::getInstance()->drawFont(FONT_RED_30, 100, POS_Y_TAULER - 50, 1.0, msg);
	pantalla.update();

}


void mostraTauler(JocTower& jocAMostrar, Screen& pantalla)
{

	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
	GraphicManager::getInstance()->drawSprite(GRAFIC_TOWERDEFENSE, 0, 0, false);
	GraphicManager::getInstance()->drawSprite(GRAFIC_MAGE, -100, -50, false);

	for (int fila = 0; fila < COLUMNESATAULER ; fila++)
	{
		for (int columna = 0; columna < FILESTAULER; columna++)
		{
			if (jocAMostrar.getValuePos(fila, columna) != 0)
			{
				GraphicManager::getInstance()->drawSprite(IMAGE_NAME(jocAMostrar.getValuePos(fila, columna) + 1),
					 ((columna + 1) * MIDA_QUADRAT),((fila)*MIDA_QUADRAT), false);
			}

		}
	}
	pantalla.update();

}

void mostraTestTauler(ModoTest& jocAMostrar, Screen& pantalla)
{
	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
	GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
	for (int fila = 0; fila < FILESTAULER; fila++)
	{
		for (int columna = 0; columna < COLUMNESATAULER; columna++)
		{
			if (jocAMostrar.getValuePos(fila, columna) != 0)
			{
				GraphicManager::getInstance()->drawSprite(IMAGE_NAME(jocAMostrar.getValuePos(fila, columna) + 1),
					POS_X_TAULER + ((columna + 1) * MIDA_QUADRAT), POS_Y_TAULER + ((fila)*MIDA_QUADRAT), false);
			}

		}
	}
	//poner fila columna en la pantalla
	int puntos = jocAMostrar.getPuntosPartida();
	string msg = "Puntos: " + to_string(puntos);
	GraphicManager::getInstance()->drawFont(FONT_RED_30, 100, POS_Y_TAULER - 50, 1.0, msg);
	pantalla.update();
}

void tetris(Screen& pantalla)
{
	
	//Instruccions necesaries per poder incloure la llibreria i que trobi el main
	

	//Inicialitza un objecte de la classe Screen que s'utilitza per gestionar la finestra grafica
	//Mostrem la finestra grafica
	pantalla.show();

	Partida game;
	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;
	Joc tetris;
	NOW = SDL_GetPerformanceCounter();
	LAST = NOW;
	double timeToGoDown = 1;
	deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());
	mostraTauler(tetris, pantalla);
	while(!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE) && !tetris.getFiPartida())
	{
		

		// Captura tots els events de ratolí i teclat de l'ultim cicle

		while (deltaTime < timeToGoDown && !Keyboard_GetKeyTrg(KEYBOARD_ESCAPE))
		{
			pantalla.processEvents();
				// aqui se guarda el valor pulsado 
				// segun la tecla pulsada hacemos x accion
			if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
			{
				tetris.mouFigura(+1);
				mostraTauler(tetris,pantalla);
			}
			else if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
			{
				tetris.mouFigura(-1);
				mostraTauler(tetris, pantalla);
			}
			else if (Keyboard_GetKeyTrg(KEYBOARD_DOWN))
			{
				tetris.giraFigura(GIR_ANTI_HORARI);
				mostraTauler(tetris, pantalla);
			}
			else if (Keyboard_GetKeyTrg(KEYBOARD_UP))
			{
				tetris.giraFigura(GIR_HORARI);
				mostraTauler(tetris, pantalla);
			}
			else if (Keyboard_GetKeyTrg(KEYBOARD_SPACE)) 
			{
				tetris.baixaFigura(); 
				tetris.hardDrop(); 
				mostraTauler(tetris, pantalla);
			}
			NOW = SDL_GetPerformanceCounter();
			deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());
		}

		LAST = NOW;
		deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());
		tetris.baixaFigura();
		mostraTauler(tetris, pantalla);
		// despres de esperar les tecles baixa la figura
		// comprueba que no se ha perdido la partida
 

	}
	// Sortim del bucle si pressionem ESC
	// _____________________________________________________________________________________________________________
	// COMIENZA EL CODIGO DEL JUEGO
	GraphicManager::getInstance()->drawFont(FONT_RED_30, SCREEN_SIZE_X / 2 -200 , SCREEN_SIZE_Y / 2 - 200 , 3.0, "YOU DIED");
	pantalla.update();
	Sleep(3000);
	pantalla.processEvents();
	if (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE))
	{
		string nomJugador = tetrisNameSelection(pantalla);
		if (nomJugador != "")
			tetris.escriuPuntuacions(nomJugador);
	}
	//Instruccio necesaria per alliberar els recursos de la llibreria 
	
}


void towerTetris(Screen& pantalla)
{
		//Instruccions necesaries per poder incloure la llibreria i que trobi el main
		 

		//Inicialitza un objecte de la classe Screen que s'utilitza per gestionar la finestra grafica
		//Mostrem la finestra grafica
		pantalla.show();

		Partida game;
		Uint64 NOW = SDL_GetPerformanceCounter();
		Uint64 LAST = 0;
		double deltaTime = 0;
		JocTower tetrisTowerDefense;
		NOW = SDL_GetPerformanceCounter();
		LAST = NOW;
		int timeToGoDown = 1;
		deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());
		while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE) && !tetrisTowerDefense.getFiPartida())
		{

			// Captura tots els events de ratolí i teclat de l'ultim cicle

			while (deltaTime < timeToGoDown && !Keyboard_GetKeyTrg(KEYBOARD_ESCAPE))
			{
				pantalla.processEvents();
				// aqui se guarda el valor pulsado 
				// segun la tecla pulsada hacemos x accion
				if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
				{
					tetrisTowerDefense.mouFigura(+1);
					mostraTauler(tetrisTowerDefense, pantalla);
				}
				else if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
				{
					tetrisTowerDefense.mouFigura(-1);
					mostraTauler(tetrisTowerDefense, pantalla);
				}
				else if (Keyboard_GetKeyTrg(KEYBOARD_DOWN))
				{
					tetrisTowerDefense.giraFigura(GIR_ANTI_HORARI);
					mostraTauler(tetrisTowerDefense, pantalla);
				}
				else if (Keyboard_GetKeyTrg(KEYBOARD_UP))
				{
					tetrisTowerDefense.giraFigura(GIR_HORARI);
					mostraTauler(tetrisTowerDefense, pantalla);
				}
				else if (Keyboard_GetKeyTrg(KEYBOARD_SPACE))
				{
					tetrisTowerDefense.baixaFigura();
					tetrisTowerDefense.hardDrop();
					for (int i = 0; i < PENALITZACIO; i++)
					{
						tetrisTowerDefense.mouSlime(-1, tetrisTowerDefense.donaSlime(1));
						mostraTauler(tetrisTowerDefense, pantalla);
						Sleep(200);
					}
				}

				//tetrisTowerDefense.mostrarTualer();
				//system("cls");

				NOW = SDL_GetPerformanceCounter();
				deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());
			}
			LAST = NOW;
			deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());
			tetrisTowerDefense.baixaFigura();
			tetrisTowerDefense.mouSlime(-1, tetrisTowerDefense.donaSlime(1));
			mostraTauler(tetrisTowerDefense, pantalla);
			//tetrisTowerDefense.mostrarTualer();
			//system("cls");
			// despres de esperar les tecles baixa la figura
			// comprueba que no se ha perdido la partida


			// Actualitza la pantalla

		}
		GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
		GraphicManager::getInstance()->drawFont(FONT_RED_30, SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 - 200, 3.0, "YOU DIED");
		pantalla.update();
		Sleep(3000);
		pantalla.processEvents();
	}


void modoTest(const string& fitxerInicial, const string& fitxerFigura, const string& fitxerMoviments, Screen& pantalla)
{

 

	//Inicialitza un objecte de la classe Screen que s'utilitza per gestionar la finestra grafica
	//Mostrem la finestra grafica
	pantalla.show();

	Partida game;
	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;

	ModoTest modoTest;

	//prepara el modo test
	modoTest.inicialitza(fitxerInicial);
	modoTest.llegirFitxerFigures(fitxerFigura);
	modoTest.llegirFitxerMoviments(fitxerMoviments);

	mostraTestTauler(modoTest, pantalla);
	bool fiDePartida = false;

	NOW = SDL_GetPerformanceCounter();
	LAST = NOW;
	double timeToGoDown = 1;
	deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());
	
		// inicializamos la figura en el tablero

	 


		// Captura tots els events de ratolí i teclat de l'ultim cicle

	while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE) && !modoTest.getFiPartida())
	{
		pantalla.processEvents();
		//getMoviment nos da la el moviment y preprara el siguiente movimiento
		switch (modoTest.getMoviment())
		{
		case MOVIMENT_ESQUERRA:
			modoTest.mouFigura(-1);
			mostraTestTauler(modoTest, pantalla);
			break;
		case MOVIMENT_DRETA:
			modoTest.mouFigura(+1);
			mostraTestTauler(modoTest, pantalla);
			break;
		case MOVIMENT_GIR_HORARI:
			modoTest.giraFigura(GIR_HORARI);
			mostraTestTauler(modoTest, pantalla);
			break;
		case MOVIMENT_GIR_ANTI_HORARI:
			modoTest.giraFigura(GIR_ANTI_HORARI);
			mostraTestTauler(modoTest, pantalla);
			break;
		case MOVIMENT_BAIXA:
			modoTest.baixaFigura();
			mostraTestTauler(modoTest, pantalla);
			break;
		case MOVIMENT_BAIXA_FINAL:
			modoTest.hardDrop();
			mostraTestTauler(modoTest, pantalla);
			break;
		default:
			cout << "No existeix cap opció" << endl;
			break;
		}
		mostraTestTauler(modoTest, pantalla);
		Sleep(500);
	}


	 
	mostraTestTauler(modoTest, pantalla);

	GraphicManager::getInstance()->drawFont(FONT_RED_30, SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 - 200, 3.0, "YOU DIED");
	pantalla.update();
	Sleep(3000);

	// despres de esperar les tecles baixa la figura
	// comprueba que no se ha perdido la partida


	// Actualitza la pantalla

 


	

}