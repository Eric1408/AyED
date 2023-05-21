// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef SLLT_H_
#define SLLT_H_

#include <iostream>
#include <cassert>

#include "sll_node_t.h"

// Clase para almacenar una lista simplemente enlazada
template <class T>
class sll_t {
 public:
  // constructor
  sll_t(void) : head_(NULL) {}

  // destructor
  ~sll_t(void);

  // getters
  sll_node_t<T>* get_head(void) const { return head_; };
  
  bool empty(void) const;
  
  // operaciones
  void push_front(sll_node_t<T>*);
  sll_node_t<T>* pop_front(void);

  void insert_after(sll_node_t<T>*, sll_node_t<T>*);
  sll_node_t<T>* erase_after(sll_node_t<T>*);

  sll_node_t<T>* search(const T&) const;

  // E/S
  std::ostream& write(std::ostream& = std::cout) const;

  // EXAMEN JUNIO 2021
  void PushSorted(sll_node_t<T>*);
  // EXAMEN JULIO 2021
  void Sort(void);

 private:
  sll_node_t<T>* head_;
};

// EXAMEN JULIO 2021
template <class T>
void sll_t<T>::Sort(void) {
  if (empty()) return;
  sll_node_t<T>* aux = head_;
  sll_node_t<T>* node;
  aux = aux->get_next();
  while (aux->get_next() != NULL) {
    if (aux->get_next()->get_data() < aux->get_data()) {
      node = aux->get_next;
      aux = aux->set_next(node->get_next());
      PushSorted(node);
      aux = node;
    } else aux = aux->get_next();
  }
}

// EXAMEN JUNIO 2021
template <class T>
void sll_t<T>::PushSorted(sll_node_t<T>* n) {
  sll_node_t<T>* aux1 = head_;
  sll_node_t<T>* prev = head_->get_next();
  
  if (aux1->get_data() >= n->get_data()) {
    push_front(n);
    return;
  }
  aux1 = aux1->get_next();
  while (aux1 != NULL) {
    if (aux1->get_data() >= n->get_data()) {
      insert_after(prev, n);
      return;
    }
    prev = aux1;
    aux1 = aux1->get_next();
  }
  insert_after(prev, n);
}

// destructor
template <class T> sll_t<T>::~sll_t(void) {
  while (!empty()) {
    sll_node_t<T>* aux = head_;
    head_ = head_->get_next();
    delete aux;
  }
}

// Comprobar si lista vacía
template <class T> bool sll_t<T>::empty(void) const {
  return head_ == NULL;
}

// operaciones
template <class T> void sll_t<T>::push_front(sll_node_t<T>* n) {
  assert(n != NULL);

  n -> set_next(head_);
  head_ = n;
}

template <class T> sll_node_t<T>* sll_t<T>::pop_front(void) { 
  assert(!empty());
  sll_node_t<T>* aux = head_;
  head_ = head_->get_next();
  aux->set_next(NULL);

  return aux;
}

template <class T> void sll_t<T>::insert_after(sll_node_t<T>* prev,
					                                     sll_node_t<T>* n) {
  assert(prev != NULL && n != NULL);

  n->set_next(prev->get_next());
  prev->set_next(n);
}

template <class T> sll_node_t<T>* sll_t<T>::erase_after(sll_node_t<T>* prev) { 
  assert(!empty());
  assert(prev != NULL);
  sll_node_t<T>* aux = prev->get_next();
  
  assert(aux != NULL);
  prev->set_next(aux->get_next());
  aux->set_next(NULL);

  return aux;
}

template <class T> sll_node_t<T>* sll_t<T>::search(const T& d) const {
  sll_node_t<T>* aux = head_;
  while ((aux != NULL) && (aux->get_data() != d))
    aux = aux->get_next();
    
  return aux;
}

// E/S
template <class T> std::ostream& sll_t<T>::write(std::ostream& os) const {
  sll_node_t<T>* aux = head_;

  while (aux != NULL) {
    aux->write(os);
    aux = aux->get_next();
  }
  return os;
}

#endif  // SLLT_H_
