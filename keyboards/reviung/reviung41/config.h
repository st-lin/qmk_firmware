/*
Copyright 2020 gtips

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#include "config_common.h"

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define RGBLIGHT_LAYERS


#define MY_SE_LAYOUT


#ifdef MY_SE_LAYOUT
	#define LSPO_KEYS KC_LSFT, KC_LSFT, KC_8
	#define RSPC_KEYS KC_RSFT, KC_TRNS, KC_QUOT
#endif 
#define LCPO_KEYS KC_LCTL, KC_TRNS, KC_DEL
#define RCPC_KEYS KC_LALT, KC_TRNS, KC_ENT

#define TAPPING_TOGGLE 2
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define COMBO_TERM 30
#define COMBO_ONLY_FROM_LAYER 6
//#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define ONESHOT_TAP_TOGGLE 3
#define ONESHOT_TIMEOUT 1500
// #define AUTO_SHIFT_TIMEOUT 175
// //#define NO_AUTO_SHIFT_ALPHA
// #define NO_AUTO_SHIFT_SPECIAL
//#define CAPS_WORD_IDLE_TIMEOUT 2500
//#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
//#define LEADER_TIMEOUT 250
