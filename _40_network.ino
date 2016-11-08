#include <SPI.h>         // needed for Arduino versions later than 0018
#include <Ethernet.h>
#include <EthernetUdp.h>         // UDP library from: bjoern@cs.stanford.edu 12/30/2008

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

IPAddress ip(192, 168, 1, 5);
unsigned int localPort = 8888;      // local port to listen on
EthernetClient client;
char packetBuffer[UDP_TX_PACKET_MAX_SIZE]; //buffer to hold incoming packet,
char  ReplyBuffer[] = "acknowledged";       // a string to send back

void initializeNetwork() {
  Ethernet.begin(mac, ip);
}


void executeRemoteCommand(String command) {
  Serial.println(command);
  if (command == SALONSUFIT1_ON_COMMAND) {
    setSalonSufit1State(HIGH);
  }
  if (command == SALONSUFIT1_OFF_COMMAND) {
    setSalonSufit1State(LOW);
  }

  if (command == SALONSUFIT2_ON_COMMAND) {
    setSalonSufit2State(HIGH);
  }
  if (command == SALONSUFIT2_OFF_COMMAND) {
    setSalonSufit2State(LOW);
  }

  if (command == DZIECKOSUFIT1_ON_COMMAND) {
    setDzieckoSufit1State(HIGH);
  }
  if (command == DZIECKOSUFIT1_OFF_COMMAND) {
    setDzieckoSufit1State(LOW);
  }

  if (command == DZIECKOSUFIT2_ON_COMMAND) {
    setDzieckoSufit2State(HIGH);
  }
  if (command == DZIECKOSUFIT2_OFF_COMMAND) {
    setDzieckoSufit2State(LOW);
  }

  if (command == KUCHNIASZAFKI_ON_COMMAND) {
    setKuchniaSzafkiState(HIGH);
  }
  if (command == KUCHNIASZAFKI_OFF_COMMAND) {
    setKuchniaSzafkiState(LOW);
  }

   if (command == KUCHNIASTOL_ON_COMMAND) {
    setKuchniaStolState(HIGH);
  }
  if (command == KUCHNIASTOL_OFF_COMMAND) {
    setKuchniaStolState(LOW);
  }

  if (command == TARASSUFIT_ON_COMMAND) {
    setTarasSufitState(HIGH);
  }
  if (command == TARASSUFIT_OFF_COMMAND) {
    setTarasSufitState(LOW);
  }
  if (command == LAZIENKASUFIT_ON_COMMAND) {
    setLazienkaSufitState(HIGH);
  }
  if (command == LAZIENKASUFIT_OFF_COMMAND) {
    setLazienkaSufitState(LOW);
  }
  if (command == LAZIENKALUSTRO_ON_COMMAND) {
    setLazienkaLustroState(HIGH);
  }
  if (command == LAZIENKALUSTRO_OFF_COMMAND) {
    setLazienkaLustroState(LOW);
  }
}

