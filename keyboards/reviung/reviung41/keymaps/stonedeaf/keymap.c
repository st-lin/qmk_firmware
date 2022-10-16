/* Copyright 2020 gtips
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include "utils/keymap_us-se.h"

enum layer_names {
    _BASE,
    _SWE,
    _FUN,
    _NUM,
    _NAV,
    _SYM,
    _EXT,
    _COM
};

#define ___N___ KC_NO
#define __XXX__ KC_NO

enum custom_keycodes {
  GUI_ALT = SAFE_RANGE,
  ALT_TAB,
  MY_SCLN,
  STR_SL,
  STR_SM,
  STR_GM,
  STR_PW
};

// enum tap_dances {
//     TD_TAB_ESC
// };
// #define TAB_ESC TD(TD_TAB_ESC)

#define C_LEFT  C(KC_LEFT)
#define C_RGHT  C(KC_RGHT)
#define C_Z   C(KC_Z)
#define C_X   C(KC_X)
#define C_C   C(KC_C)
#define C_V   C(KC_V)

#define VS_BACK C(K_MINS)
#define VS_FWD C(S(K_MINS))

#define OS_LGUI OSM(MOD_LGUI)
#define OS_RGUI OSM(MOD_RGUI)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_LALT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)

#define L_MID OS_LSFT
#define R_MID OS_RSFT
#define L_BOT LCTL_T(KC_DEL)
#define R_BOT RCTL_T(KC_ESC)

#define FUN_SPC LT(_FUN, KC_SPC)
#define NUM_SPC LT(_NUM, KC_SPC)
#define SYM_ENT LT(_SYM, KC_ENT)
#define NAV LT(_NAV, KC_LGUI)//MO(_NAV)
#define EXT MO(_EXT)

#define LEFT_LAYER_NAV_CLUSTER

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_reviung41(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    L_MID,    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     MY_SCLN,  R_MID,
    L_BOT,    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     K_COMM,   K_DOT,    K_MINS,   R_BOT,
                                            NAV,      NUM_SPC, TT(_FUN),  SYM_ENT,  EXT
  ),

  [_SWE] = LAYOUT_reviung41(
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  SW_AA,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  SW_OE,    SW_AE,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
                                            _______,  _______, TG(_SWE),  _______,  _______
  ),

  [_FUN] = LAYOUT_reviung41(
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,              KC_F6,    KC_F7,    KC_VOLU,  KC_CALC,  KC_PSCR,  _______,
    _______,  KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,             KC_HOME,  ___N___,  KC_VOLD,  ___N___,  ___N___,  KC_RSFT,
    _______,  ___N___,  ___N___,  ___N___,  ___N___,  KC_DEL,             KC_END,   ___N___,  KC_MUTE,  ___N___,  KC_LALT,  KC_RCTL,
                                            KC_WBAK,  VS_BACK, TT(_FUN),  VS_FWD,  KC_WFWD
  ),

  [_NUM] = LAYOUT_reviung41(
    _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     SW_AA,
    _______,  K_EXLM,   K_AT,     K_HASH,   K_DLR,    K_PERC,             ___N___,  ___N___,  ___N___,  ___N___,  SW_OE,    SW_AE,
    _______,  C(KC_Z),  C(KC_X),  C(KC_C),  C(KC_V),  ___N___,            ___N___,  ___N___,  ___N___,  ___N___,  ___N___,  _______,
                                            ___N___,  __XXX__,  ___N___,  ___N___,  ___N___
  ),

  [_NAV] = LAYOUT_reviung41(
    ALT_TAB,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
    _______,  K_EXLM,   K_AT,     K_HASH,   K_DLR,    K_PERC,             ___N___,  ___N___,  KC_PGUP,  KC_HOME,  KC_UP,    KC_END,
    _______,  C(KC_Z),  C(KC_X),  C(KC_C),  C(KC_V),  ___N___,            ___N___,  ___N___,  KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,
                                            __XXX__,  KC_SPC,   ___N___,  KC_ENT,   KC_RCTL    
  ),

  [_SYM] = LAYOUT_reviung41(
    ___N___,  ___N___,  ___N___,  ___N___,  ___N___,  ___N___,            K_LT,     K_GT,     KC_P7,    KC_P8,    KC_P9,    KC_PMNS,
    ___N___,  ___N___,  ___N___,  ___N___,  ___N___,  ___N___,            K_LBRC,   K_RBRC,   KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
    ___N___,  ___N___,  ___N___,  ___N___,  ___N___,  ___N___,            K_LBRC,   K_RBRC,   KC_P1,    KC_P2,    KC_P3,    KC_P0,
                                            ___N___,  KC_SPC,   ___N___,  __XXX__,  ___N___
  ),

  [_EXT] = LAYOUT_reviung41(
    _______,  ___N___,  KC_2,     KC_E,     ___N___,  ___N___,            ___N___,  ___N___,  ___N___,  ___N___,  ___N___,  _______,
    _______,  K_LGUI,   K_LALT,   K_LCTL,   K_LSFT,   ___N___,            ___N___,  ___N___,  KC_PGUP,  KC_HOME,  KC_UP,    KC_END,
    _______,  KC_Z,     KC_X,     KC_C,     KC_V,     ___N___,            ___N___,  ___N___,  KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,
                                            KC_LALT,  KC_SPC,   ___N___,  KC_ENT,   __XXX__
  ),

  [_COM] = LAYOUT_reviung41(
    KC_1,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_4,
    KC_2,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_5,
    KC_3,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_MINS,  KC_6,
                                            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5
  ),
  
};


// States for GUI_ALT
bool isMixDown = false;
bool isGuiReg = false;
bool isAltReg = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    
    // Special GUI_ALT code
    if (isMixDown && record->event.pressed && !isGuiReg && !isAltReg) {
        if (keycode == KC_TAB) {
            register_code(KC_LALT);
            isAltReg = true;
        } else {
            register_code(KC_LGUI);
            isGuiReg = true;
        }
    }

    switch (keycode) {
    case GUI_ALT:
        // Delay or decide GUI or ALT
        if (record->event.pressed) {
            isMixDown = true;
        } else {
            if (!isAltReg && !isGuiReg)
                tap_code(KC_LGUI);
            if (isGuiReg)
                unregister_code(KC_LGUI);
            if (isAltReg)
                unregister_code(KC_LALT);
            if (isGuiReg)
                unregister_code(KC_LGUI);
            isAltReg = false;
            isGuiReg = false;
            isMixDown = false;
        }
        break;
    case ALT_TAB:
        if (record->event.pressed) {
            if (!isAltReg) {
                register_code(KC_LALT);
                isAltReg = true;
            }
            tap_code(KC_TAB);
        }
    case MY_SCLN:
        if (record->event.pressed){
            if ((get_mods() & MOD_MASK_SHIFT) > 0)
                tap_code16(K_COLN);
            else
                tap_code16(K_SCLN);
        }
        break;
    case STR_SL:
        if (record->event.pressed)
            SEND_STRING("st/lin");
        return false;
    case STR_SM:
        if (record->event.pressed)
            SEND_STRING("stefan.lindholm@sectra.com");
        return false;
    case STR_GM:
        if (record->event.pressed)
            SEND_STRING("steli268@gmail.com");
        return false;
    case STR_PW:
        if (record->event.pressed)
            SEND_STRING("probi.!#!.natos");
        return false;
    }

    return true;
};



/*
 * Replacements
 */
