#include "GameState.h"
#include "Arduino.h"

//----------------------------------------
// GameState constructor - takes an int as an argument
// returns nothing
// The int is passed as the code to create the Sequence object
// inside GameState. The constructor also re-initializes
// some private variables to 0 to start a new game.

GameState::GameState(int sequenceToBeCreated):sequence_(sequenceToBeCreated)
{
  sequence_.PrintColors();
  colorIndex_ = 0;
  sequenceIndex_ = 0;
  currentState_ = GameState::ShowingLights;
}

//----------------------------------------
// MoveToNextColor - takes no argument
// returns nothing
// Increments colorIndex_ and sequenceIndex_
// to move through the sequence during the game

void GameState::MoveToNextColor(void)
{
  colorIndex_++;
  if(colorIndex_ > sequenceIndex_) 
  {
    colorIndex_ = 0;
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
}

//----------------------------------------
// ReturnCurrentColor - takes no argument
// returns a Sequence::Color
// returns the value of the color at the 
// current index in the sequence.

Sequence::Color GameState::ReturnCurrentColor(void)
{
  return sequence_.RetrieveColor(colorIndex_);
}

//----------------------------------------
// UserPressedButton - takes a Sequence::Color as an object
// returns a boolean
// Toggles the game state from pressing buttons
// to showing lights.

bool GameState::UserPressedButton(Sequence::Color buttonPressed)
{
  currentState_ = GameState::ShowingLights;
  Serial.println("We are now showing lights!");
  return 0;
}

//----------------------------------------
// RetrieveSequenceColor - takes an int as an argument
// returns a Sequence::Color
// returns a color at a specified color index

Sequence::Color GameState::RetrieveSequenceColor(int colorIndex)
{
  if((colorIndex <= sequence_.GiveSequenceLength()) && (colorIndex >= 0)) // Needs to be a valid value
  {
    return sequence_.RetrieveColor(colorIndex);
  }
  else return Sequence::UnknownColor;
}

//----------------------------------------
// ReturnCurrentState - takes no argument
// returns a GameState::CurrentState
// returns the current state of the GameState object

GameState::CurrentState GameState::ReturnCurrentState(void)
{
  return currentState_;
}
//----------------------------------------
// CompareToColor - takes a Sequence::Color as an argument
// returns a boolean
// Compares the input color to the colors in the sequence object.
// Returns a 1 if the color is correct
// Returns a 0 if the color is incorrect

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



