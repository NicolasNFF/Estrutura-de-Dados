#ifndef NODE_H
#define NODE_H

template <class TInfo>
class Node
{
private:

protected:
	// atributos
	TInfo info;
	Node * next; // próximo nó
	Node * prev; // nó anterior
public:
	// métodos construtores
	Node();
	Node(Node &node); // método de clonagem
	// métodos destrutores
	~Node();
	// métodos -> operações da classe
	// métodos setter e getter
	// setter -> métodos para atribuir valores aos atributos
	void setInfo(TInfo); 		// setter do atributo info
	TInfo getInfo(); 			// getter do atrib. info
	void setNext(Node *); 	// setter do atributo next
	Node * getNext(); 		// getter do atrib. next
	void setPrev(Node *); 	// setter do atributo prev
	Node * getPrev(); 		// getter do atrib. prev
};

#endif // NODE_H
