#include <LiquidCrystal.h>
#include "Input.h"

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

uint8_t position        = 0;
uint8_t level           = 0;

void draw_player() {
  lcd.setCursor(position % 16, 1);
  lcd.print('@');
};

void draw_position() {
  lcd.setCursor(0,0);
  lcd.print("L:");
  lcd.print(level);
  lcd.print("S:");
  lcd.print(position / 16);
}

void setup() {
  lcd.begin(16, 2);
  draw_position();
  draw_player();
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
    draw_position();
    draw_player();
  }

  delay(30);
}
