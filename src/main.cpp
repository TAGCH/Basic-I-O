#include <Arduino.h>
#include <Bounce2.h>
#define BUTTON 27
#define RED 26
#define YELLOW 25
#define GREEN 33

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
    if ( debouncer.fell() ) { 
        count++;
        if (count==0){
          
        }
        else if(count==1){
          digitalWrite(GREEN,1);
        }
        else if(count==2){
          digitalWrite(YELLOW,1);
          digitalWrite(GREEN,0);
        }
    }
}