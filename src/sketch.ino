#include <DHT.h>
#include <LiquidCrystal_I2C.h>


#define DHTPIN 15          
#define DHTTYPE DHT22    
#define POT_PIN 34         
#define BUZZER_PIN 13      
#define LED_PIN 2         

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  dht.begin();
  
  lcd.init();
  lcd.backlight();

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  

  lcd.setCursor(0, 0);
  lcd.print("EV BATT SYSTEM");
  lcd.setCursor(0, 1);
  lcd.print("INITIALIZING...");
  delay(2000);
  lcd.clear();
}

void loop() {
  float t = dht.readTemperature(); 
  int potVal = analogRead(POT_PIN); 
  
  int batPersen = map(potVal, 0, 4095, 0, 100);

  lcd.setCursor(0, 0);
  lcd.print("Baterai: "); 
  lcd.print(batPersen); 
  lcd.print("%   "); 

  
  if (batPersen < 20) {
    digitalWrite(LED_PIN, HIGH); 
    lcd.setCursor(0, 1);
    lcd.print("CARI SPKLU!!  "); 
  } 

  else if (t > 45.0) {
    digitalWrite(LED_PIN, LOW);
    lcd.setCursor(0, 1);
    lcd.print("TEMP: "); lcd.print(t, 1); lcd.print("C HOT!");
    tone(BUZZER_PIN, 1000); 
  }
  else {
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);
    lcd.setCursor(0, 1);
    lcd.print("Suhu: "); 
    lcd.print(t, 1); 
    lcd.print("C Normal ");
  }

  Serial.print("Baterai: "); Serial.print(batPersen);
  Serial.print("% | Suhu: "); Serial.print(t); Serial.println("C");

  delay(500); 
}
