#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main(int argc, char* argv[]){
    if (argc < 2){
        std::cerr << "Usage: downloads-sorter <path>\n";
        return 1;
    }

    fs::path dir(argv[1]);
    if (!fs::exists(dir) || !fs::is_directory(dir)){
        std::cerr << "Error:" << dir.string() << "is not a valid directory\n";
        return 1;
    }

    std::cout << "Scanning:" << dir << "\n";
    int count = 0;
    for (const auto& entry : fs::directory_iterator(dir)){
        if (entry.is_regular_file()) {
            std::cout << " " << entry.path().filename().string() << "(" << entry.file_size() << "bytes)\n";
            ++count;
        }
    }
    std::cout << "Found" << count << "files\n";
    return 0;
}