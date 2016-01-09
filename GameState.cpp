#include "GameState.h"
#include "Arduino.h"

GameState::GameState():sequence_(0)
{
  
}

Sequence::Color GameState::ReturnNextColor(void)
{
  Sequence::Color temporaryColorVariable = sequence_.RetrieveColor(colorIndex_);
  colorIndex_++;
  if(colorIndex_ > sequenceIndex_) 
  {
    colorIndex_ = 0;
    sequenceIndex_++;
  }
  if(sequenceIndex_ >= sequence_.GiveSequenceLength()) sequenceIndex_ = 0;
  if(colorIndex_ >= sequence_.GiveSequenceLength()) colorIndex_ = 0;
  return temporaryColorVariable;
}

Sequence::Color GameState::ReturnCurrentColor(void)
{
  return (Sequence::Color)colorIndex_;
}

bool GameState::UserPressedButton(Sequence::Color buttonPressed)
{
  
}

Sequence::Color GameState::RetrieveSequenceColor(int colorIndex)
{
  if((colorIndex <= sequence_.GiveSequenceLength()) && (colorIndex >= 0)) // Needs to be a valid value
  {
    return sequence_.RetrieveColor(colorIndex);
  }
  else return Sequence::UnknownColor;
}
