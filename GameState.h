#include <StandardCplusplus.h>
#include <vector>
#include "Sequence.h"

class GameState
{
  public:
   // GameState(void);
    Sequence::Color ReturnNextColor(void);
    Sequence::Color ReturnCurrentColor(void);
    bool UserPressedButton(Sequence::Color);
    Sequence::Color RetrieveSequenceColor(int colorIndex);
  private:
    Sequence sequence_ = Sequence(0);
    int colorIndex_ = 0;
    int sequenceIndex_ = 0;
};

