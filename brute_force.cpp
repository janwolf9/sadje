#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cout << "Please provide a file name as a command line argument.\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    std::string line;

    if (!file.is_open()) {
        std::cout << "Failed to open file" << "\n";
        return 1;
    }

    return 0;
}

