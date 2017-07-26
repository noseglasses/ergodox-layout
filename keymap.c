#define PERMISSIVE_HOLD

#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#include "keymap_german.h"

#include "keymap_nordic.h"

#include "process_papageno.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
};

enum ff_layers {
   ff_layer_norman = 0,
   ff_layer_symbol,
   ff_layer_media,
   ff_layer_qwerty
};

enum {
   ff_layer_base = 0
};

#define ___________ KC_TRANSPARENT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   /*Norman
    */
  [ff_layer_norman] = KEYMAP(
      
      KC_GRAVE   ,KC_1       ,KC_2       ,KC_3       ,KC_4       ,KC_5       ,LCTL(KC_X) ,
      KC_EQUAL   ,KC_Q       ,KC_W       ,KC_D       ,KC_F       ,KC_K       ,LCTL(KC_C) ,
      KC_DELETE  ,KC_A       ,ALT_T(KC_S),CTL_T(KC_E),KC_T       ,LT(1,KC_G) ,
      MO(1)      ,KC_Z       ,ALGR_T(KC_X),KC_C      ,KC_V        ,KC_B      ,LCTL(KC_V) ,
      OSM(MOD_LSFT),RESET    ,KC_WWW_FORWARD,KC_LEFT ,KC_RIGHT,
                                                                              KC_F1      ,KC_F3      ,
                                                                                          KC_HOME    ,
                                                                  KC_BSPACE  ,OSM(MOD_LSFT),KC_END   ,

                  ___________,KC_6       ,KC_7       ,KC_8       ,KC_9       ,KC_0       ,KC_MINUS   ,
                  KC_F8      ,KC_J       ,KC_U       ,KC_R       ,KC_L       ,KC_SCOLON  ,KC_BSLASH  ,
                              LT(1,KC_Y) ,KC_N       ,CTL_T(KC_I),ALT_T(KC_O),LT(2,KC_H) ,KC_QUOTE   ,
                  KC_F7      ,KC_P       ,KC_M        ,KC_COMMA  ,ALGR_T(KC_DOT),KC_SLASH   ,MO(1)      ,
                                          KC_UP      ,KC_DOWN    ,KC_LBRACKET,KC_RBRACKET,TG(3)      ,
      KC_F2      ,KC_ESCAPE  ,
      KC_PGUP    ,
      KC_PGDOWN  ,OSL(1),KC_SPACE
   ),

   /*Symbol
    */
  [ff_layer_symbol] = KEYMAP(
      M(0)       ,KC_F1      ,KC_F2      ,KC_F3      ,KC_F4      ,KC_F5      ,___________,
      ___________,KC_EXLM    ,KC_AT      ,KC_LCBR    ,KC_RCBR    ,KC_PIPE    ,KC_LALT    ,
      ___________,KC_HASH    ,KC_DLR     ,KC_LPRN    ,KC_RPRN    ,___________,
      ___________,KC_PERC    ,KC_CIRC    ,KC_LBRACKET,KC_RBRACKET,KC_TILD    ,KC_RALT    ,
      ___________,___________,___________,___________,___________,
                                                                              KC_F1      ,KC_F3      ,
                                                                                          KC_HOME    ,
                                                                  KC_BSPACE  ,KC_TAB     ,KC_END,

                  ___________,KC_F6      ,KC_F7      ,KC_F8      ,KC_F9      ,KC_F10     ,KC_F11     ,
                  ___________,KC_UP      ,KC_KP_7    ,KC_KP_8    ,KC_KP_9    ,KC_ASTR    ,KC_F12     ,
                              ___________,KC_KP_4    ,KC_KP_5    ,KC_KP_6    ,KC_PLUS    ,___________,
                  ___________,KC_AMPR    ,KC_KP_1    ,KC_KP_2    ,KC_KP_3    ,KC_BSLASH  ,___________,
                                          ___________,KC_DOT     ,KC_KP_0    ,KC_EQUAL   ,___________,

      KC_F2      ,KC_ESCAPE  ,
      KC_PGUP,
      KC_PGDOWN  ,KC_ENTER   ,KC_SPACE
   ),

   /* Media
    */
  [ff_layer_media] = KEYMAP(
      ___________,___________,___________,___________,___________,___________,___________,
      ___________,___________,___________,KC_MS_UP   ,___________,___________,___________,
      ___________,___________,KC_MS_LEFT ,KC_MS_DOWN ,KC_MS_RIGHT,___________,
      ___________,___________,___________,___________,___________,___________,___________,
      ___________,___________,___________,KC_MS_BTN1 ,KC_MS_BTN2 ,
                                                                              ___________,___________,
                                                                                          ___________,
                                                                  ___________,___________,___________,

                  ___________,___________,___________,___________,___________,___________,___________,
                  ___________,___________,___________,___________,___________,___________,___________,
                              ___________,___________,___________,___________,___________,KC_MEDIA_PLAY_PAUSE,
                  ___________,___________,___________,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,___________,___________,
                                          KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,___________,___________,
      ___________,___________,
      ___________,
      ___________,___________,KC_WWW_BACK),

   /* QWERTY
    */
  [ff_layer_qwerty] = KEYMAP(
      KC_GRAVE   ,KC_1       ,KC_2        ,KC_3      ,KC_4       ,KC_5       ,___________,   
      KC_EQUAL   ,KC_Q       ,KC_W        ,KC_E      ,KC_R       ,KC_T       ,___________,
      KC_DELETE  ,KC_A       ,KC_S        ,KC_D      ,KC_F       ,KC_G       ,
      KC_LSHIFT  ,KC_Z       ,KC_X        ,KC_C      ,KC_V       ,KC_B       ,___________,
      ___________,___________,___________,___________,___________,
                                                                              ___________,___________,
                                                                                          KC_HOME    ,
                                                                  KC_BSPACE  ,KC_TAB     ,KC_END     ,

                  ___________,KC_6       ,KC_7       ,KC_8       ,KC_9       ,KC_0       ,KC_MINUS   ,
                  ___________,KC_Y       ,KC_U       ,KC_I       ,KC_O       ,KC_P       ,KC_BSLASH  ,
                              KC_H       ,KC_J       ,KC_K       ,KC_L       ,KC_SCOLON  ,___________,
                  ___________,KC_N       ,KC_M       ,KC_COMMA   ,KC_DOT     ,KC_SLASH   ,KC_RSHIFT  ,
                                          ___________,___________,___________,___________,___________,
      ___________,KC_ESCAPE,
      KC_PGUP    ,
      KC_PGDOWN  ,KC_ENTER ,KC_SPACE
   )
