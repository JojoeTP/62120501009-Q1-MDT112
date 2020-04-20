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
    for(led = 3 ; led <= 13 ; led++){//ไล่ขึ้น
        if(led == 8){
            digitalWrite(led,0);
            continue;
        }
        digitalWrite(led,1);
        delay(time);
        digitalWrite(led,0);

        if ( digitalRead(2) == 0 ){
            // do noting
            
            count = count * 2;
            Serial.println("Faster X 2 (Current Speed : X" + String(count) + ")");
            tone(8,400,100);
            time = time / 2;
            delay(700);
        }
        else  {
        }

    }
    for(led = 13 ; led >= 3 ; led--){//ไล่ลง
        if(led == 8){
            digitalWrite(led,0);
            continue;
        }
        digitalWrite(led,1);
        delay(time);
        digitalWrite(led,0);

        if ( digitalRead(2) == 0 ){
            // do noting
            if( digitalRead(2) == 0 ){
            
            count = count * 2;
            Serial.println("Faster X 2 (Current Speed : X" + String(count) + ")");
            tone(8,400,100);
            time = time / 2;
            delay(700);
            
            }
        }
        else  {
            
        }
    }
}