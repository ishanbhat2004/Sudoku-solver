#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

class Board {
private:
    std::vector<std::vector<char> > board;
    std::string content;

public:
    // Constructors
    Board();
    Board(const std::string& content);
    
    // Public member functions
    void printBoard() const;
    std::string getContent() const;
    bool isValidMove(int row, int col, char val) const;  // Added this
    bool isSolved() const;                               // Added this
    void setCell(int row, int col, char val);           // Added this
    char getCell(int row, int col) const;               // Added this

private:
    // Private member functions
    bool verifyContent(const std::string& content);
    void fillBoard(const std::string& content);
};
#endif
