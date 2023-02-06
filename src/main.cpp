#include <Arduino.h>
#include <Bounce2.h>
#define BUTTON 27
#define RED 26
#define YELLOW 25
#define GREEN 33
#define LDR 32

int count = 0;
Bounce debouncer = Bounce();

void setup() {
    Serial.begin(115200);
    Serial.println("");
    Serial.println("LDR");
    debouncer.attach(BUTTON, INPUT_PULLUP);
    debouncer.interval(25); 
    ledcSetup(0, 5000, 8);
    ledcAttachPin(GREEN, 0);
    ledcSetup(1, 5000, 8);
    ledcAttachPin(RED, 1);
    ledcSetup(2, 5000, 8);
    ledcAttachPin(YELLOW, 2);
}

void loop() {
    debouncer.update();

    
    int Light = map(analogRead(LDR),500,3600,0,255);
    if ( debouncer.fell() ) { //.rose() กดแล้วปล่อยถึงติด
        count++;
    }
    if(count==1){
      ledcWrite(0,Light);
    }
    else if(count==2){
      ledcWrite(2,Light);
      ledcWrite(0,0);
    }
    else if(count==3){
      ledcWrite(0,Light);
      ledcWrite(2,Light);
    }
    else if(count==4){
      ledcWrite(2,0);
      ledcWrite(0,0);
      ledcWrite(1,Light);
    }
    else if(count==5){
      ledcWrite(0,Light);
      ledcWrite(1,Light);
    }
    else if(count==6){
      ledcWrite(0,0);
      ledcWrite(1,Light);
      ledcWrite(2,Light);
    }
    else if(count==7){
      ledcWrite(0,Light);
      ledcWrite(1,Light);
      ledcWrite(2,Light);
    }
    else if (count==8){
      ledcWrite(1,0);
      ledcWrite(2,0);
      ledcWrite(0,0);
      count=0;
    }      
}
