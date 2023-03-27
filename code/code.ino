 #include <Servo.h>;
 
 // pushbutton pin
 const int buttonPin = 8;

 // servo pin
 const int servoPin = 3;
 const int ledPin = 7;

 Servo servo;


//create a variable to store a counter and set it to 0
int counter = 0;
void setup()
{
  servo.attach(servoPin);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

  // Set up the pushbutton pins to be an input:
  pinMode(buttonPin, INPUT);
}


void loop()
{
 // local variable to hold the pushbutton states
  int buttonState;  

  //read the digital state of buttonPin with digitalRead() function and store the           //value in buttonState variable
  buttonState = digitalRead(buttonPin);
  //if the button is pressed increment counter and wait a tiny bit to give us some          //time to release the button
  if (buttonState == LOW) // light the LED
  {
    counter++;
      Serial.println(buttonState);

    delay(200);
  }
  if(counter == 0){
    servo.write (0);  // zero degrees
    digitalWrite(ledPin,LOW);
  }
  else if(counter == 1){
    servo.write(180);
    digitalWrite(ledPin, HIGH);

  }
  //else reset the counter to 0 which resets thr servo to 0 degrees
  else{
   counter = 0;
  }
  //delay(1000);

}
