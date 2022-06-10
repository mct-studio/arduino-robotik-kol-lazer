#include <Servo.h>

Servo servo1;
Servo servo2;

int x = 0;
int y = 0;
int btn = 0;
int light = 0;

void setup() {
  Serial.begin(9600);

  pinMode(9, INPUT); // servo1
  pinMode(10, INPUT); // servo2
  pinMode(6, INPUT_PULLUP); // joystick button
  pinMode(7, OUTPUT); // laser
  pinMode(5, OUTPUT); // led

  pinMode(A5, INPUT_PULLUP); // servo1

  servo1.attach(9);
  servo2.attach(10);  
}

void loop() {
  x = analogRead(A1);
  y = analogRead(A2);

  btn = digitalRead(6);
  light = analogRead(A5);
  
  Serial.print("light :");
  Serial.println(light);
  
  if (light>7) {
    if (light<70) {  
      digitalWrite(5, HIGH);
    } else {
       digitalWrite(5, LOW);
    }
  }  
  
  /*
  Serial.print("btn:");
  Serial.print(btn);

  Serial.print(", x:");
  Serial.print(x);

  Serial.print(", y:");
  Serial.print(y);
  Serial.println("\n");  
*/
  digitalWrite(7, (btn == HIGH ? HIGH : LOW));
  
  servo1.write(map(x, 0, 1023, 0, 18)*10);
  servo2.write(map(y, 0, 1023, 0, 18)*10);
   
}