const key_override_t shift_backspace_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t gui_w_override = ko_make_basic(MOD_MASK_GUI, KC_W, LGUI(KC_2));
const key_override_t ctrl_up_override = ko_make_basic(MOD_MASK_CTRL, KC_UP, KC_HOME);
const key_override_t ctrl_down_override = ko_make_basic(MOD_MASK_CTRL, KC_DOWN, KC_END);
const key_override_t shift_dot_override = ko_make_basic(MOD_MASK_SHIFT, K_DOT, K_EXLM);
const key_override_t shift_comm_override = ko_make_basic(MOD_MASK_SHIFT, K_COMM, K_QUES);

const key_override_t **key_overrides = (const key_override_t *[]){
    &shift_backspace_override,
    &gui_w_override,
    &ctrl_up_override,
    &ctrl_down_override,
    &shift_dot_override,
    &shift_comm_override,
    NULL // Null terminate the array of overrides!
};



/* 
 * Combos
 */
// COMBO_ENABLE = yes Goes in rules.mk
enum combos {
    CO_AB, // Debug
    CO_1Q,                  // Esc
    // CO_PB,                  // Bspc
    CO_QW, CO_WE, CO_ER,    // " ' `
    CO_TG, CO_YH,           // | &
    CO_BG, CO_NH,           // fs bs
    CO_TY,                  // ~
    CO_OP, CO_IO, CO_UI,    // = + *
    CO_RT, CO_YU,           // < >
    CO_FG, CO_HJ,           // { }
    CO_VB, CO_NM,           // [ ]
    CO_DF, CO_JK,           // ( )
    CO_CV, CO_MC,           // fs bs
    CO_AA, CO_AE, CO_OE,    // å ä ö
    CO_FS, CO_BS,           // fs bs
    CO_96,                  // Enter
    CO_SL, CO_SM, CO_GM,
    CO_MKL,
    CO_F1W, CO_F1E, CO_F1L,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM co_ab[] = {KC_A, KC_B, COMBO_END};
const uint16_t PROGMEM co_1q[] = {KC_1, KC_Q, COMBO_END};
const uint16_t PROGMEM co_qw[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM co_we[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM co_er[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM co_tg[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM co_yh[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM co_bg[] = {KC_B, KC_G, COMBO_END};
const uint16_t PROGMEM co_nh[] = {KC_N, KC_H, COMBO_END};
const uint16_t PROGMEM co_ty[] = {KC_T, KC_Y, COMBO_END};
const uint16_t PROGMEM co_op[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM co_io[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM co_ui[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM co_rt[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM co_yu[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM co_fg[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM co_hj[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM co_vb[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM co_nm[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM co_df[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM co_jk[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM co_cv[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM co_mc[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM co_aa[] = {KC_P, KC_4, COMBO_END};
const uint16_t PROGMEM co_ae[] = {KC_SCLN, KC_5, COMBO_END};
const uint16_t PROGMEM co_oe[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM co_fs[] = {KC_DOT, KC_MINS, COMBO_END};
const uint16_t PROGMEM co_bs[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM co_96[] = {KC_MINS, KC_6, COMBO_END};
const uint16_t PROGMEM co_sl[] = {KC_S, KC_L, COMBO_END};
const uint16_t PROGMEM co_sm[] = {KC_S, KC_M, COMBO_END};
const uint16_t PROGMEM co_gm[] = {KC_G, KC_M, COMBO_END};
const uint16_t PROGMEM co_mkl[] = {KC_M, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM co_f1w[] = {KC_F1, KC_W, COMBO_END};
const uint16_t PROGMEM co_f1e[] = {KC_F1, KC_E, COMBO_END};
const uint16_t PROGMEM co_f1l[] = {KC_F1, KC_L, COMBO_END};
/* 
 * ,-----------------------------------------------------------------.
 * 1 Esc Q  "  W  '  E  ´  R  <  T  ~  Y  >  U  *  I  +  O  =  P  Å  B
 * |-----+-----+-----+-----+---- | --- & ----+-----+-----+-----+-----+
 * S     A     S     D  (  F  {  G     H  }  J  )  K     L  Ö  ;  Ä  S
 * |-----+-----+-----+-----+---- / --- \ ----+-----+-----+-----+-----+
 * C     Z     X     C  /  V  [  B     N  ]  M  \  ,     .     -  E  C
 * `-----------------------------------------------------------------'
 */
/* 
 * ,-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----.
 * | Esc    "     '     ´     [     ~     ]     *     +     =     Å  | 
 * +                             |     &                             +
 * |                    (     {           }     )           Ö     Ä  |
 * +                             /     \                             +
 * |                    /     <           >     \                 E  |
 * `-----------------------------------------------------------------'
 */
combo_t key_combos[] = {
    [CO_AB] = COMBO(co_ab, KC_C),
    [CO_1Q] = COMBO(co_1q, KC_ESC),
    [CO_QW] = COMBO(co_qw, K_DQUO),
    [CO_WE] = COMBO(co_we, K_QUOT),
    [CO_ER] = COMBO(co_er, K_GRAVE),
    [CO_TG] = COMBO(co_tg, K_PIPE),
    [CO_YH] = COMBO(co_yh, K_AMPR),
    [CO_BG] = COMBO(co_bg, K_SLASH),
    [CO_NH] = COMBO(co_nh, K_BACKSLASH),
    [CO_TY] = COMBO(co_ty, K_TILDE),
    [CO_OP] = COMBO(co_op, K_EQUAL),
    [CO_IO] = COMBO(co_io, K_PLUS),
    [CO_UI] = COMBO(co_ui, K_ASTR),
    [CO_RT] = COMBO(co_rt, K_LEFT_BRACKET),
    [CO_YU] = COMBO(co_yu, K_RIGHT_BRACKET),
    [CO_FG] = COMBO(co_fg, K_LEFT_CURLY_BRACE),
    [CO_HJ] = COMBO(co_hj, K_RIGHT_CURLY_BRACE),
    [CO_VB] = COMBO(co_vb, K_LEFT_ANGLE_BRACKET),
    [CO_NM] = COMBO(co_nm, K_RIGHT_ANGLE_BRACKET),
    [CO_DF] = COMBO(co_df, K_LEFT_PAREN),
    [CO_JK] = COMBO(co_jk, K_RIGHT_PAREN),
    [CO_CV] = COMBO(co_cv, K_SLASH),
    [CO_MC] = COMBO(co_mc, K_BACKSLASH),
    [CO_AA] = COMBO(co_aa, SW_AA),
    [CO_AE] = COMBO(co_ae, SW_AE),
    [CO_OE] = COMBO(co_oe, SW_OE),
    [CO_FS] = COMBO(co_fs, ___N___),
    [CO_BS] = COMBO(co_bs, ___N___),
    [CO_SL] = COMBO(co_sl, STR_SL),
    [CO_SM] = COMBO(co_sm, STR_SM),
    [CO_GM] = COMBO(co_gm, STR_GM),
    [CO_96] = COMBO(co_96, KC_ENT),
    [CO_MKL] = COMBO(co_mkl, STR_PW),
    [CO_F1W] = COMBO(co_f1w, G(KC_2)),
    [CO_F1E] = COMBO(co_f1e, G(KC_E)),
    [CO_F1L] = COMBO(co_f1l, G(KC_L))
};





// /* 
//  * Tap dances
//  */
// qk_tap_dance_action_t tap_dance_actions[] = {
//     // Tap once for Escape, twice for Caps Lock
//     [TD_TAB_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC)
// };





// Lighting layers
const rgblight_segment_t PROGMEM rgb_base[] = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_BLACK});
const rgblight_segment_t PROGMEM rgb_swe[] = RGBLIGHT_LAYER_SEGMENTS({10, 1, HSV_YELLOW});
const rgblight_segment_t PROGMEM rgb_fun[] = RGBLIGHT_LAYER_SEGMENTS({10, 1, HSV_GREEN});
const rgblight_segment_t PROGMEM rgb_num[] = RGBLIGHT_LAYER_SEGMENTS({10, 1, HSV_BLUE});
const rgblight_segment_t PROGMEM rgb_nav[] = RGBLIGHT_LAYER_SEGMENTS({10, 1, HSV_CYAN});
const rgblight_segment_t PROGMEM rgb_sym[] = RGBLIGHT_LAYER_SEGMENTS({10, 1, HSV_GREEN});
const rgblight_segment_t PROGMEM rgb_ext[] = RGBLIGHT_LAYER_SEGMENTS({10, 1, HSV_MAGENTA});
// Array of lighting layers
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_base,
    rgb_swe,
    rgb_fun,
    rgb_num,
    rgb_nav,
    rgb_sym,
    rgb_ext
);
// Funcs
void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}
layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
    return state;
}
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _SWE));
    rgblight_set_layer_state(2, layer_state_cmp(state, _FUN));
    rgblight_set_layer_state(3, layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(4, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(5, layer_state_cmp(state, _SYM));
    rgblight_set_layer_state(6, layer_state_cmp(state, _EXT));
    // Special handling for alt-tab
    if (isAltReg && !IS_LAYER_ON_STATE(state, _EXT)) {
        unregister_code(KC_LALT);
        isAltReg = false;
    }
    return state;;
}

void oneshot_mods_changed_user(uint8_t mods) {
  if (mods & MOD_MASK_SHIFT) {
    rgblight_sethsv_at(HSV_RED, 10);
  }
  if (!mods) {
    default_layer_state_set_user(layer_state);
    layer_state_set_user(layer_state);
  }
}
void oneshot_locked_mods_changed_user(uint8_t mods) {
  if (mods & MOD_MASK_SHIFT) {
    rgblight_sethsv_at(HSV_RED, 10);
  }
  if (!mods) {
    default_layer_state_set_user(layer_state);
    layer_state_set_user(layer_state);
  }
}
void caps_word_set_user(bool active) {
    if (active) {
      rgblight_sethsv_at(HSV_RED, 10);
    } else {
      default_layer_state_set_user(layer_state);
      layer_state_set_user(layer_state);
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L_BOT:
            return 100;
        case NUM_SPC:
            return 150;
        default:
            return TAPPING_TERM;
    }
}
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NUM_SPC:
            return false;
        default:
            return true;
    }
}
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NUM_SPC:
            return false;
        default:
            return true;
    }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case K_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;
        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case K_UNDS:
            return true;
        // Deactivate Caps Word.
        default:
            return false;
    }
}
