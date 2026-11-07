# Objetivo(s) de la Práctica

Construir un sensor de puerta con un pulsador y un LED que detecte la apertura mediante una interrupción externa del ESP32, y comprobar experimentalmente por qué la interrupción no pierde eventos que el sondeo sí pierde y por qué hace falta el antirrebote.

Objetivos específicos:

- Configurar una interrupción externa con attachInterrupt() y el flanco FALLING.
- Escribir una ISR corta, con IRAM_ATTR, variables volatile y patrón bandera.
- Explicar con las mediciones propias la diferencia entre sondeo e interrupción y el efecto del rebote.

# Materiales, Reactivos, Equipos y Herramientas

- Simulación: Wokwi en el navegador y wokwi-cli, con el ESP32 DevKit V1, un pulsador, un LED rojo y una resistencia de 330 Ω.
- Placa real: ESP32 DevKit V1 de 30 pines con cable USB de datos, protoboard, pulsador de 4 patas, LED rojo de 5 mm, resistencia de 330 Ω y cables jumper.
- Software: Arduino IDE con el paquete esp32 de Espressif 3.x, sin librerías externas, y GitHub para la entrega.

# Procedimiento / Metodología Ejecutada

El pulsador hace de sensor de puerta (presionado = puerta abierta), el LED es la luz de alarma y el Monitor Serie es la notificación. Primero se cargó el diagram.json del Anexo A de la guía en Wokwi y se probó el Código 1 (sondeo). Los conteos de las Tablas A y B salen de wokwi-cli; las capturas, de corridas manuales en el navegador; luego el Código 2 (interrupción) con T_REBOTE = 0 y con T_REBOTE = 50; la Parte C repite el Código 2 en la placa real del grupo.

## Esquema del circuito

El circuito es el del Anexo A de la guía: el pulsador va entre D21 y GND usando patas en diagonal, con la resistencia pull-up interna, y el LED se conecta a D19 a través de una resistencia de 330 Ω, con el cátodo a GND. Ningún pin elegido es de arranque, de memoria flash o solo de entrada [@espressif_esp32_datasheet].

Figura: Diagrama del circuito en Wokwi: ESP32 DevKit V1, pulsador en D21 y LED con resistencia de 330 Ω en D19 (figures/wokwi-diagrama.png)

Figura: Montaje en la placa ESP32 real del grupo, con el LED de alarma encendido y el multímetro sobre el LED (figures/montaje.png)

Enlaces del trabajo:

- Proyecto en Wokwi del Código 1 (sondeo): https://wokwi.com/projects/479994010623459329
- Proyecto en Wokwi del Código 2 (interrupción): https://wokwi.com/projects/479992357138333697
- Repositorio de GitHub, carpeta AP4 con los dos códigos, el diagram.json, las capturas del Monitor Serie y la foto del montaje: https://github.com/AlejandroTatum/sistemas-digitales-unl/tree/main/unidad-1/ape-4-interrupciones-esp32/AP4

# Resultados

Cada prueba consistió en 10 toques cortos y rápidos del pulsador, en unos 10 segundos. En Wokwi se repitió cada prueba dos veces con ritmos distintos: en el intento 1, cada toque duró 150 ms con 850 ms de pausa; en el intento 2, 120 ms con 930 ms de pausa. El pulsador de Wokwi simula el rebote mecánico [@wokwi2025docs].

## Parte A. Sondeo

Tabla A. Sondeo: aperturas reportadas con 10 pulsaciones.

- Intento 1; 10 pulsaciones; 0 aperturas reportadas
- Intento 2; 10 pulsaciones; 1 apertura reportada

De las 20 aperturas reales de los dos intentos, el sondeo detectó una sola.

Figura: Monitor Serie del Código 1 (sondeo) tras 10 pulsaciones (figures/monitor-codigo1.png)

## Parte B. Interrupción y antirrebote en Wokwi

Tabla B. Interrupción en Wokwi: eventos contados con 10 pulsaciones.

