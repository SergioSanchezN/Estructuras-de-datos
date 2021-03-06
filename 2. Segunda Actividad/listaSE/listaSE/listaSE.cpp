#include "stdafx.h"
#include <iostream>

using namespace System;
using namespace std;

struct nodo {
	int dato;
	nodo *sig;
};

class Lse {
private:
	nodo *inicial;
	nodo *buscarLista(int clave);
public:
	Lse();
	~Lse();
	void agregar();
	void eliminarNodo(int clave);
	void eliminar();
	void desplegarLista();
};
Lse::Lse() {
	inicial = NULL;
}
Lse::~Lse()
{
	nodo *eliminar;
	eliminar = inicial;
	while (eliminar != NULL)
	{
		inicial = eliminar->sig;
		delete eliminar;
		eliminar = inicial;
	}
}

void Lse::desplegarLista() {
	cout << "______________________________" << endl;
	cout << "Lista:" << endl;
	if (inicial == NULL) {
		cout << "La lista esta vacia" << endl;
	}
	else {
		nodo *apun;
		apun = inicial;
		while (apun != NULL) {
			cout << "       "<<apun->dato << endl;
			apun = apun->sig;
		}
	}
	cout << "______________________________" << endl;
	cout << "" << endl;
}
nodo *Lse::buscarLista(int clave) {
	nodo *anterior;
	anterior = NULL;
	if (clave <= inicial->dato)return anterior;
	else {
		anterior = inicial;
		while ((anterior->sig != NULL) && (clave > anterior->sig->dato))anterior = anterior->sig;
		return anterior;
	}
}
void Lse::eliminarNodo(int clave)
{
	nodo *apunt, *elimina;
	
		apunt = buscarLista(clave);
		elimina = apunt->sig;
		apunt->sig = elimina->sig;
		delete elimina;
}
void Lse::agregar() {
	nodo *nuevo, *anterior;
	int clave1;
	bool repetido;
	char resp;

	do {
		nuevo = new nodo();
		do
		{	
			cout << "Ingrese la clave del nodo a agregar" << endl;
			cin >> clave1;
			nodo *apunt;
			apunt = inicial;
			repetido = false;
			while ((apunt != NULL) && (repetido == false))
			{	
				if (clave1 == apunt->dato)
				{
					repetido = true;
				}
				apunt = apunt->sig;
			}
			if (repetido == true)
			{
				cout << "El nodo a agregar ya existe" << endl;
			}
			else
			{
				nuevo->dato = clave1;
			}
		} while (repetido == true);
		if (inicial == NULL) {
			inicial = nuevo;
			nuevo->sig = NULL;
		}
		else {
			anterior = buscarLista(nuevo->dato);
			if (anterior == NULL) {
				nuevo->sig = inicial;
				inicial = nuevo;
			}
			else {
				if (anterior->sig != NULL) {
					if (nuevo->dato == anterior->sig->dato) {
						cout << "El nodo a agregar ya existe" << endl;
					}
					else {
						nuevo->sig = anterior->sig;
						anterior->sig = nuevo;
					}
				}
				else 
				{
					
						/*if (nuevo->dato == anterior->dato)
						{
							cout << "El nodo a agregar ya existe" << endl;
						}
						else 
						{*/
							nuevo->sig = NULL;
							anterior->sig = nuevo;
						/*}*/
				}
			}
		}
//		cout << inicial->dato << endl;
		cout << "Desea agregar otro nodo? (s/n)" << endl;
		cin >> resp;
		resp = tolower(resp);
	} while (resp == 's');
}
int main() {
	int opc,borrar;
	Lse l;
	l.agregar();
	do
	{
		cout << "[============================]" << endl;
		cout << "[  1. Agragar nodos          ]" << endl;
		cout << "[  2. Borrar nodo            ]" << endl;
		cout << "[  3. Desplegar lista        ]" << endl;
		cout << "[  4. Salir                  ]" << endl;
		cout << "[============================]" << endl;
		cin >> opc;

		switch (opc)
		{
		case 1:
			l.agregar();
			break;
		case 2:
			cout << "Digite la clave del nodo que desea borrar" << endl;
			cin >> borrar;
			l.eliminarNodo(borrar);
			break;
		case 3:
			l.desplegarLista();
			break;
		}
		if (opc < 1 || opc>4)
		{
			cout << "opcion no encontrada" << endl;
		}
	} while (opc != 4);

	system("pause");
	//return 0;
}
