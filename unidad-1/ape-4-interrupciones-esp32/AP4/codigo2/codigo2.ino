// AP4 - Código 2: sensor de puerta por INTERRUPCIÓN EXTERNA
const uint8_t  PIN_PUERTA = 21;   // pulsador = sensor de puerta
const uint8_t  PIN_LED    = 19;   // luz de alarma
const uint32_t T_REBOTE   = 50;   // ms. Parte B: probar con 0 y con 50

volatile bool     alerta = false; // bandera: la usan la ISR y el loop
volatile uint32_t eventos = 0;    // contador: lo usan la ISR y el loop
uint32_t tUltimo = 0;             // solo lo usa la ISR

// ISR: corta, en IRAM, sin Serial ni delay
void IRAM_ATTR isrPuerta() {
  uint32_t ahora = millis();
  if (ahora - tUltimo >= T_REBOTE) {   // antirrebote
    eventos++;
    alerta = true;                     // levanta la bandera
    tUltimo = ahora;
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_PUERTA, INPUT_PULLUP);   // 1.º el pin
  attachInterrupt(digitalPinToInterrupt(PIN_PUERTA),
                  isrPuerta, FALLING); // 2.º la interrupción
  Serial.print("Codigo 2: interrupcion, T_REBOTE = ");
  Serial.println(T_REBOTE);
}

void loop() {
  if (alerta) {                        // ¿está levantada la bandera?
    alerta = false;                    // bajarla
    digitalWrite(PIN_LED, !digitalRead(PIN_LED));
    Serial.print("¡Alerta! Puerta abierta. Eventos: ");
    Serial.println(eventos);           // el trabajo lento va en el loop
  }
  delay(2000);    // programa ocupado: el pulsador lo vigila el hardware
}
