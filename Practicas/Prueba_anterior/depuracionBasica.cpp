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

/* ************************************************************ */ 
/*  M�todo de ordenaci�n r�pida  */

/**
   @brief Ordena un vector por el m�todo quicksort.

   @param T: vector de elementos. Debe tener num_elem elementos.
             Es MODIFICADO.
   @param num_elem: n�mero de elementos. num_elem > 0.

   Cambia el orden de los elementos de T de forma que los dispone
   en sentido creciente de menor a mayor.
   Aplica el algoritmo quicksort.
*/
inline static 
void quicksort(vector<int> &T, int num_elem);



/**
   @brief Ordena parte de un vector por el m�todo quicksort.

   @param T: vector de elementos. Tiene un n�mero de elementos 
                   mayor o igual a final. Es MODIFICADO.
   @param inicial: Posici�n que marca el incio de la parte del
                   vector a ordenar.
   @param final: Posici�n detr�s de la �ltima de la parte del
                   vector a ordenar. 
		   inicial < final.

   Cambia el orden de los elementos de T entre las posiciones
   inicial y final - 1 de forma que los dispone en sentido creciente
   de menor a mayor.
   Aplica el algoritmo quicksort.
*/
static void quicksort_lims(vector<int> &T, int inicial, int final);


/**
   @brief Ordena un vector por el m�todo de inserci�n.

   @param T: vector de elementos. Debe tener num_elem elementos.
             Es MODIFICADO.
   @param num_elem: n�mero de elementos. num_elem > 0.

   Cambia el orden de los elementos de T de forma que los dispone
   en sentido creciente de menor a mayor.
   Aplica el algoritmo de inserci�n.
*/
inline static 
void insercion(vector<int> &T, int num_elem);


/**
   @brief Ordena parte de un vector por el m�todo de inserci�n.

   @param T: vector de elementos. Tiene un n�mero de elementos 
                   mayor o igual a final. Es MODIFICADO.
   @param inicial: Posici�n que marca el incio de la parte del
                   vector a ordenar.
   @param final: Posici�n detr�s de la �ltima de la parte del
                   vector a ordenar. 
		   inicial < final.

   Cambia el orden de los elementos de T entre las posiciones
   inicial y final - 1 de forma que los dispone en sentido creciente
   de menor a mayor.
   Aplica el algoritmo de inserci�n.
*/
static void insercion_lims(vector<int> &T, int inicial, int final);


/**
   @brief Redistribuye los elementos de un vector seg�n un pivote.

   @param T: vector de elementos. Tiene un n�mero de elementos 
                   mayor o igual a final. Es MODIFICADO.
   @param inicial: Posici�n que marca el incio de la parte del
                   vector a ordenar.
   @param final: Posici�n detr�s de la �ltima de la parte del
                   vector a ordenar. 
		   inicial < final.
   @param pp: Posici�n del pivote. Es MODIFICADO.

   Selecciona un pivote los elementos de T situados en las posiciones
   entre inicial y final - 1. Redistribuye los elementos, situando los
   menores que el pivote a su izquierda, despu�s los iguales y a la
   derecha los mayores. La posici�n del pivote se devuelve en pp.
*/
static void dividir_qs(vector<int> &T, int inicial, int final, int & pp);



/**
   Implementaci�n de las funciones
**/


inline static void insercion(vector<int> &T, int num_elem)
{
  insercion_lims(T, 0, num_elem);
}


static void insercion_lims(vector<int> &T, int inicial, int final)
{
  int i, j;
  int aux;
  for (i = inicial + 1; i < final; i++) {
    j = i;
    while ((T[j] < T[j-1]) && (j > 0)) {
      aux = T[j];
      T[j] = T[j-1];
      T[j-1] = aux;
      j--;
    };
  };
}


const int UMBRAL_QS = 50;


inline void quicksort(vector<int> &T, int num_elem)
{
  quicksort_lims(T, 0, num_elem);
}

static void quicksort_lims(vector<int> &T, int inicial, int final)
{
  int k;
  if (final - inicial < UMBRAL_QS) {
    insercion_lims(T, inicial, final);
  } else {
    dividir_qs(T, inicial, final, k);
    quicksort_lims(T, inicial, k);
    quicksort_lims(T, k + 1, final);
  };
}


static void dividir_qs(vector<int> &T, int inicial, int final, int & pp)
{
  int pivote, aux;
  int k, l;

  pivote = T[inicial];
  k = inicial;
  l = final;
  do {
    k++;
  } while ((T[k] <= pivote) && (k < final-1));
  do {
    l--;
  } while (T[l] > pivote);
  while (k < l) {
    aux = T[k];
    T[k] = T[l];
    T[l] = aux;
    do k++; while (T[k] <= pivote);
    do l--; while (T[l] > pivote);
  };
  aux = T[inicial];
  T[inicial] = T[l];
  T[l] = aux;
  pp = l;
};

/*

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

*/

//FUNCION DEPURAR SIMPLE

vector<int> depurar_registros(vector<int> v){
 vector <int> nuevo;
 bool norepetido = true;
 int t=0;
 int repetido;

    /* Se compara un elemento del vector pasado como parámetro 
       (vector aleatorio con elementos repetidos) con los 
       elementos del vector que se está construyendo. */
    for(int j=0; j < v.size(); j++){
        repetido = v[j];

        for(int k=0; k < nuevo.size() && norepetido; k++){
           
        /* Comprobamos si en algun momento hay un elemento repetido, 
           se sale del bucle for */
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
    fstream fs;
    fs.open(argv[1]);    
    vector<int> lista; 
    clock_t tini, tdesp;
   
    int pos;
    vector <int> v_entrada;
    
    while(!fs.eof()){
        fs >> pos;
        v_entrada.push_back(pos);  
    }
    fs.close();
    int tam = v_entrada.size();
    quicksort(v_entrada, v_entrada.size());
    tini = clock();
    
    

    lista = depurar_registros(v_entrada);

    tdesp = clock();
    
    cout<< tam << " " <<((double)(tdesp-tini))/CLOCKS_PER_SEC<<endl;
}


