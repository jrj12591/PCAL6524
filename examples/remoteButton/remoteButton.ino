#include <Wire.h>
#include "PCAL6254.h"


/* This code is desinged to mimic the Button schetch found in the basic arduino library sample code 
 * but with using the IO on the PCAL6254 insted of the built in IO
 * 
 * Please place a LED between the deisred pin and ground.
 * 
 * In this schetch the Input Pin is Set to P0_1 and the Output Pin is set to P0_0
 */



PCAL6524 io;  //Address Pin is tied to ground (DEFAULT)
//PCAL6524(PCAL6524_ADDRESS_0) io; //Adress Pin is Tied to SCL
//PCAL6524(PCAL6524_ADDRESS_1) io; //Adress Pin is Tied to SDA
//PCAL6524(PCAL6524_ADDRESS_3) io; //Adress Pin is Tied to VDD

/* PCAL6524 24 IO pins are brocken into 3 Banks, Pin IDs coresponed to Pin IDs from NXP data sheets
 *    Bank 0       Bank 1     Bank 2
 *    P0_0         P1_1       P2_1
 *    P0_1         P1_1       P2_1
 *    P0_2         P1_2       P2_2
 *    P0_3         P1_3       P2_3
 *    P0_4         P1_4       P2_4    
 *    P0_5         P1_5       P2_5
 *    P0_6         P1_6       P2_6
 *    P0_7         P1_7       P2_7
 */
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton statu



void setup() {
  
  //Join the MCU to the I2C buss as its master and resest the PCAL6524 to default;
  io.begin();
  //Initialize the desired Pin to desired mode (Input, or Output)
  io.remotepinMode(P0_0, OUTPUT); //Seting Pin P0_0 to an Output;
  io.remotepinMode(P0_1, INPUT);  //Sets Pin P0_1 to be an Input;

}
void loop() {
  // read the state of the pushbutton value:
  buttonState = io.remotedigitalRead(P0_1);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH)
  {
    //turn LED ON
    io.remotedigitalWrite(P0_0, HIGH);
  }
  else{  
  //turn off ON
  io.remotedigitalWrite(P0_0, LOW);
  }
}
