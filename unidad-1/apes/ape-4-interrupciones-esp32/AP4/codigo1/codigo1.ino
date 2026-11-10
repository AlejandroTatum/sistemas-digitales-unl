// AP4 - Código 1: sensor de puerta por SONDEO (polling)
const uint8_t PIN_PUERTA = 21;   // pulsador = sensor de puerta
const uint8_t PIN_LED    = 19;   // luz de alarma

uint32_t aperturas = 0;          // aperturas detectadas
int anterior = HIGH;             // con INPUT_PULLUP: suelto = HIGH

void setup() {
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_PUERTA, INPUT_PULLUP);
  Serial.println("Codigo 1: sondeo cada 2 s");
}

void loop() {
  int actual = digitalRead(PIN_PUERTA);       // ¿cómo está el pulsador AHORA?
  if (anterior == HIGH && actual == LOW) {    // pasó de suelto a presionado
    aperturas++;
    digitalWrite(PIN_LED, !digitalRead(PIN_LED));
    Serial.print("Puerta abierta. Aperturas: ");
    Serial.println(aperturas);
  }
  anterior = actual;
  delay(2000);    // programa ocupado: aquí NO se mira el pulsador
}
