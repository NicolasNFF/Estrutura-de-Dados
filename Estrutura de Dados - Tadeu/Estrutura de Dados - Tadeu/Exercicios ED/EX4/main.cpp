#include <iostream>
#include "Classifier.h"

using namespace std;

int main(int argc, char *argv[])
{
    ListaLinear<int> * ll = new ListaLinear<int>();
    Node<int> * node = NULL;
    Classifier<int> * classifier = new Classifier<int>(1);
    int num;

    while (num >= 0)
    {
        cin >> num;
        if(num >= 0){
            node = new Node<int>;
            node->setInfo(num);
            ll->InserirFinal(node);
        }
    }

    classifier->Sort(ll);

    while(!ll->isEmpty())
	{
		num = ll->RemoverInicio()->getInfo();
		cout << num <<"\n";
	}

    delete ll;

    return 0;
}
