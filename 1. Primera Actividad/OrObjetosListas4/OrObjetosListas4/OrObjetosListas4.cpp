// OrObjetosListas4.cpp: archivo de proyecto principal.

// listas4.cpp : main project file.

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
	nodo *get_inicial()
	{
		return inicial;
	}
	~lista1();
	void crear_lista(nodo *anterior, nodo *nuevo);
	void reco_iter();
};

void leer_nodo(nodo *nuevo)
{
	cout << "Entre el valor del nodo" << endl;
	cin >> nuevo->datos;
}

void lista1::crear_lista(nodo *anterior, nodo *nuevo)
{
	if (anterior == NULL)
	{
		nuevo->sig = inicial;
		leer_nodo(nuevo);
		inicial = nuevo;
	}
	else
	{
		nuevo->sig = anterior->sig;
		anterior->sig = nuevo;
		leer_nodo(nuevo);
	}
}

void imprime_nodo(nodo *apun)
{
	cout << "El valor es: " << apun->datos << endl;
}

void reco_recur(nodo *apun)
{
	if (apun != NULL)
	{
		imprime_nodo(apun);
		reco_recur(apun->sig);
	}
}

//void lista1::reco_iter()
//{
//	reco_recur(inicial);
//}

lista1::~lista1()
{
	nodo *apun = inicial;
	while (apun != NULL)
	{
		inicial = apun->sig;
		delete apun;
		apun = inicial;
	}
	system("pause");
}

void main()
{
	nodo *anterior, *nuevo, *apun;
	char resp;
	lista1 l;
	anterior = NULL;
	do
	{
		nuevo = new nodo;
		l.crear_lista(anterior, nuevo);
		anterior = nuevo;
		cout << "Desea crear otro nodo? (s/n)" << endl;
		cin >> resp;
		resp = tolower(resp);
	} while (resp != 'n');
	l.reco_recur(l.get_inicial);
}
