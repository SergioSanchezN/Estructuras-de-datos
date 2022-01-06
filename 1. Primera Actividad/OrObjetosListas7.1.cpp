// OrObjetosListas7.1.cpp: archivo de proyecto principal.

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

class lista1
{
private:
	nodo *inicial;
public:
	lista1()
	{
		inicial = NULL;
	}
	nodo * get_inicial()
	{
		return inicial;
	}
	void set_inicial(nodo *cambio)
	{
		inicial = cambio;
	}
	~lista1();
	void crear_lista(nodo *anterior, nodo *nuevo);
	void reco_recur(nodo *apun);
	nodo *buscar_nodo(nodo *apun, int &codigo);
	nodo * agregar_nodo(nodo *anterior, nodo *nuevo, int &codigo);
	void borrar_nodo(nodo *apun);
};

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
	cout << "El codigo es: " << apun->codigo << endl;
	cout << "El nombre es: " << apun->nombre << endl;
	cout << "El nivel  es: " << apun->nivel << endl;
}

void lista1::reco_recur(nodo *apun)
{
	if (apun != NULL)
	{
		imprime_nodo(apun);
		reco_recur(apun->sig);
	}
}

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

nodo * lista1::buscar_nodo(nodo *apun, int &codigo)
{
	while (apun != NULL)
	{
		if (apun->codigo == codigo)return apun;
		else apun = apun->sig;
	}
	return NULL;
}

nodo * lista1::agregar_nodo(nodo *anterior, nodo *nuevo, int &codigo)
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

void lista1::borrar_nodo(nodo *apun)
{
	nodo *aux;
	aux = get_inicial();
	if (aux == apun)
	{
		set_inicial(aux->sig);
		delete apun;
	}

	else {
		while (aux->sig != apun)
		{
			aux = aux->sig;
		}
		aux->sig = apun->sig;
		delete apun;
	}
}

void main()
{
	nodo *anterior, *nuevo, *apun;
	char resp;
	int opc;
	lista1 l;
	
	do
	{
		anterior = NULL;

		cout << "desea crear una lista?(s/n)" << endl;
		cin >> resp;
		resp = tolower(resp);

		if (resp == 's')
		{
			do
			{
				nuevo = new nodo;
				l.crear_lista(anterior, nuevo);
				anterior = nuevo;
				cout << endl;
				cout << "Desea crear otro nodo? (s/n)" << endl << endl;
				cin >> resp;
				resp = tolower(resp);
			} while (resp != 'n');

			do
			{
				cout << "[========================]" << endl;
				cout << "[   0.salir              ]" << endl;
				cout << "[   1.Mostrar lista      ]" << endl;
				cout << "[   2.Agregar nodos      ]" << endl;
				cout << "[   3.Liminar nodos      ]" << endl;
				cout << "[   4.Crear otra lista   ]" << endl;
				cout << "[========================]" << endl;
				cin >> opc;

				switch (opc)
				{
				case 1:
					cout << "LA LISTA ORIGINALMENTE CREADA ES: " << endl;
					l.reco_recur(l.get_inicial());
					cout << endl;
					break;

				case 2:
					cout << "INICIO DE LA AGREGACION DE NUEVOS NODOS A LA LISTA ORIGINAL" << endl;
					int codigo;
					apun = l.get_inicial();

					do
					{
						cout << endl;
						cout << "Entre el cogigo clave (Digite 0 si va a agregar a la cabeza de la lista, en" << endl;
						cout << "Caso contrario digite el codigo del nodo anterior al queva a crear" << endl << endl;

						cin >> codigo;
						if (codigo == 0)
						{
							nuevo = new nodo;
							l.set_inicial(l.agregar_nodo(l.get_inicial(), nuevo, codigo));
						}
						else
						{
							anterior = l.get_inicial();
							anterior = l.buscar_nodo(anterior, codigo);
							if (anterior != NULL)
							{
								nuevo = new nodo;
								anterior = l.agregar_nodo(anterior, nuevo, codigo);
							}
							else cout << "El nodo no ha sido encontrado" << endl;
						}
						cout << "Desea agregar otro nodo? (s/n)" << endl;
						cin >> resp;
						resp = tolower(resp);
					} while (resp != 'n');

					cout << "LA LISTA COMPLETA ES: " << endl;
					apun = l.get_inicial();
					l.reco_recur(apun);
					break;

				case 3:
					int cod;

					do
					{
						cout << "Digite el codigo de el nodo que quiere eliminar: " << endl << endl;
						cin >> cod;
						nodo *eliminar = l.buscar_nodo(l.get_inicial(), cod);
						l.borrar_nodo(eliminar);

						cout << "Desea eliminar otro nodo? (s/n)" << endl;
						cin >> resp;
						resp = tolower(resp);
					} while (resp != 'n');
					cout << "LA LISTA COMPLETA ES:" << endl;
					apun = l.get_inicial();
					l.reco_recur(apun);
					break;
				case 4:
					opc = 0;
					resp = 't';
					break;
				}
			} while (opc!=0);

			
		}
	} while (resp != 's' && resp != 'n');






	


	

	
	
	

	
	



}
