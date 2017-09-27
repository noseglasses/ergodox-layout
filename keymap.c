/* Copyright 2017 Florian Fleissner
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define PERMISSIVE_HOLD
#define PREVENT_STUCK_MODIFIERS

#include "config.h"

// Note that we try to determine the type of keyboard based on
// what is defined through the config.h header

#ifdef ERGODOX_EZ_CONFIG_H
   #include "ergodox_ez.h"
#else
   #include "planck.h"
#endif

#ifdef AUDIO_ENABLE
   #include "audio.h"
#endif

#include "debug.h"
#include "action_layer.h"
#include "version.h"

#include "keymap_german.h"

#include "ng_layer_settings.h"
#include "ng_portable_keymap.h"

#ifdef PAPAGENO_ENABLE
#include "ng_papageno_settings.h"
#endif

#include <avr/io.h>
#include <stdio.h>

#define UCSR0A UCSR1A
#define UDRE0 UDRE1
#define UDR0 UDR1

static int uart_putchar(char c, FILE *stream) {
   if (c == '\n')
     uart_putchar('\r', stream);
   loop_until_bit_is_set(UCSR0A, UDRE0);  
   UDR0 = c;
   return 0;
}

static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  VRSN
};

// ___  ______  ______  ______  ______  ______  ______  ______  ______  ______  
//  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)
// (______)(______)(______)(______)(______)(______)(______)(______)(______)(____
//
// Keymap definitions
//  ______  ______  ______  ______  ______  ______  ______  ______  ______  ____
// (__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  
// ___)(______)(______)(______)(______)(______)(______)(______)(______)(______)

// Hint: Print layouts with Libre Office Courier 9, A4, Landscape

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* M0: Norman Layer
 *
 * Planck
 * 
 * ,-----------------------------------------------------------------------------------.
 * |  M3  |   q  |   w  |   d  |   f  |   k  |   j  |   u  |   r  |   l  |   ;  |  M3  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  M2  |   a  |   s  |   e  |   t  |   g  |   y  |   n  |   i  |   o  |   h  |  M2  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl |   z  |   x  |   c  |   v  |   b  |   p  |   m  |   ,  |   .  |  /?  | Ctrl |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Cut/S3|Cpy/S4|Pst/S5|  Alt |Backsp|Shift |  M1  |Space | Alt  |  S1  |F7/S2 | ESC  |
 * `-----------------------------------------------------------------------------------'
 */
   
  [M0] = FF_KEYMAP(
     OSL(M3)    ,KC_Q       ,KC_W       ,KC_D       ,KC_F       ,KC_K       ,KC_J       ,KC_U       ,KC_R       ,KC_L       ,KC_SCOLON  ,OSL(M3)    ,
     OSL(M2)    ,KC_A       ,KC_S       ,KC_E       ,KC_T       ,KC_G       ,KC_Y       ,KC_N       ,KC_I       ,KC_O       ,KC_H       ,OSL(M2)    ,
     OSM(MOD_LCTL),KC_Z     ,KC_X       ,KC_C       ,KC_V       ,KC_B       ,KC_P       ,KC_M       ,KC_COMMA   ,KC_DOT     ,KC_SLASH   ,OSM(MOD_LCTL),
     LCTL(KC_X) ,LCTL(KC_C) ,LCTL(KC_V) ,OSM(MOD_LALT),KC_BSPACE,OSM(MOD_LSFT),OSL(M1)  ,KC_SPACE   ,OSM(MOD_LALT),XXXXXXXXXXX,KC_F7    ,KC_ESC
  ),

/* M1: Symbol
 *
 * Planck
 * 
 * ,-----------------------------------------------------------------------------------.
 * |******|   @  |   _  |   [  |   ]  |   ^  |   !  |   <  |   >  |   =  |   &  |******|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |******|   \  |   `  |   {  |   }  |   *  |   ?  |   (  |   )  |   -  |   :  |******|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |******|   #  |   ~  |   |  |   $  |   €  |   +  |   %  |   "  |   '  |   ;  |******|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |******|******|******|******|******|******|******|******|******|******|******|******|
 * `-----------------------------------------------------------------------------------'
 */
   
  [M1] = FF_KEYMAP(
     ___________,KC_AT      ,KC_UNDS    ,KC_LBRC    ,KC_RBRC    ,KC_CIRC    ,KC_EXLM    ,DE_LESS    ,DE_MORE    ,KC_EQL     ,KC_AMPR    ,___________,
     ___________,KC_BSLS    ,KC_GRAVE   ,KC_LCBR    ,KC_RCBR    ,KC_ASTR    ,S(KC_SLASH),KC_LPRN    ,KC_RPRN    ,KC_MINS    ,KC_COLN    ,___________,
     ___________,KC_HASH    ,KC_TILD    ,KC_PIPE    ,KC_DLR     ,ALTG(KC_5) ,KC_PLUS    ,KC_PERC    ,S(KC_QUOT) ,KC_QUOT    ,KC_SCLN    ,___________,
     ___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________
   ),
   
