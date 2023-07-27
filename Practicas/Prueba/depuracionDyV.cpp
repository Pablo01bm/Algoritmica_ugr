#include <iostream>
#include <string>
#include <ctime>
#include <vector>
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
inline static void quicksort(vector<int> &T, int num_elem);

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
inline static void insercion(vector<int> &T, int num_elem);

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
static void dividir_qs(vector<int> &T, int inicial, int final, int &pp);

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
	for (i = inicial + 1; i < final; i++)
	{
		j = i;
		while ((T[j] < T[j - 1]) && (j > 0))
		{
			aux = T[j];
			T[j] = T[j - 1];
			T[j - 1] = aux;
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
	if (final - inicial < UMBRAL_QS)
	{
		insercion_lims(T, inicial, final);
	}
	else
	{
		dividir_qs(T, inicial, final, k);
		quicksort_lims(T, inicial, k);
		quicksort_lims(T, k + 1, final);
	};
}

static void dividir_qs(vector<int> &T, int inicial, int final, int &pp)
{
	int pivote, aux;
	int k, l;

	pivote = T[inicial];
	k = inicial;
	l = final;
	do
	{
		k++;
	} while ((T[k] <= pivote) && (k < final - 1));
	do
	{
		l--;
	} while (T[l] > pivote);
	while (k < l)
	{
		aux = T[k];
		T[k] = T[l];
		T[l] = aux;
		do
			k++;
		while (T[k] <= pivote);
		do
			l--;
		while (T[l] > pivote);
	};
	aux = T[inicial];
	T[inicial] = T[l];
	T[l] = aux;
	pp = l;
};

vector<int> combinarSoluciones(vector<int> v_izq, vector<int> v_dcha){

	vector<int> v_salida;
	int inicio_bucle = 0;
	bool introducir = true;
	
	//Copiamos el vector izq en el vector de salida
	v_salida = v_izq;

	/* Si el elemento final de v_izq es igual al primer elemento de v_dcha
	hacemos que el bucle comience en el siguiente elemento */
	if(v_izq[ v_izq.size() - 1 ] == v_dcha[0])
		inicio_bucle = 1;
	
	/* Añadimos al vector de salida todos los elementos de v_dcha */
	for (int i = inicio_bucle; i < v_dcha.size(); i++)
		v_salida.push_back(v_dcha[i]);

	return v_salida;
}

vector<int> depurarRegistrosRecursiva(vector<int> v_inicial, int pos_ini, int pos_fin){

	vector<int> v_salida, v_dcha, v_izq;

	//Si v_inicial es de tamaño = 1 se devuelve un vector de una sola posicion
	if (pos_fin == pos_ini){
		v_salida.push_back(v_inicial.at(pos_ini));
		return v_salida;
	}
	//Si v_inicial es de tamaño = 2 se compara si esta dos posiciones son iguales
	if ((pos_fin - pos_ini) == 1){
		//Si son iguales se devuelve un vector de una sola posicion
		if (v_inicial.at(pos_ini) == v_inicial.at(pos_fin))
			v_salida.push_back(v_inicial.at(pos_ini));

		//Si son distintos se devuelve un vector con las dos posiciones
		else{
			v_salida.push_back(v_inicial.at(pos_ini));
			v_salida.push_back(v_inicial.at(pos_fin));
		}
	}

	/* Si v_inicial es de tamaño > 2 se llama recursivamente al algoritmo, dividiendo el
	problema en dos */
	else{

		int mitad = (pos_fin - pos_ini) / 2 + pos_ini;

		//Llamamos a la funcion depurar registros con la parte izquierda de v_inicial
		v_izq = depurarRegistrosRecursiva(v_inicial, pos_ini, mitad);

		//Llamamos a la funcion depurar registros con la parte derecha de v_inicial
		v_dcha = depurarRegistrosRecursiva(v_inicial, mitad + 1, pos_fin);

		//Combinamos los dos vectores (ambos no tienen elementos repetidos)
		v_salida = combinarSoluciones(v_izq, v_dcha);
	}

	return v_salida;
}

vector<int> depurarRegistros(vector<int> v){
	quicksort(v, v.size());
	return depurarRegistrosRecursiva(v, 0, v.size() - 1);
}

int main(int argc, char *argv[]){

	vector<int> v_entrada, v_salida;
	clock_t t_ini, t_fin;
	fstream fe;
	fe.open(argv[1]);
	int elemento;

	while (!fe.eof()){
		fe >> elemento;
		v_entrada.push_back(elemento);
	}

	fe.close();

	int tam_entrada = v_entrada.size();

	t_ini = clock();
	v_salida = depurarRegistros(v_entrada);
	t_fin = clock();

	cout << tam_entrada << " " << ((double)(t_fin - t_ini)) / CLOCKS_PER_SEC << endl;

}