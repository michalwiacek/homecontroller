const int KUCHNIASZAFKI_BUTTON_PIN = 26;
const int KUCHNIASZAFKI_RELAY_PIN = 27;
String KUCHNIASZAFKI_ON_COMMAND("kuchniaszafki#1");
String KUCHNIASZAFKI_OFF_COMMAND("kuchniaszafki#0");
//const int AFTER_CHANGE_DELAY = 500;

int KuchniaSzafkiButtonState;
int KuchniaSzafkiState = LOW;

void initializeKuchniaSzafki() {
    pinMode(KUCHNIASZAFKI_BUTTON_PIN , INPUT);
    pinMode(KUCHNIASZAFKI_RELAY_PIN , OUTPUT);
    setKuchniaSzafkiState(LOW);
  
}

void checkKuchniaSzafki() {
  KuchniaSzafkiButtonState = digitalRead(KUCHNIASZAFKI_BUTTON_PIN );
  if (KuchniaSzafkiButtonState == HIGH) {
    toogleKuchniaSzafki();   
    delay(AFTER_CHANGE_DELAY);
  }
}

void setKuchniaSzafkiState(int state) {
     digitalWrite(KUCHNIASZAFKI_RELAY_PIN , state);
      KuchniaSzafkiState = state;
      if (state == LOW) {
        sendMqttState(KUCHNIASZAFKI_OFF_COMMAND);
      } else {
                sendMqttState(KUCHNIASZAFKI_ON_COMMAND);
      }

}

void toogleKuchniaSzafki() {
  if (KuchniaSzafkiState == LOW) {
      setKuchniaSzafkiState(HIGH);
    } else {
      setKuchniaSzafkiState(LOW);
    }
}
