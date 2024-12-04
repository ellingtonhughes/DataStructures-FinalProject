#pragma once
#include "ADTInterface.h"
#include <SFML/Graphics.hpp>
#include <string>

struct Node {
    int key;
    Node* left;
    Node* right;
    int x, y; // Position for visualization

    Node(int k) : key(k), left(nullptr), right(nullptr), x(0), y(0) {}
};

class BST : public ADTInterface {
private:
    Node* root;

    // Private insert and helper methods
    Node* insert(Node* node, int key);
    void calculatePositions(Node* node, int x, int y, int xOffset);
    void drawTree(Node* node, sf::RenderWindow& window, sf::Font& font);

public:
    BST() : root(nullptr) {}

    // Override methods from ADTInterface
    void insert(int key) override;
    void remove(int value) override;
    void display() const override;
    void loadFromFile(const std::string& filename) override;

    // Visualization and utility methods
    void visualize(sf::RenderWindow& window, sf::Font& font);
};
