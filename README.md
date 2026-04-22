🦾 Guante de Rehabilitación con ESP32

Este proyecto consiste en el desarrollo de un sistema mecatrónico de bajo costo orientado a la rehabilitación de la mano, utilizando microcontroladores ESP32, potenciómetros y servomotores.

📌 Descripción general

El sistema está compuesto por dos módulos principales:

ESP32 transmisor (guante): captura el movimiento de los dedos mediante potenciómetros.
ESP32 receptor (estructura robótica): recibe los datos de forma inalámbrica y acciona servomotores que replican el movimiento.

La comunicación entre ambos dispositivos se realiza mediante el protocolo ESP-NOW, permitiendo una transmisión rápida y eficiente sin necesidad de red WiFi convencional.

⚙️ Funcionamiento
Cada dedo del guante está asociado a un potenciómetro, que genera valores analógicos según su posición.
El ESP32 transmisor lee estos valores (rango 0–4095).
Los datos se envían de forma inalámbrica al ESP32 receptor.
El receptor convierte estos valores en ángulos (0–180°).
Cada servomotor reproduce el movimiento correspondiente de cada dedo.
🧩 Componentes utilizados
2 × ESP32
4 × Potenciómetros
5 × Servomotores 
Protoboard y cables Dupont
Fuente de alimentación externa (5V para servos)
💻 Software

El proyecto está desarrollado en Arduino IDE, utilizando las siguientes librerías:

WiFi.h
esp_now.h
ESP32Servo.h
🎯 Objetivo

El objetivo principal es construir un prototipo funcional de guante que permita replicar movimientos de la mano en tiempo real, con potencial aplicación en:

Rehabilitación motora
Asistencia a pacientes con movilidad reducida
Interfaces humano-máquina
