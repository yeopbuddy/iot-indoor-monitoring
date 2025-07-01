#include <DHT.h>
#define D0 2 // PIR센서
#define D1 15 // LED
#define D2 26 // 온습도센서
#define D3 32 // 가스센서
DHT dht(D2, DHT11);
int motion = 0; // motion 감지를 위한 변수 선언

void setup() { //PIR 센서 입력 및 LED 출력 PIN 동작 모드 설정 
  dht.begin();
  delay(2000);
  Serial.begin(115200); 
  pinMode(D0, INPUT); // PIR센서 입력설정 
  pinMode(D1, OUTPUT); // LED 출력설정
  //pinMode(D2, OUTPUT); // 온습도센서 입력설정
  pinMode(D3, INPUT); // 가스센서 입력설정
} 

void loop() { //PIR 센서 입력에 따른 LED ON/OFF 제어 
  
  int motionState = digitalRead(D0); // D0핀 입력상태 저장 
  //int val = analogRead(D2);
  float tempC = dht.readTemperature();
  float humi = dht.readHumidity();
  //Serial.println(digitalRead(D0)); 
  if(motionState ==HIGH){ // PIR 센서 입력값이 HIGH이면 LED ON, 아니면 LED OFF 
    ++motion;
    if(motion == 1){
      digitalWrite(D1,HIGH);
      delay(10000);
    }
    else{
      digitalWrite(D1,LOW);
      motion = 0;
      delay(10000);
    }
  }
  else{
    delay(1000);
  } 
  //Serial.println("##############");
  //Serial.print("temp : ");
  Serial.print(tempC);
  Serial.print(",");
  //Serial.print("humidity : ");
  Serial.print(humi);
  Serial.print(",");
  //Serial.print("gas nongdo : ");
  Serial.print(analogRead(D3));
  Serial.print(",");
  //Serial.print("motion state is ");
  Serial.print(motion);
  //Serial.println("##############");
  Serial.println();
}