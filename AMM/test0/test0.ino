#include <TM1637Display.h>

#define CLK_PIN 2
#define DIO_PIN 3

TM1637Display display(CLK_PIN, DIO_PIN);

const uint8_t LETTER_H[] = {0b01110110};
const uint8_t LETTER_E[] = {0b01111001};
const uint8_t LETTER_L[] = {0b00111000};
const uint8_t LETTER_O[] = {0b00111111};
const uint8_t LETTER_N[] = {0b01010100};
const uint8_t LETTER_D[] = {0b00011110};
const uint8_t LETTER_U[] = {0b01111100};
const uint8_t LETTER_F[] = {0b01011100};
const uint8_t LETTER_Q[] = {0b01101111};
const uint8_t LETTER_A[] = {0b01110111};
const uint8_t LETTER_C[] = {0b00111001};
const uint8_t LETTER_K[] = {0b01100110};
const uint8_t LETTER_P[] = {0b01110011};
const uint8_t LETTER_T[] = {0b01111000};
const uint8_t LETTER_R[] = {0b01010000};
const uint8_t LETTER_I[] = {0b00010000};

void setup() {
  display.setBrightness(7); // Установка яркости дисплея (от 0 до 7)
}

void loop() {
  group1_variant1();
  group1_variant2();
  group1_variant3();
  group1_variant4();
  group2_variant1();
  group2_variant2();
  group2_variant3();
  group2_variant4();
  group3_variant1();
  group3_variant2();
  group3_variant3();
  group3_variant4();
}

// Группа 1 - Вариант 1: вывод чисел от -100 до 100 по середине экрана без ведущих нулей с шагом 1 и паузой 0.15 секунд
void group1_variant1() {
  for (int i = -100; i <= 100; i++) {
    display.showNumberDecEx(i, 0, false, 3, 0); // Вывод числа без ведущих нулей по середине экрана
    delay(150);
  }
}

// Группа 1 - Вариант 2: вывод чисел от -100 до 100 слева на экране без ведущих нулей с шагом 1 и паузой 0.1 секунд
void group1_variant2() {
  for (int i = -100; i <= 100; i++) {
    display.showNumberDecEx(i, 0, true, 3, 0); // Вывод числа без ведущих нулей слева на экране
    delay(100);
  }
}

// Группа 1 - Вариант 3: вывод чисел от 100 до -100 справа на экране без ведущих нулей с шагом 2 и паузой 0.2 секунды
void group1_variant3() {
  for (int i = 100; i >= -100; i -= 2) {
    display.showNumberDecEx(i, 0, false, 3, 0); // Вывод числа без ведущих нулей справа на экране
    delay(200);
  }
}

// Группа 1 - Вариант 4: вывод чисел от 100 до -100 справа на экране с ведущими нулями с шагом 2 и паузой 0.25 секунды
void group1_variant4() {
  for (int i = 100; i >= -100; i -= 2) {
    display.showNumberDecEx(i, 0, true, 4, 0); // Вывод числа с ведущими нулями справа на экране
    delay(250);
  }
}

// Группа 2 - Вариант 1: вывод вещественных чисел от -2 до 2 с шагом 0.2 и паузой 1 секунда
void group2_variant1() {
  for (float i = -2.0; i <= 2.0; i += 0.2) {
    display.showNumberDecEx(i * 100, 0b01000000, false, 3, 1); // Вывод вещественного числа с одним разрядом на целую часть и двумя разрядами на дробную часть
    delay(1000);
  }
}

// Группа 2 - Вариант 2: вывод вещественных чисел от -3 до 3 с шагом 0.25 и паузой 1 секунда
void group2_variant2() {
  for (float i = -3.0; i <= 3.0; i += 0.25) {
    display.showNumberDecEx(i * 100, 0b01000000, false, 3, 1); // Вывод вещественного числа с одним разрядом на целую часть и двумя разрядами на дробную часть
    delay(1000);
  }
}

