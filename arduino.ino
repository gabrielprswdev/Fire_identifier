int mq2Pin = A0;
int mq2Value;
int threshold = 0;
int flamePin = 2;
int flameState;
bool flame = false;
bool smoke = false;

void setup(){
    pinMode(flamePin, INPUT);
    Serial.begin(9600);
}

void loop(){
    flameState = digitalRead(flamePin);
    mq2Value = analogRead(mq2Pin);

    delay(250);

    if (flameState == LOW) {
        flame = true;
    }

    if (mq2Value > threshold){
        smoke = true;
    }

    delay(250);

    if (flame && smoke){
        Serial.println("1");
        delay(1000);
    }

}