// AUTOR: Eric Angueta Rogel 
// FECHA: 16/04/2023
// EMAIL: alu0101335339@ull.edu.es
// VERSION: 4.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef SPARSE_VECTORT_H_
#define SPARSE_VECTORT_H_

#include <iostream>
#include <math.h>  // fabs

#include "vector_t.h"
#include "pair_t.h"

#define EPS 1.0e-6

typedef PairT<double> PairDoubleT;
typedef VectorT<PairDoubleT> PairVectorT;

class SparseVectorT {
 public:
  // constructores
  SparseVectorT(const int = 0);
  SparseVectorT(const VectorT<double>&, 
  const double = EPS); // constructor normal
  SparseVectorT(const SparseVectorT&);  // constructor de copia

  // operador de asignación
  SparseVectorT& operator=(const SparseVectorT&);

  // destructor
  ~SparseVectorT();
  
  // getters
  int GetNZ(void) const;
  int GetN(void) const;

  // getters-setters
  PairDoubleT& At(const int);
  PairDoubleT& operator[](const int);
  
  // getters constantes
  const PairDoubleT& At(const int) const;
  const PairDoubleT& operator[](const int) const;

  // E/S
  void Write(std::ostream& = std::cout) const;

 private:
  PairVectorT pv_;  // valores + índices
  int nz_;            // nº de valores distintos de cero = tamaño del vector
  int n_;             // tamaño del vector original

  // bool IsNotZero(const double, const double = EPS) const;
};


bool IsNotZero(const double val, const double eps = EPS) {
  return fabs(val) > eps;
}

SparseVectorT::SparseVectorT(const int n) : pv_(n), nz_(0), n_(n) {}

// FASE II
SparseVectorT::SparseVectorT(const VectorT<double>& v, const double eps) : pv_(), nz_(0), n_(0) {
  n_ = v.GetSize();

  for (int i = 0; i < v.GetSize(); ++i) {
    if (v[i] != 0) {
      nz_++;
    }
  }

  pv_.Resize(nz_);

  int k = 0;
  for (int i = 0; i < v.GetSize(); i++) {
    if (v[i] != 0) {
      PairDoubleT aux(v.GetVal(i), i);
      pv_[k] = aux;
      k++;
    }
  }
}

// constructor de copia
SparseVectorT::SparseVectorT(const SparseVectorT& w) {
  *this = w;  // se invoca directamente al operator=
}

// operador de asignación
SparseVectorT& SparseVectorT::operator=(const SparseVectorT& w) {
  nz_ = w.GetNZ();
  n_ = w.GetN();
  pv_ = w.pv_;

  return *this;
}

SparseVectorT::~SparseVectorT() {}

inline int SparseVectorT::GetNZ() const {
  return nz_;
}

inline int SparseVectorT::GetN() const {
  return n_;
}

PairDoubleT& SparseVectorT::At(const int i) {
  assert(i >= 0 && i < GetNZ());
  return pv_[i];
}

PairDoubleT& SparseVectorT::operator[](const int i) {
  return At(i);
}

const PairDoubleT& SparseVectorT::At(const int i) const {
  assert(i >= 0 && i < GetNZ());
  return pv_[i];
}

const PairDoubleT& SparseVectorT::operator[](const int i) const {
  return At(i);
}

// E/S
void SparseVectorT::Write(std::ostream& os) const { 
  os << GetN() << "(" << GetNZ() << "): [ ";
  for (int i = 0; i < GetNZ(); i++)
    os << pv_[i] << " ";
	os << "]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SparseVectorT& sv) {
  sv.Write(os);
  return os;
}

#endif  // SPARSE_VECTORT_H_
