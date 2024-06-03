#ifndef JOC_H
#define JOC_H
#include "Figura.h"
#include "Tauler.h"
class Joc
{
private:
	Tauler m_tauler;
	Figuras m_figura;
	bool fiPartida;
	double m_time;
	int puntosPartida;
public:
	Joc();
	void novaFigura();
	void inicialitza(const string& nomFitxer);
	void mostrarTualer();
	void mostrarFigura();
	bool giraFigura(DireccioGir direccio);
	void borrarFigura();
	void posarFigura();
	void posarFiguraDeTxt(int tipusFigura, int posY, int posX, int cantidadDeGirosHorarios);
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
};

=======
#ifndef JOC_H
#define JOC_H
#include "Figura.h"
#include "Tauler.h"
class Joc
{
private:
	Tauler m_tauler;
	Figuras m_figura;
	bool fiPartida;
	double m_time;
	int m_puntsPartida;
	float m_timeDown;
	forward_list<int> m_dataPunts;
	forward_list<string> m_dataNoms;

public:
	Joc();
	void llegirPuntuacions();
	void escriuPuntuacions(const string& nomNouJugador);
	void novaFigura();
	void inicialitza(const string& nomFitxer);
	void mostrarTualer();
	void mostrarFigura();
	void punts(const int nFilesEliminades);
	bool giraFigura(DireccioGir direccio);
	void borrarFigura();
	void posarFigura();
	void posarFiguraDeTxt(int tipusFigura, int posY, int posX, int cantidadDeGirosHorarios);
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
	int getPuntosPartida()const { return m_puntsPartida; };
};

#endif