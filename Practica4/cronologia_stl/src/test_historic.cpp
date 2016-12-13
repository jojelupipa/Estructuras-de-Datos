#include <iostream>
#include "historic_event.hpp"

using namespace std;

int main () {

  cout << "Prueba de la clase evento histórico: \n" << "Prueba constructores:" << endl;
                                      // PROBAMOS CONSTRUCTORES
  set<string> set_strines;
  set_strines.insert("hola");
  set_strines.insert("adios");
  pair<int, set<string> > p(2014, set_strines);
  
  HistoricEvent vacio, fecha_string(1621,"Lamiamamma"), fecha_set(2048, set_strines), pair(p), copia(fecha_string);

// Mostramos lo mostrable
  cout << "Debería mostrar: 1621#Lamiamamma\nDebería mostrar: 2048#hola#adios\n";
  cout << "Muestra:\n";

  cout << fecha_string << endl;
  cout << fecha_set << endl;
  
  cout << "Comprobamos el funcionamiento del constructor copia:\n";

  cout << copia << endl;

  cout << "Comprobamos el funcionamiento de constructor(pair)" << endl;

  cout << pair << endl;

  // Probamos get_date
  cout << "Probamos get_date()  (En fecha_set) :" << endl;
  cout << fecha_set.get_date() << endl;

  // Probamos get_befalls (creamos un nuevo objeto a partir del set de strings de fecha_set, pero con otro año) 
  HistoricEvent prueba_get_befalls(2222,fecha_set.get_befalls()); 

  cout << "Probamos get_befalls():" << endl;
  cout << prueba_get_befalls << endl;

  //Probamos befalls_size()

  cout << "Que tiene un tamaño de: " << endl;
  cout << prueba_get_befalls.befalls_size() << endl;

  // Probamos setdate()

  cout << "Vamos a cambiarle la fecha a 1111: " << endl;

  prueba_get_befalls.set_date(1111);

  cout << prueba_get_befalls << endl;

  // Probamos add_befalls() (añadir un acontecimiento)

  cout << "Añadimos un acontecimiento, \"cositaquepasó\":" << endl;
  prueba_get_befalls.add_befall("cositaquepasó");
  cout << prueba_get_befalls << endl;


  // Probamos rm_befall(string)

  cout << "Lo que la vida te da, la vida te lo quita, borramos \"cositaquepasó\":" << endl;

  prueba_get_befalls.rm_befall("cositaquepasó");

  cout << prueba_get_befalls << endl;
  

  // Probamos search(string)
  cout << "Probamos si encontramos la cadena \"hola\", y \"patitos\" en este prueba_get_befalls\n¿Hay patitos? ";
  if (prueba_get_befalls.search("patitos"))
    cout << " Sí :D" << endl;
  else
    cout << " NO HAY PATITOS :___" << endl;

  cout << "¿Habrá al menos alguien que salude y diga \"hola\"? ";

  if (prueba_get_befalls.search("hola"))
    cout << " Sí, menos da una piedra :/" << endl;
  else
    cout << "Tampoco, matarme ya por la yuyee" << endl;


  //Probamos get_coincidences			
  HistoricEvent prueba_coincidences(prueba_get_befalls.get_coincidences("hola"));

  cout << "Si get_coincidences(string) funciona, esta Chronology debería mostrar \"hola\"" << endl;

  cout << prueba_coincidences << endl;

  // Probamos el operador ==

  cout << "Los HistoricEvents (deberían decir que no son iguales pues tienen distinta fecha) tienen: " << endl;

  cout << "fecha_set: " << fecha_set << endl;
  cout << "prueba_get_befalls: " << prueba_get_befalls << endl;
  
  
  if (prueba_get_befalls == fecha_set)
    cout << "Los vectores fecha_set y prueba_get_befalls son iguales" << endl;
  else
    cout << "Los vectores fecha_set y prueba_get_befalls no son iguales" << endl;

  
  if (fecha_set == fecha_set)
    cout << "Los vectores fecha_set y fecha_set son iguales" << endl;
  else
    cout << "Los vectores fecha_set y fecha_set son distintos (ESTO ES MALO)" << endl;

  // Probamos el operador + (y de paso el = que no lo hemos sobrecargado)

  HistoricEvent suma, sumando1(2048,"string") ;
  

  suma = fecha_set + sumando1;

  cout << "El operador suma debería devolver un HistoricEvent con el año 2048 y con los acontecimientos: hola, adios y string" << endl;

  cout << suma << endl;


  // Probamos operador de lectura
  HistoricEvent evento_leido;

  ifstream input("evento_prueba.txt");
  cout << "is_open: " <<input.is_open()<< endl;
  //input.open("./evento_prueba.txt", std::ifstream::in);

  if(input.is_open())
    input >> evento_leido;
  //cout << "Insertar evento: año#string#...#string" << endl;
  //cin >> evento_leido;
   else
    cout << "Error en la apertura de evento_prueba.txt. TIENE QUE EXISTIR ESE FICHERO" << endl;

  cout << evento_leido << endl;
  
  
  return 0;
}
