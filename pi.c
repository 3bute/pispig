#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int digits = 16;

int main(int argc, char** argv) {
  
  if (argc > 1) {
    digits = strtod(*++argv, 0);
  }
  
  char* out = malloc(sizeof(char) * digits + 1);
  int len = 10 * digits / 3
    , A[len]
    , res[digits + 1]
    , last = 0;

  for (int i = 0; i < len; i++) A[i] = 2;
  
  for (int n = 0; n < digits; n++) {
    for (int i = 0; i < len; i++) A[i] *= 10;
    for (int i = len - 1; i >= 0; i--) {
      if (i == 0 ) {
        int pre = A[i] / 10;
        if (pre == 10) {
          if (res[last - 1] < 9) {
            res[last - 1]++;
          } else {
            for (int j = last - 1; j > 0; j-- ) {
              if (res[j] < 9) {
                res[j]++;
                break ;
              } else {
                res[j] = 0;
              }
            }
            res[last] = 0;
          }
          res[last++] = 0;
        } else {
          res[last++] = pre;
        }
        A[i] = A[i] % 10;
        continue ;
      }
      int temp = (A[i] / (2 * (i + 1) - 1)) * i;
      A[i] %= (2 * (i + 1) - 1);
      if (i > 0) A[i - 1] += temp;
    }
  }
  
  printf("%d.", 3);
  for (int i = 1; i < digits; i++) {
    printf("%d", res[i]);
  }
  printf("\n");

  return 0;

}
