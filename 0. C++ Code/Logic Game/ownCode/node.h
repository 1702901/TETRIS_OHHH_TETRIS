#pragma once
#include "testFigura.h"
class Node
{
public:
	Node() :m_next(nullptr),m_valor(0) {};
	int& getValor() { return m_valor;; };
	Node* getNext() { return m_next; };
	void setValor(const int& valor) { m_valor = valor; };
	void setNext(Node* next) { m_next = next; };
private:
	int m_valor;
	Node* m_next;
};

class NodeFigura
{
public:
	NodeFigura() :m_next(nullptr) {};
	FiguraTest& getValor() { return m_valor; };
	NodeFigura* getNext() { return m_next; };
	void setValor(const int& valor, const int& v2, const int& v3, const int& v4) { m_valor.inicializar(valor, v2, v3, v4); };
	void setNext(NodeFigura* next) { m_next = next; };

private:
	FiguraTest m_valor;
	NodeFigura* m_next;

};

