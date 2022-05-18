/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TNode.cpp
 * Author: atm
 * 
 * Created on 26 de Junho de 2020, 07:16
 */

#include "TNode.h"

// método de apoio

template <class TInfo>
void TNode<TInfo>::showTree(TNode<TInfo> * aux) {
    cout << '\t';
    if (aux == NULL) {
        return;
    }
    showTree(aux->left);
    cout << '\t' << *(aux->info);
    showTree(aux->right);
}

template <class TInfo>
TNode<TInfo>::TNode() {
    this->info = NULL;
    this->left = NULL;
    this->right = NULL;
}

template <class TInfo>
TNode<TInfo>::TNode(const TNode& orig) {
}

template <class TInfo>
TNode<TInfo>::~TNode() {
    delete this->info;
    delete this->right;
    delete this->left;
    this->info = NULL;
    this->left = NULL;
    this->right = NULL;
}

template <class TInfo>
void TNode<TInfo>::addInfo(TInfo * info) {
    this->info = info;
}

template <class TInfo>
void TNode<TInfo>::addLeft(TNode<TInfo> * node) {
    this->left = node;
}

template <class TInfo>
void TNode<TInfo>::addRight(TNode<TInfo> * node) {
    this->right = node;
}

template <class TInfo>
void TNode<TInfo>::dump() {
    if (this->info == NULL) {
        return;
    }
    showTree(this->left);
    cout << '\n';
    cout << "->" << *(this->info);
    cout << '\n';
    showTree(this->right);
}

template <class TInfo>
TInfo TNode<TInfo>::getInfo() {
    if (this->info != NULL) {
        return *(this->info);
    }
}

template <class TInfo>
void TNode<TInfo>::setLeftNode(TNode<TInfo> * node) {
    if (this->left != NULL) {
        throw "Nao pode inserir nodo. Left nao e nulo";
    }
    this->left = node;
}

template <class TInfo>
void TNode<TInfo>::setRightNode(TNode<TInfo> * node) {
    if (this->right != NULL) {
        throw "Nao pode inserir nodo. right nao e nulo";
    }
    this->right = node;
}

template <class TInfo>
TNode<TInfo> * TNode<TInfo>::getLeftNode() {
    return this->left;
}

template <class TInfo>
TNode<TInfo> * TNode<TInfo>::getRightNode() {
    return this->right;
}

template class TNode<int>;
template class TNode<long>;
template class TNode<float>;
template class TNode<double>;
template class TNode<string>;