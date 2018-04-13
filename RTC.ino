#include <Wire.h>
#include "RTClib.h"//Libreria de reloj
RTC_DS1307 RTC;//Modelo Reloj

void setup() {
  Wire.begin();
  RTC.begin();//Inicializa el reloj
  RTC.adjust(DateTime(__DATE__, __TIME__));//obtine la hora del sistema
  Serial.begin(9600);//Inicializa el serial
}

void loop() {
  // put your main code here, to run repeatedly:

}
