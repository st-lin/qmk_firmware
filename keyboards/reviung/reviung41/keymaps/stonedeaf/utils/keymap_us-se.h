
#pragma once


//#define MY_US_LAYOUT
//#define MY_SE_LAYOUT


#ifndef MY_SE_LAYOUT

#define K_MINUS         KC_MINUS
#define K_MINS          KC_MINS
// - and _ 
#define K_EQUAL         KC_EQUAL
#define K_EQL           KC_EQL
// = and + 
#define K_LEFT_BRACKET  KC_LEFT_BRACKET
#define K_LBRC          KC_LBRC
// [ and { 
#define K_RIGHT_BRACKET KC_RIGHT_BRACKET
#define K_RBRC          KC_RBRC
// ] and } 
#define K_BACKSLASH     KC_BACKSLASH
#define K_BSLS          KC_BSLS
// \ and | 
#define K_NONUS_HASH    KC_NONUS_HASH
#define K_NUHS          KC_NUHS
// Non-US # and ~ 
#define K_SEMICOLON     KC_SEMICOLON
#define K_SCLN          KC_SCLN
// ; and : 
#define K_QUOTE         KC_QUOTE
#define K_QUOT          KC_QUOT
// ' and " 
#define K_GRAVE         KC_GRAVE
#define K_GRV           KC_GRV
// ` and ~ 
#define K_COMMA         KC_COMMA
#define K_COMM          KC_COMM
// , and < 
#define K_DOT           KC_DOT
// . and > 
#define K_SLASH         KC_SLASH
#define K_SLSH          KC_SLSH
// / and ? 
#define K_NONUS_BACKSLASH   KC_NONUS_BACKSLASH
#define K_NUBS          KC_NUBS
// Non-US // \ and | 
            
#define K_TILDE         KC_TILDE
#define K_TILD          KC_TILD
// ~ 
#define K_EXCLAIM       KC_EXCLAIM
#define K_EXLM          KC_EXLM
// ! 
#define K_AT            KC_AT
// @ 
#define K_HASH          KC_HASH
// # 
#define K_DOLLAR        KC_DOLLAR
#define K_DLR           KC_DLR
// $ 
#define K_PERCENT       KC_PERCENT
#define K_PERC          KC_PERC
// % 
#define K_CIRCUMFLEX    KC_CIRCUMFLEX
#define K_CIRC          KC_CIRC
// ^ 
#define K_AMPERSAND     KC_AMPERSAND
#define K_AMPR          KC_AMPR
// & 
#define K_ASTERISK      KC_ASTERISK
#define K_ASTR          KC_ASTR
// * 
#define K_LEFT_PAREN    KC_LEFT_PAREN
#define K_LPRN          KC_LPRN
// ( 
#define K_RIGHT_PAREN   KC_RIGHT_PAREN
#define K_RPRN          KC_RPRN
// ) 
#define K_UNDERSCORE    KC_UNDERSCORE
#define K_UNDS          KC_UNDS
// _ 
#define K_PLUS          KC_PLUS
// + 
#define K_LEFT_CURLY_BRACE  KC_LEFT_CURLY_BRACE
#define K_LCBR          KC_LCBR
// { 
#define K_RIGHT_CURLY_BRACE KC_RIGHT_CURLY_BRACE
#define K_RCBR          KC_RCBR
// } 
#define K_PIPE          KC_PIPE
// | 
#define K_COLON         KC_COLON
#define K_COLN          KC_COLN
// : 
#define K_DOUBLE_QUOTE  KC_DOUBLE_QUOTE
#define K_DQUO          KC_DQUO
#define K_DQT           KC_DQT
// " 
#define K_LEFT_ANGLE_BRACKET    KC_LEFT_ANGLE_BRACKET
#define K_LABK          KC_LABK
#define K_LT            KC_LT
// < 
#define K_RIGHT_ANGLE_BRACKET   KC_RIGHT_ANGLE_BRACKET
#define K_RABK          KC_RABK
#define K_GT            KC_GT
// > 
#define K_QUESTION      KC_QUESTION
#define K_QUES          KC_QUES
// ? 

