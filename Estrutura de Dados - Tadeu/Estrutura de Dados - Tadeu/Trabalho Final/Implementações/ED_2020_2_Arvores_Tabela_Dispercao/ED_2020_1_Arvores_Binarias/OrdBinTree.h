/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OrdBinTree.h
 * Author: atm
 *
 * Created on 30 de Junho de 2020, 10:07
 */

#ifndef ORDBINTREE_H
#define ORDBINTREE_H

#include "TNode.h"
template <class TInfo>
class OrdBinTree {
public:
    OrdBinTree();
    OrdBinTree(const OrdBinTree& orig);
    virtual ~OrdBinTree();
    
    void insert(TNode<TInfo> * node);
    void show();
    void showLinear();
    bool exists(TInfo info);
    TNode<TInfo> * getNode(TInfo info);
    
private:
    TNode<TInfo> * root;
    void showNode(TNode<TInfo> * node, int desloc);
    void showNodeLinear(TNode<TInfo> * node);
    TNode<TInfo> * get(TInfo info);
    
protected:
    TNode<TInfo> * getElement(TNode<TInfo> * node, TInfo info);
};

#endif /* ORDBINTREE_H */

