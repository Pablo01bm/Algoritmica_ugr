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

vector<int> depurar_registros(vector<int> v){
    vector <int> salida;
    bool repetido = false;
    int elemento;

    /* Se compara un elemento del vector pasado como parámetro (vector aleatorio con elementos
       repetidos) con los elementos del vector que se está construyendo */
    for(int i = 0; i < v.size(); i++){

        repetido = false;
        elemento = v[i];
        
        /* Recorremos el vector de salida para comproobar si ya hemos insertado el elemento.
           En ese caso, se sale del bucle for y no lo inserta de nuevo. */
        for(int j = 0; j < salida.size() && !repetido; j++)    
            //Comprobamos si en algun momento hay un elemento repetido. 
            if(elemento == salida[j]) 
                repetido = true;
            
        //Si el elemento no se encuentra ya en salida, no está duplicado por lo que lo añadimos al vector de salida.
        if(!repetido)
            salida.push_back(elemento);
    
    }
    return salida;

}


int main(int argc, char * argv[]){
    
    vector<int> lista, v_entrada;
    clock_t tini, tdesp;
    int elemento = 0, tam = 0;
    fstream fs;
    
    fs.open(argv[1]);    

    while(!fs.eof()){
        fs >> elemento;
        v_entrada.push_back(elemento);  
    }

    fs.close();
    
    tam = v_entrada.size();

    //Medimos el tiempo que tarda el algoritmo.
    tini = clock();   
    lista = depurar_registros(v_entrada); 
    tdesp = clock();

    cout<< tam << " " <<((double)(tdesp-tini))/CLOCKS_PER_SEC<<endl;

}


