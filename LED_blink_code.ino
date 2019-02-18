const int led = A0;
const int input = 12;
unsigned long now = millis();
unsigned long nextBlink = 500;
const int blinkIntervalLow = 1500;
const int blinkIntervalHigh = 250;
int ledState = 300;
const int ledOn = 0;
const int ledOff = 300;
boolean inputSignal = false;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(input, INPUT);
}

void loop() {
  now = millis();
  if (now >= nextBlink)
  {
    inputSignal = digitalRead(input);
    if (inputSignal == 1)
    {
      analogWrite(led, ledState);
      checkState();
      nextBlink += blinkIntervalHigh;
    }
    else
    {
      analogWrite(led, ledState);
      checkState();
      nextBlink += blinkIntervalLow;
    }
  }
}

void checkState()
{
  if (ledState == ledOn)
  {
    ledState = ledOff;
  }
  else
  {
    ledState = ledOn;
  }
}
