#include "board.h"

Board::Board() : board(9, std::vector<char>(9, '\0')), content("") {}

Board::Board(const std::string& content) {
    this->content = content;
    fillBoard(this->content);
}

void Board::printBoard() const {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << this->board[i][j] << " |";
        }
        std::cout << '\n';
    }
}

std::string Board::getContent() const {
    return this->content;
}

bool Board::verifyContent(const std::string& content) {
    if (content.size() != 81) {
        return false;
    }
    for (size_t i = 0; i < content.size(); i++) {
        char ch = content[i];
        if (ch == '.' || std::isdigit(ch)) {
            continue;
        }
        return false;
    }
    return true;
}

void Board::fillBoard(const std::string& content) {
    if (!verifyContent(content)) {
        throw std::invalid_argument("INVALID CONTENT");
    }
    
    this->board = std::vector<std::vector<char> >(9, std::vector<char>(9, '\0'));
    int idx = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            this->board[i][j] = content[idx++];
        }
    }
}

bool Board::isValidMove(int row, int col, char val) const {
    // Check row
    for (int i = 0; i < 9; i++) {
        if (this->board[row][i] == val) {
            return false;
        }
    }

    // Check column
    for (int i = 0; i < 9; i++) {
        if (this->board[i][col] == val) {
            return false;
        }
    }

    // Check 3x3 box
    int startRow = row - (row % 3);
    int startCol = col - (col % 3);
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (this->board[i][j] == val) {
                return false;
            }
        }
    }

    return true;
}

bool Board::isSolved() const {
    // Check if any cell is empty ('.')
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (this->board[i][j] == '.') {
                return false;
            }
        }
    }

    // If no empty cells found, the board is solved
    return true;
}

void Board::setCell(int row, int col, char val) {
    if (row >= 0 && row < 9 && col >= 0 && col < 9) {
        this->board[row][col] = val;
    }
}

char Board::getCell(int row, int col) const {
    if (row >= 0 && row < 9 && col >= 0 && col < 9) {
        return this->board[row][col];
    }
    return '\0';
}
