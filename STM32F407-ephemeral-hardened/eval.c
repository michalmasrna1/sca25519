#include "crypto/include/crypto_scalarmult.h"
#include "pcg_basic.h"

int main(void) {
  const uint64_t initstate = 0x01234567; // Will be overwritten in fault-finder
  const uint64_t initseq = 0x89abcdef;   // Will be overwritten in fault-finder
  pcg32_srandom(initstate, initseq);
  const uint8_t public_key[32];
  const UN_256bitValue private_key;
  uint8_t result[32];
  crypto_scalarmult_curve25519(result, private_key.as_uint8_t, public_key);
  return 0;
}