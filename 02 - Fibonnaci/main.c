#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
  size_t max = 100;
  if (argc > 1) {
    max = atoi(argv[1]);
  }

  size_t f0 = 1, f1 = 1;
  size_t tmp;

  size_t sum = 0;
  // Generate fibonnaci numbers till a specified threshold
  while (f1 <= max) {
    tmp = f1;
    f1 = f1 + f0;
    f0 = tmp;

    if (f0 % 2 == 0) {
      sum += f0;
    }
  }

  // Print the result
  printf("Sum upto %ld: %ld\n", max, sum);

  return 0;
}