//,
   
//    [ff_layer_aux] = KEYMAP(
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
#endif

// Define a bunch of key positions that are going to be used as 
// Papageno inputs. 
//
// Important: Every key macro must feature 
//            the auxiliary macro parameter S
//
#define LEFT_INNER_THUMB_KEY(S) PPG_QMK_KEYPOS_HEX(5, 2, S)
#define LEFT_OUTER_THUMB_KEY(S) PPG_QMK_KEYPOS_HEX(5, 3, S)

#define RIGHT_INNER_THUMB_KEY(S) PPG_QMK_KEYPOS_HEX(5, B, S)
#define RIGHT_OUTER_THUMB_KEY(S) PPG_QMK_KEYPOS_HEX(5, A, S)

#define ESC_KEY(S) PPG_QMK_KEYPOS_HEX(5, 8, S)

#define LEFT_MIDDLE_FINGER_BASE_ROW(S) PPG_QMK_KEYPOS_HEX(4, 3, S)
#define LEFT_INDEX_FINGER_BASE_ROW(S) PPG_QMK_KEYPOS_HEX(4, 4, S)
#define RIGHT_MIDDLE_FINGER_BASE_ROW(S) PPG_QMK_KEYPOS_HEX(4, 9, S)
#define RIGHT_INDEX_FINGER_BASE_ROW(S) PPG_QMK_KEYPOS_HEX(4, A, S)

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
__NL__      OP(RIGHT_OUTER_THUMB_KEY) \
__NL__      OP(ESC_KEY) \
__NL__      OP(LEFT_MIDDLE_FINGER_BASE_ROW) \
__NL__      OP(LEFT_INDEX_FINGER_BASE_ROW) \
__NL__      OP(RIGHT_MIDDLE_FINGER_BASE_ROW) \
__NL__      OP(RIGHT_INDEX_FINGER_BASE_ROW)

// Define a set of Papageno inputs that are associated with
// qmk keycodes.
//
// Important: - The macro must be named PPG_QMK_KEYCODE_INPUTS!
//            - If no inputs are supposed to be associated with
//              keycodes, define an empty PPG_QMK_KEYCODE_INPUTS
//
#define PPG_QMK_KEYCODE_INPUTS(OP)
   
// Initialize Papageno data structures for qmk
//
PPG_QMK_INIT_DATA_STRUCTURES

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

   bool key_processed = ppg_qmk_process_event(keycode, record);
   
   if(key_processed) { return false; }

   uprintf("p kk: %u\n", keycode);

  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
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
   ppg_global_set_abort_trigger(PPG_QMK_INPUT_FROM_KEYPOS_ALIAS(ESC_KEY));
   
//    ppg_qmk_set_timeout_ms(20000);
   ppg_qmk_set_timeout_ms(200);
   
   /* Allow left inner and right inner thumb key to trigger key enter if
    * clustered.
    */
   PPG_QMK_KEYPOS_CLUSTER_ACTION_KEYCODE(
      ff_layer_base, // Layer
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
      ff_layer_base,
      PPG_QMK_INPUT_FROM_KEYPOS_ALIAS(LEFT_INNER_THUMB_KEY), /* The tap key
         could also be a keycode using PPG_QMK_INPUT_FROM_KEYCODE_ALIAS */
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
      ff_layer_base, // Layer
      KC_TAB, // Keycode action
      // Matrix keypos...
      LEFT_INNER_THUMB_KEY, // left inner large thumb key
      RIGHT_OUTER_THUMB_KEY  // right outer large thumb key
   );
         
   /* Allow left inner and right outer thumb key to trigger key untab if
    * clustered.
    */
   PPG_QMK_KEYPOS_NOTE_LINE_ACTION_KEYCODE(
      ff_layer_base, // Layer
      LSFT(KC_TAB), // Keycode action  
      // Matrix keypos...
      RIGHT_OUTER_THUMB_KEY,  // right outer large thumb key
      LEFT_INNER_THUMB_KEY // left inner large thumb key
   );
   
   
   /* Define a secret chord that triggers flashing of 
    * the keyboard software
    */
   PPG_QMK_KEYPOS_CHORD_ACTION_KEYCODE(
      ff_layer_base, // Layer
      RESET, // Keycode action
      // Matrix keypos...
      LEFT_MIDDLE_FINGER_BASE_ROW, \
      LEFT_INDEX_FINGER_BASE_ROW, \
      RIGHT_MIDDLE_FINGER_BASE_ROW, \
      RIGHT_INDEX_FINGER_BASE_ROW
   );
   
   ppg_global_compile();
}

void matrix_init_user(void) { 
   init_papageno();
}

void matrix_scan_user(void) {
    
//    PPG_LOG("Matrix scan user\n");
   
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
    ppg_qmk_matrix_scan();
};
