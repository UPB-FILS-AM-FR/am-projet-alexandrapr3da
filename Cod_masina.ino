/*
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/665f6790-6201-4a32-aa76-a82aeac3fd20

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  bool dreapta;
  bool inainte;
  bool inapoi;
  bool stanga;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
int enA = 4;
int enB = 5;
int in1 = 13;
int in2 = 12;
int in3 = 11;
int in4 = 10;
const int trig = 6;
const int echo = 7;
long duration;
int distance;
void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
  */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(distance);
  ArduinoCloud.update();


}



/*
  Since Inainte is READ_WRITE variable, onInainteChange() is
  executed every time a new value is received from IoT Cloud.
*/
//VOID ULTRASONIC
void onInainteChange()  {
  if (inainte == 1 && distance >= 15)
  {
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
  }
  else
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }



}

/*
  Since Inapoi is READ_WRITE variable, onInapoiChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onInapoiChange()  {
  if (inapoi == 1)
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in4, HIGH);
  }
  else
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
}

/*
  Since Dreapta is READ_WRITE variable, onDreaptaChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onDreaptaChange()  {
  if (dreapta == 1)
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
  else
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
}

/*
  Since Stanga is READ_WRITE variable, onStangaChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onStangaChange()  {
  if (stanga == 1)
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  else
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }

}