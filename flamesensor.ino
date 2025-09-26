int flamePin = 2;
int flameState;

void setup() {
  pinMode(flamePin, INPUT);
  Serial.begin(9600);
}

void loop() {
  flameState = digitalRead(flamePin);
  if (flameState == LOW) {
    Serial.println("Chama detectada!");
  } else {
    Serial.println("Sem chama");
  }
  delay(500);
}