#include <iostream>
#include <cctype>
#include "Pilha.h"

using namespace std;

int main()
{
    char letter;
    Pilha<char> * P1 = new Pilha<char>();
    Pilha<char> * P2 = new Pilha<char>();
    Node<char> * node = NULL;
    Node<char> * nodeAux = NULL;
    bool isMatch = true;

    cin >> letter;
    while(letter != '0'){
        node = new Node<char>();
        node->setInfo(letter);
        P1->Push(node);
        cin >> letter;
    }

    cin >> letter;
    while(letter != '0'){
        node = new Node<char>();
        node->setInfo(letter);
        P2->Push(node);
        cin >> letter;
    }

    while(!P1->IsEmpty()){
        node = P1->Pop();
        nodeAux = P2->Pop();

        if(isupper(node->getInfo()) != isupper(nodeAux->getInfo())){
            isMatch = false;
        }

    }

    if(isMatch){
        cout << "SIM\n";
    }
    else{
        cout << "NAO\n";
    }
    return 0;
}
