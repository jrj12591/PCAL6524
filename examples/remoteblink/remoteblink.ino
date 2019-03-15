#include <Wire.h>
#include "PCAL6254.h"


/* This code is desinged to mimic the blink schetch found in the basic arduino library sample code 
 * but with using the IO on the PCAL6254 insted of the built in IO
 * 
 * Please place a LED between the deisred pin and ground.
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



// the setup function runs once when you press reset or power the board
void setup() {
  
  //Join the MCU to the I2C buss as its master and resest the PCAL6524 to default;
  io.begin();
  //Initialize the desired Pin to desired mode (Input, or Output)
  io.remotepinMode(P0_0, OUTPUT); //Seting Pin P0_0 to an Output);

}
// the loop function runs over and over again forever
void loop() {
  //Turn on the requested pin
  io.remotedigitalWrite(P0_0, HIGH); //(HIGH is the voltage level)
  delay(1000);// wait for a second
  //Turn off the requested pin
  io.remotedigitalWrite(P0_0, LOW);
  delay(1000);// wait for a second
  
}
