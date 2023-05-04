#include <Serial.h>

Serial raspi("/dev/ttyUSB0", 9600);

Serial arduino(Seriall, 9600);

void setup(){

    raspi.begin();
    arduino.begin();
}

void loop(){

    if(raspi.available() > 0){

        int data = raspi.read();

    arduino.write(data);
    }

if (arduino.available() > 0){

    int data = arduino.read();

   }
}
