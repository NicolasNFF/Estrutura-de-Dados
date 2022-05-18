#include <iostream>
#include "ListaLinear.h"

using namespace std;

int main()
{
	ListaLinear<int> * ll1 = new ListaLinear<int>();
	ListaLinear<int> * ll2 = new ListaLinear<int>();
	ListaLinear<int> * ll3 = new ListaLinear<int>();
	Node<int> * node = NULL;
	int num;

	while(num >= 0)
	{
		cin >> num;
        if(num >= 0){
            node = new Node<int>;
            node->setInfo(num);
            ll1->InserirFinal(node);
        }
	}
	num = 0;
	while(num >= 0)
	{
		cin >> num;
        if(num >= 0){
            node = new Node<int>;
            node->setInfo(num);
            ll2->InserirFinal(node);
        }
	}

    while(!ll1->isEmpty() || !ll2->isEmpty()){
        if(!ll1->isEmpty())
            num = ll1->RemoverInicio()->getInfo();
        else
            num = -1;

        node = new Node<int>;
		node->setInfo(num);
        ll3->InserirFinal(node);

        if(!ll2->isEmpty())
            num = ll2->RemoverInicio()->getInfo();
        else
            num = -1;

        node = new Node<int>;
		node->setInfo(num);
        ll3->InserirFinal(node);
    }

    while(!ll3->isEmpty())
	{
		num = ll3->RemoverInicio()->getInfo();
		cout << num <<"\n";
	}
    return 0;
}
