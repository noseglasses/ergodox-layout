#ifndef CONFIG_NOSEGLASSES_H
#define CONFIG_NOSEGLASSES_H

#include "../../config.h"

// #undef MOUSEKEY_TIME_TO_MAX
// #undef MOUSEKEY_MAX_SPEED
// 
// #define MOUSEKEY_TIME_TO_MAX 1
// #define MOUSEKEY_MAX_SPEED 2
// 
// #undef MOUSEKEY_DELAY
// #define MOUSEKEY_DELAY 0
// 
// #undef MOUSEKEY_WHEEL_DELAY
// #define MOUSEKEY_WHEEL_DELAY 0
// 
// #define ONESHOT_TAP_TOGGLE 2
// #define ONESHOT_TIMEOUT 3000
// #undef ONESHOT_TIMEOUT
/*
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#undef LEADER_TIMEOUT
#define LEADER_TIMEOUT 1000*/

// #define NO_ACTION_TAPPING

// There are problems with oneshot modifiers
// that result from the fact that TAPPING_TERM is 
// set to 200 by default which is too short for
// being used with Papageno processing
//
#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif
#define TAPPING_TERM 5000

//#undef ONESHOT_TIMEOUT
//#define ONESHOT_TIMEOUT 5000

#define PERMISSIVE_HOLD
#define PREVENT_STUCK_MODIFIERS

#endif
