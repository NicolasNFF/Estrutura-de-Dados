#include <iostream>
#include "Fila.h"

using namespace std;

int main()
{
    int num;
    Node<int> * node = NULL;
    Fila<int> * F = new Fila<int>();
    bool wasEven = true;
    bool wasDiferent = true;

    cin >> num;
    while(num >= 0){
        node = new Node<int>();
        node->setInfo(num);
        F->Push(node);
        cin >> num;
    }

    node = F->Pop();
    if(node->getInfo() % 2 == 0){
        wasEven = true;
    }
    else{
        wasEven = false;
    }

    while(!F->IsEmpty()){
        node = F->Pop();
        if(node->getInfo() % 2 == 0 && wasEven){
            wasDiferent = false;
        }
        if(!(node->getInfo() % 2 == 0) && !wasEven){
            wasDiferent = false;
        }

        if(node->getInfo() % 2 == 0){
            wasEven = true;
        }
        else{
            wasEven = false;
        }
    }

    if(wasDiferent){
        cout << "SIM\n";
    }
    else{
        cout << "NAO\n";
    }

    return 0;
}
