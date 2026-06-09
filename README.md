# Caja de música mediante NFC
## Descripción

Proyecto desarrollado para reproducir pistas de audio mediante tarjetas NFC. Cada tarjeta actúa como un "disco musical" que, al acercarse al lector NFC, es identificada por el sistema y desencadena la reproducción automática de un archivo de audio almacenado en una tarjeta microSD.

El sistema está diseñado para ofrecer una experiencia similar a una caja de música moderna, permitiendo asociar diferentes canciones o narraciones a distintas tarjetas NFC de forma sencilla e intuitiva.

## Funcionalidades

- Lectura e identificación de tarjetas NFC.
- Asociación de cada tarjeta con una pista de audio específica.
- Reproducción automática al detectar una tarjeta.
- Almacenamiento de archivos de audio en memoria microSD.
- Sistema autónomo y de bajo consumo.
- Posibilidad de ampliar la biblioteca musical añadiendo nuevas tarjetas NFC.

## Tecnologías

- Microcontrolador: Arduino
- Lenguaje: C++
- Lector NFC: MFRC522
- Módulo de audio: DFPlayer Mini
- Almacenamiento: Tarjeta microSD
- Altavoz: 3W
