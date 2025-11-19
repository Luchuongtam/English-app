#include "Utils.h"    
#include <iostream>   
#include <limits>           

void clearScreen() {
    std::cout << "\x1B[2J\x1B[H";
}

void clearCinBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void pauseScreen() {
    std::cout << "\nPress Enter to continue...";
    if (std::cin.peek() == '\n') {
        clearCinBuffer();
    }
    std::cin.get();
}

void pauseScreenAfterError() {
    std::cout << "\nPress Enter to continue...";
    clearCinBuffer();  
    std::cin.get();
}