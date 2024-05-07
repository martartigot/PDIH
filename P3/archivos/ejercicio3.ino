// C++ code
//

// Definimos los pines a los que están conectados los LEDs
const int ledPins[] = {13, 12, 11, 10}; 
const int numLEDs = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() {
  // Inicializamos los pines de los LEDs como salidas
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Encendemos y apagamos los LEDs secuencialmente hacia adelante
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], HIGH);  // Encendemos el LED
    delay(200);  // Esperamos un poco
    digitalWrite(ledPins[i], LOW);   // Apagamos el LED
  }
  
  // Encendemos y apagamos los LEDs secuencialmente hacia atrás
  for (int i = numLEDs - 2; i >= 0; i--) { // Empezamos desde el penúltimo LED
    digitalWrite(ledPins[i], HIGH);  // Encendemos el LED
    delay(200);  // Esperamos un poco
    digitalWrite(ledPins[i], LOW);   // Apagamos el LED
  }
}
