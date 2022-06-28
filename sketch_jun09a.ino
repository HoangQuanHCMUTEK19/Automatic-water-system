#define sensor0 A0
#define relay 8
#define led 13
#define sensor1 A1
#define TIMER_US 500000
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
  int doam = analogRead(sensor0);
  int value1 = analogRead(sensor1);
  float value2 = value1*5.0/1024.0;
  float nhiet = value2*100.0;
  doam = map(doam, 0, 1023, 0, 100);
  if (doam > 70  ) {

    digitalWrite(led, LOW);
    digitalWrite(relay, LOW);
  }
  else {
    if(nhiet > 25 && nhiet <35 ){
     digitalWrite(led, HIGH);
     digitalWrite(relay, HIGH);
     if(doam>70)
     {
      digitalWrite(led, LOW);
      digitalWrite(relay, LOW);

     }
      
     }
    
    else{
      digitalWrite(led, LOW);
      digitalWrite(relay, LOW);
     
    }
  }
      
}
