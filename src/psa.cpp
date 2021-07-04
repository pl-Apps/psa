#include "psa.h"

int main(int argc, char** argv) {
    char* execName = argv[0];
    std::string firstArg;
    if(argc >= 2) {
        
        firstArg = argv[1];
    }
    if(argc <= 1) {
        
        std::cout << "\x1b[31mNo arguments\x1b[0m\nType " << execName << " -h for help";
        exit(1);
    }
    if(firstArg == "-h") {
        help(execName);
        exit(0);
    }
    else if(firstArg == "-c") {
        if(argc <= 2) {
            std::cout << "\x1b[31mNo archive name\x1b[0m";
            exit(1);
        }
        createarchive(argv[2]);
        exit(0);
    }
    else if(firstArg == "-a") {
        if(argc <= 3) {
            std::cout << "\x1b[31mNo archive/file name\x1b[0m";
        }
        addfiletoarchive(argv[2], argv[3]);
    }
    else if(firstArg == "-e") {
        if(argc <= 2) {
            std::cout << "\x1b[31mNo archive name\x1b[0m";
            exit(1);
        }
        extractarchive(argv[2]);
        exit(0);
    }
    else
    {
        std::cout << "\x1b[31mUnknow argument\x1b[0m\nType " << execName << " -h for help";
        exit(1);
    }
}