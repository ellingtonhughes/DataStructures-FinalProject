#ifndef GUIMANAGER_H
#define GUIMANAGER_H
#include <SFML/Graphics.hpp>
#include <string>

// Include ADT headers
#include "ADTInterface.h"
#include "AVL.h"
#include "Heap.h"
#include "BST.h"
#include "BTree.h"
#include "PriorityQueue.h"
#include "RedBlack.h"
#include "StackQueue.h"

class Menu {
private:
    std::vector<sf::Text> menuItems;
    sf::Font font;
    int selectedItemIndex;
    std::vector<sf::RectangleShape> rectangles;

public:
    Menu(float width, float height, sf::Font& font);
    void handleEvent(const sf::Event& event);
    void setOptions(const std::vector<std::string>& options);
    void draw(sf::RenderWindow& window);
    void moveUp();
    void moveDown();
    int getSelectedItemIndex() const;

    sf::Font& getFont(){
        return font;
    }
};

void selectADT(int option);
void performOperation(int operation, Menu& menu, sf::RenderWindow& window, int& currentMenu);


class TextInputBox {
private:
    sf::RectangleShape box;
    sf::Text text;
    sf::Font font;
    std::string input;
    bool hasFocus;  // Add this line

public:
    TextInputBox(float x, float y, float width, float height) 
        : hasFocus(false)  // Initialize hasFocus
    {
        font.loadFromFile("arial.ttf");
        box.setSize(sf::Vector2f(width, height));
        box.setPosition(x, y);
        box.setFillColor(sf::Color::White);
        text.setFont(font);
        text.setPosition(x + 5, y + 5);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Black);
    }

    void setFocus(bool focus) {
        hasFocus = focus;
    }

    void handleEvent(const sf::Event& event) {
        if (hasFocus && event.type == sf::Event::TextEntered) {
            if (event.text.unicode == '\b' && !input.empty()) {
                input.pop_back();  // Handle backspace
            } else if (event.text.unicode < 128) {
                input += static_cast<char>(event.text.unicode);
            }
            text.setString(input);
        }
    }

    std::string getInput() const {
        return input;
    }

    void draw(sf::RenderWindow& window) {
        window.draw(box);
        window.draw(text);
    }
};



#endif