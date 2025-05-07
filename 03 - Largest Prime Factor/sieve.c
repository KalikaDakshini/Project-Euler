#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Generte all primes below a threshold using Sieve of Eratosthenes
 *
 *
 * @param primes_list Prime list to be generated
 * @param max The threshold
 * @return Number of primes in primes_list
 */
int gen_primes(int *primes_list, int max);
/**
 * @brief Print the array
 *
 *
 * @param arr Array
 * @param len Length of the array
 */
void print_arr(int *arr, int len);

int main(int argc, const char *argv[])
{
  // Get an upper bound
  int N = 13195;
  if (argc > 1) {
    N = atoi(argv[1]);
  }

  // Generate and print primes
  int *primes_list = malloc((N / 2) * sizeof(int));
  int num_primes = gen_primes(primes_list, N);
  printf("Number of primes below %d: %d\n", N, num_primes);
  print_arr(primes_list, num_primes);

  // Free memory and exit
  free(primes_list);
  return 0;
}

int gen_primes(int *primes_list, int max)
{
  int num_primes = 0;
  bool *num_array = malloc(max - 2 * sizeof(bool));

  // Initialize number list
  for (size_t idx = 0; idx < max - 2; idx++) {
    num_array[idx] = true;
  }

  // Sieve the primes
  for (size_t idx = 0; idx < max - 2; idx++) {
    // If not a prime, continue
    if (!num_array[idx]) {
      continue;
    }
    // If it is a prime, mark every multiple of it till the end
    int num = idx + 2;
    int j = num << 1;
    while (j < max) {
      num_array[j - 2] = false;
      j += num;
    }
  }

  // Gather all primes into an array
  for (size_t idx = 0; idx < max - 2; idx++) {
    if (num_array[idx]) {
      num_primes++;
    }
  }

  for (size_t idx = 0, j = 0; idx < max - 2; idx++) {
    if (num_array[idx]) {
      primes_list[j] = idx + 2;
      j++;
    }
  }

  free(num_array);
  return num_primes;
}

void print_arr(int *arr, int len)
{
  if (len < 1) {
    return;
  }

  printf("%d", arr[0]);
  for (size_t idx = 1; idx < len; idx++) {
    printf(", %d", arr[idx]);
  }
  printf("\n");
}
