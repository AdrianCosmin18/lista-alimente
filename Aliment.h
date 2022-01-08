#include <iostream>
#include<string>
using namespace std;

class Aliment
{
private:

	string firma;
	string nume;
	double greutate;
	double pret;

public:

	string get_firma() { return firma; }
	string get_nume() { return nume; }
	double get_greutate() { return greutate; }
	double get_pret() { return pret; }

	void set_firma(string f) { firma = f; }
	void set_nume(string n) { nume = n; }
	void set_greutate(double g) { greutate = g; }
	void set_pret(double p) { pret = p; }

	Aliment():firma{"anonima"}, nume{"anonim"}, greutate{0}, pret{0}{}

	Aliment(string f, string n, double g, double p):firma{f}, nume{n}, greutate{g}, pret{p}{}

	Aliment(string prp) {

		string v[4];
		int poz = prp.find(',');
		int k = -1;
		while (poz != string::npos) {

			k++;
			v[k] = prp.substr(0, poz);
			prp.erase(0, poz + 1);
			poz = prp.find(',');
		}
		v[3] = prp;


		firma = v[0];
		nume = v[1];
		greutate = stod(v[2]);
		pret = stod(v[3]);
	}

	Aliment(const Aliment& a):firma{a.firma}, nume{a.nume}, greutate{a.greutate}, pret{a.pret}{}

	virtual string describe() {

		string text = "";
		text = "\nFirma : " + firma;
		text += "\nNume : " + nume;
		text += "\nGreutate : " + to_string(greutate);
		text += "\nPret : " + to_string(pret);
		text += "\n";

		return text;
	}

	//suprascriem operatorii de comparare
	bool operator< (Aliment a1) {

		return (this->pret < a1.pret);
	}


	bool operator== (Aliment a) {

		return (this->firma == a.firma && this->nume == a.nume && this->greutate == a.greutate && this->pret == a.pret);
	}

	friend ostream& operator<<(ostream& os, const Aliment& a) {


		string text = "";
		text = "\nFirma : " + a.firma;
		text += "\nNume : " + a.nume;
		text += "\nGreutate : " + to_string(a.greutate);
		text += "\nPret : " + to_string(a.pret);
		text += "\n";

		os << text;
		return os;
	}
	
};

