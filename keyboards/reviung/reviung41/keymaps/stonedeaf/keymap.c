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

//#define USE_TAP_DANCE

enum layer_names {
    _BASE,
    _SWE,
    _FUN,
    _NUM,
    _SYM,
    _NAV,
    _EXT,
    _COM
};

enum custom_keycodes {
  GUI_ALT = SAFE_RANGE,
  ALT_TAB,
  MY_SCLN,
  MY_PRN,
  TT_OFF,
  STR_SL,
  STR_SM,
  STR_GM,
  STR_PW,
  STR_EP
};

#define ___N___ KC_NO
#define __XXX__ KC_NO
#define ___T___ TT_OFF
#define __XTX__ TT_OFF

#define C_LEFT  C(KC_LEFT)
#define C_RGHT  C(KC_RGHT)
#define C_Z   C(KC_Z)
#define C_X   C(KC_X)
#define C_C   C(KC_C)
#define C_V   C(KC_V)

#define A_F12 A(KC_F12)
#define C_F12 C(KC_F12)
#define S_F12 S(KC_F12)
#define A_HOME A(KC_HOME)

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
#define L_BOT LCTL_T(KC_TAB)
#define R_BOT RCTL_T(KC_DEL)

#define FUN_SPC LT(_FUN, KC_SPC)
#define NUM MO(_NUM)
#define NUM_SPC LT(_NUM, KC_SPC)
#define NUM_BSP LT(_NUM, KC_BSP)
#define NUM_DEL LT(_NUM, KC_DEL)
#define SYM_ENT LT(_SYM, KC_ENT)
#define SYM_BSP LT(_SYM, KC_BSPC)
#define NAV MO(_NAV)
#define NAV_GUI LT(_NAV, KC_LGUI)
#define TT_NAV TT(_NAV)
#define EXT MO(_EXT)
#define TT_EXT TT(_EXT)
#define OS_FUN OSL(_FUN)
#define GUI_Z  LGUI_T(KC_Z)
#define GUI_X  LGUI_T(KC_X)
#define ALT_Z  LALT_T(KC_Z)
#define ALT_X  LALT_T(KC_X)


