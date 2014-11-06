#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
}

void loop() {
  int reading = analogRead(A0);
  lcd.clear();
  lcd.setCursor(0, 1);

  if (reading == 407) {
    lcd.print("LEFT");
    Serial.println("LEFT");
  } else {
    Serial.println("NONE");
  }

  delay(20);
}
