/* Copyright 2022 Boardsource
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
//#define USE_LEADER_KEY
#define USE_KEY_OVERRIDES

enum layer_names {
    _BASE,
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
  MY_DSPC,
  MY_DPRN,
  MY_DSLS,
  TT_OFF,
  STR_PW,
  STR_EP
};

#define ___N___ KC_NO
#define __XXX__ KC_NO
#define ___T___ TT_OFF
#define __XTX__ TT_OFF

#define C_BSPC  C(KC_BSPC)
#define C_LEFT  C(KC_LEFT)
#define C_RGHT  C(KC_RIGHT)
#define C_Z   C(KC_Z)
#define C_X   C(KC_X)
#define C_C   C(KC_C)
#define C_V   C(KC_V)

#define A_F12 A(KC_F12)
#define C_F12 C(KC_F12)
#define S_F12 S(KC_F12)
#define A_HOME A(KC_HOME)

#define VS_BACK A(KC_LEFT)
#define VS_FWD  A(KC_RIGHT)
#define VS_PREV MEH(KC_N)
#define VS_NEXT MEH(KC_M)
#define VS_CALL LSA(KC_H)
#define VS_CON  LSA(KC_LEFT)
#define VS_EXP  LSA(KC_RIGHT)
#define VS_BLD  RCS(KC_B)
#define VS_FULL LSA(KC_ENT)

#define OS_LGUI OSM(MOD_LGUI)
#define OS_RGUI OSM(MOD_RGUI)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_LALT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)

#define NUM MO(_NUM)
#define NAV MO(_NAV)
#define EXT MO(_EXT)
#define SYM MO(_SYM)
#define GUI_Z  LGUI_T(KC_Z)
#define GUI_X  LGUI_T(KC_X)
#define ALT_Z  LALT_T(KC_Z)
#define ALT_X  LALT_T(KC_X)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_ortho_4x12(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    OS_LSFT,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     MY_SCLN,  OS_RSFT,
    KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     K_COMM,   K_DOT,    KC_UP,    K_MINS,
    KC_ESC,   KC_LALT,  KC_LGUI,  NAV,      NUM,      KC_SPC,             KC_ENT,   SYM,      EXT,      KC_LEFT,  KC_DOWN,  KC_RIGHT
  ),

  [_FUN] = LAYOUT_ortho_4x12(
    ___N___,  ___N___,  ___N___,  ___N___,  ___N___,  ___N___,            ___N___,  ___N___,  ___N___,  ___N___,  ___N___,  ___N___,
    ___N___,  ___N___,  ___N___,  ___N___,  ___N___,  ___N___,            ___N___,  ___N___,  ___N___,  ___N___,  ___N___,  ___N___,
    ___N___,  ___N___,  ___N___,  ___N___,  ___N___,  ___N___,            ___N___,  ___N___,  ___N___,  ___N___,  ___N___,  ___N___,
    ___N___,  ___N___,  ___N___,  ___N___,  ___N___,  ___N___,            ___N___,  ___N___,  ___N___,  ___N___,  ___N___,  ___N___
  ),

  [_NUM] = LAYOUT_ortho_4x12(
    _______,  K_GRV,    K_DQUO,   K_HASH,   ___N___,  ___N___,            KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   ___N___,  _______,
    _______,  K_LCTL,   K_LSFT,   K_LALT,   ___N___,  ___N___,            KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RIGHT, ___N___,  _______,
    _______,  C(KC_Z),  C(KC_X),  C(KC_C),  C(KC_V),  ___N___,            ___N___,  VS_CON,   ___N___,  VS_EXP,   _______,  _______,
    _______,  _______,  _______,  ___N___,  __XXX__,  _______,            _______,  ___N___,  ___N___,  _______,  _______,  _______
  ),

  [_SYM] = LAYOUT_ortho_4x12(
    _______,  K_QUOT,   K_DQUO,   K_HASH,   K_LBRC,   K_PIPE,             KC_PSLS,  KC_PMNS,  KC_P7,    KC_P8,    KC_P9,    _______,
    _______,  ___N___,  K_SLSH,   K_LPRN,   K_LCBR,   K_EQL,              KC_PAST,  KC_PPLS,  KC_P4,    KC_P5,    KC_P6,    _______,
    _______,  K_LALT,   MY_DSLS,  MY_DPRN,  K_LT,     K_AMPR,             KC_PENT,  KC_PDOT,  KC_P1,    KC_P2,    KC_P3,    K_DOT,
    _______,  _______,  _______,  ___N___,  ___N___,  _______,            _______,  __XXX__,  KC_P0,    ___N___,  ___N___,  ___N___
  ),

  [_NAV] = LAYOUT_ortho_4x12(
    ALT_TAB,  G(KC_L),  G(KC_2),  G(KC_E),  ___N___,  ___N___,            ___N___,  ___N___,  VS_PREV,  ___N___,  ___N___,  _______,
    S_F12,    VS_BACK,  VS_FWD,   KC_F12,   VS_CALL,  ___N___,            ___N___,  VS_CON,   VS_NEXT,  VS_EXP,   ___N___,  _______, 
    C_F12,    A_F12,    A_HOME,   ___N___,  ___N___,  ___N___,            ___N___,  ___N___,  ___N___, G(KC_DOT), _______,  _______,
    _______,  _______,  _______,  __XXX__,  ___N___,  _______,            _______,  ___N___,  ___N___,  _______,  _______,  _______
  ),

  [_EXT] = LAYOUT_ortho_4x12(
    ___N___,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,               KC_F6,    KC_F7,    KC_F8,    KC_F9,    _______,  C_BSPC,
    K_LSFT,   KC_F10,   KC_F11,   KC_F12,   VS_FULL,  ___N___,             ___N___,  ___N___,  ___N___,  ___N___,  ___N___,  _______,
    K_LCTL,   K_LALT,   C(KC_X),  C(KC_C),  C(KC_V),  VS_BLD,              ___N___,  ___N___,  ___N___,  KC_HOME,  KC_PGUP,  KC_END,
    _______,  _______,  _______,  ___N___,  ___N___,  _______,             _______,  ___N___,  __XXX__,  C_LEFT,   KC_PGDN,  C_RGHT
  ),

  [_COM] = LAYOUT_ortho_4x12(
    KC_1,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_4,
    KC_2,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_0,     KC_5,
    KC_3,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     KC_7,     KC_8,     KC_9,     KC_6,
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,              KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12
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
    case MY_DSPC:
        if (record->event.pressed) {
            tap_code16(KC_RGHT);
            tap_code16(KC_SPC);
        }
        return false;
    case MY_DPRN:
        if (record->event.pressed) {
            tap_code16(K_LPRN);
            tap_code16(K_RPRN);
            tap_code16(KC_LEFT);
        }
        return false;
    case MY_DSLS:
        if (record->event.pressed) {
            tap_code16(K_SLASH);
            tap_code16(K_SLASH);
            tap_code16(KC_SPC);
        }
        return false;
    case MY_SCLN:
        if (record->event.pressed) {
            if (get_mods() & MOD_MASK_SHIFT) {
                tap_code16(K_COLN);
                return false;
            }
        }
        break;
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



#ifdef USE_KEY_OVERRIDES
/*
 * Overrides
 */
