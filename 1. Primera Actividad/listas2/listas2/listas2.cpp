// listas2.cpp: archivo de proyecto principal.

// listas2.cpp : main project file.

#include "stdafx.h"
#include "iostream"

using namespace System;
using namespace std;

struct nodo
{
	int datos;
	nodo *sig;
};

nodo *inicial = NULL;
void crear_lista(nodo *anterior, nodo *nuevo)
{
	if (anterior == NULL)
	{
		cout << "creo" << endl;
		nuevo->sig = inicial;
		inicial = nuevo;
	}
	else
	{
		cout << "creo" << endl;
		nuevo->sig = anterior->sig;
		anterior->sig = nuevo;
	}
}

void borrar_lista(nodo *apun)
{
	nodo *inicial;
	while (apun != NULL)
	{
		cout << "borro" << endl;
		inicial = apun->sig;
		delete apun;
		apun = inicial;
	}
	
}

void main()
{
	nodo *anterior, *nuevo;
	char resp;
	anterior = NULL;
	do
	{
		nuevo = new nodo;
		crear_lista(anterior, nuevo);
		anterior = nuevo;
		cout << "Desea crear otro nodo? (s/n)" << endl;
		cin >> resp;
		resp = tolower(resp);
	} while (resp != 'n');
	borrar_lista(inicial);	
	system("pause");
}
