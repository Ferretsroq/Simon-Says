// Sequence
// This class holds a vector of colors
// To be used during the game

#include <StandardCplusplus.h>
#include <vector>

class Sequence
{
  public:
  enum Color 
    {
      UnknownColor = -1,
      Blue = 0,
      Green,
      Red,
      Yellow,
    };
    Sequence(int code);
    Color RetrieveColor(int colorIndex);
    int GiveSequenceLength(void);
    void PrintColors(void);
    void ShowColor(Sequence::Color);
    void RedefineSequence(std::vector<Sequence::Color>);
    
  private:
    std::vector<Color> order_;
    int sequenceLength_;
};


