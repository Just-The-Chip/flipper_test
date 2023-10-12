#include <stdint.h>

class Slingshot {
  public:
    Slingshot(int _switchPin, int _kickerPin);
    void update();

  private:
    int	switchPin;
    int	kickerPin;

    bool switchActivated();
};