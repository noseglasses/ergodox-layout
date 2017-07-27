#define PERMISSIVE_HOLD

#include "config.h"

// Note that we try to determine the type of keyboard based on
// what is defined through the config.h header

#ifdef KEYBOARDS_ERGODOX_CONFIG_H_
#include "ergodox.h"
#else
#include "planck.h"
#endif

#include "debug.h"
#include "action_layer.h"
#include "version.h"

#include "keymap_german.h"

#include "process_papageno.h"

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

#ifdef KEYBOARDS_ERGODOX_CONFIG_H_

// Keymap for ErgoDox EZ
//
#define FF_KEYMAP( \
    k10,k11,k12,k13,k14,k15,k18,k19,k1A,k1B,k1C,k1D, \
    k20,k21,k22,k23,k24,k25,k28,k29,k2A,k2B,k2C,k2D, \
    k30,k31,k32,k33,k34,k35,k38,k39,k3A,k3B,k3C,k3D, \
    k41,k42,k43,k44,k53,k52,k5B,k5A,k49,k4A,k4B,k4C \
) \
   /* matrix positions */               \
   {                                    \
    { fXX, k10, k20, k30, fXX, fXX },   \
    { fXX, k11, k21, k31, k41, fXX },   \
    { fXX, k12, k22, k32, k42, k52 },   \
    { fXX, k13, k23, k33, k43, k53 },   \
    { fXX, k14, k24, k34, k44, fXX },   \
    { fXX, k15, k25, k35, KC_NO, fXX },   \
    { LCTL(KC_X), LCTL(KC_C), KC_NO, LCTL(KC_V), KC_NO, fXX },   \
                                                                 \
    { fXX, KC_F8, KC_NO, KC_F7,KC_NO, fXX },   \
    { fXX, k18, k28, k38,KC_NO, fXX },   \
    { fXX, k19, k29, k39, k49, fXX },   \
    { fXX, k1A, k2A, k3A, k4A, k5A },   \
    { fXX, k1B, k2B, k3B, k4B, k5B },   \
    { fXX, k1C, k2C, k3C, k4C, fXX },   \
    { fXX, k1D, k2D, k3D, fXX, KC_NO }    \
   }
#else
   
// Keymap for Planck
//
#define FF_KEYMAP PLANCK_GRID

#endif

