#include <iostream>
#include "Fila.h"

using namespace std;

int main()
{
    int num;
    Node<int> *node = NULL;
    Fila<int> *F1 = new Fila<int>();
    Fila<int> *FP = new Fila<int>();
    Fila<int> *FI = new Fila<int>();

    cin >> num;
    while (num >= 0)
    {
        node = new Node<int>();
        node->setInfo(num);
        F1->Push(node);
        cin >> num;
    }

    while (!F1->IsEmpty())
    {
        node = F1->Pop();
        if (node->getInfo() % 2 == 0)
            FP->Push(node);
        else
            FI->Push(node);
    }

    while (!FI->IsEmpty())
    {
        num = FI->Pop()->getInfo();
        cout << num << "\n";
    }
    while (!FP->IsEmpty())
    {
        num = FP->Pop()->getInfo();
        cout << num << "\n";
    }
}
