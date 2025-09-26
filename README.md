# Atividade 1 – Estruturas de Dados Básicas
Este repositório contém a implementação das questões práticas referentes à disciplina de Estruturas de Dados.  
As soluções foram desenvolvidas em **C++**, com organização em diretórios para os arquivos-fonte, cabeçalhos, testes e automação de compilação via **Makefile**.


---

## Compilação

Para compilar o projeto, basta executar:

```bash
make
```

## Funções implementadas

1. int recursao(const std::string &str, char alvo);

Descrição:
Função recursiva que percorre a string str e realiza a contagem de ocorrências do caractere alvo.

Parâmetros:

str → string a ser analisada

alvo → caractere a ser buscado

Retorno: número de ocorrências do caractere na string.

2. int busca_binaria(int n);

Descrição:
Implementa o algoritmo de busca binária para localizar um elemento em uma coleção ordenada.

Parâmetros:

n → valor a ser buscado
(a implementação simula uma consulta à API isBadVersion, que foi declarada em tests.cpp para nível de testes do funcionamento dela)

Retorno: índice do elemento encontrado ou -1 caso não exista no vetor.

3. int conta_especialidades_distintas(int arr[], int n);

Descrição:
Realiza uma varredura em um vetor ordenado e conta quantas especialidades distintas (valores diferentes) existem.

Parâmetros:

arr[] → vetor de inteiros

n → tamanho do vetor

Retorno: quantidade de valores distintos encontrados.

## Funções auxiliares

A função conta_especialidades_distintas ainda faz uso de algumas funções auxiliares:

3.1 void swap(int &a, int &b)

Descrição: É usada pelo bubbleSort para trocar a posição dos elementos do vetor que está sendo ordenado.

3.2 void bubbleSort(int arr[], int n){

Descrição: Usada para ordernar o vetor antes de ser lido.

3.3 int busca_seq_ordenada(int arr[], int n, int alvo) 

Descrição: Implementação da busca sequencial, usada para percorrer o vetor ordenado e verificar cada elemento, buscando por elementos diferentes para realizar a contagem em conta_especialidades_distintas

