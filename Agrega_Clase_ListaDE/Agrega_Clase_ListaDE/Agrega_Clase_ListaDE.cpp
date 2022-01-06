// Agrega_Clase_ListaDE.cpp: archivo de proyecto principal.

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
public:
	Lsec();
	~Lsec();
	void agregar();
	void eliminarNodo();
	void desplegarLista();
	void desplegarListaInversa();
};

Lsec::Lsec()
{
	inicial = NULL;
}

Lsec::~Lsec()
{
	if (inicial != NULL)
	{
		nodo *apunt;
		apunt = inicial;

		while (apunt != NULL)
		{
			inicial = apunt->sig;
			delete apunt;
			apunt = inicial;
		}
	}
}


void Lsec::desplegarLista()
{
	cout << "_____________________________" << endl;
	nodo *apunt;
	if (inicial == NULL)
	{
		cout << "    La lista esta vacia" << endl;
	}
	else
	{
		apunt = inicial;
		do
		{
			cout << apunt->dato << "  ";
			apunt = apunt->sig;
		} while (apunt != NULL);
	}
	cout << endl;
	cout << "_____________________________" << endl << endl;
}

nodo *Lsec::buscarLista(int clave)
{
	nodo *anterior;
	anterior = NULL;
	if (clave <= inicial->dato)return anterior;
	else
	{
		anterior = inicial;
		while ((anterior->sig != NULL) && (clave > anterior->sig->dato))
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
			nuevo->ant = NULL;
			nuevo->sig = NULL;
		}
		else
		{
			anterior = buscarLista(nuevo->dato);

			if (anterior == NULL)
			{
				if (inicial->dato != nuevo->dato)
				{
					nuevo->sig = inicial;
					nuevo->ant = inicial->ant;
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
				if (anterior->sig != NULL)
				{
					if (nuevo->dato != anterior->sig->dato)
					{
						nuevo->sig = anterior->sig;
						nuevo->ant = anterior;
						anterior->sig->ant = nuevo;
						anterior->sig = nuevo;
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
					nuevo->sig = anterior->sig;
					nuevo->ant = anterior;
					anterior->sig = nuevo;
				}


			}
		}
		cout << "Desea agregar otro nodo? (s/n)" << endl;
		cin >> resp;
		resp = tolower(resp);
	} while (resp == 's');
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
			if (inicial->sig == NULL)
			{
				eliminar = inicial;
				inicial = NULL;
				delete eliminar;
			}
			else
			{
				eliminar = inicial;
				inicial = inicial->sig;
				inicial->ant = eliminar->ant;
				delete eliminar;
			}
		}
		else if (apunt != NULL && clave == apunt->sig->dato)
		{
			eliminar = apunt->sig;
			apunt->sig = eliminar->sig;
			if (eliminar->sig != NULL)
			{
				eliminar->sig->ant = apunt;
			}
			delete eliminar;
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
		cout << "[===========================]" << endl;
		cout << "[  1. Agregar Nodo          ]" << endl;
		cout << "[  2. Borrar Nodo           ]" << endl;
		cout << "[  3. Desplegar lista       ]" << endl;
		cout << "[  4. Borrar lista          ]" << endl;
		cout << "[  5. salir                 ]" << endl;
		cout << "[===========================]" << endl;
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
			l.~Lsec();
			cout << "_____________________________" << endl;
			cout << "| La lista ha sido borrada  |" << endl;
			cout << "[___________________________]" << endl << endl;
			break;
		}
		if (opc < 1 || opc>5)
		{
			cout << "_____________________________" << endl;
			cout << "|   Opcion no encontrada    |" << endl;
			cout << "[___________________________]" << endl << endl;
		}
	} while (opc != 5);

	system("pause");
} 
