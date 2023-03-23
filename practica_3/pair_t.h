// AUTOR: Eric Angueta Rogel
// FECHA:  05/04/2022
// EMAIL: alu0101335339@ull.edu.es
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef PAIRT_H_
#define PAIRT_H_

#include <iostream>

template<class T> class PairT {
 public:
  // constructores
  PairT(void); 
  PairT(T, int);

  // destructor
  ~PairT(void);
  
  // getters & setters
  T GetVal(void) const;
  int GetInx(void) const;
  void Set(T, int);

  // E/S
  std::istream& Read(std::istream& is = std::cin);
  std::ostream& Write(std::ostream& os = std::cout) const;

 private:
  T   val_;
  int inx_;
};


template<class T> PairT<T>::PairT() : val_(), inx_(-1) {}

template<class T> PairT<T>::PairT(T val, int inx) : val_(val), inx_(inx) {}

template<class T> PairT<T>::~PairT() {}

template<class T> void PairT<T>::Set(T val, int inx) {
  val_ = val;
  inx_ = inx;
}

template<class T> int PairT<T>::GetInx() const {
  return inx_;
}

template<class T> T PairT<T>::GetVal() const {
  return val_;
}

template<class T> std::istream& PairT<T>::Read(std::istream& is) {
  return is >> inx_ >> val_;
}

template<class T> std::ostream& PairT<T>::Write(std::ostream& os) const {
  return os << "(" << inx_ << ":" << val_ << ")";
}

template<class T> std::ostream& operator<<(std::ostream& os, const PairT<T>& p) {
  p.Write(os);
  return os;
}

#endif  // PAIRT_H_
