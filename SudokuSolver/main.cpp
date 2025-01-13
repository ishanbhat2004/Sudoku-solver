#include "solver.h"
#include "board.h"
#include <iostream>
#include <string>

int main() {
    // Example input for the Sudoku board in a single string format
    std::string boardContent =
        "53..7...."
        "6..195..."
        ".98....6."
        "8...6...3"
        "4..8.3..1"
        "7...2...6"
        ".6....28."
        "...419..5"
        "....8..79";

    // Create the Board object and initialize it with the given content
    Board board(boardContent);

    // Validate the initial board using the built-in functionality
    if (!board.getContent().empty() && !board.isSolved()) {
        std::cout << "Initial board:" << std::endl;
        board.printBoard();

        // Create the Solver object
        Solver solver;

        // Solve the Sudoku board
        solver.SolveBoard(board);

        // Check if the board is solved and print the result
        if (board.isSolved()) {
            std::cout << "\nSolved board:" << std::endl;
            board.printBoard();
        } else {
            std::cerr << "\nThe board could not be solved." << std::endl;
        }
    } else {
        std::cerr << "Invalid board or already solved!" << std::endl;
    }

    return 0;
}

