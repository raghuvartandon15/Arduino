// hobbyprojects
// 16-05-2019   PropellerClockRpmBatteryStatusDisplay

unsigned int x,j,n,k,d,ADCvalue,nm,dl;
unsigned long previousTime,rpm,tc,to = 0;
long v;
byte hours = 12;     // set Hours
byte minutes = 15;   // set minutes
byte seconds = 00;  // set seconds
int i,m,f,f1,val = 0;
byte a,c;
char s;
const PROGMEM  unsigned char data[]={0x3f,0x23,0x23,0x3f,0x01,0x13,0x3f,0x03,0x2f,0x2b,0x2b,0x3b,0x2b,0x2b,0x2b,0x3f,0x39,0x09,0x09,0x3f,0x3b,0x2b,0x2b,0x2f,0x3f,0x2b,0x2b,0x2f,0x21,0x27,0x29,0x31,0x3f,0x2b,0x2b,0x3f,0x3b,0x2b,0x2b,0x3f,0x00,0x00,0x15,0x00,0x01,0x01,0x3f,0x29,0x2d,0x13,0x01,0x3f,0x29,0x29,0x11,0x01,0x3f,0x11,0x09,0x11,0x3f,0x39,0x05,0x03,0x05,0x39,0x1F,0x11,0x11,0x00,0x1F,0x01,0x01,0x01,0x1f,0x11,0x11,0x1F,0x1F,0x11,0x11,0x00,0x1F,0x04,0x0A,0x11};
void setup()
{
  DDRD = 0xF8;
  DDRB = 0xFF;
  DDRC = 0xFE;
  PORTC = 0x01;  
  PORTD = 0x07;
  PORTB = 0x00;  
  if(hours == 12)
  hours = 0;
  attachInterrupt(0, usdl, RISING);       
}
void loop() 
{
while(m == 0)
{
  while(bit_is_clear(PIND, 2))
{
} 
  k=45;
  n=0;
  while(n < 60)
  {      
  ADCvalue = analogRead(A7);
  if(ADCvalue < 500)
  {
  minutes = k;
  seconds = 0;
  }

  ADCvalue = analogRead(A6);
  if(ADCvalue < 500)
  {
  hours = k/5;
  seconds = 0;
  }
  PORTC |= (1<<5); 
  if ((k==0) || (k==5) || (k==10) || (k==15) || (k==20) || (k==25) || (k==30) || (k==35) || (k==40) || (k==45) || (k==50) || (k==55))
  {
  PORTC |= (1<<4);
  PORTC |= (1<<3);  
  }
  if ((k==0) || (k==15) || (k==30) || (k==45))
  {
  PORTC |= (1<<2);
  PORTC |= (1<<1);     
  }
  if(k == hours*5 - 1)
  PORTD |= (1<<7); 
  if((k == hours*5) || (( k == 0 ) && (hours == 0)))
  {
  PORTB |= (1<<5);     
  PORTD |= (1<<3); 
  PORTD |= (1<<4); 
  PORTD |= (1<<5); 
  PORTD |= (1<<6); 
  PORTD |= (1<<7); 
  PORTB |= (1<<0); 
  }
  if(k == hours*5 + 1)
  PORTD |= (1<<7); 
  if((k == 59) && (hours*5 == 0))
  PORTD |= (1<<7);  
  if(k == minutes-1)
  PORTB |= (1<<1);
  if(k == minutes)
  {
  PORTB |= (1<<5);     
  PORTD |= (1<<3); 
  PORTD |= (1<<4); 
  PORTD |= (1<<5); 
  PORTD |= (1<<6); 
  PORTD |= (1<<7); 
  PORTB |= (1<<0); 
  PORTB |= (1<<1);
  PORTB |= (1<<2);     
  }
  if(k == minutes+1)
  PORTB |= (1<<1);
  if((k == 0) && (minutes == 59))
  PORTB |= (1<<1);
  if((k == 59) && (minutes == 0))
  PORTB |= (1<<1);
  if(k == seconds-1)
  PORTB |= (1<<3);  
  if(k == seconds)
  {
  PORTB |= (1<<5);    
  PORTD |= (1<<3); 
  PORTD |= (1<<4); 
  PORTD |= (1<<5); 
  PORTD |= (1<<6); 
  PORTD |= (1<<7); 
  PORTB |= (1<<0); 
  PORTB |= (1<<1);
  PORTB |= (1<<2); 
  PORTB |= (1<<3);
  PORTB |= (1<<4);
  
  }
  if(k == seconds+1)
  PORTB |= (1<<3);
  if((k == 0) && (seconds == 59))
  PORTB |= (1<<3);
  if((k == 59) && (seconds == 0))
  PORTB |= (1<<3);      
  delayMicroseconds(dl);
  PORTD = 0x07;
  PORTB = 0x00;
  PORTC = 0x01; 
  PORTB |= (1<<5); 
  delayMicroseconds(dl/50);
  PORTB &= ~(1<<5);     
  delayMicroseconds(dl*4);
  n++;
  k++;
  if(k == 60)
  k=0;
  }
  while(bit_is_set(PIND, 2))
  { 
  }     
}
while(m == 1)
  {
  while(bit_is_clear(PIND, 2))
 {
 }
  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  delay(2);
  ADCSRA |= _BV(ADSC);
  while (bit_is_set(ADCSRA,ADSC));
  v = ADCL;
  v |= ADCH<<8;
  v = 1125300L / v;
  nm = v/1000;
  nm = nm%10;
  nD();
  delayMicroseconds(dl*4);
  PORTC = 0x03;
  delayMicroseconds(dl);  
  PORTC = 0x01; 
  delayMicroseconds(dl*6);
  nm = v/100;
  nm = nm%10;
  nD();
  delayMicroseconds(dl*2);  
  nm = v/10;
  nm = nm%10;
  nD();
  delayMicroseconds(dl*2);   
  i = 0;
  while(i < 5)
 { 
  PORTC = (pgm_read_byte(&(data+61)[i]));
  delayMicroseconds(dl);  
  PORTC = 0x01; 
  delayMicroseconds(dl*2);
  i++; 
 }
  i = 0;
  while(i < 10)
 { 
  delayMicroseconds(dl);  
  i++; 
 }              
  rpm = (100000000/tc)*60; 
  nm = rpm/100000;
  nm = nm%10;
  if(nm !=0)
  nD();
  delayMicroseconds(dl*2);
  nm = rpm/10000;
  nm = nm%10;
  nD();
  delayMicroseconds(dl*2);  
  nm = rpm/1000;
  nm = nm%10;
  nD();
  delayMicroseconds(dl*2);      
  nm = rpm/100;
  nm = nm%10;
  nD();    
  delayMicroseconds(dl*2); 
  i = 0;
  while(i < 17)
 { 
  PORTC = (pgm_read_byte(&(data+44)[i]));
  delayMicroseconds(dl);  
  PORTC = 0x01; 
  delayMicroseconds(dl*2);
  i++; 
 }  
  while(i < 50)
 { 
  delayMicroseconds(dl);  
  i++; 
 }     
  nm = seconds;
  nm = nm%10;
  nmDB();
  delayMicroseconds(dl*2);
  nm = seconds/10;
  nm = nm%10;
  x=4;
  nmDB2();
  delayMicroseconds(dl*2);
  nm = 10;
  x=3;
  nmDB2();
  delayMicroseconds(dl*2);  
  nm = minutes;
  nm = nm%10;
  x=2;
  nmDB2();
  delayMicroseconds(dl*2);
  nm = minutes/10;
  nm = nm%10;
  x=1;
  nmDB2();
  delayMicroseconds(dl*2);
  nm = 10;
  x=0;
  nmDB2();
  delayMicroseconds(dl*2);  
  nm = hours;
  if(nm == 0)
  nm = 12;
  nm = nm%10;
  nmDB();
  delayMicroseconds(dl*2);    
  nm = hours;
  if(nm == 0)
  nm = 12;
  nm=nm/10;  
  nm = nm%10;
  nmDB();    
  while(bit_is_set(PIND, 2))
  { 
  } 
}
}
void nD()
{
  j=nm*4;
  i = 0;
  while(i < 4)
 { 
  PORTC = (pgm_read_byte(&(data+j)[i]));
  delayMicroseconds(dl);  
  PORTC = 0x01; 
  delayMicroseconds(dl*2);
  i++; 
 } 
}
void nmDB2()
{
  j=nm*4;
  x = x*4;
  i = 3;
  while(i >= 0)
 { 
  c = (pgm_read_byte(&(data+j)[i]));
  s=0;
  for(a = 0; a < 8; a++){
    s <<= 1;
    s |= c & 1;
    c >>= 1;
  }
  s >>= 1;
  PORTC = s;
  c = (pgm_read_byte(&(data+66+x)[i]));  
  s=0;
  for(a = 0; a < 8; a++){
    s <<= 1;
    s |= c & 1;
    c >>= 1;
  }
  PORTB = s >>= 3;
  PORTB &= ~(1<<5);   
  delayMicroseconds(dl);  
  PORTC = 0x01; 
  PORTB = 0x00;
  PORTD = 0x04;    
  delayMicroseconds(dl*2);
  i--; 
 } 
}
void nmDB()
{
  j=nm*4;
  i = 3;
  while(i >= 0)
 { 
  c = (pgm_read_byte(&(data+j)[i]));
  s=0;
  for(a = 0; a < 8; a++){
    s <<= 1;
    s |= c & 1;
    c >>= 1;
  }
  s >>= 1;
  PORTC = s;
  delayMicroseconds(dl);  
  PORTC = 0x01; 
  delayMicroseconds(dl*2);
  i--; 
 } 
}
   void usdl()
{    
  f = 0;
  n = 0;
  tc = micros()-to;
  to = micros(); 
  f = 1;
  if(m == 0)
  dl = tc/410;
  else
  dl = tc/400;     
  if (millis() >= (previousTime)) 
  {
  previousTime = previousTime + 1000;
  seconds = seconds+1;
  if (seconds == 60)
  {
  seconds = 0;
  minutes = minutes+1;
  }
  if (minutes == 60)
  {
  minutes = 0;
  hours = hours+1;
  }
  if (hours == 12)
  {
  hours = 0;
  }   
 }
  if(bit_is_clear(PINC, 0))
  m = 1;
  else
  m = 0;
} 
