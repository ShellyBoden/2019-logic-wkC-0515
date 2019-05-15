/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/DigitalReadSerial
*/

// digital pin 2 has a pushbutton attached to it. Give it a name:
//int pushButton = 2;
byte seven_seg_digits[10][7] = { { 1,1,1,1,1,1,0 },  // = 0
                                 { 0,1,1,0,0,0,0 },  // = 1
                                 { 1,1,0,1,1,0,1 },  // = 2
                                 { 1,1,1,1,0,0,1 },  // = 3
                                 { 0,1,1,0,0,1,1 },  // = 4
                                 { 1,0,1,1,0,1,1 },  // = 5
                                 { 1,0,1,1,1,1,1 },  // = 6
                                 { 1,1,1,0,0,0,0 },  // = 7
                                 { 1,1,1,1,1,1,1 },  // = 8
                                 { 1,1,1,0,0,1,1 }   // = 9
                             };

int num = 0;
int btnState=0; //add


// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(13,INPUT); //add
  digitalWrite(13,HIGH); //add
  digitalWrite(9, 0);  // 關閉小數點
  // initialize serial communication at 9600 bits per second:
  // make the pushbutton's pin an input:
}

void sevenSegWrite(byte digit) {
  byte pin = 2;
  for (byte seg = 0; seg < 7; ++seg) {
    digitalWrite(pin, seven_seg_digits[digit][seg]);
    ++pin;
  }
}


// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
    while(1){
      btnState = digitalRead(13); //add
      Serial.println(num);
      sevenSegWrite(num); 
     num ++;
     delay(1000);
  
      if(num > 9){
         num = 0;
      }
      
      if(btnState == LOW){
        num=0;
      }
    }
  // print out the state of the button:
}
