#include "GameState.h"
#include "Arduino.h"

GameState::GameState(int sequenceToBeCreated):sequence_(sequenceToBeCreated)
{
  sequence_.PrintColors();
}

void GameState::MoveToNextColor(void)
{
  colorIndex_++;
  if(colorIndex_ > sequenceIndex_) 
  {
    colorIndex_ = 0;
    sequenceIndex_++;
    currentTurn_++;
  }
  if(sequenceIndex_ >= sequence_.GiveSequenceLength()) sequenceIndex_ = 0;
  if(colorIndex_ >= sequence_.GiveSequenceLength()) colorIndex_ = 0;
  if(currentTurn_ >= sequence_.GiveSequenceLength()) currentTurn_ = 0;
}

Sequence::Color GameState::ReturnCurrentColor(void)
{
  return sequence_.RetrieveColor(colorIndex_);
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

int GameState::ReturnCurrentTurn(void)
{
  return currentTurn_;
}

