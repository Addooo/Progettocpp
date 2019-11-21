#include <string>

using namespace std;

class Persona{
  private:
      string nome;
      string cognome;
  public:
      string cod_fisc;
      Persona(string n, string c, string cf);
      Persona();
      virtual ~Persona();
};

class Studente :public virtual Persona{
  protected:
    unsigned int cfu;
  public:
    Studente(string n, string c, string cf, unsigned int cfu);
};

class Lavoratore : public virtual Persona{
  protected:
    double stipendio;
  public:
    Lavoratore(string n, string c, string cf, double s);
};

class Studente_Lavoratore : public Lavoratore, public Studente {
  public:
    unsigned int pazienza;
    Studente_Lavoratore(string n, string c, string cf,unsigned int cfu, double s, unsigned int p);
};
