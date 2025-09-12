
#include <Arduino.h>

TaskHandle_t Task1;
TaskHandle_t Task2;

void task1(void *pvParameters){
  for(;;){
    digitalWrite(2, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(2, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void task2(void *pvParameters){
  for(;;){
    Serial.println("Task 2 Running");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void setup(){
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  xTaskCreatePinnedToCore(task1, "Task 1", 1024, NULL, 1, &Task1, 0);
  xTaskCreatePinnedToCore(task2, "Task 2", 1024, NULL, 1, &Task2, 1);
}

void loop(){}