// Hint: Print layouts with Libre Office Courier 9, A4, Landscape

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* M0: Norman Layer
 *
 * ErgoDox EZ
 * 
 * ,--------------------------------------------------------.           ,--------------------------------------------------------.
 * |        |      |      |      |      |      |  Ctrl+x    |           |            |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------------|           |------------+------+------+------+------+------+--------|
 * |   =/+  |   q  |   w  |   d  |   f  |   k  |  Ctrl+c    |           |    F8      |   j  |   u  |   r  |   l  |   ;  |   \|   |
 * |--------+------+------+------+------+------|            |           |            |------+------+------+------+------+--------|
 * |   Del  |   a  |s/Alt |e/Ctrl|   t  |   g  |------------|           |------------|   y  |   n  |i/Ctrl|o/Alt |   h  |   '"   |
 * |--------+------+------+------+------+------|  Ctrl+v    |           |    F7      |------+------+------+------+------+--------|
 * |        |   z  |x/AltG|   c  |   v  |   b  |            |           |            |   p  |   m  |   ,  |./AltG|  /?  |        |
 * `--------+------+------+------+------+-------------------'           `------------+------+------+------+------+------+--------'
 *   |RESET |  M3  |  M2  | Left | Right|                                                   |  Up  | Down |  M2  |  M3  |      |
 *   `----------------------------------'                                                   `----------------------------------'
 *                                              ,-------------.       ,-------------.
 *                                              |      |      |       |      |      |       
 *                                       ,------|------|------|       |------+------+------.
 *                                       |      |      |      |       |      |      |      |
 *                                       |Backsp|Shift |------|       |------|  M1  |Space |
 *                                       |      |      |      |       |      |      |      |
 *                                       `--------------------'       `--------------------'
 * 
 * Planck
 * 
 * ,---------------------------------------------------------------------------------------.
 * |   =/+  |   q  |   w  |   d  |   f  |   k  |   j  |   u  |   r  |   l  |   ;  |   \|   |
 * |--------+------+------+------+------+------|------+------+------+------+------+--------|
 * |   Del  |   a  |s/Alt |e/Ctrl|   t  |   g  |   y  |   n  |i/Ctrl|o/Alt |   h  |   '"   |
 * |--------+------+------+------+------+------|------+------+------+------+------+--------|
 * |        |   z  |x/AltG|   c  |   v  |   b  |   p  |   m  |   ,  |./AltG|  /?  |        |
 * |--------+------+------+------+------+-------------+------+------+------+------+--------|
 * |   M3   |  M2  | Left | Right|Backsp|Shift |  M1  |Space |  Up  | Down |  M2  |  M3    |
 * `---------------------------------------------------------------------------------------'
 */
   
  [M0] = FF_KEYMAP(
     KC_EQUAL   ,KC_Q       ,KC_W       ,KC_D       ,KC_F       ,KC_K       ,KC_J       ,KC_U       ,KC_R       ,KC_L       ,KC_SCOLON  ,KC_BSLASH,
     KC_DELETE  ,KC_A       ,ALT_T(KC_S),CTL_T(KC_E),KC_T       ,LT(M1,KC_G),KC_Y       ,KC_N       ,CTL_T(KC_I),ALT_T(KC_O),LT(2,KC_H) ,KC_QUOTE,
     XXXXXXXXXXX,KC_Z       ,ALGR_T(KC_X),KC_C      ,KC_V       ,KC_B       ,KC_P       ,KC_M       ,KC_COMMA   ,ALGR_T(KC_DOT),KC_SLASH,XXXXXXXXXXX,
     OSL(M3)    ,OSL(M2)    ,KC_LEFT    ,KC_RIGHT   ,KC_BSPACE  ,OSM(MOD_LSFT),OSL(M1)  ,KC_SPACE   ,KC_UP      ,KC_DOWN    ,OSL(M2)    ,OSL(M3)
  ),

/* M1: Symbol
 *
 * ErgoDox EZ
 * 
 * ,--------------------------------------------------------.           ,--------------------------------------------------------.
 * |        |      |      |      |      |      |  Ctrl+x    |           |            |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------------|           |------------+------+------+------+------+------+--------|
 * |   °    |   @  |   _  |   [  |   ]  |   ^  |  Ctrl+c    |           |    F8      |   !  |   <  |   >  |   =  |   &  |  ´     |
 * |--------+------+------+------+------+------|            |           |            |------+------+------+------+------+--------|
 * |        |   \  |   /  |   {  |   }  |   *  |------------|           |------------|   ?  |   (  |   )  |   -  |   :  |  `     |
 * |--------+------+------+------+------+------|  Ctrl+v    |           |    F7      |------+------+------+------+------+--------|
 * |        |   #  |   ~  |   |  |   $  |   €  |            |           |            |   +  |   %  |   "  |   '  |   ;  |        |
 * `--------+------+------+------+------+-------------------'           `------------+------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                                   |      |      |      |      |      |
 *   `----------------------------------'                                                   `----------------------------------'
 *                                              ,-------------.       ,-------------.
 *                                              |      |      |       |      |      |       
 *                                       ,------|------|------|       |------+------+------.
 *                                       |      |      |      |       |      |      |      |
 *                                       |Backsp|Shift |------|       |------|      |Space |
 *                                       |      |      |      |       |      |      |      |
 *                                       `--------------------'       `--------------------'
 * 
 * Planck
 * 
 * ,---------------------------------------------------------------------------------------.
 * |   °    |   @  |   _  |   [  |   ]  |   ^  |   !  |   <  |   >  |   =  |   &  |  ´     |
 * |--------+------+------+------+------+------|------+------+------+------+------+--------|
 * |        |   \  |   /  |   {  |   }  |   *  |   ?  |   (  |   )  |   -  |   :  |  `     |
 * |--------+------+------+------+------+------|------+------+------+------+------+--------|
 * |        |   #  |   ~  |   |  |   $  |   €  |   +  |   %  |   "  |   '  |   ;  |        |
 * |--------+------+------+------+------+-------------+------+------+------+------+--------|
 * |   M3   |  M2  | Left | Right|Backsp|Shift |  M1  |Space |  Up  | Down |  M2  |  M3    |
 * `---------------------------------------------------------------------------------------'
 */
   
  [M1] = FF_KEYMAP(
     DE_RING    ,KC_AT      ,KC_UNDS    ,KC_LBRC    ,KC_RBRC    ,KC_CIRC    ,KC_EXLM    ,DE_LESS    ,DE_MORE    ,KC_EQL     ,KC_AMPR    ,ALTG(KC_QUOT),
     XXXXXXXXXXX,KC_BSLS    ,KC_SLSH    ,KC_LCBR    ,KC_RCBR    ,KC_ASTR    ,S(KC_SLASH),KC_LPRN    ,KC_RPRN    ,KC_MINS    ,KC_COLN    ,KC_GRAVE,
     XXXXXXXXXXX,KC_HASH    ,KC_TILD    ,KC_PIPE    ,KC_DLR     ,ALTG(KC_5) ,KC_PLUS    ,KC_PERC    ,S(KC_QUOT) ,KC_QUOT    ,KC_SCLN    ,XXXXXXXXXXX,
     ___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________
   ),
   
