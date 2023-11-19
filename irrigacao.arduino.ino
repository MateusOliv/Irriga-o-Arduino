/* Mateus Nunes TIA:21517762
 * Irrigação vertical com arduino
*/


#include "RTClib.h"

RTC_DS3231 rtc;
 
char daysOfTheWeek[7][12] = {"Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado"};

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int thisChar = 0 ;
int pinChuva = A0;
int valChuva = 0;
int IDproxima =0;
int temp=0;

int pinRele =8;

#define MY_SIZE 3
String anArray[MY_SIZE];

String stringTime;

void setup()
{
  Serial.begin(9600);
  pinMode(pinChuva,INPUT);
  pinMode(pinRele,OUTPUT);
  lcd.init();                      
  lcd.backlight();
  configRelogio();

  anArray[0] = "08:30";
  anArray[1] = "13:30";  
  anArray[2] = "17:00"; 

  digitalWrite(pinRele,HIGH);
}

int proximoH (int minAtual){
  for (int i=0;i<3;i++){
    int proxMin = (anArray[i].substring(0,2).toInt())*60 + int(anArray[i].substring(3,5).toInt());
    if (proxMin>=minAtual){
      return i;  
    } 
  }
  return 0;
}

void configRelogio(){
  if(! rtc.begin()) {
    while(1);
  }
  if(rtc.lostPower()){

    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  }
  delay(100);
  }

void updateDateNow(){
  lcd.setCursor(0, 0);           
  DateTime now = rtc.now(); 
  String stringDay = String(now.day(), DEC);
  lcd.print(confDois(stringDay));  
  lcd.print("/"); 
  String stringMonth = String(now.month(), DEC);
  lcd.print(confDois(stringMonth)); 
  lcd.print("/"); 
  String stringYear = String(now.year(), DEC);
  lcd.print(stringYear.substring(2,4)); 
  lcd.print(" - "); 
  String stringHour = String(now.hour(), DEC);
  lcd.print(confDois(stringHour)); 
  lcd.print(":"); 
  String stringMinute = String(now.minute(), DEC);
  lcd.print(confDois(stringMinute));  

  stringTime = confDois(stringHour)+":"+confDois(stringMinute);
  int agoraMin = stringHour.toInt()*60 + stringMinute.toInt();
  IDproxima = proximoH(agoraMin); 


  valChuva = analogRead(pinChuva);
  String stringValChuva =  String(valChuva);
  lcd.setCursor(0, 1);            
  lcd.print(confQuatro(stringValChuva));       
  lcd.setCursor(5,1);
  lcd.print("Prox: ");
  lcd.setCursor(11,1);
  String horaMinIrriga = String(anArray[IDproxima]);
  lcd.print(horaMinIrriga);

  Serial.print("proximo: ");
  Serial.println(String(anArray[IDproxima]));
  Serial.print("Atual: ");
  Serial.println(stringTime);
  
}

void Hello ()                     
{
  updateDateNow();

 if (String(anArray[IDproxima])==stringTime) 
   {
    Serial.println("Iniciando a irrigação"); 
      while (analogRead(pinChuva)>= 500)
      {

        Serial.println("Irrigando...");
        digitalWrite(pinRele,LOW);
        updateDateNow();
        delay(1000);
      } 
      digitalWrite(pinRele,HIGH);  
    }
  
}

String confDois(String in)
{
  String out ="";
  if ((in.length())==1){
  out="0"+in;
  }
  else
  {
    out = in;
  }
  return out;  
}

String confQuatro(String in)
{
  String out ="";
  if ((in.length())==1){
  out="000"+in;
  }
  else if ((in.length())==2) 
  {
     out="00"+in;
  }
   else if ((in.length())==3) 
  {
     out="0"+in;
  }
  else 
  {
    out = in;
  }
  return out;  
}

void loop()
{
  Hello ();  
  if (temp ==0)
  {
    Serial.println("Iniciando a irrigação"); 
      while (analogRead(pinChuva)>= 500)
      {
        Serial.println("Irrigando...");
        digitalWrite(pinRele,LOW);
        updateDateNow();
        delay(1000);
      } 
      digitalWrite(pinRele,HIGH); 
    }
  temp=1;  
  delay(1000);
}
