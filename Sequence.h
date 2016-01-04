#include <StandardCplusplus.h>
#include <vector>

class Sequence
{
  public:
  enum Color 
    {
      UnknownColor = -1,
      Red = 0,
      Blue,
      Green,
      Yellow,
    };
    Sequence(int code);
    Color RetrieveColor(int colorIndex);
    int GiveSequenceLength(void);
    void PrintColors(void);
    void ShowColor(Sequence::Color);
    
  private:
    std::vector<Color> order_;
    int sequenceLength_;
};


