#include <Arduino.h>
#include <Bounce2.h>
#define BUTTON 27
#define RED 26
#define YELLOW 25
#define GREEN 33
#define LDR 34
int count = 0;
Bounce debouncer = Bounce();

void setup() {
    Serial.begin(115200);
    Serial.println("");
    debouncer.attach(BUTTON, INPUT_PULLUP);
    debouncer.interval(25); 
}

void loop() {
    debouncer.update();
    light = map(analogRead(LDR),700,3600,0,255); 
    if ( debouncer.fell() ) { 
        count++;}
        if (count%8==0) {
          digitalWrite(RED,0);
          digitalWrite(YELLOW,0);
          digitalWrite(GREEN,0);
        } else if(count%8==1) {
          digitalWrite(GREEN,light);
        } else if(count%8==2) {
          digitalWrite(YELLOW,light);
          digitalWrite(GREEN,0);
        } else if(count%8==3) {
          digitalWrite(GREEN,light);
        } else if(count%8==4) {
          digitalWrite(RED,light);
          digitalWrite(YELLOW,0);
          digitalWrite(GREEN,0);
        } else if(count%8==5) {
          digitalWrite(GREEN,light);
        } else if(count%8==6) {
          digitalWrite(YELLOW,light);
          digitalWrite(GREEN,0);
        } else if(count%8==7) {
          digitalWrite(GREEN,light);
        }
    
}
