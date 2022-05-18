#include <iostream>
#include "NODE.h"

// construtor
template <class TInfo>
Node<TInfo>::Node()
{
	//this->info = 0;
	this->next = NULL;
	this->prev = NULL;
}
// construtor de clonagem
template <class TInfo>
Node<TInfo>::Node(Node& node)
{
	this->info = node.getInfo();
	this->next = node.getNext();
	this->prev = node.getPrev();
}
// destrutor
template <class TInfo>
Node<TInfo>::~Node(){
	//info = 0;
	this->next = NULL;
	this->prev = NULL;
}
// setter
template <class TInfo>
void Node<TInfo>::setInfo(TInfo info)
{
	this->info = info;
}
template <class TInfo>
void Node<TInfo>::setNext(Node * node)
{
	this->next = node;
}
template <class TInfo>
void Node<TInfo>::setPrev(Node * node)
{
	this->prev = node;
}
// getter
template <class TInfo>
TInfo Node<TInfo>::getInfo()
{
	return this->info;
}
template <class TInfo>
Node<TInfo> * Node<TInfo>::getNext()
{
	return this->next;
}
template <class TInfo>
Node<TInfo> * Node<TInfo>::getPrev()
{
	return this->prev;
}

template class Node<int>;
template class Node<long>;
template class Node<float>;
template class Node<double>;
template class Node<char>;
