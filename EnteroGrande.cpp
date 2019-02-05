
#include "EnteroGrande.h"
#include <iostream>
#include <string>

EnteroGrande::EnteroGrande()
{
	cNumero = new char[LONGITUD];
	iNumero = new int[LONGITUD];

	for(int i = 0; i < LONGITUD; i++)
	{
		cNumero[i] = 'a';
		iNumero[i] = 0;
	}
}

std::istream& operator>>(std::istream &in, EnteroGrande &numero)

{
	in >> numero.cNumero;

	int longitud = LONGITUD - 1;

	for(int i = strlen(numero.cNumero) - 1 ; i >= 0; i--)
	{
		switch(numero.cNumero[i])
		{
			case '0':
			numero.iNumero[longitud] = 0;
			break;
			case '1':
			numero.iNumero[longitud] = 1;
			break;
			case '2':
			numero.iNumero[longitud] = 2;
			break;
			case '3':
			numero.iNumero[longitud] = 3;
			break;
			case '4':
			numero.iNumero[longitud] = 4;
			break;
			case '5':
			numero.iNumero[longitud] = 5;
			break;
			case '6':
			numero.iNumero[longitud] = 6;
			break;
			case '7':
			numero.iNumero[longitud] = 7;
			break;
			case '8':
			numero.iNumero[longitud] = 8;
			break;
			case '9':
			numero.iNumero[longitud] = 9;
			break;
		}//fin switch

		longitud--;
	}//fin for

	return in;
}

std::ostream& operator<<(std::ostream &out, const EnteroGrande &numero)
{
	for(int i = 0; i < strlen(numero.cNumero); i++)
	{
		out << numero.iNumero[LONGITUD - strlen(numero.cNumero) + i];

	}

	return out;
}

EnteroGrande& operator+(const EnteroGrande &n1, const EnteroGrande &n2)
{
	EnteroGrande resultado;
	std::string cNumero = "";

	int nLongitud = 0;
	int acarreo = 0;

	//identificar el numero mas largo
	nLongitud = strlen(n1.cNumero) > strlen(n2.cNumero) ? strlen(n1.cNumero) : strlen(n2.cNumero);

	//iterador por cada digito
	for(int i = 0; i < nLongitud; i++)
	{
		//ubicarse en la posicion indica en el arreglo y sumar
		int rSuma = n1.iNumero[LONGITUD - 1 - i] + n2.iNumero[LONGITUD - 1 - i] + acarreo;
		int valor = 0;

		if(rSuma > 9)
		{
			valor = rSuma - 10;
			acarreo = 1;
		}
		else
		{
			valor = rSuma;
			acarreo = 0;
		}

		resultado.iNumero[LONGITUD - 1 - i] = valor;
		//concatenar en un string cada numero
		cNumero = std::to_string(valor) + cNumero;
	}

	if(acarreo == 1)
	{
		resultado.iNumero[LONGITUD - 1 - nLongitud] = 1;
		cNumero = std::to_string(1) + cNumero;
	}

	//copiar toda la cadena como char * en resultado
	strcpy(resultado.cNumero, cNumero.c_str());
	return resultado;

}

bool &EnteroGrande::operator<(const EnteroGrande & numero)
{
	 bool h = false;

	if (strlen(this->cNumero)>strlen(numero.cNumero)) {

		h = false;
		return h;
		
	}
	else if (strlen(this->cNumero) < strlen(numero.cNumero))
	{
		h = true;
		return h;
	}
	else
	{
		for (int i = LONGITUD - strlen(numero.cNumero); i < LONGITUD; i++)
		{
			if (this->iNumero[i] > numero.iNumero[i])
			{
				h = false;
				return h;
			
			}
			else if (this->iNumero[i] < numero.iNumero[i])
			{
				h = true;
				return h;
			}
		}
	}

	return h;
}

EnteroGrande& operator-(const EnteroGrande &n1, const EnteroGrande &n2)
{
	EnteroGrande resultado;
	std::string cNumero = "";

	int nLongitud = 0;
	int acarreo = 0;

	//identificar el numero mas largo
	nLongitud = strlen(n1.cNumero) > strlen(n2.cNumero) ? strlen(n1.cNumero) : strlen(n2.cNumero);

	//iterador por cada digito
	for (int i = 0; i < nLongitud; i++)
	{
		//ubicarse en la posicion indica en el arreglo y sumar
		int rSuma = n1.iNumero[LONGITUD - 1 - i] + n2.iNumero[LONGITUD - 1 - i] + acarreo;
		int valor = 0;

		if (rSuma > 9)
		{
			valor = rSuma - 10;
			acarreo = 1;
		}
		else
		{
			valor = rSuma;
			acarreo = 0;
		}

		resultado.iNumero[LONGITUD - 1 - i] = valor;
		//concatenar en un string cada numero
		cNumero = std::to_string(valor) + cNumero;
	}

	if (acarreo == 1)
	{
		resultado.iNumero[LONGITUD - 1 - nLongitud] = 1;
		cNumero = std::to_string(1) + cNumero;
	}

	//copiar toda la cadena como char * en resultado
	strcpy(resultado.cNumero, cNumero.c_str());
	return resultado;

}

