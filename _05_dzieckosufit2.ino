const int DZIECKOSUFIT2_BUTTON_PIN = 30;
const int DZIECKOSUFIT2_RELAY_PIN = 31;
String DZIECKOSUFIT2_ON_COMMAND("DzieckoSufit2#1");
String DZIECKOSUFIT2_OFF_COMMAND("DzieckoSufit2#0");
//const int AFTER_CHANGE_DELAY = 500;

int DzieckoSufit2ButtonState;
int DzieckoSufit2State = LOW;

void initializeDzieckoSufit2() {
    pinMode(DZIECKOSUFIT2_BUTTON_PIN , INPUT);
    pinMode(DZIECKOSUFIT2_RELAY_PIN , OUTPUT);
    setDzieckoSufit2State(LOW);
  
}

void checkDzieckoSufit2() {
  DzieckoSufit2ButtonState = digitalRead(DZIECKOSUFIT2_BUTTON_PIN );
  if (DzieckoSufit2ButtonState == HIGH) {
    toogleDzieckoSufit2();   
    delay(AFTER_CHANGE_DELAY);
  }
}

void setDzieckoSufit2State(int state) {
     digitalWrite(DZIECKOSUFIT2_RELAY_PIN , state);
      DzieckoSufit2State = state;
      if (state == LOW) {
        sendMqttState(DZIECKOSUFIT2_OFF_COMMAND);
      } else {
                sendMqttState(DZIECKOSUFIT2_ON_COMMAND);
      }

}

void toogleDzieckoSufit2() {
  if (DzieckoSufit2State == LOW) {
      setDzieckoSufit2State(HIGH);
    } else {
      setDzieckoSufit2State(LOW);
    }
}
