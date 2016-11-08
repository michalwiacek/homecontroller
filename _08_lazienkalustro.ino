const int LAZIENKALUSTRO_BUTTON_PIN = 34;
const int LAZIENKALUSTRO_RELAY_PIN = 35;
String LAZIENKALUSTRO_ON_COMMAND("lazienkalustro#1");
String LAZIENKALUSTRO_OFF_COMMAND("lazienkalustro#0");
//const int AFTER_CHANGE_DELAY = 500;

int LazienkaLustroButtonState;
int LazienkaLustroState = LOW;

void initializeLazienkaLustro() {
    pinMode(LAZIENKALUSTRO_BUTTON_PIN , INPUT);
    pinMode(LAZIENKALUSTRO_RELAY_PIN , OUTPUT);
    setLazienkaLustroState(LOW);
  
}

void checkLazienkaLustro() {
  LazienkaLustroButtonState = digitalRead(LAZIENKALUSTRO_BUTTON_PIN );
  if (LazienkaLustroButtonState == HIGH) {
    toogleLazienkaLustro();   
    delay(AFTER_CHANGE_DELAY);
  }
}

void setLazienkaLustroState(int state) {
     digitalWrite(LAZIENKALUSTRO_RELAY_PIN , state);
      LazienkaLustroState = state;
      if (state == LOW) {
        sendMqttState(LAZIENKALUSTRO_OFF_COMMAND);
      } else {
                sendMqttState(LAZIENKALUSTRO_ON_COMMAND);
      }

}

void toogleLazienkaLustro() {
  if (LazienkaLustroState == LOW) {
      setLazienkaLustroState(HIGH);
    } else {
      setLazienkaLustroState(LOW);
    }
}
