#include "RGB_LED.h"
#include "Slingshot.h"
#include "BasicComponent.h"
#include "TimedOutputComponent.h"

#define BTN1_PIN 25 // left flipper
#define BTN2_PIN 24 // right flipper

#define FLIPPER_L 27
#define FLIPPER_R 26

#define BTN1_R 2
#define BTN1_G 3
#define BTN1_B 4

#define BTN2_R 8
#define BTN2_G 9
#define BTN2_B 10

#define START_R 5
#define START_G 6
#define START_B 7
#define START_IN 33

#define LEFT_SLING_IN 23
#define LEFT_SLING_OUT 49

#define RIGHT_SLING_IN 22
#define RIGHT_SLING_OUT 47 //50

#define RAMP_RETURN_OUT 51
#define RAMP_RETURN_IN 32

#define LAUNCHER 48

// #define POP_BUMPER_1_IN 34
// #define POP_BUMPER_1_OUT 49

#define POP_BUMPER_1_IN 37
#define POP_BUMPER_1_OUT 46

// #define TEST_ROLLOVER 36

RGB_LED *btn1_led;
RGB_LED *btn2_led;
RGB_LED *start_led;

Slingshot *leftSling;
Slingshot *rightSling;

BasicComponent *leftFlipper;
BasicComponent *rightFlipper;
TimedOutputComponent *launcher;
TimedOutputComponent *rampReturn;
// BasicComponent *launcher;
// BasicComponent *rampReturn;

TimedOutputComponent *popBumper1;

void setup() {
  // Serial.begin(115200);
  // delay compensates for odd hardware issue where inputs briefly start off as on
  delay(500);
  btn1_led = new RGB_LED(BTN1_R, BTN1_G, BTN1_B, COMMON_CATHODE);
  btn2_led = new RGB_LED(BTN2_R, BTN2_G, BTN2_B);
  start_led = new RGB_LED(START_R, START_G, START_B);

  leftSling = new Slingshot(LEFT_SLING_IN, LEFT_SLING_OUT);
  rightSling = new Slingshot(RIGHT_SLING_IN, RIGHT_SLING_OUT);

  leftFlipper = new BasicComponent(BTN1_PIN, FLIPPER_L);
  rightFlipper = new BasicComponent(BTN2_PIN, FLIPPER_R);
  // launcher = new BasicComponent(START_IN, LAUNCHER, LOW, HIGH);
  launcher = new TimedOutputComponent(START_IN, LAUNCHER, 20, LOW, HIGH);

  // rampReturn = new BasicComponent(RAMP_RETURN_IN, RAMP_RETURN_OUT, HIGH, HIGH);
  rampReturn = new TimedOutputComponent(RAMP_RETURN_IN, RAMP_RETURN_OUT, 60, HIGH, HIGH);

  popBumper1 = new TimedOutputComponent(POP_BUMPER_1_IN, POP_BUMPER_1_OUT, 50, HIGH, HIGH);

  btn1_led->initRainbow();
  btn2_led->initRainbow();
  start_led->initRainbow(180);
}

void loop() {
  leftFlipper->update();
  rightFlipper->update();
  launcher->update();
  rampReturn->update();
  // Serial.println(rampReturn->inputActivated());

  leftSling->update();
  rightSling->update();

  popBumper1->update();

  btn1_led->rainbow(15);
  btn2_led->rainbow(15);
  start_led->rainbow(15);
}
