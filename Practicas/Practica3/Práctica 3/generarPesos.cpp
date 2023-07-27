#include <iostream>
#include <vector>

using namespace std;

vector<double> w;
int n;

double uniforme(){
    int t = rand();
    double f = ((double)RAND_MAX+1.0);
    return (double)t/f;
}

void generaPesos(){
    srand(time(0));
    for (int i = 0; i < n; i++) {
        double u = uniforme();
        w.push_back(u);
    }
}

int main(int argc, char *argv[]){

    if(argc != 2){
        cerr << "Error en el numero de argumentos. Ejecucion: ./generarPesos <numero_objetos>" << endl;
    }

    n = atoi(argv[1]);

    generaPesos();

    for(int i = 0; i < n; i++)
        cout << w[i] << " ";
}