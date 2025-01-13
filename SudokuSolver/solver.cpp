#include "board.h"
#include "solver.h"

Solver::Solver() {
  // empty constructor
}

void Solver::SolveBoard(Board& board) {
  // Don't need redundant board checking 
  algorithm(board, 0, 0); 
}

void Solver::algorithm(Board& board, int row, int col) {
  if (row == 9) {
        return;
  }

  // Move to the next row if we’re past the last column
  int nextRow = (col == 8) ? row + 1 : row;
  int nextCol = (col == 8) ? 0 : col + 1;

  // If the current cell is already filled, move to the next cell
  if (board.getCell(row, col) != '.') {
     algorithm(board, nextRow, nextCol);
     return;
  }

   // Try numbers '1' to '9' in the current cell
    for (char num = '1'; num <= '9'; ++num) {
        if (board.isValidMove(row, col, num)) {
            board.setCell(row, col, num); // Place the number
            algorithm(board, nextRow, nextCol); // Recursively solve the next cells

            // If the board is solved, return
            if (board.isSolved()) {
                return;
            }

            // Backtrack: Reset the cell to '.'
            board.setCell(row, col, '.');
        }
    }
}
