#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <vector>
using namespace std;

namespace sorting {

inline void merge(vector<int>& arr, int left, int mid, int right, long long& comparacoes, long long& trocas) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        comparacoes++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
            trocas++;
        } else {
            arr[k++] = R[j++];
            trocas++;
        }
    }

    while (i < n1) { arr[k++] = L[i++]; trocas++; }
    while (j < n2) { arr[k++] = R[j++]; trocas++; }
}

inline void mergeSortRec(vector<int>& arr, int left, int right, long long& comparacoes, long long& trocas) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortRec(arr, left, mid, comparacoes, trocas);
        mergeSortRec(arr, mid + 1, right, comparacoes, trocas);
        merge(arr, left, mid, right, comparacoes, trocas);
    }
}

inline void mergeSort(vector<int>& arr, long long& comparacoes, long long& trocas) {
    comparacoes = 0;
    trocas = 0;
    mergeSortRec(arr, 0, arr.size() - 1, comparacoes, trocas);
}

} // namespace sorting

#endif
