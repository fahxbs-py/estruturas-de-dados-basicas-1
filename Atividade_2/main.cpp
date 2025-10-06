#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include "make_data.hpp"
#include "bubble_sort.hpp"
#include "insertion_sort.hpp"
#include "selection_sort.hpp"
#include "merge_sort.hpp"
#include "quick_sort.hpp"

using namespace std;
using namespace chrono;

void testAlgorithmCSV(ofstream& file, const string& nomeAlg,
                      void(*sortFunc)(vector<int>&, long long&, long long&),
                      const vector<vector<int>>& conjuntos,
                      const vector<string>& tipos,
                      const vector<int>& tamanhos) {
    for (size_t t = 0; t < tamanhos.size(); t++) {
        int n = tamanhos[t];
        for (size_t i = 0; i < conjuntos.size(); i++) {
            vector<int> v = conjuntos[i];
            string tipo = tipos[i];

            long long comparacoes, trocas;
            auto start = high_resolution_clock::now();
            sortFunc(v, comparacoes, trocas);
            auto end = high_resolution_clock::now();
            double duracao = chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0;

            file << nomeAlg << "," << n << "," << tipo << ","
                 << duracao << "," << comparacoes << "," << trocas << "\n";
        }
    }
}

int main() {
    data::initRandom();

    vector<int> tamanhos = {1000, 10000, 100000};
    vector<string> tipos = {"Aleatorio", "QuaseOrdenado", "Inverso"};

    ofstream file("resultados.csv");
    file << "Algoritmo,Tamanho,Tipo,Tempo(s),Comparacoes,Trocas\n";

    for (const std::string& nomeAlg : std::initializer_list<std::string>{
    "Bubble Sort",
    "Insertion Sort",
    "Selection Sort",
    "Merge Sort",
    "Quick Sort"
    }) {
        cout << "Testando: " << nomeAlg << endl;

        for (int n : tamanhos) {
            cout << "Gerando vetores tamanho: " << n << endl;

            vector<int> aleatorio = data::generateRandom(n);
            vector<int> quaseOrdenado = data::generateAlmostSorted(n);
            vector<int> inverso = data::generateReversed(n);
            vector<vector<int>> conjuntos = {aleatorio, quaseOrdenado, inverso};

            if (nomeAlg == "Bubble Sort")
                testAlgorithmCSV(file, nomeAlg, sorting::bubbleSort, conjuntos, tipos, {n});
            else if (nomeAlg == "Insertion Sort")
                testAlgorithmCSV(file, nomeAlg, sorting::insertionSort, conjuntos, tipos, {n});
            else if (nomeAlg == "Selection Sort")
                testAlgorithmCSV(file, nomeAlg, sorting::selectionSort, conjuntos, tipos, {n});
            else if (nomeAlg == "Merge Sort")
                testAlgorithmCSV(file, nomeAlg, sorting::mergeSort, conjuntos, tipos, {n});
            else if (nomeAlg == "Quick Sort")
                testAlgorithmCSV(file, nomeAlg, sorting::quickSort, conjuntos, tipos, {n});
        }
    }

    file.close();
    cout << "Salvo em resultados.csv\n";

    return 0;
}
