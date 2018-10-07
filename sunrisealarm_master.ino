// This #include statement was automatically added by the Spark IDE.
#include "TimeAlarms/TimeAlarms.h"

#define ledPin D7
#define redPin A0
#define greenPin A1
#define bluePin A5

int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated
int r = 0;
int g = 0;
int b = 0;    
char pubstring[64];

int redList[] = {  0,8,17,26,35,43,52,61,70,79,87,96,105,114,123,131,140,149,158,167,175,184,193,202,211,219,228,237,246,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,253,253,252,252,251,250,250,249,249,248,247,247,246,246,245,245,244,243,243,242,242,241,240,240,239,239,238,237,237,236,236,235,235,234,233,233,232,232,231,230,230,229,229,228,228,227,226,226,225,225,224,223,223,222,222,221,220,220,219,219,218,218,217,216,216,215,215,214,213,213,212,212,211,211,210,209,209,208,208,207,206,206,205,205,204,203,203,202,202,201,201,200,199,199,198,198,197,196,196,195,195,194,193,193,192,192,191,191,190,189,189,188,188,187,186,186,185,185,184,184,183,182,182,181,181,180,179,179,178,178,177,176,176,175,175,174,174,173,172,172,171,171,170,169,169,168,168,167,167,166,165,165,164,164,163,162,162,161,161,160,159,159,158,158,157,157,156,155,155,154,154,153,152,152,151,151,150,150,149,148,147,146,145,144,142,141,140,139,138,137,136,135,134,133,132,131,130,129,128
};
int greenList[] = {  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,4,6,8,10,13,15,17,19,21,23,26,28,30,32,34,36,39,41,43,45,47,49,52,54,56,58,60,62,65,67,69,71,73,75,78,80,82,84,86,88,91,93,95,97,99,101,104,106,108,110,112,114,117,119,121,123,125,128,128,130,132,135,137,140,142,145,147,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,149,148,147,146,145,144,142,141,140,139,138,137,136,135,134,133,132,131,130,129,128
};
int blueList[] = {  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,3,5,6,7,9,10,11,12,14,15,16,18,19,20,22,23,24,25,27,28,29,31,32,33,34,36,37,38,40,41,42,44,45,46,47,49,50,51,53,54,55,57,58,59,60,62,63,64,66,67,68,69,71,72,73,75,76,77,79,80,81,82,84,85,86,88,89,90,92,93,94,95,97,98,99,101,102,103,104,106,107,108,110,111,112,114,115,116,117,119,120,121,123,124,125,127,128,129,130,132,133,134,136,137,138,139,141,142,143,145,146,147,149,150,151,152,154,155,156,158,159,160,162,163,164,165,167,168,169,171,172,173,174,176,177,178,180,181,182,184,185,186,187,189,190,191,193,194,195,197,198,199,200,202,203,204,206,207,208,209,211,212,213,215,216,217,219,220,221,222,224,225,226,228,229,230,232,233,234,235,236,237,238,240,241,242,243,244,245,246,247,248,249,250,251,252,253,255
};

int x = 0;
int duration = 6000;

//300 color values times "duration" milliseconds is the time the sunrise goes for.
//The sunset is set to 1/6 of that time. At 6000ms this will take 30mins for a sunrise,
//and 5mins for a sunset. This value can be changed by the slider on the webpage, 
//from 0 to 6000.

void setup() {
    
    Time.zone(+2); //Amsterdam, Paris, stuff like that...
    
    // create the alarms 
    Alarm.alarmRepeat(8,15,0, MorningAlarm);  // 8:15am every day
    Alarm.alarmRepeat(9,15,0, MorningOffAlarm);  // 9:15pm every day 
    
    Serial.begin(9600);                                                                         
   
    pinMode(ledPin, OUTPUT);
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
  
    RGB.control(true);                                                                          
    RGB.color(255,0,0);                                                                        
    myDelay(200);                                                                                   
    RGB.color(0,0,0);                                                                           
    myDelay(200);                                                                               
    RGB.color(0,0,255);                                                                         
    myDelay(200);                                                                              
    
    pubcolor();
    
    Spark.function("params", handleParams);                                                     
}

