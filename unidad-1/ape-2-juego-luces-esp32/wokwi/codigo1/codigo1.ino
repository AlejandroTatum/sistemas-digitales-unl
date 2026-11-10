// AP2 - Codigo 1: secuencia de 4 LEDs sin delay()
constexpr uint8_t LEDS[] = {16, 17, 18, 19};
constexpr uint8_t N_LEDS = sizeof(LEDS) / sizeof(LEDS[0]);
constexpr uint32_t PERIODO = 300;

uint8_t posicion = 0;
uint32_t tPaso = 0;

void setup() {
  for (uint8_t i = 0; i < N_LEDS; i++) {
    pinMode(LEDS[i], OUTPUT);
  }
}

void loop() {
  uint32_t ahora = millis();

  if (ahora - tPaso >= PERIODO) {
    tPaso = ahora;
    posicion = (posicion + 1) % N_LEDS;
  }

  for (uint8_t i = 0; i < N_LEDS; i++) {
    digitalWrite(LEDS[i], i == posicion);
  }
}
