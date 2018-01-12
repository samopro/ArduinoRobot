/************************************************/
/*                                              */
/*         Author:  Blizzard "Blizzy" Color     */
/*         Date:    11/01/2018                  */
/*         Version: 1.0                         */
/*         Subject: UltraSonic Sensor           */
/*                                              */
/************************************************/

const int trig = 2; //Defining the UltraSonic's trigger pin number on the arduino
const int echo = 3; //Defining the UltraSonic's echo pin number on the arduino
long echoRead;      //This to read the width of the pulse length in microseconds
long distance;      //This is to store and print the distance of an object in centimeters

void setup() {
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);       //This is to make sure that the Sensor is disabled at the begining
  pinMode(echo, INPUT);
  Serial.begin(9600);            //This is to be able to read the distance
}

void loop() {
  digitalWrite(trig, HIGH);      /*****************************************************/
  delayMicroseconds(10);         /*   this sends a pulse witdh of ten microsenconds   */
  digitalWrite(trig, LOW);       /*****************************************************/
  echoRead = pulseIn(echo, HIGH);//This calculates the duration of the pulse in microseconds
  distance = echoRead * 0.017;   //this calculates the distance of the echo pulse in centimeters
  Serial.print("Distance: ");    /***************************************************/
  Serial.print(distance);        /*            This is just a neat way              */
  Serial.print(" cm");           /*         to way to print out the distance        */
  Serial.print("\n");            /***************************************************/
  delay(1000);                   //This just puts a delay to not over do it

}
