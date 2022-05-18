/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   operations.h
 * Author: atm
 *
 * Created on 6 de Novembro de 2020, 09:02
 */

#include "tree.h"
#include <cstdlib>
#include <iostream>

#ifndef OPERATIONS_H
#define OPERATIONS_H

extern bool isEmpty(Tree **); 

extern void addLeft(Tree **, INFO);
extern void addRight(Tree **, INFO);
extern Tree * getRightNode(Tree *);
extern Tree * getLeftNode(Tree *);
extern INFO getInfo(Tree *);
extern void showNode(Tree *, int);
extern void addOrd(Tree **, INFO);
extern void getAscOrd(Tree *);
extern void getDescOrd(Tree *);
extern TNODO * search(Tree *, INFO);
void insertBalance(Tree **, INFO, bool *);
#endif /* OPERATIONS_H */

