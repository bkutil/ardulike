#include <LiquidCrystal.h>

enum directions { none, left, right };

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int last_change_at  = 0;
int last_value      = 1024;
int position        = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(position, 1);
  lcd.print('@');
}

void loop() {
  directions direction = none;

  int reading = analogRead(A0);
  int now = millis();

  if (reading != last_value && (now - last_change_at) > 50) {
    if (reading == 407) {
      direction = left;
    } else
    if (reading == 0) {
      direction = right;
    }
    last_value = reading;
    last_change_at = now;
  }

  if (direction == left) {
    position = (16 + position - 1) % 16;
  } else
  if (direction == right) {
    position = (16 + position + 1) % 16;
  }

  if (direction != none) {
    lcd.clear();
    lcd.setCursor(position, 1);
    lcd.print('@');
  }

  delay(30);
}
