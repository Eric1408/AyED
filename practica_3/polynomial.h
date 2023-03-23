// AUTOR: Eric Angueta Rogel 
// FECHA: 05/04/2022
// EMAIL: alu0101335339@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <iostream>
#include <math.h>  // fabs, pow

#include "vector_t.h"
#include "sparse_vector_t.h"

// Clase para polinomios basados en vectores densos de doubles
class Polynomial : public VectorT<double> {
 public:
  // constructores
  Polynomial(const int n = 0) : VectorT<double>(n) {};
  Polynomial(const Polynomial& pol) : VectorT<double>(pol) {}; // constructor de copia

  // destructor
  ~Polynomial() {};

  // E/S
  void Write(std::ostream& = std::cout, const double eps = EPS) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;
};



// Clase para polinomios basados en vectores dispersos
class SparsePolynomial : public SparseVectorT {
 public:
  // constructores
  SparsePolynomial(const int n = 0) : SparseVectorT(n) {};
  SparsePolynomial(const Polynomial& pol) : SparseVectorT(pol) {};
  SparsePolynomial(const SparsePolynomial&);  // constructor de copia

  // destructor
  ~SparsePolynomial() {};

  // E/S
  void Write(std::ostream& = std::cout) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SparsePolynomial&, const double = EPS) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;
  SparsePolynomial GreaterThan(const int) const;
  //void GreaterThan_(int, const SparsePolynomial&);
};

//MODIFICACION
SparsePolynomial SparsePolynomial::GreaterThan(const int number) const {
  SparsePolynomial result(*this);
  int k = 0;
  
  for (int i = 0; i < GetNZ(); ++i) {
    result.At(i).Set(0.0, 0);
    
  }

  for(int i = 0; i < GetNZ(); ++i) {
    if (At(i).GetInx() > number) {
      result.At(k).Set(At(i).GetVal(), At(i).GetInx());
      ++k;
    }
  }

  return result;
}

//void SparsePolynomial::GreaterThan_(int number, const SparsePolynomial& pol) {
//    std::cout << get_n() << "(" << GetNZ() << "): [ ";
//    bool first{true};
//    for (int i{number -1}; i < GetNZ(); i++) {
//      int inx{At(i).GetInx()};
//      std::cout << (!first ? " + " : "") << At(i).GetVal()
//         << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
//      if (inx > 1)
//        std::cout << inx;
//      first = false;
//    }
//    std::cout << " ]" << std::endl;
//}

// E/S
void Polynomial::Write(std::ostream& os, const double eps) const {
  os << GetSize() << ": [ ";
  bool first{true};
  for (int i{0}; i < GetSize(); i++)
    if (IsNotZero(At(i), eps)) {
      os << (!first ? " + " : "") << At(i) << (i > 1 ? " x^" : (i == 1) ? " x" : "");
      if (i > 1)
	os << i;
      first = false;
    }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
  p.Write(os);
  return os;
  }

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector denso
double Polynomial::Eval(const double x) const {
  double result{0.0};
  // poner el código aquí
  for (int i = 0; i < GetSize(); ++i) {
    result += std::pow(x, i) * GetVal(i);
  }

  return result;
}

// Comparación si son iguales dos polinomios representados por vectores densos
bool Polynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false;
  // poner el código aquí
  int size{0};
  if (GetSize() - pol.GetSize() >= eps) {
    size = pol.GetSize();
  } else {
    size = GetSize();
  }

  for (int i = 0; i < size; ++i) {
    if (fabs(GetVal(i) - pol.GetVal(i) >= eps)) {
      differents = true;
    }
  }

  return !differents;
}

// constructor de copia
SparsePolynomial::SparsePolynomial(const SparsePolynomial& spol) {
  *this = spol;   // se invoca directamente al operator=
}

// E/S
void SparsePolynomial::Write(std::ostream& os) const {
  os << GetN() << "(" << GetNZ() << "): [ ";
  bool first{true};
  for (int i{0}; i < GetNZ(); i++) {
    int inx{At(i).GetInx()};
    os << (!first ? " + " : "") << At(i).GetVal()
       << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
  }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SparsePolynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector disperso
double SparsePolynomial::Eval(const double x) const {
  double result{0.0};
  // poner el código aquí
  for (int i = 0; i < GetNZ(); ++i) {
    result += At(i).GetVal() * std::pow(x, At(i).GetInx());
  }

  return result;
}

// Comparación si son iguales dos polinomios representados por vectores dispersos
bool SparsePolynomial::IsEqual(const SparsePolynomial& spol
			       , const double eps) const {
  bool differents = false;
  // poner el código aquí
  int size{0};
  if (GetNZ() - spol.GetNZ() >= eps) {
    size = spol.GetNZ();
  } else {
    size = GetNZ();
  }

  for (int i = 0; i < size; ++i) {
    if (fabs(At(i).GetVal() - spol.At(i).GetVal()) >= eps) {
      differents = true;
    }
  }

  return !differents;
}

// Comparación si son iguales dos polinomios representados por
// vector disperso y vector denso
bool SparsePolynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false;
  // poner el código aquí
  int size{0};
  if (GetNZ() - pol.GetSize() >= eps) {
    size = pol.GetSize();
  } else {
    size = GetNZ();
  }

  for (int i = 0; i < size; ++i) {
    if (fabs(At(i).GetVal() - pol.GetVal(At(i).GetInx())) >= eps) {
      differents = true;
    } 
  }

  return !differents;
}


#endif  // POLYNOMIAL_H_
