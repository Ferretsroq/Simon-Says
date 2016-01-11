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
    int ReturnCurrentTurn(void);
    GameState::CurrentState ReturnCurrentState(void);
    bool CompareToColor(Sequence::Color);
  private:
    Sequence sequence_;
    int colorIndex_ = 0;
    int sequenceIndex_ = 0;
    int currentTurn_ = 0;
    GameState::CurrentState currentState_ = ShowingLights;
};

