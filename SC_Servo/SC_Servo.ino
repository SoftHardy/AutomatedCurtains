//////////////////////////////////////////////////////   SC_Curtain-pin4      ////////////////////////////////////////////
/////////////////////////////////////////////////////    Hanging Light-pin16 ////////////////////////////////////////////

#include<Servo.h>
#include <ESP8266WiFi.h>

String  i;
int code=0;
int rotate=86;
WiFiServer server(80);
Servo servo1;

void setup() {
  i = "";
  servo1.attach(4);
  pinMode(16,OUTPUT);
  Serial.begin(9600);
  WiFi.disconnect();
  delay(2000);
  Serial.println("Start Client");
   WiFi.begin("Pytron","pytron123");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(1000);
    Serial.println(">>");

  }
  Serial.println("Connected");
  Serial.println((WiFi.localIP()));
  Serial.println("Start the servo motor");
  server.begin();
  servo1.write(86);
}

void loop() {

  WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    i = (client.readStringUntil('\r'));
    i.remove(0, 5);
    i.remove(i.length()-9,9);
    code=i.toInt();
    Serial.println(code);
    switch(code){
      case 111:
      servo1.write(360);
      rotate=360;
      break;
      case 110:
      servo1.write(0);
      rotate=0;
      break;
      case 112:
      servo1.write(86);
      rotate=86;
      break;

      case 751:
      digitalWrite(16,HIGH);
      break;
      case 750:
      digitalWrite(16,LOW);
      break;

////////////////////////////////////---------------------------------------------------MOODS-------------------------------------------------------//////////////////////////////
/////////////////////////////////////////ALARMED MOOD/////////////////////////////////////////
      case 5011:
      if(rotate==0){
        servo1.write(86);
      }else{
        servo1.write(0);
        rotate=0;
      }
      digitalWrite(16,LOW);
      break;
      case 5010:
      if(rotate==0){
      servo1.write(86);
      }else{
        servo1.write(0);
        rotate=0;
      }
      digitalWrite(16,LOW);
      break;

/////////////////////////////////////////SUNSET MOOD/////////////////////////////////////////
      case 5021:
      if(rotate==0){
        servo1.write(86);
      }else{
        servo1.write(0);
        rotate=0;
      }
      digitalWrite(16,LOW);
      break;
      case 5020:
      if(rotate==0){
        servo1.write(86);
      }else{
        servo1.write(0);
        rotate=0;
      }
      digitalWrite(16,LOW);
      break;

/////////////////////////////////////////MOVIE MOOD/////////////////////////////////////////
      case 5031:
      if(rotate==0){
        servo1.write(0);
      }else{
        servo1.write(0);
        rotate=0;
      }
      digitalWrite(16,LOW);
      break;
      case 5030:
      if(rotate==0){
        servo1.write(86);
      }else{
      servo1.write(0);
      rotate=0;  
      }
      digitalWrite(16,HIGH);
      break;

/////////////////////////////////////////SLEEPING MOOD/////////////////////////////////////////
      case 5041:
      if(rotate==0){
        servo1.write(86);
      }else{
        servo1.write(0);
        rotate=0;
      }
      digitalWrite(16,LOW);
      break;
      case 5040:
      if(rotate==360){
        servo1.write(86);
      }
      else{
        servo1.write(360);
        rotate=360;
      }
      digitalWrite(16,HIGH);
      break;

/////////////////////////////////////////WAKEY WAKEY MOOD/////////////////////////////////////////
      case 5051:
      if(rotate==360){
        servo1.write(86);
      }else{
        servo1.write(360);
        rotate=360;
      }
      digitalWrite(16,LOW);
      break;
      case 5050:
      if(rotate==0){
        servo1.write(86);
      }else{
        servo1.write(0);
        rotate=0;
      }
      digitalWrite(16,LOW);
      break;

/////////////////////////////////////////DEFAULT MOOD/////////////////////////////////////////
      case 5000:
      if(rotate==0){
        servo1.write(86);
      }else{
        servo1.write(0);
        rotate=0;
      }digitalWrite(16,HIGH);
      break;

    }      
}