void loop() {
  digitalClockDisplay();
  Alarm.delay(1000); // wait one second between clock display
}


int handleParams(String command)
{                                                                                              
    int p = 0;                                                                                 
    while (p<(int)command.length()) {                                                           
        int i = command.indexOf(',',p);                                                     
        if (i<0) i = command.length();                                                         
        int j = command.indexOf('=',p);
        if (j<0) break;
        String key = command.substring(p,j);
        String value = command.substring(j+1,i);
        int val = value.toInt();
    
        	if (key=="r"){                                                               
                r = val;                                                                      
                Serial.println('Set red value');   
            } 
        	  
            else if (key=="g"){                                                       
                g = val;                                                                   
        	    Serial.println('Set green value');
        	}  
            
        	else if (key=="b"){                                                        
                b = val;                                                                    
        	    Serial.println('Set blue value');
        	}  
        	
        	else if (key == "GetColor"){
        	    //Just doing this to get the colors published.
            }
            
            else if (key == "duration"){
                //change the duration of the sunrise/sunset.
                duration = val;
            }
            else if (key == "sunrise"){
                //execute sunrise.
                sunrise();
            }
            else if (key == "sunset"){
                //execute sunset.
                sunset();
            }
        p = i+1;
    }
    //change colors to said values.
    color(r, g, b);
    //publish colors.
    pubcolor();
}
 
// duration is delay time in milliseconds
void myDelay(unsigned long duration)
{
  unsigned long start = millis();
  while (millis() - start <= duration)
  {
    blink(100);  // blink the LED inside the while loop
  }
}
    
    
// interval is the time that the LED is on and off
void blink(long interval)
{
  if (millis() - previousMillis > interval)
  {
    // save the last time you blinked the LED
    previousMillis = millis();
    // if the LED is off turn it on and vice versa:
    if (ledState == LOW)
      ledState = HIGH;    
    else
      ledState = LOW;
    digitalWrite(ledPin, ledState);
  }
}

//set the colors all at once, usefull as shorthand.
void color (unsigned char r, unsigned char g, unsigned char b){     
    analogWrite(redPin, r);     
    analogWrite(greenPin, g);
    analogWrite(bluePin, b);
    RGB.color(r, g, b);
};

//Convert color values to JSON string and publish them.
void pubcolor(){
    sprintf(pubstring,"{\"r\": %u, \"g\": %u, \"b\": %u}",r,g,b);         
    Spark.publish("color_values",pubstring);                                                
    Serial.println(String(pubstring));                                                     
};

//Sunrise function. Walks through the arrays.
void sunrise(){
    for (x = 0; x < 300; x++){
    	r = redList[x];
    	g = greenList[x];
    	b = blueList[x];
    	myDelay(duration);
    	color(r, g, b);
    };
}

//Sunset function. Walks through the arrays.
void sunset(){
    for (x = 0; x < 301; x++){
    	r = redList[300-x];
    	g = greenList[300-x];
    	b = blueList[300-x];
    	myDelay(duration/6);
    	color(r, g, b);
    };
}

//======================== ALARMS ===========================
// functions to be called when an alarm triggers:
void MorningAlarm(){
  Serial.println("Alarm: - turn lights on");
  RGB.color(255,0,0);                                                                        
  myDelay(200);                                                                                   
  RGB.color(0,0,0);                                                                           
  myDelay(200);                                                                               
  RGB.color(0,0,255);                                                                         
  myDelay(200);   
  
  sunrise();
};

void MorningOffAlarm(){
  Serial.println("Alarm: - turn lights off");  
  r = 0;
  g = 0;
  b = 0;
  color(r, g, b);
  RGB.color(r,g,b);
  
};

void digitalClockDisplay()
{
  // digital clock display of the time
  Serial.print(Time.hour());
  printDigits(Time.minute());
  printDigits(Time.second());
  Serial.println(); 
};

void printDigits(int digits)
{
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
};