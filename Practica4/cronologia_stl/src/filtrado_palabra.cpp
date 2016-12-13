/*
 * Prueba de la funcionalidad filtro por palabra
 */
 


#include "chronology.hpp"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]) {

  if (argc != 3) {
    cout << "Sintaxis incorrecta. Argumentos: <palabra_a_buscar> <fichero_lectura>" << endl;
    return 0;
  }

  Chronology t;
  Chronology mi_cronologia(t.word_filter(argv[1],argv[2])); // Como es un método tenemos que tener un objeto Chronolgy para poder usarlo en el constructor, aunque sea vacío


  cout << mi_cronologia << endl;

  return 0;
}
  
