// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Expresiones Regulares
// Autor: Aday Chocho Aisa
// Correo: alu0101437538@ull.edu.es
// Fecha: 31/10/2021
// Archivo dfa.cc: clase dfa
// Contiene la definición de métodos de la clase dfa
// Referencias:
// Enlaces de interés:

#include "dfa.h"

// Funsión dedicada a colocar los valores del dfa del adn en el propio dfa
void Dfa::Set_Adn() {
  alphabet_ = kAdnAlphabet;
  states_ = kAdnStates;
  finish_ = kAdnFinish;
  Function function(kAdnMatrix, kAdnRows, kAdnColumns);
  func_ = function;
}

// Función para guardar en el fichero de texto
void Dfa::Save_Dfa_Subsequences (std::string file, Chain chain) {
  std::vector<Chain> substrings;
  for (int i = 1; i <= chain.Get_Size(); ++i) {
    for (int j = 0; j < chain.Get_Size() + 1 - i; ++j) {
      Chain string;
      for (int k = 0; k < i; ++k) {
        string.Push_back(chain.Get_Chain()[k + j]);
      }
      bool flag = true;
      if (Analyze(string) == true) {
        for (int k = 0; k < substrings.size(); ++k) {
          if (substrings[k] == string) {
            flag = false;
          }
        }
        if (flag == true) {
          substrings.push_back(string);
        }
      }
    }
  }
  std::ofstream outfile(file);
  Language language(substrings, alphabet_);
  outfile << language;
}

// Función que analiza la cadena con el recorrido del DFA, devolviendo si es aceptada o no
bool Dfa::Analyze (Chain chain) {
  Symbol symbol;
  int state {0};
  for (int i = 0; i < chain.Get_Size(); ++i) {
    int position {-1};
    symbol = chain.Get_Chain()[i];
    int contador = 0;
    for (auto& j : alphabet_.Get_Symbols()) {
      if (j == symbol) {
        position = contador;
        break;
      }
      contador++;
    }
    if(position == -1) {
      return false;
    }
    state = func_.at(state, position).Get_Val();
  }
  for (int i = 0; i < finish_.size(); ++i) {
    if (finish_[i] == state) {
      return true;
    }
  }
  return false;
}