#ifdef USE_TAP_DANCE
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;
typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;
// Tap dance enums
enum {
    TD_COM,
    TD_DOT,
    TD_MIN,
};
#define MY_COM TD(TD_COM)
#define MY_DOT TD(TD_DOT)
#define MY_MIN TD(TD_MIN)
td_state_t cur_dance(qk_tap_dance_state_t *state);
// For the x tap dance. Put it here so it can be used in any keymap
void x_finished(qk_tap_dance_state_t *state, void *user_data);
void x_reset(qk_tap_dance_state_t *state, void *user_data);
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_reviung41(
    KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    L_MID,    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_LEAD,  R_MID,
    L_BOT,    ALT_Z,    GUI_X,    KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     K_COMM,   K_DOT,    K_MINS,   R_BOT,
                                            TT_NAV,   NUM_SPC,  OS_FUN,   SYM_ENT,  TT_EXT
  ),

  [_SWE] = LAYOUT_reviung41(
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
                                            _______,  _______, TG(_SWE),  _______,  _______
  ),

  [_FUN] = LAYOUT_reviung41(
    K_TILD,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,               KC_VOLU,  ___N___,  KC_INS,   KC_CALC,  KC_PSCR,  _______,
    S_F12,    KC_6,     KC_7,     KC_8,     KC_9,     KC_0,               KC_VOLD,  ___N___,  ___N___,  ___N___,  ___N___,  _______,
    C_F12,    A_F12,    KC_F12,   A_HOME,   VS_BACK,  VS_FWD,             KC_MPLY,  ___N___,  ___N___,  ___N___,  ___N___,  _______,
                                            ___N___,  ___N___,  __XTX__,  ___N___,  ___N___
  ),

  [_NUM] = LAYOUT_reviung41(
    ___N___,  ___N___,  ___N___,  ___N___,  ___N___,  ___N___,            KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   ___N___,  _______,
    K_LSFT,   VS_BACK,  VS_FWD,   K_LCTL,   K_LSFT,   ___N___,            KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  ___N___,  _______,
    K_LCTL,   K_LALT,   C(KC_X),  C(KC_C),  C(KC_V),  ___N___,            ___N___,  ___N___,  ___N___,  ___N___,  ___N___,  _______,
                                            KC_LGUI,  __XXX__,  ___N___,  KC_ENT,   ___N___
  ),

  [_SYM] = LAYOUT_reviung41(
    _______,  K_GRV,    K_DQUO,   K_LBRC,   K_RBRC,   K_PIPE,             KC_PSLS,  KC_PMNS,  KC_P7,    KC_P8,    KC_P9,    _______,
    MY_PRN,   K_SLSH,   K_LPRN,   K_LCBR,   K_RCBR,   K_EQL,              KC_PAST,  KC_PPLS,  KC_P4,    KC_P5,    KC_P6,    KC_PENT,
    _______,  K_BSLS,   K_RPRN,   K_LT,     K_GT,     K_AMPR,             KC_ESC,   KC_PDOT,  KC_P1,    KC_P2,    KC_P3,    K_DOT,
                                            ___N___,  KC_SPC,   ___N___,  __XXX__,  KC_P0
  ),

  [_NAV] = LAYOUT_reviung41(
    ALT_TAB,  G(KC_L),  G(KC_2),  G(KC_E),  ___N___,  ___N___,            ___N___,  ___N___,  ___N___,  ___N___,  KC_HOME,  _______,
    K_LSFT,   VS_BACK,  VS_FWD,   KC_F12,   ___N___,  ___N___,            ___N___,  ___N___,  KC_PGUP,  KC_HOME,  KC_UP,    KC_END, 
    K_LCTL,   K_LALT,   C(KC_X),  C(KC_C),  C(KC_V),  ___N___,            ___N___,  ___N___,  KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,
                                            __XTX__,  KC_SPC,   ___T___,  KC_ENT,   K_RCTL    
  ),

  [_EXT] = LAYOUT_reviung41(
    ___N___,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,               KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_HOME,  _______,
    K_LSFT,   KC_F10,   KC_F11,   KC_F12,   ___N___,  ___N___,             ___N___,  ___N___,  KC_PGUP,  KC_HOME,  KC_UP,    KC_END,
    K_LCTL,   K_LALT,   C(KC_X),  C(KC_C),  C(KC_V),  ___N___,             ___N___,  ___N___,  KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,
                                            ___N___,  KC_SPC,   ___T___,   KC_ENT,   __XTX__
  ),

  [_COM] = LAYOUT_reviung41(
    KC_1,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_4,
    KC_2,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_0,     KC_5,
    KC_3,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     KC_7,     KC_8,     KC_9,     KC_6,
                                            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5
  ),
};



bool isAltReg = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    
    switch (keycode) {
    case ALT_TAB:
        if (record->event.pressed) {
            if (!isAltReg) {
                register_code(KC_LALT);
                isAltReg = true;
            }
            tap_code(KC_TAB);
        }
        break;
    case TT_OFF:
        if (record->event.pressed) {
            layer_clear();
        }
        return false;
    case MY_PRN:
        if (record->event.pressed) {
            tap_code16(K_LPRN);
            tap_code16(K_RPRN);
            tap_code16(KC_LEFT);
        }
        return false;
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
    case STR_EP:
        if (record->event.pressed)
            SEND_STRING("Leo is the best!");
        return false;
    }

    return true;
};



/*
 * Overrides
 */
// //const key_override_t shift_backspace_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
// //const key_override_t gui_w_override = ko_make_basic(MOD_MASK_GUI, KC_W, LGUI(KC_2));
// //const key_override_t ctrl_up_override = ko_make_basic(MOD_MASK_CTRL, KC_UP, KC_HOME);
// //const key_override_t ctrl_down_override = ko_make_basic(MOD_MASK_CTRL, KC_DOWN, KC_END);
// //const key_override_t shift_dot_override = ko_make_basic(MOD_MASK_SHIFT, K_DOT, K_EXLM);
// //const key_override_t shift_comm_override = ko_make_basic(MOD_MASK_SHIFT, K_COMM, K_QUES);
// //const key_override_t ctrl_dot_override = ko_make_basic(MOD_MASK_CTRL, K_DOT, SW_AA);
// //const key_override_t ctrl_comm_override = ko_make_basic(MOD_MASK_CTRL, K_COMM, K_QUES);

