// AP2 - Codigo 2: juego de luces interactivo
constexpr uint8_t LEDS[] = {16, 17, 18, 19};
constexpr uint8_t N_LEDS = sizeof(LEDS) / sizeof(LEDS[0]);
constexpr uint8_t PIN_BTN = 21;
constexpr uint32_t T_REBOTE = 30;
constexpr uint32_t PERIODOS[] = {400, 150, 60};
constexpr uint8_t N_VEL = sizeof(PERIODOS) / sizeof(PERIODOS[0]);

uint8_t posicion = 0;
uint8_t velocidad = 0;
uint32_t tPaso = 0;

bool lecturaAnterior = HIGH;
bool estadoEstable = HIGH;
uint32_t tUltimoCambio = 0;

bool botonPresionado() {
  bool lectura = digitalRead(PIN_BTN);

  if (lectura != lecturaAnterior) {
    tUltimoCambio = millis();
    lecturaAnterior = lectura;
  }

  if ((millis() - tUltimoCambio) >= T_REBOTE && lectura != estadoEstable) {
    estadoEstable = lectura;
    return estadoEstable == LOW;
  }
  return false;
}

void setup() {
  Serial.begin(115200);
  for (uint8_t i = 0; i < N_LEDS; i++) {
    pinMode(LEDS[i], OUTPUT);
  }
  pinMode(PIN_BTN, INPUT_PULLUP);
  Serial.println("AP2 lista. Presiona el pulsador.");
}

void loop() {
  if (botonPresionado()) {
    velocidad = (velocidad + 1) % N_VEL;
    Serial.print("Periodo: ");
    Serial.print(PERIODOS[velocidad]);
    Serial.println(" ms");
  }

  uint32_t ahora = millis();
  if (ahora - tPaso >= PERIODOS[velocidad]) {
    tPaso = ahora;
    posicion = (posicion + 1) % N_LEDS;
  }

  for (uint8_t i = 0; i < N_LEDS; i++) {
    digitalWrite(LEDS[i], i == posicion);
  }
}
