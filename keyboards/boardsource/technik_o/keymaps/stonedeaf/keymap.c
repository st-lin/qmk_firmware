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
#include "keymap_swedish.h"

enum layers {
    _MAIN,
    _NUM,
    _NAV,
    _SYM,
    _NUL,
    _RAISE,
    _LOWER,
};

#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define SPACE   LT(_NUM, KC_SPC)

#define SW_AT   ALGR(KC_2)
#define SW_USD  ALGR(KC_4)
#define SW_LBR  ALGR(KC_7)
#define SW_RBR  ALGR(KC_0)
#define SW_LBU  ALGR(KC_8)
#define SW_RBU  ALGR(KC_9)
#define SW_PIPE ALGR(KC_NUBS)
#define SW_BSLS ALGR(KC_MINS)
#define SW_LARW KC_NUBS
#define SW_RARW S(KC_NUBS)
#define SW_HAT  S(KC_RBRC)
#define SW_AA   KC_LBRC
#define SW_AE   KC_QUOT
#define SW_OE   KC_SCLN

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Main layer
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   UP | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Alt  | GUI  | Lower|    Space    | Raise|      | Left | Down | Right|
 * `-----------------------------------------------------------------------------------'
 */
  [_MAIN] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_F13,  KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_RSFT ,
    _______, KC_LALT, KC_LGUI, _______, LOWER,   SPACE,   SPACE,   RAISE,   _______, KC_LEFT, KC_DOWN, KC_RGHT
  ),
/* Numeric layer
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |      |   7  |   8  |   9  |   *  |   +  |   7  |   8  |   9  |      | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |   4  |   5  |   6  |   /  |   -  |   4  |   5  |   6  |      | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|      |   1  |   2  |   3  |   0  |   0  |   1  |   2  |   3  |      | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Alt  | GUI  |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
  [_NUM] = LAYOUT_ortho_4x12(
    KC_ESC,  _______, KC_KP_7, KC_KP_8, KC_KP_9, KC_PAST, KC_PPLS, KC_KP_7, KC_KP_8, KC_KP_9, _______, KC_DEL,
    KC_LCTL, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_PSLS, KC_PMNS, KC_KP_4, KC_KP_5, KC_KP_6, _______, KC_ENT,
    KC_LSFT, _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_0, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, _______, KC_RSFT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
/* Navigation layer
 * ,-----------------------------------------------------------------------------------.
 * | Tab  | Home |  Up  | End  | PgUp |  F5  | F12  | Home |  Up  | End  | PgUp | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Left | Down | Right| PgDn |  F6  | F12s | Left | Down | Right| PgDn | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|  F1  |  F2  |  F3  |  F4  |  F7  | F12c |  F9  | F10  | F11  | F12  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Alt  | GUI  |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
  [_NAV] = LAYOUT_ortho_4x12(
    KC_ESC,  KC_HOME,   KC_UP,  KC_END, KC_PGUP, _______, _______, KC_HOME,   KC_UP,  KC_END, KC_PGUP, KC_DEL,
    KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_ENT,
    KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RSFT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
/* Symbol layer
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   !  |  @   |  #   |  $   |  %   |  ^   |  (   |  )   |  =   |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |  [   |  ]   |  {   |  }   |  &   |      | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|      |      |      |      |  /   |  \   |  <   |  >   |  |   |      | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Alt  | GUI  |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
  [_SYM] = LAYOUT_ortho_4x12(
    KC_ESC,  S(KC_1), SW_AT,   S(KC_3), SW_USD,  S(KC_5), SW_HAT,  S(KC_8), S(KC_9), S(KC_6), _______, KC_DEL,
    KC_LCTL, _______, _______, _______, _______, SW_LBU,  SW_RBU,  SW_LBR,  SW_RBR,  S(KC_0), _______, KC_ENT,
    KC_LSFT, _______, _______, _______, _______, S(KC_7), SW_BSLS, SW_LARW, SW_RARW, SW_PIPE, _______, KC_RSFT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [_NUL] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_RAISE] = LAYOUT_ortho_4x12(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
    QK_BOOT,   _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
  ),
  [_LOWER] = LAYOUT_ortho_4x12(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    RGB_MOD, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
  )
};



/*
 * Replacements
 */
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_F13, KC_DEL);
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_F13, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL // Null terminate the array of overrides!
};



/* 
 *Combos
 */
/* COMBO_ENABLE = yes */ // Goes in rules.mk
enum combos {
    OP_CO,
    LL_CO,
    DD_CO,
    YH_CO,
    UJ_CO,
    HN_CO,
    JM_CO,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;
const uint16_t PROGMEM op_co[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM ll_co[] = {KC_L, KC_SEMICOLON, COMBO_END};
const uint16_t PROGMEM dd_co[] = {KC_DOT, KC_SLASH, COMBO_END};
const uint16_t PROGMEM yh_co[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM uj_co[] = {KC_U, KC_J, COMBO_END};
const uint16_t PROGMEM hn_co[] = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM jm_co[] = {KC_J, KC_M, COMBO_END};
combo_t key_combos[] = {
    [OP_CO] = COMBO(op_co, SW_AA),
    [LL_CO] = COMBO(ll_co, SW_AE),
    [DD_CO] = COMBO(dd_co, SW_OE),
    [YH_CO] = COMBO(yh_co, S(KC_8)),
    [UJ_CO] = COMBO(uj_co, S(KC_9)),
    [HN_CO] = COMBO(hn_co, SW_LBR),
    [JM_CO] = COMBO(jm_co, SW_RBR)
};