// const key_override_t **key_overrides = (const key_override_t *[]){
// //    &shift_backspace_override,
// //    &gui_w_override,
// //    &ctrl_up_override,
// //    &ctrl_down_override,
// //    &shift_dot_override,
// //    &shift_comm_override,
// //    &ctrl_dot_override,
// //    &ctrl_comm_override,
//     NULL // Null terminate the array of overrides!
// };



/* 
 * Combos
 */
// COMBO_ENABLE = yes Goes in rules.mk
enum combos {
    CO_AB, // Debug
    CO_1Q,                  // Esc
    CO_AS,                  // 
    CO_QW, CO_WE, CO_ER,    // " ' `
    CO_TG, CO_YH,           // | &
    CO_BG, CO_NH,           // fs bs
    CO_TY,                  // ~
    CO_OP, CO_IO, CO_UI,    // = + *
    CO_RT, CO_YU,           // < >
    CO_FG, CO_HJ,           // { }
    CO_VB, CO_NM,           // [ ]
    CO_DF, CO_JK,           // ( )
    //CO_KL, CO_L0,           // ! ? ; :
    CO_CV, CO_M7,           // fs bs
    CO_AA, CO_AE, CO_OE,    // å ä ö
    CO_78, CO_89,           // fs bs
    CO_96, CO_3C,           // ö Gui
    CO_SL, CO_SM, CO_GM,
    CO_MKL,
    CO_F1W, CO_F1E, CO_F1L,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM co_ab[] = {KC_A, KC_B, COMBO_END};
const uint16_t PROGMEM co_1q[] = {KC_1, KC_Q, COMBO_END};
const uint16_t PROGMEM co_as[] = {KC_A, KC_S, COMBO_END};
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
//const uint16_t PROGMEM co_kl[] = {KC_K, KC_L, COMBO_END};
//const uint16_t PROGMEM co_l0[] = {KC_L, KC_0, COMBO_END};
const uint16_t PROGMEM co_cv[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM co_m7[] = {KC_M, KC_7, COMBO_END};
const uint16_t PROGMEM co_aa[] = {KC_P, KC_4, COMBO_END};
const uint16_t PROGMEM co_ae[] = {KC_0, KC_5, COMBO_END};
const uint16_t PROGMEM co_oe[] = {KC_L, KC_0, COMBO_END};
const uint16_t PROGMEM co_78[] = {KC_7, KC_8, COMBO_END};
const uint16_t PROGMEM co_89[] = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM co_96[] = {KC_9, KC_6, COMBO_END};
const uint16_t PROGMEM co_3C[] = {KC_3, KC_C, COMBO_END};
const uint16_t PROGMEM co_sl[] = {KC_S, KC_L, COMBO_END};
const uint16_t PROGMEM co_sm[] = {KC_S, KC_M, COMBO_END};
const uint16_t PROGMEM co_gm[] = {KC_G, KC_M, COMBO_END};
const uint16_t PROGMEM co_mkl[] = {KC_M, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM co_f1w[] = {KC_F1, KC_W, COMBO_END};
const uint16_t PROGMEM co_f1e[] = {KC_F1, KC_E, COMBO_END};
const uint16_t PROGMEM co_f1l[] = {KC_F1, KC_L, COMBO_END};
/* 
 * ,-----------------------------------------------------------------.
 * 1 Esc Q  "  W  '  E  ´  R  [  T  ~  Y  ]  U  *  I  +  O  =  P  Å  B
 * |-----+-----+-----+-----+---- | --- & ----+-----+-----+-----+-----+
 * S     A     S     D  (  F  {  G     H  }  J  )  K     L  Ö  ;  Ä  S
 * |-----+-----+-----+-----+---- / --- \ ----+-----+-----+-----+-----+
 * C     Z     X     C  /  V  <  B     N  >  M  \  ,     .     - Ent C
 * `-----------------------------------------------------------------'
 */
/* 
 * ,-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----.
 * | Esc    "     '     ´     [     ~     ]     *     +     =     Å  | 
 * +                             |     &                             +
 * |                    (     {           }     )           Ö     Ä  |
 * +                             /     \                             +
 * |                    /     <           >     \                Ent |
 * `-----------------------------------------------------------------'
 */
combo_t key_combos[] = {
    [CO_AB] = COMBO(co_ab, KC_C),
    [CO_1Q] = COMBO(co_1q, KC_ESC),
    [CO_AS] = COMBO(co_as, K_AT),
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
    //[CO_KL] = COMBO(co_kl, K_SCLN),
    //[CO_L0] = COMBO(co_l0, K_COLN),
    [CO_CV] = COMBO(co_cv, K_SLASH),
    [CO_M7] = COMBO(co_m7, K_BACKSLASH),
    [CO_AA] = COMBO(co_aa, SW_AA),
    [CO_AE] = COMBO(co_ae, SW_AE),
    [CO_OE] = COMBO(co_oe, SW_OE),
    [CO_78] = COMBO(co_78, K_QUES),
    [CO_89] = COMBO(co_89, K_EXLM),
    [CO_96] = COMBO(co_96, SW_OE),
    [CO_3C] = COMBO(co_3C, KC_LGUI ),
    [CO_SL] = COMBO(co_sl, STR_SL),
    [CO_SM] = COMBO(co_sm, STR_SM),
    [CO_GM] = COMBO(co_gm, STR_GM),
    [CO_MKL] = COMBO(co_mkl, STR_PW),
    [CO_F1W] = COMBO(co_f1w, G(KC_2)),
    [CO_F1E] = COMBO(co_f1e, G(KC_E)),
    [CO_F1L] = COMBO(co_f1l, G(KC_L))
};






// Lighting layers
const rgblight_segment_t PROGMEM rgb_base[] = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_BLACK});
const rgblight_segment_t PROGMEM rgb_swe[] = RGBLIGHT_LAYER_SEGMENTS({10, 1, HSV_YELLOW});
const rgblight_segment_t PROGMEM rgb_fun[] = RGBLIGHT_LAYER_SEGMENTS({10, 1, HSV_YELLOW});
const rgblight_segment_t PROGMEM rgb_num[] = RGBLIGHT_LAYER_SEGMENTS({10, 1, HSV_CYAN});
const rgblight_segment_t PROGMEM rgb_sym[] = RGBLIGHT_LAYER_SEGMENTS({10, 1, HSV_GREEN});
const rgblight_segment_t PROGMEM rgb_nav[] = RGBLIGHT_LAYER_SEGMENTS({10, 1, 155, 255, 255});
const rgblight_segment_t PROGMEM rgb_ext[] = RGBLIGHT_LAYER_SEGMENTS({10, 1, HSV_BLUE});
// Array of lighting layers
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_base,
    rgb_swe,
    rgb_fun,
    rgb_num,
    rgb_sym,
    rgb_nav,
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
    rgblight_set_layer_state(4, layer_state_cmp(state, _SYM));
    rgblight_set_layer_state(5, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(6, layer_state_cmp(state, _EXT));
    // Special handling for alt-tab
    if (isAltReg && !IS_LAYER_ON_STATE(state, _NAV)) {
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
            return 125;
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        //case FUN_SPC:
        case NUM_SPC:
        case ALT_X:
        case ALT_Z:
        case GUI_X:
        case GUI_Z:
            // Immediately select the hold action when another key is tapped.
            return false;
        default:
            // Do not select the hold action when another key is tapped.
            return true;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        //case FUN_SPC:
        case NUM_SPC:
        case ALT_X:
        case ALT_Z:
        case GUI_X:
        case GUI_Z:
            // Immediately select the hold action when another key is pressed.
            return false;
        default:
            // Do not select the hold action when another key is pressed.
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

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case K_DOT:
        case K_COMM:
        case K_MINS:
            return true;
        default:
            return false;
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        // case KC_2:
        //     register_code16((!shifted) ? KC_2 : K_QUES);
        //     break;
        case KC_4:
            register_code16((!shifted) ? KC_4 : K_DOLLAR);
            break;
        default:
            if (shifted)
                add_weak_mods(MOD_BIT(KC_LSFT));
            register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        // case KC_2:
        //     unregister_code16((!shifted) ? KC_2 : K_QUES);
        //     break;
        case KC_4:
            unregister_code16((!shifted) ? KC_4 : K_DOLLAR);
            break;
        default:
            unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}



LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_LEAD) { tap_code16(K_SCLN); }
    SEQ_TWO_KEYS(KC_LEAD, KC_LEAD) { tap_code16(K_COLN); }
    SEQ_TWO_KEYS(KC_P, KC_P) { tap_code16(KC_PSCR); }
    SEQ_ONE_KEY(KC_I) { tap_code16(KC_INS); }
    SEQ_ONE_KEY(KC_COMM) { tap_code16(K_QUES); }
    SEQ_ONE_KEY(KC_DOT) { tap_code16(K_EXLM); }
    SEQ_ONE_KEY(KC_A) { tap_code16(K_AT); }
    SEQ_ONE_KEY(KC_L) { SEND_STRING("Leo is the best!"); }

