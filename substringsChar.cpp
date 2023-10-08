#include <bits/stdc++.h>
#include <vector>
#include <set>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'ashtonString' function below.
 *
 * The function is expected to return a CHARACTER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */

char ashtonString(string s, int k) {
    set<string> vs;
    vector<char> usados;
    //vector<int> pos; // veremos si lo quitamos esto o no 
    string total = "";
    string result = "";
    int cont = 0; 
    
    /*CREAR CADENA AUXILIAR*/
    while(cont<k){
        vector<int> pos;
        char c = s[0]; 
        /*ESCOGER CARACTER*/
        for(int i = 1; i<s.length(); i++){//si tarda mucho este metodo es posible que sea optimizado
            if(s[i]<c){
                auto it = find(usados.begin(),usados.end(),s[i]);
                if(it== usados.end()){
                    c = s[i];
                    cout<<c<<endl;
                    cout<<cont<<endl;
                }
            }
        }
        //cout<<"C: "<<c<<endl;
        usados.push_back(c);
        /*COGER IND DE CHAR SELEC*/
        for(int i=0; i<s.length(); i++){
            if(s[i]==c){
                pos.push_back(i);
                //cout<<"indice"<<i<<endl;
            }
        }
        /*ORDENAR INDICES*/
        /*
        for(int i = 0; i<pos.size(); i++){
            int aux;
            for(int j = i+1; j<pos.size(); j++){
                int contPos = 0;
                while(s[pos[i]+contPos]==s[pos[j]+contPos]){
                    contPos++;
                    //cout<<"llegue aqui"<<contPos<<endl;
                }
                //cout<<"Aqui si"<<endl;
                if(s[pos[i]+contPos]>s[pos[j]+contPos]){
                    aux = pos[i];
                    pos[i] = pos[j];
                    pos[j] = aux;
                }
            }
        }
        */
        /*RECOGER SUBCADENAS*/
        for(int i : pos){
            total = s[i];
            //cout<<"pos"<<i<<endl;
        //cout<<total<<endl;
        //vs.push_back(total);
            for(int j = i ; j<=s.length(); j++ ){
                vs.insert(total);
                cont = cont + total.length();
                total = total + s[j];
                //cout<<cont<<endl;
            }
        }



    }
    for(int i = 0; i<vs.size();i++){
        auto it = vs.begin();
        advance(it,i);
        result = result + *it;
    }
    cout<<result<<endl;
    return result[k-1];

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string k_temp;
        getline(cin, k_temp);

        int k = stoi(ltrim(rtrim(k_temp)));

        char res = ashtonString(s, k);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}