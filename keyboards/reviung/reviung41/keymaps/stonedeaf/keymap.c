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
    _NUM,
    _NAV,
    _SYM,
    _COM
};

#define ___N___ KC_NO

enum custom_keycodes {
  GUI_ALT = SAFE_RANGE,
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

// #define MY_HALF ALGR(KC_7)
// #define MY_QART ALGR(KC_6)
// #define MY_POW1 ALGR(S(KC_1))
// #define MY_POW2 ALGR(KC_2)
// #define MY_POW3 ALGR(KC_3)

#define C_LEFT  C(KC_LEFT)
#define C_RGHT  C(KC_RGHT)
#define C_Z   C(KC_Z)
#define C_X   C(KC_X)
#define C_C   C(KC_C)
#define C_V   C(KC_V)

#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)

#define L_MID OS_LSFT//KC_LSPO   //  (  or SHIFT
#define R_MID OS_RSFT//KC_RSPC   //  )  or SHIFT
#define L_BOT KC_LCPO   // DEL or CTL
#define R_BOT LALT_T(KC_ENT) // ENT or ALT

#define SPC_SYM LT(_SYM, KC_SPC)
#define NUM TT(_NUM)
#define NAV TT(_NAV)
#define SYM MO(_SYM)
 
#define TOP_LAYER_NAV_CLUSTER

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

#ifndef TOP_LAYER_NAV_CLUSTER
  [_BASE] = LAYOUT_reviung41(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    L_MID,    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     MY_SCLN,  R_MID,
    L_BOT,    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   K_MINS,   R_BOT,
                                            GUI_ALT,  SPC_SYM, TG(_SWE),  TT(_NUM), TT(_NAV)
  ),
#else
  [_BASE] = LAYOUT_reviung41(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    L_MID,    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_UP,    R_MID,
    L_BOT,    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     KC_COMM,  KC_LEFT,  KC_DOWN,  KC_RGHT,
                                            GUI_ALT,  SPC_SYM,  KC_ENT,   TT(_NUM), MO(_NAV)
  ),
#endif
  [_SWE] = LAYOUT_reviung41(
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  SW_AA,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  SW_OE,    SW_AE,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  K_COMM,   K_DOT,    K_MINS,   KC_ENT,
                                            GUI_ALT,  KC_SPC, TG(_SWE),   KC_RSFT,  MO(_NAV)
  ),

  [_NUM] = LAYOUT_reviung41(
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,  S(KC_F12),            KC_PSLS,  KC_P7,    KC_P8,    KC_P9,    KC_PMNS,  _______,
    _______,  KC_F5,    KC_F6,    KC_F7,    KC_F8,  C(KC_F12),            KC_PAST,  KC_P4,    KC_P5,    KC_P6,    KC_PPLS,  _______,
    _______,  KC_F9,    KC_F10,   KC_F11,   KC_F12, A(KC_HOME),           KC_KP_0,  KC_P1,    KC_P2,    KC_P3,    KC_PDOT,  KC_PENT,
                                            _______,  KC_SPC,  TG(_NUM),  TG(_NUM),  ___N___
  ),

  [_NAV] = LAYOUT_reviung41(
    KC_0,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,               ___N___,  ___N___,  ___N___,  ___N___,  ___N___,  _______,
    _______,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,               ___N___,  ___N___,  KC_PGUP,  ___N___,  KC_HOME,  _______,
    _______,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_DEL,             ___N___,  ___N___,  KC_PGDN,  C_LEFT,   KC_END,   C_RGHT,
                                            _______,  KC_SPC,  TG(_NAV),  TG(_NAV), ___N___
  ),

#ifdef TOP_LAYER_NAV_CLUSTER
  [_SYM] = LAYOUT_reviung41(
    K_QUES,   K_EXLM,   K_AT,     K_HASH,   K_DLR,    K_PERC,             ___N___,  ___N___,  ___N___,  ___N___,  ___N___,  _______,
    _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,               K_PIPE,  K_AMPR,    ___N___,  ___N___,  K_SCLN,   _______,
    _______,  C(KC_Z),  C(KC_X),  C(KC_C),  C(KC_V),  ___N___,            K_CIRC,  K_TILD,    K_COMM,   K_DOT,    K_MINS,   K_SCLN,
                                            _______,  KC_SPC,  TG(_SYM),  ___N___,  ___N___
  ),
#else
  [_SYM] = LAYOUT_reviung41(
    _______,  K_EXLM,   K_AT,     K_HASH,   K_DLR,    K_PERC,             KC_PSCR,  ___N___,  KC_PAUSE, ___N___,  KC_P,     SW_AA,
    _______,  ___N___,  ___N___,  ___N___,  ___N___,  ___N___,            ___N___,  ___N___,  ___N___,  ___N___,  SW_OE,    SW_AE,
    _______,  C(KC_Z),  C(KC_X),  C(KC_C),  C(KC_V),  ___N___,            ___N___,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,  _______,
                                            _______,  KC_SPC,  TG(_SYM),  ___N___,  RGB_MOD
  ),
#endif

