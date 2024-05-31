#ifndef MODETEST_H
#define MODETEST_H
#include "Figura.h"
#include "Tauler.h"
#include "testLlista.h"
using namespace std;

class ModoTest
{
private:
	Tauler m_tauler;
	Figuras m_figura;
	bool fiPartida;
	double m_time;
	int puntosPartida;

	TextInfo m_infoModTest;

public:
	ModoTest();
	void novaFigura();
	void inicialitza(const string& nomFitxer);
	void mostrarTualer();
	void mostrarFigura();
	bool giraFigura(DireccioGir direccio);
	void borrarFigura();
	void posarFigura();
	bool mirarSiHaColisionsFigura();
	bool mouFigura(int dirX);
	int baixaFigura();
	int eliminarLineasCompletesBaixada();
	void escriuTauler(const string& nomFitxer);
	void inicialitzaFigura(const int tipusFiguraNova);
	bool getFiPartida()  const { return fiPartida; };
	int getValuePos(int posX, int posY) const { return m_tauler.getPosition(posX, posY); }
	int hardDrop();

	//funciones para la pantalla y etc
	void getFiguraPosActual(int& fila, int& columna);
	void punts(int nFilesEliminades);
	int getPuntosPartida()const { return puntosPartida; };

	//funciones para modo Test
	void llegirFitxerFigures(const string& nomFitxer);
	void llegirFitxerMoviments(const string& nomFitxer);
	TextInfo getInfoMod() const { return m_infoModTest; };
	int getMoviment();
	void posarFiguraDeTxt();

};

#endif