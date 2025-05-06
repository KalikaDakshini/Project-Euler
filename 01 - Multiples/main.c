#include <stdio.h>
#include <stdlib.h>

int ap_sum(int start, int max, int diff);

int main(int argc, const char *argv[])
{
  // Sum of all numbers that are either multiples of 3 or multiples of 5
  // Find sums of multiples of 3 and multiples of 5, then subtracts
  // multiples of 15
  int N = 1000;
  if (argc > 1) {
    N = atoi(argv[1]);
  }

  int multiples_3 = ap_sum(0, N, 3);
  int multiples_5 = ap_sum(0, N, 5);
  int multiples_15 = ap_sum(0, N, 15);

  printf("Sum upto %d: %d\n", N, multiples_3 + multiples_5 - multiples_15);
  return 0;
}

int ap_sum(int a, int max, int diff)
{
  int count = ((max % diff) == 0) ? max / diff : (max / diff) + 1;
  return a + diff * (((count - 1) * count) / 2);
}