/* M2: Navigation & Number Blocks
 * 
 * ErgoDox EZ
 * 
 * ,--------------------------------------------------------.           ,--------------------------------------------------------.
 * |        |      |      |      |      |      |  Ctrl+x    |           |            |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------------|           |------------+------+------+------+------+------+--------|
 * |        | PgUp | Bksp |  Up  |  DEL | PgDn |  Ctrl+c    |           |    F8      |      |   7  |   8  |   9  |      | Ins    |
 * |--------+------+------+------+------+------|            |           |            |------+------+------+------+------+--------|
 * |        | Home |  Lft | Down | Right| End  |------------|           |------------|      |   4  |   5  |   6  |   .  |        |
 * |--------+------+------+------+------+------|  Ctrl+v    |           |    F7      |------+------+------+------+------+--------|
 * |        |      |  Tab |      | Enter|      |            |           |            |   0  |   1  |   2  |   3  |   ,  |        |
 * `--------+------+------+------+------+-------------------'           `------------+------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                                   |      |      |      |      |      |
 *   `----------------------------------'                                                   `----------------------------------'
 *                                              ,-------------.       ,-------------.
 *                                              |      |      |       |      |      |       
 *                                       ,------|------|------|       |------+------+------.
 *                                       |      |      |      |       |      |      |      |
 *                                       |Backsp|Shift |------|       |------|      |Space |
 *                                       |      |      |      |       |      |      |      |
 *                                       `--------------------'       `--------------------'
 * 
 * Planck
 * 
 * ,---------------------------------------------------------------------------------------.
 * |        | PgUp | Bksp |  Up  |  DEL | PgDn |      |   7  |   8  |   9  |      | Ins    |
 * |--------+------+------+------+------+------|------+------+------+------+------+--------|
 * |        | Home |  Lft | Down | Right| End  |      |   4  |   5  |   6  |   .  |        |
 * |--------+------+------+------+------+------|------+------+------+------+------+--------|
 * |        |      |  Tab |      | Enter|      |   0  |   1  |   2  |   3  |   ,  |        |
 * |--------+------+------+------+------+-------------+------+------+------+------+--------|
 * |   M3   |  M2  | Left | Right|Backsp|Shift |  M1  |Space |  Up  | Down |  M2  |  M3    |
 * `---------------------------------------------------------------------------------------'
 */
   
  [M2] = FF_KEYMAP(
     XXXXXXXXXXX,KC_PGUP    ,KC_BSPC    ,KC_UP      ,KC_DEL     ,KC_PGDN    ,XXXXXXXXXXX,KC_7       ,KC_8       ,KC_9       ,XXXXXXXXXXX,KC_INS     ,
     XXXXXXXXXXX,KC_HOME    ,KC_LEFT    ,KC_DOWN    ,KC_RGHT    ,KC_END     ,XXXXXXXXXXX,KC_4       ,KC_5       ,KC_6       ,KC_DOT     ,XXXXXXXXXXX,
     XXXXXXXXXXX,XXXXXXXXXXX,KC_TAB     ,XXXXXXXXXXX,KC_ENT     ,XXXXXXXXXXX,KC_0       ,KC_1       ,KC_2       ,KC_3       ,KC_COMM    ,XXXXXXXXXXX,
     ___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________
   ),

