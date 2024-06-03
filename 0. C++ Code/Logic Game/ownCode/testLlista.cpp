#include "testLlista.h"
#include <iostream>
using namespace std;

void TextInfo::afegeixMoviment(const int& moviment)
{
	Node* aux = new Node;
	aux->setValor(moviment);
	aux->setNext(m_moviments);
	m_moviments = aux;
	m_firstMov = aux;
	m_nMoviments++;
}

// avanza en la lista de nodos enlazados
void TextInfo::nextMov() {
	if (m_moviments->getNext() != nullptr) {
		*m_moviments = *m_moviments->getNext();
	}
	else {
		reiniciarMov();
	}
}

//per tornar al inici de la lista
void TextInfo::reiniciarMov()
{
	*m_moviments = *m_firstMov;
}

void TextInfo::afegeixFigura(const int& figura, const int& y, const int& x, const int& nGirsH)
{
	NodeFigura* aux = new NodeFigura;
	aux->setValor(figura, y, x, nGirsH);
	aux->setNext(m_figuras);
	m_figuras = aux;
	m_nFiguras++;
}

Node* TextInfo::ultiMoviment() const
{
	Node* ultim = new Node;
	ultim = m_moviments;
	while (ultim->getNext() != nullptr)
	{
		ultim = ultim->getNext();
	}
	return ultim;
}

NodeFigura* TextInfo::ultimaFigura() const
{
	NodeFigura* ultim = new NodeFigura;
	ultim = m_figuras;
	while (ultim->getNext() != nullptr)
	{
		ultim = ultim->getNext();
	}
	return ultim;
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
		m_nFiguras--;
		delete aux;
	}
}

void TextInfo::mostraFiguraInfo() const
{
	NodeFigura* iterador = new NodeFigura;
	iterador = m_figuras;
	
	while (iterador != nullptr)
	{
		FiguraTest figura = iterador->getValor();
		cout << figura.getTipusFigura() << " " << figura.getPosY() << " " << figura.getPosX() << " " << figura.getNGirsHoraris() << endl;
		iterador = iterador->getNext();
	}
}


void TextInfo::invertirFigura()
{
	NodeFigura* previo = nullptr, * actual = m_figuras, * next = nullptr;

	while (actual != nullptr)
	{
		//guarda el next nodo
		next = actual->getNext();
		// giramos la dirección
		actual->setNext(previo);
		// movemos los iterados en un nodo previo -> actual y actual -> siguiente
		previo = actual;
		actual = next;
	}
	//para guarda el nuevo primero de la cola
	m_figuras = previo;
}

void TextInfo::invertirMoviment()
{
	Node* previo = nullptr, * actual = m_moviments, * next = nullptr;

	while (actual != nullptr)
	{
		//guarda el next nodo
		next = actual->getNext();
		// giramos la dirección
		actual->setNext(previo);
		// movemos los iterados en un nodo previo -> actual y actual -> siguiente
		previo = actual;
		actual = next;
	}
	//para guarda el nuevo primero de la cola
	m_moviments = previo;
}

=======
﻿#include "testLlista.h"
#include <iostream>
using namespace std;

void TextInfo::afegeixMoviment(const int& moviment)
{
	Node* aux = new Node;
	aux->setValor(moviment);
	aux->setNext(m_moviments);
	m_moviments = aux;
	m_firstMov = aux;
	m_nMoviments++;
}

// avanza en la lista de nodos enlazados
bool TextInfo::nextMov() {
	bool fiMoviments = false;
	if (m_moviments->getNext() != nullptr) {
		*m_moviments = *m_moviments->getNext();
	}
	else 
		fiMoviments = true;
	return fiMoviments;
}

//per tornar al inici de la lista
void TextInfo::reiniciarMov()
{
	*m_moviments = *m_firstMov;
}

void TextInfo::afegeixFigura(const int& figura, const int& y, const int& x, const int& nGirsH)
{
	NodeFigura* aux = new NodeFigura;
	aux->setValor(figura, y, x, nGirsH);
	aux->setNext(m_figuras);
	m_figuras = aux;
	m_nFiguras++;
}

Node* TextInfo::ultiMoviment() const
{
	Node* ultim = new Node;
	ultim = m_moviments;
	while (ultim->getNext() != nullptr)
	{
		ultim = ultim->getNext();
	}
	return ultim;
}

NodeFigura* TextInfo::ultimaFigura() const
{
	NodeFigura* ultim = new NodeFigura;
	ultim = m_figuras;
	while (ultim->getNext() != nullptr)
	{
		ultim = ultim->getNext();
	}
	return ultim;
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
		m_nFiguras--;
		delete aux;
	}
}

void TextInfo::mostraFiguraInfo() const
{
	NodeFigura* iterador = new NodeFigura;
	iterador = m_figuras;
	
	while (iterador != nullptr)
	{
		FiguraTest figura = iterador->getValor();
		cout << figura.getTipusFigura() << " " << figura.getPosY() << " " << figura.getPosX() << " " << figura.getNGirsHoraris() << endl;
		iterador = iterador->getNext();
	}
}


void TextInfo::invertirFigura()
{
	NodeFigura* previo = nullptr, * actual = m_figuras, * next = nullptr;

	while (actual != nullptr)
	{
		//guarda el next nodo
		next = actual->getNext();
		// giramos la dirección
		actual->setNext(previo);
		// movemos los iterados en un nodo previo -> actual y actual -> siguiente
		previo = actual;
		actual = next;
	}
	//para guarda el nuevo primero de la cola
	m_figuras = previo;
}

void TextInfo::invertirMoviment()
{
	Node* previo = nullptr, * actual = m_moviments, * next = nullptr;

	while (actual != nullptr)
	{
		//guarda el next nodo
		next = actual->getNext();
		// giramos la dirección
		actual->setNext(previo);
		// movemos los iterados en un nodo previo -> actual y actual -> siguiente
		previo = actual;
		actual = next;
	}
	//para guarda el nuevo primero de la cola
	m_moviments = previo;
}

