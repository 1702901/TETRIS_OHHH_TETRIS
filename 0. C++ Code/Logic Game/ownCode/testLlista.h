
﻿#pragma once
#include "node.h"


class TextInfo
{
public:
	TextInfo() : m_moviments(nullptr),m_figuras(nullptr),m_nFiguras(0),m_nMoviments(0) {}
	void afegeixMoviment(const int& moviment);
	void afegeixFigura(const int& figura, const int& y, const int& x, const int& nGirsH);
	//elimina el primer element
	void eliminaFirstMoviment();
	void eliminaFirstFigura();
	Node* getMoviment() const { return m_moviments; }
	int getNMoviment() const { return m_nMoviments; }
	Node* ultiMoviment() const;
	NodeFigura* ultimaFigura() const;
	bool nextMov();
	void reiniciarMov();
	int getNFiguras() const { return m_nFiguras; }

	void invertirFigura();
	void invertirMoviment();


	NodeFigura* getFigura() const { return m_figuras; };
	void mostraFiguraInfo() const;


private:
	Node* m_moviments;
	Node* m_firstMov;
	NodeFigura* m_figuras;
	int m_nFiguras;
	int m_nMoviments;
};