const key_override_t gui_w_override = ko_make_basic(MOD_MASK_GUI, KC_W, LGUI(KC_2));
const key_override_t shift_dot_override = ko_make_basic(MOD_MASK_SHIFT, K_DOT, K_EXLM); 
const key_override_t shift_comm_override = ko_make_basic(MOD_MASK_SHIFT, K_COMM, K_QUES);
const key_override_t shift_cbr_override = ko_make_basic(MOD_MASK_SHIFT, K_LCBR, K_RCBR);
const key_override_t shift_brc_override = ko_make_basic(MOD_MASK_SHIFT, K_LBRC, K_RBRC);
const key_override_t shift_prn_override = ko_make_basic(MOD_MASK_SHIFT, K_LPRN, K_RPRN);
const key_override_t shift_lgt_override = ko_make_basic(MOD_MASK_SHIFT, K_LT, K_GT);

const key_override_t **key_overrides = (const key_override_t *[]){
    &gui_w_override,
    &shift_dot_override,
    &shift_comm_override,
    &shift_cbr_override,
    &shift_brc_override,
    &shift_prn_override,
    &shift_lgt_override,
    NULL // Null terminate the array of overrides!
};
#endif



/* 
 * Combos
 */
// COMBO_ENABLE = yes Goes in rules.mk
enum combos {
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
    CO_CV, CO_M7,           // fs bs
    CO_AA, CO_AE, CO_OE,    // å ä ö
    CO_78, CO_89,           // fs bs
    CO_96, CO_3C,           // ö Gui
    CO_MKL,
    CO_F1W, CO_F1E, CO_F1L,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

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
const uint16_t PROGMEM co_cv[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM co_m7[] = {KC_M, KC_7, COMBO_END};
const uint16_t PROGMEM co_aa[] = {KC_P, KC_4, COMBO_END};
const uint16_t PROGMEM co_ae[] = {KC_0, KC_5, COMBO_END};
const uint16_t PROGMEM co_oe[] = {KC_L, KC_0, COMBO_END};
const uint16_t PROGMEM co_78[] = {KC_7, KC_8, COMBO_END};
const uint16_t PROGMEM co_89[] = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM co_96[] = {KC_9, KC_6, COMBO_END};
const uint16_t PROGMEM co_3C[] = {KC_3, KC_C, COMBO_END};
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
 * C     Z     X     C  /  V  <  B     N  >  M  \  ,  ?  .  !  -  Ö  C
 * `-----------------------------------------------------------------'
 */
/* 
 * ,-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----.
 * | Esc    "     '     ´     [     ~     ]     *     +     =     Å  | 
 * +                             |     &                             +
 * |                    (     {           }     )           Ö     Ä  |
 * +                             /     \                             +
 * |                    /     <           >     \     ?     !     Ö  |
 * `-----------------------------------------------------------------'
 */
combo_t key_combos[] = {
    [CO_1Q] = COMBO(co_1q, KC_ESC),
    [CO_AS] = COMBO(co_as, K_AT),
    [CO_QW] = COMBO(co_qw, K_QUOT),
    [CO_WE] = COMBO(co_we, K_DQUO),
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
    [CO_M7] = COMBO(co_m7, K_BACKSLASH),
    [CO_AA] = COMBO(co_aa, SW_AA),
    [CO_AE] = COMBO(co_ae, SW_AE),
    [CO_OE] = COMBO(co_oe, SW_OE),
    [CO_78] = COMBO(co_78, K_QUES),
    [CO_89] = COMBO(co_89, K_EXLM),
    [CO_96] = COMBO(co_96, SW_OE),
    [CO_3C] = COMBO(co_3C, KC_LGUI),
    [CO_MKL] = COMBO(co_mkl, STR_PW),
    [CO_F1W] = COMBO(co_f1w, G(KC_2)),
    [CO_F1E] = COMBO(co_f1e, G(KC_E)),
    [CO_F1L] = COMBO(co_f1l, G(KC_L))
};
