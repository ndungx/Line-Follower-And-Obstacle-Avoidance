#define echopin A4 // echo pin
#define trigpin A5 // Trigger pin


int motor_r2 = 9; //motor right 2
int motor_r1 = 10; //motor right 1

int motor_l2 = 5; //motor left 2
int motor_l1 = 6; //motor left 1


int speed = 200;

int  frontdist;
long duration;

int setdist= 15;

int L_S = A0; //left sensor
int R_S = A1; //right sensor


void setup(){
 
 pinMode(motor_l1, OUTPUT);
 pinMode(motor_l2, OUTPUT);
 
 pinMode(motor_r1, OUTPUT);
 pinMode(motor_r2, OUTPUT);

 pinMode (trigpin, OUTPUT);
 pinMode (echopin, INPUT);
 
 pinMode(L_S, INPUT);
 pinMode(R_S, INPUT);

 Serial.begin(9600);
 delay(1000);
 }

void loop(){
frontdist = data();
Serial.println(frontdist); 


if(frontdist>setdist){
if ((digitalRead(L_S) == 1)&&(digitalRead(R_S) == 1)){forward();}
if ((digitalRead(L_S) == 1)&&(digitalRead(R_S) == 0)){turnRight();}
if ((digitalRead(L_S) == 0)&&(digitalRead(R_S) == 1)){turnLeft();}
if ((digitalRead(L_S) == 0)&&(digitalRead(R_S) == 0)){stop();}

}else{
turnLeft();
delay(300);
forword();
delay(800);
turnRight();  
delay(300);
forward();
delay(800);
turnRight();
delay(300);
}

}

long data(){
 digitalWrite(trigpin,LOW);
 delayMicroseconds(2);
 digitalWrite(trigpin,HIGH);
 delayMicroseconds(10);
 duration=pulseIn (echopin,HIGH);
 return duration / 29 / 2; 
}

void stop(){
 analogWrite(motor_l1, 0);
 analogWrite(motor_l2, 0);
 analogWrite(motor_r1, 0);
 analogWrite(motor_r2, 0);  
}

void forward(){
 analogWrite(motor_l1, speed);
 analogWrite(motor_l2, 0);
 analogWrite(motor_r1, 0);
 analogWrite(motor_r2, speed);  
}

void backward(){
 analogWrite(motor_l1, 0);
 analogWrite(motor_l2, speed);
 analogWrite(motor_r1, speed);
 analogWrite(motor_r2, 0);   
}


void turnRight(){
analogWrite(motor_l1, 0);
analogWrite(motor_l2, speed);
analogWrite(motor_r1, 0);
analogWrite(motor_r2, speed);  
}

void turnLeft(){
analogWrite(motor_l1, speed);
analogWrite(motor_l2, 0);
analogWrite(motor_r1, speed);
analogWrite(motor_r2, 0);   
}
