/**
 * @file Cronology.hpp
 * @brief Fichero cabecera del TDA Chronology
 * @author Sofía Almeida Bruno (@SofiaAlmeida)
 * @author Jesús Sánchez de Lechina Tejada (@jojelupipa)
 * @author Pedro Bonilla Nadal (@pedrobn23)
 */

#ifndef __CHRONOLOGY
#define __CHRONOLOGY

#include "historic_event.hpp"
#include <iostream>
#include <map>
#include <vector>

/**
 * @brief T.D.A. Chronology
 *
 * Una instancia @e h del tipo de datos abstracto @c Chronology se compone
 * de un conjunto de eventos históricos. Ver documentación de historic_event para más información.
 *
 * Un ejemplo de su uso:
 * @include ../src/pruebacronologia.cpp
 * @include ../src/union_cronologia.cpp
 */

class Chronology {
  
private:
  /**
   * @page repConjunto Rep del TDA Chronology
   *
   * @section invConjunto Invariante de la representación
   *
   * El invariante es \e h.second no válido (consultar historic_event.h)
   *
   * @section faConjunto Función de abstracción
   *
   * Un objeto válido @e rep del TDA Chronology representa
   *
   *  
   * events[0].first#events[0].second[0]#...#events[0].secind[events.second.size()-1]
   *  ...
   *
   */

  map<int, HistoricEvent> events; /**<map de HistoricEvent>**/

public:
  /**
   * @brief Constructor por defecto de la clase.
   */
  Chronology() {}

  /**
   * @brief Crea una cronología a partir de otra
   * @param chrono
   * @return Cronología con las propiedades de la anterior
   */
  Chronology(const Chronology& chrono) {events = chrono.events;}
    
  /**
   * @brief Constructor
   * @param h Vector de eventos
   * @return Cronología con vector de eventos h
   */
  Chronology(vector<HistoricEvent> h);

  typedef map<int, HistoricEvent>::iterator iterator;
  typedef map<int, HistoricEvent>::const_iterator const_iterator;

  /**
   * @brief Primer elemento del map
   * @return Iterador señalando al primer elemento
   */
  iterator begin() {return events.begin();}

  /**
   * @brief Primer elemento del map
   * @return Iterador constante señalando al primer elemento
   */
  const_iterator cbegin() const {return events.cbegin();}

  /**
   * @brief Último elemento del map
   * @return Iterador señalando al último elemento
   */
  iterator end() {return events.end();}

  /**
   * @brief Último elemento del map
   * @return Iterador constante señalando al último elemento
   */
  const_iterator cend() const {return events.cend();}

  /**
   * @brief Eventos
   * @return Devuelve un map de eventos Históricos
   */
  map<int, HistoricEvent> get_events() const {return events;};

  /**
   * @brief Eventos de un año
   * @param date Fecha a consultar
   * @return Evento Histórico del año indicado
   */
  HistoricEvent get_date_events(const int date);
  
  /**
   * @brief Obtiene un set con los acontecimientos de un año
   * @param date Año a buscar
   * @return set de acontecimientos del año date
   */
  set<string> get_befalls(int date);

  /**
   * @brief Inserta un evento en su posición correspondiente
   * @param date Fecha del evento
   * @param s Nombre del evento
   * @return Void
   */
  void insert_befall(int date, const string &s);

  /**
   * @brief Añade un HistoricEvent a la cronología
   * @param h Evento a añadir
   * @return Void
   */
  void insert_event(const HistoricEvent &h);

  /**
   * @brief Borra un evento
   * @param date Fecha del evento a borrar
   * @return Void
   */
  void rm_event(int date);

  /**
   * @brief Eventos anteriores
   * @param d Año hasta el que guardar los eventos
   * @return Map con los eventos correspondientes
   */
  Chronology prev_events(int d);

  /**
   * @brief Eventos posteriores
   * @param d Año a partir del cual se buscan los eventos
   * @return Map con los eventos correspondientes
   */
  Chronology post_events(int d);

  /** @brief  Eventos en un rango
   * @param inf Extremo inferior de la búsqueda (fecha)
   * @param sup Extremo superior de la búsqueda (fecha)
   * @return Map con los eventos correspondientes
   */
  Chronology range(int inf, int sup);
  
  /**
   * @brief Busca los eventos en que se encuentra la palabra dada.
   * @param s Palabra/s a buscar
   * @return Chronology con los eventos que contienen a s
   */
  Chronology word_search(const string &s);
  
  /**
   * @brief Une dos cronologías indicadas en una tercera
   * @param input_1 Archivo donde se encuentra la primera cronología
   * @param input_2 Archivo donde se encuentra la segunda cronología
   * @param output Nombre del archivo en el cual se introducirá la nueva cronología
   * @return Void
   */
  void concat_chron(string input_1, string input_2, string output);
  
  /**
   * @brief Dada una palabra clave devolvemos un subconjunto de elementos de cronología cuyos eventos contengan esa palabra
   * @param word String a buscar
   * @param in Fichero en el que buscar
   * @return Chronology con los eventos coincidentes
   */
  Chronology word_filter(const string& word, const string& in);
  
  /**
   * @brief Filtrado por dos fechas, lee de un fichero y escribe en otro
   * @param filein Nombre del fichero de lectura
   * @param lower Primera fecha
   * @param upper Segunda fecha
   * @parm fileout Nombre del fichero de salida
   * @return Void
   */
  void date_filter(const string& filein, const int& lower, const int& upper, const string& fileout);
  
  /**
   * @brief Filtrado por dos fechas, lee de un fichero y escribe en salida estándar
   * @param filein Nombre del fichero de lectura
   * @param lower Primera fecha
   * @param upper Segunda fecha
   * @return Chronology con los eventos del intervalo especificado
   */
  void date_filter(const string& filein, const int& lower, const int& upper);
  
  /**
   * @brief Datos estadísticos acerca de la cronología: Recuento de años, número de eventos ocurridos, máximo de eventos y promedio de eventos por año(salida estándar)
   * @param filename Fichero con la cronología
   * @return Void
   */

  void stats(const string& filename);

  /**
   * @brief Unir de forma ordenada dos cronologías
   * @param c Cronología a unir con la implícita
   * @return Cronología mezclada y ordenada
   */
  Chronology& operator+(const Chronology &c);
  
  /**
   * @brief Sobrecarga del operator []
   * @param d Año de la posición a devolver
   * @return HistoricEvent con el año d
   */
  HistoricEvent& operator[](unsigned int d) {return events[d];}

  /**
   * @brief Sobrecarga del operador de asignación
   * @param c Cronología a asignar
   * @return Referencia a cronología asignada 
   */
  Chronology& operator=(const Chronology &c);
  
  /**
   * @brief Sobrecarga del operador <<
   * @param os Flujo de salida
   * @param c Cronología a mostrar
   * @return Muestra una cronología con el formato:
   *         events[0].first#events[0].second[0]#...#events[0].secind[events.second.size()-1]
   *         ...
   */
  friend ostream& operator<<(ostream &os, const Chronology &c);

  /**
   * @brief Sobrecarga del operador >>
   * @param is Flujo de entrada
   * @param c Cronología a escribir
   * @return Flujo de entrada
   */
  friend istream& operator>>(istream &is, Chronology &c);
};

#endif
