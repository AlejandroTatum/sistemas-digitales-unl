# Apuntes — Unidad 1: Microcontroladores para sistemas embebidos

Resúmenes de las diapositivas de clase con diagramas de flujo para estudiar. Cada apunte sigue el orden de su presentación y trae resueltos los ejercicios y tickets de salida de la clase.

| Semana | Sesión | Tema | Apunte | Guía PDF |
| --- | --- | --- | --- | --- |
| 1 | 1 | Del computador al microcontrolador: CPU, buses, Von Neumann/Harvard, Flash/SRAM/EEPROM | [01](01-del-computador-al-microcontrolador.md) | [PDF](pdf/01-del-computador-al-microcontrolador.pdf) |
| 1 | 2 | Bits, operaciones bit a bit, máscaras y E/S mapeada en memoria (DDR, PORT, PIN) | [02](02-bits-y-es-mapeada-en-memoria.md) | [PDF](pdf/02-bits-y-es-mapeada-en-memoria.pdf) |
| 2 | 1 | Del AVR al ESP32: GPIO matrix, W1TS/W1TC, mapa de pines, superlazo | [03](03-del-avr-al-esp32.md) | [PDF](pdf/03-del-avr-al-esp32.pdf) |
| 2 | 2 | Tipos de datos, `millis()` sin bloquear y pulsadores (antirrebote y flanco) | [04](04-tipos-tiempo-y-pulsadores.md) | [PDF](pdf/04-tipos-tiempo-y-pulsadores.pdf) |
| 3 | — | Temporizadores de hardware: prescaler, resolución, alarma, ISR | [05](05-temporizadores.md) | [PDF](pdf/05-temporizadores.pdf) |
| 4 | — | Interrupciones externas: `attachInterrupt`, IRAM_ATTR, `volatile`, patrón bandera | [06](06-interrupciones-externas.md) | [PDF](pdf/06-interrupciones-externas.pdf) |
| — | — | **Repaso para la prueba**: chuleta, errores frecuentes y ejercicios | [repaso](repaso-prueba.md) | [PDF](pdf/07-repaso-para-la-prueba.pdf) |

Las guías PDF (A4 vertical) resumen cada tema en diagramas de pasos para imprimir o leer en el celular; los apuntes en Markdown tienen el detalle completo.

## Cómo usarlos

1. Lee el **repaso** primero para ver el mapa completo.
2. Recorre cada apunte; los diagramas resumen el flujo de cada tema.
3. Intenta responder los ejercicios antes de abrir las respuestas (los bloques desplegables).

Los diagramas están en Mermaid y GitHub los muestra directamente.
