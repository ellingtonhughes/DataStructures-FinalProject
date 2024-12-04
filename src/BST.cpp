#include "BST.h"
#include <fstream>
#include <iostream>

Node* BST::insert(Node* node, int key) {
    if (!node) return new Node(key);

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else {
        node->right = insert(node->right, key);
    }

    return node;
}

void BST::insert(int key) {
    root = insert(root, key);
}

// Helper function to find the node with the minimum key in a subtree
Node* findMin(Node* node) {
    while (node && node->left) {
        node = node->left;
    }
    return node;
}

Node* removeHelper(Node* node, int value) {
    if (!node) return nullptr; // Base case: node is null, return null

    if (value < node->key) {
        node->left = removeHelper(node->left, value); // Search in left subtree
    } else if (value > node->key) {
        node->right = removeHelper(node->right, value); // Search in right subtree
    } else {
        // Node to be deleted is found

        // Case 1: Node has no children (leaf node)
        if (!node->left && !node->right) {
            delete node;
            return nullptr;
        }

        // Case 2: Node has one child
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        // Case 3: Node has two children
        // Find the in-order successor (smallest node in the right subtree)
        Node* temp = findMin(node->right);

        // Copy the in-order successor's content to the current node
        node->key = temp->key;

        // Delete the in-order successor
        node->right = removeHelper(node->right, temp->key);
    }

    return node;
}

// You can implement your remove function like this:
void BST::remove(int value) {
    // Implement your BST remove logic (this can be tricky and involves handling three cases: node with no children, one child, or two children)
    root = removeHelper(root, value);
}


void inOrderDisplay(Node* node) {
    if (node) {
        inOrderDisplay(node->left);
        std::cout << node->key << " "; // Print the key of the node
        inOrderDisplay(node->right);
    }
}

// Implement the display function:
void BST::display() const {
    // You can use a simple in-order traversal to display keys, for example
    inOrderDisplay(root);
}

// Implement the loadFromFile function to load the BST from a file
void BST::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    int value;

    while (file >> value) {
        insert(value);
    }

    file.close();
}

// Visualization-related methods
void BST::calculatePositions(Node* node, int x, int y, int xOffset) {
    if (!node) return;

    node->x = x;
    node->y = y;

    // Recur for left and right children
    calculatePositions(node->left, x - xOffset, y + 100, xOffset / 2);
    calculatePositions(node->right, x + xOffset, y + 100, xOffset / 2);
}

void BST::drawTree(Node* node, sf::RenderWindow& window, sf::Font& font) {
    if (!node) return;

    // Draw edges (lines)
    if (node->left) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(node->x, node->y)),
            sf::Vertex(sf::Vector2f(node->left->x, node->left->y))
        };
        window.draw(line, 2, sf::Lines);
    }

    if (node->right) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(node->x, node->y)),
            sf::Vertex(sf::Vector2f(node->right->x, node->right->y))
        };
        window.draw(line, 2, sf::Lines);
    }

    // Draw node (circle)
    sf::CircleShape circle(20);
    circle.setFillColor(sf::Color::Blue);
    circle.setPosition(node->x - 20, node->y - 20); // Center the circle
    window.draw(circle);

    // Draw node value (text)
    sf::Text text;
    text.setFont(font);
    text.setString(std::to_string(node->key));
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    text.setPosition(node->x - 10, node->y - 15); // Center the text
    window.draw(text);

    // Recur for left and right children
    drawTree(node->left, window, font);
    drawTree(node->right, window, font);
}

void BST::visualize(sf::RenderWindow& window, sf::Font& font) {
    if (!root) return;

    // Calculate positions for each node
    calculatePositions(root, 400, 50, 200); // Start at root (400, 50) with offset 200

    // Draw the tree
    drawTree(root, window, font);
}
