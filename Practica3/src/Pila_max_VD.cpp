/**
  * @file Pila_max_VD.cpp
  * @brief Implementación del TDA pila_max haciendo uso de vectores dinámicos
  */


  /*__________________PARTE_PRIVADA__________________________________________*/

  // Máximo

  template <class T>
  T Pila_max<T>::max(const T &max_act, const T &elem_nuevo){

    if (max_act < elem_nuevo)
    return elem_nuevo;

    else
    return max_act;

  }

  // Resize

  template <class T>
  void Pila_max<T>::resize(int size){
    assert(size > 0);

    elemento<T> *nuevo;
    nuevo = new elemento<T>[size];

    for(int i = 0; i < n_elem && i < size; ++i)   // En caso de que queramos "reducir" el espacio disponible añadimos que i < size
      nuevo[i] = v_elem[i];

    delete [] v_elem;
    v_elem = nuevo;

    n_disp = size;                              // Indicamos el número de elementos reservados actual

  }


  /*__________________PARTE_PÚBLICA_________________________________________*/

// Constructores

  template <class T>
  Pila_max<T>::Pila_max(const Pila_max &p){

    n_elem = p.n_elem;
    n_disp = p.n_disp;
    v_elem = new elemento<T> [n_disp];

    for (int i = 0; i < n_elem; ++i){

      v_elem[i] = p.v_elem[i];
    }
  }


// Destructor

  template <class T>
  Pila_max<T>::~Pila_max(){

    delete [] v_elem;
    n_elem = 0;
    n_disp = 0;
  }



// Push

  template <class T>
  void Pila_max<T>::push(const T &dato){

    elemento<T> nuevo;
    nuevo.ele = dato;

    if (n_elem > 0)
      nuevo.max = max(v_elem[n_elem-1].max, dato);      // Comparamos el máximo del último elemento insertado con el valor del actual

    else if (n_elem == 0)
      resize(1);
      nuevo.max = dato;

    if(n_elem < n_disp){

      v_elem[n_elem] = nuevo;
      n_elem++;
    }

    else{

      resize(n_disp*2);
      v_elem[n_elem] = nuevo;
      n_elem++;

    }
  }


  // Pop

  template <class T>
  void Pila_max<T>::pop(){

    assert(!empty());

    n_elem--;
  }

  // Empty(ness inside)

  template <class T>
  bool Pila_max<T>::empty(){

    if (n_elem == 0)
      return true;

    else
      return false;
  }

  // Top

  template <class T>
  elemento<T> Pila_max<T>::top(){
    assert(!empty());
      return v_elem[n_elem-1];
  }


  // Operator =

  template <class T>
  Pila_max<T>& Pila_max<T>::operator= (const Pila_max &p){

    n_elem = p.n_elem;
    n_disp = p.n_disp;
    v_elem = new elemento<T> [n_disp];

    for (int i = 0; i < n_elem; ++i){

      v_elem[i] = p.v_elem[i];
    }

    return *this;
  }
