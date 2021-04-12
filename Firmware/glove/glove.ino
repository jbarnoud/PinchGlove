#include <BleGamepad.h>
#include <TinyPICO.h>


#define PIN_INDEX 25
#define PIN_MAJOR 21

class Button {
  private:
    int _pin;
    int _button;
    BleGamepad *_gamepad;
    bool _was_pressed;
    bool _is_pressed;
  public:
    Button(int button) {
      _button = button;
      _was_pressed = false;
      _is_pressed = false;
    }
    
    void attach(int pin, BleGamepad *gamepad) {
      pinMode(pin, INPUT_PULLUP);
      _pin = pin;
      _gamepad = gamepad;
    }

    void update() {
      bool is_pressed = (digitalRead(_pin) == LOW);
      if (!_was_pressed && is_pressed) {
        _gamepad->press(_button);
        Serial.print("Press ");
        Serial.println(_button);
      } else if (_was_pressed && !is_pressed) {
        _gamepad->release(_button);
        Serial.print("Release ");
        Serial.println(_button);
      }
      _was_pressed = is_pressed;
    }
};


BleGamepad bleGamepad;
TinyPICO tp = TinyPICO();

bool was_connected = false;
Button index_finger = Button(BUTTON_1);
Button major_finger = Button(BUTTON_5);


void setup() 
{
  tp.DotStar_SetPixelColor(0, 0, 255);
  index_finger.attach(PIN_INDEX, &bleGamepad);
  major_finger.attach(PIN_MAJOR, &bleGamepad);
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleGamepad.begin();
  
}

void loop() 
{
  if(bleGamepad.isConnected()) 
  {
    if (!was_connected) {
      Serial.println("Connected");
      tp.DotStar_SetPixelColor(0, 255, 0);
      was_connected = true;
    }
    index_finger.update();
    major_finger.update();
  } else {
    if (was_connected) {
      Serial.println("Disconnected");
      tp.DotStar_SetPixelColor(255, 0, 0);
      was_connected = false;
    }
  }
}
