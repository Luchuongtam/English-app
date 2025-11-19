#pragma once

#include <string>
#include <vector>
#include <ctime> 

struct Flashcard {
    std::string front;
    std::string back;  
    int interval;      
    time_t nextReviewDate; 
    Flashcard(const std::string& f, const std::string& b);
    Flashcard(const std::string& f, const std::string& b, int i, time_t next);
};

class Deck {
private:
    std::vector<Flashcard> cards;
    std::string deckFilename;
    void updateCard(Flashcard& card, int difficulty);
    void saveToFile();
    void loadFromFile();
public:   
    Deck(const std::string& filename);
    ~Deck();
    void addCard();
    void review();
};

void runFlashcards();