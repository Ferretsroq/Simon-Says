#include "GameState.h"
#include "Arduino.h"

GameState::GameState(int sequenceToBeCreated):sequence_(sequenceToBeCreated)
{
  sequence_.PrintColors();
  colorIndex_ = 0;
  sequenceIndex_ = 0;
  currentState_ = GameState::ShowingLights;
}

void GameState::MoveToNextColor(void)
{
  colorIndex_++;
  if(colorIndex_ > sequenceIndex_) 
  {
    colorIndex_ = 0;
    currentTurn_++;
    if(currentState_ == GameState::ShowingLights)
    {
      currentState_ = GameState::WaitingForButtonPresses;
      Serial.println("We are now waiting for button presses!");
    }
    if(currentState_ == GameState::GameOver)
    {
      sequenceIndex_++;
    }
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
  currentState_ = GameState::ShowingLights;
  Serial.println("We are now showing lights!");
  return 0;
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

GameState::CurrentState GameState::ReturnCurrentState(void)
{
  return currentState_;
}

bool GameState::CompareToColor(Sequence::Color inputColor)
{
  bool answeredCorrectColor = 0;
  switch (inputColor)
  {
    case Sequence::Blue:
      if(sequence_.RetrieveColor(colorIndex_) == Sequence::Blue)
      {
        Serial.println("It was blue!");
        answeredCorrectColor = 1;
      }
      else Serial.println("It was not blue!");
      break;
    case Sequence::Green:
      if(sequence_.RetrieveColor(colorIndex_) == Sequence::Green)
      {
        Serial.println("It was green!");
        answeredCorrectColor = 1;
      }
      else Serial.println("It was not green!");
      break;
    case Sequence::Red:
      if(sequence_.RetrieveColor(colorIndex_) == Sequence::Red)
      {
        Serial.println("It was red!");
        answeredCorrectColor = 1;
      }
      else Serial.println("It was not red!");
      break;
    case Sequence::Yellow:
      if(sequence_.RetrieveColor(colorIndex_) == Sequence::Yellow)
      {
        Serial.println("It was yellow!");
        answeredCorrectColor = 1;
      }
      else Serial.println("It was not yellow!");
      break;
  }
  
  if((colorIndex_ >= sequenceIndex_) && answeredCorrectColor)
  {
    colorIndex_ = 0;
    sequenceIndex_++;
    if(sequenceIndex_ >= sequence_.GiveSequenceLength()) sequenceIndex_ = 0;
    currentState_ = GameState::ShowingLights;
    Serial.println("We are now showing lights!");
  }
  else if (answeredCorrectColor) colorIndex_++;
  else if(!answeredCorrectColor) currentState_ = GameState::GameOver;
}



