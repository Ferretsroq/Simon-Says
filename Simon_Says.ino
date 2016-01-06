#include <StandardCplusplus.h>
#include <vector>
//#include "Sequence.h"
#include "Score.h"
#include "Leaderboard.h"
#include "State.h"

// Global Variables
const int g_blueLEDPin = 2;
const int g_greenLEDPin = 5;
const int g_redLEDPin = 4; 
const int g_yellowLEDPin = 3;

const int g_blueButtonPin = 8;
const int g_greenButtonPin = 9;
const int g_redButtonPin = 10; 
const int g_yellowButtonPin = 11;

long g_timerForLEDFlashes = 0;
bool g_lightOnOrOff = 0;
Sequence g_testSequence = Sequence(240);
int g_colorIndex = 0;
bool g_redButtonState = 0;
bool g_lastRedButtonState = 0;
bool g_blueButtonState = 0;
bool g_lastBlueButtonState = 0;
bool g_greenButtonState = 0;
bool g_lastGreenButtonState = 0;
bool g_yellowButtonState = 0;
bool g_lastYellowButtonState = 0;

std::vector<State> g_states;
int g_currentState = 0;

// Function Prototypes
void ShowColor(Sequence::Color);
void ShowWholeSequence(Sequence);
void TurnColorOff(Sequence::Color colorToTurnOff);
signed char DetectButtonStateChange(int);
void PrintButtonPresses(void);
void ChangeStateWithButtonPresses(void);

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(g_blueLEDPin, OUTPUT);
  pinMode(g_greenLEDPin, OUTPUT);
  pinMode(g_redLEDPin, OUTPUT);
  pinMode(g_yellowLEDPin, OUTPUT);
  
  pinMode(g_blueButtonPin, INPUT);
  pinMode(g_greenButtonPin, INPUT);
  pinMode(g_redButtonPin, INPUT);
  pinMode(g_yellowButtonPin, INPUT);

  g_states.push_back(State(0,1,2,3));
  g_states.push_back(State(3,2,3,0));
  g_states.push_back(State(3,1,1,2));
  g_states.push_back(State(2,0,0,3));
}

void loop() 
{
  // put your main code here, to run repeatedly:
  ShowWholeSequence(g_testSequence);
  ChangeStateWithButtonPresses();
  PrintButtonPresses();
  //Serial.println(g_currentState);  
}

void ShowColor(Sequence::Color colorToShow)
{
  int lightToDisplay = -1;
  switch (colorToShow) 
  {
    case Sequence::Blue: lightToDisplay = g_blueLEDPin; break;
    case Sequence::Green: lightToDisplay = g_greenLEDPin; break;
    case Sequence::Red: lightToDisplay = g_redLEDPin; break;
    case Sequence::Yellow: lightToDisplay = g_yellowLEDPin; break;
  }
  if(lightToDisplay != -1)
  {
    digitalWrite(lightToDisplay, HIGH);
  }
  else Serial.println("Error - unknown light to display");
}

void TurnColorOff(Sequence::Color colorToTurnOff)
{
  int lightToTurnOff = -1;
  switch (colorToTurnOff) 
  {
    case Sequence::Blue: lightToTurnOff = g_blueLEDPin; break;
    case Sequence::Green: lightToTurnOff = g_greenLEDPin; break;
    case Sequence::Red: lightToTurnOff = g_redLEDPin; break;
    case Sequence::Yellow: lightToTurnOff = g_yellowLEDPin; break;
  }
  if(lightToTurnOff != -1)
  {
    digitalWrite(lightToTurnOff, LOW);
  }
  else Serial.println("Error - unknown light to display");
}

