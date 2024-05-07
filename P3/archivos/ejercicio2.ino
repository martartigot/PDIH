// C++ code
//
void setup() {
  pinMode(11, OUTPUT); // Configura el pin 11 como salida para el LED rojo
  pinMode(12, OUTPUT); // Configura el pin 12 como salida para el LED amarillo
  pinMode(13, OUTPUT); // Configura el pin 13 como salida para el LED verde
  pinMode(7, INPUT); // Configura el pin del interruptor como entrada
}

void loop() {
  if ((digitalRead(7) == true)){ // Si el interruptor está encendido
  	digitalWrite(11, HIGH);   // Enciende el LED rojo
    digitalWrite(12, LOW);   // Apaga el LED amarillo
    digitalWrite(13, LOW);   // Apaga el LED verde
    
  }else{ // Si el interruptor está apagado
    digitalWrite(11, LOW);   // Apaga el LED rojo
    digitalWrite(12, HIGH);   // Enciende el LED amarillo
    digitalWrite(13, HIGH);   // Enciende el LED verde
  }

}


