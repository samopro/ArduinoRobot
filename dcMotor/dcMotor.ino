const int dir1 = 2;
const int dir2 = 3;
const int enable = 9;

void naarVooren() {
  analogWrite(enable, 127);
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, LOW);
  delay(5000);
  analogWrite(enable, 0);
  delay(1000);
}

void naarAchter() {
  analogWrite(enable, 127);
  digitalWrite(dir1, LOW);
  digitalWrite(dir2, HIGH);
  delay(5000);
  analogWrite(enable, 0);
  delay(1000);
}


void setup() {
  pinMode(dir1, OUTPUT);
  pinMode(dir2, INPUT);
  pinMode(enable, OUTPUT);

  Serial.begin(9600);
  

}

void loop() {

  if (Serial.available() > 0) {
      int command = Serial.read();
      Serial.print(command);
      if (command == 49) {
          naarVooren();
      }

      if (command == 50) {
        naarAchter();      
    }
  }

}
