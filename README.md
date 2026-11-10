# Sistemas Digitales

**Universidad Nacional de Loja** · Facultad de la Energía, las Industrias y los Recursos Naturales No Renovables · Carrera de Computación

| | |
| --- | --- |
| **Asignatura** | Sistemas Digitales |
| **Ciclo** | 5.º |
| **Docente** | Ing. Luis Sinche Cueva, Mg. |
| **Estudiante** | Alejandro Padilla |

Repositorio con las prácticas entregadas y los apuntes de estudio de la asignatura, organizado por unidad.

## Contenido

- [Unidad 1 — Microcontroladores para sistemas embebidos](#unidad-1--microcontroladores-para-sistemas-embebidos)
  - [Prácticas (APE)](#prácticas-ape)
  - [Apuntes de estudio](#apuntes-de-estudio)
- [Estructura del repositorio](#estructura-del-repositorio)
- [Herramientas](#herramientas)

---

## Unidad 1 — Microcontroladores para sistemas embebidos

Resultado de aprendizaje **R1**: diseña arquitectura de microcontroladores. · [Ir a la unidad →](unidad-1)

### Prácticas (APE)

| Semana | Práctica | Tema | Plataforma | Informe |
| --- | --- | --- | --- | --- |
| 1 | [APE 1](unidad-1/apes/ape-1-avr-wokwi-microchip-studio) | Arquitectura, puertos de E/S y operaciones a nivel de bit | ATmega328P · Wokwi · Microchip Studio | [PDF](unidad-1/apes/ape-1-avr-wokwi-microchip-studio/documento/APE1_SistemasDigitales_Informe.pdf) |
| 2 | [APE 2](unidad-1/apes/ape-2-juego-luces-esp32) | Juego de luces interactivo | ESP32 · Wokwi | — |
| 4 | [APE 4](unidad-1/apes/ape-4-interrupciones-esp32) | Sensor de puerta con interrupciones externas | ESP32 · Wokwi · placa real | [PDF](unidad-1/apes/ape-4-interrupciones-esp32/documento/APE4_SistemasDigitales_Interrupciones.pdf) |

### Apuntes de estudio

Resúmenes propios de las clases (no forman parte de ninguna entrega), en dos formatos: **Markdown** con el detalle completo y **guía PDF** A4 con diagramas de pasos. · [Ver todos →](unidad-1/apuntes)

| Semana | Tema | Resumen | Guía |
| --- | --- | --- | --- |
| 1 | Del computador al microcontrolador | [MD](unidad-1/apuntes/01-del-computador-al-microcontrolador.md) | [PDF](unidad-1/apuntes/pdf/01-del-computador-al-microcontrolador.pdf) |
| 1 | Bits y E/S mapeada en memoria | [MD](unidad-1/apuntes/02-bits-y-es-mapeada-en-memoria.md) | [PDF](unidad-1/apuntes/pdf/02-bits-y-es-mapeada-en-memoria.pdf) |
| 2 | Del AVR al ESP32 | [MD](unidad-1/apuntes/03-del-avr-al-esp32.md) | [PDF](unidad-1/apuntes/pdf/03-del-avr-al-esp32.pdf) |
| 2 | Tipos de datos, tiempo y pulsadores | [MD](unidad-1/apuntes/04-tipos-tiempo-y-pulsadores.md) | [PDF](unidad-1/apuntes/pdf/04-tipos-tiempo-y-pulsadores.pdf) |
| 3 | Temporizadores de hardware | [MD](unidad-1/apuntes/05-temporizadores.md) | [PDF](unidad-1/apuntes/pdf/05-temporizadores.pdf) |
| 4 | Interrupciones externas | [MD](unidad-1/apuntes/06-interrupciones-externas.md) | [PDF](unidad-1/apuntes/pdf/06-interrupciones-externas.pdf) |
| — | Repaso de la unidad | [MD](unidad-1/apuntes/repaso-prueba.md) | [PDF](unidad-1/apuntes/pdf/07-repaso-para-la-prueba.pdf) |

---

## Estructura del repositorio

```text
.
├── README.md                        Este índice
└── unidad-<n>/
    ├── README.md                    Índice de la unidad
    ├── apes/                        Prácticas entregadas
    │   └── ape-<m>-<tema>/
    │       ├── README.md            Proceso y contenido de la práctica
    │       ├── documento/           Informe (PDF y fuente editable)
    │       └── …                    Código, simulación y capturas
    └── apuntes/                     Material de estudio
        ├── *.md                     Resúmenes por clase
        └── pdf/                     Guías de estudio A4
```

## Herramientas

| Tipo | Herramienta |
| --- | --- |
| Microcontroladores | ATmega328P (Arduino Uno) · ESP32 DevKit V1 (ESP32-WROOM-32) |
| Simulación | [Wokwi](https://wokwi.com) y Wokwi CLI |
| Desarrollo | Arduino IDE 2.x con el core *esp32 by Espressif Systems* 3.x · Microchip Studio |
