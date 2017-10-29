#include <SPI.h>
#include <SD.h>

const int chipSelect = 10;
File dataFile;

void setup() {
  Serial.begin(9600);
  Serial.print("Initializingard...");
    
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    return;
  }

  pinMode(8, OUTPUT);

  Serial.println("card initialized.");
  dataFile = SD.open("datalog.dat");

}

void loop() {

  int myData_read;
  
   for(int i = 0; i < 20; i++){
    myData_read = dataFile.read();
   // Serial.print(myData_read);
    for(int i=0; i < 8; i++){
      if((myData_read & (1<<i)) >> i){
        digitalWrite(8, HIGH);
        delay(10);
      }
      else {
        digitalWrite(8, LOW);
        delay(10);
      }
    }
  }
}
