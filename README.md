# noseglasses' layout

This is my personal layout for the [ErgoDox EZ](https://ergodox-ez.com/) 
and the [Planck](https://olkb.com/planck) keyboard. It is portable and supposed to be easily adjusted to other keyboards. One important idea is to define a common subset of keys between the keyboards. In consequence, this means that some of the keys of the ErgoDox remain unused.

*Please note:* This layout uses [Papageno](https://github.com/noseglasses/papageno) to process special key combinations. Papageno is currently not officially integrated with the [QMK firmware](https://github.com/qmk/qmk_firmware/) therefore to build it, you need a patched version of QMK you can find [here](https://github.com/noseglasses/qmk_firmware). The most simple way to try and test the layout is to follow the [build instructions](#how-to-build) below.

## Special Features   

At first glance, my layout is quite ordinary. It uses two layers for normal
characters and special characters and some more layers for other stuff. However,
some of the other layers `(2 - ..)` are currently inactive.

What's special about this keymap is the use of the thumb keys. I intend to do as much
work as possible with my thumbs and specially on the four large ErgoDox thumb keys as they are most convenient to reach. 

Therefore, I assign key combinations to them that trigger 

* space,
* backspace,
* del,
* tab,
* shift-tab (untab),
* double tab (e.g. for auto completion),
* enter,
* shift (one-shot) and
* layer toggle to symbol layer (one-shot).

That makes 9 actions that are mapped to four keys.
A similar assignment could of course also be achieved by using tap dances. But that would mean that at least one of the keys must be hit three times.
As to me it seems more healthy to tap two keys with two 
different thumbs in a row than with the same thumb I go a different way. This is where [Papageno](https://github.com/noseglasses/papageno), a pattern-matching libray comes in.
It enables the definition of key sequences, chords and clusters. Even combinations
of all of these are possible.
It is possible to use matrix key-positions but also keycodes to define
sequences, chords and clusters. This means that one can define sequences of physical keys or keycodes that might be mapped to several keys through QMK's keymaps.

In this way we can easily handle many different actions, i.d. keys being send, with just four different keys. And it would be possible to add even more functionality to the same four thumb keys.
And all this without any keys permanently held. Neat?

The following is a description of the exact assignments between keys pressed and related actions.
Here left/right, inner/outer refers to ErgoDox's four large thumb keys or the four center keys in the planck's bottom row (48 key Planck).

| Action      | Thumb Keys Involved                                         |
|-------------|-------------------------------------------------------------|
| space       | right outer                                                 |
| backspace   | left outer                                                  |
| delete      | sequence of right inner and left outer                      |
| tab         | sequence of left inner and right outer                      |
| shift-tab   | sequence of right outer and left inner                      |
| double tab  | tripple tap on left inner                                   |
| enter       | left inner and right inner in arbitray order                |
| shift       | left inner (tab for one shot, hold for permanent)           |
| layer toggle| right inner (tab for one shot, hold for permanent)          |

Check out the file `ng_papageno_settings.c` to see how to define all this in a clearly arranged manner. 

## How to build

To build the keyboard firmware, you need
1) All requirements that are needed to build the classical QMK firmware
2) A current version of Papageno (already integrated as a submodule in the patched version of QMK)
3) The noseglasses' layout keymap files

The build process works as follows for a bash shell on GNU/Linux.

```sh
# Define for which keyboard to build (currently supported are ergodox_ez and planck)
#
KEYBOARD=ergodox_ez

# Change to your favorite build directory
# ...

# Clone QMK
#
git clone https://github.com/noseglasses/qmk_firmware.git
cd qmk_firmware
git submodule update --init lib/papageno

# Build Papageno for atmega32u4
#
cd lib/papageno
git pull origin master
mkdir -p build/atmega32u4
cd build/atmega32u4
cmake -DCMAKE_TOOLCHAIN_FILE=$PWD/../../cmake/toolchains/Toolchain-avr-gcc.cmake \
      -DPAPAGENO_PLATFORM=atmega32u4 \
      -DPAPAGENO_ADDITIONAL_INCLUDE_PATHS=$PWD/../../../../tmk_core/common \
      ../..
make

cd ../../../..

# Clone noseglasses' layout
#
git clone https://github.com/noseglasses/noseglasses_qmk_layout.git keyboards/${KEYBOARD}/keymaps/noseglasses

# Build the layout
#
make keyboard=${KEYBOARD} keymap=noseglasses
```

## Compressed builds

Compression of Papageno key sequence patterns allows to drastically reduce the resource requirements with respect to both program memory (flash memory) and RAM.

Compression is a two stage process. It involves the generation of an intermediate hex-file and a simulated execution of the latter. The intermediate file just contains the Papageno definitions and is thus not a valid firmware. It is designed to be executed by an avr-emulator on the build host to generate a compressed and compile time static version of the otherwise dynamically allocated Papageno data structures. 

The simulated/emulated execution is necessary as compressed data structures are highly architecture dependent. The compression executable must be executed on a platform that is binary compatible to the target platform, the keyboard. One reason for the use of an emulator instead of the keyboard CPU is that the compression mechanism requires more memory than the atmega32u4 (2kb) that is used for many keyboards provides. To cope with this memory restriction, we use a binary compatible atmega1280 that comes with significantly more memory (8kb). Another reason for the use of the emulator is the necessity to output data, the compressed data structures as C-code to a file, which is way more complicated when done with the keyboard. Also, no flashing of the compression executable is required.

The exported data structures as C-code are included during the second compilation stage to finally generate the actual keyboard-firmware. 

As an avr-emulator/simulator we use [simavr](https://github.com/buserror/simavr/), which, therefore, must be installed on the firmware build host.

### How to compress

The two-stage compilation process above can then be triggered using the script `compress_keymap.sh` that comes with the keymap and that must be called from the QMK root directory.

```sh
# Install simavr and make sure that it can be found via the PATH variable
#
# ...

# Change to QMK's root directory
#
cd <whatever your qmk root directory is>

# Call build automation script with full relative path
#
./keyboards/<your keyboard, e.g. ergodox_ez>/keymap/noseglasses/compress_keymap.sh
```
