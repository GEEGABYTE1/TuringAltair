
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27, 16 , 2);

const byte numRows = 4;
const byte numCols = 4;
int GreenledPin = 11;
int RedledPin = 12;

int buttonSavePin = 0;
int buttonSkippedPin = 1;
int val;
int val2; // Button With Yellow Cap

char keymap[numRows][numCols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

String documents [4] = {" _ ", " _ ", " _ ", " _ "};

byte rowPins[numRows] = {10, 9, 7, 6};
byte colPins[numCols] = {5, 4, 3, 2};
int numLength =  0; 
int numLengthBottom = 0;
String current_string_typed = "";

bool bool_doc = false;
bool for_loop_bool = false;


Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

void setup() {
  // put your setup code here, to run once:
  pinMode(GreenledPin, OUTPUT);
  pinMode(buttonSavePin, INPUT);
  pinMode(buttonSkippedPin, INPUT);
  pinMode(RedledPin, OUTPUT);
  lcd.init();                      
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print(" Turing "); //Start up name on 1st row for calculator
  lcd.setCursor(3,1);
  lcd.print(" Altair "); //Start up name on 2nd row for calculator
  delay(4000);
  lcd.clear();
  Serial.begin(9600);
  pinMode(8, OUTPUT); // FAN

}

void loop() {
  

  // put your main code here, to run repeatedly:

  int temp = analogRead(A0);
  temp = temp * 0.48828125;
  
  if (temp > 40) {
    digitalWrite(0, HIGH);
    delay(2000);
  } else {
    digitalWrite(0, LOW);
    
  }
  
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


    if (keypressed == '0' && for_loop_bool == true) {
          documents[0] = current_string_typed;
          lcd.clear();
          delay(100);
          lcd.setCursor(0, 0);
          lcd.print("Saved at");
          lcd.setCursor(0, 1);
          lcd.print("Index: 0");
          Serial.println("New Value at Index 0: ");
          Serial.println(documents[0]);
          bool_doc = false;
          for_loop_bool = false;
          delay(1000);
          lcd.clear();
          numLength = 0;
          numLengthBottom = 0;
          digitalWrite(RedledPin, LOW);
          digitalWrite(GreenledPin, LOW);
          } else if (keypressed == '1' && for_loop_bool == true) {
          Serial.println("Index one must be saved");
          documents[1] = current_string_typed;
          lcd.clear();
          delay(100);
          lcd.setCursor(0, 0);
          lcd.print("Saved at");
          lcd.setCursor(0, 1);
          lcd.print("Index: 1");
          Serial.println("New Value at Index 1: ");
          Serial.println(documents[1]);
          bool_doc = false;
          for_loop_bool = false;
          delay(1000);
          lcd.clear();
          numLength = 0;
          numLengthBottom = 0;
          digitalWrite(RedledPin, LOW );
          digitalWrite(GreenledPin, LOW);
      } else if (keypressed == '2' && for_loop_bool == true) {
          documents[2] = current_string_typed;
          lcd.clear();
          delay(100);
          lcd.setCursor(0, 0);
          lcd.print("Saved at");
          lcd.setCursor(0, 1);
          lcd.print("Index: 2");
          Serial.println("New Value at Index 2: ");
          Serial.println(documents[2]);
          bool_doc = false;
          for_loop_bool = false;
          delay(1000);
          lcd.clear();
          numLength = 0;
          numLengthBottom = 0;
          digitalWrite(RedledPin, LOW);
          digitalWrite(GreenledPin, LOW);
     } else if (keypressed == '3' && for_loop_bool == true) {
          documents[3] = current_string_typed;
          lcd.clear();
          delay(100);
          lcd.setCursor(0, 0);
          lcd.print("Saved at");
          lcd.setCursor(0, 1);
          lcd.print("Index: 3");
          Serial.println("New Value at Index 3: ");
          Serial.println(documents[3]);
          bool_doc = false;
          for_loop_bool = false;
          delay(1000);
          lcd.clear();
          numLength = 0;
          numLengthBottom = 0;
          digitalWrite(RedledPin, LOW);
          digitalWrite(GreenledPin, LOW);
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

        lcd.setCursor(numLengthBottom - 1, 1);
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

    } else if (keypressed == 'D' && bool_doc == false) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temp (*C):");
      lcd.setCursor(0, 1);
      lcd.print(temp);
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      
      
    }
    
    
    else if (keypressed == 'A' && bool_doc == false) {
      bool_doc = true;
      current_string_typed = "";
      numLength = 0;
      numLengthBottom = 0;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Document");
      lcd.setCursor(0, 1);
      lcd.print("Launched");
      delay(1100);
      lcd.clear();
      lcd.setCursor(0, 0);

       

      
      
      
      
    } else if (keypressed == 'B' && bool_doc == false) {
        lcd.setCursor(0, 0);
        lcd.print("Current Files");
        delay(1000);
        digitalWrite(RedledPin, HIGH);
        digitalWrite(GreenledPin, HIGH);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("File 1");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0, 0);
        Serial.println(documents[0]);
        lcd.print(documents[0]);
        delay(1000);
        lcd.clear();
        delay(1000);
        Serial.println(documents[1]);
        lcd.print("File 2");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(documents[1]);
        delay(1000);
        lcd.clear();
        delay(1000);
        lcd.print("File 3");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0, 0);
        Serial.println(documents[2]);
        lcd.print(documents[2]);
        delay(1000);
        lcd.clear();
        delay(1000);
        lcd.print("File 4");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0, 0);
        Serial.println(documents[3]);
        lcd.print(documents[3]);
        delay(1000);
        lcd.clear();
        delay(1000);
        digitalWrite(RedledPin, LOW);
        digitalWrite(GreenledPin, LOW);
    }
    
    else if (keypressed == 'C' && bool_doc == true) {
        
        Serial.println("Current String");
        Serial.println(current_string_typed);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Following");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Files");
        delay(1000);
        lcd.clear();
        for_loop_bool = true;
        digitalWrite(RedledPin, HIGH);
        digitalWrite(GreenledPin, HIGH);
       
        lcd.setCursor(0, 0);
        lcd.print("File 1");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0, 0);
        Serial.println(documents[0]);
        lcd.print(documents[0]);
        delay(1000);
        lcd.clear();
        delay(1000);
        lcd.print("File 2");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0, 0);
        Serial.println(documents[1]);
        lcd.print(documents[1]);
        delay(1000);
        lcd.clear();
        delay(1000);
        lcd.print("File 3");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0, 0);
        Serial.println(documents[2]);
        lcd.print(documents[2]);
        delay(1000);
        lcd.clear();
        delay(1000);
        lcd.print("File 4");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0, 0);
        Serial.println(documents[3]);
        lcd.print(documents[3]);
        delay(1000);
        lcd.clear();
        delay(1000);

        
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Index: ");
        lcd.setCursor(0, 1);
        
      }
      
      else {
      Serial.println(keypressed);
      lcd.print(keypressed);
      current_string_typed += String(keypressed);
      

    
      
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
