/*
  Blink123Sequence

  Sets the color of an RGB LED to a rainbow's VIBGYOR sequence

  A common cathode RGB LED is used.
  The cathode is connected to the ground via a 220 Ohm resitor in series.
  The RGB terminals of LED are connected to the PWM pins 3,5&6 respectively.

  modified 21 Oct 2017
  by Jagadish N

  This example code is in the public domain.

  https://github.com/jkanasu/arduino
*/
#define pwmLedRed   3
#define pwmLedGreen 5
#define pwmLedBlue  6

void setup() {
  // put your setup code here, to run once:
  pinMode(pwmLedRed, OUTPUT);
  pinMode(pwmLedGreen, OUTPUT);
  pinMode(pwmLedBlue, OUTPUT);
  initialShow();
}

void loop() {
  // put your main code here, to run repeatedly:
  showRainbowColors();
}

void showRainbowColors(){
  //https://www.webnots.com/vibgyor-rainbow-color-codes/
  int colorPalette[]={
    148,0,211, // violet
    75,0,130, // indigo
    0,0,255, // blue
    0,255,0, // green
    255,255,0, // yellow
    255,127,0, // orange
    255,0,0 // red
  };

  for (int i = 0; i <= 18; i = i + 3){
    setLedColor(colorPalette[i],colorPalette[i+1],colorPalette[i+2]);
    delay(1000);
    allLedsOff();
    delay(500);
  }
}

void setLedColor(int redAmount, int greenAmount, int blueAmount){
  analogWrite(pwmLedRed, redAmount);
  analogWrite(pwmLedGreen, greenAmount);
  analogWrite(pwmLedBlue, blueAmount);
}

void initialShow(){
  digitalWrite(pwmLedRed, HIGH);
  delay(250);
  digitalWrite(pwmLedRed, LOW);
  delay(250);

  digitalWrite(pwmLedGreen, HIGH);
  delay(250);
  digitalWrite(pwmLedGreen, LOW);
  delay(250);

  digitalWrite(pwmLedBlue, HIGH);
  delay(250);
  digitalWrite(pwmLedBlue, LOW);
  delay(250);  
}

void allLedsOn(){
  digitalWrite(pwmLedRed, HIGH);
  digitalWrite(pwmLedGreen, HIGH);
  digitalWrite(pwmLedBlue, HIGH);
}
void allLedsOff(){
  digitalWrite(pwmLedRed, LOW);
  digitalWrite(pwmLedGreen, LOW);
  digitalWrite(pwmLedBlue, LOW);
}

