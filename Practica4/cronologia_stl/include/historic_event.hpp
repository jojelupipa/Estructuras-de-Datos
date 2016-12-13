/**
 * @file historic_event.hpp
 * @brief Fichero cabecera del TDA HistoricEvent
 * @author Sofía Almeida Bruno (@SofiaAlmeida)
 * @author Jesús Sánchez de Lechina Tejada (@jojelupipa)
 * @author Pedro Bonilla Nadal (@pedrobn23)
 * @bug
 */

#ifndef __HISTORICEVENT
#define __HISTORICEVENT

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <set>

using namespace std;

/**
 *  @brief T.D.A. HistoricEvent
 *
 * Una instancia @e h del tipo de datos abstracto @c HistoricEvent se compone
 * de una fecha y uno o más eventos sucedidos en dicha fecha. La fecha
 * representará únicamente el año en el que tuvieron lugar los acontecimientos
 * en forma de número natural, y cada uno de los acontecimientos podrán
 * contener más de una palabra.
 *
 * Un ejemplo de su uso:
 * @include test_historic.cpp
 */

class HistoricEvent {

private:
  /**
   * @page repConjunto Rep del TDA HistoricEvent
   *
   * @section invConjunto Invariante de la representación
   *
   * El invariante es \e rep.date != 0
   *
   * @section faConjunto Función de abstracción
   *
   * Un objeto válido @e rep del TDA HistoricEvent representa
   *
   * rep.first#rep.second[0]#rep.second[1]#...#rep.second[rep.size()-1]
   *
   */
  pair<int, set<string> > p;/**pair con un año y los acontecimientos */

public:

  /**
   * @brief Constructor por defecto de la clase
   */
  HistoricEvent() {}

  /**
   * @brief Constructor de la clase
   * @param d Fecha
   * @param s Acontecimiento ocurrido en dicha fecha
   * @return Crea el evento histórico con fecha d y acontecimiento s
   */
  HistoricEvent(int d, const string& s);

  /**
   * @brief Constructor de la clase
   * @param p pareja de int (fecha) y set de string (acontecimientos)
   * @return  Crea el evento histórico a partir del pair dado
   */
  HistoricEvent(const pair<int, set<string> > &p_alt);
  
  /**
   * @brief Constructor de la clase
   * @param d Fecha
   * @param v Set con string que almacenan acontecimientos ocurridos en dicha fecha
   * @return Crea el evento histórico con fecha d y acontecimientos v
   */
  HistoricEvent(int d, const set<string> &s);

  /**
   * @brief Constructor copia de la clase
   * @param c Cronología a copiar
   * @return Crea el evento histórico a partir de la cronología pasada
   */
  HistoricEvent(const HistoricEvent &h) {p = h.p;}

  typedef typename set<string>::iterator iterator;
  typedef typename set<string>::const_iterator const_iterator;

   /**
   * @brief Primer elemento del set
   * @return Iterador señalando al primer elemento
   */
  iterator begin() {return p.second.begin();}

  /**
   * @brief Primer elemento del set
   * @return Iterador constante señalando al primer elemento
   */
  const_iterator cbegin() const {return p.second.cbegin();}

  /**
   * @brief Último elemento del set
   * @return Iterador señalando al último elemento
   */
  iterator end() {return p.second.end();}

  /**
   * @brief Último elemento del set
   * @return Iterador constante señalando al último elemento
   */
  const_iterator cend() const {return p.second.cend();}

  /**
   * @brief Fecha
   * @return Fecha del evento implícito
   */
  int get_date() const {return p.first;}

  /**
   * @brief Acontecimientos
   * @return Devuelve un set de acontecimientos
   */
  set<string> get_befalls() const {return p.second;}

  /**
   * @brief Muestra el número de acontecimientos
   * @return Tamaño set befalls
   */
  int befalls_size() const {return p.second.size();}

  /**
   * @brief Asignar fecha
   * @param d Fecha a asignar
   * @return Void
   */
  void set_date(unsigned int d) {p.first = d;}

  /**
   * @brief Añadir acontecimiento.
   *        Si ya está, no se añade
   * @param Acontecimiento
   * @return Void
   */
  void add_befall(const string &s);

  /**
   * @brief Borra el acontecimiento indicado 
   * @param s Acontecimiento a borrar
   * @return Void
   */
  void rm_befall(const string &s) {p.second.erase(s);};

  /**
   * @brief Busca una cadena dentro de un set de acontecimientos
   * @param s String a buscar
   * @retval True si encuentra el string
   */
  bool search(const string &s) const;

  /**
   * @brief Busca una cadena dentro de un set de acontecimientos
   * @param s String a buscar
   * @return HistoricEvent con los acontecimientos que contienen dicho string
   */
  HistoricEvent get_coincidences(const string &s) const;

  /**
   * @brief Sobrecarga del operador == 
   *        Dos HistoricEvent se consideran iguales si tienen la misma fecha y los mismos acontecimientos
   * @param h HistoricEvent a comparar con el objeto implícito
   * @retval True si este objeto es igual a h
   */
  bool operator==(const HistoricEvent &h) {return p == h.p;}
 
  /**
   * @brief Sobrecarga del operador +
   * @pre Las dos cronologías deben tener el mismo año
   * @param h objeto a sumar con el implícito
   * @return objeto implícito al que se ha añadido los acontecimientos que no tenía de h.befalls
   */
  HistoricEvent& operator+(const HistoricEvent &h);
  
  /**
   * @brief Sobrecarga del operador <<
   * @param h HistoricEvent a comparar con el objeto implícito
   * @retval true si el año del objeto implícito es menor que el de h
   */
  friend ostream& operator<<(ostream &os, const HistoricEvent &h);

  /**
   * @brief Sobrecarga del operador >>
   * @param h HistoricEvent a comparar con el objeto implícito
   * @retval true si el año del objeto implícito es mayor que el de h
   */
  friend istream& operator>>(istream &is, HistoricEvent &h);

};

#endif
