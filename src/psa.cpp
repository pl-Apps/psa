#include "psa.h"

int main(int argc, char** argv) {
    char* execName = argv[0];
    std::string firstArg;
    if(argc >= 2) {
        firstArg = argv[1];
    }
    else if(argc <= 1) {
        std::cout << "No arguments\nType " << execName << " -h for help";
        exit(1);
    }
    else if(firstArg == "-h") {
        help(execName);
        exit(0);
    }
    else if(firstArg == "-c") {
        if(argc <= 2) {
            std::cout << "No archive name";
        }
        else
        {
            createarchive(argv[2]);
            exit(0);
        }
    }
}