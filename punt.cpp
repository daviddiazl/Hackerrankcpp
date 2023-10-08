#include <iostream>


using namespace std;

int main(){

    int* p[2];
    for(int i=0;i<2;i++){
        int k=0;
        cout<< "\nEscribe el indice del array:";
        scanf("%d",&k);
        int aanid[k];
        for(int j=0;j<k;j++){
            int aux=0;
            cout<<"\nEscribe un valor del array:";
            scanf("%d",&aux);
            aanid[j]=aux;
        }
        p[i]=aanid;
        cout<<*p[i]<<endl;
    }

    cout<<*p[0]<<" "<<*(p[1]);

    return 0;
}