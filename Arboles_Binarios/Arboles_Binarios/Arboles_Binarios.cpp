#include "stdafx.h"
#include "iostream"

using namespace System;
using namespace std;

class nodoarbol
{
public:
	int info;
	nodoarbol *der, *izq;
	nodoarbol()
	{
		izq = NULL;
		der = NULL;
	}
	nodoarbol(int dato)
	{
		info = dato;
		izq = NULL;
		der = NULL;
	}
};

class ABB
{
private:
	nodoarbol *raiz;
	int altura;
public:
	ABB()
	{
		raiz = NULL;
	}

	~ABB()
	{
		cout << "Entró al destructor" << endl;
		borrar_nodos(raiz);
		cout << "Salgo del destructor" << endl;
	}

	void borrar_nodos(nodoarbol *raiz)
	{
		if (raiz != NULL)
		{
			nodoarbol *derecho, *izquierdo;

			derecho = raiz->der;
			izquierdo = raiz->izq;

			cout << "Destructor de " << raiz->info << endl;
			delete raiz;

			borrar_nodos(izquierdo);
			borrar_nodos(derecho);
		}
	}

	void insertar()
	{
		nodoarbol *aux1, *aux2, *aux3;
		aux1 = new nodoarbol;
		bool rep;

		aux2 = raiz;
		aux3 = NULL;
		cout << "Ingrese el valor del nuevo nodo" << endl;
		cin >> aux1->info;
		while (aux2 != NULL)
		{
			if (aux2->info == aux1->info)
			{
				cout << "El nodo a insertar ya existe" << endl;
				aux2 = NULL;
				rep = true;
				delete aux1;
			}
			else
			{
				aux3 = aux2;
				if (aux1->info > aux2->info) aux2 = aux2->der;
				else
					aux2 = aux2->izq;
			}
		}
		if (rep == false)
		{
			if (aux3 == NULL) raiz = aux1;
			else
				if (aux1->info < aux3->info) aux3->izq = aux1;
				else
					aux3->der = aux1;
		}

	}

	nodoarbol *devolver_raiz()
	{
		return raiz;
	}

	//IMPRIMIR

	//  Preorden

	void despliegaPreorden(nodoarbol *raiz)
	{
		if (raiz != NULL)
		{
			cout << raiz->info << endl;
			despliegaPreorden(raiz->izq);
			despliegaPreorden(raiz->der);
		}
	}

	//  Inorden

	void despliegaInorden(nodoarbol *raiz)
	{
		if (raiz != NULL)
		{
			despliegaInorden(raiz->izq);
			cout << raiz->info << endl;
			despliegaInorden(raiz->der);
		}
	}

	//   Postorden

	void despliegaPostorden(nodoarbol *raiz)
	{
		if (raiz != NULL)
		{			
			despliegaPostorden(raiz->izq);
			despliegaPostorden(raiz->der);
			cout << raiz->info << endl;
		}
	}

	//  Preorden Converso

	void despliegaPreorden_Con(nodoarbol *raiz)
	{
		if (raiz != NULL)
		{
			cout << raiz->info << endl;
			despliegaPreorden(raiz->der);
			despliegaPreorden(raiz->izq);
		}
	}

	//   Inorden Converso

	void despliegaInorden_Con(nodoarbol *raiz)
	{
		if (raiz != NULL)
		{
			despliegaInorden(raiz->der);
			cout << raiz->info << endl;
			despliegaInorden(raiz->izq);
		}
	}

	//   Postorden Converso

	void despliegaPostorden_Con(nodoarbol *raiz)
	{
		if (raiz != NULL)
		{
			despliegaPostorden(raiz->der);
			despliegaPostorden(raiz->izq);
			cout << raiz->info << endl;
		}
	}

	// Nivel por nivel

	void despliegaNivelxNivel() {
		for (int i = 0; i <= alturaArbol(); i++) {
			desplegarPORNIVEL(raiz, 0, i);
			cout << endl;
		}
	}

	//  Nivel por nivel converso
	
	void despliegaNivelxNivel_IN()
	{
		for (int i = alturaArbol(); i >= 0; i--) {
			desplegarPORNIVEL(raiz, 0, i);
			cout << endl;
		}
	}

	void desplegarPORNIVEL(nodoarbol *puntero, int nivel, int contador) 
	{

		if (puntero != NULL) {
			if (nivel == contador) {
				cout << contador<<":"<< puntero->info<<endl;
			}
			desplegarPORNIVEL(puntero->izq, nivel + 1, contador);
			desplegarPORNIVEL(puntero->der, nivel + 1, contador);
		}
	}
	
