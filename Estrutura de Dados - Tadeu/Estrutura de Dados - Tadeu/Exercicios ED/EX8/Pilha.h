#ifndef PILHA_H
#define PILHA_H
#ifndef LISTALINEAR_H
#include "ListaLinear.h"
#endif // LISTALINEAR_H

template <class TInfo>
class Pilha
{
    public:
        Pilha();
        virtual ~Pilha();
        void Push(Node<TInfo> * );
        Node<TInfo> * Pop();
        void Dump();
        bool IsEmpty();

    protected:
        ListaLinear<TInfo> * LLE;
    private:
};

#endif // PILHA_H
