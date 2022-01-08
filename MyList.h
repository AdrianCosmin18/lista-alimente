#include"Node.h"

class MyList
{
public:

	virtual void add(Aliment* m) = 0;

	virtual void remove(int index) = 0;

	virtual void remove(Aliment* m) = 0;

	virtual bool contains(Aliment* m) = 0;

	virtual bool isEmpty() = 0;

	virtual int indexOf(Aliment* m) = 0;

	virtual int size() = 0;

	virtual Aliment* get(int index) = 0;
};

