#include <SPI.h>
#include <SD.h>

const int chipSelect = 10;
const int output_pin = 8;
File dataFile;

void setup() {
  Serial.begin(115200);
  Serial.print("Initializingard...");
    
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    return;
  }

  pinMode(output_pin, OUTPUT);

  Serial.println("card initialized.");
  dataFile = SD.open("datalog.dat");

}

void loop() {

  int myData_read;
  
  for(int i = 0; i < 26; i++){
    myData_read = dataFile.read();
    for(int i=0; i < 8; i++){
      if((myData_read & (1<<i)) >> i){
        digitalWrite(output_pin, HIGH);
        delayMicroseconds(1);
      }
      else {
        digitalWrite(output_pin, LOW);
        delayMicroseconds(1);
      }
    }
  }

  //digitalWrite(output_pin, LOW);
  //delay(5000000);
}
