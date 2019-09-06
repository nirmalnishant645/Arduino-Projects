const int leftForward = 5;
const int leftBackward = 6;
const int rightForward = 9;
const int rightBackward = 10;
int obstaclePin = 11;
int hasObstacle;

void setup() {
  pinMode(leftForward , OUTPUT);
  pinMode(leftBackward , OUTPUT);
  pinMode(rightForward , OUTPUT);
  pinMode(rightBackward , OUTPUT);
  pinMode(obstaclePin, INPUT);
  Serial.begin(9600);  
}
void loop() {
  hasObstacle = digitalRead(obstaclePin);
  if (hasObstacle == LOW)
  {
    Serial.println("STOP");
    analogWrite(leftForward , 0);
    analogWrite(rightForward , 0);
    analogWrite(leftBackward , 0);
    analogWrite(rightBackward , 0);
  }
  else
  {
    Serial.println("GO");
    analogWrite(leftForward , 255);
    analogWrite(rightForward , 255);
    analogWrite(leftBackward , 0);
    analogWrite(rightBackward , 0);
    delay(3000);
  }
  delay(100);
}
