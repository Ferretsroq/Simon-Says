// GameState 
// The GameState determines what phase of the game
// is currently being played.
// The event loop is dependent upon what state
// the game is currently in.

#include <StandardCplusplus.h>
#include <vector>
#include "Sequence.h"

class GameState
{
  public:
    enum CurrentState
    {
      GameOver = -1,
      ShowingLights = 0,
      WaitingForButtonPresses = 1,
    };
  
    GameState(int sequenceToBeCreated);
    void MoveToNextColor(void);
    Sequence::Color ReturnCurrentColor(void);
    bool UserPressedButton(Sequence::Color);
    Sequence::Color RetrieveSequenceColor(int colorIndex);
    GameState::CurrentState ReturnCurrentState(void);
    bool CompareToColor(Sequence::Color);
  private:
    Sequence sequence_;
    int colorIndex_ = 0;
    int sequenceIndex_ = 0;
    GameState::CurrentState currentState_ = ShowingLights;
};

