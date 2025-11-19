#pragma once
#include <string>
#include <vector>

class QuizQuestion {
public:
    std::string question;
    std::string answer;
    QuizQuestion(const std::string& q, const std::string& a);
};

class Quiz {
public:
    std::vector<QuizQuestion> questions;

    bool loadFromFile(const std::string& filename);

    void startQuiz_TuLuan(int numQuestions);

    void startQuiz_TracNghiem(int numQuestions);
};

void runQuizGenerator();