
#ifndef ENTEROGRANDE_H
#define ENTEROGRANDE_H

#include <iostream>

#define LONGITUD 50

class EnteroGrande
{
	friend std::istream& operator>>(std::istream &, EnteroGrande &);
	friend std::ostream& operator<<(std::ostream &, const EnteroGrande &);
	friend EnteroGrande& operator+(const EnteroGrande &, const EnteroGrande &);

	//Realizar implementacion de operador de resta
	friend EnteroGrande& operator-(const EnteroGrande &, const EnteroGrande &);
private:
	char *cNumero;
	int *iNumero;
public:
	EnteroGrande(void);

	//Realizar implementacion de siguientes operadores
	bool &operator<(const EnteroGrande &);
	bool &operator>(const EnteroGrande &);
	bool &operator<=(const EnteroGrande &);
	bool &operator>=(const EnteroGrande &);
	bool &operator==(const EnteroGrande &);
	bool &operator++(); //preincremento
	bool operator++(int); //posincremento
	EnteroGrande &operator+=(const EnteroGrande);
	EnteroGrande &operator-=(const EnteroGrande);
};

#endif
