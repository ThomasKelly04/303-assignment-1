#include "Header.h"

ArrayFunctions::ArrayFunctions(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        throw std::runtime_error("Failed to open the file.");
    }

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (!(inputFile >> array[i][j])) {
                throw std::runtime_error("Error reading data from the file.");
            }
            colCount++;
        }
        rowCount++;
        colCount = 0;
    }
}

int ArrayFunctions::findInteger(int num) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (array[i][j] == num) {
                return i * COLS + j; // Return the index as a single integer
            }
        }
    }
    return -1; // Return -1 if the number is not found
}

std::pair<int, int> ArrayFunctions::modifyInteger(int index, int newValue) {
    if (index < 0 || index >= ROWS * COLS) {
        throw std::out_of_range("Index out of range");
    }

    int row = index / COLS;
    int col = index % COLS;
    int oldValue = array[row][col];
    array[row][col] = newValue;

    return std::make_pair(oldValue, newValue); // Fixed order of old and new values
}

void ArrayFunctions::addInteger(int num) {
    if (rowCount < ROWS) {
        array[rowCount][colCount] = num;
        colCount++;

        if (colCount >= COLS) {
            colCount = 0;
            rowCount++;
        }
    }
    else {
        throw std::overflow_error("Array is full");
    }
}

void ArrayFunctions::replaceOrRemove(int index, bool remove) {
    if (index < 0 || index >= ROWS * COLS) {
        throw std::out_of_range("Index out of range");
    }

    int row = index / COLS;
    int col = index % COLS;

    if (remove) {
        array[row][col] = 0;
    }
    else {
        array[row][col] = 0;
    }
}

void ArrayFunctions::printArray() const {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << array[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
