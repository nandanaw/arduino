#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define LIGHT_PIN 8

const int tiltPin = 6;
int tiltState = 0;
int prevTiltState = 0;
int reply; // defining variables

//messages to display when a player loses
String goodMessages[] = {"You're so smart!", "Galaxy Brain!", "400 IQ!", "A Smart Sister!", "Ms. Henderson??"};

void setup() {
  lcd.begin(16, 2);
  pinMode(tiltPin, INPUT);
  pinMode(LIGHT_PIN, OUTPUT);

  digitalWrite(LIGHT_PIN, LOW);

// intro sequence

  lcd.setCursor(5, 0);
  lcd.print("HELLO!");
  lcd.setCursor(0, 1);
  lcd.print("by zenaz and nan");
  delay(2500);
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("*Learn new");
  lcd.setCursor(5, 1);
  lcd.print("words*");
  delay(2500);
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("*Avoid the");
  lcd.setCursor(4, 1); 
  lcd.print("GOODBYE*");
  delay(2500);
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("READY?");
  delay(2500);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Tap to START");
  
  
}

void loop() {
  
    tiltState = digitalRead(tiltPin); //reads value from tilt sensor
    if (tiltState == HIGH){ // if the tilt sensor is reading a value
      reply = random(8); // sets int reply equal to a random integer from 0 to 8 (determines which language is displayed)
      int theWords = random(0, 5); // sets theWords equal to a random integer from 0 to 5 (determines which goodMessage is shown)
      lcd.clear();
      lcd.setCursor(0, 0);
      
      if(reply == 0){
        
        lcd.print("GOODBYE"); // player loses
        lcd.setCursor(0, 1);
        lcd.print(goodMessages[theWords]); //display the goodMessage in the array that is @ the position of int theWords

        digitalWrite(LIGHT_PIN, HIGH);

      }
               
      else if(reply == 1){ //display the language that corresponds to int reply
        
        lcd.print("Spanish:");
        lcd.setCursor(0, 1);
        lcd.print("Hola!");
        digitalWrite(LIGHT_PIN, LOW);
      }

      else if(reply == 2){
        lcd.print("French:");
        lcd.setCursor(0, 1);
        lcd.print("Bonjour!");
        digitalWrite(LIGHT_PIN, LOW);

      }

      else if(reply == 3){
        lcd.print("Italian:");
        lcd.setCursor(0, 1);
        lcd.print("Ciao!");
                digitalWrite(LIGHT_PIN, LOW);

      }
        
      else if(reply == 4){
        lcd.print("German:");
        lcd.setCursor(0, 1);
        lcd.print("Hallo!");
                digitalWrite(LIGHT_PIN, LOW);

      }
        
        
      else if(reply == 5){
        lcd.print("Japanese:");
        lcd.setCursor(0, 1);
        lcd.print("Konnichiwa!");
                digitalWrite(LIGHT_PIN, LOW);

      }
        

      else if(reply == 6){
        lcd.print("Korean:");
        lcd.setCursor(0, 1);
        lcd.print("Annyeonghaseyo!");
        digitalWrite(LIGHT_PIN, LOW);

      }
        
      else if(reply == 7){
        lcd.print("Mandarin:");
        lcd.setCursor(0, 1);
        lcd.print("Ni Hao!");
        digitalWrite(LIGHT_PIN, LOW);

      }

      else if(reply == 8){
        lcd.print("Portuguese");
        lcd.setCursor(0, 1);
        lcd.print("Ola!");
        digitalWrite(LIGHT_PIN, LOW);

      }  
   }

}
