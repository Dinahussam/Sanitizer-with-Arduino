//Ultasonic Sensor

  
//Pins connected to the ultrasonic sensor

#define trigPin  2

#define echoPin 3

#define pump 8

int range = 5;//range in inches


void setup() {

  // initialize serial communication:

  Serial.begin(9600);

  //initialize the sensor pins

  pinMode(trigPin, OUTPUT);

  pinMode(echoPin, INPUT);

  //initialize LED pins

  pinMode(pump, OUTPUT);

  digitalWrite(pump, LOW);

 

}

void loop()

{

  // establish variables for duration of the ping,

  // and the distance result in inches and centimeters:

  long duration, inches, cm;


  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.

  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:

  digitalWrite(trigPin, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10 );

  digitalWrite(trigPin, LOW);


  // Take reading on echo pin

  duration = pulseIn(echoPin, HIGH);


  // convert the time into a distance

  inches = microsecondsToInches(duration);

  cm = microsecondsToCentimeters(duration);

 

  Serial.print(inches);

  Serial.print("in, ");

  Serial.print(cm);

  Serial.print("cm");

  Serial.println();

 

  if(inches < 5) {

    Serial.println("hand puted");


    digitalWrite(pump, HIGH);

     

    delay(100);

  } else {

    Serial.println("no hand");

     digitalWrite(pump, LOW);

     delay(100);

  }  

 

  delay(200);

}


long microsecondsToInches(long microseconds)

{


  return microseconds / 74 / 2;

}


long microsecondsToCentimeters(long microseconds)

{

  // The speed of sound is 340 m/s or 29 microseconds per centimeter.

  // The ping travels out and back, so to find the distance of the

  // object we take half of the distance travelled.

  return microseconds / 29 / 2;

}