// Группа 2 - Вариант 3: вывод вещественных чисел от 1 до -1 с шагом 0.1 и паузой 2 секунды
void group2_variant3() {
  for (float i = 1.0; i >= -1.0; i -= 0.1) {
    display.showNumberDecEx(i * 100, 0b01000000, false, 3, 2); // Вывод вещественного числа с одним разрядом на целую часть и двумя разрядами на дробную часть
    delay(2000);
  }
}

// Группа 2 - Вариант 4: вывод вещественных чисел от 3 до -3 с шагом 0.3 и паузой 0.5 секунды
void group2_variant4() {
  for (float i = 3.0; i >= -3.0; i -= 0.3) {
    display.showNumberDecEx(i * 100, 0b01000000, false, 3, 0); // Вывод вещественного числа с одним разрядом на целую часть и двумя разрядами на дробную часть
    delay(500);
  }
}

// Группа 3 - Вариант 1: вывод текста "hello node" с задержкой 1 секунда и сдвигом на 1 символ раз в 1 секунду
void group3_variant1() {
  const uint8_t helloNode[] = {LETTER_H[0], LETTER_E[0], LETTER_L[0], LETTER_L[0], LETTER_O[0], 0x00, 0x00, 0x00, LETTER_N[0], LETTER_O[0], LETTER_D[0], LETTER_E[0]};
  int textLength = sizeof(helloNode) / sizeof(helloNode[0]);

  while (true) {
    for (int i = 0; i < textLength; i++) {
      display.setSegments(&helloNode[i], 1, i); // Вывод одного символа текста
      delay(1000);
    }
  }
}

// Группа 3 - Вариант 2: вывод текста "queue full" с задержкой 0.8 секунды и сдвигом на 1 символ раз в 0.8 секунды
void group3_variant2() {
  const uint8_t queueFull[] = {LETTER_Q[0], LETTER_U[0], LETTER_E[0], LETTER_U[0], LETTER_E[0], 0x00, 0x00, 0x00, LETTER_F[0], LETTER_U[0], LETTER_L[0], LETTER_L[0]};
  int textLength = sizeof(queueFull) / sizeof(queueFull[0]);

  while (true) {
    for (int i = 0; i < textLength; i++) {
      display.setSegments(&queueFull[i], 1, i); // Вывод одного символа текста
      delay(800);
    }
  }
}

// Группа 3 - Вариант 3: вывод текста "lock open" с задержкой 0.6 секунды и сдвигом на 1 символ раз в 0.6 секунды
void group3_variant3() {
  const uint8_t lockOpen[] = {LETTER_L[0], LETTER_O[0], LETTER_C[0], LETTER_K[0], 0x00, 0x00, 0x00, 0x00, LETTER_O[0], LETTER_P[0], LETTER_E[0], LETTER_N[0]};
  int textLength = sizeof(lockOpen) / sizeof(lockOpen[0]);

  while (true) {
    for (int i = 0; i < textLength; i++) {
      display.setSegments(&lockOpen[i], 1, i); // Вывод одного символа текста
      delay(600);
    }
  }
}


// Группа 3 - Вариант 4: вывод текста "train left" с задержкой 0.4 секунды и сдвигом на 1 символ раз в 0.4 секунды
void group3_variant4() {
  const uint8_t trainLeft[] = {LETTER_T[0], LETTER_R[0], LETTER_A[0], LETTER_I[0],  LETTER_N[0], 0x00, 0x00, 0x00, LETTER_L[0], LETTER_E[0], LETTER_F[0], LETTER_T[0]};
  int textLength = sizeof(trainLeft) / sizeof(trainLeft[0]);

  while (true) {
    for (int i = 0; i < textLength; i++) {
      display.setSegments(&trainLeft[i], 1, i); // Вывод одного символа текста
      delay(400);
    }
  }
}