#include "ControlAliment.h"

int main() {

	/*Aliment* a1 = new Aliment("Vel Pitar", "Paine", 500, 7.99);
	Aliment* a2 = new Aliment("SUS,Lapte,1,6");
	cout << a2->operator<(*a1);*/

	/*Lista* l = new Lista();


	l->add(new Aliment("Vel Pitar,Paine,500,7"));
	l->add(new Aliment("Oke,Lapte,1,6"));
	l->add(new Aliment("Nutella,Ciocolata,700,14"));
	l->add(new Aliment("Nestea,Ceai de Piersici,1.5,6"));

	Aliment* a = new Aliment("Fanta,Suc de Portocale,2,5.5");

	l->sort();
	l->traverse();*/

	ControlAliment* cal = new ControlAliment();

	cout << *(cal->GetAlimentByFirmaAndNumeAndGreutate("Nestea","ceai de piersici", 1.5));

	//cal->traverse();
}