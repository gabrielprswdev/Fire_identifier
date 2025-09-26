int mq2Pin = A0;
int mq2Value;

void setup() {
  Serial.begin(9600);
}

void loop() {
  mq2Value = analogRead(mq2Pin);
  Serial.println(mq2Value);
  delay(1000);
}
