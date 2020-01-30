#include "Button.h"
#include "Led.h"

#define Button_1 49
#define Button_2 50
#define Button_3 51
#define Button_4 52
#define Button_5 53

#define Led_1 22
#define Led_2 23
#define Led_3 24
#define Led_4 25
#define Led_5 26

Button button1(Button_1);
Button button2(Button_2);
Button button3(Button_3);
Button button4(Button_4);
Button button5(Button_5);

Led Led1(Led_1);
Led Led2(Led_2);
Led Led3(Led_3);
Led Led4(Led_4);
Led Led5(Led_5);


void setup()
{
  Serial.begin(115200);
  button1.begin();
}

void loop()
{
  static bool ledState;
  button1.read();
  if (button1.wasReleased())
  {
    Serial.println("1. Button pressed");
    ledState = !ledState;
    digitalWrite(Led_1, ledState);
  }

  button2.read();
  if (button2.wasReleased())
  {
    Serial.println("2. Button pressed");
    ledState = !ledState;
    digitalWrite(Led_2, ledState);
  }

  button3.read();
  if (button3.wasReleased())
  {
    Serial.println("3. Button pressed");
    ledState = !ledState;
    digitalWrite(Led_3, ledState);
  }

  button4.read();
  if (button4.wasReleased())
  {
    Serial.println("4. Button pressed");
    ledState = !ledState;
    digitalWrite(Led_4, ledState);
  }

  button5.read();
  if (button5.wasReleased())
  {
    Serial.println("5. Button pressed");
    ledState = !ledState;
    digitalWrite(Led_5, ledState);
  }
}
