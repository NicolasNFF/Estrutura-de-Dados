#include "Classifier.h"
#include <iostream>
#include <cstddef>

template <class TInfo>
Classifier<TInfo>::Classifier(int method)
{

if (method < _BUBBLE_SORT || method > _INSERTION_SORT)

{

throw "Methodo de ordenação nao suportado";

}

this->method = method;

}

template <class TInfo>
Classifier<TInfo>::~Classifier()
{

}

template <class TInfo>
Classifier<TInfo>::Classifier(const Classifier& other)

{

//copy ctor

}

template <class TInfo>
void Classifier<TInfo>::Sort(ListaLinear<TInfo> * LLE)
{

switch (this->method)

{

case _BUBBLE_SORT : BubleSort(LLE);

break;

case _SELECTION_SORT : SelectionSort(LLE);

break;

case _INSERTION_SORT : InsertionSort(LLE);

}

}

template <class TInfo>
void Classifier<TInfo>::BubleSort(ListaLinear<TInfo> * LLE){

    int swapped;
    Node<TInfo> * nodeAux;
    Node<TInfo> * swapNode;
    Node<TInfo> * node = NULL;

    if (LLE->isEmpty())
        return;

    do
    {
        swapped = false;
        nodeAux = LLE->getHead();

        while (nodeAux->getNext() != node)
        {
            if (nodeAux->getInfo() > nodeAux->getNext()->getInfo())
            {
                swapNode->setInfo(nodeAux->getInfo());
                nodeAux->setInfo(nodeAux->getNext()->getInfo());
                nodeAux->getNext()->setInfo(swapNode->getInfo());
                swapped = 1;
            }
            nodeAux = nodeAux->getNext();
        }
        node = nodeAux;
    }
    while (swapped);
}

template <class TInfo>
void Classifier<TInfo>::SelectionSort(ListaLinear<TInfo> * LLE){

}

template <class TInfo>
void Classifier<TInfo>::InsertionSort(ListaLinear<TInfo> * LLE){

}


template class Classifier<int>;
template class Classifier<long>;
template class Classifier<float>;
template class Classifier<double>;
