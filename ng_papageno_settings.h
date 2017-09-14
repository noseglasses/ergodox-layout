
#include "ng_layer_settings.h"

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

// Define stubs for compression
//
#if PAPAGENO_COMPRESSION_ENABLED

#define NG_PPG_SYMBOLS(S) \
   S(double_tab_callback) \
   S(repeat_last_command_callback) \
   S(ordinary_search_command_callback) \
   S(file_search_command_callback) \
   S(reset_callback)

PPG_QMK_COMPRESSION_PREPARE_SYMBOLS(NG_PPG_SYMBOLS)

#endif

void init_papageno(void)
{
   PPG_QMK_INIT
   
   // Only list symbols here that are required after initialization
   //
   // Note: The functions passed as PPG_Leader_Functions are only required
   //       during setup.
   // 
   PPG_QMK_COMPRESSION_REGISTER_SYMBOLS(NG_PPG_SYMBOLS)
   
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
      
   /* Allow left inner and right outer thumb key to trigger key tab when
    * hit consecutively.
    */
   PPG_QMK_KEYPOS_NOTE_LINE_ACTION_KEYCODE(
      M0, // Layer
      KC_TAB, // Keycode action
      // Matrix keypos...
      LEFT_INNER_THUMB_KEY, // left inner large thumb key
      RIGHT_OUTER_THUMB_KEY  // right outer large thumb key
   );
         
   /* Allow left inner and right outer thumb key to trigger key untab when
    * hit consecutively.
    */
   PPG_QMK_KEYPOS_NOTE_LINE_ACTION_KEYCODE(
      M0, // Layer
      LSFT(KC_TAB), // Keycode action  
      // Matrix keypos...
      RIGHT_OUTER_THUMB_KEY,  // right outer large thumb key
      LEFT_INNER_THUMB_KEY // left inner large thumb key
   );
   
   /* Allow right inner and left outer thumb key to trigger Del key when
    * hit consecutively.
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
