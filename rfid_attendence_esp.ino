#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN D8
#define RST_PIN D0
#define GREEN_LED_PIN D1  // Pin for green LED (correct UID)
#define RED_LED_PIN D2    // Pin for red LED (incorrect UID)

MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class

MFRC522::MIFARE_Key key;

// Define the correct UID for attendance (replace these values with your card's UID)
byte correctUID[4] = {0x79, 0x89, 0xD5, 0x00};

void setup() {
  Serial.begin(115200);
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522

  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  digitalWrite(GREEN_LED_PIN, LOW);
  digitalWrite(RED_LED_PIN, LOW);

  Serial.println(F("Attendance system ready. Please scan your card."));
}

void loop() {
  // Reset the loop if no new card is present on the sensor/reader
  if (!rfid.PICC_IsNewCardPresent()) return;

  // Verify if the NUID has been read
  if (!rfid.PICC_ReadCardSerial()) return;

  Serial.print(F("Scanned UID: "));
  printHex(rfid.uid.uidByte, rfid.uid.size);
  Serial.println();

  // Compare scanned UID with the correct UID
  bool correctCard = true;
  for (byte i = 0; i < 4; i++) {
    if (rfid.uid.uidByte[i] != correctUID[i]) {
      correctCard = false;
      break;
    }
  }

  // Attendance logic
  if (correctCard) {
    Serial.println(F("Access granted. Welcome!"));
    digitalWrite(GREEN_LED_PIN, HIGH);  // Turn on green LED
    digitalWrite(RED_LED_PIN, LOW);     // Turn off red LED
  } else {
    Serial.println(F("Access denied. Incorrect card."));
    digitalWrite(GREEN_LED_PIN, LOW);   // Turn off green LED
    digitalWrite(RED_LED_PIN, HIGH);    // Turn on red LED
  }

  delay(1000);  // Keep the LED on for 1 second
  digitalWrite(GREEN_LED_PIN, LOW);     // Turn off LEDs
  digitalWrite(RED_LED_PIN, LOW);

  // Halt PICC and stop encryption on PCD
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}

/**
   Helper routine to dump a byte array as hex values to Serial.
*/
void printHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}