    // Paren
    SEQ_ONE_KEY(KC_P) { 
        tap_code16(K_LPRN);
        tap_code16(K_RPRN);
        tap_code16(KC_LEFT);
    }
    // Del to End
    SEQ_TWO_KEYS(KC_D, KC_E) {
        register_code(KC_LSFT);
        tap_code(KC_END);
        unregister_code(KC_LSFT);
        tap_code(KC_DEL);
    }
    // Del to Home
    SEQ_TWO_KEYS(KC_D, KC_H) {
        register_code(KC_LSFT);
        tap_code(KC_HOME);
        unregister_code(KC_LSFT);
        tap_code(KC_BSPC);
    }
    // Select Line
    SEQ_TWO_KEYS(KC_S, KC_L) {
        tap_code(KC_HOME);
        tap_code(KC_HOME);
        register_code(KC_LSFT);
        tap_code(KC_DOWN);
        unregister_code(KC_LSFT);
    }
  }
}


#ifdef USE_TAP_DANCE
/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }
    if (state->count == 2) {
        return TD_DOUBLE_TAP;
        // if (state->interrupted || !state->pressed) return TD_DOUBLE_TAP;
        // else return TD_DOUBLE_HOLD;
    }
    return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t com_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t dot_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t min_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void com_finished(qk_tap_dance_state_t *state, void *user_data) {
    com_tap_state.state = cur_dance(state);
    switch (com_tap_state.state) {
        case TD_SINGLE_TAP:  tap_code16(K_COMM); break;
        case TD_SINGLE_HOLD: tap_code16(K_SCLN); break;
        case TD_DOUBLE_TAP:  tap_code16(SW_AA); break;
        default: break;
    }
}
void dot_finished(qk_tap_dance_state_t *state, void *user_data) {
    dot_tap_state.state = cur_dance(state);
    switch (dot_tap_state.state) {
        case TD_SINGLE_TAP:  tap_code16(K_DOT); break;
        case TD_SINGLE_HOLD: tap_code16(K_COLN); break;
        case TD_DOUBLE_TAP:  tap_code16(SW_AE); break;
        default: break;
    }
}
void min_finished(qk_tap_dance_state_t *state, void *user_data) {
    min_tap_state.state = cur_dance(state);
    switch (min_tap_state.state) {
        case TD_SINGLE_TAP:  tap_code16(K_MINS); break;
        case TD_SINGLE_HOLD: tap_code16(K_UNDS); break;
        case TD_DOUBLE_TAP:  tap_code16(SW_OE); break;
        default: break;
    }
}

void x_reset(qk_tap_dance_state_t *state, void *user_data) {
    // switch (xtap_state.state) {
    //     default: break;
    // }
    com_tap_state.state = TD_NONE;
    dot_tap_state.state = TD_NONE;
    min_tap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_COM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, com_finished, x_reset),
    [TD_DOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dot_finished, x_reset),
    [TD_MIN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, min_finished, x_reset),
};
#endif
