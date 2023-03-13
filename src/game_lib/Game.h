#pragma once

#include <string>
#include <list>
#include <vector>

class Game{

  public:
    Game();
  
    void add(std::string playerName);
    void handle_roll(int roll);
    bool handle_correct_answer();
    bool handle_wrong_answer();

  private:
    void askQuestion();
    std::string currentCategory();
    bool didPlayerNotWin();
    
    std::vector<std::string> players;
    std::vector<int> places;
    std::vector<int> purses;
    std::vector<bool> inPenaltyBox;

    std::list<std::string> popQuestions;
    std::list<std::string> scienceQuestions;
    std::list<std::string> sportsQuestions;
    std::list<std::string> rockQuestions;

    unsigned int currentPlayer;
    bool isGettingOutOfPenaltyBox;
};

