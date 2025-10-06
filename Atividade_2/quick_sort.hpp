#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include <vector>
using namespace std;

namespace sorting {

// Função para calcular a mediana de três elementos
inline int medianOfThree(vector<int>& arr, int low, int mid, int high) {
    if ((arr[low] <= arr[mid] && arr[mid] <= arr[high]) || (arr[high] <= arr[mid] && arr[mid] <= arr[low]))
        return mid;
    else if ((arr[mid] <= arr[low] && arr[low] <= arr[high]) || (arr[high] <= arr[low] && arr[low] <= arr[mid]))
        return low;
    else
        return high;
}

inline int partition(vector<int>& arr, int low, int high, long long& comparacoes, long long& trocas) {
    int mid = low + (high - low) / 2;
    int medianIndex = medianOfThree(arr, low, mid, high);
    swap(arr[medianIndex], arr[high]); // coloca o pivô no final
    trocas++;

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparacoes++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            trocas++;
        }
    }
    swap(arr[i + 1], arr[high]);
    trocas++;
    return i + 1;
}

inline void quickSortRec(vector<int>& arr, int low, int high, long long& comparacoes, long long& trocas) {
    if (low < high) {
        int pi = partition(arr, low, high, comparacoes, trocas);
        quickSortRec(arr, low, pi - 1, comparacoes, trocas);
        quickSortRec(arr, pi + 1, high, comparacoes, trocas);
    }
}

inline void quickSort(vector<int>& arr, long long& comparacoes, long long& trocas) {
    comparacoes = 0;
    trocas = 0;
    quickSortRec(arr, 0, arr.size() - 1, comparacoes, trocas);
}

} // namespace sorting

#endif
