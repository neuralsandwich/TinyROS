#include <Wire.h>

#define SLAVE_ADDRESS 0x04
int number = 0;
int state = 0;

double temp;

void setup() {
  pinMode(13, OUTPUT);

  // initialize i2c as slave
  Wire.begin(SLAVE_ADDRESS);

  // define callbacks for i2c communication
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
}

void loop() {
  delay(10);
}

// callback for received data
void receiveData(int byteCount){

  while(Wire.available()) {
    number = Wire.read();

    if (number == 1){
      if (state == 0){
	digitalWrite(13, HIGH); // set the LED on
	state = 1;
      } else{
	digitalWrite(13, LOW); // set the LED off
	state = 0;
      }
    } else {
      number = 42;
    }
  }
}

// callback for sending data
void sendData(){
  Wire.write(number);
}
