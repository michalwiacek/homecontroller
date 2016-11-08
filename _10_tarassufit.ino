const int TARASSUFIT_BUTTON_PIN = 38;
const int TARASSUFIT_RELAY_PIN = 39;
String TARASSUFIT_ON_COMMAND("TarasSufit#1");
String TARASSUFIT_OFF_COMMAND("TarasSufit#0");
//const int AFTER_CHANGE_DELAY = 500;

int TarasSufitButtonState;
int TarasSufitState = LOW;

void initializeTarasSufit() {
    pinMode(TARASSUFIT_BUTTON_PIN , INPUT);
    pinMode(TARASSUFIT_RELAY_PIN , OUTPUT);
    setTarasSufitState(LOW);
  
}

void checkTarasSufit() {
  TarasSufitButtonState = digitalRead(TARASSUFIT_BUTTON_PIN );
  if (TarasSufitButtonState == HIGH) {
    toogleTarasSufit();   
    delay(AFTER_CHANGE_DELAY);
  }
}

void setTarasSufitState(int state) {
     digitalWrite(TARASSUFIT_RELAY_PIN , state);
      TarasSufitState = state;
      if (state == LOW) {
        sendMqttState(TARASSUFIT_OFF_COMMAND);
      } else {
                sendMqttState(TARASSUFIT_ON_COMMAND);
      }

}

void toogleTarasSufit() {
  if (TarasSufitState == LOW) {
      setTarasSufitState(HIGH);
    } else {
      setTarasSufitState(LOW);
    }
}
