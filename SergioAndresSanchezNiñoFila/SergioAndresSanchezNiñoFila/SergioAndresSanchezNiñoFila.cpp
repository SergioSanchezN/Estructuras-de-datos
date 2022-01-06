// SergioAndresSanchezNiñoFila.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include "iostream"

using namespace System;
using namespace std;

struct nodo 
{
	int dato;
	nodo *sig;
};

class Fila 
{
private:
	nodo *frente;
	nodo *final;
public:
	Fila();
	char meter(int valor);
	char sacar(int &valor);
	~Fila();
	void limpiarFila();
	int frenteFila();
	int longitudFila();
	void desplegarFila();
};

Fila::Fila() {
	frente = NULL;
	final = NULL;
}

Fila::~Fila() {
	nodo *apunt;
	apunt = frente;
	while (frente != NULL) {
		frente = apunt->sig;
		delete apunt;
		apunt = frente;
	}
}

char Fila::meter(int valor) {
	nodo *nuevo;
	nuevo = new nodo;
	if (nuevo == NULL)return 0;
	else {
		nuevo->dato = valor;
		if (final == NULL)frente = nuevo;
		else final->sig = nuevo;
		nuevo->sig = NULL;
		final = nuevo;
		return 1;
	}
}

char Fila::sacar(int &valor) {
	nodo *apunt;
	apunt = frente;
	if (apunt == NULL)return 0;
	else {
		valor = apunt->dato;
		if (frente->sig == NULL) {
			frente = NULL;
			final = NULL;
		}
		else frente = apunt->sig;
		delete apunt;
		return 1;
	}
}

int Fila::longitudFila()
{
	nodo *apunt;
	int num;
	if (frente != NULL)
	{
		apunt = frente;
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

void Fila::desplegarFila() {
	if (frente != NULL) {
		nodo *apunt;
		apunt = frente;
		while (apunt != NULL) {
			cout << apunt->dato << " ";
			apunt = apunt->sig;
		}
	}
	else
	{
		cout << "_____________________________" << endl;
		cout << "|    La fila esta vacia     |" << endl;
		cout << "[___________________________]" << endl << endl;
	}
	cout << endl;
	system("pause");
}
void Fila::limpiarFila()
{
	nodo *apunt;
	apunt = frente;
	while (frente != NULL) {
		frente = apunt->sig;
		delete apunt;
		apunt = frente;
	}
	frente = NULL;
	final = NULL;
}
int Fila::frenteFila()
{
	return frente->dato;
}
void main() {
	Fila l;
	int opc = 0, valor;
	nodo *anterior, *nuevo, *apun, *eliminar;
	char resp;
	anterior = NULL;
	do {
		cout << "________________________________" << endl;
		cout << "|1. Agregar Elemento           |" << endl;
		cout << "|2. Sacar Elemento             |" << endl;
		cout << "|3. Longitud De Fila           |" << endl;
		cout << "|4. Frente De La Fila          |" << endl;
		cout << "|5. Limpiar La Fila            |" << endl;
		cout << "|6. Desplegar La Fila          |" << endl;
		cout << "|7. Salir                      |" << endl;
		cout << "[______________________________]" << endl;
		cout << endl;
		cin >> opc;
		switch (opc) {
		case 1:
			do {
				cout << "Ingrese un elemento a la fila" << endl;
				cin >> valor;
				l.meter(valor);
				cout << "Desea ingresar otro elemento a la fila? (s/n)" << endl;
				cin >> resp;
				resp = tolower(resp);
			} while (resp == 's');
			system("pause");
			break;
		case 2:
			do {
				if (l.sacar(valor))
				{
					cout << "El elemento eliminado es : " << valor << endl;
					cout << "Desea eliminar otro elemento? (s/n)" << endl;
					cin >> resp;
					resp = tolower(resp);
				}
				else
				{
					cout << "_____________________________" << endl;
					cout << "|    La fila esta vacia     |" << endl;
					cout << "[___________________________]" << endl << endl;
				}
			} while (resp == 's');
			system("pause");
			break;
		case 3:
			cout << "____________________________________________________" << endl;
			cout << "La longitud de la Fila es: " << l.longitudFila() << endl;;
			cout << "____________________________________________________" << endl << endl;
			break;
		case 4:
			cout << "____________________________________________________" << endl;
			cout << "El frente de la fila es: " << l.frenteFila() << endl;
			cout << "____________________________________________________" << endl << endl;
			break;
		case 5:
			l.limpiarFila();
			break;
		case 6:
			cout << "_____________________________" << endl;
			l.desplegarFila();
			cout << "_____________________________" << endl << endl;
			break;
		case 7:
			cout << "_____________________________" << endl;
			cout << "|     Fin del programa      |" << endl;
			cout << "[___________________________]" << endl << endl;
			l.~Fila();
			break;
		}
		if (opc < 1 || opc>7)
		{
			cout << "_____________________________" << endl;
			cout << "|   Opcion no encontrada    |" << endl;
			cout << "[___________________________]" << endl << endl;
		}
	} while (opc != 7);
	system("pause");
}