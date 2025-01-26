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
Here the code for creating a new dsa problem folder

```
#include <iostream>
#include <filesystem>
#include <fstream>
#include <cstdlib>

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
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <folder_name>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string folderName = argv[1];

    // Create the new folder
    createFolder(folderName);

    // Copy files
    copyFile("./utility/read.cpp", "./" + folderName + "/read.cpp");
    copyFile("./utility/skeleton.cpp", "./" + folderName + "/0-" + folderName + ".cpp");

    // Create an empty input.txt file
    createEmptyFile("./" + folderName + "/input.txt");

    return EXIT_SUCCESS;
}
```

Make it so that the compiled program also accepts a -s or -i flag and includes either ./read_string_from_stdin.cpp or ./read_int_from_stdin.cpp in the same manner as read.cpp (if no flag is provided it includes the int one)
Also give me the code for these two cpp files as well
*/

// ---------------------------------------------------------------------------

/* Prompt 2
Now edit the create_new.cpp to create a new empty text file input.txt

Also give me a cpp file that implements a function read_input() that reads the input.txt file as stdin and gives error if it's unable to do so
*/

// #include <iostream>
// #include <filesystem>
// #include <fstream>
// #include <cstdlib>

// namespace fs = std::filesystem;

// void createFolder(const std::string& folderName) {
//     if (!fs::exists(folderName)) {
//         if (fs::create_directory(folderName)) {
//             std::cout << "Folder created: " << folderName << std::endl;
//         } else {
//             std::cerr << "Failed to create folder: " << folderName << std::endl;
//             exit(EXIT_FAILURE);
//         }
//     } else {
//         std::cout << "Folder already exists: " << folderName << std::endl;
//     }
// }

// void copyFile(const std::string& source, const std::string& destination) {
//     try {
//         fs::copy(source, destination, fs::copy_options::overwrite_existing);
//         std::cout << "Copied " << source << " to " << destination << std::endl;
//     } catch (const fs::filesystem_error& e) {
//         std::cerr << "Error copying file: " << e.what() << std::endl;
//         exit(EXIT_FAILURE);
//     }
// }

// void createEmptyFile(const std::string& filePath) {
//     std::ofstream file(filePath);
//     if (file) {
//         std::cout << "Created empty file: " << filePath << std::endl;
//     } else {
//         std::cerr << "Failed to create file: " << filePath << std::endl;
//         exit(EXIT_FAILURE);
//     }
// }

// int main(int argc, char* argv[]) {
//     if (argc != 2) {
//         std::cerr << "Usage: " << argv[0] << " <folder_name>" << std::endl;
//         return EXIT_FAILURE;
//     }

//     std::string folderName = argv[1];

//     // Create the new folder
//     createFolder(folderName);

//     // Copy files
//     copyFile("./utility/read.cpp", "./" + folderName + "/read.cpp");
//     copyFile("./utility/skeleton.cpp", "./" + folderName + "/0-" + folderName + ".cpp");

//     // Create an empty input.txt file
//     createEmptyFile("./" + folderName + "/input.txt");

//     return EXIT_SUCCESS;
// }

// ---------------------------------------------------------------------------

/* Prompt 1

Give me a cpp file (create_new.cpp) that creates a new folder "example" from the following command
```bash
create_new "example"
```
Then copy the file "./utility/read.cpp" to "./example/read.cpp"
And also copy the file "./utility/skeleton.cpp" to "./example/0-example.cpp"
*/

// #include <cstdlib>
// #include <filesystem>
// #include <iostream>

// namespace fs = std::filesystem;

// void createFolder(const std::string& folderName) {
//     if (!fs::exists(folderName)) {
//         if (fs::create_directory(folderName)) {
//             std::cout << "Folder created: " << folderName << std::endl;
//         } else {
//             std::cerr << "Failed to create folder: " << folderName << std::endl;
//             exit(EXIT_FAILURE);
//         }
//     } else {
//         std::cout << "Folder already exists: " << folderName << std::endl;
//     }
// }

// void copyFile(const std::string& source, const std::string& destination) {
//     try {
//         fs::copy(source, destination, fs::copy_options::overwrite_existing);
//         std::cout << "Copied " << source << " to " << destination << std::endl;
//     } catch (const fs::filesystem_error& e) {
//         std::cerr << "Error copying file: " << e.what() << std::endl;
//         exit(EXIT_FAILURE);
//     }
// }

// int main(int argc, char* argv[]) {
//     if (argc != 2) {
//         std::cerr << "Usage: " << argv[0] << " <folder_name>" << std::endl;
//         return EXIT_FAILURE;
//     }

//     std::string folderName = argv[1];

//     // Create the new folder
//     createFolder(folderName);

//     // Copy files
//     copyFile("./utility/read.cpp", "./" + folderName + "/read.cpp");
//     copyFile("./utility/skeleton.cpp", "./" + folderName + "/0-" + folderName + ".cpp");

//     return EXIT_SUCCESS;
// }
// ---------------------------------------------------------------------------