	int alturaArbol() {
		altura = 0;
		if (raiz != NULL)
		{
			alturaArbol(raiz, 1);
			return altura;
		}
		
	}
	void alturaArbol(nodoarbol *pivote, int nivel) {
		if (pivote != NULL) {
			alturaArbol(pivote->izq, nivel + 1);
			if (nivel > altura)
			{
				altura = nivel;
			}
			alturaArbol(pivote->der, nivel);
		}
	}

	

	void eliminar_nodo(int valor) {

		nodoarbol *aux1, *aux2, *temp;
		bool b;

		if (raiz != NULL) {

			aux1 = raiz;
			aux2 = NULL;

			while (aux1->info != valor) {

				aux2 = aux1;
				if (valor < aux1->info) aux1 = aux1->izq;
				else aux1 = aux1->der;

				if (aux1 == NULL) {
					cout << "El nodo a eliminar no existe" << endl;
					break;
				}
			}
		}
		else 
		{

			cout << "El arbol no tiene nodos" << endl;
			aux1 = NULL;

		}


		if (aux1 != NULL) {

			//Cuando no tiene hijos

			temp = aux1;

			if ((aux1->izq == NULL) && (aux1->der == NULL)) 
			{

				if (aux2 != NULL) 
				{

					if (aux1->info > aux2->info) aux2->der = NULL;
					else aux2->izq = NULL;

				}
				else 
				{
					raiz = NULL;
				}

			}
			else 
			{

				if ((aux1->izq != NULL) && (aux1->der != NULL)) 
				{

					//Cuando tiene dos hijos
					aux2 = aux1;//Con el predecesor
					temp = aux1->der;
					b = true;

					while (temp->izq != NULL) 
					{

						aux2 = temp;
						temp = temp->izq;
						b = false;

					}

					aux1->info = temp->info;
					if (b == true)aux1->der = temp->der;

					else 
					{
						if (temp->der != NULL)aux2->izq = temp->der;
						else aux2->izq = NULL;
					}

				}
				else {

					//Cuando tiene un solo hijo

					if (aux1->izq == NULL)
						if (aux2 != NULL) 
						{
							if (aux1->info < aux2->info) aux2->izq = aux1->der;
							else aux2->der = aux1->der;
						}

						else raiz = aux1->der;

					else

						if (aux2 != NULL)
						{
							if (aux1->info < aux2->info) aux2->izq = aux1->izq;
							else aux2->der = aux1->izq;
						}
						else raiz = aux1->izq;

				}

			}

			delete temp;

		}

	}

};

void main()
{
	nodoarbol *raiz;
	ABB n;
	int opc;
	char resp;
	do
	{
		
		cout << "___________________________________________" << endl;
		cout << "| 1. Agregar nodo arbol                    |" << endl;
		cout << "| 2. Borrar nodos                          |" << endl;
		cout << "| 3. Desplegar en preorden                 |" << endl;
		cout << "| 4. Desplegar en inorden                  |" << endl;
		cout << "| 5. Desplegar en postorden                |" << endl;
		cout << "| 6. Desplegar en preorden - converso      |" << endl;
		cout << "| 7. Desplegar en inorden - converso       |" << endl;
		cout << "| 8. Desplegar en postorden - converso     |" << endl;
		cout << "| 9. Desplegar nivel por nivel             |" << endl;
		cout << "| 10. Desplegar nivel por nivel - converso |" << endl;
		cout << "| 11. Borrar arbol                         |" << endl;
		cout << "| 12. salir                                |" << endl;
		cout << "___________________________________________" << endl;
		cin >> opc;
		switch (opc)
		{
		case 1:
			do 
			{
				n.insertar();
				cout << "Desea agregar otro nodo? (s/n)" << endl;
				cin >> resp;
				resp = tolower(resp);
			} while (resp == 's');
			break;
		case 2:
			n.eliminar_nodo(60);
			n.eliminar_nodo(20);
			n.eliminar_nodo(30);
			break;
		case 3:
			n.despliegaPreorden(n.devolver_raiz());
			break;
		case 4:
			n.despliegaInorden(n.devolver_raiz());
			break;	
		case 5:
			n.despliegaPostorden(n.devolver_raiz());
			break;
		case 6:
			n.despliegaPreorden_Con(n.devolver_raiz());
			break;
		case 7:
			n.despliegaInorden_Con(n.devolver_raiz());
			break;
		case 8:
			n.despliegaPostorden_Con(n.devolver_raiz());
			break;
		case 9:
			n.despliegaNivelxNivel();
			break;
		case 10:
			n.despliegaNivelxNivel_IN();
			break;
		case 11:
			n.~ABB();
			break;
		}
		if (opc < 1 || opc>12)
		{
			cout << "Opcion no encontrada" << endl;
		}
	} while (opc != 12);

	system("pause");	
}


