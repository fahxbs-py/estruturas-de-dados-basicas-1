#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include <vector>
using namespace std;

namespace sorting {

inline void selectionSort(vector<int>& arr, long long& comparacoes, long long& trocas) {
    int n = arr.size();
    comparacoes = 0;
    trocas = 0;

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            comparacoes++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
            trocas++;
        }
    }
}

} // namespace sorting

#endif
