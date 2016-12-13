template <class T>
//Añadir un elemento a la pila
void Pila_max<T>::push(const T &dato) {
   elemento<T> e;
   e.ele = dato;
   //Arreglamos el máximo
   if (pila.vacia())
      e.max = dato;
   else
      if (pila.frente().max > dato)
         e.max = pila.frente().max;
      else
         e.max = dato;

   //Añadimos el elemento al principio
   Cola<elemento<T> > aux;
   aux.poner(e);
   while(!pila.vacia()) {
      aux.poner(pila.frente());
      pila.quitar();
   }
   pila = aux;
}

template <class T>
//Sobrecarga operador =
Pila_max<T>& Pila_max<T>::operator=(const Pila_max<T> &p) {
   pila = p.pila;
   return *this;
}
