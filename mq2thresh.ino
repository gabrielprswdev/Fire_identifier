int mq2Pin = A0;
int mq2Value;
int threshold = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  mq2Value = analogRead(mq2Pin);
  if (mq2Value > threshold) {
    Serial.println("Fumaça detectada!");
  }
  delay(500);
}
