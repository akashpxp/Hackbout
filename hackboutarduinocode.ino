
char Incoming_value = 0;    
int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo
long duration, cm, inches;
unsigned long delayStart = 0; // the time the delay started
bool delayRunning = false;

//Variable for storing Incoming_value
void setup() 
{
  Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
  pinMode(13, OUTPUT);   
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);//Sets digital pin 13 as output pin
  unsigned long delayStart = 0; // the time the delay started
  bool delayRunning = false; // true if still waiting for delay to finish
  
}
void loop()
{
    int flag=1;
  if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();      //Read the incoming data and store it into variable Incoming_value
    //Serial.print(Incoming_value);        //Print Value of Incoming_value in Serial monitor
    if(Incoming_value == '1')
    {
    delayStart = millis();   // start delay
    delayRunning = true; // not finished yet
   while (((millis() - delayStart) <= 5000) && (flag==1))
    { // Serial.print("inside");

      
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration/2) / 29.1;     
  //Serial.print(cm);
  //Serial.print("cm");
  //Serial.println();
  delay(250);  
  if (cm<12){
    //print("found");
    Serial.write('1');
    flag=0;
  }
   }          

   if (flag==1){
    //Serial.print("not found");
       Serial.write('0');
   }

   }  
  }                            
}                
