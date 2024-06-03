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
	void setValor(const int& tipusFigura, const int& y, const int& x, const int& nGirsHoraris) { m_valor.inicializar(tipusFigura, y, x, nGirsHoraris); };
	void setNext(NodeFigura* next) { m_next = next; };

private:
	FiguraTest m_valor;
	NodeFigura* m_next;

};

=======
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
	void setValor(const int& tipusFigura, const int& y, const int& x, const int& nGirsHoraris) { m_valor.inicializar(tipusFigura, y, x, nGirsHoraris); };
	void setNext(NodeFigura* next) { m_next = next; };

private:
	FiguraTest m_valor;
	NodeFigura* m_next;

};

