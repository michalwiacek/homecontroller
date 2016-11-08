const int DZIECKOSUFIT1_BUTTON_PIN = 28;
const int DZIECKOSUFIT1_RELAY_PIN = 39;
String DZIECKOSUFIT1_ON_COMMAND("DzieckoSufit1#1");
String DZIECKOSUFIT1_OFF_COMMAND("DzieckoSufit1#0");
//const int AFTER_CHANGE_DELAY = 500;

int DzieckoSufit1ButtonState;
int DzieckoSufit1State = LOW;

void initializeDzieckoSufit1() {
    pinMode(DZIECKOSUFIT1_BUTTON_PIN , INPUT);
    pinMode(DZIECKOSUFIT1_RELAY_PIN , OUTPUT);
    setDzieckoSufit1State(LOW);
  
}

void checkDzieckoSufit1() {
  DzieckoSufit1ButtonState = digitalRead(DZIECKOSUFIT1_BUTTON_PIN );
  if (DzieckoSufit1ButtonState == HIGH) {
    toogleDzieckoSufit1();   
    delay(AFTER_CHANGE_DELAY);
  }
}

void setDzieckoSufit1State(int state) {
     digitalWrite(DZIECKOSUFIT1_RELAY_PIN , state);
      DzieckoSufit1State = state;
      if (state == LOW) {
        sendMqttState(DZIECKOSUFIT1_OFF_COMMAND);
      } else {
                sendMqttState(DZIECKOSUFIT1_ON_COMMAND);
      }

}

void toogleDzieckoSufit1() {
  if (DzieckoSufit1State == LOW) {
      setDzieckoSufit1State(HIGH);
    } else {
      setDzieckoSufit1State(LOW);
    }
}
