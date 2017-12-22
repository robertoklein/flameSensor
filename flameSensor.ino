/* Flame Sensor analog example.
Code by Reichenstein7 (thejamerson.com)

Flame Sensor Ordered from DX ( http://www.dx.com/p/arduino-flame-sensor-for-temperature-
detection-blue-dc-3-3-5v-118075?tc=USD&gclid=CPX6sYCRrMACFZJr7AodewsA-Q#.U_n5jWOrjfU )

To test view the output, point a serial monitor such as Putty at your arduino. 
*/
#include <ESP8266WiFi.h>
WiFiClient espClient;

// lowest and highest sensor readings:
//const int sensorMin = 0;     // sensor minimum
//const int sensorMax = 1024;  // sensor maximum


/**
 * porta d5 ligado o led
 */
int LED = 14; //D5
int sensorPin = A0;
//int sensorPin = 12;
int sensorValue = 0;

/**
 * conexao com wifi
 */
char ssid[] = "AndroidAP";
char pass[] = "ifyy0846";

void setup() {
  Serial.begin(9600);  
    //inicia o wifi
    initWifi();
    initPins(); 
}

void initPins(){
  pinMode(LED, OUTPUT);
  //pinMode(LED, LOW);
}
void loop() {

  reconnectWifi();

  //sensorValue = digitalRead(sensorPin);
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);

  if(sensorValue < 100){
  Serial.println("fire detected");  
  ligaLed();
  delay(2000);
  }else{
    desligaLed();
  }
  
  delay(500);  // delay between reads

  // range value:
  //switch (range) {
 // case 0:    // A fire closer than 1.5 feet away.
   // Serial.println("** Close Fire **");
   // ligaLed();
   // break;
  //case 1:    // A fire between 1-3 feet away.
    //Serial.println("** Distant Fire **");
   // break;
  //case 2:    // No fire detected.
    //Serial.println("No Fire");
    //desligaLed();
   // break;
  //}
 
}

/**
 * metodo para iniciar a conexao com wifi
 */
void initWifi(){
    delay(10);
  Serial.println("Connecting to: " + String(ssid));
  WiFi.begin(ssid,pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.println("trying to connect the wifi");
  }
 Serial.println();
 Serial.println("Connected to the WiFi network");
}

/**
 * metodo para concectar com o wifi
 */
void reconnectWifi(){
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.println("Connecting to WiFi..");
  }
}

void ligaLed(){
  Serial.println("entrou no ligaled");
  digitalWrite(LED, LOW);
}

void desligaLed(){
  Serial.println("entrou no desligaled");
  digitalWrite(LED, HIGH);
}
