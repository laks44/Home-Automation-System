int light=2;
int motor1=3;
int motor2=8;
int motore=9;
int ldr=A2;
int tmp=A0;
int data=0;
int data1=0;
int p=0;
int p1=0;
int sensorValue=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(motore,OUTPUT);
  pinMode(light,OUTPUT);
  pinMode(ldr,INPUT);
  pinMode(tmp,INPUT);
  digitalWrite(motor1,LOW);
  digitalWrite(motor2,LOW);
  analogWrite(motore,255);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>0){
    data=Serial.read();
    p=0;
    if(data==1){
      digitalWrite(light,HIGH);
    }
    else if(data==2){
      digitalWrite(light,LOW);
    }
    else if(data==3){
      p=10;
    }
    while(p==10){
      delay(200);
      int pwm=Serial.read();
      analogWrite(motor1,pwm);
      digitalWrite(motor2,LOW);
      analogWrite(motore,pwm);
      data=Serial.read();
      if(data==4){
        p=0;
        digitalWrite(motor1,LOW);
        digitalWrite(motor2,LOW);
        digitalWrite(motore,LOW);
        data=0;
      }
    }
    if(data==5){
      p1=11;
    }
    while(p1==11){
      delay(500);
      data1=analogRead(ldr);
      if(data1>35){
        digitalWrite(light,HIGH);
      }
      else{
        digitalWrite(light,LOW);
      }
      data=Serial.read();
      if(data==2){
        digitalWrite(light,LOW);
        p1=0;
        
      }
    }
    if(data==6){
      sensorValue = analogRead(tmp);
      sensorValue=(sensorValue)/100;
      Serial.println(sensorValue);
    }
  }

}
