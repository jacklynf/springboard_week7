#include "Game.h"
#include <iostream>

using namespace std;

Game::Game() : currentPlayer(0){
  string s = "";
  for (int i = 0; i < 50; i++)
  {
    s = "Pop Question " + to_string(i);
    popQuestions.push_back(s);

    s = "Science Question " + to_string(i);
    scienceQuestions.push_back(s);

    s = "Sports Question " + to_string(i);
    sportsQuestions.push_back(s);

    s = "Rock Question " + to_string(i);
    rockQuestions.push_back(s);
  }
}

void Game::add(string playerName){
  players.push_back(playerName);
  places.push_back(0);
  purses.push_back(0);
  inPenaltyBox.push_back(false);

  cout << playerName 
       << " was added" 
       << endl;
  cout << "They are player number " 
       << players.size() 
       << endl;
}

void Game::handle_roll(int roll)
{
  cout << players[currentPlayer] 
       << " is the current player" 
       << endl;
  cout << "They have rolled a " 
       << roll 
       << endl;
  
  isGettingOutOfPenaltyBox = (roll % 2 == 1);

  if (inPenaltyBox[currentPlayer])
  {
    if (isGettingOutOfPenaltyBox)
    {
      cout << players[currentPlayer] 
           << " is getting out of the penalty box" 
           << endl;
    }
    else
    {
      cout << players[currentPlayer] 
           << " is not getting out of the penalty box" 
           << endl;
    }
  }
  if (!inPenaltyBox[currentPlayer] || isGettingOutOfPenaltyBox)
  {
    places[currentPlayer] = (places[currentPlayer] + roll) % 12;
    cout << players[currentPlayer] 
         << "'s new location is " 
         << places[currentPlayer] 
         << endl;
    cout << "The category is " 
         << currentCategory() 
         << endl;
      
    askQuestion();
  }
}

void Game::askQuestion()
{
  if (currentCategory() == "Pop")
  {
    cout << popQuestions.front() << endl;
    popQuestions.pop_front();
  }
  else if (currentCategory() == "Science")
  {
    cout << scienceQuestions.front() << endl;
    scienceQuestions.pop_front();
  }
  else if (currentCategory() == "Sports")
  {
    cout << sportsQuestions.front() << endl;
    sportsQuestions.pop_front();
  }
  else if (currentCategory() == "Rock")
  {
    cout << rockQuestions.front() << endl;
    rockQuestions.pop_front();
  }
  else
  {
    throw "Invalid category";
  }
}

string Game::currentCategory()
{
  vector<string> categories = {
    "Pop", "Science", "Sports", "Rock"
  };

  return categories[places[currentPlayer] % 4];
}

bool Game::handle_correct_answer()
{
  bool winner = true;

  if (!inPenaltyBox[currentPlayer] || isGettingOutOfPenaltyBox)
  {
    cout << "Answer was correct!!!!" 
         << endl;
    
    purses[currentPlayer]++;
    cout << players[currentPlayer]
         << " now has "
         << purses[currentPlayer]
         <<  " Gold Coins." 
         << endl;

    winner = didPlayerNotWin();
  }
  
  currentPlayer = (currentPlayer + 1) % players.size();
  
  return winner;
}

bool Game::handle_wrong_answer()
{
  cout << "Question was incorrectly answered" 
       << endl;
  cout << players[currentPlayer] 
       << " was sent to the penalty box" 
       << endl;
  
  inPenaltyBox[currentPlayer] = true;

  currentPlayer = (currentPlayer + 1) % players.size();
  
  return true;
} 

bool Game::didPlayerNotWin()
{
  return purses[currentPlayer] != 6;
}

