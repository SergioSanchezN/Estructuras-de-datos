// OrObjetosListas1.cpp: archivo de proyecto principal.

// listas1OrOb.cpp : main project file.

#include "stdafx.h"
#include "iostream"

using namespace System;
using namespace std;

struct nodo
{
	int datos;
	nodo *sig;
};

class lista1
{
private:
	nodo *inicial;
public:
	lista1()
	{
		inicial = NULL;
	}
	~lista1();
	void crear_lista(nodo *anterior, nodo *nuevo);
};

void lista1::crear_lista(nodo *anterior, nodo *nuevo)
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

lista1::~lista1()
{
	nodo *apun = inicial;
	while (apun != NULL)
	{
		cout << "borro" << endl;
		inicial = apun->sig;
		delete apun;
		apun = inicial;
	}
	system("pause");
}

void main()
{
	nodo *anterior, *nuevo;
	int i;
	lista1 l;
	anterior = NULL;
	for (i = 1; i <= 3; i++) {
		nuevo = new nodo;
		l.crear_lista(anterior, nuevo);
		anterior = nuevo;
	}

}
