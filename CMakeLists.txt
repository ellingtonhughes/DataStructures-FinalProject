
# CMakeLists.txt

cmake_minimum_required (VERSION 3.10)

project (FinalProject)

set (CMAKE_CXX_STANDARD 17)

set (CMAKE_CXX_STANDARD_REQUIRED True)

include_directories (include)

add_executable (FinalProject src/main.cpp src/GUIManager.cpp src/AVL.cpp src/Heap.cpp src/BTree.cpp src/BST.cpp src/PriorityQueue.cpp src/RedBlack.cpp src/StackQueue.cpp)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

target_link_libraries(FinalProject sfml-graphics sfml-window sfml-system)

# Copy the resources folder to the build directory
file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR})


