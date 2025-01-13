#ifndef SOLVER_H
#define SOLVER_H

#include "board.h" // Include the Board class

class Solver {

public: 
  Solver(); 
  void SolveBoard(Board& board);

private: 
  void algorithm(Board& board, int row, int col); 
}; 

#endif
