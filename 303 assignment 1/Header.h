#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <stdexcept>

const int ROWS = 10;
const int COLS = 10;

class ArrayFunctions {
public:
    ArrayFunctions(const std::string& filename);

    int findInteger(int num);
    std::pair<int, int> modifyInteger(int index, int newValue);
    void addInteger(int num);
    void replaceOrRemove(int index, bool remove);

    void printArray() const;

private:
    int array[ROWS][COLS] = { 0 };
    int rowCount = 0;
    int colCount = 0;
};

#endif
