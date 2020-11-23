/*
NOME DO PROJETO: SMART GLOVE
FEITO POR: BBB

THIS PROJECT READS SENSOR VALUE AND TRY TO UNDERSTAND SYMBOLS GENERATED FROM AMERICAN SIGN LANGUAGE (ASL) CHART
AND DISPLAY ON A SMARTPHONE.
-------PIN CONFIGURATION----------------
A0-A4 : FLEX SENSOR
D4&D5 : FOR BLUETOOTH RX AND TX
A5&A6 : XPIN AND YPIN FOR ACCELROMETER
*/

#include <SoftwareSerial.h>

SoftwareSerial mySerial(4,5);

char temp = '0';

int flex_pin1 = A0;
int data1 = 0;
int min1 = 0;
int max1 = 1023;

int flex_pin2 = A1;
int data2 = 0;
int min2 = 0;
int max2 = 1023;

int flex_pin3 = A2;
int data3 = 0;
int min3 = 0;
int max3 = 1023;

int flex_pin4 = A3;
int data4 = 0;
int min4 = 0;
int max4= 1023;

int flex_pin5 = A4;
int data5 = 0;
int min5 = 0;
int max5 = 1023;

void setup() {
  
  mySerial.begin(9600);
  
  pinMode(flex_pin1, INPUT);
  pinMode(flex_pin2, INPUT);
  pinMode(flex_pin3, INPUT);
  pinMode(flex_pin4, INPUT);
  pinMode(flex_pin5, INPUT);
}

void printfun(char cp){
  if(cp != temp){
    mySerial.println(cp);
    temp=cp;
  }
}

void loop() {
  float data1 = analogRead(flex_pin1);
  float data2 = analogRead(flex_pin2);
  float data3 = analogRead(flex_pin3);
  float data4 = analogRead(flex_pin4);
  float data5 = analogRead(flex_pin5);

if(((data1>=942)&&(data1<=944))&&((data2>=1005)&&(data2<=1013))&&((data3>=1005)&&(data3<=1013))&&((data4>=1006)&&(data4<=1013))&&((data5>=1009)&&(data5<=1014))){
    printfun('0'); 
}else if(((data1>=945)&&(data1<=965))&&((data2>=1011)&&(data2<=1014))&&((data3>=1010)&&(data3<=1018))&&((data4>=1009)&&(data4<=1018))&&((data5>=1014)&&(data5<=1019))){
    printfun('1');
}else if(((data1>=945)&&(data1<=965))&&((data2>=992)&&(data2<=1005))&&((data3>=1010)&&(data3<=1018))&&((data4>=1005)&&(data4<=1015))&&((data5>=1014)&&(data5<=1020))){
    printfun('2');
}else if(((data1>=949)&&(data1<=953))&&((data2>=992)&&(data2<=1003))&&((data3>=991)&&(data3<=1000))&&((data4>=996)&&(data4<=1003))&&((data5>=1014)&&(data5<=1030))){
    printfun('3');
}else if(((data1>=930)&&(data1<=945))&&((data2>=992)&&(data2<=1003))&&((data3>=990)&&(data3<=1000))&&((data4>=996)&&(data4<=1003))&&((data5>=1000)&&(data5<=1010))){
    printfun('4');
}
 
  delay(600);

}
