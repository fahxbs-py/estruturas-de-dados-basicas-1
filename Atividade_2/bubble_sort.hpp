#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include <vector>
#include <algorithm> // para std::swap

namespace sorting {

inline void bubbleSort(std::vector<int>& arr, long long& comparacoes, long long& trocas) {
    int n = arr.size();
    comparacoes = 0;
    trocas = 0;
    for (int i = 0; i < n - 1; i++) {
        bool trocou = false;
        for (int j = 0; j < n - i - 1; j++) {
            comparacoes++;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                trocas++;
                trocou = true;
            }
        }
        if (!trocou) break;
    }
}

} // namespace sorting

#endif
