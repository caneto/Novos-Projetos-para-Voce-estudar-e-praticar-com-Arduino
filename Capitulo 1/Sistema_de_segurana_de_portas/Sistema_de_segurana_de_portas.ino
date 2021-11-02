#include "SPI.h"  
#include "MFRC522.h"  

#define SS_PIN 10  
#define RST_PIN 9  

int m=0,n=0;  

MFRC522 rfid(SS_PIN, RST_PIN);  
MFRC522::MIFARE_Key key;  

void setup() {  
   Serial.begin(9600);  
   SPI.begin();  
   rfid.PCD_Init();  
   pinMode(5, OUTPUT);  
   pinMode(6, OUTPUT);  
   pinMode(7, OUTPUT);  
}  

void loop() {  
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())  
     return;  
  // Serial.print(F("PICC type: "));  
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);  
  // Serial.println (rfid.PICC_GetTypeName(piccType)); 
  // Verifique se o PICC do tipo MIFARE clássico
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&  
     piccType != MFRC522::PICC_TYPE_MIFARE_1K &&  
     piccType != MFRC522::PICC_TYPE_MIFARE_4K) {  
     Serial.println(F("Sua tag não é do tipo MIFARE Classic."));  
     return;  
  }  
  String strID = "";  
  for (byte i = 0; i < 4; i++) {  
   strID += (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +  
   String(rfid.uid.uidByte[i], HEX) + (i!=3 ? ":" : "");  
  }  
  strID.toUpperCase();  
  Serial.print("Toque na tecla do cartão: ");  
  Serial.println(strID);  

  if(strID.indexOf("E0:68:F7:29")>=0)  // here you can replace your tag id 
  {  
    Serial.println("cartão aceito");    
    digitalWrite(5, HIGH);  
    digitalWrite(6, HIGH);  
    digitalWrite(7, LOW);  
    delay(3000);  
    digitalWrite(5, LOW);  
    digitalWrite(6,LOW);  
    digitalWrite(7, HIGH);  
  } else {  
    digitalWrite(5, LOW);  
    digitalWrite(6,LOW);  
    digitalWrite(7, HIGH);  
  }  
  
  if(strID.indexOf("D5:4A:B0:65")>=0)  // aqui você pode substituir seu id de tag
  {  
    Serial.println("Token aceito");  
    digitalWrite(A1, HIGH);  
    digitalWrite(A1, LOW);  
  } else {  
    digitalWrite(A1, LOW);  
  }  
  rfid.PICC_HaltA();  
  rfid.PCD_StopCrypto1();  
} 
