// C++ code

void setup() {
  pinMode(12, OUTPUT); // Configurar el pin 12 como salida para el LED rojo
  pinMode(13, OUTPUT); // Configurar el pin 13 como salida para el LED verde
}

void loop() {
  digitalWrite(12, HIGH); // Encender el LED rojo
  digitalWrite(13, LOW); // Apagar el LED verde
  delay(1500); // Esperar 1.5 segundos
  
  digitalWrite(12, LOW); // Apagar el LED rojo
  digitalWrite(13, HIGH); // Encender el LED verde
  delay(1500); // Esperar 1.5 segundos
}
