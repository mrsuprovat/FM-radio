#include <Wire.h>
#include <TEA5767Radio.h>
#include <LiquidCrystal_I2C.h>

TEA5767Radio radio;
LiquidCrystal_I2C lcd(0x27, 16, 2);

// FM station list (Preset)
float presetStations[] = {91.9, 92.7, 93.5, 94.3, 98.3, 100.1, 101.8, 104.0, 104.8, 106.2, 106.4, 107, 107.8};
int totalStations = sizeof(presetStations) / sizeof(presetStations[0]);

int freqUpButton = 3;
int freqDownButton = 2;
int presetUpButton = 5;
int presetDownButton = 4;

float currentFrequency = 91.9;
int presetIndex = 0;

void setup() {
  pinMode(freqUpButton, INPUT);
  pinMode(freqDownButton, INPUT);
  pinMode(presetUpButton, INPUT);
  pinMode(presetDownButton, INPUT);
  
  lcd.begin();
  lcd.backlight();
  
  Wire.begin();
  radio.setFrequency(currentFrequency);
  
  updateDisplay();
}

void loop() {
  if (digitalRead(freqUpButton) == HIGH) {
    currentFrequency += 0.05;
    if (currentFrequency > 108.0) currentFrequency = 108.0;
    radio.setFrequency(currentFrequency);
    updateDisplay();
    delay(500);
  }

  if (digitalRead(freqDownButton) == HIGH) {
    currentFrequency -= 0.05;
    if (currentFrequency < 87.5) currentFrequency = 87.5;
    radio.setFrequency(currentFrequency);
    updateDisplay();
    delay(500);
  }

  if (digitalRead(presetUpButton) == HIGH) {
    presetIndex++;
    if (presetIndex >= totalStations) presetIndex = 0;
    currentFrequency = presetStations[presetIndex];
    radio.setFrequency(currentFrequency);
    updateDisplay();
    delay(500);
  }

  if (digitalRead(presetDownButton) == HIGH) {
    presetIndex--;
    if (presetIndex < 0) presetIndex = totalStations - 1;
    currentFrequency = presetStations[presetIndex];
    radio.setFrequency(currentFrequency);
    updateDisplay();
    delay(500);
  }
}

void updateDisplay() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SUPRO FM: ");
  lcd.print(currentFrequency, 2);
  
  lcd.setCursor(0, 1);
  if (presetIndex >= 0 && presetIndex < totalStations) {
    lcd.print("Preset: ");
    lcd.print(presetStations[presetIndex]);
  }
}
