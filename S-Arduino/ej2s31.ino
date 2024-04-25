// C++ code

void setup() {
  pinMode(13, OUTPUT); // Configura el pin del LED como salida
  pinMode(7, INPUT); // Configura el pin del interruptor como entrada
}

void loop() {
  if ((digitalRead(7) == true)){ // Si el interruptor está encendido
  	digitalWrite(13, HIGH);   // Enciende el LED
  }else{
    digitalWrite(13, LOW);   // Apaga el LED
  }

}


