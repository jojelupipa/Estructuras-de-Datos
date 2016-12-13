#include <iostream>
#include "Pila_max.hpp"

using namespace std;

int main(){

  Pila_max<int> p;
  int i;

  for ( i=10; i>=0 ; i--)
    p.push(i);

  while (!p.empty() ){
    elemento<int> x = p.top();
    cout << x << endl;
    p.pop();
  }

  if (p.empty())                                          // Comprobamos el correcto funcionamiento de pop
    cout << "La pila ya se encuentra vacía :-)" << endl;

  return 0;
}
