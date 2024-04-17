/*Keypad example
    by miliohm.com */

#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

String pad;
const byte numRows = 4;
const byte numCols = 4;

char keymap[numRows][numCols] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
//------------------------------------------------------------
byte rowPins[numRows] = {10,9, 8, 7};
byte colPins[numCols] = {6, 5, 4, 3};

Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols); //mapping keypad

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Keypad");
  lcd.setCursor(0, 1);
  lcd.print("Test");
  delay(1000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  readKeypad();
  lcd.setCursor(0, 0);
  lcd.print("hello!");
  lcd.print(pad);
  delay(100);
}

void readKeypad() {
  
  char keypressed = myKeypad.getKey(); //deteksi penekanan keypad
  String konv = String(keypressed);
  pad += konv;
}
