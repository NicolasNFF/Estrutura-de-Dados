#include <iostream>
#include "ListaLinear.h"

using namespace std;

int main()
{
	ListaLinear<char> * ll1 = new ListaLinear<char>();
	ListaLinear<char> * ll2 = new ListaLinear<char>();
	Node<char> * node = NULL;
	Node<char> * nodeAux = NULL;
	char letter;
	int matches=0,aux=0,i=0;

	while(letter != '0')
	{
		cin >> letter;

		if(letter != '0'){
			node = new Node<char>;
			node->setInfo(letter);
			ll1->InserirInicio(node);
		}
	}

	letter = '*';

	while(letter != '0')
	{
		cin >> letter;

		if(letter != '0'){
			node = new Node<char>;
			node->setInfo(letter);
			ll2->InserirInicio(node);
		}
	}

	node = ll1->getHead();
	nodeAux = ll2->getHead();
	while(ll2->getSize() - aux)
	{
	    i=0;
        while(true){
            if(i == ll1->getSize()){
                node = ll1->getHead();
                i = 0;
                break;
            }
            if(node->getInfo() != nodeAux->getInfo()){
                node = ll1->getHead();
                if(nodeAux->getNext())
                    nodeAux = nodeAux->getNext();
                break;
            }
            else{
                i++;
                if(node->getNext()){
                    node = node->getNext();
                }
                if(nodeAux->getNext())
                    nodeAux = nodeAux->getNext();
                if(i == ll1->getSize())
                    matches++;
            }
        }
        aux++;
	}
    cout << matches << "\n";
    return 0;
}
