#include <math.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * @brief Solve a particular quadractic equation and check for positive integer
 * roots
 *
 *
 * @param a pointer to first root
 * @param b pointer to second root
 * @return
 */
bool solve_quadractic(int c, int p, int *a, int *b);

// Check if a given floating point number is an integer
bool is_int(float a)
{
  return a - (int)a == 0;
}

int main(int argc, const char *argv[])
{
  int p = 1000;
  int a = 0, b = 0, c = 330;
  for (c = 330; c < 1000; c++) {
    if (solve_quadractic(c, p, &a, &b)) {
      printf("a: %d, b: %d, c: %d\n", a, b, c);
      break;
    }
  }

  // Print the product
  printf("abc: %d\n", a * b * c);

  return 0;
}

bool solve_quadractic(int c, int p, int *a, int *b)
{
  float determinant = c * c - p * p + 2 * c * p;
  // Check if the determinant is positive
  if (determinant < 0) {
    return false;
  }
  // Check if the root is an integer
  determinant = sqrtf(determinant);
  if (!is_int(determinant)) {
    return false;
  }

  // Check if roots are positive integers
  float r1 = ((p - c) + determinant) / 2;
  float r2 = ((p - c) - determinant) / 2;
  if (!is_int(r1) || (r2 <= 0)) {
    return false;
  }

  // Assign roots and return
  *a = r1;
  *b = r2;
  return true;
}
