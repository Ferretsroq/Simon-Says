#include <StandardCplusplus.h>
#include <vector>

class Sequence
{
  public:
    Sequence(int code);
    std::vector<int> RetrieveColors(void);
  private:
    std::vector<int> order_;
    int sequenceLength_;
    
};

Sequence::Sequence(int code)
{
  if(code == 0)
  {
    sequenceLength_ = 4;
    order_.resize(sequenceLength_);
    std::vector<int> temporaryOrder(sequenceLength_);
    temporaryOrder[0] = 0;
    temporaryOrder[1] = 1;
    temporaryOrder[2] = 2;
    temporaryOrder[3] = 3; 
    order_ = temporaryOrder;
  }
  else if(code == 1)
  {
    sequenceLength_ = rand()%10;
    order_.resize(sequenceLength_);
    std::vector<int> temporaryOrder(sequenceLength_);
    for(int orderIndex = 0; orderIndex < sequenceLength_; orderIndex++)
    {
      temporaryOrder[orderIndex] = rand()%4;
    }
    order_ = temporaryOrder;
  }
  else
  {
    sequenceLength_ = code;
    order_.resize(sequenceLength_);
    std::vector<int> temporaryOrder(sequenceLength_);
    for(int orderIndex = 0; orderIndex < sequenceLength_; orderIndex++)
    {
      temporaryOrder[orderIndex] = rand()%4;
    }
    order_ = temporaryOrder;
  }
}

std::vector<int> Sequence::RetrieveColors(void)
{
  for(int orderIndex = 0; orderIndex < sequenceLength_; orderIndex++)
  {
    Serial.println(order_[orderIndex]);
  }
  return order_;
}

class Score
{
  public:
  private:
    String name_ = "";
    int scoreValue_ = 0;
    String scoreDate_ = "";
};

class Leaderboard
{
  public:
  private:
};
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  Sequence testSequence = Sequence(0);
  std::vector<int> testVector = testSequence.RetrieveColors();
}
