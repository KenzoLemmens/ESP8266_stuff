int sensorPin = A0;
int ledPin = LED_BUILTIN;
int sensorValue = 0;

void setup() {
  Serial.begin(115200);
  //enablePhaseLockedWaveform();
  pinMode(ledPin, OUTPUT);
  analogWriteRange(1024);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  //Serial.println(sensorValue);
  analogWrite(ledPin, sensorValue);
  //delay(1000);
}