/* M3: Function & Media Keys
 * 
 * ErgoDox EZ
 * 
 * ,--------------------------------------------------------.           ,--------------------------------------------------------.
 * |        |      |      |      |      |      |  Ctrl+x    |           |            |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------------|           |------------+------+------+------+------+------+--------|
 * |        |      | Print|Scroll|Pause |      |  Ctrl+c    |           |    F8      |      |  F7  |  F8  |  F9  |  F12 |        |
 * |--------+------+------+------+------+------|            |           |            |------+------+------+------+------+--------|
 * |        |      | Mute | Vol- | Vol+ |      |------------|           |------------|   Â³  |  F4  |  F5  |  F6  |  F11 |        |
 * |--------+------+------+------+------+------|  Ctrl+v    |           |    F7      |------+------+------+------+------+--------|
 * |        |      | Prev | Play | Next |      |            |           |            |   Â²  |  F1  |  F2  |  F3  |  F10 |        |
 * `--------+------+------+------+------+-------------------'           `------------+------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                                   |      |      |      |      |      |
 *   `----------------------------------'                                                   `----------------------------------'
 *                                              ,-------------.       ,-------------.
 *                                              |      |      |       |      |      |       
 *                                       ,------|------|------|       |------+------+------.
 *                                       |      |      |      |       |      |      |      |
 *                                       |Backsp|Shift |------|       |------|      |Space |
 *                                       |      |      |      |       |      |      |      |
 *                                       `--------------------'       `--------------------'
 * 
 * Planck
 * 
 * ,---------------------------------------------------------------------------------------.
 * |        |      | Print|Scroll|Pause |      |      |  F7  |  F8  |  F9  |  F12 |        |
 * |--------+------+------+------+------+------|------+------+------+------+------+--------|
 * |        |      | Mute | Vol- | Vol+ |      |   Â³ |  F4  |  F5  |  F6  |  F11 |        |
 * |--------+------+------+------+------+------|------+------+------+------+------+--------|
 * |        |      | Prev | Play | Next |      |   Â² |  F1  |  F2  |  F3  |  F10 |        |
 * |--------+------+------+------+------+-------------+------+------+------+------+--------|
 * |   M3   |  M2  | Left | Right|Backsp|Shift |  M1  |Space |  Up  | Down |  M2  |  M3    |
 * `---------------------------------------------------------------------------------------'
 */
   
  [M3] = FF_KEYMAP(
     XXXXXXXXXXX,XXXXXXXXXXX,KC_PSCR    ,KC_SLCK    ,KC_PAUS    ,XXXXXXXXXXX,XXXXXXXXXXX,KC_F7      ,KC_F8      ,KC_F9      ,KC_F12     ,XXXXXXXXXXX,  
     XXXXXXXXXXX,XXXXXXXXXXX,KC_MUTE    ,KC_VOLD    ,KC_VOLU    ,XXXXXXXXXXX,DE_SQ3     ,KC_F4      ,KC_F5      ,KC_F6      ,KC_F11     ,XXXXXXXXXXX,
     XXXXXXXXXXX,XXXXXXXXXXX,KC_MPRV    ,KC_MPLY    ,KC_MNXT    ,XXXXXXXXXXX,DE_SQ2     ,KC_F1      ,KC_F2      ,KC_F3      ,KC_F10     ,XXXXXXXXXXX,
     ___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________
  )
  
//,
   
//    [ff_layer_aux] = FF_KEYMAP(
//       ___________,___________,___________,___________,___________,___________,___________,   
//       ___________,___________,___________,___________,___________,___________,___________,   
//       ___________,___________,___________,___________,___________,___________,
//       ___________,___________,___________,___________,___________,___________,___________,   
//       ___________,___________,___________,___________,___________,
//                                                                               ___________,___________,
//                                                                                           ___________,
//                                                                   ___________,___________,___________,
// 
//                   ___________,___________,___________,___________,___________,___________,___________,
//                   ___________,___________,___________,___________,___________,___________,___________,
//                               ___________,___________,___________,___________,___________,___________,
//                   ___________,___________,___________,___________,___________,___________,___________,
//                                           ___________,___________,___________,___________,___________,
//       ___________,___________,
//       ___________,
//       ___________,___________,___________
//    ),
};


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
    
#define PLANCK_GRID( \
   k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
   k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
   k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
   k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b \
) \
{ \
   { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b }, \
   { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b }, \
   { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b }, \
   { k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b } \
}
#endif

