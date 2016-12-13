#include "chronology.hpp"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]) {

  if (argc > 5) {
      cout << "El uso de este fichero es:" << endl;
      cout << "filtradoIntervalo <datos.txt> <año_inf> <año_sup> (<fichero_guardar.txt>)" << endl;

      return 0;
   }
  
   Chronology c, resultado;

   int inf = stoi(argv[2]);
   int sup = stoi(argv[3]);

   if(argc == 4) {
     c.date_filter(argv[1], inf, sup);
   }
   else {
     c.date_filter(argv[1], inf, sup, argv[4]);
   }

     return 0;
}
