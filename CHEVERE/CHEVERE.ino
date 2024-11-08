#include <Wire.h>

const int ledPin = 13;

void setup() {
  Wire.begin(); 
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Wire.requestFrom(8, 6); 
  String mensaje = "";
  
  while (Wire.available()) {
    char c = Wire.read();
    mensaje += c;
  }

  mensaje.trim();

  float temperatura = mensaje.toFloat();

  if (temperatura > 30) {
    digitalWrite(ledPin, HIGH); 
  } else {
    digitalWrite(ledPin, LOW);
  }
  
  Serial.println(temperatura);
  
  delay(1000); 
}


