#include <stdio.h>
extern int fib(int n);
int main() {
  for(int i = 1; i <= 10; i++)
    printf("fib(%d) - %d \n", i, fib(i));
  return 0;
}
