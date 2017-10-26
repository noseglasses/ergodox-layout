#ifndef NG_PAPAGENO_SETTINGS_H
#define NG_PAPAGENO_SETTINGS_H

#include "process_papageno.h"
#include "ng_layer_settings.h"
#include "ng_portable_keymap.h"

#ifdef PAPAGENO_USE_COMPRESSED_DATA_STRUCTURES
#include "compressed_keymap.h"
#endif

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

// For compression we use stubs instead of the actual
// callback functions
//
#if !PAPAGENO_COMPRESSION_ENABLED

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

// Important: If you change the number of entries in
//            ng_magic_word_table, make sure to adjust the number of
//             entries wherever ng_magic_word_table is used
//
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
void ng_double_tab_callback(bool activation, void *user_data)
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
void ng_repeat_last_command_callback(bool activation, void *user_data)
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
void ng_ordinary_search_command_callback(bool activation, void *user_data)
{
   if(!activation) { return; }
   
   register_code16 (LCTL(KC_F));
   unregister_code16 (LCTL(KC_F));
   register_code (KC_ENTER);
   unregister_code (KC_ENTER);
}

// Similar the search callback above, but for a search
// in multiple files. This works with editors
// that have been customized to feature Shift+F1
// as command to open the search-in-files menu.
//
void ng_file_search_command_callback(bool activation, void *user_data)
{
   if(!activation) { return; }
   
   register_code16 (S(KC_F1));
   send_keyboard_report();
   unregister_code16 (S(KC_F1));
   send_keyboard_report();
   register_code (KC_ENTER);
   unregister_code (KC_ENTER);
}

inline
static bool ng_is_shift_enabled(void)
{
   return   (get_oneshot_mods() & MOD_BIT(KC_LSFT))
         || (keyboard_report->mods & MOD_BIT(KC_LSFT));
}

void ng_umlaut_callback(bool activation, void *user_data)
{
   uint16_t keycode = (uint16_t)user_data;

   // TODO: Find out why one shot mods do timeout
   //       so fast
   
   if(activation) {
      
      register_code16(KC_RALT);
      register_code(keycode);
   }
   else {
      unregister_code(keycode);
      unregister_code16(KC_RALT);
   }
}

// We need a callback to trigger the keyboard reset (to flash firmware)
// as the RESET keycode is processed by the qmk system and is
// for specific reason not available as Papageno keycode action.
//
void ng_reset_callback(bool activation, void *user_data)
{
   if(!activation) { return; }
   
   reset_keyboard();
}

void action_exec_user(keyevent_t event)
{
   // Just for debugging with debug mode enabled (DEBUG-keycode)
   //
//    debug_config.matrix = true;
//    debug_config.keyboard = true;
//    debug_config.mouse = true;
//    
//   
   
   #ifdef PAPAGENO_ENABLE
   ppg_qmk_process_event(event);
   #else
   action_exec(event);
   #endif
}

#else // #if PAPAGENO_COMPRESSION_ENABLED

// Define stubs for compression
//
#define NG_PPG_SYMBOLS(S) \
   S(ng_double_tab_callback) \
   S(ng_repeat_last_command_callback) \
   S(ng_ordinary_search_command_callback) \
   S(ng_file_search_command_callback) \
   S(ng_umlaut_callback) \
   S(ng_reset_callback) \
   S(ng_get_magic_word_string) \
   S(ng_get_magic_word_string_action) \
   S(ng_input_from_alphabetic_character)

PPG_QMK_COMPRESSION_PREPARE_SYMBOLS(NG_PPG_SYMBOLS)

#endif // #if PAPAGENO_COMPRESSION_ENABLED
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
   // Only if compression of the papageno data structures 
   // is desired, the actual tree specification is considered
   //
   #if defined(PAPAGENO_COMPRESSION_ENABLED) | !defined(PAPAGENO_USE_COMPRESSED_DATA_STRUCTURES)
   
   PPG_QMK_INIT
   
   // Only list symbols here that are required after initialization
   //
   // Note: The functions passed as PPG_Leader_Functions are only required
   //       during setup.
   // 
   PPG_QMK_COMPRESSION_REGISTER_SYMBOLS(NG_PPG_SYMBOLS)
   
   ppg_qmk_set_timeout_ms(200);
   
//    ppg_global_set_timeout_enabled(false);
   
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
               ng_double_tab_callback,
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
         
