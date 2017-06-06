#define echoPin 4 // Echo Pin
#define trigPin 5 // Trigger Pin
int maximumRange = 20; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

void setup() {
  
 
 pinMode(12, OUTPUT); //Initiates Motor Channel A pin
 pinMode(9, OUTPUT); //Initiates Brake Channel A pin
 pinMode(13, OUTPUT); // initiates motor channel B pin
 pinMode(8, OUTPUT); // initiates Brake channel B pin
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
  
}

  bool checkDistance()
  {
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration/58.2;

       if (distance <= maximumRange)
      {
        return true;
      }
      else
      {
      return false;
      }
  } // endCheckDistance



void loop(){

  if(checkDistance())
 {
  digitalWrite(9, HIGH);   //Disengage the Brake for Channel
  delay(1000);
 }

  digitalWrite(12, LOW); //Establishes forward direction of Channel A
  digitalWrite(13, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 255);   //Spins the motor on Channel A at full speed
  analogWrite(11, 255);   //Spins the motor on Channel A at full speed

 if(checkDistance())
 {
   digitalWrite(9, HIGH);   //Disengage the Brake for Channe
   //digitalWrite(8, HIGH);
  delay(100);
  //digitalWrite(9, LOW); 
  
 }

}


