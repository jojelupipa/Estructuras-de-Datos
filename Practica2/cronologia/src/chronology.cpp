#include "chronology.h"

//Constructor por defecto
Chronology::Chronology() {

}

//Constructor copia
Chronology::Chronology(const Chronology &chrono) {
  event = chrono.get_events();
}

//Constructor
Chronology::Chronology(vector<HistoricEvent> h) : event(h) {}

//Obtener vector de befalls
vector<string> Chronology::get_befalls(int date){
  int size = event.size();
  bool found = false;
  vector<string> befalls_found;

  for(int i = 0; i < size && !found; ++i)

    if(event[i].get_date() == date){
      befalls_found = event[i].get_befalls();
      found = true;
    }

  return befalls_found;
}

//Insertar acontecimiento
bool Chronology::InsertBefall(int date, const string &s) {
  bool insert = false;
  int var_date;
	int size = event.size();

	if (size > 0) {
	  for(int i = 0; i < size && !insert; ++i) {
	    var_date = event[i].get_date();

			if (var_date > date) {
	      HistoricEvent e(date, s);
				event.push_back(e);
			  insert = true;
			}
	    else if (var_date == date){
				if (!(event[i].search(s,false))) {
					event[i].add_befall(s);
					insert = true;
	    	}
	    }
	  }
	}

	else {
		HistoricEvent e(date, s);
		event.push_back(e);
		insert = true;
	}

  return insert;
}

//Insertar evento
bool Chronology::InsertEvent(const HistoricEvent &h) {
  int date = h.get_date();
  vector<string> v = h.get_befalls();
  int size = v.size();
  bool insert = false;

	for(int i = 0; i < size; ++i)
    insert = InsertBefall(date,v[i]);

	return insert;
}

//Borrar evento
void Chronology::rm_event(int date) {
  int size = event.size();
  bool rm = false;

  for(int i = 0; i < size && !rm; ++i)
    if(date == event[i].get_date()) {
      event.erase(event.begin()+i);
      rm = true;
    }
}

//Ordenar por fecha
Chronology& Chronology::sort() {    //mergesort
   if (event.size() > 1) {
      Chronology cl, cr;
      int middle = event.size() / 2;
      for(int i = 0; i < middle; ++i)
         cl.InsertEvent(event[i]);

      int size = event.size();
      for(int i = middle; i <= size; ++i)
         cr.InsertEvent(event[i]);

      cl = cl.sort();
      cr = cr.sort();

      if(cl[cl.event.size()] < cr[0]) {
         int cr_size = cr.event.size();
         //inserta en la posición final de cl desde el principio hasta el final de cr
         for(int i = 0; i < cr_size; ++i) {
            cl.event.push_back(cr.event[i]);
         }
         *this = cl;
      }
      else
         *this = cl.merge(cr);
   }

   return *this;
}

//Mezclar dos cronologías
Chronology& Chronology::merge(Chronology &c) {
   while(event.size() > 0 && c.event.size() > 0)
      if(event.begin() < c.event.begin()) {
         (*this).InsertEvent(event[0]);
         rm_event(event[0].get_date());
      }
      else {
         (*this).InsertEvent(c.event[0]);
         c.rm_event(c.event[0].get_date());
      }

   if(event.size() > 0)
      (*this).event.insert((*this).event.end(),event.begin(),event.end());
   if(c.event.size() > 0)
      (*this).event.insert((*this).event.end(),c.event.begin(),c.event.end());
   return *this;
}

//Sumar dos cronologías
Chronology Chronology::sum_chrono(const Chronology &chron2){
  vector<HistoricEvent> v;
  int size_chron1 = event.size();
  int size_chron2 = chron2.event.size();

  for(int i = 0; i < size_chron1; ++i){
    v.push_back(event[i]);
  }

  for(int i = 0; i < size_chron2; i++){
    v.push_back(chron2.event[i]);
  }

  Chronology result(v);
  result.sort();

  return result;
}

//Eventos anteriores
vector<HistoricEvent> Chronology::prev_events(int d) {
   vector<HistoricEvent> result;
   sort();

   int i = 0;
   while(event[i].get_date() < d)  {
      result.push_back(event[i]);
      ++i;
   }

   return result;
}

//Eventos posteriores
vector<HistoricEvent> Chronology::post_events(int d) {
   vector<HistoricEvent> result;
   sort();

   int i = event.size();
   while(event[i].get_date() > d) {
      result.push_back(event[i]);
      i--;
   }

   return result;
}

//Eventos en un rango
void Chronology::show_range(int inf, int sup) {
  if (inf > sup)
    std::swap(inf,sup);
  int size = event.size();
  int befalls_size;

  for(int i = 0; i < size; ++i){                                        // Comprueba si la fecha de cada HistoricEvent
    if (event[i].get_date() >= inf && event[i].get_date() <= sup) {    // es correcta y procede a mostrar su contenido
      befalls_size = event[i].befalls_size();

      for(int j = 0; j < befalls_size; i++)
         event[i].show(j);

    }
   }
}

//Buscar una palabra
Chronology Chronology::word_search(const string &s, bool be_shown) {
   Chronology c;
   int size = event.size();

   for(int i = 0; i < size; ++i)
      if(event[i].search(s,0))
         c.InsertEvent(event[i]);

   if(be_shown) {
      cout << c;
   }

   return c;
}


// Operador <<
ostream& operator<<(ostream &os, const Chronology &c) {
  int size = c.event.size();
  int n_befalls;

  for(int i = 0; i < size; ++i) {
     os << c.event[i].get_date();
     n_befalls = c.event[i].befalls_size();
     for(int j = 0; j < n_befalls; ++j) {
        os << '#' << c.event[i].get_befalls()[j] << endl;
     }
     os << endl;
  }

  return os;
}

//Operador >>
//BUG: solo se lee el primer año.
istream& operator>>(istream &is, Chronology &c) {
  int d, size, j;
	char* s = new char[1024];
  vector<string> v;
	const char DELIM = '#';
	char ch;
	string st;

  while(is) {
     is >> d;

		 is.getline(s, 1024);
		 string aux (s);
     size = aux.size();
     j = 0;
		 v.push_back(st);

     for(int i = 0; i < size; ++i) {
			 ch = aux[i];
		   v[j].push_back(ch);

			 if(v[j][v[j].size()-1] == DELIM) {
				 v[j].pop_back();
				 ++j;
				 v.push_back(st);
       }
     }

     HistoricEvent h(d, v);
     c.InsertEvent(h);
  }

	delete[] s;
  return is;
}
