#include <iostream>
#include "Fila.h"

using namespace std;

template <class TInfo>
Fila<TInfo>::Fila()
{
	LLE = new ListaLinear<TInfo>();
}

template <class TInfo>
Fila<TInfo>::~Fila()
{
    delete LLE;
}

template <class TInfo>
void Fila<TInfo>::Push(Node<TInfo> * node)
{
	this->LLE->InserirFinal(node);
}

template <class TInfo>
Node<TInfo> * Fila<TInfo>::Pop()
{
	return this->LLE->RemoverInicio();
}

template <class TInfo>
void Fila<TInfo>::Dump()
{
	this->LLE->dump();
}

template <class TInfo>
bool Fila<TInfo>::IsEmpty()
{
	return LLE->isEmpty();
}



template class Fila<int>;
template class Fila<long>;
template class Fila<float>;
template class Fila<double>;
template class Fila<char>;
