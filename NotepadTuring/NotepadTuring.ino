
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27, 16 , 2);

const byte numRows = 4;
const byte numCols = 4;

char keymap[numRows][numCols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[numRows] = {10, 9, 7, 6};
byte colPins[numCols] = {5, 4, 3, 2};
int numLength =  0; 
int numLengthBottom = 0;

Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

void setup() {
  // put your setup code here, to run once:
  lcd.init();                      
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print(" Sci Pro"); //Start up name on 1st row for calculator
  lcd.setCursor(3,1);
  lcd.print("Calculator"); //Start up name on 2nd row for calculator
  delay(4000);
  lcd.clear();
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  char keypressed = myKeypad.getKey();
  if (keypressed!= NO_KEY)
   {
    if (numLength == 17 || numLengthBottom > 0) {
      if (numLengthBottom > 0) {
        lcd.setCursor(numLengthBottom - 1, 1);
      } else {
        lcd.setCursor(0, 1);
      }
      
      Serial.println("The column changed");
    } 
    if (keypressed == '#') {
      lcd.clear();
      lcd.setCursor(0, 0);
      numLength = 0;
      numLengthBottom = 0;
    } else if (keypressed == '*') {
      if ((numLength <= 16) && (numLengthBottom == 0)) {
        lcd.setCursor(numLength - 1, 0);// integrate dynamic column
        lcd.print(" ");
        lcd.setCursor(numLength - 1, 0);
        if (numLength > 0) {
           numLength -= 1;
        }
        
        Serial.println("You are now on index: ");
        Serial.println(numLength - 1);
        Serial.println("Current numLength is:");
        Serial.println(numLength);
      } else {
        Serial.println("Removing on Second on Line");


        if (numLengthBottom < 18) {

        lcd.setCursor(numLengthBottom - 1, 1);// integrate dynamic column
        lcd.print(" ");
        lcd.setCursor(numLengthBottom - 1, 1);
        if (numLengthBottom > 0) {
           numLengthBottom -= 1;
        }
        
        Serial.println("You are now on index: ");
        Serial.println(numLengthBottom - 1);
        Serial.println("Current numLengthBottom is:");
        Serial.println(numLengthBottom);
       
      } 

      }

    }
      
      else {
      Serial.println(keypressed);
      lcd.print(keypressed);

    
      
      if (numLength < 16) {
        numLength += 1;
        Serial.println("Number Length is: ");
        Serial.println(numLength);
      } else {
        numLengthBottom += 1;
        Serial.println("Number LengthBottom  is: ");
        Serial.println(numLengthBottom);
        if (numLength == 17) {
          lcd.setCursor(0, 1);
          lcd.print(keypressed);
        }
      }
        
      }
      
  
    }
    
    
   }
