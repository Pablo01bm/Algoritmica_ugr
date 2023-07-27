#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<double> C, S;
int n = 0;

int seleccionarSiguiente(double pesoRestante){
    bool cabe = false;
    int pos = -1;
    
    for (int i = 0; i < C.size() && !cabe; i++)
        if (C[i] <= pesoRestante ){
            pos = i;
            cabe = true;
        }
    return pos;
}

int funcionGreedy(){

    int recipientes = 1, posObjeto;
    double restante_actual = 1;

    while( !C.empty() ){
        
        posObjeto = seleccionarSiguiente(restante_actual);   

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
        cerr << "Error en el numero de argumentos. Ejecucion: ./recipientes_greedy_2 <nombre_fichero>" << endl;
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