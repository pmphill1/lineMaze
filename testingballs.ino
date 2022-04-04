//www.elegoo.com

//Line Tracking IO define
#define LT_R !digitalRead(10)
#define LT_M !digitalRead(4)
#define LT_L !digitalRead(2)


#define ENB 5
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
#define ENA 6

#define carSpeed 200
#define carSpeedTurn 200
void forward(){
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("go forward!");
}

void back(){
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("go back!");
}

void left(){
  analogWrite(ENA, carSpeedTurn);
  analogWrite(ENB, carSpeedTurn);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("go left!");
}

void right(){
  analogWrite(ENA, carSpeedTurn);
  analogWrite(ENB, carSpeedTurn);
  digitalWrite(IN1, HIGH);//left side forward
  digitalWrite(IN2, LOW);//left side backwards
  digitalWrite(IN3, HIGH);//right side backwards
  digitalWrite(IN4, LOW);//right side forwards
  Serial.println("go right!");
} 


void stop(){
   digitalWrite(ENA, LOW);
   digitalWrite(ENB, LOW);
   Serial.println("Stop!");
} 

//chill function is stop but running code???

void chill(){
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("chill!");
}
//void backwards(){
//  analogWrite(ENA, carSpeed);
//  analogWrite(ENB, carSpeed);
//  digitalWrite(IN1, LOW);
//  digitalWrite(IN2, HIGH);
//  digitalWrite(IN3, HIGH);
//  digitalWrite(IN4, LOW); 
//  Serial.println("go backwards!");
//}

void detection(){


//Middle and right
  if(!LT_M && !LT_R && LT_L){
    chill();
    delay(100);
    right();
  }
//
//  //Middle and left
//  if(!LT_M && !LT_L && LT_R){
//    chill();
//    delay(100);
//    left();
////    double r = random(0,1);
////    if(r <0.5){
////      delay(100);
////      left();
////    }
////    else if(r >0.5){
////      delay(100);
////      forward();
////    }
//  }
//
//  
//  
//  //Just Middle
//  if(!LT_M && LT_L && LT_R){
//    forward();
//  }
//
//  //Only right
//  if(LT_M && LT_L && !LT_R){
//    right();
//  }
//  //Only sees Left
//  if(LT_M && LT_R && !LT_L){
//    left();
//  }
//
//
//
//  //T cross
//  if(!LT_M && !LT_L && !LT_R){
//    int y = (int)random(0,3);
//    if(y==0){
//      forward();
//    }
//    else if(y==1){
//      delay(100);
//      right();
//    }
//    else if(y==2){
//      delay(100);
//      left();
//    }
//  }
//
//
//  //Spin
//  if(LT_M && LT_L && LT_R){
//  double x=random(0,1);
//  if(x <0.5){
//    delay(100);
//    right();
// if(!LT_R || !LT_M || !LT_L){
//  stop();
//  delay(100);
//    forward();
//  }
//    
//  }
//  else if(x>0.5){
//    delay(100);
//    left();
//  if(!LT_L || !LT_M || !LT_R){
//  stop();
//  delay(100);
//    forward();
//  }
//  }
//  }
}

void setup(){
  Serial.begin(9600);
}

void loop() {

detection();
  

}
