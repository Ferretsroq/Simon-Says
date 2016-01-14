#include "Sequence.h"
#include "Arduino.h"

//----------------------------------------
// Sequence constructor - takes an int as an argument
// Populates the Sequence with a vector of Sequence::Colors
// The input code determines what sequence will be created
// 0 - sequence will be 0, 1, 2, 3. Used for testing.
// 1 - sequence will be a random length between 1 and 10, with random colors.
// Any other number - sequence will be of the specified length, with random colors.

Sequence::Sequence(int code)
{
  if(code == 0) // Gives a known array
  {
    sequenceLength_ = 4;
    order_.resize(sequenceLength_);
    order_[0] = Blue;
    order_[1] = Green;
    order_[2] = Red;
    order_[3] = Yellow; 
  }
  else if(code == 1) // Gives an array of a random size
  {
    sequenceLength_ = ((rand()%10) + 1);
    order_.resize(sequenceLength_);
    for(int orderIndex = 0; orderIndex < sequenceLength_; orderIndex++)
    {
      order_[orderIndex] = (Color)(rand()%4);
    }
  }
  else // Gives an array of the specified size
  {
    sequenceLength_ = code;
    order_.resize(sequenceLength_);
    for(int orderIndex = 0; orderIndex < sequenceLength_; orderIndex++)
    {
      order_[orderIndex] = (Color)(rand()%4);
    }
  }
}

//----------------------------------------
// RetrieveColor - takes an int as an argument
// returns a Sequence::Color
// returns the color at the specified index in the sequence vector.

Sequence::Color Sequence::RetrieveColor(int colorIndex)
{
  if((colorIndex <= sequenceLength_) && (colorIndex >= 0)) // Needs to be a valid value
  {
    return order_[colorIndex];
  }
  else return UnknownColor;
}
//----------------------------------------
// PrintColors - takes no argument
// returns nothing
// Prints the color vector to the serial monitor
// Used for testing and debugging.

void Sequence::PrintColors(void)
{
  for(int colorIndex = 0; colorIndex<sequenceLength_; colorIndex++)
  {
    Serial.println(order_[colorIndex]);
  }
}

//----------------------------------------
// GiveSequenceLength - takes no argument
// returns an int
// Returns the length of the vector of colors

int Sequence::GiveSequenceLength(void)
{
  return sequenceLength_;
}

//----------------------------------------
// RedefineSequence - takes a vector of Sequence::Colors as an argument
// returns nothing
// Redefines the vector of colors to a new specified vector of colors.

void Sequence::RedefineSequence(std::vector<Sequence::Color> newSequenceValues)
{
  order_ = newSequenceValues;
}

