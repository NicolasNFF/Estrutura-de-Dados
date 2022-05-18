#include <iostream>
#include "Pilha.h"

using namespace std;

template <class TInfo>
Pilha<TInfo>::Pilha()
{
	LLE = new ListaLinear<TInfo>();
}

template <class TInfo>
Pilha<TInfo>::~Pilha()
{
    delete LLE;
}

template <class TInfo>
void Pilha<TInfo>::Push(Node<TInfo> * node)
{
	this->LLE->InserirFinal(node);
}

template <class TInfo>
Node<TInfo> * Pilha<TInfo>::Pop()
{
	return this->LLE->RemoverFinal();
}

template <class TInfo>
void Pilha<TInfo>::Dump()
{
	this->LLE->dump();
}

template <class TInfo>
bool Pilha<TInfo>::IsEmpty()
{
	return LLE->isEmpty();
}


template class Pilha<int>;
template class Pilha<long>;
template class Pilha<float>;
template class Pilha<double>;
template class Pilha<char>;
