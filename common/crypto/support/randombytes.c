#include "../include/randombytes.h"
#include "pcg_basic.h"

#include <stdint.h>

void randombytes(unsigned char *x, unsigned long long xlen) {
  union {
    unsigned char aschar[4];
    uint32_t asint;
  } random;

  while (xlen > 4) {
    random.asint = pcg32_random();
    *x++ = random.aschar[0];
    *x++ = random.aschar[1];
    *x++ = random.aschar[2];
    *x++ = random.aschar[3];
    xlen -= 4;
  }
  if (xlen > 0) {
    for (random.asint = pcg32_random(); xlen > 0; --xlen) {
      *x++ = random.aschar[xlen - 1];
    }
  }
}