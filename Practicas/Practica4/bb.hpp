#include <vector>
#include <iostream>
#include <ostream>


using namespace std;

class Solucion{ 

    private:
    vector<int> x; // Almacena la solucion. Para cada posicion x[i] Dominio = {0, 1, ... N, N+1} Siendo NULO = 0 y END = N+1
    vector<double> objetos; //Pasado como parametro
    int pos_e; // Posicion de la ultima decision en X
    int numRecipientes; //Ganancia acumulada
    double peso; // peso ocupado
    int estimador; // Valor del estimador para el nodo X
    
    public:
    
    /*
        CONSTRUCTOR INICIALIZA A NULO
    */
    Solucion(const int tam_max, vector<double> obj);

    /*
        INDICAR SI ES FACTIBLE O NO LA SOLUCION
    */
    bool Factible() const;

    /*
        Inicializa x[k] a nulo
    */
    void PrimerValorComp(int k);

    /*
        Cambia el valor de x[k] al siguiente valor del dominio
    */
    void sigValComp(int k);

    /*
        Devuelve el valor de x[k]
    */
    int comp(int k) const;

    /*
        Devuelve el valor de la cota Local
    */
    int cotaLocal() const;

    /*
        Indica si no se ha llegado al final es decir si x[k] != END
    */
    bool hayMasValores(int k) const;
    
    /*
        Calcula el valor de la ganancia actual
    */
    int evalua();

    /*
        Devuelve el tamaño de x
    */
    int numComponentes() const;
    
    /*
        Evalua si x es o no solucion
    */
    bool esSolucion() const;
    
    /*
        Devuelve pos_e 
    */
    int compActual();

    void actualizaEstimador(int k);
    void actualizarNumRecipientes();

    /*
        Operador < de estimador
    */
    bool operator<(const Solucion &s) const;

    friend ostream& operator<<(ostream &os, const Solucion &Solucion);

};

ostream& operator<<(ostream &os, const Solucion &Solucion)
    {
        os << "<";
        for (int i = 0; i < Solucion.x.size(); i++)
            os << Solucion.x[i] << ", ";
        os << ">";
        return os;
    }