//    /* Allow left inner and right outer thumb key to trigger key untab when
//     * hit consecutively.
//     */
//    PPG_QMK_KEYPOS_CHORD_ACTION_KEYCODE(
//       M0, // Layer
//       LSFT(KC_TAB), // Keycode action  
//       // Matrix keypos...
//       RIGHT_OUTER_THUMB_KEY,  // right outer large thumb key
//       LEFT_INNER_THUMB_KEY // left inner large thumb key
//    );
      
   // Double tap right inner thumb key to trigger untab
   //
   // Note: This used to be triggered via a note line 
   //       of left inner and right outer thumb key,
   //       that turned out to interfere with
   //       the popular combination of space followed
   //       by shift (capital letter) at the begin
   //       of a new sentence.
   //
   ppg_tap_dance(
      M0,
      PPG_QMK_INPUT_FROM_KEYPOS_ALIAS(RIGHT_INNER_THUMB_KEY),
      PPG_TAP_DEFINITIONS(
         PPG_TAP(
            2, 
            PPG_QMK_ACTION_KEYCODE(
               LSFT(KC_TAB)
            )
         )
      )
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
               ng_repeat_last_command_callback,
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
               ng_ordinary_search_command_callback,
               NULL
            )
         ),
         PPG_TAP(
            3, 
            PPG_ACTION_USER_CALLBACK(
               ng_file_search_command_callback,
               NULL
            )
         ),
         PPG_TAP(
            5, 
            PPG_ACTION_USER_CALLBACK(
               ng_reset_callback,
               NULL
            )
         )
      )
   );
   
   // Double tap on S4 triggers Ctrl-r (replace in many editors)
   //
   ppg_tap_dance(
      M0,
      PPG_QMK_INPUT_FROM_KEYPOS_ALIAS(SPECIAL_KEY_4), 
      PPG_TAP_DEFINITIONS(
         PPG_TAP(
            2, 
            PPG_QMK_ACTION_KEYCODE(
               LCTL(KC_R)
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
   
   
   // Assign german umlauts as tripple taps to
   // suitable and non-colliding (digraphs!) keys of the home row
   //
   // Occurence probabilities of umlauts in written german:
   //
   // a-umlaut  0,54%
   // o-umlaut  0,30%
   // u-umlaut  0,65%
   // s-umlaut  0,37%
   //
   // These are used together with the EURKEY keyboard layout
   // that is available on Linux and Windows
   
   ppg_tap_dance(
      PPG_LAYER_UPPER_BOUNDARY(M0), // We do not want this to be available on higher layers
      PPG_QMK_INPUT_FROM_KEYPOS_ALIAS(ALPH_KEY_E), 
      PPG_TAP_DEFINITIONS(
         PPG_TAP(
            3, 
            PPG_ACTION_USER_CALLBACK(
               ng_umlaut_callback,
               (void*)KC_A
            )
         )
      )
   );
   
   ppg_tap_dance(
      PPG_LAYER_UPPER_BOUNDARY(M0),
      PPG_QMK_INPUT_FROM_KEYPOS_ALIAS(ALPH_KEY_O), 
      PPG_TAP_DEFINITIONS(
         PPG_TAP(
            3, 
            PPG_ACTION_USER_CALLBACK(
               ng_umlaut_callback,
               (void*)KC_O
            )
         )
      )
   );
   
   ppg_tap_dance(
      PPG_LAYER_UPPER_BOUNDARY(M0),
      PPG_QMK_INPUT_FROM_KEYPOS_ALIAS(ALPH_KEY_I), 
      PPG_TAP_DEFINITIONS(
         PPG_TAP(
            3, 
            PPG_ACTION_USER_CALLBACK(
               ng_umlaut_callback,
               (void*)KC_U
            )
         )
      )
   );
   
   ppg_tap_dance(
      PPG_LAYER_UPPER_BOUNDARY(M0),
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
      3, // number of entries in ng_magic_word_table
      (PPG_Leader_Functions) {
         .retreive_string = (PPG_Leader_String_Retreival_Callback)      
                                 ng_get_magic_word_string,
         .retreive_action = (PPG_Leader_Action_Retreival_Callback)
                                 ng_get_magic_word_string_action,
         .input_from_char = (PPG_Leader_Character_To_Input_Callback)
                                 ng_input_from_alphabetic_character
      },
      true // Allow fallback, i.e. only require input until a sequence
           // can be uniquely identified. Typing e.g. <leader>c or
           // <leader>ca instead
           // of <leader>cat yields the same action as long as the
           // typed sequence is unambiguous.
   );
#if 0
#endif
   
   PPG_QMK_COMPILE
   
   #else
   PPG_INITIALIZE_CONTEXT_noseglasses
   PPG_QMK_SETUP_NON_DEFAULT_MANAGERS
   #endif
}

#endif
