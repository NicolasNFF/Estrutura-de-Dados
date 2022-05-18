/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hashtable.h
 * Author: atm
 *
 * Created on 24 de Novembro de 2020, 11:25
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct SItem ITEM;
typedef ITEM * HashTable;

struct SItem 
{
    long key;
    int  value;
};



#endif /* HASHTABLE_H */

