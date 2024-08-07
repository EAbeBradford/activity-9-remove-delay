
#define LED_PIN 8

unsigned long timeStart = 0;
boolean LEDOn = true;


int blinkrate = 1000;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(10);
  pinMode(LED_PIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currTime = millis();

  if(currTime - timeStart > userBlinkRate()){

    if(LEDOn){
      digitalWrite(LED_PIN, HIGH);
      LEDOn = false;
    } else {
      digitalWrite(LED_PIN, LOW);
      LEDOn = true;
    }
    timeStart += blinkrate;
  }

}

int userBlinkRate(){
  if(Serial.available() > 0 ){
    blinkrate = Serial.parseInt();
    if(blinkrate > 1000 || blinkrate < 100){
      blinkrate = 1000;
    }
  }

  return blinkrate;
}
