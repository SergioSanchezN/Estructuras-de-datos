// SergioAndresSanchezNiñoPila.cpp: archivo de proyecto principal.
#include "stdafx.h"
#include "iostream"

using namespace System;
using namespace std;

struct nodo
{
	int dato;
	nodo *sig;
};

class pila
{
private:
	nodo *tope;
public:
	pila();
	char meter(int valor);
	char sacar(int &valor);
	~pila();
	void limpiarPila();
	int cimaPila();
	int longitudPila();
	void desplegarPila();
};

pila::pila()
{
	tope = NULL;
}

pila::~pila()
{
	nodo *apunt;
	apunt = tope;
	while (tope != NULL)
	{
		tope = apunt->sig;
		delete apunt;
		apunt = tope;
	}
}

void pila::limpiarPila()
{
	nodo *apunt;
	apunt = tope;
	while (tope != NULL)
	{
		tope = apunt->sig;
		delete apunt;
		apunt = tope;
	}
}

int pila::cimaPila()
{
	if (tope != NULL)
	{
		return tope->dato;
	}
	else
	{
		return 11111;
	}
}

int pila::longitudPila()
{
	nodo *apunt;
	int num;
	if (tope != NULL)
	{
		apunt = tope;
		num = 0;
		while (apunt != NULL)
		{
			apunt = apunt->sig;
			num = num + 1;
		}
		return num;
	}
	else
	{
		return 0;
	}
}

void pila::desplegarPila()
{
	nodo *apunt;
	apunt = tope;
	cout << "_______________________________" << endl;
	while (apunt != NULL)
	{
		cout << apunt->dato << "  ";
		apunt = apunt->sig;
	}
	cout << endl;
	cout << "_______________________________" << endl << endl;
}

char pila::meter(int valor)
{
	nodo *nuevo;
	nuevo = new nodo;
	if (nuevo == NULL) return 0;
	else
	{
		nuevo->dato = valor;
		nuevo->sig = tope;
		tope = nuevo;
		return 1;
	}
}

char pila::sacar(int &valor)
{
	nodo *apunt;
	apunt = tope;
	if (apunt == NULL) return 0;
	else
	{
		valor = apunt->dato;
		tope = tope->sig;
		delete apunt;
		return 1;
	}
}

void main()
{
	pila p;
	int opc, valor;
	char resp;
	do {
		cout << "[===========================]" << endl;
		cout << "[  1. Meter nodo            ]" << endl;
		cout << "[  2. Sacar nodo            ]" << endl;
		cout << "[  3. Limpiar pila          ]" << endl;
		cout << "[  4. Cima pila             ]" << endl;
		cout << "[  5. Longitud de pila      ]" << endl;
		cout << "[  6. Desplegar pila        ]" << endl;
		cout << "[  7. Salir                 ]" << endl;
		cout << "[===========================]" << endl;
		cin >> opc;
		switch (opc)
		{
		case 1:
			do
			{
				cout << "Entre el elemento a agregar a la pila" << endl;
				cin >> valor;
				p.meter(valor);
				cout << "Desea Agregar otro dato a la pila? (s/n)" << endl;
				cin >> resp;
				resp = tolower(resp);
			} while (resp == 's');
			break;
		case 2:
			cout << "Desea sacar un elemnto de la pila? (s/n)" << endl;
			cin >> resp;
			resp = tolower(resp);
			if (resp == 's')
			{
				do
				{
					if (p.sacar(valor))
					{
						cout << "El nodo extraido es " << valor << endl;
						cout << "desea sacar otro elemnto de la pila ? (s/n)" << endl;
						cin >> resp;
						resp = tolower(resp);
					}
					else
					{
						cout << "_____________________________" << endl;
						cout << "|    La pila esta vacia     |" << endl;
						cout << "[___________________________]" << endl << endl;
						break;
					}
				} while (resp == 's');
			}
			break;
		case 3:
			p.limpiarPila();
			break;
		case 4:
			int cima;
			cima = p.cimaPila();
			if (cima != 11111)
			{
				cout << "____________________________________" << endl;
				cout << "la cima de pila es: " << p.cimaPila() << endl;
				cout << "____________________________________" << endl << endl;
			}
			else
			{
				cout << "____________________________" << endl;
				cout << "|    La pila esta vacia     |" << endl;
				cout << "[___________________________]" << endl << endl;
			}
			break;
		case 5:
			int lon;
			lon = p.longitudPila();
			if (lon != 0)
			{
				cout << "______________________________________" << endl;
				cout << "la pila tiene " << lon << " nodos" << endl;
				cout << "______________________________________" << endl << endl;
			}
			else
			{
				cout << "_____________________________" << endl;
				cout << "|    La pila esta vacia     |" << endl;
				cout << "[___________________________]" << endl << endl;
			}
			break;
		case 6:
			lon = p.longitudPila();
			if (lon != 0)
			{
				p.desplegarPila();
			}
			else
			{
				cout << "_____________________________" << endl;
				cout << "|    La pila esta vacia     |" << endl;
				cout << "[___________________________]" << endl << endl;
			}
			break;
		}
		if (opc < 1 || opc>7)
		{
			cout << "_____________________________" << endl;
			cout << "|   Opcion no encontrada    |" << endl;
			cout << "[___________________________]" << endl << endl;
		}
	} while (opc != 7);
}
