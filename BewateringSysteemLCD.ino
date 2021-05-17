/*
  Jan Moeskops - mei 2021
  Deze code is gebaseerd op 
  https://github.com/TeamScheire/WateringStation/tree/master/wateringstation-arduino
  https://github.com/moeskopsjan
  
 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Servomotor is verbonden met pin 9
 Een moisture sensor is vervangen door potmeter op pin A0



 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// library en settings voor servomotor
#include <Servo.h>
Servo wateringServo;
#define moisturePin A0

const int minMoisturelevel = 100;  // De minimum waarde instellen

const int ServoPosStart = 180;
const int ServoPosWatering = 90;
const int ServoPin = 9;       // Digitale pin voor de sturing van servo

int moistureLevel;

//--------------------------- s e t u p --------------------------
void setup() 
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("H2O-systeem");
  delay(2000);
  lcd.clear();
  Serial.begin(9600);
  pinMode(moisturePin, INPUT);
  initServo();   // procedure om servo klaar te zetten
}


// ---------------------------- l o o p ---------------------------
void loop() 
{
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  measureMoistureLevel();
  lcd.setCursor(0,0);
  lcd.print("Vochtigheid:");
  lcd.print(moistureLevel);
  lcd.print("  ");
  
  if (moistureLevel < minMoisturelevel) 
  {
    lcd.setCursor(0,1);
    lcd.print("!!!! DORST !!!!");
    wateringSequence();
    lcd.setCursor(0,1);
    
  }
  lcd.setCursor(0,1);
  lcd.print("Dank voor H2O");
  delay(2000);   // een beetje tijd om het water te verspreiden
}

// -------------------------- init servo ---------------
void initServo() 
{
  wateringServo.attach(ServoPin);
  Serial.println("Initialising Servo ...");
  lcd.setCursor(0,0);
  lcd.print("Init.servo");
  wateringServo.write(ServoPosStart);
  delay(500);
  Serial.println("done");
  lcd.setCursor(0,0);
  lcd.print("Done      ");
  delay(1000);
  lcd.clear();
  wateringServo.detach();
}

// -------------------------- meet vochtigheid ---------------
void measureMoistureLevel() 
{
  moistureLevel = analogRead(moisturePin);
  Serial.print("moisture level: ");
  Serial.println(moistureLevel);  
}

// -------------------------- Geef water ---------------
void wateringSequence() 
{
  wateringServo.attach(ServoPin);
  wateringServo.write(ServoPosWatering);
  delay(2500); // geef het rietje de tijd om leeg te lopen
  wateringServo.write(ServoPosStart);
  delay(2000); // geef het rietje de tijd om terug vol te lopen
  wateringServo.detach();
}  
