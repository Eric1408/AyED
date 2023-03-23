// AUTOR: Eric Angueta Rogel 
// FECHA: 05/04/2022
// EMAIL: alu0101335339@ull.edu.es
// VERSION: 3.1
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef VECTORT_H_
#define VECTORT_H_

#include <iostream>
#include <cassert>

template<class T> class VectorT {
 public:
  // constructores
  VectorT(const int = 0);
  VectorT(const VectorT&); // constructor de copia

  // operador de asignación
  VectorT<T>& operator=(const VectorT<T>&);

  // destructor
  ~VectorT();
  
  // getters
  T GetVal(const int) const;
  int GetSize(void) const;
  
  // setters
  void SetVal(const int, const T);
  
  // getters-setters
  T& At(const int);
  T& operator[](const int);
  
  // getters constantes
  const T& At(const int) const;
  const T& operator[](const int) const;

  // Redimensionado
  void Resize(const int);
  
  // E/S
  void Read(std::istream& = std::cin);
  void Write(std::ostream& = std::cout) const;

 private:
  T *v_;
  int sz_;
  
  void Build(void);
  void Destroy(void);
};


/**
 * @brief Constructor por defecto
*/
template<class T> VectorT<T>::VectorT(const int n) : v_(NULL), sz_(n) {
  Build();
}

// constructor de copia
template<class T> VectorT<T>::VectorT(const VectorT<T>& w)
    : v_(NULL), sz_(0) {
  *this = w; // se invoca directamente al operator=
}

// operador de asignación
template<class T> VectorT<T>& VectorT<T>::operator=(const VectorT<T>& w) {
  Resize(w.GetSize());
  for (int i = 0; i < GetSize(); i++)
    At(i) = w.At(i);
  
  return *this;
}

template<class T> VectorT<T>::~VectorT() {
  Destroy();
}

template<class T> void VectorT<T>::Build() {
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}

template<class T> void VectorT<T>::Destroy() {
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}

template<class T> void VectorT<T>::Resize(const int n) {
  Destroy();
  sz_ = n;
  Build();
}

template<class T> inline T VectorT<T>::GetVal(const int i) const {
  assert(i >= 0 && i < GetSize());
  return v_[i];
}

template<class T> inline int VectorT<T>::GetSize() const {
  return sz_;
}

template<class T> void VectorT<T>::SetVal(const int i, const T d) {
  assert(i >= 0 && i < GetSize());
  v_[i] = d;
}

template<class T> T& VectorT<T>::At(const int i) {
  assert(i >= 0 && i < GetSize());
  return v_[i];
}

template<class T> T& VectorT<T>::operator[](const int i) {
  return At(i);
}

template<class T> const T& VectorT<T>::At(const int i) const {
  assert(i >= 0 && i < GetSize());
  return v_[i];
}

template<class T> const T& VectorT<T>::operator[](const int i) const {
  return At(i);
}

template<class T> void VectorT<T>::Read(std::istream& is) {
  is >> sz_;
  Resize(sz_);
  for (int i = 0; i < sz_; i++)
    is >> At(i);
}

template<class T> void VectorT<T>::Write(std::ostream& os) const {
  os << GetSize() << ": [ ";
  for (int i = 0; i < GetSize(); i++)
    os << At(i) << (i != GetSize() - 1 ? "\t" : "");
  os << " ]" << std::endl;
}

template<class T> std::istream& operator>>(std::istream& is, VectorT<T>& v) {
  v.Read(is);
  return is;
}

template<class T> std::ostream& operator<<(std::ostream& os, const VectorT<T>& v) {
  v.Write(os);
  return os;
}

#endif  // VECTORT_H_
