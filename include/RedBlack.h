#include <iostream>
#include "ADTInterface.h"

class RedBlack : public ADTInterface{
public: 
    ~RedBlack() override;
    void loadFromFile(const std::string& filename) override;

    void insert(int value) override; 

    void remove(int value) override;

    void display() const override;

};