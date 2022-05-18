#include "NODE.h"

template <class TInfo>
class ListaLinearOrdenada
{
private:

protected:
	Node<TInfo> * head;
	Node<TInfo> * tail;
	long size;

	void addSize();
	void decSize();
public:
	ListaLinearOrdenada();
	ListaLinearOrdenada(ListaLinearOrdenada&);
	~ListaLinearOrdenada();

	bool isEmpty();
	Node<TInfo> *  RemoverFinal();
	Node<TInfo> *  RemoverInicio();
	void Inserir(Node<TInfo> *);
	long getSize();
	void dump();
};
