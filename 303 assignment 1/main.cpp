
#include "Header.h"

int main() {
    try {
        ArrayFunctions arrayFunctions("data.txt");

        int index = arrayFunctions.findInteger(42);
        if (index != -1) {
            std::cout << "Integer 42 found at index " << index << std::endl;
        }
        else {
            std::cout << "Integer 42 not found." << std::endl;
        }

        std::pair<int, int> modifiedValue = arrayFunctions.modifyInteger(5, 99);
        std::cout << "Modified value: Old = " << modifiedValue.first << ", New = " << modifiedValue.second << std::endl;

        arrayFunctions.addInteger(123);
        arrayFunctions.replaceOrRemove(15, true); // Remove the value at index 15

        // Print the modified array
        arrayFunctions.printArray();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
