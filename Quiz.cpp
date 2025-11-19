#include "Quiz.h"
#include "Utils.h"        
#include <iostream>
#include <fstream>
#include <algorithm>     
#include <random>         
#include <cctype>        

// --- Implement QuizQuestion ---
QuizQuestion::QuizQuestion(const std::string& q, const std::string& a) 
    : question(q), answer(a) {}

// --- Implement Quiz Class ---

bool Quiz::loadFromFile(const std::string& filename) {
    std::ifstream quizFile(filename);
    
    // Nếu file không mở được (chưa tồn tại)
    if (!quizFile.is_open()) {
        std::cout << "\n[NOTICE] File not found '" << filename << "'.\n";
        std::cout << "Do you want to create this file now? (y/n): ";
        char createChoice;
        std::cin >> createChoice;
        clearCinBuffer(); // Hàm từ Utils.h
        
        if (createChoice == 'y' || createChoice == 'Y') {
            std::ofstream newFile(filename);
            if (newFile.is_open()) {
                std::cout << "File '" << filename << "' has been created successfully!\n";
                std::cout << "Now, open the file and add questions.\n";
                std::cout << "FORMAT: Each line should be: Question[space]?[space]Answer\n";
                newFile.close();
            } else {
                std::cout << "[ERROR] Cannot create file. Please check folder permissions.\n";
            }
        } else {
            std::cout << "Cancelled.\n";
        }
        return false;
    }

    // Nếu file rỗng
    if (quizFile.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "\n[ERROR] File '" << filename << "' is empty.\n";
        std::cout << "Please open the file and add questions in the following format:\n";
        std::cout << "Question[space]?[space]Answer\n";
        quizFile.close();
        return false;
    }

    questions.clear();
    std::string line;
    int lineCount = 0;
    int errorCount = 0;

    while (std::getline(quizFile, line)) {
        lineCount++;
        if (line.empty()) continue;
        
        // Tìm dấu phân cách " ? "
        size_t separatorPos = line.find(" ? ");
        if (separatorPos == std::string::npos) {
            std::cout << "[WARNING] Line " << lineCount << " has an invalid format (missing ' ? '). Skipped.\n";
            errorCount++;
            continue;
        }

        std::string question = line.substr(0, separatorPos);
        std::string answer = line.substr(separatorPos + 3);

        if (question.empty() || answer.empty()) {
            std::cout << "[WARNING] Line " << lineCount << " contains an empty question/answer. Skipped.\n";
            errorCount++;
            continue;
        }
        questions.push_back(QuizQuestion(question, answer));
    }
    quizFile.close();

    std::cout << "\n--- FILE LOADING COMPLETED ---\n";
    std::cout << "Valid questions: " << questions.size() << "\n";
    std::cout << "Lines skipped due to errors: " << errorCount << "\n";

    if (questions.size() < 4) {
        std::cout << "[WARNING] You need at least 4 questions in the file for the quiz mode to work properly.\n";
    }

    return !questions.empty();
}

void Quiz::startQuiz_TuLuan(int numQuestions) {
    if (questions.empty()) return;
    if (numQuestions > (int)questions.size()) numQuestions = (int)questions.size();

    // Trộn câu hỏi ngẫu nhiên
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(questions.begin(), questions.end(), g);

    int score = 0;
    std::string userAnswer;
    clearCinBuffer(); // Xóa buffer trước khi nhập chuỗi

    for (int i = 0; i < numQuestions; ++i) {
        clearScreen();
        std::cout << "--- WRITTEN QUIZ (Question " << (i+1) << "/" << numQuestions << ") ---\n";
        std::cout << "=======================================\n";
        std::cout << "Question: " << questions[i].question << "\n";
        std::cout << "Your answer: ";
        
        std::getline(std::cin, userAnswer);

        if (userAnswer == questions[i].answer) {
            std::cout << "\nCorrect!\n";
            score++;
        } else {
            std::cout << "\nWrong! The correct answer is:\n";
            std::cout << " -> " << questions[i].answer << "\n";
        }
        pauseScreen();
    }

    clearScreen();
    std::cout << "--- QUIZ COMPLETED ---\n";
    std::cout << "You answered correctly: " << score << "/" << numQuestions << " questions.\n";
}

