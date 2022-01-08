#include"Lista.h"
#include<fstream>

class ControlAliment
{
private:
	Lista* l;

public:

	ControlAliment() {
		l = new Lista();
		load();
	}

	void load() {

		ifstream f("alimente.txt");

		while (!f.eof()) {
			string a;
			getline(f, a);

			if (a != "") { l->add(new Aliment(a)); }
		}
	}

	void traverse() {

		Node* itr = l->first();

		while (itr != NULL) {
			
			cout << *(itr->get_aliment());
			itr = itr->get_next();
		}
	}

	void add_aliment(Aliment* a) { l->add(a); }

	void remove(string firma, string nume, double greutate) {

		int poz = l->indexOf(firma, nume, greutate);
		cout << poz << "pozitie de stergere";

		if (poz != -1 && poz == 0) { l->remove_first(); }
		else if (poz != -1) { l->remove(poz); }
		else { cout << "\nNu exista aceasta masina"; }
	}

	void modify(string firma, string nume, double greutate, double pret) {

		int index = l->indexOf(firma, nume, greutate);

		if (index != -1) {

			Aliment* a_nou = new Aliment(firma, nume, greutate, pret);
			l->replace(a_nou, index);
		}
		else { cout << "nu exista aceasta masina"; }

	}

	Aliment* GetAlimentByFirmaAndNumeAndGreutate(string firma, string nume, double greutate) {

		int index = l->indexOf(firma, nume, greutate);
		if (index != -1) {

			Aliment* a = l->get(index);
			return a;
		}
		else { cout << "Nu ex aceasta masina"; }
	}
};

