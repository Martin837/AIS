#include <SoftwareSerial.h>
#include <Adafruit_Sensor.h>
#include <ArduinoJson.h>
#include <DHT.h>

//?sensores
#define Sensor1 A0
#define Sensor2 A1
#define Sensor3 A2
#define Sensor4 A3
#define Sensor5 A4
int Dht11 = 8;
int Ws = 3;

//?variables
float h1 = 0;
float h2 = 0;
float h3 = 0;
float h4 = 0;
float h5 = 0;
float threshold1l = 100;
float threshold2l = 110;
float threshold3l = 130;
float threshold4l = 160;
float threshold5l = 150;
float threshold1h = 180;
float threshold2h = 150;
float threshold3h = 180;
float threshold4h = 200;
float threshold5h = 190;
float temp = 0;

int fan = 7;
int manual = 6; 
int mn = 0;
int ecode = 0;
int s1 = 9;
int s2 = 10;
int s3 = 11;
int s4 = 12;
int s5 = 13;
bool s1s = 0;
bool s2s = 0;
bool s3s = 0;
bool s4s = 0;
bool s5s = 0;


bool agua = 0;

int l_error = 5;
int btn1 = 2;
int btn1s = 0;
int buzzer = 4;

//?RX pin, TX pin
SoftwareSerial s(0,1);

//?dht
#define DHTPIN 8
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup(){

    s.begin(115200);
    dht.begin();

    pinMode(btn1, INPUT);
    pinMode(manual, INPUT);
    pinMode(Ws, INPUT);
    pinMode(fan, OUTPUT);
    pinMode(l_error, OUTPUT);
    pinMode(s1, OUTPUT);
    pinMode(s2, OUTPUT);
    pinMode(s3, OUTPUT);
    pinMode(s4, OUTPUT);
    pinMode(s5, OUTPUT);
    pinMode(buzzer, OUTPUT);

    digitalWrite(l_error, LOW);
}

void humedad(){
    / ?Valores humedad
    for(int i = 0; i <= 100; i++){
        h1 = h1 + analogRead(Sensor1);
        delay(1);
        h1 = h1 / 100.00;

        h2 = h2 + analogRead(Sensor2);
        delay(1);
        h2 = h2 / 100.00;

        h3 = h3 + analogRead(Sensor3);
        delay(1);
        h3 = h3 / 100.00;

        h4 = h4 + analogRead(Sensor4);
        delay(1);
        h4 = h4 / 100.00;

        h5 = h5 + analogRead(Sensor5);
        delay(1);
        h5 = h5 / 100.00;                
    
   }        
}

void s1error(){
while(true){
    humedad();      
    digitalWrite(l_error, HIGH);
    btn1s = digitalRead(btn1);
    ecode = 1;
    Serial.println(h1);
    if(btn1s == 1){
        //? 0
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        
        delay(1500);

        //? 1
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);        
        Serial.println(ecode);
    }
    if(h1 < 1000){
      return; 
    }
    
}
}
void s2error(){
while(true){
    
    humedad();
    digitalWrite(l_error, HIGH);
    btn1s = digitalRead(btn1);
    ecode = 2;
    if(btn1s == 1){
        //? 0
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        
        delay(1500);

        //? 2
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);        
    }
    if(h2 < 1000){
      return;
    }
}
}

void s3error(){
while(true){  
    humedad();
    digitalWrite(l_error, HIGH);
    btn1s = digitalRead(btn1);
    ecode = 3;
    if(btn1s == 1){
        //? 0
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        
        delay(1500);

        //? 3
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);        
    }
       if(h3 < 1000){
        return;
       }
}
}

void s4error(){ 
while(true){
  humedad();
    digitalWrite(l_error, HIGH);
    btn1s = digitalRead(btn1);
    ecode = 4;
    if(btn1s == 1){
        //? 0
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        
        delay(1500);

        //? 4
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);        
    }
    if(h4 < 1000){
      return;
    }
}
}

void s5error(){
while(true){  
    humedad();
    digitalWrite(l_error, HIGH);
    btn1s = digitalRead(btn1);
    ecode = 5;
    if(btn1s == 1){
        //? 0
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        
        delay(1500);

        //? 5
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);        
    }
    if(h5 < 1000){
      return;
    }
}
}

void dhterror(){
while(true){ 
    digitalWrite(l_error, HIGH);
    btn1s = digitalRead(btn1);
    ecode = 6;
    if(btn1s == 1){
        //? 0
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        
        delay(1500);

        //? 6
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        delay(300);
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);        
    }
    if(temp < 40){
      return;
    }

}    
}    

