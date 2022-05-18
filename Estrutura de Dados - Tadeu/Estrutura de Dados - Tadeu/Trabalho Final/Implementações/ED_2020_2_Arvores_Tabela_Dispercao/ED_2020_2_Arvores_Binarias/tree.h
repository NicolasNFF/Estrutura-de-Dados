/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tree.h
 * Author: atm
 *
 * Created on 6 de Novembro de 2020, 08:58
 */

#ifndef TREE_H
#define TREE_H

typedef int INFO;
typedef struct STNODO TNODO;
typedef TNODO Tree;

struct STNODO 
{
    TNODO * left;
    INFO info;
    TNODO * right;
    // inserçoes balanceadas
    int bal;   // -1, 0, 1
    int count; // duplicatas
};


#endif /* TREE_H */

