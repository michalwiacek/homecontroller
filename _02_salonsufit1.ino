const int SALONSUFIT1_BUTTON_PIN = 22;
const int SALONSUFIT1_RELAY_PIN = 23; 
String SALONSUFIT1_ON_COMMAND("salonsufit1#1");
String SALONSUFIT1_OFF_COMMAND("salonsufit1#0");
const int AFTER_CHANGE_DELAY = 500;

int salonSufit1ButtonState;
int salonSufit1State = LOW;

void initializeSalonSufit1() {
    pinMode(SALONSUFIT1_BUTTON_PIN , INPUT);
    pinMode(SALONSUFIT1_RELAY_PIN , OUTPUT);
    setSalonSufit1State(LOW);
  
}

void checkSalonSufit1() {
  salonSufit1ButtonState = digitalRead(SALONSUFIT1_BUTTON_PIN );
  if (salonSufit1ButtonState == HIGH) {
    toogleSalonSufit1();   
    delay(AFTER_CHANGE_DELAY);
  }
}

void setSalonSufit1State(int state) {
     digitalWrite(SALONSUFIT1_RELAY_PIN , state);
      salonSufit1State = state;
      if (state == LOW) {
        sendMqttState(SALONSUFIT1_OFF_COMMAND);
      } else {
                sendMqttState(SALONSUFIT1_ON_COMMAND);
      }

}

void toogleSalonSufit1() {
  if (salonSufit1State == LOW) {
      setSalonSufit1State(HIGH);
    } else {
      setSalonSufit1State(LOW);
    }
}
