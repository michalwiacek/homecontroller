const int SALONSUFIT2_BUTTON_PIN = 24;
const int SALONSUFIT2_RELAY_PIN = 25;
String SALONSUFIT2_ON_COMMAND("salonsufit2#1");
String SALONSUFIT2_OFF_COMMAND("salonsufit2#0");
//const int AFTER_CHANGE_DELAY = 500;

int salonSufit2ButtonState;
int salonSufit2State = LOW;

void initializeSalonSufit2() {
    pinMode(SALONSUFIT2_BUTTON_PIN , INPUT);
    pinMode(SALONSUFIT2_RELAY_PIN , OUTPUT);
    setSalonSufit2State(LOW);
  
}

void checkSalonSufit2() {
  salonSufit2ButtonState = digitalRead(SALONSUFIT2_BUTTON_PIN );
  if (salonSufit2ButtonState == HIGH) {
    toogleSalonSufit2();   
    delay(AFTER_CHANGE_DELAY);
  }
}

void setSalonSufit2State(int state) {
     digitalWrite(SALONSUFIT2_RELAY_PIN , state);
      salonSufit2State = state;
      if (state == LOW) {
        sendMqttState(SALONSUFIT2_OFF_COMMAND);
      } else {
                sendMqttState(SALONSUFIT2_ON_COMMAND);
      }

}

void toogleSalonSufit2() {
  if (salonSufit2State == LOW) {
      setSalonSufit2State(HIGH);
    } else {
      setSalonSufit2State(LOW);
    }
}
