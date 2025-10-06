#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include <vector>
using namespace std;

namespace sorting {

inline void insertionSort(vector<int>& arr, long long& comparacoes, long long& trocas) {
    int n = arr.size();
    comparacoes = 0;
    trocas = 0;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparacoes++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                trocas++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

} // namespace sorting

#endif
