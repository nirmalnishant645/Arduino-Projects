void setup() {
  
  pinMode(13, OUTPUT);  
  pinMode(12, OUTPUT);  
  pinMode(11, OUTPUT);  
  pinMode(10, OUTPUT);  
  pinMode(9, OUTPUT);   
  pinMode(8, OUTPUT);   
}

void loop() {
  digitalWrite(13, HIGH);   
  digitalWrite(12, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(9,  HIGH);
  delay(100);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  delay(100);
  
  digitalWrite(11, HIGH);   
  digitalWrite(12, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9,  HIGH);
  delay(100);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  delay(100);

}