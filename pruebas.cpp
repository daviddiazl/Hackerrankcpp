#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    int n, q;
    cout << "Escribe el indice y las consultas:";
    scanf("%d %d", &n, &q);

    int *index[n];

    for (int i = 0; i < n; i++)
    {
        int k = 0;
        cout << "\nEscribe el indice del array:";
        scanf("%d", &k);
        int *aanid = (int *)malloc(k * sizeof(int));
        for (int j = 0; j < k; j++)
        {
            int aux = 0;
            cout << "\nEscribe un valor del array:";
            scanf("%d", &aux);
            aanid[j] = aux;
        }
        index[i] = &aanid[0];
    }
    for (int i = 0; i < q; i++)
    {
        int ind, refe;
        cout << "\nIndice y consulta:";
        scanf("%d %d", &ind, &refe);
        printf("%d\n", *(index[ind] + refe));
    }
    for (int i = 0; i < n; i++)
    {
        free(index[i]);
    }
    */
   vector <int> vectorp;
   int a,b,c;
   a=0;
   b=1;
   c=7;
   vectorp.push_back(a);
   vectorp.push_back(b);
   vectorp.push_back(c);
   printf("el primer elemento es: %d \n el último elemento es: %d",vectorp[0],vectorp[2]);

    return 0;
}

/**
 Probar con malloc para reservar una parte de la memoria y que no se sobreescriban los arrays en el bucle
*/
