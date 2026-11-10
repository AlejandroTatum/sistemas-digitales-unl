# APE 4 — Sensor de puerta con interrupciones externas en el ESP32

[← Volver a la Unidad 1](../../README.md)

Semana 4 · Un pulsador (sensor de puerta) y un LED (luz de alarma) detectan la apertura mediante una interrupción externa del ESP32. Se comprueba con mediciones por qué la interrupción no pierde eventos que el sondeo sí pierde y por qué hace falta el antirrebote.

## Circuito

Pulsador entre GPIO21 y GND con pull-up interna; LED en GPIO19 con resistencia de 330 Ω a GND.

## Contenido

| Carpeta | Contenido |
| --- | --- |
| [`documento/`](documento) | Informe entregado (PDF) y su fuente editable (`informe.md`). |
| [`AP4/codigo1/`](AP4/codigo1) | Código 1: detección por sondeo, con sus pruebas de Wokwi CLI. |
| [`AP4/codigo2/`](AP4/codigo2) | Código 2: detección por interrupción (`attachInterrupt`, ISR con `IRAM_ATTR`, `volatile` y patrón bandera), con `T_REBOTE = 0` y `T_REBOTE = 50`. |
| [`AP4/diagram.json`](AP4/diagram.json) | Circuito de Wokwi. |
| [`AP4/simulacion/`](AP4/simulacion) | Registros de las corridas en Wokwi CLI. |
| [`AP4/capturas/`](AP4/capturas) | Capturas del Monitor Serie. |
| [`AP4/placa/`](AP4/placa) | Foto del montaje en la placa real. |
