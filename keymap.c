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
// #define PREVENT_STUCK_MODIFIERS

#include "config.h"

// Note that we try to determine the type of keyboard based on
// what is defined through the config.h header

#ifdef KEYBOARDS_ERGODOX_CONFIG_H_

   // Define SUBPROJECT_ez explicitly to ensure that
   // it is define during compression builds
   //
   #ifndef SUBPROJECT_ez
   #define SUBPROJECT_ez
   #endif

   #include "ergodox.h"
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

#ifdef PAPAGENO_ENABLE
#include "process_papageno.h"
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

enum ff_layers {
   M0 = 0,
   M1,
   M2,
   M3
};

#define ___________ KC_TRANSPARENT
#define XXXXXXXXXXX KC_NO

#define fXX KC_NO

// ___  ______  ______  ______  ______  ______  ______  ______  ______  ______  
//  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)
// (______)(______)(______)(______)(______)(______)(______)(______)(______)(____
//
// ErgoDox and Planck keyboard definitions
//  ______  ______  ______  ______  ______  ______  ______  ______  ______  ____
// (__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  
// ___)(______)(______)(______)(______)(______)(______)(______)(______)(______)

#ifdef KEYBOARDS_ERGODOX_CONFIG_H_

// Keymap for ErgoDox EZ
//
#define FF_KEYMAP( \
    X1 ,k11,k12,k13,k14,k15,k18,k19,k1A,k1B,k1C,X4 , \
    X2 ,k21,k22,k23,k24,k25,k28,k29,k2A,k2B,k2C,X5 , \
    X3 ,k31,k32,k33,k34,k35,k38,k39,k3A,k3B,k3C,X6 , \
    k40,k41,k42,k43,k53,k52,k5B,k5A,k4A,k4B,k4C,k4D \
) \
   KEYMAP( \
      /* left hand, spatial positions */                          \
      fXX,fXX,fXX,fXX,fXX,fXX,LCTL(KC_X),                         \
      X1 ,k11,k12,k13,k14,k15,LCTL(KC_C),                         \
      X2 ,k21,k22,k23,k24,k25,                                    \
      X3 ,k31,k32,k33,k34,k35,LCTL(KC_V),                         \
      k40,k41,k42,k43,fXX,                                        \
                              fXX,fXX,                            \
                                 fXX,                             \
                           k53,k52,fXX,                           \
                                                                  \
      /* right hand, spatial positions */                         \
         fXX,fXX,fXX,fXX,fXX,fXX,fXX,                             \
         KC_F8,k18,k19,k1A,k1B,k1C,X4 ,                           \
               k28,k29,k2A,k2B,k2C,X5 ,                           \
         KC_F7,k38,k39,k3A,k3B,k3C,X6 ,                           \
                   fXX,k4A,k4B,k4C,k4D,                           \
      fXX,fXX,                                                    \
      fXX,                                                        \
      fXX,k5B,k5A                                                 \
   )    

// Define a bunch of key aliases for transparent 
// naming of keys
   
#define NG_KEY_X1  1, 0
#define NG_KEY_01  1, 1
#define NG_KEY_02  1, 2
#define NG_KEY_03  1, 3
#define NG_KEY_04  1, 4
#define NG_KEY_05  1, 5
#define NG_KEY_06  1, 8
#define NG_KEY_07  1, 9
#define NG_KEY_08  1, A
#define NG_KEY_09  1, B
#define NG_KEY_10  1, C
#define NG_KEY_X4  1, D
   
#define NG_KEY_X2  2, 0
#define NG_KEY_11  2, 1
#define NG_KEY_12  2, 2
#define NG_KEY_13  2, 3
#define NG_KEY_14  2, 4
#define NG_KEY_15  2, 5
#define NG_KEY_16  2, 8
#define NG_KEY_17  2, 9
#define NG_KEY_18  2, A
#define NG_KEY_19  2, B
#define NG_KEY_20  2, C
#define NG_KEY_X5  2, D
   
#define NG_KEY_X3  3, 0
#define NG_KEY_21  3, 1
#define NG_KEY_22  3, 2
#define NG_KEY_23  3, 3
#define NG_KEY_24  3, 4
#define NG_KEY_25  3, 5
#define NG_KEY_26  3, 8
#define NG_KEY_27  3, 9
#define NG_KEY_28  3, A
#define NG_KEY_29  3, B
#define NG_KEY_30  3, C
#define NG_KEY_X6  3, D
   
