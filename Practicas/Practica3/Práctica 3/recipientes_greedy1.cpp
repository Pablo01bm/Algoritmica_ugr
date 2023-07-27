#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<double> C, S;
int n = 0;

int seleccionarMayorPesoQueCabe(double pesoRestante){
    //En el caso de que no haya un objeto que quepa
    int pos = -1;
    double maximoPeso = 0;
    for(int i = 0; i < C.size(); i++)
        if(C[i] <= pesoRestante && C[i] >= maximoPeso){
            pos = i;
            maximoPeso = C[i];
        }
        //Si hay un objeto que cabe y tiene mayor peso del que se habia guardado, se reemplaza.            
    return pos;
}

int funcionGreedy(){

    int recipientes = 1, posObjeto;
    double restante_actual = 1;

    while( !C.empty() ){ //Mientras quedan candidatos (Funcion solución)
        
        posObjeto = seleccionarMayorPesoQueCabe(restante_actual); //Función selección

        if(posObjeto != -1){
            restante_actual -= C[posObjeto];
            S.push_back(C[posObjeto]);
            C.erase(C.begin() + posObjeto);
        }
        else{
            recipientes++;
            restante_actual = 1;
        }     

    }       

    return recipientes; 
    
}

int main(int argc, char *argv[]){

    if(argc != 2){
        cerr << "Error en el numero de argumentos. Ejecucion: ./recipientes_greedy_1 <nombre_fichero>" << endl;
    }

    clock_t t_ini, t_fin;
    int recipientesUsados = 0, numeroRecipiente = 1;
    double pesoRestante = 1, elemento;
    
    fstream fe;
	fe.open(argv[1]);

	while (!fe.eof()){
		fe >> elemento;
		C.push_back(elemento);
	}

    n = C.size()-1;

    cout << "Vector inicial: " << endl;
    for (int i = 0; i < C.size(); i++)
        cout << C[i] << " ";
    cout << endl;

    t_ini = clock();
    recipientesUsados = funcionGreedy();
    t_fin = clock();

    cout << n << " " << ((double)(t_fin - t_ini)) / CLOCKS_PER_SEC << endl;
    cout << "Recipientes: " << recipientesUsados << endl;
    cout << "La distribucion es: " << endl;
    for (int i = 0; i < S.size(); i++){
        if(S[i] <= pesoRestante)
            pesoRestante -= S[i];
        else{
            pesoRestante = 1 - S[i];
            numeroRecipiente++;
        } 
        cout << S[i] << " en recipiente " << numeroRecipiente << endl;
    } 
    cout << " " << endl;
}