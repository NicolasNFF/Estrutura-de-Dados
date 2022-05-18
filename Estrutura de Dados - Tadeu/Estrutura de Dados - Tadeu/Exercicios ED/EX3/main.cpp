#include <iostream>
#include "ListaLinearOrdenada.h"

using namespace std;

int main()
{
    ListaLinearOrdenada<int> * ll1 = new ListaLinearOrdenada<int>();
    ListaLinearOrdenada<int> * ll2 = new ListaLinearOrdenada<int>();
    ListaLinearOrdenada<int> * ll3 = new ListaLinearOrdenada<int>();

   Node<int> * node = NULL;
	int num;

	while(num >= 0)
	{
		cin >> num;
        if(num >= 0){
            node = new Node<int>;
            node->setInfo(num);
            ll1->Inserir(node);
        }
	}
	num = 0;
	while(num >= 0)
	{
		cin >> num;
        if(num >= 0){
            node = new Node<int>;
            node->setInfo(num);
            ll2->Inserir(node);
        }
	}

    while(!ll1->isEmpty() || !ll2->isEmpty()){

        if(!ll1->isEmpty()){
            num = ll1->RemoverInicio()->getInfo();
            node = new Node<int>;
            node->setInfo(num);
            ll3->Inserir(node);
        }

        if(!ll2->isEmpty()){
            num = ll2->RemoverInicio()->getInfo();
            node = new Node<int>;
            node->setInfo(num);
            ll3->Inserir(node);
        }
    }

    while(!ll3->isEmpty())
	{
		num = ll3->RemoverInicio()->getInfo();
		cout << num <<"\n";
	}

	return 0;
}
