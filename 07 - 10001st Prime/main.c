#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Generate primes and return nth prime
 *
 *
 * @param n Number of the prime
 * @return nth prime
 */
void gen_prime(int n);

int main(int argc, const char *argv[])
{
  gen_prime(10001);
  return 0;
}

void gen_prime(int n)
{
  // Assumes n to be less than 10k
  int MAX = 1e6;

  // Generate a number array for the sieve
  bool *num_array = malloc(MAX * sizeof(bool));

  // Initialize number list
  for (size_t idx = 0; idx < MAX; idx++) {
    num_array[idx] = true;
  }

  // Sieve the primes
  for (size_t num = 2; num * num < MAX; num++) {
    // If not a prime, continue
    if (!num_array[num - 2]) {
      continue;
    }
    // If it is a prime, mark every multiple of it till the end
    int j = num << 1;
    while (j < MAX) {
      num_array[j - 2] = false;
      j += num;
    }
  }

  // Print all the primes upto n
  int num_primes = 0;
  for (size_t idx = 0; idx < MAX; idx++) {
    if (num_array[idx]) {
      num_primes += 1;
      if (num_primes == n) {
        printf("%dth prime is %ld\n", n, idx + 2);
        break;
      }
    }
  }

  free(num_array);
}
