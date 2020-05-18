int laserPin = 2;
int  sensorPin  =  A0;     // select the input  pin for  the potentiometer 
int buzzer = 11; // off right now, 10 to turn it on

int redPin = A2; // because A6 seems to be broken
int greenPin = A4;
int bluePin = A3;

int onThresh = 850;
int offThresh = 950;

int  sensorValue;  // variable to  store  the value  coming  from  the sensor
bool state;       // variable to store current state of water level (above/below)

void setup() {
  // Set output pins
  pinMode(laserPin, OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);

  Serial.begin(9600);

  // Read initial value
  digitalWrite(laserPin,HIGH);
  delay(200);
  sensorValue =  analogRead(sensorPin);
  Serial.println(sensorValue);
  if (sensorValue<(offThresh+onThresh)/2){
    state = true;
  }
  else {
    state = false;
  }
  delay(200);
  
}

void loop() {

  // Set indicating LED to current state
  if (state){
    digitalWrite(redPin,LOW);
    digitalWrite(greenPin,HIGH);
    digitalWrite(bluePin,LOW);
  }
  else{
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,LOW);
    digitalWrite(bluePin,LOW);
  }

  delay(1000);

  // Read new value
  sensorValue =  analogRead(sensorPin);
  Serial.println(sensorValue);

  // Set state to false if resistance too high
  if (state && sensorValue>offThresh){
    state = false;
    digitalWrite(greenPin,LOW);
    digitalWrite(bluePin,LOW);
    
    for(int i=0;i<3;i++){
        analogWrite(buzzer,200);
        digitalWrite(redPin,HIGH);
        delay(300);
        digitalWrite(buzzer,LOW);
        digitalWrite(redPin,LOW);
        delay(300);
    }
  }

  // Set state to true if resistance too low
  if (!state && sensorValue < onThresh){
    state = true;

    digitalWrite(redPin,LOW);
    digitalWrite(greenPin,LOW);
    
    for (int i=0; i<3;i++){
      digitalWrite(bluePin,HIGH);
      analogWrite(buzzer,50);
      delay(300);
      digitalWrite(buzzer,LOW);
      digitalWrite(bluePin,LOW);
      delay(300);
    }
  }

}
