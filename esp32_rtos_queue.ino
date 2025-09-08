
#include <Arduino.h>

QueueHandle_t queue;

void senderTask(void *pvParameters) {
  int counter = 0;
  for (;;) {
    xQueueSend(queue, &counter, portMAX_DELAY);
    counter++;
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void receiverTask(void *pvParameters) {
  int data;
  for (;;) {
    if (xQueueReceive(queue, &data, portMAX_DELAY)) {
      Serial.print("Received: ");
      Serial.println(data);
    }
  }
}

void setup() {
  Serial.begin(115200);
  queue = xQueueCreate(5, sizeof(int));
  xTaskCreate(receiverTask, "Receiver", 2048, NULL, 1, NULL);
  xTaskCreate(senderTask, "Sender", 2048, NULL, 1, NULL);
}

void loop() {}
