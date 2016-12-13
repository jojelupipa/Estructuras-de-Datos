/*
 * Prueba de la funcionalidad estadísticas
 */
 


#include "chronology.hpp"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]) {

  if (argc != 2) {
    cout << "Sintaxis incorrecta. Introduzca el nombre del archivo donde se encuentra la cronología a leer únicamente" << endl;
    return 0;
  }

  Chronology c;

  c.stats(argv[1]);

  return 0;
}
