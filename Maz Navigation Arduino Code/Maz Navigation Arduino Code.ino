/* @file HelloKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates the simplest use of the matrix Keypad library for the Velleman VMA300.
|| #
*/
#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
 {'1','2','3'},
 {'4','5','6'},
 {'7','8','9'},
 {'*','0','#'}
};
byte rowPins[ROWS] = {8, 7, 6, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 3, 2}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
void setup(){
 Serial.begin(9600);
}

void loop(){
 char key = keypad.getKey();

if (key){
 Serial.println(key);
 }
}
