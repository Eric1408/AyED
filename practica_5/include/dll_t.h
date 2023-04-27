// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef DLLT_H_
#define DLLT_H_

#include <cassert>
#include <iostream>

#include "dll_node_t.h"

// Clase para almacenar una lista doblemente enlazada
template <class T> class DllT {
 public:
  // constructor
  DllT(void) : head_(NULL), tail_(NULL), sz_(0) {}

  // destructor
  ~DllT(void); 

  // getters
  DllNodeT<T>* GetTail(void) const { return tail_; }
  DllNodeT<T>* GetHead(void) const { return head_; }
  int GetSize(void) const { return sz_; }

  bool Empty(void) const;

  // operaciones
  void PushBack(DllNodeT<T>*);
  void PushFront(DllNodeT<T>*);

  DllNodeT<T>* PopBack(void);
  DllNodeT<T>* PopFront(void);

  DllNodeT<T>* Erase(DllNodeT<T>*);

  // E/S
  std::ostream& Write(std::ostream& = std::cout) const;

 private:
  DllNodeT<T>* head_;
  DllNodeT<T>* tail_;
  int            sz_;
};


// destructor
template <class T> DllT<T>::~DllT(void) {
  while (head_ != NULL) {
    DllNodeT<T>* aux = head_;
    head_ = head_->GetNext();
    delete aux;
  }
  sz_ = 0;
  tail_ = NULL;
}

// Comprobar si lista vacía
template <class T> bool DllT<T>::Empty(void) const {
  if (head_ == NULL) {
    assert(tail_ == NULL);
    assert(sz_ == 0);
    return true;
  } else
    return false;
}

// operaciones
template <class T> void DllT<T>::PushFront(DllNodeT<T>* nodo) {
  assert(nodo != NULL);

  if (Empty()) {
    head_ = nodo;
    tail_ = head_;
  } else {
    head_->SetPrev(nodo);
    nodo->SetNext(head_);
    head_ = nodo;
  }
  sz_++;
}

template <class T> void DllT<T>::PushBack(DllNodeT<T>* nodo) {
  assert(nodo != NULL);

  if (Empty()) {
    head_ = nodo;
    tail_ = head_;
  } else {
    tail_->SetNext(nodo);
    nodo->SetPrev(tail_);
    tail_ = nodo;
  }
  sz_++;
}

template <class T> DllNodeT<T>* DllT<T>::PopBack(void) {
  assert(!Empty());

  DllNodeT<T>* aux = tail_;
  tail_ = tail_->GetPrev();
  if (tail_ != NULL)
    tail_->SetNext(NULL);
  else
    head_ = NULL;
  sz_--;
  aux->SetNext(NULL);
  aux->SetPrev(NULL);
  return aux;
}

template <class T> DllNodeT<T>* DllT<T>::PopFront(void) {
  assert(!Empty());

  DllNodeT<T>* aux = head_;
  head_ = head_->GetNext();
  if (head_ != NULL)
    head_->SetPrev(NULL);
  else
    tail_ = NULL;
  sz_--;
  aux->SetNext(NULL);
  aux->SetPrev(NULL);
  return aux;
}

template <class T> DllNodeT<T>* DllT<T>::Erase(DllNodeT<T>* nodo) {
  assert(nodo != NULL);

  if (nodo->GetPrev() != NULL)
    nodo->GetPrev()->SetNext(nodo->GetNext());
  else
    head_ = nodo->GetNext();
  if (nodo->GetNext() != NULL)
    nodo->GetNext()->SetPrev(nodo->GetPrev());
  else
    tail_ = nodo->GetPrev();
  sz_--;
  nodo->SetPrev(NULL);
  nodo->SetNext(NULL);
  return nodo;
}

// E/S
template <class T> std::ostream& DllT<T>::Write(std::ostream& os) const {
  DllNodeT<T>* aux = head_;

  while (aux != NULL) {
    aux->Write(os);
    aux = aux->GetNext();
  }
  return os;
}

#endif  // DLLT_H_
