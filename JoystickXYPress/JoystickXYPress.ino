#define X_PIN A0
#define Y_PIN A1
#define SW_PIN 4

void setup() {
  // put your setup code here, to run once:
  pinMode(X_PIN, INPUT);
  pinMode(Y_PIN, INPUT);
  pinMode(SW_PIN, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x_pos = analogRead(X_PIN);
  int y_pos = analogRead(Y_PIN);
  int sw_state = digitalRead(SW_PIN);

  Serial.println("x: "+String(x_pos)+" y: "+String(y_pos)+" sw: "+String(sw_state));
  delay(y_pos);
}
