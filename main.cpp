#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    const int N = 10;

    int A[N], B[N], R[N];

    for (int i = 0; i < N; i++) {
        A[i] = i + 1;
        B[i] = i + 11;
    }

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        R[i] = A[i] + B[i];
    }

    for (int i = 0; i < N; i++) {
        cout << R[i] << " ";
    }

    return 0;
}
