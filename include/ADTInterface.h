#ifndef ADT_INTERFACE_H
#define ADT_INTERFACE_H
#pragma once
#include <string>

class ADTInterface {
public:
    virtual void insert(int value) = 0;
    virtual void remove(int value) = 0;
    virtual void display() const = 0;
    virtual void loadFromFile(const std::string& filename) = 0;
    virtual ~ADTInterface() = default;
};

#endif

