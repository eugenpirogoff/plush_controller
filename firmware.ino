#include <CapPin.h>

CapPin cPin_10 = CapPin(10);    // read pin 10 (D10 on Flora) - connect to NES B
CapPin cPin_9  = CapPin(9);     // read pin 9 (D9 on Flora)   - connect to NES A
CapPin cPin_6  = CapPin(6);     // read pin 6 (D6 on Flora)   - connect to NES Start
CapPin cPin_12 = CapPin(12);    // read pin 12 (D12 on Flora) - connect to NES Select
CapPin cPin_1  = CapPin(1);     // read pin 1 (TX on Flora)   - connect to NES right
CapPin cPin_0  = CapPin(0);     // read pin 0 (RX on Flora)   - connect to NES up
CapPin cPin_2  = CapPin(2);     // read pin 2 (SDA on Flora)  - connect to NES left
CapPin cPin_3  = CapPin(3);     // read pin 3 (SCL on Flora)  - connect to NES down

CapPin pins[] = {cPin_10, cPin_9, cPin_6, cPin_12, cPin_1, cPin_0, cPin_2, cPin_3};

char Keys[] =   {  'a',    'b',    ' ',     KEY_RETURN, KEY_RIGHT_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_DOWN_ARROW};
boolean currentPressed[] = {false, false, false, false, false, false, false, false};

#define THRESH 5

float smoothed[8] = {0,0,0,0,0,0,0,0};

void setup()
{
  Serial.begin(115200);
  Serial.println("start");
  Keyboard.begin();
}

void loop()                    
{ 
  for (int i=0;i<8;i++) {
    delay(1);
    long total1 = 0;
    long start = millis();
    long total =  pins[i].readPin(50);

    if ((total > THRESH) && (! currentPressed[i])) {
      Serial.print("Key pressed #"); Serial.print(i);
      Serial.print(" ("); Serial.print(Keys[i]); Serial.println(")");
      currentPressed[i] = true;

      Keyboard.press(Keys[i]);
    } 
    else if ((total <= THRESH) && (currentPressed[i])) {
      // key was released (no touch, and it was pressed before)
      Serial.print("Key released #"); Serial.print(i);
      Serial.print(" ("); Serial.print(Keys[i]); Serial.println(")");
      currentPressed[i] = false; 
      Keyboard.release(Keys[i]);
    }
    delay(3);
  }
}
