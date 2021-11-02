// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Expresiones Regulares
// Autor: Aday Chocho Aisa
// Correo: alu0101437538@ull.edu.es
// Fecha: 31/10/2021
// Archivo client_p05.cc: programa cliente
// Contiene la función principal del proyecto
// Referencias:
// Enlaces de interés:


#include <iostream>
#include "dfa.h"

int main(int argc, char* argv[]) {
  std::string option = argv[1];
  if (argc == 3) {
    Dfa adn;
    Alphabet alphabet = kAdnAlphabet;
    adn.Set_Adn();
    if (alphabet.Check(argv[1])) {
      Chain chain (argv[1], alphabet);
      adn.Save_Dfa_Subsequences(argv[2], chain);
    }
    else {
      std::cout << "La cadena introducida no es de ADN" << std::endl;
    }
  }
  else if (option == "--help") {
    std::cout << "El programa pide por parámetros una cadena de ADN y un "
    << "fichero de texto, de manera que almacenará todas las subcadenas "
    << "que cumplan con la condición de empezar y terminar por una A o "
    << "por una T. Modo de empleo: " <<std::endl;
    std::cout << argv[0] << " [Cadena de texto] [Fichero]" << std::endl;
    std::cout << "[Cadena de texto] -> Cadena de ADN a introducir" << std::endl;
    std::cout << "[Fichero] -> Fichero de salida" << std::endl;
  }
  else {
    std::cout << argv[0] << std::endl;
    std::cout << "Modo de empleo "
    << argv[0] << " [Cadena de texto] [Fichero]" << std::endl;
    std::cout << "Para más información, use " << argv[0]
    << " --help" << std::endl;
  }
  return 0;
}