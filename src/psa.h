#include <iostream>
#include <fstream>
#include <string>

void help(char* execName) {
    std::cout << execName << " [OPTIONS]\n";
    std::cout << "\t-h                                     Show this text\n";
    std::cout << "\t-c [ARCHIVE NAME]                      Create empty archive file\n";
    std::cout << "\t-e [ARCHIVE NAME]                      Extract all file from archive\n";
    std::cout << "\t-f [ARCHIVE NAME] [FILE NAME]          Extract file from archive\n";
    std::cout << "\t-a [ARCHIVE NAME] [FILE NAME]          Add file to archive\n";
    std::cout << "\t-r [ARCHIVE NAME] [FILE NAME]          Remove file from archive\n";
}

void createarchive(char* archivename) {
    std::fstream archive(archivename);
    archive << "";
}