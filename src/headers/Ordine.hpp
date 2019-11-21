#include <iostream>
#include <list>
#include <map>
//#include "Persona.hpp"

using namespace std;


class Ordine{
  private:
    double guadagno;
  public:
    Menu* m;
    list<Persona*> clienti;
    unsigned int n_ord;
    map<pair<unsigned int,string>, int> piatti;
    Ordine(Menu* m, list<Persona*> c, unsigned int n_ord);
    virtual ~Ordine();
    double getGuadagno();
    //ridefinizione degli operatori + e << 
    Ordine* operator +(Ordine& o);
    friend ostream &operator<<(ostream& output, const Ordine& o);
};
