const int ledPin1 = 13;
const int ledPin2 = 12;
const int ledPin3 = 11;
const int ledPin4 = 10;
const int switchPin = 9;

const int ldrPin = A0;

int switchState = 0; 

void setup() {

Serial.begin(9600);

pinMode(ledPin1, OUTPUT);

pinMode(ledPin2, OUTPUT);

pinMode(ledPin3, OUTPUT);

pinMode(ledPin4, OUTPUT);

pinMode(ldrPin, INPUT);

pinMode(switchPin, INPUT);

}

void loop() {

switchState = digitalRead(switchPin);
  
int ldrStatus = analogRead(ldrPin);

if (switchState == HIGH ) //if it is,the state is HIGH
  {
    if (ldrStatus <= 935) {

	  digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, HIGH);

	  Serial.print("Its DARK, Turn on the LED : ");

	  Serial.println(ldrStatus);

	}
	else {

	  Serial.print("Its BRIGHT, Turn off the LED : ");

	  digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, LOW);

	  Serial.println(ldrStatus);

}
  }
  else
  {
    digitalWrite(ledPin1, LOW); //turn the led off
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
  }

}
