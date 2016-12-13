#include "chronology.hpp"

// Constructor
Chronology::Chronology(vector<HistoricEvent> h) {
  int size = h.size();
  for(int i = 0; i < size; ++i) {
    events.insert(pair<int, HistoricEvent> (h[i].get_date(), h[i]));
  }
}

HistoricEvent Chronology::get_date_events(const int date) {
  HistoricEvent h;

  Chronology::const_iterator c_it = events.find(date);
  return (*c_it).second;  
}

// Obtener vector de befalls
set<string> Chronology::get_befalls(int date) {
  Chronology::const_iterator c_it = events.find(date);
  return (*c_it).second.get_befalls();
}

// Insertar acontecimiento
void Chronology::insert_befall(int date, const string &s) {
  Chronology::iterator it = events.find(date);

  //Si la fecha ya está, añadimos el string 
  if (it != end()) {
    (*it).second.add_befall(s);
  }
  else {
    HistoricEvent h(date, s);
    events.insert(pair<int, HistoricEvent> (h.get_date(), h));
  }
}

// Insertar evento
void Chronology::insert_event(const HistoricEvent &h) {
  Chronology::iterator it = events.find(h.get_date());

  if(it == events.end()) {
    events.insert(pair<int, HistoricEvent> (h.get_date(), h));
  }
  else {
    //Si la fecha ya está, unimos los dos eventos
    (*it).second + h;
  }
}

// Borrar evento
void Chronology::rm_event(int date) {
  //Solo se ejecutará si hay un evento con esa fecha
  Chronology::iterator it;
  if ((it = events.find(date)) != end()) {
    events.erase(it);
  }
}

//Eventos anteriores
Chronology Chronology::prev_events(int d) {
  Chronology result;
  Chronology::const_iterator tope = events.find(d);
  Chronology::const_iterator c_it;

  for(c_it = events.begin(); c_it != tope; ++c_it) {
    result.insert_event((*c_it).second);
  }
  
  return result;
}

// Eventos posteriores
Chronology Chronology::post_events(int d) {
  Chronology result;
  Chronology::const_iterator c_it;
   
  for(c_it = events.find(d); c_it != events.end(); ++c_it) {
    result.insert_event(c_it->second);
  }

  return result;
}

// Eventos en un rango
Chronology Chronology::range(int inf, int sup) {
  if (inf > sup)
    std::swap(inf,sup);
  Chronology result;
  Chronology::const_iterator bot = events.find(inf);
  Chronology::const_iterator top = events.find(sup);
  Chronology::const_iterator c_it;

  if (bot->first != inf) {
    for (c_it = events.cbegin(); c_it != events.cend() && c_it->first - inf < 0 && c_it->first < sup; ++c_it);
    bot = c_it;
  }

  if (top->first != sup) {
    for (c_it = --(events.cend()); c_it != events.cbegin() && c_it->first - sup > 0 && c_it->first > inf; --c_it);
    top = c_it;
  }
    
  if (bot->first <= sup && top->first >= inf) {
    if (bot != top) {
      for (c_it = bot; c_it != top; ++c_it)
	result.insert_event(c_it->second);
    }
    result.insert_event(top->second);
  }
    
  return result;
}

// Buscar una palabra
Chronology Chronology::word_search(const string &s) {
  Chronology result;
  HistoricEvent aux;
  Chronology::const_iterator c_it;

  for(c_it = cbegin(); c_it != cend(); ++c_it) 
    if((*c_it).second.search(s)) {
      aux = (*c_it).second.get_coincidences(s);//IMPLEMENTAR EN HISTORICEVENT
      result.insert_event(aux);
    }
	
  return result;
}

// FUNCIONALIDADES EXTRA

