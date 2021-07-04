#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <windows.h>

std::string tobin(std::string value, char divider) {
    std::string ret;
    char c;
    for(char &c : value) {
        ret += std::bitset<8>(c).to_string();
        ret += divider;
    }
    return ret;
}

std::string bintostring(std::string value, char divider) {
    std::string ret;
    std::string tmp;
    char c;
    int i = 0;
    for(char &c : value) {
        if(c != divider) {
            tmp += c;
        }
        else
        {
            ret += static_cast<char>(std::bitset<8>(tmp).to_ullong());
            tmp = "";
        }
        i++;
    }
    if(i = 36) {
        ret = ret.substr(0, ret.size()-2);
    }
    return ret;
    LPCWSTR test;
    
}

std::string* split_string(std::string target, char divider) {
    char i;
    std::string* ret;
    std::string tmp;
    for(char i : target) {
        if(i == divider) {
            ret[i] = tmp;
            continue;
        }
        tmp += i;
    }
    return ret;
}

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
    std::ofstream archive;
    archive.open(archivename);
    archive << "";
    archive.close();
}

void extractarchive(char* archivename) {
    std::fstream archive;
    std::string line;
    std::string tmp;
    std::string* files_content;
    std::string* files_name;
    bool contl;
    int i = 0;
    while(std::getline(archive, line)) {
        if(line.erase(0, 1) == "/") {
            i++;
            tmp = "";
            continue;
        }
        tmp += line;
        files_content[i] = tmp;
    }
    for(int i=0; sizeof(files_content) < i; i++) {
        files_content[i] = bintostring(files_content[i], '|');
        std::fstream target(files_name[i]);
        target << files_content[i];
    }
}

void extractfilefromarchive(char* archivename, char* filename) {
    
}

void addfiletoarchive(char* archivename, char* filename) {
    std::fstream archive(archivename, std::ios_base::app);
    std::fstream target(filename);
    std::string line;
    archive << "/";
    archive << filename;
    archive << "\n";
    while(std::getline(target, line)) {
        archive << tobin(line, '|');
    }
    archive << "\n";
    archive.close();
}