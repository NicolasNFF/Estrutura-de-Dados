#ifndef NODE_H
#define NODE_H

template <class TInfo>
class Node
{
private:

protected:
	// atributos
	TInfo info;
	Node * next; // pr�ximo n�
	Node * prev; // n� anterior
public:
	// m�todos construtores
	Node();
	Node(Node &node); // m�todo de clonagem
	// m�todos destrutores
	~Node();
	// m�todos -> opera��es da classe
	// m�todos setter e getter
	// setter -> m�todos para atribuir valores aos atributos
	void setInfo(TInfo); 		// setter do atributo info
	TInfo getInfo(); 			// getter do atrib. info
	void setNext(Node *); 	// setter do atributo next
	Node * getNext(); 		// getter do atrib. next
	void setPrev(Node *); 	// setter do atributo prev
	Node * getPrev(); 		// getter do atrib. prev
};

#endif // NODE_H