- T_REBOTE = 0 ms; intento 1: 905 eventos; intento 2: 963 eventos; más de 10
- T_REBOTE = 50 ms; intento 1: 20 eventos; intento 2: 20 eventos; más de 10

Con T_REBOTE = 0, cada rebote dispara la ISR y el contador llega a entre 90 y 96 eventos por toque; una corrida aparte en el navegador terminó en 876 eventos, del mismo orden. Con T_REBOTE = 50 el conteo baja de unos 930 a 20 eventos por intento: 2 por toque, y el contador Eventos sube con cada toque, así que no se pierde ninguna apertura. La captura del navegador con 10 clics también terminó en 20 eventos.

El segundo evento de cada toque aparece al soltar: el contacto también rebota al abrirse, y esos rebotes producen flancos de bajada que llegan más de 50 ms después del flanco aceptado al presionar, porque cada toque duró entre 120 y 150 ms. El filtro por tiempo descarta los rebotes de un mismo cambio, pero no distingue el rebote de soltar de una apertura nueva.

Figura: Monitor Serie del Código 2 con T_REBOTE = 0 (figures/monitor-codigo2-t0.png)

Figura: Monitor Serie del Código 2 con T_REBOTE = 50 (figures/monitor-codigo2-t50.png)

## Parte C. Placa ESP32 real

El grupo no tuvo Monitor Serie con la placa, así que la prueba se hizo mirando el LED de alarma y midiendo su voltaje con un multímetro. Se grabó un video de cada condición con 10 pulsaciones, y los cambios de estado del LED se contaron cuadro a cuadro.

Tabla C. Placa real: comportamiento del LED con 10 pulsaciones.

- T_REBOTE = 0 ms; intento 1: eventos no medidos, el LED cambió de estado 5 veces; intento 2: no realizado (un solo video por valor); observaciones: cambios a los 2, 4, 6, 8 y 12 s del video; 1,91 a 1,92 V en el LED encendido y 0,00 V apagado
- T_REBOTE = 50 ms; intento 1: eventos no medidos, el LED cambió de estado 2 veces; intento 2: no realizado (un solo video por valor); observaciones: el LED se encendió a los 2,8 s y se apagó a los 6,8 s

Valor esperado por teoría, no medido: con T_REBOTE = 0 el contador debería pasar de 10, porque un pulsador mecánico rebota varios milisegundos y cada flanco dispara la ISR [@yershov2019debouncing]; con T_REBOTE = 50 debería quedar entre 10 y 20, según si el contacto también rebota al soltar, como ocurrió en Wokwi.

El montaje funcionó: el LED responde al pulsador mientras el loop() está en el delay(2000). Sin embargo, el LED no sirve como contador, porque el loop() lo cambia a lo sumo una vez cada 2 s aunque la ISR haya contado decenas de eventos; por eso los cambios quedan separados por múltiplos de 2 s y la placa no permite comparar los conteos de 0 y 50 ms como la Tabla B.

# Preguntas de Control

## Con el Código 1, ¿por qué se perdieron aperturas?

Porque el loop() pasa casi todo el tiempo dentro del delay(2000) y solo lee el pin un instante cada 2 s. Si el toque empieza y termina entre dos lecturas, el programa nunca ve el pin en 0; por eso la Tabla A muestra 0 y 1 aperturas de 10.

## ¿Por qué el Código 2 no pierde aperturas aunque también tiene delay(2000)? ¿Quién vigila el pin?

Lo vigila el periférico GPIO del ESP32 por hardware: al detectar el flanco de bajada avisa a la CPU, que pausa el programa, ejecuta la ISR y vuelve al mismo punto, aunque el loop() esté en el delay [@espressif_arduino_esp32_gpio]. La ISR solo cuenta y levanta la bandera, sin que el programa tenga que consultar el pin [@reverter2020noncpu]; el trabajo lento queda para el loop().

## ¿Por qué el contador marcó más de 10 eventos con T_REBOTE = 0? ¿Qué cambió con 50 ms?

