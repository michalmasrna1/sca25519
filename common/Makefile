PREFIX	?= arm-none-eabi
CC		= $(PREFIX)-gcc-9.2.1
LD		= $(PREFIX)-gcc-9.2.1
OPENCM3_DIR = ../../libopencm3

LDSCRIPT   = ../common/stm32f405x6_CCM.ld
LIBNAME    = opencm3_stm32f4
ARCH_FLAGS = -mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16
DEFINES    = -DSTM32F4 -DCORTEX_M4
OBJS	   = crypto/asm/cortex_m4_cswap.o crypto/asm/cortex_m4_hsalsa20_block.o crypto/asm/cortex_m4_reduce25519.o crypto/asm/cortex_m4_sqr_fe25519.o crypto/asm/cortex_m4_mpy_fe25519.o crypto/asm/cortex_m4_add_fe25519.o crypto/asm/cortex_m4_mpy_256.o crypto/asm/cortex_m4_mpy121666.o crypto/asm/cortex_m4_sqr_256.o \
			 crypto/support/randombytes.o \
			 crypto/scalarmult/scalarmult_25519.o \
			 crypto/numerics/fe25519.o crypto/numerics/fe25519_invert.o crypto/numerics/bigint.o crypto/numerics/sc25519.o


CFLAGS		+= -g -O2 \
		   -Wall -Wextra -Wimplicit-function-declaration \
		   -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes \
		   -Wundef -Wshadow \
		   -I$(OPENCM3_DIR)/include \
		   -fno-common $(ARCH_FLAGS) -ffunction-sections -fdata-sections -MD $(DEFINES)
LDFLAGS		+= --static -Wl,--start-group -Wl,--strip-debug -lc -lgcc -lnosys -Wl,--end-group \
		   -T$(LDSCRIPT) -nostartfiles -Wl,--gc-sections,--print-gc-sections \
		   $(ARCH_FLAGS) \
		   -L$(OPENCM3_DIR)/lib

-include local.mk

all: eval.elf

lib:
	make -C $(OPENCM3_DIR)

%.elf: %.o $(OBJS) $(LDSCRIPT)
	$(LD) -o $(*).elf $(*).o $(OBJS) $(LDFLAGS) -l$(LIBNAME)

crypto/asm/%.o: crypto/asm/%.S
	$(CC) $(CFLAGS) -o $@ -c $<

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	find . -name \*.o -type f -exec rm -f {} \;
	find . -name \*.d -type f -exec rm -f {} \;
	rm -f *.elf
	rm -f *.bin

