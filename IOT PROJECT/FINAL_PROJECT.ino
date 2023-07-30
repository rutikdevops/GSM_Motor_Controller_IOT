// Variable to store text message
String textMessage;
String textcall;

// Create a variable to store Leds state
String MotorState = "LOW";

// Motors connected to pin 9 and 10
const int Motorled = 9;
const int Motor = 10;
int redled = 7;
int greenled = 6;
const int buzzerPin = 5;
const int flamePin = 11;
int Flame = "HIGH";


void setup() {
 
  // Set leds as OUTPUT
  pinMode(Motorled, OUTPUT);
  pinMode(Motor, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(flamePin, INPUT);
  
  // By default the leds is on
  digitalWrite(Motorled, LOW);
  digitalWrite(Motor, LOW);
  
  // Initializing serial commmunication
  Serial.begin(19200);

  // Give time to your GSM shield log on to network
  delay(20000);

  // AT command to set SIM900 to SMS mode
  Serial.print("AT+CMGF=1\r"); 
  delay(100);
  // Set module to send SMS data to serial out upon receipt 
  Serial.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);
}



void loop(){
  
  if(Serial.available()>0){
    textMessage = Serial.readString(); 
    textMessage.toUpperCase();   
    delay(10);
  } 
 
  if(textMessage.indexOf("MOTORON")>=0){
    {
    // Turn on red led and save current state
    digitalWrite(Motorled, LOW);
    digitalWrite(Motor, LOW);
    MotorState = "ON"; 
    textMessage = "";   
    }
    delay(100); 
  tone(8,1100);
  delay(200);
  noTone(8);
  tone(8,1000);
  delay(200);
  noTone(8);
  tone(8,900);  
  delay(200);
  noTone(8);
  tone(8,800);
  delay(200);
  noTone(8);
  tone(8,700);
  delay(200);    
  tone(8,1100);
  delay(200);
  noTone(8);
  tone(8,1000);
  delay(200);
  noTone(8);
  tone(8,900);
  delay(200);
  noTone(8);
  tone(8,800);
  delay(200);
  noTone(8);
  tone(8,700);
  delay(200);
  noTone(8);
  tone(8,1100);
  delay(200);
  noTone(8);
  tone(8,1000);
  delay(200);
  noTone(8);
  tone(8,900);
  delay(200);
  noTone(8);
  tone(8,800);
  delay(200);
  noTone(8);
  tone(8,700);
  delay(200);
  noTone(8);
   }

   
  if(textMessage.indexOf("MOTOROFF")>=0){
    {
    // Turn off motoe and save current state
    digitalWrite(Motorled, HIGH);
    digitalWrite(Motor, HIGH);
    MotorState = "OFF"; 
    textMessage = ""; 
    }
    delay(100);
  tone(8,300);
  delay(300);
  noTone(8);
  tone(8,400);
  delay(300);
  noTone(8);
  tone(8,500);
  delay(300);
  noTone(8);
  tone(8,600);
  delay(300);
  noTone(8);
  tone(8,700);
  delay(300);
  noTone(8);
  tone(8,800);
  delay(300);
  noTone(8);
   }


   if(Serial.available()>0){
     Serial.println("ATD");
     delay(4000);
   {
    digitalWrite(Motorled, HIGH);
    digitalWrite(Motor, HIGH);
    MotorState = "OFF"; 
   }  
     if(Serial.available()>0){
     Serial.println("ATH");
     delay(4000);
     }
     delay(100);
   tone(8,300);
   delay(300);
   noTone(8);
   tone(8,400);
   delay(300);
   noTone(8);
   tone(8,500);
   delay(300);
   noTone(8);
   tone(8,600);
   delay(300);
   noTone(8);
   tone(8,700);
   delay(300);
   noTone(8);
   tone(8,800);
   delay(300);
   noTone(8);
    }  

 if(textMessage.indexOf("MOTORSTATE")>=0){
    String message = "GSM BASED WATER MOTOR CONTROL SYSTEM Hello Rutik your Motor is  " + MotorState;
    sendSMS(message);
    textMessage = "";
  } 

 Flame = digitalRead(flamePin);
   if (Flame== LOW)
   { 
     Serial.println("ATD9082309694;"); // ATD9082309694; semicolon should be at the last ;AT command that follows UART protocol;
     delay(1000);  // Delay of 1 second
     digitalWrite(buzzerPin, HIGH);
     digitalWrite(redled, HIGH);
     digitalWrite(greenled, LOW);
     Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     Serial.println("AT+CMGS=\"+919082309694\"\r"); // Replace x with mobile number
     Serial.println("ALERT !!! ALERT !!! ALERT !!!            FIRE IN THE MOTOR OR SYSTEM");// The SMS text you want to send
     Serial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
     //delay(100);  
  }
  else
  {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(redled, LOW);
    digitalWrite(greenled, HIGH);
  }   
}  


// Function that sends SMS
void sendSMS(String message){
  // AT command to set SIM900 to SMS mode
  Serial.print("AT+CMGF=1\r"); 
  delay(100);

  // REPLACE THE X's WITH THE RECIPIENT'S MOBILE NUMBER
  // USE INTERNATIONAL FORMAT CODE FOR MOBILE NUMBERS
  Serial.println("AT + CMGS = \"919082309694\""); 
  delay(100);
  // Send the SMS
  Serial.println(message); 
  delay(100);

  // End AT command with a ^Z, ASCII code 26
  Serial.println((char)26); 
  delay(100);
  Serial.println();
  // Give module time to send SMS
  delay(5000);  
}
