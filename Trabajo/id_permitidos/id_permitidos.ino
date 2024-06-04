#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 5
#define SS_PIN 53

MFRC522 mfrc522(SS_PIN, RST_PIN); // Crear instancia MFRC522

// Lista de UID permitidos
byte allowedUIDs[][4] = {
  {0x27, 0xA4, 0x7F, 0x60}, // UID 1: 27 A4 7F 60
  //{0xA9, 0x75, 0xAD, 0x99}, // UID 2: A9 75 AD 99 (para acceso denegado)
};

void setup() {
  Serial.begin(9600);  // Inicializar comunicación serial con el PC
  while (!Serial);    // No hacer nada si no se abre el puerto serie

  SPI.begin();       // Iniciar bus SPI
  mfrc522.PCD_Init();  // Inicializar MFRC522

  delay(4);          // Retardo opcional para algunas placas
  mfrc522.PCD_DumpVersionToSerial(); // (Opcional) Mostrar detalles del lector

  Serial.println(F("Escanee PICC para verificar el acceso..."));
}

void loop() {
  // Restablecer el bucle si no hay una nueva tarjeta presente
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Seleccionar una tarjeta
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Verificar si el UID de la tarjeta está en la lista de permitidos
  bool isAllowed = false;
  for (int i = 0; i < sizeof(allowedUIDs) / sizeof(allowedUIDs[0]); i++) {
    if (memcmp(mfrc522.uid.uidByte, allowedUIDs[i], mfrc522.uid.size) == 0) {
      isAllowed = true;
      break;
    }
  }

  // Procesamiento según el acceso permitido
  if (isAllowed) {
    // UID permitido: proceder a la lectura o autenticación
    mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
    
  } else {
    // UID no permitido: denegar acceso
    Serial.print(F("Acceso denegado para UID: "));
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      Serial.print(mfrc522.uid.uidByte[i], HEX);
      if (i < mfrc522.uid.size - 1) {
        Serial.print(" ");
      }
    }
    Serial.println();
  }
}
