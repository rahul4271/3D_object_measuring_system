#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

const int l_trigPin = 10;
const int l_echoPin = 11;

const int b_trigPin = 6;
const int b_echoPin = 3;

const int h_trigPin = 7;
const int h_echoPin = 4;

long l_duration;
int l_distance;

long b_duration;
int b_distance;

long h_duration;
int h_distance;

void setup()
{
  pinMode(l_trigPin, OUTPUT);
  pinMode(l_echoPin, INPUT);

  pinMode(b_trigPin, OUTPUT);
  pinMode(b_echoPin, INPUT);

  pinMode(h_trigPin, OUTPUT);
  pinMode(h_echoPin, INPUT);

  Serial.begin(9600);
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(1, 1);
  lcd.print("SYSTEM INITIALIZING");
  delay(2000);
  lcd.clear();
  lcd.setCursor(1, 1);
  lcd.print("PLEASE WAIT....");
  delay(3000);
  lcd.clear();
}
void loop()
{
  lcd.clear();
  //for first sensor
  digitalWrite(l_trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(l_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(l_trigPin, LOW);

  l_duration = pulseIn(l_echoPin, HIGH);
  int l_distance = 20 - (l_duration * 0.034 / 2);
  //int thickness = distace;

  //for second sensor
  digitalWrite(b_trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(b_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(b_trigPin, LOW);

  b_duration = pulseIn(b_echoPin, HIGH);
  int b_distance = 20 - (b_duration * 0.034 / 2);
  // int thickness1 = distance1;

  //for third sensor
  digitalWrite(h_trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(h_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(h_trigPin, LOW);

  h_duration = pulseIn(h_echoPin, HIGH);
  int h_distance = 20 - (h_duration * 0.034 / 2);
  // int thickness2 = distance2;

  Serial.print("Length : ");
  Serial.println(l_distance);

  Serial.print("Breadth : ");
  Serial.println(b_distance);

  Serial.print("Height : ");
  Serial.println(h_distance);
  if (l_distance == 0 && b_distance == 0 && h_distance == 0) {
    lcd.setCursor(0, 0);
    lcd.print("No Object Placed");
    lcd.setCursor(0, 1);
    lcd.print("Place the object in ");
    lcd.setCursor(0, 2);
    lcd.print(" the setup");
  }
  else {
    lcd.setCursor(0, 0);
    lcd.print("The Dimensions are : ");
    lcd.setCursor(0, 1);
    lcd.print("Length  : ");
    lcd.print(l_distance);
    lcd.print(" cm       ");

    lcd.setCursor(0, 2);
    lcd.print("Breadth : ");
    lcd.print(b_distance);
    lcd.print(" cm    ");

    lcd.setCursor(0, 3);
    lcd.print("Height : ");
    lcd.print(h_distance);
    lcd.print(" cm      ");
  }
  delay(100);
}
/*
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);
const int l_trigPin =3;
const int l_echoPin =5;

const int b_trigPin =6;
const int b_echoPin =9;

const int h_trigPin =10;
const int h_echoPin =11;

long l_duration;
int l_distance;

long b_duration;
int b_distance;

long h_duration;
int h_distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(l_trigPin, OUTPUT);
  pinMode(l_echoPin, INPUT);

  pinMode(b_trigPin, OUTPUT);
  pinMode(b_echoPin, INPUT);

  pinMode(h_trigPin, OUTPUT);
  pinMode(h_echoPin, INPUT);
  
  Serial.begin(9600);  
  lcd.init();
  lcd.init();
  lcd.backlight();

}

void loop() {
   digitalWrite(l_trigPin, LOW);
   digitalWrite(b_trigPin, LOW);
   digitalWrite(h_trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(l_trigPin, HIGH);
   digitalWrite(b_trigPin, HIGH);
   digitalWrite(h_trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(l_trigPin, LOW);
   digitalWrite(b_trigPin, LOW);
   digitalWrite(h_trigPin, LOW); 

   l_duration = pulseIn(l_echoPin, HIGH);
   b_duration = pulseIn(b_echoPin, HIGH);
   h_duration = pulseIn(h_echoPin, HIGH);

   l_distance = 21 - (l_duration*0.034/2);
   b_distance = 19 - (b_duration*0.034/2);
   h_distance = 21 - (h_duration*0.034/2);

   Serial.print("Length : ");
   Serial.println(l_distance);
    
   Serial.print("Breadth : ");
   Serial.println(b_distance);

   Serial.print("Height : ");
   Serial.println(h_distance);
   lcd.setCursor(0,0);
   lcd.print("3dimension ");
   lcd.setCursor(0,1);
   lcd.print(l_distance);
   lcd.setCursor(0,2);
   lcd.print(b_distance);
   lcd.setCursor(0,3);
   lcd.print(h_distance);
  delay(100);
}

*/
