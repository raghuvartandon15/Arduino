#define do 264 
#define re 297 
#define mi 330
#define fa 352
#define so 396
#define la 440
#define si 495
#define do1 528

const int C = 10;
const int D = 9;
const int E = 8;
const int F = 7;
const int G = 6;
const int A = 5;
const int B = 4;
const int C1 = 3;



const int Buzz = 11;
const int LED = 13;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(C, INPUT);
  digitalWrite(C,HIGH);
  
  pinMode(D, INPUT);
  digitalWrite(D,HIGH);
  
  pinMode(E, INPUT);
  digitalWrite(E,HIGH);
  
  pinMode(F, INPUT);
  digitalWrite(F,HIGH);
  
  pinMode(G, INPUT);
  digitalWrite(G,HIGH);
  
  pinMode(A, INPUT);
  digitalWrite(A,HIGH);
  
  pinMode(B, INPUT);
  digitalWrite(B,HIGH);

 pinMode(C1, INPUT);
  digitalWrite(C1,HIGH);

   digitalWrite(LED,LOW);
}

void loop()
{
  while(digitalRead(C) == LOW)
  {
    tone(Buzz,do);
    digitalWrite(LED,HIGH);
  }

  while(digitalRead(D) == LOW)
  {
    tone(Buzz,re);
    digitalWrite(LED,HIGH);
  }

  while(digitalRead(E) == LOW)
  {
    tone(Buzz,mi);
    digitalWrite(LED,HIGH);
  }

  while(digitalRead(F) == LOW)
  {
    tone(Buzz,fa);
    digitalWrite(LED,HIGH);
  }

  while(digitalRead(G) == LOW)
  {
    tone(Buzz,so);
    digitalWrite(LED,HIGH);
  }

  while(digitalRead(A) == LOW)
  {
    tone(Buzz,la);
    digitalWrite(LED,HIGH);
  }

  while(digitalRead(B) == LOW)
  {
    tone(Buzz,si);
    digitalWrite(LED,HIGH);
  }

 while(digitalRead(C1) == LOW)
  {
    tone(Buzz,do1);
    digitalWrite(LED,HIGH);
  }
  

  noTone(Buzz);
  digitalWrite(LED,LOW);

}
