const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 6;
const int buzzerPin = 7;

const int threshold = 20;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  long duration;
  float distance;

  // Send ultrasonic trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Read echo duration
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance
  distance = (duration * 0.0343) / 2.0;

  // Display distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Obstacle detection
  if (distance > 0 && distance <= threshold) {

    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000);

  } else {

    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }

  delay(100);
}
