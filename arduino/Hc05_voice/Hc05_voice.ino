int Green = 3;
int Orange = 4;
int Red = 5;

void setup() {
  Serial.begin(9600);
  pinMode(Green,OUTPUT);
  pinMode(Orange,OUTPUT);
  pinMode(Red,OUTPUT);
  

}


char c;
String voice;

void loop() {
  if (Serial.available()>0)
  {
    voice="";
    voice=Serial.readString();
    Serial.print(voice+'\n');
  }

  if(voice=="green")
  {
    digitalWrite(Green,HIGH);
  } else if(voice=="green off")
  {
    digitalWrite(Green,LOW);
  }

    if(voice=="orange")
  {
    digitalWrite(Orange,HIGH);
  } else if(voice=="Orange off")
  {
    digitalWrite(Orange,LOW);
  }

  
  if(voice=="turn on")
  {
    digitalWrite(Red,HIGH);
  } else if(voice=="turn off")
  {
    digitalWrite(Red,LOW);
  }

}