/* M2: Navigation & Number Blocks

 * Planck
 * 
 * ,-----------------------------------------------------------------------------------.
 * |******| PgUp | Bksp |  Up  |  DEL | PgDn |      |   7  |   8  |   9  |      |******|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |******| Home |  Lft | Down | Right| End  |      |   4  |   5  |   6  |   .  |******|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |******|      |  Tab |      | Enter|      |   0  |   1  |   2  |   3  |   ,  |******|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |******|******|******|******|******|******|******|******|******|******|******|******|
 * `-----------------------------------------------------------------------------------'
 */
   
  [M2] = FF_KEYMAP(
     ___________,KC_PGUP    ,KC_BSPC    ,KC_UP      ,KC_DEL     ,KC_PGDN    ,XXXXXXXXXXX,KC_7       ,KC_8       ,KC_9       ,XXXXXXXXXXX,___________,
     ___________,KC_HOME    ,KC_LEFT    ,KC_DOWN    ,KC_RGHT    ,KC_END     ,XXXXXXXXXXX,KC_4       ,KC_5       ,KC_6       ,KC_DOT     ,___________,
     ___________,XXXXXXXXXXX,KC_TAB     ,XXXXXXXXXXX,KC_ENT     ,XXXXXXXXXXX,KC_0       ,KC_1       ,KC_2       ,KC_3       ,KC_COMM    ,___________,
     ___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________
   ),

/* M3: Function & Media Keys

 * Planck
 * 
 * ,-----------------------------------------------------------------------------------.
 * |******|      | Print|Scroll|Pause |      |      |  F7  |  F8  |  F9  |  F12 |******|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |******|      | Mute | Vol- | Vol+ |      |   Â³ |  F4  |  F5  |  F6  |  F11 |******|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |******|      | Prev | Play | Next |      |   Â² |  F1  |  F2  |  F3  |  F10 |******|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |******|******|******|******|******|******|******|******|******|******|******|******|
 * `-----------------------------------------------------------------------------------'
 */
   
  [M3] = FF_KEYMAP(
     ___________,XXXXXXXXXXX,KC_PSCR    ,KC_SLCK    ,KC_PAUS    ,XXXXXXXXXXX,XXXXXXXXXXX,KC_F7      ,KC_F8      ,KC_F9      ,KC_F12     ,___________,  
     ___________,XXXXXXXXXXX,KC_MUTE    ,KC_VOLD    ,KC_VOLU    ,XXXXXXXXXXX,DE_SQ3     ,KC_F4      ,KC_F5      ,KC_F6      ,KC_F11     ,___________,
     ___________,XXXXXXXXXXX,KC_MPRV    ,KC_MPLY    ,KC_MNXT    ,XXXXXXXXXXX,DE_SQ2     ,KC_F1      ,KC_F2      ,KC_F3      ,KC_F10     ,___________,
     ___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________
  )
};


#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
//float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
// float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
// float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
// float tone_plover[][2]     = SONG(PLOVER_SOUND);
// float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif

#if 0
    /* left hand, spatial positions */                          
    k00,k01,k02,k03,k04,k05,k06,                                
    k10,k11,k12,k13,k14,k15,k16,                                
    k20,k21,k22,k23,k24,k25,                                    
    k30,k31,k32,k33,k34,k35,k36,                                
    k40,k41,k42,k43,k44,                                        
                            k55,k56,                            
                                k54,                            
                        k53,k52,k51,                            
                                                                
    /* right hand, spatial positions */                         
        k07,k08,k09,k0A,k0B,k0C,k0D,                            
        k17,k18,k19,k1A,k1B,k1C,k1D,                            
            k28,k29,k2A,k2B,k2C,k2D,                            
        k37,k38,k39,k3A,k3B,k3C,k3D,                            
                k49,k4A,k4B,k4C,k4D,                            
    k57,k58,                                                    
    k59,                                                        
    k5C,k5B,k5A

#endif

// ___  ______  ______  ______  ______  ______  ______  ______  ______  ______  
//  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)
// (______)(______)(______)(______)(______)(______)(______)(______)(______)(____
//
// Definitions for using this keymap with both ErgoDox and Planck
//  ______  ______  ______  ______  ______  ______  ______  ______  ______  ____
// (__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  
// ___)(______)(______)(______)(______)(______)(______)(______)(______)(______)

/* ,-----------------------------------------------------------------------------------.
 * |  X1  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |  10  |  X4  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  X2  |  11  |  12  |  13  |  14  |  15  |  16  |  17  |  18  |  19  |  20  |  X5  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  X3  |  21  |  22  |  23  |  24  |  25  |  26  |  27  |  28  |  29  |  30  |  X6  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  31  |  32  |  33  |  34  |  35  |  36  |  37  |  38  |  39  |  40  |  41  |  42  |
 * `-----------------------------------------------------------------------------------'
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
 
  switch (keycode) {
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) { 
   
   stdout = &mystdout;
   
   #ifdef PAPAGENO_ENABLE
   init_papageno();
   #endif
       
   #ifdef AUDIO_ENABLE
   startup_user();
   #endif
}

void matrix_scan_user(void) {
    
//    PPG_LOG("Matrix scan user\n");
   
#ifdef ERGODOX_EZ_CONFIG_H
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }
#endif

   #ifdef PAPAGENO_ENABLE
   ppg_qmk_matrix_scan();
   #endif
};

#ifdef AUDIO_ENABLE

void startup_user(void)
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user(void)
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
