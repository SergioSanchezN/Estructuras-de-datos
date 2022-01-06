// Agrega_Clase_ListaDEC.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include "iostream"

using namespace System;
using namespace std;

struct nodo
{
	int dato;
	nodo *ant;
	nodo *sig;
};

class Lsec
{
private:
	nodo *inicial;
	nodo *buscarLista(int clave);
	nodo *buscarUltimo();
public:
	Lsec();
	~Lsec();
	void agregar();
	void eliminarNodo();
	void desplegarLista();
	void desplegarAntiH();

};

Lsec::Lsec()
{
	inicial = NULL;
}



Lsec::~Lsec()
{
	nodo *apun, *eliminar;
	apun = inicial;
	apun->ant->sig = NULL;
	while (apun->sig != NULL)
	{
		eliminar = apun;
		apun = apun->sig;
		delete eliminar;
	}
	inicial = NULL;
}

nodo *Lsec::buscarUltimo()
{
	nodo *ultimo;
	
	if (inicial != NULL) {
		ultimo = inicial->ant;
		return ultimo;
	}
	else
	{
		return NULL;
	}
}

void Lsec::desplegarAntiH()
{
	nodo *apunt;
	if (inicial == NULL)
	{
		cout << "    La lista esta vacia" << endl;
	}
	else
	{
		apunt = buscarUltimo();
		do
		{
			cout << apunt->dato << "  ";
			apunt = apunt->ant;
		} while (apunt->sig != inicial);
	}
	cout << endl;
}


nodo *Lsec::buscarLista(int clave)
{
	nodo *anterior;
	anterior = NULL;
	if (clave <= inicial->dato)return anterior;
	else
	{
		anterior = inicial;
		while ((clave > anterior->sig->dato) && (anterior->sig != inicial))
			anterior = anterior->sig;
		return anterior;
	}
}

void Lsec::agregar()
{
	nodo *nuevo, *anterior;
	char resp;
	do
	{
		nuevo = new nodo();
		cout << "Entre la clave del nodo a agregar" << endl;
		cin >> nuevo->dato;
		if (inicial == NULL)
		{
			inicial = nuevo;
			nuevo->ant = nuevo;
			nuevo->sig = nuevo;
		}
		else
		{
			anterior = buscarLista(nuevo->dato);

			if (anterior == NULL)
			{
				if (inicial->dato != nuevo->dato)
				{
					inicial->ant->sig = nuevo;
					nuevo->ant = inicial->ant;
					nuevo->sig = inicial;
					inicial->ant = nuevo;
					inicial = nuevo;
				}
				else
				{
					cout << "_____________________________" << endl;
					cout << "[    El dato ingrasado ya   ]" << endl;
					cout << "[     existe en la lista    ]" << endl;
					cout << "[___________________________]" << endl << endl;
				}
			}
			else
			{
				if (nuevo->dato != anterior->sig->dato)
				{
					anterior->sig->ant = nuevo;
					nuevo->sig = anterior->sig;
					nuevo->ant = anterior;
					anterior->sig = nuevo;
				}
				else
				{
					cout << "_____________________________" << endl;
					cout << "[    El dato ingresado ya   ]" << endl;
					cout << "[     existe en la lista    ]" << endl;
					cout << "[___________________________]" << endl << endl;
				}
			}
		}
		cout << "Desea agregar otro nodo? (s/n)" << endl;
		cin >> resp;
		resp = tolower(resp);
	} while (resp == 's');
}

void Lsec::desplegarLista()
{
	cout << "_________________________________________________" << endl;
	int respuesta;

	nodo *apunt;

	if (inicial == NULL)
	{
		cout << "    La lista esta vacia" << endl;
	}
	else
	{
		cout << "Digite  1: para desplegar en sentido horario" << endl;
		cout << "        2: para desplegar en sentido anti horario" << endl;
		cout << "_________________________________________________" << endl;
		cin >> respuesta;
		if (respuesta == 1)
		{
			apunt = inicial;
			do
			{
				cout << apunt->dato << "  ";
				apunt = apunt->sig;
			} while (apunt != inicial);
		}
		else
		{
			apunt = inicial->ant;
			do
			{
				cout << apunt->dato << "  ";
				apunt = apunt->ant;
			} while (apunt->sig != inicial);
		}

	}
	cout << endl;
	cout << "_________________________________________________" << endl;
}


void Lsec::eliminarNodo()
{
	if (inicial != NULL)
	{
		nodo *eliminar, *apunt;
		int clave;

		cout << "Dijite la clave del nodo que desea eliminar" << endl;
		cin >> clave;

		apunt = buscarLista(clave);
		if (clave == inicial->dato)
		{
			if (inicial->sig == inicial)
			{
				eliminar = inicial;
				inicial = NULL;
				delete eliminar;
			}
			else
			{
				eliminar = inicial;
				inicial->sig->ant = inicial->ant;
				inicial->ant->sig = inicial->sig;
				inicial = inicial->sig;
				delete eliminar;
			}
		}
		else if (apunt != NULL)
		{
			if (clave == apunt->sig->dato)
			{
				eliminar = apunt->sig;
				eliminar->sig->ant = apunt;
				apunt->sig = eliminar->sig;
				delete eliminar;
			}
		}
		else
		{
			cout << "_____________________________" << endl;
			cout << "| El codigo no se encuentra |" << endl;
			cout << "| en la lista               |" << endl;
			cout << "[___________________________]" << endl << endl;
		}
	}
	else
	{
		cout << "_____________________________" << endl;
		cout << "|    la lista esta vacia    |" << endl;
		cout << "[___________________________]" << endl << endl;
	}
}


void main()
{
	Lsec l;
	int opc;
	do
	{
		cout << "[=============================]" << endl;
		cout << "[  1. Agregar Nodo            ]" << endl;
		cout << "[  2. Borrar Nodo             ]" << endl;
		cout << "[  3. Desplegar lista         ]" << endl;
		cout << "[  4. Desplegar lista anti H  ]" << endl;
		cout << "[  5. Borrar lista            ]" << endl;
		cout << "[  6. salir                   ]" << endl;
		cout << "[=============================]" << endl;
		cin >> opc;
		switch (opc)
		{
		case 1:
			l.agregar();
			break;
		case 2:
			l.eliminarNodo();
			break;
		case 3:
			l.desplegarLista();
			break;
		case 4:
			l.desplegarAntiH();
			break;
		case 5:
			l.~Lsec();
			cout << "_____________________________" << endl;
			cout << "| La lista ha sido borrada  |" << endl;
			cout << "[___________________________]" << endl << endl;
			break;
		}
		if (opc < 1 || opc>6)
		{
			cout << "_____________________________" << endl;
			cout << "|   Opcion no encontrada    |" << endl;
			cout << "[___________________________]" << endl << endl;
		}
	} while (opc != 6);

	system("pause");
}
