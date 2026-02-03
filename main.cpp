#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <ctime>

#define N 1000
#define chunk 100
#define mostrar 10

using namespace std;

void imprimeArreglo(float *d);

int main() {

    cout << "Sumando Arreglos en Paralelo!\n";

    float a[N], b[N], c[N];
    int i;

    // Semilla para números aleatorios
    srand(time(NULL));

    // Inicializar arreglos con valores aleatorios
    for (i = 0; i < N; i++) {
        a[i] = rand() % 100;   // 0–99
        b[i] = rand() % 100;
    }

    int pedazos = chunk;

    // Suma paralela con OpenMP
    #pragma omp parallel for shared(a,b,c,pedazos) private(i) schedule(static,pedazos)
    for (i = 0; i < N; i++) {
        c[i] = a[i] + b[i];
    }

    // Imprimir resultados
    cout << "Primeros " << mostrar << " valores de A:\n";
    imprimeArreglo(a);

    cout << "Primeros " << mostrar << " valores de B:\n";
    imprimeArreglo(b);

    cout << "Primeros " << mostrar << " valores de C (A+B):\n";
    imprimeArreglo(c);

    return 0;
}

void imprimeArreglo(float *d) {
    for (int x = 0; x < mostrar; x++) {
        cout << d[x] << " ";
    }
    cout << endl;
}