void RA(){
  
    for(int i = 0; i <= 100; i++){
        h1 = h1 + analogRead(Sensor1);
        delay(1);
        h1 = h1 / 100.00;

        h2 = h2 + analogRead(Sensor2);
        delay(1);
        h2 = h2 / 100.00;

        h3 = h3 + analogRead(Sensor3);
        delay(1);
        h3 = h3 / 100.00;

        h4 = h4 + analogRead(Sensor4);
        delay(1);
        h4 = h4 / 100.00;

        h5 = h5 + analogRead(Sensor5);
        delay(1);
        h5 = h5 / 100.00;                
    }

    //?riego
    if(h1 < threshold1l){
        digitalWrite(s2, LOW);
        digitalWrite(s3, LOW);
        digitalWrite(s4, LOW);
        digitalWrite(s5, LOW);
        digitalWrite(s1, HIGH);
        while(true){
           agua = digitalRead(Ws);
           delay(10);

           if(agua == 0){   
              digitalWrite(s2, LOW);
              digitalWrite(s3, LOW);
              digitalWrite(s4, LOW);
              digitalWrite(s5, LOW);
              digitalWrite(s1, LOW);
              return;
           }                    
          humedad();
          if(h1 > threshold1h){
            digitalWrite(s1, LOW);
            s1s = 0;
            return;
          }
        }
    }
    if(h1 > 1000){
        s1error();
    }
    if(h1 >= threshold1h){
        digitalWrite(s1, LOW);
        s1s = 0;
    }
    Serial.println(h1);

    if(h2 < threshold2l && s1s == 0){
        digitalWrite(s1, LOW);
        digitalWrite(s3, LOW);
        digitalWrite(s4, LOW);
        digitalWrite(s5, LOW);
        digitalWrite(s2, HIGH);
        while(true){
           agua = digitalRead(Ws);
           delay(10);

           if(agua == 0){   
              digitalWrite(s2, LOW);
              digitalWrite(s3, LOW);
              digitalWrite(s4, LOW);
              digitalWrite(s5, LOW);
              digitalWrite(s1, LOW);
              return;
           }                    
          humedad();
          if(h2 > threshold2h){
            digitalWrite(s2, LOW);
            s2s = 0; 
            return;
          }
        }        
    }
    if(h2 > 1000){
        s2error();
    }
    if(h2 >= threshold2h){
        digitalWrite(s2, LOW);
        s2s = 0;
    }

    if(h3 < threshold3l && s2s == 0){
        digitalWrite(s2, LOW);
        digitalWrite(s1, LOW);
        digitalWrite(s4, LOW);
        digitalWrite(s5, LOW);
        digitalWrite(s3, HIGH);
        while(true){
           agua = digitalRead(Ws);
           delay(10);

           if(agua == 0){   
              digitalWrite(s2, LOW);
              digitalWrite(s3, LOW);
              digitalWrite(s4, LOW);
              digitalWrite(s5, LOW);
              digitalWrite(s1, LOW);
              return;
           }                    
          humedad();
          if(h3 > threshold3h){
            digitalWrite(s3, LOW);
            s3s = 0;
            return;
          }
        }    
    }
    if(h3 > 1000){
        s3error();
    }
    if(h3 >= threshold3h){
        digitalWrite(s3, LOW);
        s3s = 0;
    }

    if(h4 < threshold4l && s3s == 0){
        digitalWrite(s2, LOW);
        digitalWrite(s3, LOW);
        digitalWrite(s1, LOW);
        digitalWrite(s5, LOW);
        digitalWrite(s4, HIGH);
        while(true){
           agua = digitalRead(Ws);
           delay(10);

           if(agua == 0){   
              digitalWrite(s2, LOW);
              digitalWrite(s3, LOW);
              digitalWrite(s4, LOW);
              digitalWrite(s5, LOW);
              digitalWrite(s1, LOW);
           }                    
          humedad();
          if(h1 > threshold1h){
            digitalWrite(s4, LOW);
            s4s = 0;
            return;
          }
        }
    }
    if(h4 > 1000){
        s4error();
    }
    if(h4 >= threshold4h){
        digitalWrite(s4, LOW);
        s4s = 0;
    }

    if(h5 < threshold5l && s4s == 0){
        digitalWrite(s2, LOW);
        digitalWrite(s3, LOW);
        digitalWrite(s4, LOW);
        digitalWrite(s1, LOW);
        digitalWrite(s5, HIGH);
        while(true){
           agua = digitalRead(Ws);
           delay(10);

           if(agua == 0){   
              digitalWrite(s2, LOW);
              digitalWrite(s3, LOW);
              digitalWrite(s4, LOW);
              digitalWrite(s5, LOW);
              digitalWrite(s1, LOW);
              return;
           }          
          humedad();
          if(h5 > threshold5h){
            digitalWrite(s5, LOW);
            s5s = 0;
            return;
          }
        }    
    }
    if(h5 > 1000){
        s5error();
    }
    if(h5 >= threshold5h){
        digitalWrite(s5, LOW);
        s5s = 0;
    }            
    

}

void loop(){

    //?modo manual o automático 
    mn = digitalRead(manual); 
    //?Temperatura y ventilador
    digitalWrite(l_error, LOW);
    temp = dht.readTemperature();

    if(temp >= 30){
        digitalWrite(fan, HIGH);
    }
    else if(temp > 40){
      dhterror();
    }
    else{
        digitalWrite(fan, LOW);
    }

    //? Sensor de agua
    agua = digitalRead(Ws);
    delay(10);

    if(agua == 0){   
        digitalWrite(s2, LOW);
        digitalWrite(s3, LOW);
        digitalWrite(s4, LOW);
        digitalWrite(s5, LOW);
        digitalWrite(s1, LOW);
    }

    //?Comunicación con esp8266
   // StaticJsonDocument<1000> doc;
   // DeserializationError error = deserializeJson(doc, json);
     //   doc["agua"] = agua;
       // doc["error"] = ecode;
        //doc["humedad1"] = h1;
       // doc["humedad2"] = h2;
       // doc["humedad3"] = h3;
       // doc["humedad4"] = h4;
       // doc["humedad5"] = h5;
       // doc["manual"] = mn;
       // doc["sector1"] = s1s;
       // doc["sector2"] = s2s;
       // doc["sector3"] = s3s;
       // doc["sector4"] = s4s;
       // doc["sector5"] = s5s;
    
   // if(s.available()>0){
   //     doc.printTo(s);
   // }

    if(mn == 1){
        humedad();
    }
    else if (mn == 0 && agua == 1){
        RA();
    }
  Serial.println(ecode);

}
