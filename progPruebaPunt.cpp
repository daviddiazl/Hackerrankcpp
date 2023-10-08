#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream> 
#include <algorithm>
using namespace std;

struct prueba{
    string nombre;
    vector<prueba> pruebas; 
};

int main(){
   /* vector<prueba> pCreadas;
    prueba pS;
    pS.nombre = "PruebaSecundaria";
    for(int i = 0; i<10; i++){
        prueba p;
        p.nombre = "prueba"+ to_string(i);
        pCreadas.push_back(p);
    }

    prueba& pP = pCreadas.back();
    pP.pruebas.push_back(pS);

    if(not pCreadas.empty()){
        if(not pCreadas.back().pruebas.empty()){
            const prueba pAux1 = pCreadas.back();
            const prueba pAux2 = *pAux1.pruebas.begin();
            cout<< pAux2.nombre<<endl;
        }else{
            cout<< "El vector de la ultima prueba está vacío" << endl;
        }
    }else{
        cout<< "El vector pCreadas esta vacio"<<endl;
    }

    */
    vector<prueba*> v1;
    vector<prueba*> v2;

    prueba pS;
    prueba pT;
    pS.nombre = "PruebaSecundaria";
    pT.nombre = "PruebaTerciaria" ;

    for(int i = 0; i<10; i++){
        prueba p;
        p.nombre = "prueba"+ to_string(i);
        v1.push_back(&p);
        v2.push_back(&p);
    }

    v1.push_back(&pT);

    prueba& pP = *v1.back();
    pP.pruebas.push_back(pS);
    cout<<"Antes de la catastrofe"<< endl;
    /*cout<< "El nombre del ultimo valor en v1 es: "<< v1.back()->nombre << " y su siguiente es: " << v1.back()->pruebas.begin()->nombre << endl;
    cout<< "El nombre del ultimo valor en v2 es: "<< v2.back()->nombre << " y su siguiente es: " << v2.back()->pruebas.begin()->nombre << endl;
*/

    cout<< "El nombre del ultimo valor en v1 es: "<< v1.back()->nombre << endl;
    cout<< "El nombre del ultimo valor en v2 es: "<< v2.back()->nombre << endl;

    //prueba* iterador = v1.back();
    //delete iterador;
    v1.pop_back();

    cout<<"Despues de la catastrofe"<<endl;
    cout<< "El nombre del ultimo valor en v2 es: "<< v2.back()->nombre << " y su siguiente es: " << v2.back()->pruebas.begin()->nombre << endl;

    prueba* iterador2 = v2.back();
    delete iterador2;
    v1.pop_back();

    return 0;
}