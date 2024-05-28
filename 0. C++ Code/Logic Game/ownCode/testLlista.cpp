#include "testLlista.h"

void TextInfo::afegeixMoviment(const int& moviment)
{
	Node* aux = new Node;
	aux->setValor(moviment);
	aux->setNext(m_moviments);
	m_moviments = aux;
	m_nMoviments++;
}
void TextInfo::afegeixFigura(const int& figura,const int& y, const int& x, const int& nGirsH)
{
	NodeFigura* aux = new NodeFigura;
	aux->setValor(figura,y,x,nGirsH);
	aux->setNext(m_figuras);
	m_figuras = aux;
	m_nFiguras++;
}
void TextInfo::eliminaFirstMoviment()
{
	//miramos que no este vacio
	if (m_moviments != nullptr)
	{
		// Guardar apuntador al primer element en un auxiliar

		Node* aux = m_moviments;

		// Modificar apuntador al primer element (al seg�ent element)

		m_moviments = m_moviments->getNext();

		// Alliberar el primer element(utilitzant l�apuntador auxiliar)

		delete aux;
	}
}
void TextInfo::eliminaFirstFigura()
{
	if (m_figuras != nullptr)
	{
		// Guardar apuntador al primer element en un auxiliar

		NodeFigura* aux = m_figuras;

		// Modificar apuntador al primer element (al seg�ent element)

		m_figuras = m_figuras->getNext();

		// Alliberar el primer element(utilitzant l�apuntador auxiliar)

		delete aux;
	}
}