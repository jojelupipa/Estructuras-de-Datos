/***
   * @file Pila_max_List.h
   * @brief Fichero cabecera del TDA Pila_max_list
   * Pila ordenada implementada a partir de celdas enlazadas
   *
   * @author Sofía Almeida Bruno (@SofiaAlmeida)
   * @author Jesús Sánchez de Lechina Tejada (@jojelupipa)
   * @author Pedro Bonilla Nadal (@pedrobn23)
   */

#ifndef __PILA_MAX_LIST_H__
#define __PILA_MAX_LIST_H__

#include <cassert>
#include <iostream>
#include "lista.hpp"
/***
   *  @brief T.D.A. Pila_max_list
   *
   */
template <class T>
class Pila_max {
private:
	Lista<T> l;

public:
/**
  * @brief Función que devuelve el valor del primer último de la pila. FIFO.
  * @return elemento de la pila.
  */
	elemento<T> top () const {return l.top();};
/**
  * @brief Evalua si la pila está vacia.
  * @return devuelve un bool con la información.
  */
	bool empty() {return l.empty();};
/**
  * @brief saca el último elemento de la pila
  */
	void pop() {l.pop();};
/**
  * @brief añade un elemento de la pila
  */
	void push(const T& t) {l.push(t);};
};

#endif
