const int KUCHNIASTOL_BUTTON_PIN = 32;
const int KUCHNIASTOL_RELAY_PIN = 33;
String KUCHNIASTOL_ON_COMMAND("kuchniastol#1");
String KUCHNIASTOL_OFF_COMMAND("kuchniastol#0");
//const int AFTER_CHANGE_DELAY = 500;

int KuchniaStolButtonState;
int KuchniaStolState = LOW;

void initializeKuchniaStol() {
    pinMode(KUCHNIASTOL_BUTTON_PIN , INPUT);
    pinMode(KUCHNIASTOL_RELAY_PIN , OUTPUT);
    setKuchniaStolState(LOW);
  
}

void checkKuchniaStol() {
  KuchniaStolButtonState = digitalRead(KUCHNIASTOL_BUTTON_PIN );
  if (KuchniaStolButtonState == HIGH) {
    toogleKuchniaStol();   
    delay(AFTER_CHANGE_DELAY);
  }
}

void setKuchniaStolState(int state) {
     digitalWrite(KUCHNIASTOL_RELAY_PIN , state);
      KuchniaStolState = state;
      if (state == LOW) {
        sendMqttState(KUCHNIASTOL_OFF_COMMAND);
      } else {
                sendMqttState(KUCHNIASTOL_ON_COMMAND);
      }

}

void toogleKuchniaStol() {
  if (KuchniaStolState == LOW) {
      setKuchniaStolState(HIGH);
    } else {
      setKuchniaStolState(LOW);
    }
}
