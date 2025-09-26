#include "recursao.hpp"
#include <string>
#include <iostream>

int recursao(const std::string &str, char alvo) {
  if (str.empty()) return 0; 

  int contador = (str[0] == alvo) ? 1 : 0;

  return contador + recursao(str.substr(1), alvo);
}
