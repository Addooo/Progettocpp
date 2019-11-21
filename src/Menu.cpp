#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Menu{
  private:
    string ristorante;
    string nome;
  public:
    double prezzo;
    Menu(string r,string n, double p);
    Menu();
    virtual ~Menu(){
      nome = "0";
      prezzo = 0;
      cout << "Elimino tutto [Menù]" << endl;
    }
    virtual string getDescrizione(){
      string desc;
      desc = "Questo è la descrizione generica del menù di un ristorante giapponese: viva il sushi";
      return desc;
    }
    double getPrezzo();
    string getNome();
};
Menu::Menu(string r,string n, double p) : ristorante(r), nome(n),prezzo(p){};
Menu::Menu(){
    ristorante = "";
    nome = "";
    prezzo = 0.0;
}
double Menu::getPrezzo(){
  return this->prezzo;
}
string Menu::getNome(){
  return this->nome;
}


class Menu_ayce : Menu{
  public:
      const double penale_piatto = 5.0;
      Menu_ayce(string r, string n, double p);
      virtual string getDescrizione(){
      string desc  = "Questo è la descrizione generica del menù ALL YOU CAN EAT di un ristorante giapponese: se non finisci il cibo la penale è " + to_string(penale_piatto) + " euro";
      return desc;
    }
    double getPrezzo();
};
Menu_ayce::Menu_ayce(string r, string n, double p) : Menu(r,n,p){};
double Menu_ayce::getPrezzo(){//getPrezzo ha un'accisa per mostrare la ridefinizione del metodo
  double accisa = 2.0;
  return this->prezzo + accisa;
}

class Menu_lavoro: Menu{
  public:
      vector<unsigned int> PiattiDisponibili;
      Menu_lavoro(string r, string n, double p, vector<unsigned int> numeri);
      virtual string getDescrizione(){
        string desc = "Questo è la descrizione generica del menù \"Pranzo di Lavoro\"  di un ristorante giapponese: pare che lavori quindi dacci i $$$";
              return desc;
      }
      double getPrezzo();
};
Menu_lavoro::Menu_lavoro(string r, string n, double p, vector<unsigned int> numeri) : Menu(r,n,p){
  PiattiDisponibili = numeri;
}
double Menu_lavoro::getPrezzo(){//qua invece c'è lo sconto puramente allo scopo di mostrare che il metodo viene ridefinito
  double sconto_menu_non_esoso = -2.5;
  return this->prezzo + sconto_menu_non_esoso;
}