#define NG_KEY_31  4, 0
#define NG_KEY_32  4, 1
#define NG_KEY_33  4, 2
#define NG_KEY_34  4, 3
#define NG_KEY_35  5, 3
#define NG_KEY_36  5, 2
#define NG_KEY_37  5, B
#define NG_KEY_38  5, A
#define NG_KEY_39  4, A
#define NG_KEY_40  4, B
#define NG_KEY_41  4, C
#define NG_KEY_42  4, D

#define NG_KEYPOS(KEY_ALIAS, S) PPG_QMK_KEYPOS_HEX(KEY_ALIAS, S)
#else
   
// Keymap for Planck
//
#define FF_KEYMAP PLANCK_GRID

// Define a bunch of key aliases for transparent 
// naming of keys
   
#define NG_KEY_X1  0, 0
#define NG_KEY_01  0, 1
#define NG_KEY_02  0, 2
#define NG_KEY_03  0, 3
#define NG_KEY_04  0, 4
#define NG_KEY_05  0, 5
#define NG_KEY_06  0, 6
#define NG_KEY_07  0, 7
#define NG_KEY_08  0, 8
#define NG_KEY_09  0, 9
#define NG_KEY_10  0, A
#define NG_KEY_X4  0, B
   
#define NG_KEY_X2  1, 0
#define NG_KEY_11  1, 1
#define NG_KEY_12  1, 2
#define NG_KEY_13  1, 3
#define NG_KEY_14  1, 4
#define NG_KEY_15  1, 5
#define NG_KEY_16  1, 6
#define NG_KEY_17  1, 7
#define NG_KEY_18  1, 8
#define NG_KEY_19  1, 9
#define NG_KEY_20  1, A
#define NG_KEY_X5  1, B
   
#define NG_KEY_X3  2, 0
#define NG_KEY_21  2, 1
#define NG_KEY_22  2, 2
#define NG_KEY_23  2, 3
#define NG_KEY_24  2, 4
#define NG_KEY_25  2, 5
#define NG_KEY_26  2, 6
#define NG_KEY_27  2, 7
#define NG_KEY_28  2, 8
#define NG_KEY_29  2, 9
#define NG_KEY_30  2, A
#define NG_KEY_X6  2, B
   
#define NG_KEY_31  3, 0
#define NG_KEY_32  3, 1
#define NG_KEY_33  3, 2
#define NG_KEY_34  3, 3
#define NG_KEY_35  3, 4
#define NG_KEY_36  3, 5
#define NG_KEY_37  3, 6
#define NG_KEY_38  3, 7
#define NG_KEY_39  3, 8
#define NG_KEY_40  3, 9
#define NG_KEY_41  3, A
#define NG_KEY_42  3, B

#define NG_SWAP_ROW_COL(ROW, COL) COL, ROW

// Planck swaps rows and cols in comparison to planck (or vice versa?)
//
#define NG_KEYPOS(KEY_ALIAS, S) PPG_QMK_KEYPOS_HEX(NG_SWAP_ROW_COL(KEY_ALIAS), S)

#endif