#define SW_AA   ALGR(KC_W)
#define SW_AE   ALGR(KC_Q)
#define SW_OE   ALGR(KC_P)



#else // MY_SE_LAYOUT



#include "keymap_swedish.h"

#define K_MINUS         SE_MINS
#define K_MINS          SE_MINS
// - and _ 
#define K_EQUAL         SE_EQL
#define K_EQL           SE_EQL
// = and + 
#define K_LEFT_BRACKET  SE_LBRC
#define K_LBRC          SE_LBRC
// [ and { 
#define K_RIGHT_BRACKET SE_RBRC
#define K_RBRC          SE_RBRC
// ] and } 
#define K_BACKSLASH     SE_BSLS
#define K_BSLS          SE_BSLS
// \ and | 
#define K_NONUS_HASH    SE_NUHS
#define K_NUHS          SE_NUHS
// Non-US # and ~ 
#define K_SEMICOLON     SE_SCLN
#define K_SCLN          SE_SCLN
// ; and : 
#define K_QUOTE         SE_QUOT
#define K_QUOT          SE_QUOT
// ' and " 
#define K_GRAVE         SE_GRV
#define K_GRV           SE_GRV
// ` and ~ 
#define K_COMMA         SE_COMM
#define K_COMM          SE_COMM
// , and < 
#define K_DOT           SE_DOT
// . and > 
#define K_SLASH         SE_SLSH
#define K_SLSH          SE_SLSH
// / and ? 
#define K_NONUS_BACKSLASH   SE_NUBS
#define K_NUBS          SE_NUBS
// Non-US // \ and | 
            
#define K_TILDE         SE_TILD
#define K_TILD          SE_TILD
// ~ 
#define K_EXCLAIM       SE_EXLM
#define K_EXLM          SE_EXLM
// ! 
#define K_AT            SE_AT
// @ 
#define K_HASH          SE_HASH
// # 
#define K_DOLLAR        SE_DLR
#define K_DLR           SE_DLR
// $ 
#define K_PERCENT       SE_PERC
#define K_PERC          SE_PERC
// % 
#define K_CIRCUMFLEX    SE_CIRC
#define K_CIRC          SE_CIRC
// ^ 
#define K_AMPERSAND     SE_AMPR
#define K_AMPR          SE_AMPR
// & 
#define K_ASTERISK      SE_ASTR
#define K_ASTR          SE_ASTR
// * 
#define K_LEFT_PAREN    SE_LPRN
#define K_LPRN          SE_LPRN
// ( 
#define K_RIGHT_PAREN   SE_RPRN
#define K_RPRN          SE_RPRN
// ) 
#define K_UNDERSCORE    SE_UNDS
#define K_UNDS          SE_UNDS
// _ 
#define K_PLUS          SE_PLUS
// + 
#define K_LEFT_CURLY_BRACE  SE_LCBR
#define K_LCBR          SE_LCBR
// { 
#define K_RIGHT_CURLY_BRACE SE_RCBR
#define K_RCBR          SE_RCBR
// } 
#define K_PIPE          SE_PIPE
// | 
#define K_COLON         SE_COLN
#define K_COLN          SE_COLN
// : 
#define K_DOUBLE_QUOTE  SE_DQUO
#define K_DQUO          SE_DQUO
#define K_DQT           SE_DQUO
// " 
#define K_LEFT_ANGLE_BRACKET    SE_LABK
#define K_LABK          SE_LABK
#define K_LT            SE_LABK
// < 
#define K_RIGHT_ANGLE_BRACKET   SE_RABK
#define K_RABK          SE_RABK
#define K_GT            SE_RABK
// > 
#define K_QUESTION      SE_QUES
#define K_QUES          SE_QUES
// ? 

#define SW_AA   KC_LBRC 
#define SW_AE   KC_QUOT 
#define SW_OE   KC_SCLN

#endif

#define K_LGUI  KC_LGUI
#define K_RGUI  KC_RGUI
#define K_LALT  KC_LALT
#define K_RALT  KC_RALT
#define K_LCTL  KC_LCTL
#define K_RCTL  KC_RCTL
#define K_LSFT  KC_LSFT
#define K_RSFT  KC_RSFT
