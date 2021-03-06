#include <SoftwareSerial.h>

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10
#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme;

SoftwareSerial mySerial(3, 2); // RX, TX

unsigned long delayTime;
unsigned long temp;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  bool status;
   status = bme.begin();  //SDA:A4, SCL:A5
    if (!status) {
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
    }
  delayTime = 1000;


  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);

  temp = (unsigned long)bme.readTemperature();
  
  mySerial.write(bme.readTemperature());
  
}

void loop() { // run over and over

  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  } 
    mySerial.write(bme.readTemperature());
    delay(2000);
  
}
