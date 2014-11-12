#include <LiquidCrystal.h>
#include "Input.h"

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

uint8_t position        = 0;
uint8_t level           = 0;

void setup() {
  lcd.begin(16, 2);

  lcd.setCursor(0,0);
  lcd.print("L:");
  lcd.print(level);
  lcd.print("S:");
  lcd.print(position / 16);
  lcd.setCursor(position, 1);
  lcd.print('@');
}

void loop() {
  bool changed = false;
  Button input = Input::get();

  if (input == ButtonLeft) {
    position -= 1;
    changed   = true;
  } else
  if (input == ButtonRight) {
    position += 1;
    changed   = true;
  }

  if (changed) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("L:");
    lcd.print(level);
    lcd.print("S:");
    lcd.print(position / 16);

    lcd.setCursor(position % 16, 1);
    lcd.print('@');
  }

  delay(30);
}