Porque el pulsador rebota y, sin filtro, cada rebote es un flanco que dispara la ISR: se contaron entre 905 y 963 eventos. Con 50 ms la ISR ignora los flancos que llegan muy seguidos al último aceptado [@yershov2019debouncing], y el conteo bajó a 20; el segundo evento de cada toque viene del rebote al soltar, explicado en la Parte B.

## ¿Por qué alerta y eventos son volatile y tUltimo no?

Las variables alerta y eventos se escriben en la ISR y se leen en el loop(); volatile obliga al compilador a leerlas siempre de memoria y no de una copia vieja en un registro. tUltimo solo lo usa la ISR, así que no hay otro código que pueda leer un valor desactualizado. Compartir datos entre la ISR y el programa principal sin este cuidado es un error típico de los sistemas embebidos [@freire2023electronica].

## ¿Por qué el Serial.print está en el loop() y no en la ISR?

Porque la ISR debe ser corta y Serial.print es lento y depende del búfer y del periférico UART, que trabajan con sus propias interrupciones. Si se moviera a la ISR, esta tardaría demasiado, podría quedarse esperando espacio en el búfer de la UART y el watchdog reiniciaría el ESP32 con un Guru Meditation Error; por eso se usa el patrón bandera [@espressif_arduino_esp32_gpio].

## Si se usara RISING en lugar de FALLING, ¿en qué momento se encendería la alarma?

Al soltar el pulsador, no al presionarlo. Con INPUT_PULLUP el pin pasa de 1 a 0 al presionar (FALLING) y de 0 a 1 al soltar (RISING), así que la alarma llegaría tarde: cuando la puerta ya se cerró.

# Conclusiones

1. El sondeo cada 2 s detectó 0 y 1 aperturas de 10 en los intentos 1 y 2, mientras que la interrupción contó al menos un evento por toque (20 con T_REBOTE = 50) con el mismo delay(2000).
2. Sin antirrebote, 10 toques generaron entre 905 y 963 eventos; con T_REBOTE = 50 el conteo bajó a 20.
3. El antirrebote por tiempo no basta para toques más largos que T_REBOTE: el rebote al soltar se contó como un segundo evento en cada toque.

# Recomendaciones

- Para toques más largos que T_REBOTE, aceptar el flanco solo si el pin sigue en 0 o usar un T_REBOTE mayor que la duración típica de un toque.
- Mantener el patrón bandera: la ISR solo registra y el loop() hace el trabajo lento.

# Declaración de Uso de IA Generativa

Yo, Alejandro Padilla Espinoza, en nombre del grupo integrado por Melissa Contento, Jaime Landázuri, Doménica Rojas e Ivett Zaragocín, declaro de manera transparente el uso de herramientas de Inteligencia Artificial Generativa (IAG) en este trabajo.

## Alcance del uso de IA generativa

La IAG se usó como apoyo, sin sustituir el juicio ni la autoría del grupo:

- Automatizar la simulación de Wokwi por línea de comandos (wokwi-cli) para registrar los conteos de las Tablas A y B a partir de los códigos de la guía, sin modificarlos salvo la constante T_REBOTE que pide la práctica.
- Extraer cuadros de los videos de la placa para contar los cambios de estado del LED de la Tabla C y obtener la foto del montaje.
- Estructurar, redactar y dar formato al informe.

## Clasificación del uso según GAIDeT

- Nivel 1, asistencia lingüística: corrección y claridad de la redacción.
- Nivel 3, asistencia técnica: apoyo en la automatización de la simulación y en la construcción del documento.

## Validación y responsabilidad

El grupo revisó los conteos contra los registros del Monitor Serie de cada simulación, comparó los cambios del LED con sus videos de la placa y asume la responsabilidad sobre el contenido.

## Herramientas utilizadas

- Claude (Anthropic): automatización de la simulación, redacción y formato del informe. Partes afectadas: la redacción y el formato de todo el informe, y el contenido de Resultados, Preguntas de Control y Conclusiones.

# Anexos

La carpeta AP4 del repositorio (enlace en el esquema del circuito) contiene además los registros de texto del Monitor Serie de cada simulación por wokwi-cli y los escenarios de 10 toques usados.
