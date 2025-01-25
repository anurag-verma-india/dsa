
// // deepseek.com (r1)

// /* Prompt
// Now edit the create_new.cpp to create a new empty text file input.txt

// Also give me a cpp file that implements a function read_input() that reads the input.txt file as stdin and gives error if it's unable to do so
// */

// /* Compile
// ```bash
// g++ -o read_input read_input.cpp
// ```
// */

#include <cstdlib>
#include <fstream>
#include <iostream>

void read_input(const std::string& filePath) {
    // Redirect stdin to read from the file
    std::ifstream inputFile(filePath);
    if (!inputFile) {
        std::cerr << "Error: Unable to open file " << filePath << std::endl;
        exit(EXIT_FAILURE);
    }

    // Redirect std::cin to read from the file
    std::cin.rdbuf(inputFile.rdbuf());

    // Read input from the file (now stdin)
    std::string line;
    while (std::getline(std::cin, line)) {
        std::cout << "Read from file: " << line << std::endl;
    }

    // Restore std::cin to its original state (optional)
    inputFile.close();
    std::cin.rdbuf(std::cin.rdbuf());
}

int main() {
    std::string filePath = "./example/input.txt";  // Path to the input file
    read_input(filePath);
    return 0;
}