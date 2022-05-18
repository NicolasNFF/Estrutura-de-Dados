/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: atm
 *
 * Created on 13 de Novembro de 2020, 07:36
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    long limit = 1000;
    
    if (argc < 2)
    {
        cerr << "\n\nNumero de parametros invalido!";
        cerr << "\n\nexecute:";
        cerr << argv[0] << " <quantidade de numeros>\n\n";
        exit(-1);
    }
    
    srand(time(NULL));
    
    for (long i=0; i < atol(argv[1]); i++)
    {
        cout << (rand() % limit) << "\t";
    }
    
    return 0;
}

