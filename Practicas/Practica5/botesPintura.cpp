#include <iostream>
#include <climits>
#include <vector>

using namespace std;

void mejorK ( const vector<vector<int>> &K, int tipo, int volumen, vector<int> &solucion, const vector<int> &litros, int tipos){
    int volAct = volumen - K[tipo][volumen] * litros[tipo];
    solucion[tipo] = K[tipo][volumen];

    if (tipo > 0)
        mejorK(K, tipo - 1, volAct, solucion, litros, tipos);
    
}

pair<int, vector<int>> coste( int tipos, int Volumen, vector<int> unidades, vector<int> costes, vector<int> litros ){
    vector<vector<int>> Coste(tipos);
    vector<vector<int>> MejorK(tipos);
    pair<int, vector<int>> solucion;
    solucion.second = vector<int>(tipos);
    int coste = INT_MAX;

    for(int i = 0; i < Coste.size(); i++)
        Coste[i] = vector<int>(Volumen + 1, -1);

    for(int i = 0; i < MejorK.size(); i++)
        MejorK[i] = vector<int>(Volumen + 1, 0);
    
    //Caso base j=0 && i>0 => Coste = 0 -> funciona
    for (int i = 0; i < tipos; i++)
        Coste[i][0] = 0;


    //Caso base i=0 && j>0 => Coste = k * c[i] -> funciona

    for (int j = 1; j <= Volumen; j++){
        Coste[0][j] = INT_MAX;
        if (unidades[0] * litros[0] >= j){
            for (int k = 1; k <= unidades[0]; k++){
                if(k * litros[0] >= j)
                    coste = k * costes[0];
                else    
                    coste = INT_MAX;

                if ((Coste[0][j] > coste)){
                    Coste[0][j] = coste;
                    MejorK[0][j] = k;
                }
                    
            }
        }
    }
    int sumaLitros = unidades[0] * litros[0];
    
    for (int i = 1; i < Coste.size(); i++){
        sumaLitros += unidades[i] * litros[i];
        for(int j = 1; j <= Volumen; j++){
            Coste[i][j] = INT_MAX;
            if (sumaLitros > j){
                for(int k = 0; k <= unidades[i]; k++){
                    if(k * litros[i] > j)
                        coste = Coste[i - 1][j];
                    else
                        coste = Coste[i - 1][j - k * litros[i]] + k * costes[i];
                    if (Coste[i][j] > coste){
                        Coste[i][j] = coste;
                        MejorK[i][j] = k;
                    }        
                }
            }
        }

    }

     for(int i = 0; i < tipos; i++){
        for(int j = 0; j <= Volumen; j++)
            cout << Coste[i][j] << "\t";
        cout << endl;
    }
    cout << endl ;

    for(int i = 0; i < tipos; i++){
        for(int j = 0; j <= Volumen; j++)
            cout << MejorK[i][j] << "\t";
        cout << endl;
    } 
    
    solucion.first  = Coste[tipos - 1][Volumen];
    mejorK(MejorK, tipos - 1, Volumen, solucion.second, litros, tipos);
    
    return solucion;    
}

int main(int argc, char *argv[]){ 

    if(argc < 3){
        cout << "Uso: ./" << argv[0] << " <Número de tipos de recipientes> <Volumen> (<Random>)" << endl;
        exit(-1);
    }

    int tipos = atoi(argv[1]);
    int volumen = atoi(argv[2]);
    bool random = false; 
    if (argc == 4)
        random = true;
    
    vector<int> unidades(tipos);
    vector<int> costes(tipos);
    vector<int> litros(tipos);

    if(random){
        srand(time(NULL));
        for (int i = 0; i < tipos; i++){
            litros[i]= rand() % volumen + 1;
            unidades[i]= rand() % litros[i] + 1;
            costes[i]= rand() % litros[i] * 2 + 1;
        }  
    }
    else{
        for(int i = 0; i < tipos; i++){
            cout << "Litros[" << i+1 << "] = ";
            cin >> litros[i]; 
            cout << "Unidades[" << i+1 << "] = ";
            cin >> unidades[i]; 
            cout << "Costes[" << i+1 << "] = ";
            cin >> costes[i]; 
        }
    }

    for(int i = 0; i < tipos; i++){
            cout << "Unidades[" << i+1 << "] = " << unidades[i] << "\t";
            cout << "Costes[" << i+1 << "] = " << costes[i] << "\t";
            cout << "Litros[" << i+1 << "] = " << litros[i] << endl;
    }
    
    pair<int, vector<int> > solucion = coste(tipos, volumen, unidades, costes, litros);
    
    cout << "Mejor Coste = " << solucion.first << endl;
    cout << "Solucion:" << endl;

    for (int i = 0; i < solucion.second.size(); i++){
        cout << "   Envase " << i + 1 << " --> Numero de envases usados " << solucion.second[i] << endl;
    }

    return 0;
}