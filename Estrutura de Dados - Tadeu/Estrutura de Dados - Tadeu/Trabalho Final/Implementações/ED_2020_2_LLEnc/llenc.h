/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   llenc.h
 * Author: atm
 *
 * Created on 9 de Outubro de 2020, 07:53
 */

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#ifndef LLENC_H
#define LLENC_H

typedef int INFO;
typedef struct SNODO NODO;
typedef NODO ListaLinear;

struct SNODO 
{
    NODO * ant;
    NODO * prox;
    INFO info;
};

#endif /* LLENC_H */

