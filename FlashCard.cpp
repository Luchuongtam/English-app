// Flashcard.cpp
#include "Flashcard.h"
#include "Utils.h"      
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>      
#include <limits>       

static const long long ONE_DAY_IN_SECONDS = 86400; 

Flashcard::Flashcard(const std::string& f, const std::string& b)
    : front(f), back(b), interval(0), nextReviewDate(time(0)) {}

Flashcard::Flashcard(const std::string& f, const std::string& b, int i, time_t next)
    : front(f), back(b), interval(i), nextReviewDate(next) {}

Deck::Deck(const std::string& filename) : deckFilename(filename) {
    loadFromFile();
}

Deck::~Deck() {
    saveToFile();
}

void Deck::updateCard(Flashcard& card, int difficulty) {
    time_t now = time(0);
    if (difficulty == 1) { 
        card.interval = 1; 
    }
    else if (difficulty == 2) { 
        card.interval = (card.interval == 0) ? 2 : card.interval * 2; 
    }
    else if (difficulty == 3) {
        card.interval = (card.interval == 0) ? 4 : card.interval * 3; 
    }

    
    card.nextReviewDate = now + (card.interval * ONE_DAY_IN_SECONDS);

    
    #pragma warning(suppress : 4996) 
    struct tm *localTime = localtime(&card.nextReviewDate);
    char timeStr[20];
    strftime(timeStr, sizeof(timeStr), "%Y-%m-%d", localTime);
    
    std::cout << "-> You will review this card in " << card.interval << " days (on " << timeStr << ").\n";
}

void Deck::addCard() {
    std::string front, back;
    
    
    clearCinBuffer(); 
    
    std::cout << "Enter front: ";
    std::getline(std::cin, front);
    std::cout << "Enter back: ";
    std::getline(std::cin, back);
    
    cards.emplace_back(front, back);
    std::cout << "-> New card added.\n";
    saveToFile();
}

void Deck::review() {
    time_t now = time(0);
    std::vector<Flashcard*> dueCards; 

    // 1. Tìm tất cả các thẻ đã đến hạn
    for (Flashcard& card : cards) {
        if (card.nextReviewDate <= now) {
            dueCards.push_back(&card);
        }
    }

    if (dueCards.empty()) {
        std::cout << "\nGreat job! You've finished all your reviews for today.\n";
        return;
    }

    std::cout << "\nYou have " << dueCards.size() << " cards to review today.\n";

    clearCinBuffer(); 
    
    for (Flashcard* cardPtr : dueCards) {
        std::cout << "\n----------------------------------------\n";
        std::cout << "Front: " << cardPtr->front << "\n";
        std::cout << "(Press Enter to reveal answer...)";

        std::cin.get(); 
        
        std::cout << "Back: " << cardPtr->back << "\n\n";

        // 3. Hỏi độ khó và cập nhật thẻ
        int difficulty = 0;
        while (difficulty < 1 || difficulty > 3) {
            std::cout << "Rate difficulty: (1) Hard, (2) Good, (3) Easy? ";
            std::cin >> difficulty;
            if(std::cin.fail()) { 
                std::cin.clear();
                clearCinBuffer(); 
                difficulty = 0;
            }
        }
        
        
        clearCinBuffer(); 

        // 4. Cập nhật thẻ bằng logic SRS
        updateCard(*cardPtr, difficulty);
    }
    
    std::cout << "\n----------------------------------------\n";
    std::cout << "Review session completed!\n";
    saveToFile(); 
}

void Deck::saveToFile() {
    std::ofstream outFile(deckFilename);
    if (!outFile) {
        std::cerr << "Error: Could not save file " << deckFilename << std::endl;
        return;
    }
    for (const auto& card : cards) {
        outFile << card.front << "|"
                << card.back << "|"
                << card.interval << "|"
                << card.nextReviewDate << "\n";
    }
    outFile.close();
}

void Deck::loadFromFile() {
    std::ifstream inFile(deckFilename);
    if (!inFile) {
        std::cout << "File " << deckFilename << " not found. Creating a new deck.\n";
        return;
    }
    std::string line;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string segment;
        std::string front, back;
        int interval;
        time_t nextReviewDate;

        // Tách chuỗi bằng dấu '|'
        if (!std::getline(ss, front, '|')) continue;
        if (!std::getline(ss, back, '|')) continue;
        if (!std::getline(ss, segment, '|')) continue;
        try {
            interval = std::stoi(segment);
            if (!std::getline(ss, segment, '|')) continue;
            nextReviewDate = std::stoll(segment);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Warning: Skipping corrupted line in deck file." << std::endl;
            continue;
        }

        cards.emplace_back(front, back, interval, nextReviewDate);
    }
    inFile.close();
    if (!cards.empty()) {
        std::cout << "-> Loaded " << cards.size() << " cards from file.\n";
    }
}

// --- Menu và Hàm chạy chính của Module Flashcard ---

// Hàm hiển thị menu (riêng của Flashcard)
static void showFlashcardMenu() {
    std::cout << "\n=== Study vocabulary with flashcards ===\n";
    std::cout << "1. Add New Card\n";
    std::cout << "2. Review Now\n";
    std::cout << "3. Exit\n";
    std::cout << "Your choice: ";
}

// Hàm chạy chính của module
void runFlashcards() {
    Deck myDeck("my_deck.txt");
    int choice = 0;

    while (true) {
        showFlashcardMenu();
        std::cin >> choice;

        if (std::cin.fail()) { 
            std::cin.clear();
            clearCinBuffer(); 
            choice = 0; 
        }

        switch (choice) {
            case 1:
                myDeck.addCard();
                break;
            case 2:
                myDeck.review();
                break;
            case 3:
                std::cout << "Saving... Returning to main menu!\n";
                return; 
            default:
                std::cout << "Invalid option. Please select 1, 2, or 3.\n";
                break;
        }
    }
}