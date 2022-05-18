/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OrdBinTree.cpp
 * Author: atm
 * 
 * Created on 30 de Junho de 2020, 10:08
 */

#include "OrdBinTree.h"

template <class TInfo>
OrdBinTree<TInfo>::OrdBinTree() {
    root = NULL;
}

template <class TInfo>
OrdBinTree<TInfo>::OrdBinTree(const OrdBinTree& orig) {
}

template <class TInfo>
OrdBinTree<TInfo>::~OrdBinTree() {
    delete this->root;
}

template <class TInfo>
void OrdBinTree<TInfo>::insert(TNode<TInfo> * node) {
    TNode<TInfo> * aux = this->root;
    TNode<TInfo> * ant_aux;
    bool pos = true; // true = left e false = right

    // se a arvore estiver vazia (nó raiz igual a nulo)
    if (this->root == NULL) {
        this->root = node;
        return;
    }

    while (aux != NULL) {
        ant_aux = aux;
        void show();
        if (node->getInfo() <= aux->getInfo()) {

            aux = aux->getLeftNode();
            pos = true;
        } else {
            aux = aux->getRightNode();
            pos = false;
        }
    }

    if (pos) {
        ant_aux->addLeft(node);
    } else {
        ant_aux->addRight(node);
    }

}

template <class TInfo>
void OrdBinTree<TInfo>::show() {
    cout << endl;
    this->showNode(this->root, 0);
}

void showTabs(int n) {
    while (n > 0) {
        cout << "\t";
        n--;
    }
}

template <class TInfo>
void OrdBinTree<TInfo>::showNode(TNode<TInfo> * node, int desloc) {
    int i = desloc;

    if (node == NULL) {
        return;
    }

    cout << endl;
    showTabs(desloc);
    showNode(node->getRightNode(), desloc + 1);
    cout << endl;
    showTabs(desloc);
    cout << node->getInfo();
    cout << endl;
    showTabs(desloc);
    showNode(node->getLeftNode(), desloc + 1);
}

template <class TInfo>
void OrdBinTree<TInfo>::showLinear() {
    this->showNodeLinear(this->root);
}

template <class TInfo>
void OrdBinTree<TInfo>::showNodeLinear(TNode<TInfo> * node) {
    if (node == NULL) {
        return;
    }
    cout << "->";
    showNodeLinear(node->getLeftNode());
    cout << "->" << node->getInfo() << "->";
    showNodeLinear(node->getRightNode());
}

template <class TInfo>
bool OrdBinTree<TInfo>::exists(TInfo info)
{
    /*
     *  if (this->getInfo() == NULL)
     *      return false
     *  else
     *      return true
     */
    return (this->get(info) == NULL ? false : true);
    
}

template <class TInfo>
TNode<TInfo> * OrdBinTree<TInfo>::getNode(TInfo info)
{
    return this->get(info);
}

template <class TInfo>
TNode<TInfo> * OrdBinTree<TInfo>::get(TInfo info) {
    return this->getElement(this->root,info);
}

template <class TInfo>
TNode<TInfo> * OrdBinTree<TInfo>::getElement(TNode<TInfo> * node, TInfo info)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (node->getInfo() == info)
    {
        return node;
    }
    if (node->getInfo() > info)
    {
        return this->getElement(node->getLeftNode(), info);
    }
    else
    {
        return this->getElement(node->getRightNode(), info);
    }
    
    return NULL;
}

template class OrdBinTree<int>;
template class OrdBinTree<long>;
template class OrdBinTree<float>;
template class OrdBinTree<double>;
template class OrdBinTree<string>;

