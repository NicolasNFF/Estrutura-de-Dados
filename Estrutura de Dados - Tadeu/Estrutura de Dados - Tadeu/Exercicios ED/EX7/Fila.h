#ifndef FILA_H
#define FILA_H
#ifndef LISTALINEAR_H
#include "ListaLinear.h"
#endif // LISTALINEAR_H

template <class TInfo>
class Fila
{
    public:
        Fila();
        virtual ~Fila();
        void Push(Node<TInfo> * );
        Node<TInfo> * Pop();
        void Dump();
        bool IsEmpty();

    protected:
        ListaLinear<TInfo> * LLE;
    private:
};

#endif // FILA_H
