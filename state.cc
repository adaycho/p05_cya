// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Expresiones Regulares
// Autor: Aday Chocho Aisa
// Correo: alu0101437538@ull.edu.es
// Fecha: 31/10/2021
// Archivo state.cc: clase estado
// Contiene la definición de métodos de la clase estado
// Referencias:
// Enlaces de interés:

#include "state.h"

// Función que retorna el valor que marca al estado
int State::Get_Val() const {
  return value_;
}

// Sobrecarga de operadores
// Menor que
bool operator<(const State& state1, const State& state2) {
  return state1.value_ < state2.value_;
}

// Mayor que
bool operator>(const State& state1, const State& state2) {
  return state1.value_ > state2.value_;
}

// Igualdad
bool operator==(const State& state1, const State& state2) {
  return state1.value_ == state2.value_;
}

// Desigualdad
bool operator!=(const State& state1, const State& state2) {
  return state1.value_ != state2.value_;
}
