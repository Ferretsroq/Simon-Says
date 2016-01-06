#include <StandardCplusplus.h>
#include <vector>
#include "Sequence.h"


class State
{
  public:
    State(int, int, int, int);
    int nextState(int buttonPressed);
  private:
    int button0NextState_;
    int button1NextState_;
    int button2NextState_;
    int button3NextState_;
};