bool &EnteroGrande::operator>(const EnteroGrande & numero)
{

	bool h = false;

	if (strlen(this->cNumero) > strlen(numero.cNumero)) {
		h = true;
		return h;
	}
	else if (strlen(this->cNumero) < strlen(numero.cNumero))
	{
		h = false;
		return h;
	}
	else
	{
		for (int i = LONGITUD - strlen(numero.cNumero); i < LONGITUD; i++)
		{
			if (this->iNumero[i] > numero.iNumero[i])
			{
				h = true;
				return h;
			}
			else if (this->iNumero[i] < numero.iNumero[i])
			{
				h = false;
				return h;
			}
		}
	}

	return h;
}

bool &EnteroGrande::operator>=(const EnteroGrande & numero)
{

	bool h = true;

	if (strlen(this->cNumero) > strlen(numero.cNumero)) {
		h = true;
		return h;
	}
	else if (strlen(this->cNumero) < strlen(numero.cNumero))
	{
		h = false;
		return h;
	}
	else
	{
		for (int i = LONGITUD - strlen(numero.cNumero); i < LONGITUD; i++)
		{
			if (this->iNumero[i] > numero.iNumero[i])
			{
				h = true;
				return h;
			}
			else if (this->iNumero[i] < numero.iNumero[i])
			{
				h = false;
				return h;
			}
		}
	}

	return h;
}

bool &EnteroGrande::operator<=(const EnteroGrande & numero)
{
	bool h = false;
	if (strlen(this->cNumero) < strlen(numero.cNumero))
	{
		h = true;
		return h;
	}

	if (strlen(this->cNumero) > strlen(numero.cNumero))
	{
		h = false;
		return h;
	}
	else
	{
		for (int i = LONGITUD - strlen(numero.cNumero); i < LONGITUD; i++)
		{
			if (this->iNumero[i] < numero.iNumero[i])
			{
				h = true;
				return h;
			}
			else if (this->iNumero[i] > numero.iNumero[i])
			{
				h = false;
				return h;
			}
		}

	}

	h = true;
	return h;

}

EnteroGrande &EnteroGrande::operator-=(const EnteroGrande s)
{
	EnteroGrande respuesta = *this - s;

	return respuesta;
}

bool &EnteroGrande::operator==(const EnteroGrande & numero)
{
	bool h = false;
	if (strlen(this->cNumero) == strlen(numero.cNumero))
	{
		h = true;
		return h;
	}

	if (strlen(this->cNumero) == strlen(numero.cNumero))
	{
		h = false;
		return h;
	}
	else
	{
		for (int i = LONGITUD - strlen(numero.cNumero); i < LONGITUD; i++)
		{
			if (this->iNumero[i] < numero.iNumero[i])
			{
				h = true;
				return h;
			}
			else if (this->iNumero[i] > numero.iNumero[i])
			{
				h = false;
				return h;
			}
		}

	}

	h = true;
	return h;

}

bool &EnteroGrande::operator++()
{
	bool h=true;
	if (strlen(this->cNumero) > 2) {

		h = false;
		return h;

	}
	else if (strlen(this->cNumero) < 3)
	{
		h = true;
		return h;
	}
	else
	{
		for (int i = LONGITUD - 1; i < LONGITUD; i++)
		{
			if (this->iNumero[i] > 8)
			{
				h = false;
				return h;

			}
			else if (this->iNumero[i] < 5)
			{
				h = true;
				return h;
			}
		}
	}

	return h;
}
	


bool EnteroGrande::operator++(int a)
{
	bool h = true;
	if (strlen(this->cNumero) > 2) {

		h = false;
		return h;

	}
	else if (strlen(this->cNumero) < 3)
	{
		h = true;
		return h;
	}
	else
	{
		for (int i = LONGITUD - 1; i < LONGITUD; i++)
		{
			if (this->iNumero[i] > 8)
			{
				h = false;
				return h;

			}
			else if (this->iNumero[i] < 5)
			{
				h = true;
				return h;
			}
		}
	}

	return h;


}

EnteroGrande &EnteroGrande::operator+=(const EnteroGrande s)
{
	EnteroGrande respuesta = *this + s;

	return respuesta;
}

