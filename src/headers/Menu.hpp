#include <vector>
#include <string>

using namespace std;

class Menu{
  private:
    string ristorante;
    string nome;
  public:
    double prezzo;
    Menu(string r, string n, double p);
    Menu();
    virtual ~Menu();
    virtual string getDescrizione();
    double getPrezzo();
    string getNome();
};

class Menu_ayce :  Menu{
  public:
    const double penale_piatto;
    Menu_ayce(string r,string n, double p);
    virtual string getDescrizione();
    double getPrezzo();
};

class Menu_lavoro: Menu{
  public:
      vector<unsigned int> PiattiDisponibili;
      Menu_lavoro(string r,string n, double p, vector<unsigned int> numeri);
      virtual string getDescrizione();
      double getPrezzo();
};
