// DIM-Guitar v0.2
// https://github.com/rayder13/DIM-Guitar
// Distributed under GPL 3.0 license.
// 
// NOTE: This sketch file is for use with Arduino Leonardo and
//       Arduino Micro only.
// 
// I have tried to retain as much of the original GH guitar
// functionality as possible while constraining everything
// to work on a 5v Pro Micro board.
//
// Uses the unmodified Joystick.h library from
// https://github.com/MHeironimus/ArduinoJoystickLibrary
// under GPL 3.0 license.
// 
// by rayder13
// 
//--------------------------------------------------------------------

#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  15, 0,                 // 6 Fret Buttons, 5 D-Pad Buttons and 2 for up/down strum bar, start and star power, No Hat Switch
  true, false, false,    // X Axis for whammy bar, no Y Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

const byte buttonPin[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 14, 15, 16, A0, A2, A3};

void setup() {

//  Serial.begin(9600);
//  while (!Serial) {
//    delay(200); // wait for serial port to connect. Needed for native USB
//  }
  
  // Initialize Button Pins
  pinMode(2, INPUT_PULLUP);   // Fret 1
  pinMode(3, INPUT_PULLUP);   // Fret 2
  pinMode(4, INPUT_PULLUP);   // Fret 3
  pinMode(5, INPUT_PULLUP);   // Fret 4
  pinMode(6, INPUT_PULLUP);   // Fret 5
  pinMode(7, INPUT_PULLUP);   // Fret 6
  pinMode(8, INPUT_PULLUP);   // Strum Up
  pinMode(9, INPUT_PULLUP);   // Strum Down
  pinMode(10, INPUT_PULLUP);  // D-Pad Middle
  pinMode(14, INPUT_PULLUP);  // D-Pad Up
  pinMode(15, INPUT_PULLUP);  // D-Pad Right
  pinMode(16, INPUT_PULLUP);  // D-Pad Down
  pinMode(A0, INPUT_PULLUP);  // D-Pad Left
  pinMode(A1, INPUT);         // Whammy Bar
  pinMode(A2, INPUT_PULLUP);  // Star Power
  pinMode(A3, INPUT_PULLUP);  // Start

  // Initialize Joystick Library
  Joystick.begin();

  // The original potentiometer in the WoR guitar doesn't have full range of
  // motion (0-1023). Seems to go up to around 650 so set to 600 to ensure
  // effects of existing wear is minimised.
  Joystick.setXAxisRange(1, 600); 
}

// Constant that maps the phyical pin to the joystick button.
// 15/09/20 probably have no use for this?
// const int pinToButtonMap = 2;

// Last state of the buttons
int lastButtonState[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void loop() {

  // Read pin values
  for (int index = 0; index < 15; index++)
  {
//    int currentButtonState = !digitalRead(index + pinToButtonMap);
    int currentButtonState = !digitalRead(buttonPin[index]);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
    
    int whammyPos = analogRead(A1);
    Joystick.setXAxis(whammyPos);
//    Serial.println(analogRead(A1));
  }

  delay(10);
}