// Unión cronologías
void concat_chron(string input_1, string input_2, string output) {

  Chronology chron1, chron2, chron3;

  ifstream file1, file2;

  file1.open(input_1);
    
  if (file1.is_open()) {				 
    file1 >> chron1;	
    file1.close();
  }
  else
    cout << "No se pudo leer el archivo " << input_1 << endl;

  file2.open(input_2);

  if (file2.is_open()) {
    file2 >> chron2;
    file2.close();
  }
  else
    cout << "No se pudo leer el archivo " << input_2 << endl;

  chron3 = chron1 + chron2; 

  ofstream file3;

  file3.open(output);
    
  if (file3.is_open()) {
    file3 << chron3;
    file3.close();
  }
  
  else
    cout << "No se pudo abrir el archivo " << output << endl;
}

// Filtro por palabras
Chronology Chronology::word_filter(const string& word, const string& in) {

  Chronology chron, result;
  ifstream input;

  input.open(in);
    
  if (input.is_open()) {
    input >> chron;
    input.close();
  }
  else{
    cout << "Error en la apertura del fichero " << in << endl;
    exit(0);
  }
  
  result = chron.word_search(word);
  return result;
}


// Filtro por fecha versión salida fichero
void Chronology::date_filter(const string& filein, const int& lower, const int& upper, const string& fileout) {

  Chronology chron;
  ifstream in;

  in.open(filein);
    
  if (in.is_open()) {
    in >> chron;
    in.close();
  }
  else
    cout << "Error en la apertura del fichero " << filein << endl;

  chron = chron.range(lower, upper);

  ofstream out;

  out.open(fileout);
    
  if (out.is_open()) {
    out << chron;
    out.close();
  }
  else
    cout << "Error en la apertura del fichero " << fileout << endl;
}


// Filtro por fecha versión salida estándar
void Chronology::date_filter(const string& filein, const int& lower, const int& upper) { 
 
  Chronology chron;
  ifstream in;

  in.open(filein);
    
  if (in.is_open()) {
    in >> chron;
    in.close();
  }
  else
    cout << "Error en la apertura del fichero " << filein << endl;
    
  chron = chron.range(lower, upper);
    
  cout << chron;
}

// Estadísticas 
void Chronology::stats(const string& filename) {

  ifstream in;
  Chronology chron;

  in.open(filename);
  
  if (in.is_open()) {
    in >> chron;
    in.close();
  }
  else{
    cout << "Error en la apertura de " << filename << endl;
    exit(0);
  }
  
  double total_years = 0;
  double total_befalls = 0, mean_befalls; // Total de eventos y promedio de eventos/año

  Chronology::const_iterator c_it;

  total_years = chron.events.size();
  
  for(c_it = chron.cbegin(); c_it != chron.cend(); ++c_it) 
    total_befalls += (*c_it).second.befalls_size();
  
  mean_befalls = total_befalls / total_years;
  
  cout << "Hay un total de " << total_befalls << " ocurridos en " << total_years << " años\nEsto hace una media de " << mean_befalls << " eventos/año" << endl;
  
}

//Sobrecarga operador +
Chronology& Chronology::operator+(const Chronology &c) {
  Chronology::const_iterator c_it;
  
  for(c_it = c.events.begin(); c_it != c.events.end(); ++c_it) {
    (*this).insert_event((*c_it).second);
  }
  
  return *this;
}

// Operador =
Chronology& Chronology::operator=(const Chronology &c) {
  events = c.events;
  return *this;
}

// Operador <<
ostream& operator<<(ostream &os, const Chronology &c) {
  Chronology::const_iterator c_it;
    
  for(c_it = c.events.begin(); c_it != c.events.end(); ++c_it) {
    os << (*c_it).second; 		// Este operador deberá escribir la fecha seguido de todos los acontecimientos separados por #
  }

  os << endl;

  return os;
}

// Operador >>
istream& operator>>(istream &is, Chronology &c) {
  string buffer;  

  while(!is.eof()) {
    HistoricEvent h;
    is >> h;
    c.insert_event(h);
  }
  
  return is;
}

