#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Check if the number is a n-digit palindrome
 *
 *
 * @param p The number
 * @param n_digits Length of the palindrome
 * @return True if the number is a palindrome
 */
bool is_palindrome(int p, int n_digits)
{
  int half = p;
  int rev_half = 0;

  // Accumulate the second half of the number into a second number
  for (int i = 0; i < n_digits / 2; i++) {
    rev_half = half % 10 + rev_half * 10;
    half = half / 10;
  }

  // n_digits is an odd number
  if (n_digits & 1) {
    half = half / 10;
  }

  return half == rev_half;
}

// Multiply two n-digit numbers and return the largest palindrome
int main(int argc, const char *argv[])
{
  size_t n_digits = 3;
  if (argc > 1) {
    n_digits = atoi(argv[1]);
  }

  size_t palin_len = n_digits * 2;

  size_t max = 0, num = 0;
  // Check all multiples of 11 vs 3-digit numbers
  for (size_t i = 990; i >= 110; i -= 11) {
    if (max > i * 999) {
      break;
    }
    for (size_t j = 999; j >= 100; j--) {
      num = i * j;
      // If a palindrome is found, update and resume next loop
      if (is_palindrome(num, palin_len)) {
        if (max < num) {
          max = num;
        }
        break;
      }
    }
  }

  printf("Largest Palindrome Product: %ld\n", max);

  return 0;
}