  [_COM] = LAYOUT_reviung41(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_LSFT,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_RSFT,
    KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_MINS,  KC_RCTL,
                                            KC_LALT,  KC_SPC,  KC_ESC,  KC_SLSH, KC_BSLS
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

const key_override_t **key_overrides = (const key_override_t *[]){
    &shift_backspace_override,
    &gui_w_override,
    NULL // Null terminate the array of overrides!
};



/* 
 * Combos
 */
// COMBO_ENABLE = yes Goes in rules.mk
enum combos {
    AB_CO, // Debug
    TQ_CO,                  // Tab + Q = Esc
    // ZX_CO, XC_CO, CV_CO,    // Cut Copy Paste
    QW_CO, WE_CO, ER_CO,    // " ' `
    TG_CO, YH_CO,           // | &
    BG_CO, NH_CO,           // fs bs
    TY_CO,                  // ~
    OP_CO, IO_CO, UI_CO,    // = + *
    RT_CO, YU_CO,           // < >
    FG_CO, HJ_CO,           // { }
    VB_CO, NM_CO,           // [ ]
    DF_CO, JK_CO,           // ( )
    CV_CO, MC_CO,           // fs bs
    AA_CO, AE_CO, OE_CO,    // å ä ö
    FS_CO, BS_CO,           // fs bs
    EX_CO, SC_CO, SC2_CO,   // ! ; ;
    SL_CO, SM_CO, GM_CO,
    MKL_CO,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM ab_co[] = {KC_A, KC_B, COMBO_END};
const uint16_t PROGMEM tq_co[] = {KC_TAB, KC_Q, COMBO_END};
// const uint16_t PROGMEM zx_co[] = {KC_Z, KC_X, COMBO_END};
// const uint16_t PROGMEM xc_co[] = {KC_X, KC_C, COMBO_END};
// const uint16_t PROGMEM cv_co[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM qw_co[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM we_co[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM er_co[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM tg_co[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM yh_co[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM bg_co[] = {KC_B, KC_G, COMBO_END};
const uint16_t PROGMEM nh_co[] = {KC_N, KC_H, COMBO_END};
const uint16_t PROGMEM ty_co[] = {KC_T, KC_Y, COMBO_END};
const uint16_t PROGMEM op_co[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM io_co[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM ui_co[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM rt_co[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM yu_co[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM fg_co[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM hj_co[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM vb_co[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM nm_co[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM df_co[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_co[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM cv_co[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM mc_co[] = {KC_M, KC_COMM, COMBO_END};

const uint16_t PROGMEM aa_co[] = {KC_P, KC_BSPC, COMBO_END};
const uint16_t PROGMEM ae_co[] = {KC_SCLN, KC_RSFT, COMBO_END};
const uint16_t PROGMEM oe_co[] = {KC_L, KC_SCLN, COMBO_END};

const uint16_t PROGMEM fs_co[] = {KC_DOT, KC_MINS, COMBO_END};
const uint16_t PROGMEM bs_co[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM ex_co[] = {KC_SCLN, KC_MINS, COMBO_END};
const uint16_t PROGMEM sc_co[] = {KC_SCLN, KC_DOT, COMBO_END};
const uint16_t PROGMEM sc2_co[] = {KC_MINS, KC_RCTL, COMBO_END};
const uint16_t PROGMEM sl_co[] = {KC_S, KC_L, COMBO_END};
const uint16_t PROGMEM sm_co[] = {KC_S, KC_M, COMBO_END};
const uint16_t PROGMEM gm_co[] = {KC_G, KC_M, COMBO_END};
const uint16_t PROGMEM mkl_co[] = {KC_M, KC_K, KC_L, COMBO_END};
/* 
 * ,-----------------------------------------------------------------.
 * T Esc Q  "  W  '  E  ´  R  <  T  ~  Y  >  U  *  I  +  O  =  P  Å  B
 * |-----+-----+-----+-----+---- | --- & ----+-----+-----+-----+-----+
 * S     A     S     D  (  F  {  G     H  }  J  )  K     L  Ö  ;  Ä  S
 * |-----+-----+-----+-----+---- / --- \ ----+-----+-----+---- ! ----+
 * C     Z     X     C  /  V  [  B     N  ]  M  \  ,  \  .  /  -  ;  C
 * `-----------------------------------------------------------------'
 */
/* 
 * ,-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----.
 * | Esc    "     '     ´     <     ~     >     *     +     =     Å  | 
 * +                             |     &                             +
 * |                    (     {           }     )           Ö     Ä  |
 * +                             /     \                      ; !    +
 * |                    /     [           ]     \     \     /     ;  |
 * `-----------------------------------------------------------------'
 */
combo_t key_combos[] = {
    [AB_CO] = COMBO(ab_co, KC_C),
    [TQ_CO] = COMBO(tq_co, KC_ESC),
    // [ZX_CO] = COMBO(zx_co, C(KC_X)),
    // [XC_CO] = COMBO(xc_co, C(KC_C)),
    // [CV_CO] = COMBO(cv_co, C(KC_V)),
    [QW_CO] = COMBO(qw_co, K_DQUO),
    [WE_CO] = COMBO(we_co, K_QUOT),
    [ER_CO] = COMBO(er_co, K_GRAVE),

    [TG_CO] = COMBO(tg_co, K_PIPE),
    [YH_CO] = COMBO(yh_co, K_AMPR),
    [BG_CO] = COMBO(bg_co, K_SLASH),
    [NH_CO] = COMBO(nh_co, K_BACKSLASH),

    [TY_CO] = COMBO(ty_co, K_TILDE),
    [OP_CO] = COMBO(op_co, K_EQUAL),
    [IO_CO] = COMBO(io_co, K_PLUS),
    [IO_CO] = COMBO(ui_co, K_ASTR),
    [RT_CO] = COMBO(rt_co, K_LT),
    [YU_CO] = COMBO(yu_co, K_GT),
    [FG_CO] = COMBO(fg_co, K_LEFT_CURLY_BRACE),
    [HJ_CO] = COMBO(hj_co, K_RIGHT_CURLY_BRACE),
    [VB_CO] = COMBO(vb_co, K_LEFT_BRACKET),
    [NM_CO] = COMBO(nm_co, K_RIGHT_BRACKET),
    [DF_CO] = COMBO(df_co, K_LEFT_PAREN),
    [JK_CO] = COMBO(jk_co, K_RIGHT_PAREN),
    [CV_CO] = COMBO(cv_co, K_SLASH),
    [MC_CO] = COMBO(mc_co, K_BACKSLASH),

    [AA_CO] = COMBO(aa_co, SW_AA),
    [AE_CO] = COMBO(ae_co, SW_AE),
    [OE_CO] = COMBO(oe_co, SW_OE),

    [FS_CO] = COMBO(fs_co, C(KC_LEFT)),
    [BS_CO] = COMBO(bs_co, K_BACKSLASH),
    [EX_CO] = COMBO(ex_co, K_EXCLAIM),
    [SC_CO] = COMBO(sc_co, K_SCLN),
    [SC2_CO] = COMBO(sc2_co, KC_ENT),
    [SL_CO] = COMBO(sl_co, STR_SL),
    [SM_CO] = COMBO(sm_co, STR_SM),
    [GM_CO] = COMBO(gm_co, STR_GM),
    [MKL_CO] = COMBO(mkl_co, STR_PW)
};





// /* 
//  * Tap dances
//  */
// qk_tap_dance_action_t tap_dance_actions[] = {
//     // Tap once for Escape, twice for Caps Lock
//     [TD_TAB_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC)
// };





// Lighting layers
const rgblight_segment_t PROGMEM rgb_base[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 10, HSV_BLACK}
);
const rgblight_segment_t PROGMEM rgb_swe[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 1, HSV_YELLOW}
);
const rgblight_segment_t PROGMEM rgb_num[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 1, HSV_BLUE}
);
const rgblight_segment_t PROGMEM rgb_nav[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 1, HSV_RED}
);
const rgblight_segment_t PROGMEM rgb_sym[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 1, HSV_GREEN}
);
// Array of lighting layers
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_base,
    rgb_swe,
    rgb_num,
    rgb_nav,
    rgb_sym
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
    rgblight_set_layer_state(2, layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(3, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(4, layer_state_cmp(state, _SYM));
    return state;
}

void oneshot_mods_changed_user(uint8_t mods) {
  if (mods & MOD_MASK_SHIFT) {
    rgblight_sethsv_at(HSV_MAGENTA, 10);
  }
  if (!mods) {
    default_layer_state_set_user(layer_state);
    layer_state_set_user(layer_state);
  }
}
void oneshot_locked_mods_changed_user(uint8_t mods) {
  if (mods & MOD_MASK_SHIFT) {
    rgblight_sethsv_at(HSV_MAGENTA, 10);
  }
  if (!mods) {
    default_layer_state_set_user(layer_state);
    layer_state_set_user(layer_state);
  }
}
