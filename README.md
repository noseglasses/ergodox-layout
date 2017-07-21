# noseglasses' layout

This is my personal layout for the [ErgoDox EZ](https://ergodox-ez.com/).

This layout uses [Papageno](https://github.com/noseglasses/papageno) to process special key combinations. Papageno is currently not officially integrated with the [QMK firmware](https://github.com/qmk/qmk_firmware/) therefore to build it, you need a patched version of QMK you can find [here](https://github.com/noseglasses/qmk_firmware).

## How to build

To build it, you need
1) All requirements that are needed to build classical QMK firmware
2) A current version of Papageno (already integrated as a submodule in the patched version of QMK)
3) The noseglasses' layout keymap files

The build process works as follows

```sh
# Change to your favorite build directory
# ...

# Clone QMK
#
git clone https://github.com/noseglasses/qmk_firmware.git
cd qmk_firmware
git submodule update --init --recursive

# Build Papageno for avr-gcc
#
cd lib/papageno
mkdir -p build/avr-gcc
cd build/avr-gcc
cmake -DCMAKE_TOOLCHAIN_FILE=$PWD/../../cmake/toolchains/Toolchain-avr-gcc.cmake -DPAPAGENO_PLATFORM=avr-gcc ../..
make

cd ../../../..

# Clone noseglasses' layout
#
git clone https://github.com/noseglasses/ergodox-layout.git keyboards/ergodox/keymaps/noseglasses

# Build the layout
#
make keyboard=ergodox keymap=noseglasses
```
