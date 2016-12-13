#include <iostream>
#include "historic_event.h"
using namespace std;

int main () {

  cout << "Prueba de la clase evento histórico: \n" << "Prueba constructores:\n" << endl;
                                      // PROBAMOS CONSTRUCTORES
  vector<string> vector_strines;
  vector_strines.push_back("hola");
  vector_strines.push_back("adios");
  HistoricEvent vacio, fecha_string(1621,"Lamiamamma"),fecha_vector(2048, vector_strines);

// Mostramos lo mostrable

  fecha_string.show(0);
  fecha_vector.show(0);
  fecha_vector.show(1);

// Probamos get_date()
  int fecha_fechastrin = fecha_string.get_date();

  cout << "La fecha de fecha_string (\"Lamiamamma\") es: " << fecha_fechastrin << endl;


// Probamos get_befalls();
  vector<string> test_get_befalls = fecha_vector.get_befalls();
  cout << "Test_get_befalls (prueba de get_befalls) devuelve un vector que contiene: " << test_get_befalls[0] << "  " << test_get_befalls[1] << endl;

// Probamos befalls_size()
  cout << "El HistoricEvent vacío tiene (prueba de befalls_size): " << vacio.befalls_size() << endl;

// Probamos set_date(int)
  fecha_string.set_date(9667);
  cout << "La fecha de fecha_string es ahora: " << fecha_string.get_date() << " (Prueba de  setdate)" << endl;

  // Probamos add_befall y rm_befalls

  fecha_vector.rm_befalls("hola");
  cout << "Eliminamos \"hola\" del HistoricEvent con hola y adios y mostramos cual es el nuevo elemento primero (prueba rm_befalls): " << endl;
  fecha_vector.show(0);

  fecha_vector.add_befall("yanosaludo");
  cout << "Ahora para probar add_befall mostramos el segundo elemento de fecha_vector: " << endl;
  fecha_vector.show(1);

  // Prueba search(string, bool)

  cout << "Ahora vamos a comprobar si \"o\" lo podemos encontrar en la cadena, y si sí lo mostraremos" << endl;

  if (fecha_vector.search("o",true))
    cout << "Encontrado y mostrado" << endl;

// Prueba de operador ==

  HistoricEvent igual_1(1000,"igual"), igual_2(1000,"igual"), desigual(1000,"desigual");

  if(igual_1 == igual_2)
    cout << "Probado con == que son iguales \"gual_1(1000,\"igual\"), igual_2(1000,\"igual\");\"" << endl;
  else
    cout << "No son iguales (== usado)" << endl;

  if(!(igual_1 == desigual))
    cout << "\"desigual(100,\"desigual\")\" e igual_1 son distintos" << endl;

  // Probamos < y >

  if(fecha_vector < igual_1)
    cout << "fecha_vector sucedió antes que los acontecimientos de igual_1" << endl;
  else if (fecha_vector > igual_1)
    cout << "fecha_vector sucedió después que igual_1" << endl;

    fecha_vector.show(0);
    igual_1.show(0);

  // Probamos el operador +

  HistoricEvent suma;
  suma = desigual + igual_1;

  cout << "Probamos a sumar desigual e igual_1 y lo mostramos en un Evento suma" << endl;

  vector<string> test_sum = suma.get_befalls();
  for(int i = 0; i < test_sum.size(); ++i) // Probamos si puede mostrar todos los Eventos de suma
    suma.show(i);

  return 0;
}
