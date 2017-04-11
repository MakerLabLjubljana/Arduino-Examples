const byte ledPin = 10;
const byte interruptPin = 2;

volatile int ledState = 0;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(interruptPin), toggle, RISING);
}

void loop() {
  Serial.println("Led ON!");
  digitalWrite(ledPin, ledState);
  delay(5000);
}

void toggle() {
  Serial.println("Interrupt!");
  ledState = !ledState;
}
