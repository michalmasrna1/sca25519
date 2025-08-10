#include "crypto/include/crypto_scalarmult.h"

int main(void) {
  const uint8_t public_key[32];
  const UN_256bitValue private_key;
  uint8_t result[32];
  crypto_scalarmult_curve25519(result, private_key.as_uint8_t, public_key);
  return 0;
}