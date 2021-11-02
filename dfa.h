// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Expresiones Regulares
// Autor: Aday Chocho Aisa
// Correo: alu0101437538@ull.edu.es
// Fecha: 31/10/2021
// Archivo dfa.h: clase dfa
// Contiene la declaración de métodos y los atributos de la clase dfa
// Referencias:
// Enlaces de interés:


#ifndef DFA_H
#define DFA_H

#include "function.h"
#include "language.h"
#include <string>

// Valores establecidos para el ADN
const std::string kA = "A", kC = "C", kG = "G", kT = "T";
const std::vector<Symbol> kAdnSet {kA, kC, kG, kT};
const Alphabet kAdnAlphabet(kAdnSet);
const std::vector<State> kAdnFinish {4,5};
const std::vector<State> kAdnStates {0,1,2,3,4,5};
const int kAdnRows {6}, kAdnColumns {4};
const std::vector<State> kAdnMatrix {1,2,2,3,
                                     4,1,1,1,
                                     2,2,2,2,
                                     3,3,3,5,
                                     4,1,1,1,
                                     3,3,3,5};

// Clase que almacena un Autómata Finito Determinista
class Dfa {
 public:
  // Constructor
  Dfa() : alphabet_(), states_(), start_(0), finish_(), func_() {};

  // Funciones
  void Save_Dfa_Subsequences (std::string file, Chain chain);
  bool Analyze (Chain chain);
  void Set_Adn();
  
 private:
  Alphabet alphabet_;
  std::vector<State> states_;
  State start_;
  std::vector<State> finish_;
  Function func_;
};

#endif