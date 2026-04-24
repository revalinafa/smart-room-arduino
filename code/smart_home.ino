#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ======================
// PIN
// ======================
int ldrPin = A1;
int lampPin = 12;

int tempPin = A0;
int fanPin = 11;

int gasPin = A2;
int buzzerPin = 10;

int ledHijau = 9;
int ledBiru  = 8;
int ledMerah = 7;

int buttonMode = 2;   // interrupt
int buttonLamp = 6;   // manual lamp
int buttonFan  = 5;   // manual fan

// ======================
// STATUS
// ======================
bool autoMode = true;

bool lampManual = false;
bool fanManual  = false;

bool lampStatus = false;
bool fanStatus  = false;

bool lastLampState = HIGH;
bool lastFanState  = HIGH;

unsigned long lastInterrupt = 0;
unsigned long lastLCD = 0;

// ======================
// SETUP
// ======================
void setup() {

  pinMode(lampPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  pinMode(ledHijau, OUTPUT);
  pinMode(ledBiru, OUTPUT);
  pinMode(ledMerah, OUTPUT);

  pinMode(buttonMode, INPUT_PULLUP);
  pinMode(buttonLamp, INPUT_PULLUP);
  pinMode(buttonFan, INPUT_PULLUP);

  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(buttonMode), gantiMode, FALLING);

  lcd.init();
  lcd.backlight();
  lcd.clear();
}

// ======================
// LOOP
// ======================
void loop() {

  // ======================
  // SENSOR
  // ======================
  int cahaya = analogRead(ldrPin);
  int gasValue = analogRead(gasPin);
  int sensorValue = analogRead(tempPin);

  float voltage = sensorValue * 5.0 / 1023.0;
  float suhu = (voltage - 0.5) * 100.0;

  // ======================
  // LED MODE
  // ======================
  digitalWrite(ledHijau, autoMode);
  digitalWrite(ledBiru, !autoMode);

  // ======================
  // MODE AUTO
  // ======================
  if (autoMode) {

    lampManual = false;
    fanManual = false;

    // lampu otomatis
    if (cahaya < 550) {
      digitalWrite(lampPin, HIGH);
      lampStatus = true;
    } else {
      digitalWrite(lampPin, LOW);
      lampStatus = false;
    }

    // fan otomatis
    if (suhu >= 27) {
      analogWrite(fanPin, 255);
      fanStatus = true;
    } else {
      analogWrite(fanPin, 0);
      fanStatus = false;
    }
  }

  // ======================
  // MODE MANUAL
  // ======================
  else {

    bool bacaLamp = digitalRead(buttonLamp);
    bool bacaFan  = digitalRead(buttonFan);

    // tombol lampu
    if (lastLampState == HIGH && bacaLamp == LOW) {
      lampManual = !lampManual;
    }

    // tombol fan
    if (lastFanState == HIGH && bacaFan == LOW) {
      fanManual = !fanManual;
    }

    lastLampState = bacaLamp;
    lastFanState  = bacaFan;

    // lampu manual
    digitalWrite(lampPin, lampManual);
    lampStatus = lampManual;

    // fan manual
    if (fanManual) {
      analogWrite(fanPin, 255);
      fanStatus = true;
    } else {
      analogWrite(fanPin, 0);
      fanStatus = false;
    }
  }

  // ======================
  // SENSOR GAS
  // ======================
  String gasText = "SAFE";

  if (gasValue > 100) {
    digitalWrite(ledMerah, HIGH);
    gasText = "WARNING";
  } else {
    digitalWrite(ledMerah, LOW);
  }

  if (gasValue > 300) {
    tone(buzzerPin, 500);
    gasText = "DANGER";
  } else {
    noTone(buzzerPin);
  }

  // ======================
  // LCD UPDATE (smooth)
  // ======================
  if (millis() - lastLCD > 200) {

    lcd.setCursor(0, 0);
    lcd.print("Mode: ");

    if (autoMode)
      lcd.print("AUTO   ");
    else
      lcd.print("MANUAL ");

    lcd.setCursor(0, 1);
    lcd.print("S:");
    lcd.print((int)suhu);
    lcd.print("C ");

    lcd.print("G:");
    lcd.print(gasText);
    lcd.print("   ");

    lastLCD = millis();
  }

  // ======================
  // SERIAL MONITOR
  // ======================
  Serial.print("Mode: ");
  Serial.print(autoMode ? "AUTO" : "MANUAL");

  Serial.print(" | Cahaya: ");
  Serial.print(cahaya);

  Serial.print(" | Suhu: ");
  Serial.print(suhu);

  Serial.print(" C | Gas: ");
  Serial.print(gasValue);

  Serial.print(" | Lampu: ");
  Serial.print(lampStatus);

  Serial.print(" | Fan: ");
  Serial.println(fanStatus);

  delay(10);
}

// ======================
// INTERRUPT MODE
// ======================
void gantiMode() {

  if (millis() - lastInterrupt > 300) {
    autoMode = !autoMode;
    lastInterrupt = millis();
  }
}