#include "historic_event.h"

//Constructor por defecto
HistoricEvent::HistoricEvent() {
	set_date(0);											//Lo hacemos así porque al no existir
	 																	//el año 0 esto lo marcaria como año inválido
}

//Constructor
HistoricEvent::HistoricEvent(int d, const string& s) {
	set_date(d);
	add_befall(s);
}

//Constructor
HistoricEvent::HistoricEvent(int d, vector<string> v) {
	befalls = v;
	set_date(d);
}

//Borrar acontecimiento
void HistoricEvent::rm_befalls(string s) {
  int size = befalls_size();
  for(int i = 0; i < size; ++i){
    if(s.compare(befalls[i]) == 0){
      befalls.erase(befalls.begin()+i);
      --i;
      --size;
    }
  }
}

//Mostrar acontecimiento i-ésimo
void HistoricEvent::show(int i){
  cout << "Year: " << date << " "<< befalls[i] << endl;
}

//Buscar
bool HistoricEvent::search(const string &s, bool be_shown){
	bool find = false;
	int size = befalls_size();

	for(int i = 0; i < size; ++i)
		if (befalls[i].find(s) < befalls[i].size()) {
			find = true;

			if(be_shown)
				show(i);
		}

	return find;
}

//Operador ==
bool HistoricEvent::operator==(const HistoricEvent &h) {
   bool eq = ((date == h.date) && (befalls_size() == h.befalls_size())) ? true : false;

   for(unsigned int i = 0; i < befalls.size() && eq; ++i)
      if(befalls[i].compare(h.befalls[i]) != 0)   //compare devuelve 0 si son iguales
         eq = false;

   return eq;
}

// Operador +
HistoricEvent& HistoricEvent::operator+(const HistoricEvent &h) {
	if(date == h.date) {
		for(int i = 0; i < h.befalls_size(); ++i)
			if(!search(h.befalls[i],false))
				add_befall(h.befalls[i]);
	}
	return *this;
}
