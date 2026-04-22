// ESP32 RECEPTOR - recibe 4 valores por ESP-NOW y mueve 5 servos
// El potenciómetro 1 mueve el servo 1 y también el servo 5

#include <WiFi.h>
#include <esp_now.h>
#include <ESP32Servo.h>

#define NUM_POTS 4
#define NUM_SERVOS 5

int servoPins[NUM_SERVOS] = {19, 18, 5, 17, 16};

Servo servos[NUM_SERVOS];

typedef struct struct_message {
  int numeros[NUM_POTS];
} struct_message;

struct_message myData;

int angulosServo[NUM_SERVOS] = {0, 0, 0, 0, 0};

void OnDataRecv(const esp_now_recv_info *info, const uint8_t *incomingData, int len) {
  if (len != sizeof(myData)) {
    Serial.print("Error: tamaño de datos incorrecto. Recibido: ");
    Serial.print(len);
    Serial.print(" bytes / Esperado: ");
    Serial.println(sizeof(myData));
    return;
  }

  memcpy(&myData, incomingData, sizeof(myData));

  // Servo 1 <- Pot 1
  angulosServo[0] = myData.numeros[0];

  // Servo 2 <- Pot 2
  angulosServo[1] = myData.numeros[1];

  // Servo 3 <- Pot 3
  angulosServo[2] = myData.numeros[2];

  // Servo 4 <- Pot 4
  angulosServo[3] = myData.numeros[3];

  // Servo 5 <- Pot 1
  angulosServo[4] = myData.numeros[0];

  for (int i = 0; i < NUM_SERVOS; i++) {
    servos[i].write(angulosServo[i]);
  }

  Serial.print("Pot1: ");
  Serial.print(myData.numeros[0]);
  Serial.print(" -> Servo1 y Servo5: ");
  Serial.print(angulosServo[0]);
  Serial.print(" / ");
  Serial.println(angulosServo[4]);

  Serial.print("Pot2: ");
  Serial.print(myData.numeros[1]);
  Serial.print(" -> Servo2: ");
  Serial.println(angulosServo[1]);

  Serial.print("Pot3: ");
  Serial.print(myData.numeros[2]);
  Serial.print(" -> Servo3: ");
  Serial.println(angulosServo[2]);

  Serial.print("Pot4: ");
  Serial.print(myData.numeros[3]);
  Serial.print(" -> Servo4: ");
  Serial.println(angulosServo[3]);

  Serial.println("-------------------");
}

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < NUM_SERVOS; i++) {
    servos[i].attach(servoPins[i]);
    servos[i].write(0);
  }

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error al inicializar ESP-NOW");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);

  Serial.println("Receptor listo");
}

void loop() {
}