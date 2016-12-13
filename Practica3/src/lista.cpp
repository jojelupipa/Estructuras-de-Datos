template <class T>
Lista<T>::Lista() {
	Celda<T>* aux = new Celda<T>;
	cabecera = aux;
	aux->ant = 0;
	aux->sig = 0;
}


template <class T>
/*NOTE:recordadme que ponga el algoritmo algo mas fino si sobra tiempo, este es la version simple*/
Lista<T>::Lista(const Lista& p) {
	cabecera->ant = cabecera->sig = 0; /*Esta linea de codigo se realiza para poder usar sin problemas la
	                                    función push;*/
	for (Celda<T>* q = p.cabecera->sig; q != cabecera; p = p->sig){
		push(p->dato.ele);
	}
}

template <class T>
Lista<T>& Lista<T>::operator= (const Lista& p){
	if (this != &p) {
		while (cabecera->ant) {
			pop();
		}

		for (Celda<T>* q = p.cabecera->sig; q != cabecera; p = q->sig){
			push(q->dato.ele);
		}
	}

	return this;
}

template <class T>
void Lista<T>::push(const T& y) {
	if (cabecera->ant != 0) {
		Celda<T>* aux = new Celda<T>;
		aux->ant = cabecera->ant;
		cabecera->ant->sig = aux;
		cabecera->ant = aux;
		aux->sig = cabecera;

		aux->dato.ele = y;
		T x = (aux->ant->dato.max);
		aux->dato.max = (y>x ? y : x);
	}

	else {
		Celda<T>* aux = new Celda<T>;
		aux->ant = aux->sig = cabecera;
		cabecera->ant = cabecera->sig = aux;
		aux->dato.ele = aux->dato.max = y;
	}
}

template <class T>
void Lista<T>::pop () {
	if (cabecera->ant) {
		Celda<T>* aux = cabecera->ant;
		cabecera->ant = cabecera->ant->ant;
		delete aux;
	}
	if (cabecera->ant == cabecera) {
		cabecera->ant = cabecera->sig = 0;
	}
}

template <class T>
Lista<T>::~Lista () {
	while (cabecera->ant) {
		pop();
	}
	delete cabecera;
}
