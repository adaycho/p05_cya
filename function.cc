#include "function.h"

// Constructor
Function::Function(std::vector<State> function, int rows, int columns) {
  rows_ = rows;
  columns_ = columns;
  matrix_ = function;
}

// Getter del valor en cierta fila y columna
State Function::at(const int row, const int column) const{
  return matrix_[row*columns_ + column];
}