#include "busca_binaria.hpp"

extern bool isBadVersion(int version);

int busca_binaria(int n) {
  int esquerda = 1;
  int direita = n;

  while(esquerda < direita){
    int meio = esquerda + (direita - esquerda) / 2;


    if (isBadVersion(meio)){
      direita = meio;
    } else {
      esquerda = meio + 1;
    }
  }

  return esquerda;
}