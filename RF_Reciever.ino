void setup() {
    pinMode(5, OUTPUT);
    pinMode(6, INPUT);
    pinMode(7, OUTPUT);

    digitalWrite(5, HIGH);
    digitalWrite(7, LOW);
    
    Serial.begin(115200);
    delay(1500);
}

boolean last = false;
boolean temp = false;
int chain = 0;
int badchain = 0;
int max = 0;

int get(){
    return digitalRead(6);
}

void loop(){
    temp = get();
    
    if(temp == last){
        chain++;
    }
    else{
        if(chain >= 280 && chain <= 320){
            Serial.println(String(chain));
            last = temp;
            chain = 1;
            
            while(true){
                delay(0.5);
                temp = get();
    
                if(temp == last){
                    chain++;
                }
                else{
                    last = temp;
                    
                    Serial.println(String(chain));
                    
                    if(chain <= 5){
                        badchain++;
                        if(badchain > 34){
                            delay(250);
                            badchain = 0;
                            break;
                        }
                    }
                    if(chain >5){
                      badchain = 0;
                    }
                    if(chain >= 2700){
                        delay(250);
                        break;
                    }
                    chain = 1;
            
                }
            }
        }

        //Serial.println(chain);
        //Serial.println(String(temp) + ": " + String(chain));
        last = temp;
        chain = 1;
    }
  
    
  //  for(int i = 0; i < 1; i++){
  //    Serial.print(get());
  //  }
  //  Serial.println();

}









