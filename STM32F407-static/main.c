#include "main.h"

#include <stdio.h>

#include "stm32wrapper.h"

// Local function prototypes:
// void cycles_updatekey(void);
// int test_point(void);
// void cycles_cswap(void);

int main(void) {

  // blinded key prepared by user
  UN_256bitValue ustatic_key = {{0x1b, 0xc7, 0x9e, 0xf8, 0xe8, 0x24, 0xb2, 0x7a,
                                0x9d, 0xc5, 0x9b, 0x41, 0x63, 0x5a, 0x9c, 0x9d,
                                0xab, 0x9e, 0xd3, 0xaf, 0xa6, 0x0f, 0x34, 0xc5,
                                0xa5, 0xe0, 0xa1, 0xc4, 0x74, 0x29, 0x3a, 0x0d}};
  UN_256bitValue ublindingFactor = {
      {0x23, 0x09, 0xef, 0x5b, 0x32, 0x46, 0xdb, 0x2f, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
  // static point for point blinding - prepared by user
  UN_256bitValue uRx = {{0x0f, 0x52, 0x4b, 0xef, 0x7e, 0x12, 0x25, 0x8f,
                        0xd9, 0xee, 0xfc, 0xd9, 0xe4, 0x68, 0xb2, 0x1e,
                        0x54, 0x3d, 0x90, 0xcc, 0x4a, 0x54, 0xb3, 0x47,
                        0xf4, 0x8c, 0xc5, 0x96, 0x9f, 0xeb, 0xf4, 0x32}};
  UN_256bitValue uRy = {{0xb8, 0x00, 0xed, 0x3e, 0xe5, 0xc6, 0x7f, 0xa7,
                        0x53, 0x28, 0x30, 0x59, 0x44, 0xdd, 0x5a, 0x89,
                        0x66, 0x3f, 0x60, 0xdd, 0xcc, 0x1e, 0x48, 0xbb,
                        0xe0, 0xf5, 0x5b, 0x19, 0x25, 0x30, 0x9d, 0x17}};
  UN_256bitValue uRz = {{0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

  UN_256bitValue uSx = {{0x96, 0xbb, 0x65, 0x32, 0x04, 0x20, 0xa1, 0x8f,
                        0x53, 0x04, 0x2c, 0x0e, 0xdd, 0x51, 0xdb, 0xdd,
                        0xac, 0xf0, 0xb9, 0x65, 0x2f, 0x77, 0x44, 0x92,
                        0x64, 0xeb, 0xa9, 0x68, 0x35, 0xad, 0x83, 0x53}};
  UN_256bitValue uSy = {{0x36, 0xd0, 0xaa, 0x8c, 0xfe, 0x37, 0x34, 0x3f,
                        0x51, 0x27, 0x1d, 0xdb, 0x4b, 0xd4, 0x0f, 0xd3,
                        0x62, 0x70, 0x80, 0xa0, 0xe5, 0x5c, 0x48, 0x5f,
                        0xdf, 0x4a, 0x4f, 0x53, 0xe2, 0x8b, 0x61, 0x32}};
  UN_256bitValue uSz = {{0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

// void cycles_updatekey() {
//   SCS_DEMCR |= SCS_DEMCR_TRCENA;
//   DWT_CYCCNT = 0;
//   DWT_CTRL |= DWT_CTRL_CYCCNTENA;

//   int i;
//   unsigned int oldcount = DWT_CYCCNT;
//   for (i = 0; i < 1000; i++) {
//     update_static_key_curve25519();
//   }
//   unsigned int newcount = DWT_CYCCNT - oldcount;

//   char str[100];
//   sprintf(str, "Cost update static key: %d", newcount / 1000);
//   send_USART_str((unsigned char *)str);
// }

// #define MAX 10000
// COUNT_CYCLES_EXTRA_SM needs to be (or not) defined in crypto_scalarmult.h
// by default it is not defined

  // clock_setup();
  // gpio_setup();
  // usart_setup(115200);
  // rng_enable();
  // char str[100];

  // send_USART_str((unsigned char *)"Program Started.");
  // send_USART_str((unsigned char *)"This test should take around 16-17 minutes.");

  set_static_key_curve25519(uRx.as_uint8_t, uRy.as_uint8_t, uRz.as_uint8_t,
                            uSx.as_uint8_t, uSy.as_uint8_t, uSz.as_uint8_t,
                            ustatic_key.as_uint8_t, ublindingFactor.as_uint8_t);

  // int retval = test_point();
  // sprintf(str, "Test point: %d", retval);
  // send_USART_str((unsigned char *)str);

  // to avoid overflows we perform MAX^2 scalar multiplications and we avarage.
  // So it will be 10000 total executions here.
  uint8_t result[32];
//   int i;
//   unsigned int oldcount, newcount;
//   unsigned long long totalcountNumber = 0;

// #ifdef COUNT_CYCLES_EXTRA_SM
//   globalcount = 0;
//   for (i = 0; i < MAX; i++) {
  crypto_scalarmult_base_curve25519(result /*static_key.as_uint8_t*/);
//   }
//   sprintf(str, "Cost additional 64-bits: %d", globalcount / MAX);
//   send_USART_str((unsigned char *)str);
// #else
//   SCS_DEMCR |= SCS_DEMCR_TRCENA;
//   DWT_CYCCNT = 0;
//   DWT_CTRL |= DWT_CTRL_CYCCNTENA;

//   for (i = 0; i < MAX;) {
//     oldcount = DWT_CYCCNT;
//     crypto_scalarmult_base_curve25519(result);
//     newcount = DWT_CYCCNT;
//     if (newcount < oldcount) {
//       sprintf(str, "Clock Overflown");
//       send_USART_str((unsigned char *)str);
//     } else {
//       totalcountNumber += ((long long)newcount - (long long)oldcount);
//       i++;
//     }
//   }
//   sprintf(str, "Cost scalarmult base: %d", (unsigned)(totalcountNumber / MAX));
//   send_USART_str((unsigned char *)str);
// #endif

//   cycles_cswap();
//   cycles_updatekey();

//   uint32_t res;

//   send_USART_str((unsigned char *)"Test scalarmult!");

//   res = test_curve25519_static();
//   sprintf(str, "Test DH static(0 correct): %lu", res);
//   send_USART_str((unsigned char *)str);

//   send_USART_str((unsigned char *)"Done!");
//   update_static_key_curve25519();

//   while (1)
//     ;

  return 0;
}
