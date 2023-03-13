#include "Game.h"
#include <string>
#include <cstdlib>

using namespace std;

int main()
{

  bool still_no_winner;
  srand(time(NULL));
  Game game;

  game.add("Chet");
  game.add("Pat");
  game.add("Sue");

  do
  {

    game.handle_roll(rand() % 5 + 1);

    if (rand() % 9 == 7)
    {
       still_no_winner = game.handle_wrong_answer();
    }
    else
    {
      still_no_winner = game.handle_correct_answer();
    }
  } while (still_no_winner);

}
