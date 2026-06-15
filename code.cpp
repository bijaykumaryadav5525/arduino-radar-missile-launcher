#include <Servo.h> 

const int trigPin = 7; 
const int echoPin = 6; 

Servo launcherServo; 
Servo radarServo; 

const int ledPin = 3; 
const int buzzerPin = 2; 

const int launcherPin = 9; 
const int radarPin = 10; 

long duration; 
int distance; 

int radarAngle = 0; 
int radarDirection = 2; // faster step (was 1) 

unsigned long previousMillis = 0; 
const int interval = 10; // faster update (was 20) 

bool targetDetected = false; 
const int detectionDistance = 30; 

void setup() { 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(ledPin, OUTPUT); 
  pinMode(buzzerPin, OUTPUT); 

  launcherServo.attach(launcherPin); 
  radarServo.attach(radarPin); 

  Serial.begin(9600); 

  launcherServo.write(90); 
} 

void loop() { 
  radarScanFast(); 
  distance = getDistanceFast(); 

  if (distance <= detectionDistance && distance > 0) { 
    if (!targetDetected) { 
      targetDetected = true; 
      triggerAlarmFast(); 
      fireMissileFast(); 
    } 
  } else { 
    targetDetected = false; 
  } 
} 

// Faster radar movement 
void radarScanFast() { 
  unsigned long currentMillis = millis(); 

  if (currentMillis - previousMillis >= interval) { 
    previousMillis = currentMillis; 

    radarAngle += radarDirection; 
    
    if (radarAngle >= 180 || radarAngle <= 0) { 
      radarDirection *= -1; 
    } 
    
    radarServo.write(radarAngle); 
  } 
} 

// Faster distance reading (timeout added) 
int getDistanceFast() { 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 

  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(8); // shorter pulse 
  digitalWrite(trigPin, LOW); 

  duration = pulseIn(echoPin, HIGH, 20000); // timeout (20ms) 

  if (duration == 0) return 999; // no reading 

  return duration * 0.0343 / 2; 
} 

// Faster alarm 
void triggerAlarmFast() { 
  for (int i = 0; i < 2; i++) { // reduced loops 
    digitalWrite(ledPin, HIGH); 
    tone(buzzerPin, 1500); 
    delay(100); // shorter delay 
    digitalWrite(ledPin, LOW); 
    noTone(buzzerPin); 
    delay(100); 
  } 
} 

// Faster firing 
void fireMissileFast() { 
  Serial.println("FIRE!"); 
  
  // Move launcher servo to firing position (adjust angle as needed)
  launcherServo.write(180); // Fire position
  delay(500); // Wait for servo to move
  launcherServo.write(90); // Return to ready position
  delay(500);
}