#include <StandardCplusplus.h>
#include <vector>
#include "Sequence.h"

class GameState
{
  public:
    GameState(int sequenceToBeCreated);
    void MoveToNextColor(void);
    Sequence::Color ReturnCurrentColor(void);
    bool UserPressedButton(Sequence::Color);
    Sequence::Color RetrieveSequenceColor(int colorIndex);
    int ReturnCurrentTurn(void);
  private:
    Sequence sequence_;
    int colorIndex_ = 0;
    int sequenceIndex_ = 0;
    int currentTurn_ = 0;
};

