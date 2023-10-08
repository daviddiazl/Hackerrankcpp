#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    if(Fireball* f = dynamic_cast<Fireball*>(spell)){
        f->revealFirepower();
    }else if(Frostbite* fb = dynamic_cast<Frostbite*>(spell)){
        fb->revealFrostpower();
    }else if(Waterbolt* w = dynamic_cast<Waterbolt*>(spell)){
        w->revealWaterpower();
    }else if(Thunderstorm* t = dynamic_cast<Thunderstorm*>(spell)){
        t->revealThunderpower();
    }else{
        string s = spell->revealScrollName();
        string sFin = ""; // el nombre del spell reducido
        string r = ""; // representa la cadena del journal reducida
        string act = ""; //cadena actual 
        string maxL = "";
        //int cont = 0;
        //int contAux = 0;
        //int cont = 0;
        //int contAux = 0;

        for(int i = 0; i< SpellJournal::journal.size();i++){
            char jour = SpellJournal::journal[i];
            auto it = s.find(jour);
            if(it != string::npos){
                r = r+SpellJournal::journal[i];
            }
        }
        cout<<r<<endl;
        for(int i=0 ; i<s.size();i++){
            char sp = s[i];
            size_t it = r.find(sp);
            if(it !=string::npos){
                sFin = sFin + sp;
            }
        }
        cout<<sFin<<endl;

          for(int i = 0; maxL.size()<(sFin.size()-i);i++){ //antes ponia i<sFin.size()
            //cout<<i<<endl;
            int cont = 0;
            int contAux = 0;
            char c = sFin[i];
            vector<int> sStack; // se utiliza como pila para volver hacia atras luego con los char del hechizo
            vector<int> jStack; // para volver atras con los char del journal

            //PRIMERA CADENA
            while(cont<r.size() && c!=r[cont]){
                    cont++;
                }
                if(c==r[cont]){
                    act = act+c;
                    cont++;
                    contAux = cont;
                    sStack.push_back(i);//antes iba cont
                    int contI = cont; // contador interno que empieza donde este el contador externo
                    int contAuxI = contI;
                    jStack.push_back(contAuxI);
                    int goBack = i;
                    while(!sStack.empty()){
                        for(int j=goBack+1;j<sFin.size();j++){ //igual no es j=i+1 si no otra variable que al principio coge el valor de i pero luego el del stack
                            while(contI<r.size() && sFin[j]!= r[contI]){
                                contI++;
                            }
                            if(sFin[j]==r[contI]){
                                act = act + sFin[j];
                                //cout<<act<<endl;
                                sStack.push_back(j);
                                contI++;
                                contAuxI = contI;
                                jStack.push_back(contAuxI);
                            }else{
                                contI = contAuxI;
                                //cout<<contI<<endl;
                            }
                        }
                        cout<<act<<endl;
                        if(maxL.size()<act.size()){
                            maxL = act;
                        }
                        goBack = sStack.back();
                        sStack.pop_back(); //piede una iteracion el bucle en este momento
                        if(act.size()>1){
                            act.pop_back();
                        }else{
                            act = "";
                        }
                        jStack.pop_back();
                        contI = jStack.back();
                        contAuxI = contI;
                    } 

                }else{
                    cont = contAux;
                }     
            }
            cout<<maxL<< " "<<maxL.size()<<endl;
        }  
    }
    


class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}