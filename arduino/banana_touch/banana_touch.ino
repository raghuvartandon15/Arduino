#include <CapacitiveSensor.h>
#define buzzer 11

// Set the Send Pin & Receive Pin.
CapacitiveSensor   cs_12_3 = CapacitiveSensor(12,3);       
CapacitiveSensor   cs_12_4 = CapacitiveSensor(12,4);        
CapacitiveSensor   cs_12_5 = CapacitiveSensor(12,5);    
CapacitiveSensor   cs_12_6 = CapacitiveSensor(12,6);    
CapacitiveSensor   cs_12_7 = CapacitiveSensor(12,7);     
CapacitiveSensor   cs_12_8 = CapacitiveSensor(12,8);        
CapacitiveSensor   cs_12_9 = CapacitiveSensor(12,9); 
CapacitiveSensor   cs_12_10 = CapacitiveSensor(12,10);    

void setup()                   
{
  // turn off autocalibrate on channel 1 - just as an example
  cs_12_3.set_CS_AutocaL_Millis(0xFFFFFFFF); 
  cs_12_4.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_12_5.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_12_6.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_12_7.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_12_8.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_12_9.set_CS_AutocaL_Millis(0xFFFFFFFF);    
  cs_12_10.set_CS_AutocaL_Millis(0xFFFFFFFF);
}

void loop()                   
{
  // Set the sensitivity of the sensors.
  long touch1 =  cs_12_3.capacitiveSensor(1000);
  long touch2 =  cs_12_4.capacitiveSensor(1000);
  long touch3 =  cs_12_5.capacitiveSensor(1000);
  long touch4 =  cs_12_6.capacitiveSensor(1000);
  long touch5 =  cs_12_7.capacitiveSensor(1000);
  long touch6 =  cs_12_8.capacitiveSensor(1000);
  long touch7 =  cs_12_9.capacitiveSensor(1000);
  long touch8 =  cs_12_10.capacitiveSensor(1000);
 
  // When we touched the sensor, the buzzer will produce a tone.
  if (touch1 > 1000){
    tone(buzzer,400);
    } 
  if (touch2 > 1000){
    tone(buzzer,270);
    } 
  if (touch3 > 1000){
    tone(buzzer,650);
  }
  if (touch4 > 1000) {
    tone(buzzer,900);
  }
  if (touch5 > 1000){
    tone(buzzer,1100);
  }
  if (touch6 > 1000){
    tone(buzzer,1300);
  }
  if (touch7 > 1000){
    tone(buzzer,1670);
  }
  if (touch8 > 1000){
    tone(buzzer,2000);
  }

  // When we didn't touch it, no tone is produced.
  if (touch1<=1000  &  touch2<=1000  &  touch3<=1000 & touch4<=1000  &  touch5<=1000  &  touch6<=1000 &  touch7<=1000 &  touch8<=1000)
    noTone(buzzer);
  delay(10); 
 }
