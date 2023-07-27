#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <ctime>
#include <cmath>
#include <fstream>
using namespace std;

//FUNCION DEPURAR SIMPLE

vector<int> depurar_registros(vector<int> v){
 vector <int> nuevo;
 bool norepetido = true;
 int t=0;

    int repetido;
//Se compara un elemento del vector pasado como parámetro (vector aleatorio con elementos repetidos) con los elementos del vector que se está construyendo
    for(int j=0; j < v.size(); j++){
        repetido = v[j];

        for(int k=0; k < nuevo.size() && norepetido; k++){
           
        //Comprobamos si en algun momento hay un elemento repetido, se sale del bucle for 
            if(repetido == nuevo[k]){  
                norepetido = false;
            }else{
                t++;
            }
        }
        //Añade el elemento no repetido en el vector 
        if(t==nuevo.size()){
            nuevo.push_back(repetido);
        }
        norepetido = true;
        t=0;
    }
    return nuevo;

}



////////////////////////////////////////////////////////////

int main(int argc, char * argv[])
{
 vector<int> lista; 
 clock_t tini, tdesp;
 int n=argc-1;

  vector <int> v_entrada;

  for (int i=1; i < argc; i++){
       v_entrada.push_back(atoi(argv[i]));  
  }

tini = clock();
 
lista=depurar_registros(v_entrada);

tdesp = clock();

cout<< n << " " <<((double)(tdesp-tini))/CLOCKS_PER_SEC<<endl;

}


