const int buttonPin = 2;
const int ledPin = 10;

// Variables will change:
int ledState = HIGH;
int buttonState;
int lastButtonState = LOW;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, ledState);
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading == 1) {
    ledState = !ledState;
    delay(100);
  }
    
  digitalWrite(ledPin, ledState);
}
