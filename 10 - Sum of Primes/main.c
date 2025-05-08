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
size_t sum_primes(int max);

int main(int argc, const char *argv[])
{
  size_t prime_sum = sum_primes(2e6);
  printf("Sum of primes: %ld\n", prime_sum);
  return 0;
}

size_t sum_primes(int n)
{
  // Assumes n to be less than 10k
  int MAX = n;

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
    while (j < MAX + 2) {
      num_array[j - 2] = false;
      j += num;
    }
  }

  // Add all primes upto n
  size_t prime_sum = 0;
  for (size_t num = 2; num < MAX; num++) {
    if (num_array[num - 2]) {
      prime_sum += num;
    }
  }

  free(num_array);
  return prime_sum;
}
