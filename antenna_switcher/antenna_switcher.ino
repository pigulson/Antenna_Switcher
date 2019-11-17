//ANTENNA SWITCHER 
//by SP3H & SQ7OVR


#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Keypad.h>

//YOU CAN CHANGE ANTENNA DESCRIPTIONS HERE
//TU MOŻESZ ZMIENIAĆ OPISY ANTEN
String opis1 = "opis1"; //antena 1
String opis2 = "opis2"; //antena 2
String opis3 = "opis3"; //antena 3
String opis4 = "opis4"; //antena 4
String opis5 = "opis5"; //antena 5
String opis6 = "opis6"; //antena 6
String opis7 = "opis7"; //antena 7
String opis8 = "opis8"; //antena 8
//KONIEC EDYCJI

//keypad
const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {12, 11, 10, 9}; 
byte colPins[COLS] = {8, 7, 6, 5}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

//display
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

//relays
int R1 = 4;
int R2 = 3;
int R3 = 2;
int R4 = 14;
int R5 = 15;
int R6 = 16;
int R7 = 17;
int R8 = 13;

#define ON   0
#define OFF  1

void setup() {

  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(R4, OUTPUT);
  pinMode(R5, OUTPUT);
  pinMode(R6, OUTPUT);
  pinMode(R7, OUTPUT);
  pinMode(R8, OUTPUT);
 
  relay_SetStatus(OFF,OFF,OFF,OFF,OFF,OFF,OFF,OFF); //turn off all the relay
  
  lcd.begin(16,2);   //display start
  lcd.setCursor(0,0); 
  lcd.print("ANTENNA SWITCHER");
  lcd.setCursor(0,1); 
  lcd.print("by SP3H & SQ7OVR");
  delay(2000);
  Serial.begin(9600);
  lcd.clear();
  lcd.setCursor(1,0); 
  lcd.print("Wybierz antene");
  lcd.setCursor(0,1); 
  lcd.print("1 - 8   D - BRAK");
  }

void loop()
{
    switch ( customKeypad.getKey() )
    {
        case '1': 
        relay_SetStatus(ON,OFF,OFF,OFF,OFF,OFF,OFF,OFF);
        lcd.clear();
        lcd.setCursor(4,0); 
        lcd.print("ANTENNA 1");
        lcd.setCursor(0,1); 
        lcd.print(opis1);
        break;
        case '2': 
        relay_SetStatus(OFF,ON,OFF,OFF,OFF,OFF,OFF,OFF);
        lcd.clear();
        lcd.setCursor(4,0); 
        lcd.print("ANTENNA 2");
        lcd.setCursor(0,1); 
        lcd.print(opis2);
        break;
        case '3': 
        relay_SetStatus(OFF,OFF,ON,OFF,OFF,OFF,OFF,OFF);
        lcd.clear();
        lcd.setCursor(4,0); 
        lcd.print("ANTENNA 3");
        lcd.setCursor(0,1); 
        lcd.print(opis3);
        break;
        case '4': 
        relay_SetStatus(OFF,OFF,OFF,ON,OFF,OFF,OFF,OFF);
        lcd.clear();
        lcd.setCursor(4,0); 
        lcd.print("ANTENNA 4");
        lcd.setCursor(0,1); 
        lcd.print(opis4);
        break;
        case '5': 
        relay_SetStatus(OFF,OFF,OFF,OFF,ON,OFF,OFF,OFF);
        lcd.clear();
        lcd.setCursor(4,0); 
        lcd.print("ANTENNA 5");
        lcd.setCursor(0,1); 
        lcd.print(opis5);
        break;
        case '6': 
        relay_SetStatus(OFF,OFF,OFF,OFF,OFF,ON,OFF,OFF);
        lcd.clear();
        lcd.setCursor(4,0); 
        lcd.print("ANTENNA 6");
        lcd.setCursor(0,1); 
        lcd.print(opis6);
        break;
        case '7': 
        relay_SetStatus(OFF,OFF,OFF,OFF,OFF,OFF,ON,OFF);
        lcd.clear();
        lcd.setCursor(4,0); 
        lcd.print("ANTENNA 7");
        lcd.setCursor(0,1); 
        lcd.print(opis7);
        break;
        case '8': 
        relay_SetStatus(OFF,OFF,OFF,OFF,OFF,OFF,OFF,ON);
        lcd.clear();
        lcd.setCursor(4,0); 
        lcd.print("ANTENNA 8");
        lcd.setCursor(0,1); 
        lcd.print(opis8);
        break;
        case 'D': 
        relay_SetStatus(OFF,OFF,OFF,OFF,OFF,OFF,OFF,OFF);
        lcd.clear();
        lcd.setCursor(6,0);
        lcd.print("BRAK");
        lcd.setCursor(5,1);
        lcd.print("ANTENY");
    }
}

void relay_SetStatus( unsigned char status_1,  unsigned char status_2, unsigned char status_3, unsigned char status_4, unsigned char status_5, unsigned char status_6, unsigned char status_7, unsigned char status_8)
{
  digitalWrite(R1, status_1);
  digitalWrite(R2, status_2);
  digitalWrite(R3, status_3);
  digitalWrite(R4, status_4);
  digitalWrite(R5, status_5);
  digitalWrite(R6, status_6);
  digitalWrite(R7, status_7);
  digitalWrite(R8, status_8);
}
