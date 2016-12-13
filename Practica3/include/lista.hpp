#ifndef _LISTA___
#define _LISTA___

#include <iostream>
#include <cassert>

/*Puesto que la pila es una estructura que solo se puede leer de atrás a adelante
no vamos a implementar una lista circular, si no una lista de celdas encalazadas hacia atrás,
pero también hacia adelante, para aumentar la eficiencia del constructor de entrada y salida
*/
template <class T>
struct Celda {
	elemento<T> dato;
	Celda<T>* ant;
	Celda<T>* sig;
};

template <class T>
class Lista {
private:
	Celda<T> *cabecera;

public:
	Lista ();
	Lista (const Lista& p);

	elemento<T> top () const {return (cabecera->ant->dato);};
	bool empty() {return !(cabecera->ant);};
	void pop();
	void push(const T& t);
	Lista& operator= (const Lista& p);;

	~Lista ();
};
#include "../src/lista.cpp"
#endif
