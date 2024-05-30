#pragma once

class FiguraTest
{
public:
	FiguraTest() :m_tipusFigura(0), m_posY(0), m_posX(0), m_nGirsHoraris(0) {};
	FiguraTest(const int& tipusFigura,const int& y,const int& x, const int& nGirsHoraris) :
		m_tipusFigura(tipusFigura), m_posY(y), m_posX(x), m_nGirsHoraris(nGirsHoraris) {};
	void inicializar(const int& tipusFigura, const int& y, const int& x, const int& nGirsHoraris) {
		m_tipusFigura = tipusFigura, m_posY = y, m_posX = x,m_nGirsHoraris = nGirsHoraris;
	};
	int getTipusFigura() const { return m_tipusFigura; }
	int getPosY() const { return m_posY; }
	int getPosX() const { return m_posX; }
	int getNGirsHoraris() const { return m_nGirsHoraris; }


private:
	int m_tipusFigura;
	int m_posY;
	int m_posX;
	int m_nGirsHoraris;
};
