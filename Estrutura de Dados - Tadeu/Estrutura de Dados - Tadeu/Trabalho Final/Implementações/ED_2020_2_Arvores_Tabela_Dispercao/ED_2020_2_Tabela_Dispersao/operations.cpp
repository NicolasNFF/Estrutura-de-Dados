/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "operations.h"

long fhash(long key)
{
    return key % 1024;
}

void set(HashTable * hash, long key,int value)
{
    ITEM * item = new ITEM;
    item->key = key;
    item->value = value;
    hash[fhash(key)] = item;
}

int get(HashTable * hash, long key)
{
    ITEM * item = hash[fhash(key)];
    return item->value;
}