void ShowWholeSequence(Sequence sequence)
{
  if(millis() >= (g_timerForLEDFlashes+250))
    {
      if(!g_lightOnOrOff)
      {
        g_lightOnOrOff = 1;
        ShowColor(sequence.RetrieveColor(g_colorIndex));
      }
      else if(g_lightOnOrOff)
      {
        g_lightOnOrOff = 0;
        TurnColorOff(sequence.RetrieveColor(g_colorIndex));
        g_colorIndex++;
        if(g_colorIndex >= sequence.GiveSequenceLength()) g_colorIndex = 0;
        //Serial.println(g_colorIndex);
      }
      g_timerForLEDFlashes = millis();
    }
}

// DetectButtonStateChange - takes the pin of a button as an argument
// returns a signed char. 
// -1 means no state change at all
// 0 means a state change to the button being released
// 1 means a state change to the button being pressed

signed char DetectButtonStateChange(int buttonOfInterest)
{
  signed char returnedButtonState = -1;
  switch (buttonOfInterest)
  {
    case g_blueButtonPin:
       g_blueButtonState = digitalRead(g_blueButtonPin);
       if(g_blueButtonState != g_lastBlueButtonState)
       {
          if(g_blueButtonState) returnedButtonState = 1;
          else returnedButtonState = 0;
       }
       g_lastBlueButtonState = g_blueButtonState;
       break;

     case g_greenButtonPin:
       g_greenButtonState = digitalRead(g_greenButtonPin);
       if(g_greenButtonState != g_lastGreenButtonState)
       {
         if(g_greenButtonState) returnedButtonState = 1;
         else returnedButtonState = 0;
       }
       g_lastGreenButtonState = g_greenButtonState;
       break;
       
      case g_redButtonPin:
        g_redButtonState = digitalRead(g_redButtonPin);
        if(g_redButtonState != g_lastRedButtonState)
        {
          if(g_redButtonState) returnedButtonState = 1;
          else returnedButtonState = 0;
        }
        g_lastRedButtonState = g_redButtonState;
        break;
        
      case g_yellowButtonPin:
        g_yellowButtonState = digitalRead(g_yellowButtonPin);
        if(g_yellowButtonState != g_lastYellowButtonState)
        {
          if(g_yellowButtonState) returnedButtonState = 1;
          else returnedButtonState = 0;
        }
        g_lastYellowButtonState = g_yellowButtonState;
        break;   
  }
  return returnedButtonState;
}

void PrintButtonPresses(void)
{
  int blueButtonState = DetectButtonStateChange(g_blueButtonPin);
  int greenButtonState = DetectButtonStateChange(g_greenButtonPin);
  int redButtonState = DetectButtonStateChange(g_redButtonPin);
  int yellowButtonState = DetectButtonStateChange(g_yellowButtonPin);
  
  if(blueButtonState == 1) Serial.println("You pressed the blue button!");
  else if(blueButtonState == 0) Serial.println("You released the blue button!");
  
  if(greenButtonState == 1) Serial.println("You pressed the green button!");
  else if(greenButtonState == 0) Serial.println("You released the green button!");
  
  if(redButtonState == 1) Serial.println("You pressed the red button!");
  else if(redButtonState == 0) Serial.println("You released the red button!");
  
  if(yellowButtonState == 1) Serial.println("You pressed the yellow button!");
  else if(yellowButtonState == 0) Serial.println("You released the yellow button!");
}

void ChangeStateWithButtonPresses(void)
{
  if(DetectButtonStateChange(g_blueButtonPin) == 1)
  {
    g_currentState = g_states[g_currentState].nextState(0); 
    Serial.println(g_currentState); 
  }
  
  if(DetectButtonStateChange(g_greenButtonPin) == 1)
  {
    g_currentState = g_states[g_currentState].nextState(1); 
    Serial.println(g_currentState);
  }
 
  if(DetectButtonStateChange(g_redButtonPin) == 1)
  {
    g_currentState = g_states[g_currentState].nextState(2); 
    Serial.println(g_currentState);
  }
  
  if(DetectButtonStateChange(g_yellowButtonPin) == 1)
  {
    g_currentState = g_states[g_currentState].nextState(3);
    Serial.println(g_currentState);
  }
}

