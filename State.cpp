#include "State.h"
#include "Arduino.h"


State::State(int button0NextState, int button1NextState, int button2NextState, int button3NextState)
{
  button0NextState_ = button0NextState;
  button1NextState_ = button1NextState;
  button2NextState_ = button2NextState;
  button3NextState_ = button3NextState;
}

int State::nextState(int buttonPressed)
{
  switch(buttonPressed)
  {
    case 0: return button0NextState_;
    case 1: return button1NextState_;
    case 2: return button2NextState_;
    case 3: return button3NextState_;
  }
}

