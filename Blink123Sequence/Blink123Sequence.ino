/*
  Blink123Sequence

  Turns an LED on and off in the famous clapping sequence
  123, 123, 1..2..3

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1500 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 13 Oct 2017
  by Jagadish N

  This example code is in the public domain.

  http://www.github.com/jkanasu/arduino/Blink123Sequence
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  int delaySequenceLength = 24;
  // generally the values should be a pair, values in a pair are for ON and OFF delay
  int delaySequence[] = {
    200,150,200,150,200,150,
    0,330, // ON time is zero
    200,150,200,150,200,150,
    0,330, // ON time is zero
    330,330,330,330,330,330,
    0,2000 // ON time is zero
    };
  for ( int i = 0 ; i < delaySequenceLength ; i = i +2){
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(delaySequence[i]);           // wait for the time specified by array element
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(delaySequence[i+1]);         // wait for the time specified by array element
  }
}

