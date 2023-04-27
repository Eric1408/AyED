// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef STACKL_H_
#define STACKL_H_

#include <iostream>
#include <iomanip>
#include <cassert>

#include "dll_t.h"

// Clase para pilas mediante estructura dinámica
template<class T> class Stack {
 public:	
  // constructor
  Stack(void) : l_() {}

  // destructor
  ~Stack(void) {}

  // operaciones
  void Push(const T&);
  void Pop(void);
  const T& Top(void) const;
  bool Empty(void) const;

  // E/S	
  std::ostream& Write(std::ostream& os = std::cout) const;

private:
  DllT<T> l_;
};


// operaciones
template<class T> void Stack<T>::Push(const T& dato) {
  DllNodeT<T>* nodo = new DllNodeT<T>(dato);
  assert(nodo != NULL);
  l_.PushFront(nodo);
}

template<class T> void Stack<T>::Pop(void) {
  assert(!Empty());
  delete l_.PopFront();
}

template<class T> const T& Stack<T>::Top(void) const {
  assert(!Empty());
  return l_.GetHead()->GetData();
}

template<class T> bool Stack<T>::Empty(void) const {
  return l_.Empty();
}

// E/S
template<class T> std::ostream& Stack<T>::Write(std::ostream& os) const {
  DllNodeT<T>* aux = l_.GetHead();
  while (aux != NULL) { 
    os << " │ " << std::setw(2) << aux->GetData() << "  │" << std::endl;
    aux = aux->GetNext();
  }
  os << " └─────┘" << std::endl;
  return os;
}


#endif  // STACKL_H_