void Quiz::startQuiz_TracNghiem(int numQuestions) {
    if (questions.size() < 4 && questions.size() > 0) {
        std::cout << "[ERROR] Not enough questions to create a multiple-choice quiz.\n";
        std::cout << "Please add at least 4 questions to the file.\n";
        return;
    }
    if (questions.empty()) return;
    if (numQuestions > (int)questions.size()) numQuestions = (int)questions.size();

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(questions.begin(), questions.end(), g);

    int score = 0;
    clearCinBuffer();

    for (int i = 0; i < numQuestions; ++i) {
        std::string correctAnswer = questions[i].answer;
        std::vector<std::string> options;
        options.push_back(correctAnswer); // Thêm đáp án đúng trước

        // Tìm các đáp án sai
        std::vector<std::string> wrongAnswers;
        for(const auto& q : questions) {
            if(q.answer != correctAnswer) {
                wrongAnswers.push_back(q.answer);
            }
        }
        
        // Trộn và lấy 3 đáp án sai
        std::shuffle(wrongAnswers.begin(), wrongAnswers.end(), g);
        for(size_t j = 0; j < 3 && j < wrongAnswers.size(); ++j) {
            options.push_back(wrongAnswers[j]);
        }
        
        // Nếu không đủ đáp án (hiếm gặp), thêm dummy text
        while(options.size() < 4) {
            options.push_back("Another answer");
        }

        // Trộn thứ tự A, B, C, D
        std::shuffle(options.begin(), options.end(), g);

        clearScreen();
        std::cout << "--- MULTIPLE-CHOICE QUIZ (Question " << (i+1) << "/" << numQuestions << ") ---\n";
        std::cout << "=======================================\n";
        std::cout << "Question: " << questions[i].question << "\n\n";
        std::cout << "  A. " << options[0] << "\n";
        std::cout << "  B. " << options[1] << "\n";
        std::cout << "  C. " << options[2] << "\n";
        std::cout << "  D. " << options[3] << "\n";
        std::cout << "---------------------------------------\n";
        std::cout << "Your answer (A, B, C, D): ";

        char userChoice;
        std::cin >> userChoice;
        userChoice = toupper(userChoice);
        clearCinBuffer();

        std::string chosenAnswer;
        switch(userChoice) {
            case 'A': chosenAnswer = options[0]; break;
            case 'B': chosenAnswer = options[1]; break;
            case 'C': chosenAnswer = options[2]; break;
            case 'D': chosenAnswer = options[3]; break;
            default: chosenAnswer = "";
        }

        if (chosenAnswer == correctAnswer) {
            std::cout << "\nCorrect! \n";
            score++;
        } else {
            std::cout << "\nWrong! The correct answer is: " << correctAnswer << "\n";
        }
        pauseScreen();
    }

    clearScreen();
    std::cout << "--- QUIZ COMPLETED ---\n";
    std::cout << "You answered correctly: " << score << "/" << numQuestions << " question.\n";
}

// --- Hàm chạy chính ---
void runQuizGenerator() {
    clearScreen();
    std::cout << "====================================\n";
    std::cout << "--- OPTION 3: TAKE AN ENGLISH TEST ---\n";
    std::cout << "====================================\n";

    static Quiz myQuiz;
    std::string filename;

    std::cout << "Please enter the quiz file name (Example: english.txt): ";
    std::cin >> filename;

    if (myQuiz.loadFromFile(filename)) {
        int totalLoaded = (int)myQuiz.questions.size();
        int desiredNum = 0;

        std::cout << "\nLoaded " << totalLoaded << " questions.\n";
        std::cout << "How many questions do you want to attempt? (Maximum " << totalLoaded << "): ";
        
        while (!(std::cin >> desiredNum) || desiredNum <= 0 || desiredNum > totalLoaded) {
            std::cout << "Invalid number. Please enter a number from 1 to " << totalLoaded << ": ";
            std::cin.clear();
            clearCinBuffer();
        }

        std::cout << "\nWhich mode would you like to use?\n";
        std::cout << "  1. Written (Fill in the answer)\n";
        std::cout << "  2. Multiple-choice (Choose A, B, C, D)\n";
        std::cout << "Your choice: ";
        
        int quizType;
        std::cin >> quizType;

        if (quizType == 1) {
            std::cout << "Starting WRITTEN mode with " << desiredNum << " questions...\n";
            pauseScreen();
            myQuiz.startQuiz_TuLuan(desiredNum);
        } else if (quizType == 2) {
            std::cout << "Starting MULTIPLE-CHOICE mode with " << desiredNum << " questions...\n";
            pauseScreen();
            myQuiz.startQuiz_TracNghiem(desiredNum);
        } else {
            std::cout << "Invalid choice, returning to menu.\n";
        }
    }
}