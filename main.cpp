#include <iostream>
#include <limits>
#include "Utils.h"
#include "GPACalculator.h"
#include "FlashCard.h"
#include "Quiz.h"
#include "Pomodoro.h"

void showMainMenu() {
    clearScreen();
    std::cout << "=================================================\n";
    std::cout << "      WELCOME TO THE ENGLISH STUDY DASHBOARD      \n";
    std::cout << "=================================================\n";
    std::cout << "Select an option: \n";
    std::cout << "  1. Exam score goal\n";
    std::cout << "  2. Study vocabulary with flashcards\n";
    std::cout << "  3. Take an English test\n";
    std::cout << "  4. Start Pomodoro Session(Focus for 25 minutes)\n";
    std::cout << "-------------------------------------------------\n";
    std::cout << "  0. Exit program\n";
    std::cout << "=================================================\n";
    std::cout << "Your options is: ";
}

int main() {
    int choice = -1;

    while (choice != 0) {
        
        showMainMenu(); 

        if (!(std::cin >> choice)) {
            std::cout << "\n[ERROR] Please enter a number only.\n";
            std::cin.clear(); 
            clearCinBuffer(); 
            pauseScreenAfterError();
            continue; 
        }

        switch (choice) {
            case 1:
                runGpaCalculator();
                break;
            case 2:
                runFlashcards();
                break;
            case 3:
                runQuizGenerator();
                break;
            case 4:
                runPomodoro();
                break;
            case 0:
                std::cout << "Goodbye! Wish you good luck with your studies!\n";
                break;
            default:
                std::cout << "\n[ERROR] Invalid choice. Please select a number from 0 to 4.\n";
                break;
        }
        if (choice != 0) {
            pauseScreen();
        }
    }

    return 0;
}