// C++ code
//
#include <Arduino.h>
#include "Talkie.h"
#include "Vocab_US_Large.h"
#include "Vocab_Special.h"
#include "Vocab_US_TI99.h"
#include "Vocab_US_Clock.h"
int red_light_pin= 13;
int green_light_pin = 12;
int blue_light_pin = 11;
int value;
int ldr= A2;
int val;
int tempPin = A0;
int i;
int buzzer=3;
Talkie voice;
void setup()
{
 #if defined(__AVR_ATmega32U4__) || defined(SERIAL_USB) ||
defined(SERIAL_PORT_USBVIRTUAL) || defined(ARDUINO_attiny3217)
 delay(4000); // To be able to connect Serial monitor after reset or power up and before
first print out. Do not wait for an attached Serial Monitor!
#endif
 // Just to know which program is running on my Arduino
 Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version "
VERSION_TALKIE));
// voice.doNotUseUseInvertedOutput();
#if defined(TEENSYDUINO)
 pinMode(3, OUTPUT);
 digitalWrite(3, HIGH); //Enable Amplified PROP shield
 #endif
 Serial.begin(9600);
 pinMode(red_light_pin, OUTPUT);
 pinMode(green_light_pin, OUTPUT);
 pinMode(blue_light_pin, OUTPUT);
 pinMode(buzzer, OUTPUT); 
}
void loop()
{
value=analogRead(ldr);//Reads the Value of LDR(light).
 Serial.print("Light = ");
 Serial.print(value);
 delay(1000);
val = analogRead(tempPin);
 float mv = ( val/1024.0)*5000;
 float cel = mv/10;
 Serial.print("TEMP = ");
 Serial.print(cel);
 delay(1000);
 if(cel<76 && (value>600))
 {
 RGB_color(0, 255, 255); // Cyan

 voice.say(spt_M);
 voice.say(spt_I);
 voice.say(spt_D);
 voice.say(spt_N);
 voice.say(spt_I);
 voice.say(spt_G);
 voice.say(spt_H);
 voice.say(spt_T);
 Serial.print(" Midnight");
 }
 else if((cel>75 && cel<124) && (value<401 && value>250))
 {
 RGB_color(255,255,0); // Yellow

 tone(buzzer, 3000); // Send 3KHz sound signal...
 delay(1000); // ...for 1 sec
 noTone(buzzer); // Stop sound...
 delay(1000); // ...for 1sec
 voice.say(spc_GOOD);
 voice.say(spc_AFTERNOON);
 Serial.print(" Afternoon ");
 }
 else if((cel>75 && cel<124) || (value<601 && value>400))
 {
 RGB_color(255,255,0); // Yellow

 tone(buzzer, 3000); // Send 3KHz sound signal...
 delay(1000); // ...for 1 sec
 noTone(buzzer); // Stop sound...
 delay(1000); // ...for 1sec
 voice.say(spc_GOOD);
 voice.say(spt_N);
 voice.say(spt_I);
 voice.say(spt_G);
 voice.say(spt_H);
 voice.say(spt_T);
 Serial.print(" Night ");
 }
 else if(cel>125 && value<76)
 {
 RGB_color(255,0,0); // Red
 tone(buzzer, 5000); // Send 5KHz sound signal...
 delay(1000); // ...for 1 sec
 noTone(buzzer); // Stop sound...
 delay(1000); // ...for 1sec
 voice.say(spc_GOOD);
 voice.say(spc_MORNING);
 Serial.print(" Morning ");
 }
 else if(cel>125 && (value<251 && value>75))
 {
 RGB_color(255,0,0); // Red
 tone(buzzer, 5000); // Send 5KHz sound signal...
 delay(1000); // ...for 1 sec
 noTone(buzzer); // Stop sound...
 delay(1000); // ...for 1sec
 voice.say(spc_GOOD);
 voice.say(spc_EVENING);
 Serial.print(" Evening ");
 }
}
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
{
 analogWrite(red_light_pin, red_light_value);
 analogWrite(green_light_pin, green_light_value);
 analogWrite(blue_light_pin, blue_light_value);
}
2. Explanation o
