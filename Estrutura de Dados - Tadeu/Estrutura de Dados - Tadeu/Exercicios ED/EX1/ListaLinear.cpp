#include <iostream>
#include "ListaLinear.h"
using namespace std;

// public methods

// construtor
template <class TInfo>
ListaLinear<TInfo>::ListaLinear()
{
	this->head = NULL;
	this->tail = NULL;
	this->size = 0;
}

// construtor de c�pia clonagem
template <class TInfo>
ListaLinear<TInfo>::ListaLinear(ListaLinear&){
// vazio
}

// destrutor
template <class TInfo>
ListaLinear<TInfo>::~ListaLinear()
{
	while (!this->isEmpty())
	{
		delete this->RemoverFinal();
	}
}
/*
destrutor (l�gica b�sica)
ListaLinear<TInfo>::~ListaLinear()
{
	Node * aux = this->tail;

	while (aux != NULL)
	{
	   aux = tail->getPrev();
	   delete this->tail;
	   this->tail = aux;
	   this->decSize();
	}
	this->head = this->tail = NULL;
	this->size = 0;
}
*/

// opera��es da insterface
/*
   inserir um n� no in�cio da Lista
*/
template <class TInfo>
void ListaLinear<TInfo>::InserirInicio(Node<TInfo> * node)
{
	if (node == NULL)
	{
		throw "Node � nulo";
	}

	// integridade dos elos
	node->setNext(NULL);
	node->setPrev(NULL);

	if (this->isEmpty())
	{
		this->head = this->tail = node;
	}
	else
	{
		node->setNext(this->head);
		(this->head)->setPrev(node);
		this->head = node;
	}

	this->addSize();
}
/*
    Remover um n� (node) do in�cio da lista
*/
template <class TInfo>
Node<TInfo> *  ListaLinear<TInfo>::RemoverInicio()
{
	Node<TInfo> * aux;

	if (this->isEmpty())
	{
		throw "A lista est� vazia";
	}

    aux = this->head;

	if (this->getSize() == 1)
	{
		this->head = this->tail = NULL;
	}
	else
	{
		this->head = aux->getNext();
		(this->head)->setPrev(NULL);
	}

    this->decSize();

	aux->setNext(NULL);
	aux->setPrev(NULL);

	return aux;
}

/*
    Inserir um n� (node) no final da Lista
*/
template <class TInfo>
void ListaLinear<TInfo>::InserirFinal(Node<TInfo> * node)
{
	if (node == NULL)
	{
		throw "Node � nulo";
	}

	// integridade dos elos
	node->setNext(NULL);
	node->setPrev(NULL);

	if (this->isEmpty())
	{
		this->head = this->tail = node;
	}
	else
	{
		node->setPrev(this->tail);
		(this->tail)->setNext(node);
		this->tail = node;
	}

	this->addSize();
}

/*
    Remover um n� do final da lista
*/
template <class TInfo>
Node<TInfo> * ListaLinear<TInfo>::RemoverFinal()
{
	Node<TInfo> * aux;

	if (this->isEmpty())
	{
		throw "A lista est� vazia";
	}

    aux = this->tail;

	if (this->getSize() == 1)
	{
		this->head = this->tail = NULL;
	}
	else
	{
		this->tail = aux->getPrev();
		(this->tail)->setNext(NULL);
	}

    this->decSize();

	aux->setNext(NULL);
	aux->setPrev(NULL);

	return aux;
}

/*
Retorn ao tamanho da lista
*/
template <class TInfo>
long ListaLinear<TInfo>::getSize()
{
	return this->size;
}

template <class TInfo>
Node<TInfo> * ListaLinear<TInfo>::getHead()
{
	return this->head;
}

/*
    Consultar se a lista esta vazia
	  retorno TRUE se a lista esta vazia
      retorno FALSE se a lista n�o estiver vazia
*/
template <class TInfo>
bool ListaLinear<TInfo>::isEmpty()
{
	bool retValue = false;
	if (this->size == 0)
	{
		if (this->head == NULL && this->tail == NULL)
		{
			retValue = true;
		}
		else
		{
			throw "Lista linear corrompida!";
		}
	}
	else
	{
		if (this->head == NULL || this->tail == NULL)
		{
			throw "Lista linear corrompida!";
		}
	}
	return retValue;
}

/*
    Exibir os elementos da lista

	exibe:

    [end. do n�] [end. n� ant.] info [end. prox. n�]
*/
template <class TInfo>
void ListaLinear<TInfo>::dump()
{
	Node<TInfo> * aux = this->head;
	while (aux != NULL)
	{
		cout << "[" << hex << aux << "] ";
		cout << "[" << hex << aux->getPrev() << "] ";
		cout << dec << aux->getInfo();
		cout << "[" << hex << aux->getNext() << "]" << endl;
		aux = aux->getNext();
	}
}

// protected methods
/*
    incremeta o tamanho da lista
*/
template <class TInfo>
void ListaLinear<TInfo>::addSize()
{
	this->size++;
}

/*
    decrementa o tamanho da lista
*/
template <class TInfo>
void ListaLinear<TInfo>::decSize()
{
	if (this->size <= 0)
	{
		throw "Lista vazia";
	}
	else
	{
		this->size--;
	}
}

template class ListaLinear<int>;
template class ListaLinear<long>;
template class ListaLinear<float>;
template class ListaLinear<double>;
template class ListaLinear<char>;
