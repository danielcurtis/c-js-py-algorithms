#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *a = temp;
}

void bubble(int data[], int length) {
  int flag = 0;

  for (int i = 0; i < length - 1; i++) {
    flag = 0;

    for (int j = 0; j < length - i - 1; j++) {
      if (data[j] > data[j + 1]) {
        swap(&data[j], &data[j + 1]);
        flag = 1;
      }
    }

    if (flag == 0) {
      break;
    }
  }
}

int main() {
  int data[] = {10, 9, 3, 7, 8, 6, 11, 2};
  int length = 8;

  bubble(data, length);

  for (int i = 0; i < length; i++) {
    printf("%d ", data[i]);
  }

  printf("\n");

  return 0;
}
