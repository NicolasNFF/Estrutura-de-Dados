
/*
Declaração de Constantes
*/


#define True 1
#define False 0

/*
Apelido para o tipo do int
*/

typedef int boolean;

/*
Funções
*/

void swap(int vetor[], int x, int y)
{
    int aux = vetor[x];
    vetor[x]= vetor[y];
    vetor[y]= aux;
}

/*
BubbleSort
*/


void BubbleSort(int vetor[], int size)
{
    int indx;
    boolean trocou = True;

    while(trocou == True)
    {
        trocou = False;
        for(indx=0; indx < size;indx++)
        {
            if (vetor[indx] > vetor[indx+1])
            {
                swap(vetor, indx, indx+1);
                trocou = True;
            }
        }
    }
}
