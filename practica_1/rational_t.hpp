/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructura de Datos 2021-2022
  *
  * @file rational_t.hpp
  * @author Eric Angueta Rogel alu0101335339@ull.edu.es
  * @date 08/03/2022
  * @brief Este programa verifica un numero de Armstrong,
  *        que es la suma de sus propios digitos,cada uno de los cuales
  *        elevado al numero de digitos del numero.
  * @bug There are no known bugs
  * @see se indican entre [] las pautas de estilo aplicadas de
  *        "C++ Programming Style Guidelines"
  *        https://geosoft.no/development/cppstyle.html
  */
 
// pauta de estilo [92]: comentarios multilíne
#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// pauta de estilo [5]
# define EPSILON 1e-6

using namespace std;

class rational_t
{
  // pautas de estilos [44] y [73]: primero "public" y después "private"
public:
  
  /**
   * @brief Construct a new rational t object
   * 
   */
  rational_t(const int = 0, const int = 1);
  //rational_t(const int num = 0, const int den = 1) : num_{num}, den_{den} {}
  
  /**
   * @brief Destroy the rational t object
   * 
   */
  ~rational_t() {}
  
  // pauta de estilo [71]: indentación a 2 espacios
  // getters
  int get_num() const;
  int get_den() const;
  
  // setters
  void set_num(const int);
  void set_den(const int);

  double value(void) const;

  // FASE II
  bool is_equal(const rational_t&, const double precision = EPSILON) const;
  bool is_greater(const rational_t&, const double precision = EPSILON) const;
  bool is_less(const rational_t&, const double precision = EPSILON) const;
  
  // FASE III
  rational_t add(const rational_t&);
  rational_t substract(const rational_t&);
  rational_t multiply(const rational_t&);
  rational_t divide(const rational_t&);
  
  void write(ostream& = cout) const;
  void read(istream& = cin);

  //MODIFICACION
  rational_t opposite(void) const; 
  
private:
  // pauta de estilo [11]: nombre de los atributos seguido de "_"
  int num_, den_;
};
