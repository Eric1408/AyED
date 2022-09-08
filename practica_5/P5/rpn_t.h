// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase RPN (Reverse Polish Notation)

#ifndef RPNT_H_
#define RPNT_H_

#include <iostream>
#include <cctype>
#include <cmath>
//#include <cstdlib>

#include "queue_l_t.h"

// Clase RPN (Reverse Polish Notation)
template <class T> class rpn_t {
 public:
  // constructor
 rpn_t(void) : stack_() {}

  // destructor
  ~rpn_t() {}

  // operaciones
  const int evaluate(queue_l_t<char>&);

 private: 
  T stack_;
  void operate_(const char operador);
};


// operaciones
template<class T> const int rpn_t<T>::evaluate(queue_l_t<char>& q) {
  while (!q.empty()) 	{
    char c = q.front();
    
    q.pop();
    std::cout << "Sacamos de la cola un carácter: " << c;

    if (isdigit(c)) {
      int i = c - '0';

      stack_.push(i);

      std::cout << " (es un dígito) " << std::endl
		<< "   Lo metemos en la pila..." << std::endl;
    } else {
      std::cout << " (es un operador)" << std::endl;

      operate_(c);

    }
  }

  return stack_.top();

}

template<class T> void rpn_t<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/');
  int primer_operador;
  int segundo_operador;
  primer_operador = stack_.top();
  stack_.pop();

  std::cout << "   Sacamos de la pila un operando: " << primer_operador << std::endl;

  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' ) {
    segundo_operador = stack_.top();
    stack_.pop();
  }

  std::cout << "   Sacamos de la pila otro operando: " << segundo_operador << std::endl;
  
  int resultado;
  switch (c) {
    case '+':
      resultado = segundo_operador + primer_operador;
      break;
    case '-':
      resultado = segundo_operador - primer_operador;
      break;
    case '*':
      resultado = segundo_operador * primer_operador;
      break;
    case '/':
      resultado = segundo_operador / primer_operador;
      break;
    case '^':
      resultado = pow(segundo_operador, primer_operador);
      break;
    case 'r':
      resultado = sqrt(primer_operador);
      break;
    case '1':
      resultado = log2(primer_operador);
      break;
    case 'c':
      resultado = pow(primer_operador, 2);
      break;
  }

  stack_.push(resultado);
  std::cout << "   Metemos en la pila el resultado: " << resultado << std::endl;
}

 
#endif  // RPNT_H_
