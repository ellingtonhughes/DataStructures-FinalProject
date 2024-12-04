#include <SFML/Graphics.hpp>
#include "GUIManager.h"
#include <iostream>
#include <vector>

sf::Font font;

void loadFont() {
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
    } else {
        std::cout << "Font loaded successfully" << std::endl;
    }
}

enum MenuState { MAIN_MENU, OPERATION_MENU };

void runMenu(Menu& menu, sf::RenderWindow& window, bool& isRunning, int& currentMenu) {
    while (isRunning) {
        sf::Event event;
        
        // Poll events and handle them.
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                isRunning = false;
                break;
            }

            menu.handleEvent(event);  // Handle navigation and input for the menu.

            // Handle Enter key input separately.
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                int selectedOption = menu.getSelectedItemIndex();  // Get the selected menu item.

                if (currentMenu == 0) {  // Main menu state.
                    performOperation(selectedOption, menu, window, currentMenu);
                } else if (currentMenu == 1) {  // Operations menu (Insert/Delete/Display).
                    performOperation(selectedOption, menu, window, currentMenu);

                   }else if (currentMenu == 2) {  // Operations menu (Insert/Delete/Display).
                    performOperation(selectedOption, menu, window, currentMenu);

                   }else if (currentMenu == 3) {  // Operations menu (Insert/Delete/Display).
                    performOperation(selectedOption, menu, window, currentMenu);

                   }else if (currentMenu == 4) {  // Operations menu (Insert/Delete/Display).
                    performOperation(selectedOption, menu, window, currentMenu);

                   }else if (currentMenu == 5) {  // Operations menu (Insert/Delete/Display).
                    performOperation(selectedOption, menu, window, currentMenu);

                   }else if (currentMenu == 6) {  // Operations menu (Insert/Delete/Display).
                    performOperation(selectedOption, menu, window, currentMenu);

                   }else if (currentMenu == 7) {  // Operations menu (Insert/Delete/Display).
                    performOperation(selectedOption, menu, window, currentMenu);

                   }
            }
        }

        // Clear and draw the updated menu.
        window.clear();
        menu.draw(window);
        window.display();
    }
}






int main() {
    loadFont();  // Load font at the beginning
    bool isRunning = true;
    int currentMenu = 0;

    BST bstTree;
    bstTree.insert(50);
    bstTree.insert(30);
    bstTree.insert(70);
    bstTree.insert(20);
    bstTree.insert(40);
    bstTree.insert(60);
    bstTree.insert(80);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Main Menu");

    Menu menu(window.getSize().x, window.getSize().y, font);  // Pass the font

    std::vector<std::string> mainMenuOptions = {"Heap", "BST", "Stack", "Queue", "AVL", "BTree", "Priority Queue", "RedBlack", "Import From File"};
    menu.setOptions(mainMenuOptions);

    runMenu(menu, window, isRunning, currentMenu);  // Start the main loop

    return 0;
}


