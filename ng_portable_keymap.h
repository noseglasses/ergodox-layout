#ifndef NG_PORTABLE_KEYMAP_H
#define NG_PORTABLE_KEYMAP_H


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

#ifdef ERGODOX_EZ_CONFIG_H

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

#define NG_PASS_QMK_KEYPOS_HEX(S1, S2) PPG_QMK_KEYPOS_HEX(S1, S2)

// Planck swaps rows and cols in comparison to planck (or vice versa?)
//
#define NG_KEYPOS(KEY_ALIAS, S) NG_PASS_QMK_KEYPOS_HEX(NG_SWAP_ROW_COL(KEY_ALIAS), S)

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

#endif
