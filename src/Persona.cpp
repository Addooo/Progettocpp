#include <iostream>
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
      virtual ~Persona(){
        cout << "Elimino tutto [Persona] " << cod_fisc << " " << this << endl;
        nome = "0";
        cognome = "0";
        cod_fisc = "0";
      }
};
Persona::Persona(string n, string c, string cf) : nome(n), cognome(c), cod_fisc(cf){};
Persona::Persona():nome("0"),cognome("0"),cod_fisc("0"){};
class Studente : public virtual Persona{
  protected:
    unsigned int cfu;
  public:
    Studente(string n, string c, string cf, unsigned int cfu);
};
Studente::Studente(string n, string c, string cf, unsigned int cfu) : Persona(n,c,cf), cfu(cfu){}

class Lavoratore : public virtual Persona{
  protected:
    double stipendio;
  public:
    Lavoratore(string n, string c, string cf, double s);
};
Lavoratore::Lavoratore(string n, string c, string cf, double s) : Persona(n,c,cf), stipendio(s){};

class Studente_Lavoratore : public Lavoratore, public Studente {
  public:
    unsigned int pazienza;
    Studente_Lavoratore(string n, string c, string cf,unsigned int cfu, double s, unsigned int p);
};
Studente_Lavoratore::Studente_Lavoratore(string n, string c, string cf,unsigned int cfu, double s, unsigned int p) : Persona(n,c,cf), Lavoratore(n,c,cf,s),Studente(n,c,cf,cfu){
    this->pazienza = p;
/*    this->cfu = cfu;
    this->stipendio = s;*/
}
