#!/bin/bash

# This script builds a keymap for compression using
# Papageno and simavr

# TODO: Integrate this in the qmk build system to make it more general
#       so it can be used with other keyboards.

SOURCE="${BASH_SOURCE[0]}"
while [ -h "$SOURCE" ]; do # resolve $SOURCE until the file is no longer a symlink
   DIR="$( cd -P "$( dirname "$SOURCE" )" && pwd )"
   SOURCE="$(readlink "$SOURCE")"
   [[ $SOURCE != /* ]] && SOURCE="$DIR/$SOURCE" # if $SOURCE was a relative symlink, we need to resolve it relative to the path where the symlink file was located
done
CUR_DIR="$( cd -P "$( dirname "$SOURCE" )" && pwd )"

QUANTUM_DIR=${CUR_DIR}/../../../../quantum
BASE_DIR=${CUR_DIR}/../../../..

KEYBOARD=$(basename $(dirname $(dirname ${CUR_DIR})))
KEYMAP=$(basename ${CUR_DIR})

COMPRESS_EXE="papageno_compress_${KEYBOARD}_${KEYMAP}"
  
echo "Compiling compression firmware"
#   -mmcu=atmega128 \
avr-gcc \
   \
  -mmcu=atmega1280 \
   \
   -funsigned-char \
   -funsigned-bitfields \
   -ffunction-sections \
   -fdata-sections \
   -fpack-struct \
   -fshort-enums \
   -fno-inline-small-functions \
   -fno-strict-aliasing \
   \
   -gdwarf-2 \
   \
   -std=gnu99 \
   \
   -Os \
   \
   -Wall \
   -Wstrict-prototypes \
   -Werror \
   \
   -o ${COMPRESS_EXE} \
   \
   -DPAPAGENO_COMPRESSION_ENABLED \
    \
   -DINTERRUPT_CONTROL_ENDPOINT \
   -DBOOTLOADER_SIZE=512 \
   -DFORCE_NKRO \
   -DUSER_PRINT \
   -DPAPAGENO_ENABLE \
   -DMAGIC_ENABLE \
   -DNO_PRINT \
   -DNO_DEBUG \
   -DNKRO_ENABLE \
   -DONEHAND_ENABLE \
   -DARCH=ARCH_AVR8 \
   -DUSE_FLASH_DESCRIPTORS \
   -DUSE_STATIC_OPTIONS="(USB_DEVICE_OPT_FULLSPEED | USB  _OPT_REG_ENABLED | USB_OPT_AUTO_PLL)" \
   -DFIXED_CONTROL_ENDPOINT_SIZE=8 \
   -DFIXED_NUM_CONFIGURATIONS=1 \
   -DPROTOCOL_LUFA \
   -DF_CPU=16000000UL \
   -DQMK_KEYBOARD=\"${KEYBOARD}\" \
   -DQMK_KEYMAP=\"${KEYMAP}\" \
    \
   -I${BASE_DIR}/keyboards/${KEYBOARD}/keymaps/${KEYMAP} \
   -I${BASE_DIR}/keyboards/${KEYBOARD} \
   -I${BASE_DIR}/. \
   -I${BASE_DIR}/./tmk_core \
   -I${BASE_DIR}/./quantum \
   -I${BASE_DIR}/./quantum/keymap_extras \
   -I${BASE_DIR}/./quantum/audio \
   -I${BASE_DIR}/./quantum/process_keycode \
   -I${BASE_DIR}/./quantum/api \
   -I${BASE_DIR}/./drivers \
   -I${BASE_DIR}/./quantum/serial_link \
   -I${BASE_DIR}/./drivers/avr \
   -I${BASE_DIR}/tmk_core/protocol \
   -I${BASE_DIR}/./tmk_core/common \
   -I${BASE_DIR}/./tmk_core/protocol/lufa \
   -I${BASE_DIR}/./lib/lufa \
   -I${BASE_DIR}/quantum/../lib/papageno/src \
   -I${BASE_DIR}/quantum/../lib/papageno/3rd_party \
   -I${BASE_DIR}/quantum/../lib/papageno/build/avr-gcc/src \
    \
   -include keyboards/planck/keymaps/noseglasses/config.h \
   \
   ${CUR_DIR}/compress_keymap.c \
   \
   ${BASE_DIR}/lib/papageno/build/avr-gcc/src/libpapageno.a
   
echo "Running simulated compression run with simavr"
run_avr -m atmega1280 ./${COMPRESS_EXE} 2>&1 \
   \
   | sed 's/\.\.$//' `# Remove dots at end of the line as generated by simavr` \
   | sed '/__PPG_END_OF_GENERATED_CODE__/,$ d' `# Remove any lines after generated code` \
   | sed -r "s/\x1b\[([0-9]{1,2}(;[0-9]{1,2})*)?m//g" `# Remove coloring escape sequences` \
   \
   > ${CUR_DIR}/compressed_keymap.h
   
echo "Compiling actual firmware for keyboard=${KEYBOARD} and keymap=${KEYMAP}"
make keyboard=${KEYBOARD} keymap=${KEYMAP}