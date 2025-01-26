// deepseek.com (r1)

/*
Compile command
```bash
g++ -o create_new create_new.cpp -lstdc++fs
```
*/
/* Usage
./create_folder my_problem_folder [ -s | -i | (default int) ]
*/
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

void createFolder(const std::string& folderName) {
    if (!fs::exists(folderName)) {
        if (fs::create_directory(folderName)) {
            std::cout << "Folder created: " << folderName << std::endl;
        } else {
            std::cerr << "Failed to create folder: " << folderName << std::endl;
            exit(EXIT_FAILURE);
        }
    } else {
        std::cout << "Folder already exists: " << folderName << std::endl;
    }
}

void copyFile(const std::string& source, const std::string& destination) {
    try {
        fs::copy(source, destination, fs::copy_options::overwrite_existing);
        std::cout << "Copied " << source << " to " << destination << std::endl;
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error copying file: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

void createEmptyFile(const std::string& filePath) {
    std::ofstream file(filePath);
    if (file) {
        std::cout << "Created empty file: " << filePath << std::endl;
    } else {
        std::cerr << "Failed to create file: " << filePath << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 3) {
        std::cerr << "Usage: " << argv[0] << " <folder_name> [-s | -i]" << std::endl;
        return EXIT_FAILURE;
    }

    std::string folderName = argv[1];
    std::string readFile = "./utility/read_int.cpp";  // Default to int

    if (argc == 3) {
        std::string flag = argv[2];
        if (flag == "-s") {
            readFile = "./utility/read_string.cpp";
        } else if (flag == "-i") {
            readFile = "./utility/read_int.cpp";
        } else {
            std::cerr << "Invalid flag: " << flag << std::endl;
            return EXIT_FAILURE;
        }
    }

    // Create the new folder
    createFolder(folderName);

    // Copy files
    copyFile(readFile, "./" + folderName + "/read.cpp");
    copyFile("./utility/skeleton.cpp", "./" + folderName + "/0-" + folderName + ".cpp");

    // Create an empty input.txt file
    createEmptyFile("./" + folderName + "/input.txt");

    return EXIT_SUCCESS;
}


/* Prompt
Here is the code for my cpp file

```cpp
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

void createFolder(const std::string& folderName) {
    if (!fs::exists(folderName)) {
        if (fs::create_directory(folderName)) {
            std::cout << "Folder created: " << folderName << std::endl;
        } else {
            std::cerr << "Failed to create folder: " << folderName << std::endl;
            exit(EXIT_FAILURE);
        }
    } else {
        std::cout << "Folder already exists: " << folderName << std::endl;
    }
}

void copyFile(const std::string& source, const std::string& destination) {
    try {
        fs::copy(source, destination, fs::copy_options::overwrite_existing);
        std::cout << "Copied " << source << " to " << destination << std::endl;
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error copying file: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

void createEmptyFile(const std::string& filePath) {
    std::ofstream file(filePath);
    if (file) {
        std::cout << "Created empty file: " << filePath << std::endl;
    } else {
        std::cerr << "Failed to create file: " << filePath << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 3) {
        std::cerr << "Usage: " << argv[0] << " <folder_name> [-s | -i]" << std::endl;
        return EXIT_FAILURE;
    }

    std::string folderName = argv[1];
    std::string readFile = "./utility/read_int.cpp";  // Default to int

    if (argc == 3) {
        std::string flag = argv[2];
        if (flag == "-s") {
            readFile = "./utility/read_string.cpp";
        } else if (flag == "-i") {
            readFile = "./utility/read_int.cpp";
        } else {
            std::cerr << "Invalid flag: " << flag << std::endl;
            return EXIT_FAILURE;
        }
    }

    // Create the new folder
    createFolder(folderName);

    // Copy files
    copyFile(readFile, "./" + folderName + "/read.cpp");
    copyFile("./utility/skeleton.cpp", "./" + folderName + "/0-" + folderName + ".cpp");

    // Create an empty input.txt file
    createEmptyFile("./" + folderName + "/input.txt");

    return EXIT_SUCCESS;
}
```
Make it so that the input flag and folder_name are position independent, anything that start with -  (dash) is treated a as a flag and (only two inputs are allowed)
*/