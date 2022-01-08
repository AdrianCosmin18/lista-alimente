#include"Aliment.h"

class Node
{
private:
	Aliment* a;
	Node* next;

public:

	Aliment* get_aliment() { return a; }
	Node* get_next() { return next; }

	void set_aliment(Aliment* al) { a = al; }
	void set_next(Node* n) { next = n; }
};

