#include <LiquidCrystal.h>
#include "Input.h"

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

uint8_t position        = 0;
uint8_t level           = 0;

bool init_draw          = true;

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

void draw_terrain() {
  randomSeed(((position / 16 + 1) << 8) + level);

  for (uint8_t i = 0; i < 16; i++) {
    if ((random() % 4) == 0) { lcd.setCursor(i, 1); lcd.print("T"); }
  }
};

void draw_stairs() {
  randomSeed(level);

  uint8_t up   = random(256);
  uint8_t down = up;

  while (up == down) { down = random(256); }

  if (level > 0 && up >= (position / 16) * 16 && up < ((position / 16) + 1) * 16) {
    lcd.setCursor(up % 16, 1);
    lcd.print("<");
  }

  if (level < 255 && down >= (position / 16) * 16 && down < ((position / 16) + 1) * 16) {
    lcd.setCursor(down % 16, 1);
    lcd.print(">");
  }
}

void draw() {
  if (init_draw) {
    lcd.begin(16, 2);
    init_draw = false;
  } else {
    lcd.clear();
  }

  draw_position();
  draw_terrain();
  draw_stairs();
  draw_player();
};

void setup() {
  draw();
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
    draw();
  }

  delay(30);
}
