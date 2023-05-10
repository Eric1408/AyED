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
template <class T> class RPN {
 public:
  // constructor
 RPN(void) : stack_() {}

  // destructor
  ~RPN() {}

  // operaciones
  const int Evaluate(Queue<char>&);

 private: 
  T stack_;
  void operate_(const char operador);
};


// operaciones
template<class T> const int RPN<T>::Evaluate(Queue<char>& q) {
  while (!q.Empty()) 	{
    char c = q.Front();
    
    q.Pop();
    std::cout << "Sacamos de la cola un carácter: " << c;

    if (isdigit(c)) {
      int i = c - '0';
      // poner código
      stack_.Push(i);
      std::cout << " (es un dígito) " << std::endl
		<< "\tLo metemos en la pila..." << std::endl;
    } else {
      std::cout << " (es un operador)" << std::endl;
      // poner código
      operate_(c);
    }
  }
  // poner código
  int result = stack_.Top();
  stack_.Pop();

  if (stack_.Empty())
    return result;
  else {
    std::cerr << "Error: la pila no esta vacia\n";
    return -1;
  } 
}

template<class T> void RPN<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'r' || c == 'l' || c == 'c');

  // poner código
  int op1 = stack_.Top();
  std::cout << "\tSacamos de la pila un operando: " << op1 << std::endl;
  stack_.Pop();
  
  // poner código
  int op2;
  if (!(c == 'r' || c == 'l' || c == 'c')) {
    op2 = stack_.Top();
    std::cout << "\tSacamos de la pila otro operando: " << op2 << std::endl;
    stack_.Pop();
  }

  int result;

  switch (c) {
    case '+':
      // poner código
      result = op2 + op1;
      break;
    // poner código resto de operadores
    case '-':
      result = op2 - op1;
      break;
    case '*':
      result = op2 * op1;
      break;
    case '/':
      result = op2 / op1;
      break;
    case '^':
      result = pow(op2, op1);
      break;
    case 'r':
      result = sqrt(op1);
      break;
    case 'l':
      result = log2(op1);
      break;
    case 'c':
      result = op1 * op1;
      break;
    default:
      std::cerr << "Error: operador no reconocido\n";
      break;
  }

  // poner código
  std::cout << "\tMetemos en la pila el resultado: " << result << std::endl;
  stack_.Push(result);
}

 
#endif  // RPNT_H_
