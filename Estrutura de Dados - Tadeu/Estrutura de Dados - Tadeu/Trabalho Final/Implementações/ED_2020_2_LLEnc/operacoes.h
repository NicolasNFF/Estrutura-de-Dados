/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   operacoes.h
 * Author: atm
 *
 * Created on 9 de Outubro de 2020, 07:51
 */

#ifndef OPERACOES_H
#define OPERACOES_H

#include "llenc.h"
#include "pilha.h"
#include "fila.h"


extern bool isEmpty(ListaLinear *);
extern void Show(ListaLinear *);
extern void InserirInicio(ListaLinear **, INFO);
extern NODO * RemoverInicio(ListaLinear **);
extern NODO * GetFinalNode(ListaLinear **);
extern void InserirFinal(ListaLinear **, INFO);
extern NODO * RemoverFinal(ListaLinear **);
extern bool search(ListaLinear *, INFO);
extern INFO getValuePos(ListaLinear *, int);
extern NODO * getNodePos(ListaLinear **, long);
extern void InserirPosN(ListaLinear **, INFO info, long pos);
extern NODO * RemoverPosN(ListaLinear **, long);


// Operaçoes Pilha

extern void push(Pilha **, INFO); // incluir nodos na pilha
extern NODO * pop(Pilha **); // retirar um nodo da pilha

// Operaçoes Fila

extern void insert(Fila **, INFO); // incluir nodo na fila
extern NODO * remove(Fila **); // retirar nodo da Fila


#endif /* OPERACOES_H */

