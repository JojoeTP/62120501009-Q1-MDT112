void setup(){
    pinMode(2,INPUT_PULLUP);
    Serial.begin(9600);
    for(int led = 3 ; led <= 13 ;led++){
        pinMode(led,OUTPUT);
    }
    tone(8,200,500);
    delay(250);
    tone(8,400,100);
    
}

int led = 3,time = 100,count = 1;

void loop(){
    for(led = 3 ; led <= 13 ; led++){
        if(led == 8){
            digitalWrite(led,0);
            continue;
        }
        digitalWrite(led,1);
        delay(time);
        digitalWrite(led,0);
        
        int press = 0;
        while ( digitalRead(2) == 0 ){
            press = press + 1;
            delay(100);
            if(press<=1){
                delay(100);
                count = count * 2;
                Serial.println("Faster X 2 (Current Speed : X" + String(count) + ")");
                tone(8,400,100);
                time = time / 2;
            }
        } 
    }
    for(led = 13 ; led >= 3 ; led--){
        if(led == 8){
            digitalWrite(led,0);
            continue;
        }
        digitalWrite(led,1);
        delay(time);
        digitalWrite(led,0);
        
        int press = 0;
        while ( digitalRead(2) == 0 ){
            press = press + 1;
            delay(100);
            if(press<=1){
                delay(100);
                count = count * 2;
                Serial.println("Faster X 2 (Current Speed : X" + String(count) + ")");
                tone(8,400,100);
                time = time / 2;
            }
        } 
    }
}