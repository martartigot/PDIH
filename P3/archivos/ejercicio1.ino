// C++ code
//
void setup() {
  pinMode(11, OUTPUT); // Configurar el pin 11 como salida para el LED rojo
  pinMode(12, OUTPUT); // Configurar el pin 12 como salida para el LED amarillo
  pinMode(13, OUTPUT); // Configurar el pin 13 como salida para el LED verde
}

void loop() {
  digitalWrite(11, HIGH); // Encender el LED rojo
  digitalWrite(12, LOW); // Apagar el LED amarillo
  digitalWrite(13, LOW); // Apagar el LED verde
  delay(1500); // Esperar 1.5 segundos
  
  digitalWrite(11, LOW); // Apagar el LED rojo
  digitalWrite(12, HIGH); // Encender el LED amarillo
  digitalWrite(13, LOW); // Apagar el LED verde
  delay(1500); // Esperar 1.5 segundos
  
  digitalWrite(11, LOW); // Apagar el LED rojo
  digitalWrite(12, LOW); // Apagar el LED amarillo
  digitalWrite(13, HIGH); // Encender el LED verde
  delay(1500); // Esperar 1.5 segundos
}