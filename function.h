#ifndef FUNCTION_H
#define FUNCTION_H

#include <vector>
#include "state.h"

// Clase función, representada por una matriz de estados de n filas y m columnas
class Function {
 public:
  // Constructor
  Function(std::vector<State> function, int rows, int columns);
  Function() : matrix_(), rows_(0), columns_(0) {};
  // Getter
  State at(const int row, const int colum) const;

 private:
  std::vector<State> matrix_;
  int rows_;
  int columns_;
};
#endif