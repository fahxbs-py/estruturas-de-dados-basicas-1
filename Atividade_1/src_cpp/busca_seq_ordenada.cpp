#include "busca_seq_ordenada.hpp"


void swap(int &a, int &b){
  int auxiliar = a;
  a = b;
  b = auxiliar;
}


void bubbleSort(int arr[], int n){
  bool mudou = true;
  int fim = n;

  while(mudou){
    mudou = false;
    for (int i = 0; i < fim - 1; i++){
      if(arr[i] > arr[i + 1]){
        swap(arr[i], arr[i + 1]);
        mudou = true;
      }
    }
    fim --;
  }
}


int busca_seq_ordenada(int arr[], int n, int alvo) {
  for (int i = 0; i < n; i++){
    if (arr[i] == alvo) return i;
    if (arr[i] > alvo) return -1;
  }
  return -1;
}


int conta_especialidades_distintas(int arr[], int n){
  bubbleSort(arr, n);
  int contador = 0;

  for (int i = 0; i < n; i++){
    if (busca_seq_ordenada(arr, i, arr[i]) == -1){
      contador ++;
    }
  }
  return contador;
}