
#include <iostream>
#include <conio.h>

using std::cout;
using std::cin;

#include "EnteroGrande.h"

int main()
{

	cout << "*** SOBRECARGA DE OPERADORES : ENTEROGRANDE ***\n\n";

	EnteroGrande n1;
	EnteroGrande n2;

	cout << "Ingrese numero 1: ";
	cin >> n1;
	cout << "Ingrese numero 2: ";
	cin >> n2;



	EnteroGrande n3 = n1 + n2;
	cout << "El resultado de la suma es: " << n3 << std::endl;


	if (n1 > n2) {
		cout << "Si funca prros";
	}

	getch();

}