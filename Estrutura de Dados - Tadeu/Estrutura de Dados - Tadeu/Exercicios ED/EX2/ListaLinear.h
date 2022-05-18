#include "NODE.h"

template <class TInfo>
class ListaLinear
{
private:

protected:
	/*
	   Atribuitos protegidos
	*/
	Node<TInfo> * head;  // ponteiro para o início da lista
	Node<TInfo> * tail;  // ponteiro para o último nó da lista
	long size;	  // tamanho ou qtde de nós da lista
	/*
	   Métodos protegidos
	*/
	void addSize();  // incrementa o tamanho da lista
	void decSize();	 // decrementa o tamanho da lista
public:
	/*
	   Métodos públicos
	*/

	// construtores e destrutor
	ListaLinear();             // LinkList ou List
	ListaLinear(ListaLinear&);
	~ListaLinear();

	// métodos da interface da classe
	void InserirInicio(Node<TInfo> *); // insert
	Node<TInfo> *  RemoverInicio();    // remove
	void InserirFinal(Node<TInfo> *);  // append
	Node<TInfo> *  RemoverFinal();	    // pop
	long getSize(); // retorna o tamanho da lista
	Node<TInfo> * getHead();
	bool isEmpty(); // retorna TRUE se a lista está vazia
	void dump();    // exibe a lista e os respectivos endereços
	                // dos nós
};


