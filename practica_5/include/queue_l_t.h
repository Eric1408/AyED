// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase TAD cola implementada con una lista

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <cassert>

#include "dll_t.h"

// Clase TAD cola implementada con una lista
template <class T> class Queue {
 private:
  DllT<T> l_;

 public:
  // constructor
  Queue(void) : l_() {}

  // destructor
  ~Queue(void) {}

  // operaciones
  bool Empty(void) const;
  int Size(void) const;
  void Push(const T& dato);
  void Pop(void);
  const T& Front(void) const;
  const T& Back(void) const;

  // E/S
  std::ostream& Write(std::ostream& os = std::cout) const;
};


// operaciones
template<class T> bool Queue<T>::Empty(void) const {
  return l_.Empty();
}

template<class T> int Queue<T>::Size(void) const {
  return l_.GetSize();	
}

template<class T> void Queue<T>::Push(const T& dato) {
  DllNodeT<T>* node = new DllNodeT<T>(dato);
  assert(node != NULL);
  l_.PushFront(node);
}

template<class T> void Queue<T>::Pop(void) {
  assert(!Empty());
  delete l_.PopBack();
}

template<class T> const T& Queue<T>::Front(void) const {
  assert(!Empty());
  return (l_.GetTail()->GetData());
}

template<class T> const T& Queue<T>::Back(void) const {
  assert(!Empty());
  return (l_.GetHead()->GetData());
}

 // E/S
template<class T> std::ostream& Queue<T>::Write(std::ostream& os) const {
  DllNodeT<T>* aux = l_.GetHead();
  while (aux != NULL) {
    os << aux->GetData() << " ";
    aux = aux->GetNext();
  }
  os << std::endl;
  return os;
}

template<class T> std::ostream& operator<<(std::ostream& os,
					   const Queue<T>& q) {
  q.Write(os);
  return os;
}


#endif  // QUEUE_H_
