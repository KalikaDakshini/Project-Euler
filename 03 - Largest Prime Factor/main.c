#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

size_t largest_prime_factor(size_t N);

int main(int argc, const char *argv[])
{
  size_t num = 13195;
  if (argc > 1) {
    num = atol(argv[1]);
  }

  printf("Largest factor of %ld: %ld\n", num, largest_prime_factor(num));
  return 0;
}

size_t largest_prime_factor(size_t num)
{
  // Check for 2 first
  while (num % 2 == 0) {
    num = num / 2;
  }
  if (num == 1) {
    return 2;
  }

  size_t p = 3;
  while (p < num) {
    // Remove all factors of p
    while (num % p == 0) {
      num = num / p;
    }
    // If it is the last prime factor, return
    if (num == 1) {
      return p;
    }
    // Go to next odd number and repeat
    p += 2;
  }
  return num;
}
