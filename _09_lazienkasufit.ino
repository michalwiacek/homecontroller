const int LAZIENKASUFIT_BUTTON_PIN = 36;
const int LAZIENKASUFIT_RELAY_PIN = 37;
String LAZIENKASUFIT_ON_COMMAND("LazienkaSufit#1");
String LAZIENKASUFIT_OFF_COMMAND("LazienkaSufit#0");
//const int AFTER_CHANGE_DELAY = 500;

int LazienkaSufitButtonState;
int LazienkaSufitState = LOW;

void initializeLazienkaSufit() {
    pinMode(LAZIENKASUFIT_BUTTON_PIN , INPUT);
    pinMode(LAZIENKASUFIT_RELAY_PIN , OUTPUT);
    setLazienkaSufitState(LOW);
  
}

void checkLazienkaSufit() {
  LazienkaSufitButtonState = digitalRead(LAZIENKASUFIT_BUTTON_PIN );
  if (LazienkaSufitButtonState == HIGH) {
    toogleLazienkaSufit();   
    delay(AFTER_CHANGE_DELAY);
  }
}

void setLazienkaSufitState(int state) {
     digitalWrite(LAZIENKASUFIT_RELAY_PIN , state);
      LazienkaSufitState = state;
      if (state == LOW) {
        sendMqttState(LAZIENKASUFIT_OFF_COMMAND);
      } else {
                sendMqttState(LAZIENKASUFIT_ON_COMMAND);
      }

}

void toogleLazienkaSufit() {
  if (LazienkaSufitState == LOW) {
      setLazienkaSufitState(HIGH);
    } else {
      setLazienkaSufitState(LOW);
    }
}
