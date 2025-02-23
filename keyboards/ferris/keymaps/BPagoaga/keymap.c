#pragma once

#include <stdint.h>
#include QMK_KEYBOARD_H
#include "quantum.h"
#include <stdbool.h>

enum layer_names {
    _BASE,
    _SYM,
    _NUM,
    _NAV,
};

enum custom_keycodes {
    // SMTD keycodes begin
    SMTD_KEYCODES_BEGIN = SAFE_RANGE,

    // left home row
    CKC_A,
    CKC_S,
    CKC_D,
    CKC_F,

    CKC_BSPC,
    CKC_TAB,

    // right home row
    CKC_J,
    CKC_K,
    CKC_L,
    CKC_M,

    CKC_ENTER,
    CKC_SPC,

    SMTD_KEYCODES_END,
    // SMTD keycodes end
};

// Tap Dance declarations
enum { TD_U, TD_A };

#include "sm_td.h"

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }
    // your code here

    return true;
};

// @TODO add new vertical combos
const uint16_t PROGMEM combo1[]  = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo2[]  = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo3[]  = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo4[]  = {LGUI_T(KC_A), LALT_T(KC_S), COMBO_END};
const uint16_t PROGMEM combo5[]  = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo6[]  = {LGUI_T(KC_A), TD(TD_A), COMBO_END};
const uint16_t PROGMEM combo7[]  = {LALT_T(KC_S), KC_W, COMBO_END};
const uint16_t PROGMEM combo8[]  = {LCTL_T(KC_D), KC_E, COMBO_END};
const uint16_t PROGMEM combo9[]  = {LSFT_T(KC_F), KC_R, COMBO_END};
const uint16_t PROGMEM combo10[] = {KC_G, KC_T, COMBO_END};
const uint16_t PROGMEM combo11[] = {KC_Z, LGUI_T(KC_A), COMBO_END};
const uint16_t PROGMEM combo12[] = {KC_X, LALT_T(KC_S), COMBO_END};
const uint16_t PROGMEM combo13[] = {KC_C, LCTL_T(KC_D), COMBO_END};
const uint16_t PROGMEM combo14[] = {KC_V, LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM combo15[] = {KC_B, KC_G, COMBO_END};
const uint16_t PROGMEM combo16[] = {KC_N, KC_H, COMBO_END};
const uint16_t PROGMEM combo17[] = {KC_M, LSFT_T(KC_J), COMBO_END};
const uint16_t PROGMEM combo18[] = {KC_COMMA, LCTL_T(KC_K), COMBO_END};
const uint16_t PROGMEM combo19[] = {KC_DOT, LALT_T(KC_L), COMBO_END};
const uint16_t PROGMEM combo20[] = {KC_SLASH, LGUI_T(KC_SEMICOLON), COMBO_END};
const uint16_t PROGMEM combofj[] = {LSFT_T(KC_F), LSFT_T(KC_J), COMBO_END};

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_MT(CKC_A, KC_A, KC_LEFT_GUI)
        SMTD_MT(CKC_S, KC_S, KC_LEFT_ALT)
        SMTD_MT(CKC_D, KC_D, KC_LEFT_CTRL)
        SMTD_MT(CKC_F, KC_F, KC_LSFT)

        SMTD_MT(CKC_BSPC, KC_BSPC, KC_LSFT)
        SMTD_MT(CKC_TAB, KC_TAB, KC_LSFT)

        SMTD_MT(CKC_ENTER, KC_ENTER, KC_LSFT)
        SMTD_MT(CKC_SPC, KC_SPC, KC_LSFT)

        SMTD_MT(CKC_J, KC_J, KC_LSFT)
        SMTD_MT(CKC_K, KC_K, KC_LEFT_CTRL)
        SMTD_MT(CKC_L, KC_L, KC_LEFT_ALT)
        SMTD_MT(CKC_M, KC_M, KC_LEFT_GUI)
    }
};
// macro for ê on combo 10 ?

combo_t key_combos[] = {COMBO(combo1, KC_0), COMBO(combo2, KC_2), COMBO(combo3, KC_7), COMBO(combo4, KC_ESCAPE), COMBO(combo5, KC_9), COMBO(combo6, KC_ESCAPE), COMBO(combo8, KC_2), COMBO(combo9, KC_7), COMBO(combo11, KC_KP_1), COMBO(combo12, KC_KP_2), COMBO(combo13, KC_KP_3), COMBO(combo14, KC_KP_4), COMBO(combo15, KC_KP_5), COMBO(combo16, KC_KP_6), COMBO(combo17, KC_KP_7), COMBO(combo18, KC_KP_8), COMBO(combo19, KC_KP_9), COMBO(combo20, KC_KP_0), COMBO(combofj, QK_CAPS_WORD_TOGGLE)};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for u, twice for ù
    [TD_U] = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_QUOTE),
    // Tap once for a, twice for à
    [TD_A] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_0),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[_BASE] = LAYOUT_split_3x5_2(TD(TD_A), KC_W, KC_E, KC_R, KC_T, KC_Y, TD(TD_U), KC_I, KC_O, KC_P, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G, KC_H, LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SEMICOLON), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, LSFT_T(KC_BACKSPACE), LT(3, KC_TAB), LT(2, KC_ENTER), LT(1, KC_SPACE)),
                                                              [_SYM]  = LAYOUT_split_3x5_2(KC_1, KC_LBRC, RALT(KC_4), RALT(KC_EQUAL), RALT(KC_6), KC_GRAVE, RALT(KC_7), KC_8, RALT(KC_0), KC_KP_ASTERISK, KC_EQUAL, KC_RBRC, KC_5, KC_MINUS, KC_NONUS_BACKSLASH, LSFT(KC_NONUS_BACKSLASH), KC_3, KC_4, KC_NO, KC_KP_PLUS, RALT(KC_3), LSFT(KC_QUOTE), RALT(KC_5), RALT(KC_MINUS), RALT(KC_2), KC_NO, KC_NO, KC_NO, RALT(KC_8), KC_KP_MINUS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
                                                              [_NUM]  = LAYOUT_split_3x5_2(KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, KC_0, KC_LBRC, KC_NO, KC_NO, KC_NO, KC_NUM_LOCK, KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS, KC_KP_PLUS, KC_CAPS_LOCK, LSFT(KC_LBRC), KC_NO, KC_NO, KC_NO, KC_NO, KC_M, LSFT(KC_COMMA), KC_DOT, KC_KP_EQUAL, KC_BACKSPACE, KC_Z, KC_LSFT, KC_Z),
                                                              [_NAV]  = LAYOUT_split_3x5_2(OSM(MOD_LSFT | MOD_LGUI), OSM(MOD_LSFT | MOD_LALT), OSM(MOD_LCTL | MOD_LSFT), OSM(MOD_LCTL | MOD_LGUI), KC_BRID, KC_BRIU, KC_PGDN, KC_PGUP, KC_PRINT_SCREEN, KC_F12, OSM(MOD_LGUI), OSM(MOD_LCTL | MOD_LALT), OSM(MOD_MEH), OSM(MOD_HYPR), KC_VOLU, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_NO, KC_MUTE, KC_CUT, KC_COPY, KC_PSTE, KC_VOLD, KC_WH_R, KC_WH_U, KC_WH_D, KC_WH_L, KC_NO, KC_BTN3, KC_BTN4, KC_BTN1, KC_BTN2)};
