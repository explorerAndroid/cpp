/* Тернарный оператор и макросы в C */
#include <stdio.h>

/* Объявление макросов с параметрами */
/* Скобки нужны чтобы вычисления производились в "ожидаемом" */
/* программистом порядке */
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int main() {
  int a = 5, b = 2;
  // Демонстрация вызова макроса
  printf("a = %d  b = %d  MIN = %d  MAX = %d\n",
         a, b, MIN(a, b), MAX(a, b) );

  // (a < b) ? a : b = 10;

  return 0;
}
