/***********************************************
* name:Infrared-Receiver
* function:press the CH- key of a remote control,
* and both the LED attached and that connected to pin 13 on the Arduino Uno board will light up.
* Then press any other key, and the LEDs will go out.
**********************************************/
#include "IRremote.h"
const int irReceiverPin =7; //the SIG of receiver module attach to pin7 
IRrecv irrecv(irReceiverPin); //Creates a variable of type IRrecv
decode_results results;
void setup()
{
  pinMode(irReceiverPin, INPUT);
  Serial.begin(115200);//initialize serial 
  irrecv.enableIRIn(); //enable ir receiver module 
}
void loop() 
{
  if (irrecv.decode(&results)) //if the ir receiver module receives data
  {
//    Serial.println(results.value);
    switch (results.value) {
      case 2534850111: //1
        Serial.println("1");
        break;
      case 1033561079: //2
        Serial.println("2");
        break;
      case 1635910171: //3
        Serial.println("3");
        break;
      case 2351064443: //4
        Serial.println("4");
        break;
      case 1217346747: //5
        Serial.println("5");
        break;
      case 71952287: //6
        Serial.println("6");
        break;
      case 851901943: //7
        Serial.println("7");
        break;
      case 465573243: //8
        Serial.println("8");
        break;
      case 1053031451: //9
        Serial.println("9");
        break;
      case 1386468383:
        Serial.println("ArrLeft");
        break;
      case 3622325019:
        Serial.println("ArrRight");
        break;
      case 4034314555:
        Serial.println("VolDown");
        break;
      case 2747854299:
        Serial.println("VolUp");
        break;
      case 3810010651:
        Serial.println("ChDown");
        break;
      case 5316027:
        Serial.println("Ch");
        break;
      case 16769565:
        Serial.println("ChUp");
        break;
      case 553536955:
        Serial.println("Play");
        break;
      case 3855596927:
        Serial.println("EQ");
        break;
    }
//    if (results.value == 3238126971) {
//      Serial.println("Click!");
//    }
    irrecv.resume(); // Receive the next value 
  }
  
   delay(250); //delay 250ms
  // if any key long pressed
}
