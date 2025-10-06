#ifndef MAKE_DATA_HPP
#define MAKE_DATA_HPP

#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

namespace data {

// Inicializa gerador de números aleatórios
inline void initRandom() {
    srand(static_cast<unsigned>(time(nullptr)));
}

// Gera vetor aleatório
inline vector<int> generateRandom(int n, int maxValor = 10000) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = rand() % maxValor;
    return arr;
}

// Gera vetor quase ordenado (95% ordenado)
inline vector<int> generateAlmostSorted(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = i;

    int swaps = n * 0.05;
    for (int i = 0; i < swaps; i++) {
        int a = rand() % n;
        int b = rand() % n;
        swap(arr[a], arr[b]);
    }
    return arr;
}

// Gera vetor inversamente ordenado
inline vector<int> generateReversed(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = n - i;
    return arr;
}

} // namespace data

#endif
