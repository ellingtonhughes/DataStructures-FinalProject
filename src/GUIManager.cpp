#include <SFML/Graphics.hpp>
#include "GUIManager.h"
#include <iostream>
#include <vector>

    Menu::Menu(float width, float height, sf::Font& font) : selectedItemIndex(0) {

        // if (!font.loadFromFile("arial.ttf")) {
        //     std::cerr << "Error loading font\n";
        // }

 std::vector<std::string> options = {"Heap", "BST", "Stack", 
    "Queue", "AVL", "Red-Black", "B-Tree","Priority Queue", "Import from File"};
   

    for (size_t i = 0; i < options.size(); ++i) {
        sf::Text item;
        sf::RectangleShape rectangle;

        rectangle.setSize(sf::Vector2f(260.f, 38.f));
        rectangle.setFillColor(sf::Color::Blue);
        rectangle.setPosition(width / 2 - 100, height / 2 - 150 + i * 62);
        rectangles.push_back(rectangle);

        item.setFont(font);
        item.setString(options[i]);
        item.setCharacterSize(30);
        item.setFillColor(i == 0 ? sf::Color::Magenta : sf::Color::White);
        item.setPosition(sf::Vector2f(width / 2 - 100, height / 2 - 150 + i * 62));
        menuItems.push_back(item);
        
        
    }
    }

    ////
    void Menu::setOptions(const std::vector<std::string>& options){
    // Instead of clearing, just modify the text of existing menu items
    for (size_t i = 0; i < options.size(); ++i) {
        // Ensure that we don't exceed the number of existing menu items
        if (i < menuItems.size()) {
            menuItems[i].setString(options[i]);
            menuItems[i].setPosition(400, 100 + i * 62);
            menuItems[i].setFillColor(i == 0 ? sf::Color::Magenta : sf::Color::White);
            
            rectangles[i].setPosition(350, 100 + i * 62);  // Adjust rectangle positions
        } else {
            // Create new items if we have more options than the existing ones
            sf::Text item;
            item.setFont(font);
            item.setString(options[i]);
            item.setCharacterSize(30);
            item.setFillColor(i == 0 ? sf::Color::Magenta : sf::Color::White);
            item.setPosition(410, 200 + i * 62);
            menuItems.push_back(item);

            sf::RectangleShape rectangle;
            rectangle.setSize(sf::Vector2f(260.f, 38.f));
            rectangle.setFillColor(sf::Color::Blue);
            rectangle.setPosition(400, 100 + i * 62);
            rectangles.push_back(rectangle);
        }
    }
}

 //

    void Menu::draw(sf::RenderWindow& window) {
        for (const auto& rectangle : rectangles) {
            //  std::cout << "Rectangle at (" << rectangle.getPosition().x 
            //       << ", " << rectangle.getPosition().y << ")" << std::endl;
        window.draw(rectangle);
        }
        
        for (const auto& item : menuItems) {
            // std::cout << "Text: " << item.getString().toAnsiString() 
            //       << " at (" << item.getPosition().x 
            //       << ", " << item.getPosition().y << ")" << std::endl;
        window.draw(item);
        }
        
    }

    void Menu::moveUp() {
        if (selectedItemIndex > 0) {
            menuItems[selectedItemIndex].setFillColor(sf::Color::White);
            selectedItemIndex--;
            menuItems[selectedItemIndex].setFillColor(sf::Color::Magenta);
        }
    }
    
    void Menu::moveDown() {
        if (selectedItemIndex < menuItems.size() - 1) {
        menuItems[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menuItems[selectedItemIndex].setFillColor(sf::Color::Magenta);
        }
    }   

    int Menu::getSelectedItemIndex() const {
        return selectedItemIndex;
    }





// Example Menu Integration
// Global pointers to current ADT
ADTInterface* currentADT = nullptr;
Heap heapADT;
BST bstADT;
AVL avlADT;
BTree btreeADT;
PriorityQueue pqADT;
RedBlack redblackADT;
StackQueue sqADT;

// Menu Actions
void selectADT(int option) {
    if (option == 0) {
        currentADT = &heapADT;
    } else if (option == 1) {
        currentADT = &bstADT;
    }else if(option == 2) {
        currentADT = &sqADT;
    }else if(option == 3) {
        currentADT = &sqADT;
    }else if(option == 4) {
        currentADT = &avlADT;
    }else if(option == 5) {
        currentADT = &btreeADT;
    }else if(option == 6) {
        currentADT = &pqADT;
    }else if(option == 7) {
        currentADT = &redblackADT;
    }
}

// Perform operations on the current ADT
void performOperation(int operation, Menu& menu, sf::RenderWindow& window, int& currentMenu) {
    static BST bst;  // Initialize once
    
    if (currentMenu == 0) {  // Main menu
        switch (operation) {
            case 0:  // Navigate to Insert/Delete/Display menu
                menu.setOptions({"Insert", "Delete", "Display"}); 
                currentMenu = 1;
                break;
            case 1:  
                menu.setOptions({"Insert", "Delete", "Display"}); 
                currentMenu = 1;
                break;
            case 2:  // Navigate to Insert/Delete/Display menu
                menu.setOptions({"Insert", "Delete", "Display"}); 
                currentMenu = 1;
                break;
            case 3:  // Navigate to Insert/Delete/Display menu
                menu.setOptions({"Insert", "Delete", "Display"}); 
                currentMenu = 1;
                break;
            case 4:  // Navigate to Insert/Delete/Display menu
                menu.setOptions({"Insert", "Delete", "Display"}); 
                currentMenu = 1;
                break;
            case 5:  // Navigate to Insert/Delete/Display menu
                menu.setOptions({"Insert", "Delete", "Display"}); 
                currentMenu = 1;
                break;
            case 6:  // Navigate to Insert/Delete/Display menu
                menu.setOptions({"Insert", "Delete", "Display"}); 
                currentMenu = 1;
                break;
            case 7:  // Navigate to Insert/Delete/Display menu
                menu.setOptions({"Insert", "Delete", "Display"}); 
                currentMenu = 1;
                break;
            default:
                break;
        }
    } 
    else if (currentMenu == 1) { 
    if (currentADT != nullptr) {
        switch (operation) {
            case 0: {  // Insert Operation
                TextInputBox inputBox(100, 200, 200, 30);  // Get input from the user
                bool inputReceived = false;

                while (!inputReceived) {
                    sf::Event event;
                    while (window.pollEvent(event)) {
                        if (event.type == sf::Event::Closed) {
                            window.close();
                            return;
                        }
                        inputBox.handleEvent(event);
                        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                            inputReceived = true;
                            int value = std::stoi(inputBox.getInput());
                            currentADT->insert(value);  // Perform the insert operation on the selected ADT
                        }
                    }
                    window.clear(sf::Color::Black);
                    inputBox.draw(window);
                    window.display();
                }
                break;
            }
            case 1: {  // Delete Operation
                TextInputBox inputBox(100, 200, 200, 30);
                bool inputReceived = false;

                while (!inputReceived) {
                    sf::Event event;
                    while (window.pollEvent(event)) {
                        if (event.type == sf::Event::Closed) {
                            window.close();
                            return;
                        }
                        inputBox.handleEvent(event);
                        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                            inputReceived = true;
                            int value = std::stoi(inputBox.getInput());
                            currentADT->remove(value);  // Perform delete on the selected ADT
                        }
                    }
                    window.clear(sf::Color::Black);
                    inputBox.draw(window);
                    window.display();
                }
                break;
            }
            case 2:  // Display Operation
                window.clear();
                currentADT->display();  // Display the ADT's contents
                window.display();
                break;
            default:
                std::cerr << "Invalid operation.\n";
                break;
        }

        // After performing the operation, return to the main menu
        menu.setOptions({"Heap", "BST", "Stack", "Queue", "AVL", "BTree", "Priority Queue", "RedBlack", "Import From File"});
        currentMenu = 0;
    } else {
        std::cerr << "No ADT selected.\n";  // Handle cases where no ADT is selected
    }
}
}

void Menu::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            moveUp();  // Move the selection up
        } else if (event.key.code == sf::Keyboard::Down) {
            moveDown();  // Move the selection down
        } else if (event.key.code == sf::Keyboard::Enter) {
            // Handle the enter key (you may need to call some function here)
            std::cout << "Enter key pressed on option: " << getSelectedItemIndex() << std::endl;
        }
    }
}





