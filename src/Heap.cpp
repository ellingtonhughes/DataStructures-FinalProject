#include "Heap.h"
#include <fstream>
#include <sstream>
#include <iostream>

Heap::~Heap() {}

void Heap::loadFromFile(const std::string& filename){

}

void Heap::insert(int value){

}

void Heap::remove(int value){

}

void Heap::display() const {

}
/*
void Heap::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return;
    }

    int value;

    if(!(file>>value)){
        std::cerr<<"Error: Invalid data format in file\n";
        return;
    }

    while (file >> value) {
        insert(value);
    }

    file.close();
}
*/