#include "stdafx.h"
#include "iostream"


using namespace std;

struct nodo
{
	int dato;
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
};

Lsec::Lsec()
{
	inicial = NULL;
}

Lsec::~Lsec()
{
	if (inicial != NULL)
	{
		nodo *apunt, *ultimo;
		ultimo = buscarUltimo();
		ultimo->sig = NULL;
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
		} while (apunt != inicial);
	}
	cout << endl;
	cout << "_____________________________" << endl << endl;
}

nodo *Lsec::buscarUltimo()
{
	nodo *ultimo;
	ultimo = inicial;
	while (ultimo->sig != inicial)ultimo = ultimo->sig;
	return ultimo;
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
	nodo *nuevo, *anterior, *apunt;
	char resp;
	do
	{
		nuevo = new nodo();
		cout << "Entre la clave del nodo a agregar" << endl;
		cin >> nuevo->dato;
		if (inicial == NULL)
		{
			inicial = nuevo;
			nuevo->sig = nuevo;
		}
		else
		{
			anterior = buscarLista(nuevo->dato);

			if (anterior == NULL)
			{
				if (nuevo->dato != inicial->dato)
				{
					nodo *ultimo;
					ultimo = buscarUltimo();
					ultimo->sig = nuevo;
					nuevo->sig = inicial;
					inicial = nuevo;
				}
				else
				{
					cout << "_____________________________" << endl;
					cout << "|El nodo a agregar ya existe|" << endl;
					cout << "[___________________________]" << endl << endl;
				}
			}
			else
			{
				apunt = anterior->sig;
				if (nuevo->dato != apunt->dato)
				{
					nuevo->sig = anterior->sig;
					anterior->sig = nuevo;
				}
				else
				{
					cout << "_____________________________" << endl;
					cout << "|El nodo a agregar ya existe|" << endl;
					cout << "[___________________________]" << endl << endl;
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
		nodo *ultimo, *eliminar, *apunt;
		ultimo = buscarUltimo();
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
				inicial = inicial->sig;
				ultimo->sig = inicial;
				delete eliminar;
			}
		}
		else if (apunt != NULL && clave == apunt->sig->dato)
		{
			eliminar = apunt->sig;
			apunt->sig = eliminar->sig;
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
		cout << "[___________________________]" << endl<<endl;
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
