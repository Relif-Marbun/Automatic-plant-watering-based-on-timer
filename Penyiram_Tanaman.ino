#include <Wire.h>
#include <DS3231.h> //mengincludekan library DS3231
#include <LiquidCrystal_I2C.h>

DS3231  rtc(SDA, SCL); // inisialisasi penggunaan i2c
Time t;
LiquidCrystal_I2C lcd(0x27, 16, 2);

int jam; int menit; int detik; int relay = 2;

void setup() {
  Serial.begin(115200);
  pinMode(relay, OUTPUT);
  rtc.begin();
//    rtc.setDate(26, 5, 2023);   //mensetting tanggal 07 april 2018
//    rtc.setTime(12, 22, 00);     //menset jam 22:00:00
  //  rtc.setDOW(5);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0); lcd.print("==WELCOME TO==");
  lcd.setCursor(2, 1); lcd.print("OUR SYSTEM");
  delay(2000);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print("DATE: "); lcd.setCursor(6, 0); lcd.print(rtc.getDateStr()); //prosedur pembacaan hari
  lcd.setCursor(0, 1); lcd.print("TIME: "); lcd.setCursor(6, 1); lcd.print(rtc.getTimeStr()); //prosedur pembacaan tanggal
  t = rtc.getTime();
  jam = t.hour;
  menit = t.min;
  detik = t.sec;
  if (jam == 13 && menit == 17   && detik == 00 ) {
    Serial.println("Siramm");
    digitalWrite(relay, LOW);
    delay(10000);
    digitalWrite(relay, HIGH); 
  }
  else {
    digitalWrite(relay, HIGH);
  }
  if (jam == 13 && menit == 19 && detik == 00 ) {
    Serial.println("Siramm");
    digitalWrite(relay, LOW);
    delay(10000);
    digitalWrite(relay, HIGH); 
  }
  else {
    digitalWrite(relay, HIGH);
  }

  delay(1000);
  Serial.print(rtc.getDOWStr()); //prosedur pembacaan hari
  Serial.print(", ");
  Serial.print(rtc.getDateStr()); //prosedur pembacaan tanggal
  Serial.println("");
  Serial.println(rtc.getTimeStr()); //prosedur pembacaan waktu
}
