#pragma once

#include <stdint.h>
#include QMK_KEYBOARD_H
#include "quantum.h"
#include <stdbool.h>
#include "keymap_french.h"

enum layer_names {
    _BASE,
    _SYM,
    _NUM,
    _NAV,
};

// Tap Dance declarations
enum { TD_U, TD_A };

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_split_3x5_2('L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'L', 'L', 'R', 'R');

const uint16_t PROGMEM combo_cced[] = {FR_C, FR_V, COMBO_END};
const uint16_t PROGMEM combo_esc[]  = {LGUI_T(FR_Q), TD(TD_A), COMBO_END};
const uint16_t PROGMEM combo_eacu[] = {LCTL_T(FR_D), FR_E, COMBO_END};
const uint16_t PROGMEM combo_egrv[] = {LSFT_T(FR_F), FR_R, COMBO_END};
const uint16_t PROGMEM combo_euro[] = {FR_T, FR_G, COMBO_END};
const uint16_t PROGMEM combo_fj[]   = {LSFT_T(FR_F), LSFT_T(FR_J), COMBO_END};

combo_t key_combos[] = {COMBO(combo_cced, FR_CCED), COMBO(combo_esc, KC_ESCAPE), COMBO(combo_eacu, FR_EACU), COMBO(combo_egrv, FR_EGRV), COMBO(combo_fj, QK_CAPS_WORD_TOGGLE), COMBO(combo_euro, FR_EURO)};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for u, twice for ù
    [TD_U] = ACTION_TAP_DANCE_DOUBLE(KC_U, FR_UGRV),
    // Tap once for a, twice for à
    [TD_A] = ACTION_TAP_DANCE_DOUBLE(FR_A, FR_AGRV),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[_BASE] = LAYOUT_split_3x5_2(TD(TD_A), FR_Z, FR_E, FR_R, FR_T, FR_Y, TD(TD_U), FR_I, FR_O, FR_P, LGUI_T(FR_Q), LALT_T(FR_S), LCTL_T(FR_D), LSFT_T(FR_F), FR_G, FR_H, LSFT_T(FR_J), LCTL_T(FR_K), LALT_T(FR_L), LGUI_T(FR_M), FR_W, FR_X, FR_C, FR_V, FR_B, FR_N, FR_COMM, FR_SCLN, FR_COLN, FR_EXLM, LSFT_T(KC_BACKSPACE), LT(3, KC_TAB), LT(2, KC_ENTER), LT(1, KC_SPACE)),
                                                              [_SYM]  = LAYOUT_split_3x5_2(FR_AMPR, FR_CIRC, FR_LCBR, FR_RCBR, FR_PIPE, KC_GRAVE, FR_GRV, FR_UNDS, FR_AT, FR_ASTR, FR_EQL, FR_DLR, FR_LPRN, FR_RPRN, FR_LABK, FR_RABK, FR_DQUO, FR_QUOT, KC_NO, FR_PLUS, FR_HASH, FR_PERC, FR_LBRC, FR_RBRC, FR_TILD, KC_NO, KC_NO, KC_NO, FR_BSLS, FR_MINS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
                                                              [_NUM]  = LAYOUT_split_3x5_2(FR_1, FR_2, FR_3, FR_4, FR_5, FR_6, FR_7, FR_8, FR_9, FR_0, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NUM_LOCK, KC_NO, KC_NO, KC_NO, KC_NO, KC_CAPS_LOCK, FR_DIAE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LSFT(KC_COMMA), KC_DOT, KC_KP_EQUAL, KC_BACKSPACE, KC_NO, KC_NO, KC_NO),
                                                              [_NAV]  = LAYOUT_split_3x5_2(OSM(MOD_LSFT | MOD_LGUI), OSM(MOD_LSFT | MOD_LALT), OSM(MOD_LCTL | MOD_LSFT), OSM(MOD_LCTL | MOD_LGUI), KC_BRID, KC_BRIU, KC_PGDN, KC_PGUP, KC_PRINT_SCREEN, KC_F12, OSM(MOD_LGUI), OSM(MOD_LCTL | MOD_LALT), OSM(MOD_MEH), OSM(MOD_HYPR), KC_VOLU, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_NO, KC_MUTE, KC_CUT, KC_COPY, KC_PSTE, KC_VOLD, KC_WH_R, KC_WH_U, KC_WH_D, KC_WH_L, KC_NO, KC_BTN3, KC_BTN4, KC_BTN1, KC_BTN2)};
