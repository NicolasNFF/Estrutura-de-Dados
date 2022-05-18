#include <iostream>
#include "ListaLinearOrdenada.h"

using namespace std;

template <class TInfo>
ListaLinearOrdenada<TInfo>::ListaLinearOrdenada()
{
	this->head = NULL;
	this->tail = NULL;
	this->size = 0;
}
template <class TInfo>
ListaLinearOrdenada<TInfo>::ListaLinearOrdenada(ListaLinearOrdenada&){
// vazio
}

template <class TInfo>
ListaLinearOrdenada<TInfo>::~ListaLinearOrdenada()
{
	while (!this->isEmpty())
	{
		delete this->RemoverFinal();
	}
}

template <class TInfo>
Node<TInfo> *  ListaLinearOrdenada<TInfo>::RemoverInicio()
{
	Node<TInfo> * aux;

	if (this->isEmpty())
	{
		throw "A lista está vazia";
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

template <class TInfo>
Node<TInfo> * ListaLinearOrdenada<TInfo>::RemoverFinal()
{
	Node<TInfo> * aux;

	if (this->isEmpty())
	{
		throw "A lista está vazia";
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

template <class TInfo>
void ListaLinearOrdenada<TInfo>::Inserir(Node<TInfo> * node)
{
	bool wasInserted = false;
	Node<TInfo> * nodeAux = this->head;

	if (node == NULL)
	{
		throw "Node � nulo";
	}

	// integridade dos elos
	node->setNext(NULL);
	node->setPrev(NULL);

	if (this->isEmpty())
	{
		this->head = node;
		this->tail = node;
	}
	else
	{
		while(!wasInserted)
		{
			if(node->getInfo() <= nodeAux->getInfo())
			{
				if(nodeAux == this->head)
					this->head = node;

				node->setNext(nodeAux);
				if(nodeAux->getPrev() != NULL)
				{
					node->setPrev(nodeAux->getPrev());
					(nodeAux->getPrev())->setNext(node);
				}
				nodeAux->setPrev(node);
				wasInserted = true;
			}
			else
			{
				if(nodeAux->getNext() == NULL)
				{
					nodeAux->setNext(node);
					node->setPrev(nodeAux);
					this->tail = node;
					wasInserted = true;
				}
				else
				{
					if(node->getInfo() < (nodeAux->getNext())->getInfo())
					{
						node->setPrev(nodeAux);
						if(nodeAux->getNext() != NULL)
						{
							node->setNext(nodeAux->getNext());
							nodeAux->getNext()->setPrev(node);
						}
						nodeAux->setNext(node);
						wasInserted = true;
					}
				}
			}
			if(nodeAux->getNext() != NULL && !wasInserted)
				nodeAux = nodeAux->getNext();
		}
	}

	this->addSize();
}

template <class TInfo>
long ListaLinearOrdenada<TInfo>::getSize()
{
	return this->size;
}

template <class TInfo>
bool ListaLinearOrdenada<TInfo>::isEmpty()
{
	bool retValue = false;
	if (this->size == 0)
	{
		if (this->head == NULL)
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
		if (this->head == NULL)
		{
			throw "Lista linear corrompida!";
		}
	}
	return retValue;
}

template <class TInfo>
void ListaLinearOrdenada<TInfo>::dump()
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

template <class TInfo>
void ListaLinearOrdenada<TInfo>::addSize()
{
	this->size++;
}

template <class TInfo>
void ListaLinearOrdenada<TInfo>::decSize()
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

template class ListaLinearOrdenada<int>;
template class ListaLinearOrdenada<long>;
template class ListaLinearOrdenada<float>;
template class ListaLinearOrdenada<double>;