/* The general key relation between ErgoDox EZ and Planck is
 *
 * ,--------------------------------------------------------.           ,--------------------------------------------------------.
 * |        |      |      |      |      |      |  Ctrl+x    |           |            |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------------|           |------------+------+------+------+------+------+--------|
 * |   X1   |   1  |   2  |   3  |   4  |   5  |  Ctrl+c    |           |    F8      |   6  |   7  |   8  |   9  |  10  |   X4   |
 * |--------+------+------+------+------+------|            |           |            |------+------+------+------+------+--------|
 * |   X2   |  11  |  12  |  13  |  14  |  15  |------------|           |------------|  16  |  17  |  18  |  19  |  20  |   X5   |
 * |--------+------+------+------+------+------|  Ctrl+v    |           |    F7      |------+------+------+------+------+--------|
 * |   X3   |  21  |  22  |  23  |  24  |  25  |            |           |            |  26  |  27  |  28  |  29  |  30  |   X6   |
 * `--------+------+------+------+------+-------------------'           `------------+------+------+------+------+------+--------'
 *   |  31  |  32  |  33  |  34  |      |                                                   |      |  39  |  40  |  41  |  42  |
 *   `----------------------------------'                                                   `----------------------------------'
 *                                              ,-------------.       ,-------------.
 *                                              |      |      |       |      |      |       
 *                                       ,------|------|------|       |------+------+------.
 *                                       |      |      |      |       |      |      |      |
 *                                       |  35  |  36  |------|       |------|  37  |  38  |
 *                                       |      |      |      |       |      |      |      |
 *                                       `--------------------'       `--------------------'
 * 
 * Planck
 * 
 * ,-----------------------------------------------------------------------------------.
 * |  X1  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |  10  |  X4  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  X2  |  11  |  12  |  13  |  14  |  15  |  16  |  17  |  18  |  19  |  20  |  X5  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  X3  |  21  |  22  |  23  |  24  |  25  |  26  |  27  |  28  |  29  |  30  |  X6  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  31  |  32  |  33  |  34  |  35  |  36  |  37  |  38  |  39  |  40  |  41  |  42  |
 * `-----------------------------------------------------------------------------------'
 * 
 * Note: Keys number 40 and 41 are special keys (S1 and S2 for extended one hand usage)
 */

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
     OSL(M2)    ,KC_A       ,KC_S       ,KC_E       ,KC_T       ,LT(M1,KC_G),KC_Y       ,KC_N       ,KC_I       ,KC_O       ,KC_H       ,OSL(M2)    ,
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
 * |******|   \  |   /  |   {  |   }  |   *  |   ?  |   (  |   )  |   -  |   :  |******|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |******|   #  |   ~  |   |  |   $  |   €  |   +  |   %  |   "  |   '  |   ;  |******|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |******|******|******|******|******|******|******|******|******|******|******|******|
 * `-----------------------------------------------------------------------------------'
 */
   
  [M1] = FF_KEYMAP(
     ___________,KC_AT      ,KC_UNDS    ,KC_LBRC    ,KC_RBRC    ,KC_CIRC    ,KC_EXLM    ,DE_LESS    ,DE_MORE    ,KC_EQL     ,KC_AMPR    ,___________,
     ___________,KC_BSLS    ,KC_SLSH    ,KC_LCBR    ,KC_RCBR    ,KC_ASTR    ,S(KC_SLASH),KC_LPRN    ,KC_RPRN    ,KC_MINS    ,KC_COLN    ,___________,
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

#ifdef PAPAGENO_ENABLE

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
// Definitions for using Papageno with both ErgoDox and Planck
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
// Define a bunch of key positions that are going to be used as 
// Papageno inputs. 
//
// Important: Every key macro must feature 
//            the auxiliary macro parameter S
//

#define LEFT_INNER_THUMB_KEY(S)     NG_KEYPOS(NG_KEY_36, S)
#define LEFT_OUTER_THUMB_KEY(S)     NG_KEYPOS(NG_KEY_35, S)

#define RIGHT_INNER_THUMB_KEY(S)    NG_KEYPOS(NG_KEY_37, S)
#define RIGHT_OUTER_THUMB_KEY(S)    NG_KEYPOS(NG_KEY_38, S)

#define SPECIAL_KEY_1(S)            NG_KEYPOS(NG_KEY_40, S)
#define SPECIAL_KEY_2(S)            NG_KEYPOS(NG_KEY_41, S)
#define SPECIAL_KEY_3(S)            NG_KEYPOS(NG_KEY_31, S)
#define SPECIAL_KEY_4(S)            NG_KEYPOS(NG_KEY_32, S)
#define SPECIAL_KEY_5(S)            NG_KEYPOS(NG_KEY_33, S)

// Define alphabetic keys for norman layout. 
//
// These definition are e.g. useful to map alphabetic characters
// to key positions.
//
#define ALPH_KEY_A(S)               NG_KEYPOS(NG_KEY_11, S)
#define ALPH_KEY_B(S)               NG_KEYPOS(NG_KEY_25, S)
#define ALPH_KEY_C(S)               NG_KEYPOS(NG_KEY_23, S)
#define ALPH_KEY_D(S)               NG_KEYPOS(NG_KEY_03, S)
#define ALPH_KEY_E(S)               NG_KEYPOS(NG_KEY_13, S)
#define ALPH_KEY_F(S)               NG_KEYPOS(NG_KEY_04, S)
#define ALPH_KEY_G(S)               NG_KEYPOS(NG_KEY_15, S)
#define ALPH_KEY_H(S)               NG_KEYPOS(NG_KEY_20, S)
#define ALPH_KEY_I(S)               NG_KEYPOS(NG_KEY_18, S)
#define ALPH_KEY_J(S)               NG_KEYPOS(NG_KEY_06, S)
#define ALPH_KEY_K(S)               NG_KEYPOS(NG_KEY_05, S)
#define ALPH_KEY_L(S)               NG_KEYPOS(NG_KEY_09, S)
#define ALPH_KEY_M(S)               NG_KEYPOS(NG_KEY_27, S)
#define ALPH_KEY_N(S)               NG_KEYPOS(NG_KEY_17, S)
#define ALPH_KEY_O(S)               NG_KEYPOS(NG_KEY_19, S)
#define ALPH_KEY_P(S)               NG_KEYPOS(NG_KEY_26, S)
#define ALPH_KEY_Q(S)               NG_KEYPOS(NG_KEY_01, S)
#define ALPH_KEY_R(S)               NG_KEYPOS(NG_KEY_08, S)
#define ALPH_KEY_S(S)               NG_KEYPOS(NG_KEY_12, S)
#define ALPH_KEY_T(S)               NG_KEYPOS(NG_KEY_14, S)
#define ALPH_KEY_U(S)               NG_KEYPOS(NG_KEY_07, S)
#define ALPH_KEY_V(S)               NG_KEYPOS(NG_KEY_24, S)
#define ALPH_KEY_W(S)               NG_KEYPOS(NG_KEY_02, S)
#define ALPH_KEY_X(S)               NG_KEYPOS(NG_KEY_22, S)
#define ALPH_KEY_Y(S)               NG_KEYPOS(NG_KEY_16, S)
#define ALPH_KEY_Z(S)               NG_KEYPOS(NG_KEY_21, S)

#define PPG_QMK_MATRIX_POSITION_INPUTS_ALPHABETIC(OP) \
__NL__      OP(ALPH_KEY_A) \
__NL__      OP(ALPH_KEY_B) \
__NL__      OP(ALPH_KEY_C) \
__NL__      OP(ALPH_KEY_D) \
__NL__      OP(ALPH_KEY_E) \
__NL__      OP(ALPH_KEY_F) \
__NL__      OP(ALPH_KEY_G) \
__NL__      OP(ALPH_KEY_H) \
__NL__      OP(ALPH_KEY_I) \
__NL__      OP(ALPH_KEY_J) \
__NL__      OP(ALPH_KEY_K) \
__NL__      OP(ALPH_KEY_L) \
__NL__      OP(ALPH_KEY_M) \
__NL__      OP(ALPH_KEY_N) \
__NL__      OP(ALPH_KEY_O) \
__NL__      OP(ALPH_KEY_P) \
__NL__      OP(ALPH_KEY_Q) \
__NL__      OP(ALPH_KEY_R) \
__NL__      OP(ALPH_KEY_S) \
__NL__      OP(ALPH_KEY_T) \
__NL__      OP(ALPH_KEY_U) \
__NL__      OP(ALPH_KEY_V) \
__NL__      OP(ALPH_KEY_W) \
__NL__      OP(ALPH_KEY_X) \
__NL__      OP(ALPH_KEY_Y) \
__NL__      OP(ALPH_KEY_Z)

// Define a set of Papageno inputs that are associated with
// keyboard matrix positions.
//
// Important: - The macro must be named PPG_QMK_MATRIX_POSITION_INPUTS!
//            - If no inputs are supposed to be associated with
//              matrix positions, define an empty PPG_QMK_MATRIX_POSITION_INPUTS
//
#define PPG_QMK_MATRIX_POSITION_INPUTS(OP) \
\
__NL__      OP(LEFT_INNER_THUMB_KEY) \
__NL__      OP(LEFT_OUTER_THUMB_KEY) \
__NL__      OP(RIGHT_INNER_THUMB_KEY) \
__NL__      OP(RIGHT_OUTER_THUMB_KEY) \
\
__NL__      OP(SPECIAL_KEY_1) \
__NL__      OP(SPECIAL_KEY_2) \
__NL__      OP(SPECIAL_KEY_3) \
__NL__      OP(SPECIAL_KEY_4) \
__NL__      OP(SPECIAL_KEY_5) \
\
__NL__      PPG_QMK_MATRIX_POSITION_INPUTS_ALPHABETIC(OP)

// Define a set of Papageno inputs that are associated with
// qmk keycodes.
//
// Important: - The macro must be named PPG_QMK_KEYCOKC_INPUTS!
//            - If no inputs are supposed to be associated with
//              keycodes, define an empty PPG_QMK_KEYCOKC_INPUTS
//
#define PPG_QMK_KEYCODE_INPUTS(OP)
   
// Initialize Papageno data structures for qmk
// This is based on the definitions of 
//
//    PPG_QMK_MATRIX_POSITION_INPUTS
//
// and
//
//    PPG_QMK_KEYCODE_INPUTS
//
PPG_QMK_INIT_DATA_STRUCTURES

// ___  ______  ______  ______  ______  ______  ______  ______  ______  ______  
//  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)
// (______)(______)(______)(______)(______)(______)(______)(______)(______)(____
//
// Definitions of inventory for Papageno leader sequences
//  ______  ______  ______  ______  ______  ______  ______  ______  ______  ____
// (__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  
// ___)(______)(______)(______)(______)(______)(______)(______)(______)(______)

#define NG_GLUE_AUX(S1, S2) S1##S2
#define NG_GLUE(S1, S2) NG_GLUE_AUX(S1, S2)
   
#define NG_ALPH_CASE(LOWER_CASE_QUOTED, UPPER_CASE_QUOTED, ID) \
__NL__         case LOWER_CASE_QUOTED: \
__NL__         case UPPER_CASE_QUOTED: \
__NL__            return PPG_QMK_KEYPOS_ENUM(NG_GLUE(ALPH_KEY_, ID));

// Define an input lookup function that maps alphabetic characters
// to inputs. This is based on the definition of the macros ALPH_KEY_*
// above. If you use a different keylayout (i.e. not Norman) change
// the definitions of ALPH_KEY_* accordingly.
//
PPG_Input_Id ng_input_from_alphabetic_character(char c) {
   
   switch(c) {
      NG_ALPH_CASE('a', 'A', A)
      NG_ALPH_CASE('b', 'B', B)
      NG_ALPH_CASE('c', 'C', C)
      NG_ALPH_CASE('d', 'D', D)
      NG_ALPH_CASE('e', 'E', E)
      NG_ALPH_CASE('f', 'F', F)
      NG_ALPH_CASE('g', 'G', G)
      NG_ALPH_CASE('h', 'H', H)
      NG_ALPH_CASE('i', 'I', I)
      NG_ALPH_CASE('j', 'J', J)
      NG_ALPH_CASE('k', 'K', K)
      NG_ALPH_CASE('l', 'L', L)
      NG_ALPH_CASE('m', 'M', M)
      NG_ALPH_CASE('n', 'N', N)
      NG_ALPH_CASE('o', 'O', O)
      NG_ALPH_CASE('p', 'P', P)
      NG_ALPH_CASE('q', 'Q', Q)
      NG_ALPH_CASE('r', 'R', R)
      NG_ALPH_CASE('s', 'S', S)
      NG_ALPH_CASE('t', 'T', T)
      NG_ALPH_CASE('u', 'U', U)
      NG_ALPH_CASE('v', 'V', V)
      NG_ALPH_CASE('w', 'W', W)
      NG_ALPH_CASE('x', 'X', X)
      NG_ALPH_CASE('y', 'Y', Y)
      NG_ALPH_CASE('z', 'Z', Z)
   }
   
   return 0;
}

// This demonstrates the use of Papageno to process leader
// keys. Currently we do nothing else than replace some keywords
// with their upper case representations.

const char string_1[] PROGMEM = "cool";
const char string_2[] PROGMEM = "cat";
const char string_3[] PROGMEM = "dog";

PGM_P const ng_magic_word_table[] PROGMEM = 
{
   string_1,
   string_2,
   string_3
};

void ng_get_magic_word_string(uint8_t magic_word_id,
                              char *buffer, 
                              uint8_t max_chars)
{
   strncpy_P(buffer, 
             (PGM_P)pgm_read_word(
                  &(ng_magic_word_table[magic_word_id])), 
             max_chars);
}

// This is the action callback that is executed when
// a leader matches. 
// Turns the string uppercase and adds some decoration.
//
static void ng_print_magic_word(bool activation, void *user_data)
{
   if(!activation) { return; }
   
   uint8_t pos = (uint8_t)(uintptr_t)user_data;
   
//    uprintf("pos: %d\n", pos);
   
   char buffer[PPG_MAX_SEQUENCE_LENGTH];
   
   strncpy_P(buffer, (PGM_P)pgm_read_word(&(ng_magic_word_table[pos])), PPG_MAX_SEQUENCE_LENGTH);
   
//    uprintf("leader: %s\n", buffer);

   register_code16(KC_ASTR);
   unregister_code16(KC_ASTR);
   register_code16(KC_ASTR);
   unregister_code16(KC_ASTR);
   register_code16(KC_ASTR);
   unregister_code16(KC_ASTR);
      
   for(int i = 0; buffer[i]; i++) {
      
      uint8_t kc = 0;
      char c = buffer[i];

      switch (c) {
         case '0':
            kc = KC_0;
            break;
         case '1' ... '9':
            kc = c - '1' + KC_1;
            break;
         case 'a' ... 'z':
            kc = c - 'a' + KC_A;
            break;
         case 'A' ... 'Z':
            kc = c - 'A' + KC_A;
            break;
      }

      if (kc) {
         register_code16(S(kc));
         unregister_code16(S(kc));
         wait_ms(10);
      }
   }  
   
   register_code16(KC_ASTR);
   unregister_code16(KC_ASTR);
   register_code16(KC_ASTR);
   unregister_code16(KC_ASTR);
   register_code16(KC_ASTR);
   unregister_code16(KC_ASTR);
}

// A helper function that returns actions that are associated
// with leader sequences.
//
PPG_Action ng_get_magic_word_string_action(uint8_t magic_word_id)
{
   return PPG_ACTION_USER_CALLBACK(
      ng_print_magic_word,
      (void*)(uintptr_t)magic_word_id
   );
}

// User callback the emulates double tab for
// shell auto completion
//
void double_tab_callback(bool activation, void *user_data)
{
   if(!activation) { return; }
   
   register_code (KC_TAB);
   unregister_code (KC_TAB);
   register_code (KC_TAB);
   unregister_code (KC_TAB);
}

// User callback that repeats the most recent shell
// command
//
void repeat_last_command_callback(bool activation, void *user_data)
{
   if(!activation) { return; }
   
   register_code (KC_UP);
   unregister_code (KC_UP);
   register_code (KC_ENTER);
   unregister_code (KC_ENTER);
}

// Issues a search command that can be used with
// any editor that is configured in a way that F1
// opens the search entry with the string that the cursor
// currently rests on.
//
void ordinary_search_command_callback(bool activation, void *user_data)
{
   if(!activation) { return; }
   
   register_code16 (KC_F1);
   unregister_code16 (KC_F1);
   register_code (KC_ENTER);
   unregister_code (KC_ENTER);
}

// Similar the search callback above, but for a search
// in multiple files. This works with editors
// that have been customized to feature Shift+F1
// as command to open the search-in-files menu.
//
void file_search_command_callback(bool activation, void *user_data)
{
   if(!activation) { return; }
   
   register_code16 (S(KC_F1));
   send_keyboard_report();
   unregister_code16 (S(KC_F1));
   send_keyboard_report();
   register_code (KC_ENTER);
   unregister_code (KC_ENTER);
}

// We need a callback to trigger the keyboard reset (to flash firmware)
// as the RESET keycode is processed by the qmk system and is
// for specific reason not available as Papageno keycode action.
//
void reset_callback(bool activation, void *user_data)
{
   if(!activation) { return; }
   
   reset_keyboard();
}

// ___  ______  ______  ______  ______  ______  ______  ______  ______  ______  
//  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)
// (______)(______)(______)(______)(______)(______)(______)(______)(______)(____
//
// Definitions of Papageno patterns, tap-dances and leader sequences
//  ______  ______  ______  ______  ______  ______  ______  ______  ______  ____
// (__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  
// ___)(______)(______)(______)(______)(______)(______)(______)(______)(______)

void init_papageno(void)
{
   PPG_QMK_INIT
   
   // Only list symbols here that are required after initialization
   //
   // Note: The functions passed as PPG_Leader_Functions are only required
   //       during setup.
   // 
   PPG_QMK_COMPRESSION_REGISTER_SYMBOL(double_tab_callback)
   PPG_QMK_COMPRESSION_REGISTER_SYMBOL(repeat_last_command_callback)
   PPG_QMK_COMPRESSION_REGISTER_SYMBOL(ordinary_search_command_callback)
   PPG_QMK_COMPRESSION_REGISTER_SYMBOL(file_search_command_callback)
   PPG_QMK_COMPRESSION_REGISTER_SYMBOL(reset_callback)
   
   ppg_qmk_set_timeout_ms(200);
   
   /* Allow left inner and right inner thumb key to trigger key enter if
    * clustered.
    */
   PPG_QMK_KEYPOS_CLUSTER_ACTION_KEYCODE(
      M0, // Layer
      KC_ENTER, // Keycode action
      // Matrix keypos...
      LEFT_INNER_THUMB_KEY, // left inner large thumb key
      RIGHT_INNER_THUMB_KEY  // right inner large thumb key
   );
   
   /* Allow double tap of the left inner thumb key to be an alternative 
    * for double tab (shell completion).
    */
   ppg_tap_dance(
      M0,
      PPG_QMK_INPUT_FROM_KEYPOS_ALIAS(LEFT_INNER_THUMB_KEY), /* The tap key
         could also be a keycode using PPG_QMK_INPUT_FROM_KEYCOKC_ALIAS */
      PPG_TAP_DEFINITIONS(
         PPG_TAP(
            2, 
            PPG_ACTION_USER_CALLBACK(
               double_tab_callback,
               NULL
            )
         )
      )
   );
      
   /* Allow left inner and right outer thumb key to trigger key tab if
    * clustered.
    */
   PPG_QMK_KEYPOS_NOTE_LINE_ACTION_KEYCODE(
      M0, // Layer
      KC_TAB, // Keycode action
      // Matrix keypos...
      LEFT_INNER_THUMB_KEY, // left inner large thumb key
      RIGHT_OUTER_THUMB_KEY  // right outer large thumb key
   );
         
   /* Allow left inner and right outer thumb key to trigger key untab if
    * clustered.
    */
   PPG_QMK_KEYPOS_NOTE_LINE_ACTION_KEYCODE(
      M0, // Layer
      LSFT(KC_TAB), // Keycode action  
      // Matrix keypos...
      RIGHT_OUTER_THUMB_KEY,  // right outer large thumb key
      LEFT_INNER_THUMB_KEY // left inner large thumb key
   );
   
   /* Allow left outer and right inner thumb key to trigger Del key if
    * clustered.
    */
   PPG_QMK_KEYPOS_NOTE_LINE_ACTION_KEYCODE(
      M0, // Layer
      KC_DEL, // Keycode action  
      // Matrix keypos...
      RIGHT_INNER_THUMB_KEY,  // right outer large thumb key
      LEFT_OUTER_THUMB_KEY // left inner large thumb key
   );
   
   // Double tap on S1 repeats last command (Up, Enter)
   //
   ppg_tap_dance(
      M0,
      PPG_QMK_INPUT_FROM_KEYPOS_ALIAS(SPECIAL_KEY_1),
      PPG_TAP_DEFINITIONS(
         PPG_TAP(
            2, 
            PPG_ACTION_USER_CALLBACK(
               repeat_last_command_callback,
               NULL
            )
         )
      )
   );
   
   // Double tap on S3 triggers F1 (customized search command)
   // Triple tap on S3 triggers Shift+F1 (customized search in files)
   //
   ppg_tap_dance(
      M0,
      PPG_QMK_INPUT_FROM_KEYPOS_ALIAS(SPECIAL_KEY_3), 
      PPG_TAP_DEFINITIONS(
         PPG_TAP(
            2, 
            PPG_ACTION_USER_CALLBACK(
               ordinary_search_command_callback,
               NULL
            )
         ),
         PPG_TAP(
            3, 
            PPG_ACTION_USER_CALLBACK(
               file_search_command_callback,
               NULL
            )
         ),
         PPG_TAP(
            5, 
            PPG_ACTION_USER_CALLBACK(
               reset_callback,
               NULL
            )
         )
      )
   );
   
   // Double tap on S4 triggers F2 (customized replace)
   //
   ppg_tap_dance(
      M0,
      PPG_QMK_INPUT_FROM_KEYPOS_ALIAS(SPECIAL_KEY_4), 
      PPG_TAP_DEFINITIONS(
         PPG_TAP(
            2, 
            PPG_QMK_ACTION_KEYCODE(
               KC_F2
            )
         )
      )
   );
      
   // Double tap on S5 triggers F3 (customized continue search)
   //
   ppg_tap_dance(
      M0,
      PPG_QMK_INPUT_FROM_KEYPOS_ALIAS(SPECIAL_KEY_5), 
      PPG_TAP_DEFINITIONS(
         PPG_TAP(
            2, 
            PPG_QMK_ACTION_KEYCODE(
               KC_F3
            )
         )
      )
   );
   
   // Tap dances for german umlauts (ä, ö, ü, ß)
   //
   // These are used together with the EURKEY keyboard layout
   // that is available on Linux and Windows
   
   ppg_tap_dance(
      M0,
      PPG_QMK_INPUT_FROM_KEYPOS_ALIAS(ALPH_KEY_A), 
      PPG_TAP_DEFINITIONS(
         PPG_TAP(
            3, 
            PPG_QMK_ACTION_KEYCODE(
               RALT(KC_A)
            )
         )
      )
   );
   
   ppg_tap_dance(
      M0,
      PPG_QMK_INPUT_FROM_KEYPOS_ALIAS(ALPH_KEY_O), 
      PPG_TAP_DEFINITIONS(
         PPG_TAP(
            3, 
            PPG_QMK_ACTION_KEYCODE(
               RALT(KC_O)
            )
         )
      )
   );
   
   ppg_tap_dance(
      M0,
      PPG_QMK_INPUT_FROM_KEYPOS_ALIAS(ALPH_KEY_U), 
      PPG_TAP_DEFINITIONS(
         PPG_TAP(
            3, 
            PPG_QMK_ACTION_KEYCODE(
               RALT(KC_U)
            )
         )
      )
   );
   
   ppg_tap_dance(
      M0,
      PPG_QMK_INPUT_FROM_KEYPOS_ALIAS(ALPH_KEY_S), 
      PPG_TAP_DEFINITIONS(
         PPG_TAP(
            3, 
            PPG_QMK_ACTION_KEYCODE(
               RALT(KC_S)
            )
         )
      )
   );
//    
   // The following defines a set of leader sequences
   // Currently this is just used for demonstration 
   // purposes.
   
   // First we define a leader token. This can be anything
   // from a single note, a chord or cluster, a note sequence
   // or tap dance. What ever returns a token can be used
   // and serves as a basis for sequences.
   //
   PPG_Token leader_token
      = 
   ppg_token_set_flags(
      PPG_QMK_KEYPOS_CHORD_ACTION_KEYCODE(
         M0, // Layer
         XXXXXXXXXXX, // No action. We use the chord only as leader
         LEFT_OUTER_THUMB_KEY,
         RIGHT_OUTER_THUMB_KEY
      ),
      
      // Without the following the chord would consume all consequent
      // releases and re-pressing of keys involved
      //
      PPG_Chord_Flags_Disallow_Input_Deactivation
   );
   
   ppg_alphabetic_leader_sequences(
      M0, // layer
      leader_token,  // The leader input, use NULL if no leader key is 
                     // wanted
      sizeof(ng_magic_word_table)/sizeof(PGM_P), // number of sequences
      (PPG_Leader_Functions) {
         .retreive_string = ng_get_magic_word_string,
         .retreive_action = ng_get_magic_word_string_action,
         .input_from_char = ng_input_from_alphabetic_character
      },
      true // Allow fallback, i.e. only require input until a sequence
           // can be uniquely identified. Typing e.g. <leader>c or
           // <leader>ca instead
           // of <leader>cat yields the same action as long as the
           // typed sequence is unambiguous.
   );
   
   PPG_QMK_COMPILE
}

#endif

void action_exec_user(keyevent_t event)
{
   // Just for debugging with debug mode enabled (DEBUG-keycode)
   //
//    debug_config.matrix = true;
//    debug_config.keyboard = true;
//    debug_config.mouse = true;
   
   #ifdef PAPAGENO_ENABLE
   ppg_qmk_process_event(event);
   #else
   action_exec(event);
   #endif
}

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
   
   printf("Bla\n");
    
//    PPG_LOG("Matrix scan user\n");
   
#ifdef KEYBOARDS_ERGODOX_CONFIG_H_
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
