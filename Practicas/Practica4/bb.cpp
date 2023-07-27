#include <iostream>
#include <ostream>
#include <queue>
#include <cmath>
#include <assert.h>
#include "bb.hpp"
#include <vector>

using namespace std;

Solucion::Solucion(const int tam_max, vector<double> obj)
{
    vector<int> aux(tam_max, 0); //inicializarlo cn el tam max y al valor nulo = 0
    x = aux;
    pos_e = -1;
    numRecipientes = 0;
    peso = 0;
    objetos = obj;
    estimador = numRecipientes + tam_max;
    actualizaEstimador(-1);
}

bool Solucion::Factible() const{
    
    cout << "PESO = " << peso << endl;
    cout << "OBJETOS[pos_E] = " << objetos[pos_e] << endl;
    cout << "NumRecipientes = " << numRecipientes << endl;
    cout << "pos_e = " << pos_e << endl;
    if ( peso > numRecipientes){
        cout << "no ES FACTIBLE" << endl << endl;
         return false;
    }
    
    cout << "ES FACTIBLE" << endl;
    
    return true;
}

void Solucion::PrimerValorComp(int k)
{
    assert(k >= 0 && k < x.size()); 
    x[k] = 0;
    peso+=objetos[k];
    
}

void Solucion::sigValComp(int k)
{
    assert(k >= 0 && k < x.size());
    x[k]++;
    actualizaEstimador(k);
    actualizarNumRecipientes();
    
}

int Solucion::comp(int k) const{
    assert(k >= 0 && k < x.size());
    return x[k];
}

int Solucion::cotaLocal() const{    
    return estimador;
}

bool Solucion::hayMasValores(int k) const{
    assert(k >= 0 && k < x.size());
    return x[k] != x.size() + 1;
}

int Solucion::evalua(){
    /* int n=0;
    for (int i=0; i<x.size(); i++)
        if(x[i]>n)
            n=x[i];
    
    numRecipientes = n;
    cout << "ACTUALIZA NUM RECIPIENTES = " <<numRecipientes<< endl; */
    return numRecipientes;
}

int Solucion::numComponentes() const{
    return x.size();
}

bool Solucion::esSolucion() const{ 
    
    //comprobar que todos los elementos != NULO
    bool sol = true;
    for (int i = 0; i < x.size() && sol; i++)
    {
        if (x[i] == 0)
            sol = false;
    }

    if(sol)
        cout << "ES SOLUCION" << endl;
    else 
        cout << "NO ES SOLUCION" << endl;

    return sol;
}

int Solucion::compActual() {    
    return pos_e++;
}

bool Solucion::operator<(const Solucion &s) const{
    return  s.estimador< estimador;
}

void Solucion::actualizaEstimador (int k){
    double num;
    for (int i = k+1; i < objetos.size(); i++)
        num += objetos[i];    
 
    int parteEntera = num;
    
    int recisAprox = (num>parteEntera)? num+1 : num; 
    estimador = recisAprox + numRecipientes;
}

void Solucion::actualizarNumRecipientes(){
    for (int i = 0; i < objetos.size(); i++)
        if(numRecipientes<x[i]) 
            numRecipientes=x[i];
}

///////////////////////////////////////////////////////////////////////////
Solucion Algoritmo_BB(vector<double> pesos)
{
    priority_queue<Solucion> Q;
    Solucion n_e(pesos.size(), pesos), mejor_solucion(pesos.size(), pesos); //nodoE en expansion
    int k;
    float CG = 0; // Cota Global
    float ganancia_actual;

    Q.push(n_e);    
    while(!Q.empty() && (Q.top().cotaLocal() > CG)) {
        
        n_e = Q.top();
        
        Q.pop();
        k = n_e.compActual();
        cout << "K =" << k <<endl;
        for (n_e.PrimerValorComp(k + 1); n_e.hayMasValores(k + 1) && (k+1)<n_e.numComponentes(); n_e.sigValComp(k + 1)){
            cout << n_e << endl;
            if (n_e.esSolucion()){               
                ganancia_actual = n_e.evalua();
                if (ganancia_actual < CG){
                    CG = ganancia_actual;
                    mejor_solucion = n_e;
                }
            } else{ 
                if (n_e.Factible() && n_e.cotaLocal() > CG)
                    Q.push(n_e);  
            } 
        }
    }
    return mejor_solucion;
}

int main(int argc, char *argv[])
{
    
    /* if (argc != 2)
    {
        cerr << "Formato " << argv[0] << " <tamano>" << endl;
        return -1;
    } */

   // int n = atoi(argv[1]);
    vector<double> pesitos;
    pesitos.push_back(0.3);
    pesitos.push_back(0.4);
    pesitos.push_back(0.6);
    pesitos.push_back(0.7);
 /*    pesitos.push_back(0.16);
    pesitos.push_back(0.18); */
    
    Solucion A(pesitos.size(), pesitos);

    cout << "<";
    for (int i = 0; i < pesitos.size(); i++)
        cout << pesitos[i] << ", ";
    cout << ">" << endl;

    A = Algoritmo_BB(pesitos);
    
    cout << Algoritmo_BB(pesitos) << endl;
    
    // LLAMADA AL ALGORITMO
}