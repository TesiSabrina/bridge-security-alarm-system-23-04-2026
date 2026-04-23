int doorPin = 7;
int resetPin = 8;
int redLED = 2;
int greenLED = 3;
int buzzer = 6;
int ldrPin = A0;

bool alarmActive = false;

void setup() {
  pinMode(doorPin, INPUT);
  pinMode(resetPin, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
  Serial.println("MONITORING ACTIVE");
}

void loop() {
 int ldrValue = analogRead(ldrPin);
  int doorState = digitalRead(doorPin);
  int resetState = digitalRead(resetPin);

  
  if (!alarmActive) {
    if (ldrValue > 600) {
      Serial.println("NIGHT MODE ON");

      digitalWrite(greenLED, HIGH);
      delay(500);
      digitalWrite(greenLED, LOW);
      delay(500);
    } else {
      digitalWrite(greenLED, HIGH);
    }
  }

  
  if (doorState == HIGH && !alarmActive) {
    alarmActive = true;
    Serial.println("INTRUDER DETECTED");

    digitalWrite(greenLED, LOW);

    
    for (int i = 0; i < 10; i++) {
      digitalWrite(redLED, HIGH);digitalWrite(buzzer, HIGH);
  }
  }
 
  
  if (resetState == HIGH && alarmActive) {
    alarmActive = false;

    digitalWrite(redLED, LOW);
    digitalWrite(buzzer, LOW);

    Serial.println("SYSTEM RESET");
    Serial.println("MONITORING ACTIVE");}
}
 