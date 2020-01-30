#include <Arduino.h>

class Button
{
  public:

    Button(uint8_t pin, uint32_t dbTime = 25, uint8_t puEnable = true, uint8_t invert = true)
      : pin(pin), m_dbTime(dbTime), m_puEnable(puEnable), m_invert(invert) {}

    void begin();

    bool read();
    bool isPressed();
    bool isReleased();
    bool wasPressed();
    bool wasReleased();
    bool pressedFor(uint32_t ms);
    bool releasedFor(uint32_t ms);
    uint32_t lastChange();

  private:
    uint8_t pin;
    uint32_t m_dbTime;
    bool m_puEnable;
    bool m_invert;
    bool m_state;
    bool m_lastState;
    bool m_changed;
    uint32_t m_time;
    uint32_t m_lastChange;
};

class ToggleButton : public Button
{
  public:

    ToggleButton(uint8_t pin, bool initialState = false, uint32_t dbTime = 25, uint8_t puEnable = true, uint8_t invert = true)
      : Button(pin, dbTime, puEnable, invert), m_toggleState(initialState) {}

    bool read()
    {
      Button::read();
      if (wasPressed())
      {
        m_toggleState = !m_toggleState;
        m_changed = true;
      }
      else
      {
        m_changed = false;
      }
      return m_toggleState;
    }

    bool changed() {
      return m_changed;
    }

    bool toggleState() {
      return m_toggleState;
    }

  private:
    bool m_toggleState;
    bool m_changed;
};
