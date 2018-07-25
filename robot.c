#include <Servo.h>

Servo servoLeft;
Servo servoRight;

int PIEZOPIN = 2;
int LedPIN = 3;


void setup()
{
    tone(4, 3000, 1000);                       // Play tone for 1 second
  delay(1000);                               // Delay to finish tone
  pinMode(7, INPUT);                         // Set right whisker pin to input
  pinMode(4, INPUT);                         // Set left whisker pin to input  

  Serial.begin(9600);      


  servoLeft.attach(13);
  servoRight.attach(12);
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);


}

  void clockwise()
  {
    servoLeft.writeMicroseconds(1200);
    servoRight.writeMicroseconds(1200);
    delay (1000);
     Sensor();
  }
  void right()
  {
    servoLeft.writeMicroseconds(1200);
    servoRight.writeMicroseconds(1700);
    delay (1000);
     Sensor();
  }
  void counter_clockwise()
  {
    servoLeft.writeMicroseconds(1300);
    servoRight.writeMicroseconds(1200);
    delay (1000);
     Sensor();
  }
  void forward ()
  {
    servoLeft.writeMicroseconds(1300);
    servoRight.writeMicroseconds(1700);
    delay (1000);
    right ();
    Sensor ();
   
  }
  void backward()
  {
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1300);
    delay (1000);
    Sensor();
  }
  void H()
  {
     digitalWrite (3, HIGH);
    delay (2000);
    digitalWrite (3, LOW);
    delay (1000);
    digitalWrite (3, HIGH);
    delay (2000);
    digitalWrite (3, LOW);
    delay (1000);
    digitalWrite (3, HIGH);
    delay (2000);
    digitalWrite (3, LOW);
    delay (1000);
    digitalWrite (3, HIGH);
    delay (2000);
    digitalWrite (3, LOW);
    delay (1000);
  }
  void E()
  {
    digitalWrite (3,HIGH);
    delay (2000);
    digitalWrite (3, LOW);
    delay (1000);
  }
  void L()
  {
     digitalWrite (3, HIGH);
    delay (2000);
    digitalWrite (3, LOW);
    delay (1000);
    digitalWrite (3, HIGH);
    delay (3000);
    digitalWrite (3, LOW);
    delay (1000);
    digitalWrite (3, HIGH);
    delay (2000);
    digitalWrite (3, LOW);
    delay (1000);
    digitalWrite (3, HIGH);
    delay (2000);
    digitalWrite (3, LOW);
    delay (1000);
  }
  void P()
  {
    digitalWrite (3, HIGH);
    delay (2000);
    digitalWrite (3, LOW);
    delay (1000);
    digitalWrite (3, HIGH);
    delay (3000);
    digitalWrite (3, LOW);
    delay (1000);
    digitalWrite (3, HIGH);
    delay (3000);
    digitalWrite (3, LOW);
    delay (1000);
     digitalWrite (3, HIGH);
    delay (2000);
    digitalWrite (3, LOW);
    delay (1000);
  }
void Speaker ()
{
  EMT();
  delay (1000);
  H();
  delay (1000);
  EMT();
  delay (1000);
  E();
  delay (1000);
  EMT();
  delay (1000);
  L();
  delay (1000);
  EMT();
  delay (1000);
  P();
  delay (1000);
}
void EMT()
{ 
  
  for(int hz = 440; hz < 1000; hz++){
    tone(2, hz, 50);
    delay(5);
  }
  noTone(2);

  // Whoop down
  for(int hz = 1000; hz > 440; hz--){
    tone(2, hz, 50);
    delay(5);
  }
 noTone(2);
 for(int hz = 440; hz < 1000; hz++){
    tone(2, hz, 50);
    delay(5);
  }
  noTone(2);

//  Whoop down
  for(int hz = 1000; hz > 440; hz--){
    tone(2, hz, 50);
    delay(5);
  }
 noTone(2);
 for(int hz = 440; hz < 1000; hz++){
    tone(2, hz, 50);
    delay(5);
  }
  noTone(2);

  // Whoop down
  for(int hz = 1000; hz > 440; hz--){
    tone(2, hz, 50);
    delay(5);
  }
  noTone(2);
}

void Help()
{
  H();
 delay (1000);
 E();
 delay (1000);
 L();
 delay (2000);
 P();
 delay (1000);
}
void Sensor()
{
   byte wLeft = digitalRead(4);               // Copy left result to wLeft  
  byte wRight = digitalRead(7);              // Copy right result to wRight

                    
  if(wLeft==0 && wRight ==0){
    Serial.print(wLeft);                       // Display left whisker state
  Serial.println(wRight);// Display right whisker state
    Speaker();
  delay(50);  
  }
}
void loop()
{
  forward();
  
}
