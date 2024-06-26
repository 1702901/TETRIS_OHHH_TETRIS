#ifndef TAULER_TOWER_H
#define TAULER_TOWER_H
#include "Figura.h"
#include "Tauler.h"
#include "slime.h"
class JocTower
{
private:
	TaulerTower m_tauler;
	Figuras m_figura;
	bool fiPartida;
	Slime slimes[MAX_SLIMES];
	int vida; 
public:
	JocTower();
	int getValuePos(const int posY, const int posX) const { return m_tauler.getPosition(posY, posX); };
	void novaFigura();
	void mostrarTualer();
	void mostrarFigura();
	bool giraFigura(DireccioGir direccio);
	void borrarFigura();
	void posarFigura();
	void posarFiguraHardDrop();
	bool mirarSiHaColisionsFigura();
	bool mirarSiHaColisionsFiguraBaixada();
	bool mouFigura(int dirX);
	int baixaFigura();
	int eliminarLineasCompletesBaixada();
	int eliminarColumnesCompletesBaixada();
	void escriuTauler(const string& nomFitxer);
	void inicialitzaFigura(const int tipusFiguraNova);
	void inicialitzaSlime(Slime& slimeABorrar);
	void borrarSlime(Slime& slimeABorrar);
	void posarSlime(Slime& slimeAPossar);
	bool mirarSiHaColisionsSlime(Slime& slimeAMoure);
	bool mouSlime(int dirX, Slime& slimeAMoure);
	bool getFiPartida()  const { return fiPartida; };
	Slime& donaSlime(const int slimeIndex)  { return slimes[slimeIndex]; };
	int hardDrop();
};



#endif