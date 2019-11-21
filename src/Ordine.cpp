#include <iostream>
#include <list>
#include <map>
#include "headers/Persona.hpp"
#include "headers/Menu.hpp"

using namespace std;

class Ordine{
  private:
      double guadagno;
  public:
    Menu *m;
    list<Persona*> clienti;
    unsigned int n_ord;
    Ordine(Menu* m, list<Persona*> c, unsigned int n_ord);

    virtual ~Ordine(){
      cout << "Distruggo l'ordine " << n_ord << endl;
      n_ord = 0;
      delete m;
      while(!clienti.empty())
      {
        cout << " Richiamo il delete della persona " << clienti.front() << endl;
        clienti.pop_front();
      }
    };
    double getGuadagno();
    Ordine* operator +(Ordine& o);
    friend ostream& operator<<(ostream& output, const Ordine& o);
};
Ordine::Ordine(Menu* m, list<Persona*> c, unsigned int n_ord)
{
  this->m = m; // questi sono overloading degli operatori già fatti
  this->clienti = c; // questi sono overloading degli operatori già fatti
  this->n_ord = n_ord;
  this->guadagno = this->clienti.size() * this->m->getPrezzo();
}

double Ordine::getGuadagno()
{
    return this->guadagno;
}

Ordine* Ordine::operator+(Ordine& o)
{
  Menu *m_final = new Menu("RistSomma","Somma",(this->m->getPrezzo()*this->clienti.size() + o.m->getPrezzo()*o.clienti.size() )/(this->clienti.size() + o.clienti.size()) );//ci mette il prezzo medio
  unsigned int n = 0;
  unsigned int DIM = this->clienti.size() + o.clienti.size();
  list<Persona*> tot_pers;
  Persona *P = new Persona[DIM];
  unsigned int i = 0;

  for(list<Persona*>::iterator it = this->clienti.begin(); it != this->clienti.end(); ++it)P[i++] = **it;
  for(list<Persona*>::iterator it = o.clienti.begin(); it != o.clienti.end(); ++it)P[i++] = **it;

//  cout<<"per creare il nuo vett " << endl;
  for(i = 0 ; i < DIM ; i++){
    tot_pers.push_back(P);
  //  cout << P->cod_fisc << "   " << P << endl;
    P++;
  }
  //cout<< "----------" << endl;
  Ordine *ris = new Ordine(m_final, tot_pers,n);

  return ris;
}

ostream& operator<<(ostream& output, const Ordine& o){
  output << "Questo è l'ordine " << o.n_ord << endl;
  output << "Questo è un menù " << o.m->getNome() << ", questo è il prezzo (medio) del menù " << o.m->getPrezzo() << endl;
  output << "Questi sono stati tutti i clienti: " << "(" << o.clienti.size() << ")" <<endl;
  list<Persona*> app = o.clienti;
      for(list<Persona*>::iterator it = app.begin(); it != app.end(); ++it)
    output << (*it)->cod_fisc << " "<<*it <<endl;
  output << "Guadagno totale " << o.guadagno << endl;
  return output;
}
