//Bird trap test

#include <IRremote.h>

int ActuatorF = 11;
int ActuatorR = 10;
int val = Serial.read();
int RECV_PIN = 7; 
IRrecv irrecv(RECV_PIN);
decode_results results;

  void setup(){
      pinMode(ActuatorF, OUTPUT);
      pinMode(ActuatorR, OUTPUT);
    digitalWrite(ActuatorF, LOW);
      digitalWrite(ActuatorR, LOW);
      Serial.begin(9600);
      irrecv.enableIRIn();
    }

  void loop(){
    
        if (irrecv.decode(&results))
        {
         Serial.println(results.value, DEC);
         digitalWrite(ActuatorF, HIGH); //forwards
         digitalWrite(ActuatorR, LOW);
        }
       else 
       { digitalWrite(ActuatorF, LOW); //backwards
         digitalWrite(ActuatorR, HIGH);
       }
  }


