/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TNode.h
 * Author: atm
 *
 * Created on 26 de Junho de 2020, 07:16
 */

#include <string>
#include <iostream>

using namespace std;

#ifndef TNODE_H
#define TNODE_H

template <class TInfo>
class TNode {
protected:
    TInfo * info;
    TNode<TInfo> * left;
    TNode<TInfo> * right;
    
    void showTree(TNode<TInfo> *);
public:
    TNode();
    TNode(const TNode& orig);
    virtual ~TNode();
    
    // métodos da interface
    void addInfo(TInfo *);
    void addLeft(TNode<TInfo> *);
    void addRight(TNode<TInfo> *);
    TInfo getInfo();
    void setLeftNode(TNode<TInfo> * node);
    void setRightNode(TNode<TInfo> * node);
    TNode<TInfo> * getLeftNode();
    TNode<TInfo> * getRightNode();
    void dump();
private:

};

#endif /* TNODE_H */

