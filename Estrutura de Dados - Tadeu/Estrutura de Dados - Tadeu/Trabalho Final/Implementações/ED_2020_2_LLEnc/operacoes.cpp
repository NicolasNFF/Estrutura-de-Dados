/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "operacoes.h"

bool isEmpty(ListaLinear * ll) {
    return ll == NULL ? true : false;
    /*
     * if (ll == NULL)
     *     return true;
     * else
     *     return false;
     * 
     */
}

void Show(ListaLinear * ll) {
    while (!isEmpty(ll)) {
        cout << ll->info << " --> ";
        ll = ll->prox;
    }
    cout << endl << endl;
}

void InserirInicio(ListaLinear ** ll, INFO info) {
    NODO * nodo = new NODO;
    nodo->info = info;
    nodo->ant = nodo->prox = NULL;

    if (!isEmpty(*ll)) {
        nodo->prox = (*ll);
        (*ll)->ant = nodo;
    }

    (*ll) = nodo;
}

NODO * RemoverInicio(ListaLinear ** ll) {
    if (isEmpty(*ll)) {
        return NULL;
    }

    NODO * nodo = (*ll);
    (*ll) = (*ll)->prox;
    if (!isEmpty(*ll)) {
        (*ll)->ant = NULL;
    }
    nodo->prox = NULL;

    return nodo;
}

NODO * GetFinalNode(ListaLinear ** ll) {
    NODO * aux = *ll;

    if (isEmpty(*ll)) {
        return NULL;
    }

    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    return aux;
}

void InserirFinal(ListaLinear ** ll, INFO info) {
    if (isEmpty(*ll)) {
        InserirInicio(ll, info);
        return;
    }

    NODO * tail = GetFinalNode(ll);
    NODO * aux = new NODO;
    aux->info = info;
    aux->prox = NULL;

    tail->prox = aux;
    aux->ant = tail;

}

NODO * RemoverFinal(ListaLinear ** ll) {
    if (isEmpty(*ll)) {
        return NULL;
    }

    NODO * tail = GetFinalNode(ll);
    NODO * aux = tail;

    tail = aux->ant;

    if (tail == NULL) {
        *ll = NULL;
    } else {
        tail->prox = aux->ant = NULL;
    }

    return aux;
}

bool search(ListaLinear * ll, INFO info) {
    bool ret = false;

    if (isEmpty(ll)) {
        return ret;
    }

    NODO * aux = ll;

    while (aux != NULL) {
        if (aux->info == info) {
            ret = true;
            break;
        }

        aux = aux->prox;
    }

    return ret;
}

INFO getValuePos(ListaLinear *ll, int pos) {
    int value = 0;

    if (isEmpty(ll)) {
        return value;
    }

    NODO * aux = ll;

    for (int i = 1; aux != NULL; i++) {
        if (i == pos) {
            value = aux->info;
            break;
        }

        aux = aux->prox;
    }

    return value;
}

NODO * getNodePos(ListaLinear **ll, long pos) {
    NODO * ret = NULL;

    if (isEmpty(*ll)) {
        return NULL;
    }

    NODO * aux = *ll;

    for (int i = 1; aux != NULL; i++) {
        if (i == pos) {
            ret = aux;
            break;
        }

        aux = aux->prox;
    }

    if (ret == NULL) {
        return NULL;
    }

    return ret;
}

void InserirPosN(ListaLinear **ll, INFO info, long pos) {

    if (isEmpty(*ll) && pos == 1) {
        InserirInicio(ll, info);
        return;
    }

    NODO * aux = getNodePos(ll, pos);

    if (aux == NULL) {
        return;
    }

    NODO * nodo_novo = new NODO;
    nodo_novo->info -= info;
    nodo_novo->prox = nodo_novo->ant = NULL;

    NODO * aux2 = aux->ant;

    nodo_novo->prox = aux;
    nodo_novo->ant = aux2;
    aux2->prox = nodo_novo;
    aux->ant = nodo_novo;

}

NODO * RemoverPosN(ListaLinear ** ll, long pos) {

    // lista vazia
    if (isEmpty(*ll)) {
        return NULL;
    }
    // apenas um elemento na lista
    if (pos == 1) {
        return RemoverInicio(ll);
    }

    // mais de um elemento na lista
    NODO * aux = getNodePos(ll, pos);
    
    if (aux == NULL) // pos fora da lista ou pos > tamanho da lista
    {
        return NULL;
    }
    
    // se aux = ultimo nodo
    if (aux->prox == NULL)
    {
        return RemoverFinal(ll);
    }
    
    // nodo da posiçao pos e intermediario e tem nodo anterior e proximo assinalado
    NODO * aux_ant = aux->ant;
    NODO * aux_prox = aux->prox;
    
    aux_ant->prox = aux_prox;
    aux_prox->ant = aux_ant;
    aux->ant = aux->prox = NULL;
    
    return aux;
}

void push(Pilha ** pilha, INFO info)
{
    InserirFinal(pilha,info);
}// incluir nodos na pilha


NODO * pop(Pilha ** pilha)
{
    return RemoverFinal(pilha);
}// retirar um nodo da pilha

void insert(Fila ** fila, INFO info)
{
    InserirFinal(fila,info);
} // incluir nodo na fila

NODO * remove(Fila ** fila)
{
    return RemoverInicio(fila);
}// retirar nodo da Fila






