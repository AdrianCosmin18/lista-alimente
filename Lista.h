#include"MyList.h"

class Lista:public MyList
{
private:

	Node* head = NULL;

public:

	Node* get_last_node() {

		Node* itr = head;
		Node* aux = itr;
		aux = head;
		while (itr != NULL) {

			aux = itr;
			itr = itr->get_next();
		}
		return aux;
	}

	void add(Aliment* a) {

		if (head == NULL) {

			head = new Node();
			head->set_aliment(a);
			head->set_next(NULL);
		}
		else {

			Node* n = new Node();
			n->set_aliment(a);

			Node* prev = new Node();
			prev = get_last_node();

			prev->set_next(n);
		}
	}

	void traverse() {

		Node* itr = head;

		while (itr != NULL) {

			cout << *(itr->get_aliment())<<endl;
			itr = itr->get_next();
		}

	}

	int indexOf(Aliment* a) {

		int poz = -1;
		Node* itr = head;
		while (itr != NULL) { 
			
			poz++;
			if (itr->get_aliment()->operator==(*a)) { return poz; }
		
			itr = itr->get_next();
		}
		return -1;
	}

	int indexOf(string firma, string nume, double greutate) {

		int poz = -1;
		Node* itr = head;
		while (itr != NULL) {

			poz++;
			if (itr->get_aliment()->get_firma() == firma &&
				itr->get_aliment()->get_nume() == nume &&
				itr->get_aliment()->get_greutate() == greutate) {

				return poz;
			}
			itr = itr->get_next();
		}

		return -1;
	}

	Node* poz_nod(int p) {

		Node* itr = head;
		int poz = -1;

		while (itr != NULL) {

			poz++;
			if (poz == p) { return itr; }
			itr = itr->get_next();
		}
		return NULL;
	}

	void remove_first() {

		Node* aux = new Node();
		head = head->get_next();
		delete aux;
	}

	void remove(int index) {

		Node* node = poz_nod(index);
		Node* prev_node = poz_nod(index - 1);
		prev_node->set_next(node->get_next());
	}

	void remove(Aliment* a) {

		int poz = indexOf(a);
		Node* node = poz_nod(poz);
		Node* prev_node = poz_nod(poz - 1);
		prev_node->set_next(node->get_next());
	}

	bool contains(Aliment* a) {

		Node* node = head;

		while(node != NULL) {

			if (node->get_aliment()->operator==(*a)) { return true; }
			node = node->get_next();
		}
		return false;
	}

	bool isEmpty() {

		Node* node = head;
		if (head == NULL) { return true; }
		return false;
	}

	int size() {

		int size = 0;
		Node* node = head;

		while (node != NULL) {

			size++;
			node = node->get_next();
		}
		return size;
	}

	Aliment* get(int index) {

		Node* node = poz_nod(index);

		if(node != NULL){ return node->get_aliment(); }
		return NULL;
	}

	void replace(Aliment* a, int index) {

		Node* node = poz_nod(index);
		node->set_aliment(a);
	}

	void swap(Node* n1, Node* n2) {

		int pozitie1 = indexOf(n1->get_aliment());
		int pozitie2 = indexOf(n2->get_aliment());

		replace(n1->get_aliment(), pozitie2);
		replace(n2->get_aliment(), pozitie1);
	}

	void sort() {

		int flag = 0;
		do {
			flag = 0;

			for (int i = 0; i < size() - 1; i++) {

				if (get(i + 1)->operator< (*get(i)))
				{
					Aliment* a = get(i);
					replace(get(i + 1), i);
					replace(a, i + 1);
					flag = 1;
				}
			}
		} while (flag == 1);
	}

	Node* first() { return this->head; }

};

