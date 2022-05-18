#include "ListaLinear.h"

template <class TInfo>
class Classifier

{

public:

static const int _BUBBLE_SORT = 1;

static const int _SELECTION_SORT = 2;

static const int _INSERTION_SORT = 3;

Classifier(int method);

virtual ~Classifier();

Classifier(const Classifier& other);

void Sort(ListaLinear<TInfo> * LLE);

protected:

int method;

private:

    void BubleSort(ListaLinear<TInfo> * LLE);
    void SelectionSort(ListaLinear<TInfo> * LLE);
    void InsertionSort(ListaLinear<TInfo> * LLE);

};
