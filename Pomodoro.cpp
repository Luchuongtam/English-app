// Pomodoro.cpp
#include "Pomodoro.h"
#include "Utils.h"        
#include <iostream>
#include <iomanip>        
#include <thread>         
#include <chrono>        

void runCountdown(int minutes, const std::string& label) {
    int totalSeconds = minutes * 60;
    
    for (int i = totalSeconds; i >= 0; --i) {
        int displayMinutes = i / 60;
        int displaySeconds = i % 60;

        std::cout << "\r" 
                  << label << ": " 
                  << std::setw(2) << std::setfill('0') << displayMinutes << ":" 
                  << std::setw(2) << std::setfill('0') << displaySeconds 
                  << "   " << std::flush;

        if (i > 0) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    std::cout << "\nCompleted! " << '\a' << std::endl; // \a là tiếng bíp
}

// Hàm chạy chính
void runPomodoro() {
    clearScreen();
    std::cout << "=============================================\n";
    std::cout << "--- OPTION 4: START POMODORO SESSION ---\n";
    std::cout << "=============================================\n";
    std::cout << "This feature will LOCK the program for 25 minutes\n";
    std::cout << "to help you focus without distractions.\n\n";
    std::cout << "Are you sure you want to start ? (y/n): ";
    char choice;
    std::cin >> choice;
    clearCinBuffer(); 

    if (choice == 'y' || choice == 'Y') {
        std::cout << "Starting a 25-minute focus session. Please turn off your phone!\n";
        
        // Chạy phiên tập trung 25 phút
        runCountdown(25, "FOCUS");
        
        std::cout << "\nCongratulations! You have completed it!\n";
        std::cout << "Starting a 5-minute break for relaxation...\n";
        
        // Chạy phiên nghỉ 5 phút
        runCountdown(5, "BREAK");
        
        std::cout << "Done! Are you ready for the next session?\n";
    } else {
        std::cout << "Cancelled. Returning to the menu.\n";
    }
}