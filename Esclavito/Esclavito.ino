#include <Wire.h>

const int lm35Pin = A0;
float temperatura;

void setup() {
  Wire.begin(8); 
  Wire.onRequest(requestEvent); 
  Serial.begin(9600);
}

void loop() {
  int lectura = analogRead(lm35Pin);
  temperatura = (lectura * 5.0 / 1023.0) * 100.0; 
  Serial.print("Temperatura: ");
  Serial.println(temperatura);
  
  delay(1000);
}

void requestEvent() {
  String tempStr = String(temperatura, 2);
  Wire.write(tempStr.c_str()); //Envía la temperatura como cadena de caracteres
}


