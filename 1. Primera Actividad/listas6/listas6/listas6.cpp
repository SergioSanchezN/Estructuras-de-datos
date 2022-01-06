// listas6.cpp: archivo de proyecto principal.

// listas6.cpp : main project file.

#include "stdafx.h"
#include "iostream"

using namespace System;
using namespace std;

struct nodo
{
	int codigo;
	char *nombre;
	int nivel;
	nodo *sig;
};

nodo *inicial = NULL;
void leer_nodo(nodo *nuevo)
{
	cout << "Entre el codigo del estudiante" << endl;
	cin >> nuevo->codigo;
	cout << "Entre el nombre del estudiante" << endl;
	cin.ignore();
	nuevo->nombre = new char[30];
	cin.getline(nuevo->nombre, 30);
	cout << "Entre nivel del estudiante" << endl;
	cin >> nuevo->nivel;
}

void crear_lista(nodo *anterior, nodo *nuevo)
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
	cout << "El codigo es: " << apun->codigo << endl;
	cout << "El nombre es: " << apun->nombre << endl;
	cout << "El nivel  es: " << apun->nivel << endl;
}
void reco_recur(nodo *apun)
{
	if (apun != NULL)
	{
		imprime_nodo(apun);
		reco_recur(apun->sig);
	}
}

void borrar_lista(nodo *apun)
{
	nodo *inicial;
	while (apun != NULL)
	{
		inicial = apun->sig;
		delete apun;
		apun = inicial;
	}

}

nodo * buscar_nodo(nodo *apun, int &codigo)
{
	while (apun != NULL)
	{
		if (apun->codigo == codigo)return apun;
		else apun = apun->sig;
	}
	return NULL;
}

nodo * agregar_nodo(nodo *anterior, nodo *nuevo, int &codigo)
{
	if (codigo == 0)
	{
		//agrega al inicio de la lista
		nuevo->sig = anterior;
		anterior = nuevo;
		leer_nodo(nuevo);
		return anterior;
	}
}

void main()
{
	nodo *anterior, *nuevo, *apun;
	char resp;
	anterior = NULL;
	do
	{
		nuevo = new nodo;
		crear_lista(anterior, nuevo);
		anterior = nuevo;
		cout << endl;
		cout << "Desea crear otro nodo? (s/n)" << endl << endl;
		cin >> resp;
		resp = tolower(resp);
	} while (resp != 'n');

	//Inicio del recorrido de la lista
	cout << "LA LISTA ORIGINALMENTE CREADA ES: " << endl;
	apun = inicial;
	reco_recur(apun);

	//Inicio de la agregacion de nuevos nodos
	cout << endl;
	cout << "INICIO DE LA AGREGACION DE NUEVOS NODOS A LA LISTA ORIGINAL" << endl;
	int codigo;
	apun = inicial;

	do
	{
		cout << endl;
		cout << "Entre el cogigo clave (Digite 0 si va a agregar ala cabeza de la "
			"lista, en" << endl;
		cout << "Caso contrario digite el codigo del nodo anterior al queva a crear" << endl << endl;

		cin >> codigo;
		if (codigo == 0)
		{
			nuevo = new nodo;
			inicial = agregar_nodo(inicial, nuevo, codigo);
		}
		else
		{
			anterior = inicial;
			anterior = buscar_nodo(anterior, codigo);
			if (anterior != NULL)
			{
				nuevo = new nodo;
				anterior = agregar_nodo(anterior, nuevo, codigo);
			}
			else cout << "El nodo no ha sido encontrado" << endl;
		}
		cout << "Desea agregar otro nodo? (s/n)" << endl;
		cin >> resp;
		resp = tolower(resp);
	} while (resp != 'n');

		cout << "LA LISTA COMPLETA ES: " << endl;
	apun = inicial;
	reco_recur(apun);

	borrar_lista(inicial);

}
