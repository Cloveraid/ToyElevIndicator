#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

 int RelayPin = 5; //릴레이 핀 설정

 int A  = 37;
 int B  = 39;
 int C  = 41;
 int D  = 43;
 int E  = 45;
 int F  = 47;
 int G  = 49;

 int LEDPINR = 51;
 int LEDPING = 53;
 int LEDPINB = 52;

int distance = 0; //Cm로 계산된 거리값을 저장해두기위해 변수를 선언합니다.

void setup() 
{

 lcd.init();
 lcd.backlight();

 Serial.begin(9600); // 시리얼통신 시작
 Serial.println("Serial begin"); 
 lcd.clear(); 
 lcd.setCursor(0,0); 
 lcd.print("Serial begin..");
  
 pinMode(RelayPin, OUTPUT);
 Serial.println("Pinmode setup"); 
 delay(1000);
    lcd.clear(); 
 pinMode(LEDPINR,OUTPUT);
 pinMode(LEDPING,OUTPUT);
 pinMode(LEDPINB,OUTPUT);

 pinMode(A, OUTPUT);
 pinMode(B, OUTPUT);
 pinMode(C, OUTPUT);
 pinMode(D, OUTPUT);
 pinMode(E, OUTPUT);
 pinMode(F, OUTPUT);
 pinMode(G, OUTPUT);

 for(int i=39;i<=53;i++){
  pinMode(i,OUTPUT);
  digitalWrite(i,LOW);
  }
 delay(2000);

}


void loop() 
{

  int volt = map(analogRead(A1), 0, 1023, 0, 5000); /*
                                                      거리값을 cm로 변환해주기 쉽게 하기위해서
                                                      map 함수를 사용해서 데이터값을 변환 해줍니다.
                                                      */ 

  distance = (27.61 / (volt - 0.1696)) * 1000; /*
                                               거리값을 cm로 변환하는 계산공식 입니다.
                                               변환된 cm값을 distance 변수에 저장합니다.
                                               */

  Serial.println(distance);  //거리값을 시리얼모니터로 출력해줍니다.
  delay(500);
 
if(distance < 10)

{ 
  // Let's turn on the relay...
 digitalWrite(RelayPin, LOW);
 digitalWrite(LEDPING,LOW);
 digitalWrite(LEDPINR,LOW);
 digitalWrite(LEDPINB,LOW);
 digitalWrite(LEDPINR,HIGH);
 //Serial.println("Door opened!");
 digitalWrite (A,HIGH);
 digitalWrite (B,LOW);
 digitalWrite (C,HIGH);
 digitalWrite (D,HIGH);
 digitalWrite (E,HIGH);
 digitalWrite (F,LOW);
 digitalWrite (G,HIGH);
 lcd.clear(); 
 lcd.setCursor(0,0);        
 lcd.print("I==I");        
 lcd.setCursor(0,1);          
 lcd.print("I==I");    



} 

else
{
  // Let's turn off the relay...
   

  digitalWrite(RelayPin, HIGH);
  digitalWrite(LEDPING,LOW);
  digitalWrite(LEDPINR,LOW);
  digitalWrite(LEDPINB,LOW);
  digitalWrite(LEDPING,HIGH);
  digitalWrite (A,LOW);
  digitalWrite (B,LOW);
  digitalWrite (C,LOW);
  digitalWrite (D,HIGH);
  digitalWrite (E,LOW);
  digitalWrite (F,LOW);
  digitalWrite (G,HIGH);
  
  lcd.clear(); 
  lcd.setCursor(12,0);          
  lcd.print("I==I");      
  lcd.setCursor(12,1);          
  lcd.print("I==I");     

//Serial.println("Door Closed!");
 }
}

/*

Reference)

https://blog.naver.com/dokkosam/221173069413
https://www.engineersgarage.com/seven-segment-display-with-arduino/
https://popcorn16.tistory.com/163
https://m.blog.naver.com/eduino/221066151223
https://codeda.tistory.com/30
https://edu.goorm.io/learn/lecture/203/%ED%95%9C-%EB%88%88%EC%97%90-%EB%81%9D%EB%82%B4%EB%8A%94-%EC%95%84%EB%91%90%EC%9D%B4%EB%85%B8-%EA%B8%B0%EC%B4%88/lesson/12407/7-segment-%EC%86%8C%EA%B0%9C
https://codingrun.com/106
https://fishpoint.tistory.com/7077
https://whitewing4139.tistory.com/67
https://carrotweb.tistory.com/137

*/
