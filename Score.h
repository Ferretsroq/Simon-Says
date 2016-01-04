
class Score
{
  public:
    void GetNameFromUser(void);
    int ReportScore(void);
  private:
    String name_ = "";
    int scoreValue_ = 0;
    String scoreDate_ = "";
};

void Score::GetNameFromUser(void)
{
  
}

int Score::ReportScore(void)
{
  return scoreValue_;
}

