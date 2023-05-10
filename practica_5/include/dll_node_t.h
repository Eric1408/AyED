// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef DLL_NODET_H_
#define DLL_NODET_H_

#include <iostream>

// Clase para nodos de listas doblemente enlazadas
template <class T> class DllNodeT {
 public:
  // constructores
  DllNodeT() : prev_(NULL), data_(), next_(NULL) {}  // por defecto
  DllNodeT(const T& data) : prev_(NULL), data_(data), next_(NULL) {}

  // destructor
  ~DllNodeT(void) {}

  // getters & setters
  DllNodeT<T>* GetNext(void) const { return next_; }
  void SetNext(DllNodeT<T>* next) { next_ = next; }
  
  DllNodeT<T>* GetPrev(void) const { return prev_; }
  void SetPrev(DllNodeT<T>* prev) { prev_ = prev; }
  
  const T& GetData(void) const { return data_; }
  void SetData(const T& data) { data_ = data; }

  // E/S
  std::ostream& Write(std::ostream& = std::cout) const;

 private:
  DllNodeT<T>* prev_;
  T data_;
  DllNodeT<T>* next_;
};

  
// E/S
template <class T> std::ostream& DllNodeT<T>::Write(std::ostream& os) const {
  os << data_;
  return os;
}

#endif  // DLL_NODET_H_
