#include "GPACalculator.h"
#include "Utils.h"        
#include <iostream>
#include <string>
#include <cmath>         
#include <iomanip>      

void runGpaCalculator() {
    clearScreen();
    std::cout << "=================================================\n";
    std::cout << "--- OPTION 1: EXAM SCORE GOAL ---\n";
    std::cout << "(Calculate the required score to achieve your desired GPA)\n";
    std::cout << "=================================================\n";

    double targetAverage;
    int componentCount;
    double totalWeight = 0;
    double achievedScore = 0;
    double remainingWeight = 0;

    // 1. Nhap diem muc tieu
    std::cout << "Enter the average score you want to achieve (out of 10): ";
    while (!(std::cin >> targetAverage) || targetAverage < 0 || targetAverage > 10) {
        std::cout << "Invalid score. Please enter a value from 0 to 10: ";
        std::cin.clear();
        clearCinBuffer(); 
    }

    // 2. Nhap cac cot diem
    std::cout << "Enter the total number of grade components for the subject (Example 3): ";
    while (!(std::cin >> componentCount) || componentCount <= 0) {
        std::cout << "Invalid number. There must be at least 1 grade component: ";
        std::cin.clear();
        clearCinBuffer();
    }
    clearCinBuffer(); 

    std::cout << "\n--- Please enter the information for each grade component ---\n";
    std::cout << "(Enter -1 in the 'Score' column if the component does not have a score yet.)\n\n";

    for (int i = 0; i < componentCount; ++i) {
        std::string name;
        double weight, score;

        std::cout << "  [Grade component " << (i + 1) << "]\n";
        std::cout << "  Grade component name (Example: Chuyen can): ";
        std::getline(std::cin, name);

        std::cout << "  Weight (%) (Example: 10): ";
        while (!(std::cin >> weight) || weight <= 0 || weight > 100) {
            std::cout << "  Invalid weight. Please enter again: ";
            std::cin.clear();
            clearCinBuffer();
        }

        std::cout << "  Score (out of 10) (enter -1 if not yet available): ";
        while (!(std::cin >> score) || (score < -1) || (score > 10)) {
            std::cout << "  Invalid score. Please enter again: ";
            std::cin.clear();
            clearCinBuffer();
        }
        clearCinBuffer();

        std::cout << "---------------------------------\n";

        totalWeight += weight;
        if (score == -1) {
            remainingWeight += weight; // Cot diem nay chua co diem
        } else {
            achievedScore += (score * weight); // Cot diem nay da co diem
        }
    }

    // 3. Kiem tra va Tinh toan
    if (std::abs(totalWeight - 100.0) > 0.01) {
        std::cout << "[WARNING] The total weight you entered is " << totalWeight << "%, is not 100%.\n";
        std::cout << "The result may not be accurate.\n\n";
    }

    if (remainingWeight == 0) {
        std::cout << "[RESULT] You have entered scores for all components.\n";
        std::cout << "Your final average score is: " << (achievedScore / totalWeight) << "\n";
    } else {
        double neededScoreSum = (targetAverage * totalWeight) - achievedScore;
        double requiredAverageOnRemaining = neededScoreSum / remainingWeight;

        std::cout << "[CALCULATION RESULT]\n";
        std::cout << "To achieve the target " << targetAverage << " subject average score\n";
        std::cout << "You need to achieve an average of " << std::fixed << std::setprecision(2) << requiredAverageOnRemaining<< " Score (out of 10)\n";
        std::cout << "for the total " << remainingWeight << "% of remaining weight.\n";

        if (requiredAverageOnRemaining > 10.0) {
            std::cout << "\n[WARNING] This target is UNACHIEVABLE!\n";
        } else if (requiredAverageOnRemaining < 0.0) {
            std::cout << "\n[NOTICE] You will definitely achieve this target, even if you score 0 on the remaining components!\n";
        }
    }
}