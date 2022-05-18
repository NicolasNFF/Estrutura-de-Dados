#include "NODE.h"

template <class TInfo>
class ListaLinear
{
private:

protected:
	/*
	   Atribuitos protegidos
	*/
	Node<TInfo> * head;  // ponteiro para o in�cio da lista
	Node<TInfo> * tail;  // ponteiro para o �ltimo n� da lista
	long size;	  // tamanho ou qtde de n�s da lista
	/*
	   M�todos protegidos
	*/
	void addSize();  // incrementa o tamanho da lista
	void decSize();	 // decrementa o tamanho da lista
public:
	/*
	   M�todos p�blicos
	*/

	// construtores e destrutor
	ListaLinear();             // LinkList ou List
	ListaLinear(ListaLinear&);
	~ListaLinear();

	// m�todos da interface da classe
	void InserirInicio(Node<TInfo> *); // insert
	Node<TInfo> *  RemoverInicio();    // remove
	void InserirFinal(Node<TInfo> *);  // append
	Node<TInfo> *  RemoverFinal();	    // pop
	long getSize(); // retorna o tamanho da lista
	Node<TInfo> * getHead();
	bool isEmpty(); // retorna TRUE se a lista est� vazia
	void dump();    // exibe a lista e os respectivos endere�os
	                // dos n�s
};


