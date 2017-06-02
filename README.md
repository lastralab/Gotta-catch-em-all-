# Gotta catch 'em all!

**Safe bird trap for research.**

These are the images from the 3D model (AutoCAD), based on the Yunick trap design for parakeets.

<img width="754" alt="screen shot 2016-11-10 at 2 02 40 pm" src="https://cloud.githubusercontent.com/assets/22894897/20194512/ce112846-a74f-11e6-92e3-7e0b57c12696.png">

The green box is for the Signal Receiver, Relay and battery.

<img width="965" alt="screen shot 2016-11-10 at 2 04 29 pm" src="https://cloud.githubusercontent.com/assets/22894897/20194509/ce0b6dac-a74f-11e6-929f-106f5d8ad491.png">

The blue box is for the actuator.  Once it's activated by the remote control the door will fall to trap the birds.

<img width="758" alt="screen shot 2016-11-11 at 10 28 05 am" src="https://cloud.githubusercontent.com/assets/22894897/20224033/a867fb9c-a7f9-11e6-9de8-ae2f08a6c396.png">

**The DIY remote control mechanism:**

<img width="891" alt="screenshot 2017-01-26 15 08 45" src="https://cloud.githubusercontent.com/assets/22894897/22352500/a62693f4-e3d9-11e6-8ea4-3f709d24f731.png">

**ESSENTIAL PARTS:**

Receiver & Relay 12VDC Module (IR or RF signal can be used)

Transmitter Control (buy one or make your own)

Solenoid 4.5V

12V Battery A23

Battery holder

The Fritzing Sketch can be used as a guide, just replace 9V with 12V battery, even if it works with 9V ('cause it does!), and working
with the module, the rest is easier because it already has the relay and the signal receiver in it, then you'll just
have to press a button to activate it. Modules are not in the Fritzing world, so I had to use separated components.

**Schematics:**

<img width="760" alt="screenshot 2017-01-26 15 50 49" src="https://cloud.githubusercontent.com/assets/22894897/22353767/4fcc05e2-e3df-11e6-8643-c9629233b5da.png">

**First prototype:**

![rf](https://cloud.githubusercontent.com/assets/22894897/22353963/40ffa644-e3e0-11e6-8583-06736c381c1a.gif)

I apologize for bad gif quality.

# Alternative option: Controlling cage through IR remote control and two SPDT relays:

![dcr](https://cloud.githubusercontent.com/assets/22894897/26065112/49ca8332-3969-11e7-903d-391ef67d7696.gif)

**Arduino Code:**

```C++
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

```
