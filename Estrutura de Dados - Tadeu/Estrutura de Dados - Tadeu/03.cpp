#include <iostream>

using namespace std;

class No
{
private:
	int v;
	No* prox;
public:
	No(int v)
	{
		this->v = v;
		this->prox = NULL;
	}

	int obterValor()
	{
		return v;
	}

	No* obterProx()
	{
		return prox;
	}

	void setProx(No* p)
	{
		prox = p;
	}

	void setValue(int p)
	{
		v = p;
	}
};

class Lista
{
private:
	No* cabeca;
	No* cauda;
public:
	Lista()
	{
		cabeca = NULL;
		cauda = NULL;
	}

	Lista(int v)
	{
		cabeca = new No(v);
		cauda = cabeca;
	}

	virtual ~Lista()
	{
		delete cabeca;
	}

	void mostrar()
	{
		cout << "\nImprimindo todos os elementos...\n";
		No* c = cabeca;

		if(vazia())
			cout << "A lista NAO possui elementos!!\n";
		else
		{
			while(c)
			{
				cout << c->obterValor() << endl;
				c = c->obterProx();
			}
			cout << endl;
		}
	}

	void ordemCrescente(int p) {

        No* c = cabeca;

        No* b = c;

        int aux;


        for(int i = 0;i < p;i++){


            for(int j = 0;j < p;j++){

                if(c->obterValor() < b->obterValor()){

                    aux = c->obterValor();
                    c->setValue(b->obterValor());
                    b->setValue(aux);

                }

                b = b->obterProx();

            }

            b = cabeca;

            c = c->obterProx();

        }

    }

	int obter(int n)
	{
		No* c = cabeca;

		if(vazia())
			cout << "A lista NAO possui elementos!!\n";
		else
		{
		    if(n > 1){

                for(int i = 0;i + 1 < n;i++){

                    c = c->obterProx();

                }

		    }
            return c->obterValor();
		}
	}

	bool vazia()
	{
		return (cabeca == NULL);
	}

	void inserir_final(int v)
	{
		No* novo_no = new No(v);

		if(vazia())
		{
			cabeca = novo_no;
			cauda = novo_no;
		}
		else
		{
			cauda->setProx(novo_no);
			cauda = novo_no;
		}
	}

	int tamanho()
	{
		if(vazia())
			return 0;

		No* c = cabeca;
		int tam = 0;

		do
		{
			c = c->obterProx();
			tam++;
		}
		while(c);

		return tam;
	}

};

int main(int argc, char *argv[])
{
	Lista l1, l2, l3;
	bool c;
    int n, ql1, ql2, ql3;

    cout << "Lista 1" << endl;

    do{
            cout << "Escreva um numero: ";
            cin >> n;
            c = n >= 0;
            if(c){
                l1.inserir_final(n);
            }
            cout << endl;

	}while(c);

    ql1 = l1.tamanho();

    l1.ordemCrescente(ql1);

    cout << "Lista 2" << endl;

	do{
            cout << "Escreva um numero: ";
            cin >> n;
            c = n >= 0;
            if(c){
                l2.inserir_final(n);
            }
            cout << endl;

	}while(c);

	ql2 = l2.tamanho();

    l2.ordemCrescente(ql2);

    if(ql1 < ql2){
        for(int i = 1;i <= ql2;i++){
            if(i <= ql1){
                l3.inserir_final(l1.obter(i));
            }
            l3.inserir_final(l2.obter(i));

        }
    }

    else if(ql2 < ql1){
        for(int i = 1;i <= ql1;i++){
            l3.inserir_final(l1.obter(i));
            if(i <= ql2){
                l3.inserir_final(l2.obter(i));
            }
        }
    }

    else{

        for(int i = 1;i <= ql1;i++){
            l3.inserir_final(l1.obter(i));
            l3.inserir_final(l2.obter(i));
        }

    }

    ql3 = l3.tamanho();
    l3.ordemCrescente(ql3);

    l3.mostrar();


	return 0;
}
