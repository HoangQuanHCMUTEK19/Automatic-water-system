
//Cac chan cua cam bien
#define sensor0 A0
#define sensorpower 7
#define sensor1 A1

//Cac chan cua co cau chap hanh
#define relay 8
#define led 13

//Cac gia tri nguong do am
#define Kho 750
#define Uot 500

//.................................................
void setup() {
  Serial.begin(9600);
  pinMode(sensor0, INPUT);
  pinMode(sensor1, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(led, OUTPUT);
}
//.................................................
void loop() {
  //Doc gia tri cam bien do am
  int doam = ReadYL69();
  //Doc gia tri cam bien nhiet do
  int value1 = analogRead(sensor1);
  //Chuyen doi thanh gia tri nhietdo
  float Vnhiet = value1*5.0/1024;
  float nhiet = Vnhiet*100;
  //Dieu kien thuc thi
  if (doam >= Kho) 
  {
    if(nhiet > 25 && nhiet < 35 ){
     Serial.println("Dat kho - nhiet do vua: Co the tuoi cay");
     digitalWrite(led, HIGH);
     digitalWrite(relay, HIGH);
    }
    else
    {
      Serial.println("Dat kho - nhiet do khong phu hop: Khong the tuoi cay");
      digitalWrite(led, HIGH);
      digitalWrite(relay, LOW);
    }
  }
  else if (doam < Kho && doam > Uot)
    {
        Serial.println("Dat co do am thich hop");
        digitalWrite(led, LOW);
        digitalWrite(relay, LOW);
    }
  else 
   { 
      Serial.println("Dat uot");
      digitalWrite(led, LOW);
      digitalWrite(relay, LOW);
   }
  }  
}
int ReadYL69()
{
  digitalWrite(sensorpower, HIGH);
  delay(10);
  int val = analogRead(sensor0);
  digitalWrite(sensorpower,LOW);
  return val;
}
