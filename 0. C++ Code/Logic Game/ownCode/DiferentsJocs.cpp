#include "DiferentsJocs.h"
#include "JocTower.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined  (_WIN64)

#include <iostream>
//Definicio necesaria per poder incloure la llibreria i que trobi el main
#define SDL_MAIN_HANDLED
#include <windows.h>
//Llibreria grafica
#include "../../Graphic Lib/libreria.h"
#include "../../Graphic Lib/NFont/NFont.h"
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

#include "../Partida.h"
#include "../InfoJoc.h"
#include "../GraphicManager.h"

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
	string msg = "Puntos: " + to_string(puntos);
	GraphicManager::getInstance()->drawFont(FONT_RED_30, 100, POS_Y_TAULER - 50, 1.0, msg);
	pantalla.update();

}


void mostraTauler(JocTower& jocAMostrar, Screen& pantalla)
{
	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
	GraphicManager::getInstance()->drawSprite(GRAFIC_TOWERDEFENSE, 0, 0, false);
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

void tetris()
{
	
	//Instruccions necesaries per poder incloure la llibreria i que trobi el main
	SDL_SetMainReady();
	SDL_Init(SDL_INIT_VIDEO);

	//Inicialitza un objecte de la classe Screen que s'utilitza per gestionar la finestra grafica
	Screen pantalla(SCREEN_SIZE_X, SCREEN_SIZE_Y);
	//Mostrem la finestra grafica
	pantalla.show();

	Partida game;
	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;
	Joc tetris;
	tetris.mostrarTualer();
	NOW = SDL_GetPerformanceCounter();
	LAST = NOW;
	double timeToGoDown = 1;
	deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());
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
		tetris.mostrarTualer();

		LAST = NOW;
		deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());
		tetris.baixaFigura();
		mostraTauler(tetris, pantalla);
		// despres de esperar les tecles baixa la figura
		// comprueba que no se ha perdido la partida


		// Actualitza la pantalla
		tetris.mostrarTualer();

	}
	// Sortim del bucle si pressionem ESC
	// _____________________________________________________________________________________________________________
	// COMIENZA EL CODIGO DEL JUEGO
	
	// no se hasta darle a q 
	std::cout << "\nFi de la partida";
	//Instruccio necesaria per alliberar els recursos de la llibreria 
	SDL_Quit();
	
}


void towerTetris()
{
		//Instruccions necesaries per poder incloure la llibreria i que trobi el main
		SDL_SetMainReady();
		SDL_Init(SDL_INIT_VIDEO);

		//Inicialitza un objecte de la classe Screen que s'utilitza per gestionar la finestra grafica
		Screen pantalla(SCREEN_SIZE_Y,SCREEN_SIZE_X);
		//Mostrem la finestra grafica
		pantalla.show();

		Partida game;
		Uint64 NOW = SDL_GetPerformanceCounter();
		Uint64 LAST = 0;
		double deltaTime = 0;
		JocTower tetrisTowerDefense;
		tetrisTowerDefense.mostrarTualer();
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
						Sleep(300);
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
	}


void modoTest(const string& fitxerInicial, const string& fitxerFigura, const string& fitxerMoviments)
{

	//Instruccions necesaries per poder incloure la llibreria i que trobi el main
	SDL_SetMainReady();
	SDL_Init(SDL_INIT_VIDEO);

	//Inicialitza un objecte de la classe Screen que s'utilitza per gestionar la finestra grafica
	Screen pantalla(SCREEN_SIZE_X, SCREEN_SIZE_Y);
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

	modoTest.mostrarTualer();
	mostraTestTauler(modoTest, pantalla);
	bool fiDePartida = false;

	NOW = SDL_GetPerformanceCounter();
	LAST = NOW;
	double timeToGoDown = 1;
	deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());
	while (modoTest.getNFiguras() != 0 && !Keyboard_GetKeyTrg(KEYBOARD_ESCAPE)) {
		// inicializamos la figura en el tablero

		while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE) && modoTest.getNFiguras() != 0)
		{


			// Captura tots els events de ratolí i teclat de l'ultim cicle

			while (deltaTime < timeToGoDown && !Keyboard_GetKeyTrg(KEYBOARD_ESCAPE))
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

					modoTest.mostrarTualer();

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
				modoTest.mostrarTualer();

				NOW = SDL_GetPerformanceCounter();
				deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());
			}

			modoTest.posarFiguraDeTxt();

			LAST = NOW;
			deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());
			mostraTestTauler(modoTest, pantalla);
			// despres de esperar les tecles baixa la figura
			// comprueba que no se ha perdido la partida


			// Actualitza la pantalla

		}

	}
	
	SDL_Quit();

}