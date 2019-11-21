#include <iostream>
#include <string>
#include <map>
#include <list>
#include <cstdlib>
#include "headers/Menu.hpp"
#include "headers/Persona.hpp"
#include "headers/Ordine.hpp"

#define RISTORANTE "SushiMix"
#define MAX_PERSONE 10
#define MAX_ORDINI_GENERATI 10

using namespace std;

void creapiatti(map<unsigned int,string>&);
void generaPersone(list<Persona*>&);

int main(void)
{
  map<unsigned int,string> piatti;
  creapiatti(piatti);
  srand(time(NULL)); // così è sempre casuale
  //map<std::pair<int,int>, int> myMap;
 /// Menu *m = new Menu("SUMO","Menu",20.4);
  //cout << "è il getPrezzo (prova)" << m->getPrezzo() <<endl;
 // Menu_ayce *m2 = new Menu_ayce("SUMO","ALL YOU CAN EAT",20.90);
//  cout << m2->getDescrizione() << endl;

  vector<unsigned int> n;
 // n.push_back(2u);
 // n.push_back(4u);
 // n.push_back(6u);
 // Menu_lavoro *m3 = new Menu_lavoro("SUMO","Pranzo di lavoro",10.90,n);

  //list<Persona*> c;
  //generaPersone(c);
  //list<Persona*> c2;
  //generaPersone(c2);

  Ordine *o;// = new Ordine((Menu*)m2,c,1); //,piatti
  //delete o;
//  o = new Ordine((Menu*)m2,c2,1); //,piatti
  //delete o;
//    cout<<"ecco: "<<endl;
//  Ordine *o2;// = new Ordine((Menu*)m3,c2,2);
  //  cout << *o << endl << *o2 << endl;

  unsigned int n_ord = 0;
  char scelta;
  vector<Ordine*> o_v;
  unsigned int k = 1;
  Ordine *sum = NULL;
  do{

    cout << "SUPER SUSHI RESTAURANT" << endl;
    cout << "1 - Simula il ristorante" << endl;
    cout << "2 - Visualizza Totale ordini" << endl;
    cout << "3 - Cancella tutto" << endl;
    cout << "4 - Esci " << endl;
    cin >> scelta;
    if( sum == NULL)
    {
      delete sum;
      sum = NULL;
    }
    cout << "\033[2J\033[1;1H";//per pulire la console
    switch(scelta)
    {
      case '1':{ //SIMULA
        //simula il ristorante
        //-genera lista di persone casuali
        //-scelta a caso tra all you can eat e Lavoro
        //-fai vedere i vari ordini che arrivano
          n_ord = rand()%MAX_ORDINI_GENERATI + 1;
          //cout << "[" << n_ord << "]" << endl;
          for(int i = 0; i < n_ord; i++){
            //genera persone a caso
            list<Persona*> persone;
            generaPersone(persone);
            //genera menu a caso
            if( rand()%2 > 0.5){
              Menu_ayce* m_ayce = new Menu_ayce(RISTORANTE, "ALL YOU CAN EAT", 20.90);
              o = new Ordine((Menu*)m_ayce,persone,i + k);
            }
            else
            {
                Menu_lavoro* m_l = new Menu_lavoro(RISTORANTE, "Menù LAVORO", 10.90,n);
                o = new Ordine((Menu*)m_l,persone,i + k);
            }
            //metti tutto in ordine
            cout << "Ordine - >" << (i + k) << "FATTO" << endl;
            o_v.push_back(o);
        }
        k = k + n_ord ;
      }
        break;
      case '2':{ //VISUALIZZA
        //visualizza i vari ordini e poi il totale dei prezzi
        bool primo = true ;
        for(vector<Ordine*>::iterator it = o_v.begin(); it != o_v.end(); ++it){
          cout << *(*it) << endl;
          if(primo){//se è il primo non somma gli ordini
            sum = (*it);
            primo = false;
        }
        else//somma gli ordini
            sum = *sum + *(*it);
        }
        if(!primo)//se non c'è stato un solo ordine visualizza
          cout << *sum << endl;
        }
        break;
      case '3':{ // cancella gli ordini
        for(vector<Ordine*>::iterator it = o_v.begin(); it != o_v.end(); ++it)
          delete *it;
        o_v.clear();
        k = 1;
        }
        break;
      case '4'://esce dal programma
        cout << "FINE" << endl;
        break;
      default:
        break;
    }
  }while(scelta != '4');
    return 0;
}

void creapiatti(map<unsigned int,string>& piatti )
{

  unsigned int n_elem = 6;//numero di piatti
  string nomi_piatti[n_elem] = {"Sushi misto", "Futo maki fritto", "Pollo al limone", "Sashimi", "Chirashi", "Nigiri"};

  unsigned int i = 0;
  while(i < n_elem){//inserisce all'interno della map
      piatti.insert(make_pair((i+1),nomi_piatti[i]));
      i++;
    }

}

void generaPersone(list<Persona*>& p)
{
  unsigned int n_r = 10;
  string nomi[n_r] = {"Marco","Luca","Giovanna","Francesco","Sara","Vale","Matteo","Roberto","Ale","Luisa"};
  string cognomi[n_r] = {"Rossi","Verdi","Adobati","Oldani","Sabato","Paris","Brandolini","Singh","Rota","Manzoni"};
  unsigned int n_p = rand()%MAX_PERSONE + 1 ,n = 2 ,c = 2;
  Persona* ins;
  for(int i = 0; i < n_p; i++) //generazione di persone in modo pseudocasuale
  {
    n = rand()%n_r; c = rand()%n_r;
    if( i % 3)
      ins = new Studente(nomi[n],cognomi[c],nomi[n].substr(0,3)+cognomi[c].substr(0,3),i*2);
    else{
       if(i % 2)
        ins = new Lavoratore(nomi[n],cognomi[c],nomi[n].substr(0,3)+cognomi[c].substr(0,3),i*250);
       else
        ins = new Studente_Lavoratore(nomi[n],cognomi[c],nomi[n].substr(0,3)+cognomi[c].substr(0,3),i*2,i*200,10);
     }
     p.push_back(ins);
  }

}
