
void setup() {
  Serial.begin(9600);
  initializeNetwork();
  initializeMqtt();


  initializeSalonSufit1();
  initializeSalonSufit2();
  initializeKuchniaSzafki();
  initializeKuchniaStol();
  initializeLazienkaSufit();
  initializeLazienkaLustro();
  initializeDzieckoSufit1();
  initializeDzieckoSufit2();
  initializeTarasSufit();


}

void loop() {
  checkSalonSufit1();
  checkSalonSufit2();
  checkKuchniaSzafki();
  checkKuchniaStol();
  checkLazienkaSufit();
  checkLazienkaLustro();
  checkDzieckoSufit1();
  checkDzieckoSufit2();
  checkTarasSufit();
  
  checkMqtt();
}
