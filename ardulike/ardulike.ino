#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int last_change_at  = 0;
int last_value      = 1024;

void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
}

void loop() {
  int reading = analogRead(A0);
  int now = millis();

  lcd.clear();
  lcd.setCursor(0, 1);

  if (reading != last_value && (now - last_change_at) > 50) {
    if (reading == 407) {
      lcd.print("LEFT");
      Serial.println("LEFT");
    }
    last_value = reading;
    last_change_at = now;
  } else {
    Serial.println("NONE");
  }

  delay(20);
}
