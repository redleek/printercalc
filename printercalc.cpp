#include <stddef.h>

void printercalc(int array[], unsigned int pages)
{
  if (pages < 4) return;
  // assign known variables
  array[0] = pages;
  array[1] = 1;
  array[pages/2] = 2;
  array[pages/2 + 1] = pages - 1;
  // if array already full
  if (pages == 4) return;
  int a = 1, b = pages;
  for (size_t i = 2; i < pages/2 - 1; ++i)
    {
      b -=2;
      a +=2;
      array[i] = b;
      ++i;
      array[i] = a;
    }
  a = 2, b = pages - 1;
  for (size_t i = pages/2 + 2; i < pages; ++i)
    {
      a += 2;
      b -= 2;
      array[i] = a;
      ++i;
      array[i] = b;
    }
}
