/**
  * @file chronology.h
  * @brief Fichero cabecera del TDA Chronology
  * @author Sofía Almeida Bruno (@SofiaAlmeida)
  * @author Jesús Sánchez de Lechina Tejada (@jojelupipa)
  * @author Pedro Bonilla Nadal (@pedrobn23)
  * @bug operator >>
  */

#ifndef __CHRONOLOGY
#define __CHRONOLOGY

#include "historic_event.h"
#include <iostream>

/**
  *  @brief T.D.A. Chronology
  *
  * Una instancia @e h del tipo de datos abstracto @c Chronology se compone
  * de un conjunto de eventos históricos. Se representará un vector de eventos
  * históricos. Ver documentación de historic_event para más información.
  *
  	TODO (si sobra tiempo)
  * Un ejemplo de su uso:
  * @include
  */

class Chronology {

 private: // REVIEW
/**
  * @page repConjunto Rep del TDA Chronology
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es \e rep.event[i] no válido (consultar historic_event.h)
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA Chronology representa
  *
  *  event[0]
  *  event[1]
  *  ...
  *
*/
	vector<HistoricEvent> event; /**< vector con los eventos historicos */


 public:
/**
* @brief Constructor por defecto de la clase.
*/
Chronology();

/**
  * @brief Crea una cronología a partir de otra
  * @param chrono
  * @return Cronología con las propiedades de la anterior
  */
  Chronology(const Chronology& chrono);

/**
  * @brief Constructor
  * @param h Vector de eventos
  * @return cronología con vector de eventos h
  */
  Chronology(vector<HistoricEvent> h);

/**
  * @brief Eventos
  * @return Devuelve un vector de eventos
  */
  vector<HistoricEvent> get_events() const {return event;};

/**
  * @brief Obtiene vector con los befalls de un año
  * @param date Año a buscar
  * @return Vector de befalls del año date
  */
  vector<string> get_befalls(int date);

/** @brief Inserta un evento en su posición correspondiente
  * @param date Fecha del evento
  * @param s Nombre del evento
  * @retval true si el evento ha sido insertado correctamente
  */
  bool InsertBefall(int date, const string &s);

/**
  * @brief Añade un HistoricEvent a la cronología
  * @param h evento a añadir
  * @retval true si el evento ha sido insertado correctamente
  */
  bool InsertEvent(const HistoricEvent &h);

/**
  * @brief Borra un evento
  * @param date fecha del evento a borrar
  * @return Void
  */
  void rm_event(int date);

/**
  * @brief Ordenar por fecha
  * @return Cronología ordenada
  */
  Chronology& sort();

/**
  * @brief Mezclar de forma ordenada dos cronologías
  * @param c cronología a mezclar con la implícita
  * @return cronología mezclada y ordenada
  */
  Chronology& merge(Chronology &c);

/** @brief Suma la cronología implícita con la que es pasada como argumento
  * @param chrono Cronología a sumar
  * @return Cronología suma de ambas
  */
  Chronology sum_chrono(const Chronology &chron2);

/**
  * @brief Eventos anteriores
  * @param d año a partir del cual se buscan los eventos
  * @return Vector con los eventos correspondientes
  */
  vector<HistoricEvent> prev_events(int d);

/**
  * @brief Eventos posteriores
  * @param d año a partir del cual se buscan los eventos
  * @return Vector con los eventos correspondientes
  */
  vector<HistoricEvent> post_events(int d);

/** @brief  Muestra todos los eventos situados entre dos fechas
  * @param inf Extremo inferior de la búsqueda
  * @param sup Extremo superior de la búsqueda
  * @return Void
  */
  void show_range(int inf, int sup);

/**
  * @brief Busca los eventos en que se encuentra la palabra dada.
  *        Además, puede mostrar dichos eventos   .
  * @param s palabra/s a buscar
  * @param be_shown si es true se mostrarán los eventos
  * @return Chronology con los eventos que contienen a s
  */
  Chronology word_search(const string &s, bool be_shown);

/**
  * @brief Sobrecarga del operator []
  * @param i Posición a devolver
  * return HistoricEvent en la posición i-ésima de event
  */
  HistoricEvent& operator[](unsigned int i) {return get_events()[i];};

/**
  * @brief Sobrecarga del operador <<
  * @param os flujo de salida
  * @param c cronología a mostrar
  * @return muestra una cronología con el formato:
  *         Year: date eventos
  */
  friend ostream& operator<<(ostream &os, const Chronology &c);

/**
  * @brief Sobrecarga del operador >>
  * @param is flujo de entrada
  * @param c cronología a escribir
  * @return flujo de entrada
  */
  friend istream& operator>>(istream &is, Chronology &c);
};

#endif
