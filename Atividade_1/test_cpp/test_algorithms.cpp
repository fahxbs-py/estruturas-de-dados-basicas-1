#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "busca_seq_ordenada.hpp"
#include "busca_binaria.hpp"
#include "recursao.hpp"

#define RUN_TEST(name, expr, expected)                                 \
    do {                                                               \
        int result = (expr);                                           \
        std::cout << std::left << std::setw(25) << name                \
                  << ": " << ((result == (expected)) ? "OK" : "FAIL")  \
                  << std::endl;                                        \
    } while(0)

//FUNÇÃO isBadVersion PARA SIMULAÇÃO DA API

int first_bad = 4; 
bool isBadVersion(int version){
    return version >= first_bad;
};

int main() {

    //TESTES DE BUSCA ORDENADA

    int arr1[] = {7,3,9,1,5,7,3,3,9,1,5,5,2,1,7};
    int n1 = 15;
    RUN_TEST("Busca ordenada", conta_especialidades_distintas(arr1,n1), 6);


    int arr2[] = {1,1,1,1,2,2,2,2,3,3,3,8,8,8,9};
    int n2 = 15;
    RUN_TEST("Busca ordenada", conta_especialidades_distintas(arr2,n2), 5);

    //TESTES DE BUSCA BINÁRIA

    int total_versoes1 = 10;
    RUN_TEST("Busca binaria", busca_binaria(total_versoes1), first_bad);
    
    int total_versoes2 = 27;
    RUN_TEST("Busca binaria", busca_binaria(total_versoes2), first_bad);

    //TESTES DE RECURSAO
    RUN_TEST("Recursao", recursao("teste", 't'), 2);
    RUN_TEST("Recursao", recursao("teste", 'e'), 2);
    RUN_TEST("Recursao", recursao("atividade", 't'), 1);

    return 0;
}

