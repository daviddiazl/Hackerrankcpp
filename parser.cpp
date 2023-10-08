#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream> 
#include <algorithm>
using namespace std;

struct ATTR {
    string name;
    string value;

};

struct TAG {
    string name;
    vector<TAG*> sig;
    vector<ATTR*> attrs;

};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,q;
    int contags =0;
    vector<TAG*> tagsO; //open tags
    vector<TAG*> tagsR; //root tags
    vector<TAG*> tagsD; //delete tags
    scanf("%d %d",&n,&q);
    cin.ignore();

    /****PARTE DEL ANALISIS****/

    for(int i =0;i<n;i++){
        string line;
        int cont=1;
        int contA=0;
        getline(cin,line);
        cout << line <<endl;
        if((char)line[cont]!='/'){
            TAG* tag = new TAG;
            while((char)line[cont]!=' ' && (char)line[cont]!='>'){
                tag->name = tag->name + line[cont];
                cont+=1;  
                cout<< tag->name <<endl;
            }
            
            // Because if there are no attributes then we dont need to update the pointer
            if ((char)line[cont]==' '){
                cont+=1;
            }

            while((char)line[cont]!='>'){
                ATTR* atrr = new ATTR;
                //tag.attrs.push_back(atrr);
                while((char)line[cont]!=' '){
                    atrr->name = atrr->name + line[cont];
                    cont +=1;
                }
                cont = cont +4; //With this line the pointer goes right after the first " | antes estaba cont +=3  
                while((char)line[cont]!='"'){
                    atrr->value = atrr->value + line[cont];
                    cont+=1;
                }
                if((char)line[cont+1]==' '){
                    cont+=2;
                }else cont +=1;
                // antes era cont+=1
                contA+=1; // esto se puede quitar creo 
                cout<< atrr->name << endl;
                cout<< "patata" << endl;
                tag->attrs.push_back(atrr);
            }
            // parte donde se asigna el tag anterior del tag creado y se mete el tag a la lista de tags abiertos 
            if(tagsO.empty()){
                tagsO.push_back(tag);
                tagsR.push_back(tag);
                tagsD.push_back(tag);
                cout<< "Estoy aqui"<< endl; 
            }else{
                //TAG& tagAnt = *tagsO.back(); // es back()
                //tagAnt.sig.push_back(tag); // punto complicado 
                tagsO.back()->sig.push_back(tag);
                //const TAG tagAux = tagAnt;
                //tag.ant = &tagsO.back();
                tagsO.push_back(tag);
                tagsD.push_back(tag);
                cout << "El tag anterior es: " << tagsR.back()->name << " y su tag siguiente es: "<<tagsR.back()->sig.back()->name <<  endl;
            }
        }else{ 
            cont+=1;
            string tagName="";
            while((char)line[cont]!='>'){
                tagName = tagName + line[cont];
                cont+=1;  
            }

            //Var de f lambda que recoge por referencia nombre a buscar compara con nombre del tag 
            auto isTag = [&](TAG* aTag){
                return aTag->name == tagName;
            };

            //Busq de elem en vect 
            auto iterador = find_if(tagsO.begin(),tagsO.end(),isTag);

            if (iterador != tagsO.end()){

                tagsO.erase(iterador);

            }else{
                printf("El TAG que ha intentado cerrar no existe o ya ha sido cerrado anteriormente");
            }

        }
    }


    /****PARTE DE CONSULTAS****/
    for(int i =0;i<q;i++){
        TAG* tag = nullptr;
        ATTR* atr = nullptr; 
        string query;
        string search = "";
        string resp = "Not Found!";
        int cont=0;
        bool error = false;
        bool isAttr = false;

        //cin.ignore();
        getline(cin,query);
        cout<< query << endl;
        cout<< query.size()<< endl;
        cout<< query[0] << endl;

        /*SECCION PELIGROSA*/
        
        while((cont < query.size()) && ( error == false)){
            if(isAttr == false){
                if((query[cont] == '.') && (tag == nullptr)){ //El error tiene que estar en el puto tag null 

                    //Var de f lambda que recoge por referencia nombre a buscar compara con nombre del tag 
                    auto isTag = [&](TAG* aTag){
                        return aTag->name == search;
                    };

                    //Busq de elem en vect PARA MIRAR EN EL ROOT EN EL PRIMER TAG 
                    auto iterador = find_if(tagsR.begin(),tagsR.end(),isTag);

                    if (iterador != tagsR.end()){

                        tag = *iterador;

                        cout<<"Situacion 1 correcta, tag buscado: "<< search <<endl;

                    }else error = true;
                    search="";

                }else if ((query[cont] == '.'))
                {
                    /*LAMBDA SI HAY MAS DE UN TAG*/
                    auto isTag = [&](TAG* aTag){
                        return aTag->name == search;
                    };

                    auto iterador = find_if(tag->sig.begin(),tag->sig.end(),isTag);

                    if (iterador != tagsR.end()){

                        tag = *iterador;
                        cout<<"Situacion 2 correcta, tag buscado: "<< search <<endl;

                    }else error=true;
                    search="";


                }else if((query[cont] == '~') && (tag == nullptr)){

                    auto isTag = [&](TAG* aTag){
                        return aTag->name == search;
                    };

                    //Busq de elem en vect PARA MIRAR EN EL ROOT EN EL PRIMER TAG 
                    auto iterador = find_if(tagsR.begin(),tagsR.end(),isTag);

                    if (iterador != tagsR.end()){

                        tag = *iterador;
                        isAttr = true;
                        cout<<"Situacion 3 correcta, tag buscado: "<< search <<endl;

                    }else error = true;
                    search="";

                }else if ((query[cont] == '~'))
                {
                    /*LAMBDA SI HAY MAS DE UN TAG*/
                    auto isTag = [&](TAG* aTag){
                        return aTag->name == search;
                    };

                    auto iterador = find_if(tag->sig.begin(),tag->sig.end(),isTag);
                    cout<< "1 Llega aqui????"<< endl;
                    if (iterador != tag->sig.end()){
                        cout<< "2 Llega aqui????"<< endl;
                        tag = *iterador;
                        cout<< "3 Llega aqui????"<< endl;
                        isAttr = true;
                        cout<<"Situacion 4 correcta, tag buscado: "<< search <<endl;

                    }else {
                        error = true;
                        cout<< "4 Llega aqui????"<< endl;
                        }
                    search="";
                    
                }else{
                    search = search+ query[cont];
                    cout<< "Se va actualizando el search: "<< search << endl;
                }
            }else{
                search = search + query[cont];
                cout<< "Se va actualizando el search: "<< search << endl;

                /*SI ES EL ULTIMO VALOR*/
                if(cont == query.size()-1){

                   /*LAMBDA PARA ATRIBUTO*/
                    auto isAttrib = [&](ATTR* atr){
                        return atr->name == search;
                    };

                    /*BUSQUEDA DE ATRIBUTO*/
                    auto iterador = find_if(tag->attrs.begin(),tag->attrs.end(),isAttrib);

                    if (iterador != tag->attrs.end()){
                        
                        atr = *iterador;
                        resp = atr->value;
                        cout<<"Situacion 5 correcta, tag buscado: "<< search <<endl;


                    }else error = true;

                }
            }
            cont +=1;
            
        }
        /*ACABA SECCION PELIGROSA*/
        cout<< "5 Llega aqui????"<< endl;
        cout<< resp<< endl;
    }

    cout<< "Hey: " <<tagsD.size() << endl;
    //cout<< tagsD[0]->name << tagsD[1]->name << tagsD[2]->name<<endl;

    /*SECCIÓN DE CERRAR PUNTEROS*/

   /* for(int i = tagsD.size()-1;i>=0;i--){
        cout << tagsD[i]->name << endl;
        for(int j = tagsD[i]->attrs.size()-1;i>=0;i--){
            cout<< j << endl;
            cout << tagsD[i]->attrs[j]->name << endl;
            delete tagsD[i]->attrs[j];
        }
        delete tagsD[i];
        cout<< i << endl;
    }
    tagsD.clear();
    */
    for(TAG* tag : tagsD){
        cout << tag->name << endl;
        for(ATTR* atr : tag->attrs){
            cout<< atr->name <<endl;
            delete atr;
        }
        tag->attrs.clear();
        delete tag;
    }
    tagsD.clear();


    return 0;
}