// Define a bunch of key positions that are going to be used as 
// Papageno inputs. 
//
// Important: Every key macro must feature 
//            the auxiliary macro parameter S
//
#ifdef KEYBOARDS_ERGODOX_CONFIG_H_

#define LEFT_INNER_THUMB_KEY(S) PPG_QMK_KEYPOS_HEX(5, 2, S)
#define LEFT_OUTER_THUMB_KEY(S) PPG_QMK_KEYPOS_HEX(5, 3, S)

#define RIGHT_INNER_THUMB_KEY(S) PPG_QMK_KEYPOS_HEX(5, B, S)
#define RIGHT_OUTER_THUMB_KEY(S) PPG_QMK_KEYPOS_HEX(5, A, S)

#else

#define LEFT_INNER_THUMB_KEY(S) PPG_QMK_KEYPOS_HEX(3, 5, S)
#define LEFT_OUTER_THUMB_KEY(S) PPG_QMK_KEYPOS_HEX(3, 4, S)

#define RIGHT_INNER_THUMB_KEY(S) PPG_QMK_KEYPOS_HEX(3, 6, S)
#define RIGHT_OUTER_THUMB_KEY(S) PPG_QMK_KEYPOS_HEX(3, 7, S)

#endif

// Define a set of Papageno inputs that are associated with
// keyboard matrix positions.
//
// Important: - The macro must be named PPG_QMK_MATRIX_POSITION_INPUTS!
//            - If no inputs are supposed to be associated with
//              matrix positions, define an empty PPG_QMK_MATRIX_POSITION_INPUTS
//
#define PPG_QMK_MATRIX_POSITION_INPUTS(OP) \
__NL__      OP(LEFT_INNER_THUMB_KEY) \
__NL__      OP(LEFT_OUTER_THUMB_KEY) \
__NL__      OP(RIGHT_INNER_THUMB_KEY) \
__NL__      OP(RIGHT_OUTER_THUMB_KEY)

// Define a set of Papageno inputs that are associated with
// qmk keycodes.
//
// Important: - The macro must be named PPG_QMK_KEYCOKC_INPUTS!
//            - If no inputs are supposed to be associated with
//              keycodes, define an empty PPG_QMK_KEYCOKC_INPUTS
//
#define PPG_QMK_KEYCODE_INPUTS(OP)
   
// Initialize Papageno data structures for qmk
//
PPG_QMK_INIT_DATA_STRUCTURES

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

   bool key_processed = ppg_qmk_process_event(keycode, record);
   
   if(key_processed) { return false; }

//   uprintf("p kk: %u\n", keycode);

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

void double_tab_callback(void *user_data)
{
   register_code (KC_TAB);
   unregister_code (KC_TAB);
   register_code (KC_TAB);
   unregister_code (KC_TAB);
}

void init_papageno(void)
{
   PPG_QMK_INIT
   
   // When the abort key is pressed, pattern recognition is aborted
   // the same as if timeout had occured.
   //
   //ppg_global_set_abort_trigger(PPG_QMK_INPUT_FROM_KEYPOS_ALIAS(ESC_KEY));
   
//    ppg_qmk_set_timeout_ms(20000);
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
    * 
    * Allow tripple tap of the left outer thumb key to be an alternative 
    * enter.
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
         ),
         PPG_TAP(
            3, 
            PPG_QMK_ACTION_KEYCODE(
               KC_ENTER
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
   
   /* Define a secret chord that triggers flashing of 
    * the keyboard software
    */
   ppg_token_set_flags(
      PPG_QMK_KEYPOS_CHORD_ACTION_KEYCODE(
         M0, // Layer
         RESET, // Keycode action
         // Matrix keypos...
         LEFT_INNER_THUMB_KEY,
         LEFT_OUTER_THUMB_KEY,
         RIGHT_INNER_THUMB_KEY,
         RIGHT_OUTER_THUMB_KEY
      ),
      
      // Without the following the chord would consume all consequent
      // releases and re-pressing of keys involved
      //
      PPG_Chord_Flags_Disallow_Input_Deactivation
   );
   
   ppg_global_compile();
}

void matrix_init_user(void) { 
   init_papageno();
}

void matrix_scan_user(void) {
    
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

    ppg_qmk_matrix_scan();
};
