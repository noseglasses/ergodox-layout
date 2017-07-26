# noseglasses' layout

This is my personal layout for the [ErgoDox EZ](https://ergodox-ez.com/).

*Please note:* This layout uses [Papageno](https://github.com/noseglasses/papageno) to process special key combinations. Papageno is currently not officially integrated with the [QMK firmware](https://github.com/qmk/qmk_firmware/) therefore to build it, you need a patched version of QMK you can find [here](https://github.com/noseglasses/qmk_firmware).

## Special Features   

At first glance, my layout is quite ordinary. It uses two layers for normal
characters and special characters and some more layers for other stuff. However,
some of the other layers `(2 - ..)` are currently inactive.

What's special about this keymap is the use of the thumb keys. I want to do as much
work as possible with my thumbs and specially on the four large ErgoDox thumb keys as they are most convenient to reach. 

Therefore, I assign key combinations to them that trigger 

* space,
* backspace,
* tab,
* shift-tab (untab),
* double tab (e.g. for auto completion),
* enter,
* shift (one-shot) and
* layer toggle to symbol layer (one-shot).

A similar assignment could of course also be achieved by using tap dances. 
But to me it seems more healthy to tap two keys with two 
different thumbs in a row than with the same thumb. This is where [Papageno](https://github.com/noseglasses/papageno), a pattern-matching libray comes in.
It enables the definition of key sequences, chords and clusters. Even combinations
of all of those are possible.
It is possible to use matrix key-positions but also keycodes to define
sequences, chords and clusters.

In this way we can easily handle eight different actions, i.d. keys being send, with just four different keys. And it would be possible to add even more functionality to the same four thumb keys.
And all this without any keys permanently held. Neat?

The following provides a description of the exact assignments between keys pressed and keys send.
Here left/right, inner/outer refers to ErgoDox's four large thumb keys.

| Key Send    | ErgoDox Thumb Keys Involved                                 |
|-------------|-------------------------------------------------------------|
| space       | right outer                                                 |
| backspace   | left outer                                                  |
| tab         | sequence of left inner and right outer                      |
| shift-tab   | sequence of right outre and left inner                      |
| double tab  | tripple tap on left inner                                   |
| enter       | left inner and right inner in arbitray order                |
| shift       | left inner (tab for one shot, hold for permanent)           |
| layer toggle| right inner (tab for one shot, hold for permanent)          |

Check out the `keymap.c` to see how to define all this in a clearly arranged manner. 

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
git submodule update --init lib/papageno

# Build Papageno for avr-gcc
#
cd lib/papageno
git pull origin master
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
