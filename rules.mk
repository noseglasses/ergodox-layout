BOOTMAGIC_ENABLE=no
COMMAND_ENABLE = no        # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend
FORCE_NKRO ?= yes
DEBUG_ENABLE = no
CONSOLE_ENABLE = no
TAP_DANCE_ENABLE = no
PAPAGENO_ENABLE = yes
KEYLOGGER_ENABLE ?= no
UCIS_ENABLE = no
MOUSEKEY_ENABLE = no
AUTOLOG_ENABLE ?= no
#EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
EXTRAKEY_ENABLE = no       # Audio control and System control(+450)
NKRO_ENABLE = yes            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls

# ifeq (${KEYBOARD},planck)
# AUDIO_ENABLE = yes           # Audio output on port C6
# else
AUDIO_ENABLE = no           # Audio output on port C6
# endif
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.  Do not enable this with audio at the same time.

ifeq (${FORCE_NKRO},yes)
OPT_DEFS += -DFORCE_NKRO
endif

ifeq (${AUTOLOG_ENABLE},yes)
KEYLOGGER_ENABLE = yes
OPT_DEFS += -DAUTOLOG_ENABLE
endif

ifeq (${KEYLOGGER_ENABLE},yes)
OPT_DEFS += -DKEYLOGGER_ENABLE
CONSOLE_ENABLE = yes
endif

#OPT_DEFS += -DUSER_PRINT
# OPT_DEFS += -DDEBUG_ACTION

ifeq (${PAPAGENO_USE_COMPRESSED_DATA_STRUCTURES},yes)
	OPT_DEFS += -DPAPAGENO_USE_COMPRESSED_DATA_STRUCTURES
endif

KEYMAP_VERSION = $(shell \
 if [ -d "${KEYMAP_PATH}/.git" ]; then \
  cd "${KEYMAP_PATH}" && git describe --abbrev=6 --dirty --always --tags --match 'v*' 2>/dev/null; \
 else echo QMK; fi)

KEYMAP_BRANCH = $(shell \
 if [ -d "${KEYMAP_PATH}/.git" ]; then \
  cd "${KEYMAP_PATH}"; \
 fi; \
 git rev-parse --abbrev-ref HEAD 2>/dev/null)

OPT_DEFS += -DKEYMAP_VERSION=\"$(KEYMAP_VERSION)\\\#$(KEYMAP_BRANCH)\"
# 
# LIBDIR      := /home/flo/Software/simavr/simavr/simavr/obj-x86_64-linux-gnu
# LDFLAGS  += -Wl,-L${LIBDIR} -Wl,/home/flo/Software/simavr/simavr/simavr/obj-x86_64-linux-gnu/libsimavr.a

# LDFLAGS= -Wl,-u,vfprintfs -lprintf_min

#---------------- Library Options ----------------
# Minimalistic printf version
PRINTF_LIB_MIN = -Wl,-u,vfprintf -lprintf_min

# Floating point printf version (requires MATH_LIB = -lm below)
PRINTF_LIB_FLOAT = -Wl,-u,vfprintf -lprintf_flt

# If this is left blank, then it will use the Standard printf version.
# PRINTF_LIB = 
PRINTF_LIB = $(PRINTF_LIB_MIN)
#PRINTF_LIB = $(PRINTF_LIB_FLOAT)


LDFLAGS += $(PRINTF_LIB) 
CFLAGS += -g

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
