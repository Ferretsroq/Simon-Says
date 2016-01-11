#include "Sequence.h"
#include "Arduino.h"

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

Sequence::Color Sequence::RetrieveColor(int colorIndex)
{
  if((colorIndex <= sequenceLength_) && (colorIndex >= 0)) // Needs to be a valid value
  {
    return order_[colorIndex];
  }
  else return UnknownColor;
}

void Sequence::PrintColors(void)
{
  for(int colorIndex = 0; colorIndex<sequenceLength_; colorIndex++)
  {
    Serial.println(order_[colorIndex]);
  }
}

int Sequence::GiveSequenceLength(void)
{
  return sequenceLength_;
}

void Sequence::RedefineSequence(std::vector<Sequence::Color> newSequenceValues)
{
  order_ = newSequenceValues;
}

