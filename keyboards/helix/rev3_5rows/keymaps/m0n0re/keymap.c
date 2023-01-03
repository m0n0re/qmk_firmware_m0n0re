/* Copyright 2020 yushakobo
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


// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _PAINT1 = 0,
  _PAINT2,
  _PAINT3,
  _SYSTEM,
  _BASE,
  _OPT,
  _FUNC,
  _SYM,
  _NUM
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  EISU = SAFE_RANGE,
  RGBRST,
  BURASHI_SIZE
};

// LAYER
#define L_P1 MO(_PAINT1)
#define L_P2 MO(_PAINT2)
#define L_P3 MO(_PAINT3)

#define TG_SYS TG(_SYSTEM)
#define TO_SYS TO(_SYSTEM)
#define TO_P1 TO(_PAINT1)
#define FROGGY TO(_BASE)

#define LT_OPT LT(_OPT,KC_SPC)

// OPERATION
#define UNDO LCMD(KC_Z)
#define REDO LCMD(KC_Y)
#define SAVE LCMD(KC_S)
#define COPY LCMD(KC_C)
#define CUT LCMD(KC_X)
#define PASTE LCMD(KC_V)
#define MIRR LCMD(KC_M) // 左右反転
#define MIRRUD LCMD(A(KC_M)) // 上下反転
#define MIRRRST LCMD(S(KC_M)) // 回転反転リセット
#define RELEASE LCMD(KC_D) // 選択範囲解除


// TOOL
#define KESIGOM KC_E    //消しゴム
#define PEN KC_P        //ペン
#define PREV_T KC_COMM  //前のサブツール
#define NEXT_T KC_DOT   //次のサブツール
#define B_SIZE BURASHI_SIZE   //ブラシ濃度(Ctrl+Alt+Drag)
#define SELECT KC_M // 範囲選択
#define AT_SELE KC_W // 自動選択
#define L_MOVE KC_K//レイヤー移動
#define KAITEN KC_R//回転

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_PAINT1] = LAYOUT( \
      XXXXXXX,  XXXXXXX, XXXXXXX, AT_SELE,  SELECT, RELEASE,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,     PEN, KESIGOM,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX,  MIRRRST, MIRRUD,     MIRR,    UNDO,    REDO,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX,  XXXXXXX, XXXXXXX,  KAITEN, KC_SPC,  B_SIZE,  L_MOVE,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
       PREV_T,   NEXT_T, XXXXXXX, XXXXXXX, XXXXXXX,   L_P3,  L_P2,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
      ), 

  [_PAINT2] = LAYOUT( \
      TG_SYS , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_DEL, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX,    SAVE, XXXXXXX, XXXXXXX,    COPY,   PASTE,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     CUT, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
      ),

  [_PAINT3] = LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
      ),

  [_SYSTEM] =  LAYOUT( \
    RESET,   TO_P1,   FROGGY,  _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
    RGBRST,  _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  ),

  // Froggy
  [_BASE] = LAYOUT( \
      LCTL(KC_Z),    KC_SCLN,       KC_LBRC,       KC_LPRN,   KC_LT,     KC_LCBR,                                _______,  _______,  _______,  _______,  _______,  _______, \
      KC_LANG1,      KC_P,          KC_K,          KC_R,      KC_A,      KC_F,                                   _______,  _______,  _______,  _______,  _______,  _______, \
      KC_BSPC,       KC_D,          KC_T,          KC_H,      KC_E,      KC_O,                                   _______,  _______,  _______,  _______,  _______,  _______, \
      OSM(MOD_LSFT), KC_Y,          KC_S,          KC_N,      KC_I,      KC_U,       KC_SPC, _______,  _______,  _______,  _______,  _______,  _______,  _______, \
      OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), MO(_SYM),  MO(_NUM),  LT_OPT,     KC_ENT, _______,  _______,  _______,  _______,  _______,  _______,  _______ \
  ),

  [_OPT] = LAYOUT( \
      KC_ESC,  KC_COLN,KC_RBRC, KC_RPRN,KC_GT,     KC_RCBR,                   _______,  _______,  _______,  _______,  _______,  _______, \
      KC_LANG2,KC_J,   KC_M,    KC_B,   KC_QUOT,   KC_TAB,                    _______,  _______,  _______,  _______,  _______,  _______, \
      KC_DOT,  KC_V,   KC_C,    KC_L,   KC_Z,      KC_Q,                      _______,  _______,  _______,  _______,  _______,  _______, \
      _______, KC_X,   KC_G,    KC_W,   KC_MINUS,  KC_DEL,  KC_ESC,  _______, _______,  _______,  _______,  _______,  _______,  _______, \
      _______, _______,_______, KC_COMM,_______,   _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______ \
      ),
    
  [_FUNC] = LAYOUT( \
      TO_SYS, XXXXXXX, _______, RESET,   XXXXXXX, XXXXXXX,                         _______,  _______,  _______,  _______,  _______,  _______, \
      XXXXXXX,XXXXXXX, KC_F7,   KC_F8,   KC_F9,   _______,                     _______,  _______,  _______,  _______,  _______,  _______, \
      XXXXXXX,XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F12,                      _______,  _______,  _______,  _______,  _______,  _______, \
      XXXXXXX,KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_F11,   _______,  _______, _______,  _______,  _______,  _______,  _______,  _______, \
      _______,_______, _______, _______, _______, _______,  _______,  _______, _______,  _______,  _______,  _______,  _______,  _______ \
      ),

  [_SYM] = LAYOUT( \
      KC_INS,  KC_GRV,  _______, KC_PGUP, KC_PGDN, KC_CIRC,                   _______,  _______,  _______,  _______,  _______,  _______, \
      _______, KC_BSLS, KC_HASH, KC_EQL,  KC_QUES, KC_PERC,                   _______,  _______,  _______,  _______,  _______,  _______, \
      _______, KC_DLR,  KC_UP,   KC_AT,   KC_EXLM, KC_PIPE,                   _______,  _______,  _______,  _______,  _______,  _______, \
      KC_CAPS, KC_LEFT, KC_DOWN, KC_RIGHT,KC_UNDS, KC_AMPR, _______, _______, _______,  _______,  _______,  _______,  _______,  _______, \
      _______, _______, KC_PSCR, _______, KC_TILD, _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______ \
      ),

  [_NUM] = LAYOUT( \
      _______,  _______, OSL(_FUNC), KC_HOME, KC_END,  _______,                          _______,  _______,  _______,  _______,  _______,  _______, \
      _______,  KC_ASTR, KC_P7,      KC_P8,   KC_P9,   KC_MINS,                          _______,  _______,  _______,  _______,  _______,  _______, \
      KC_PDOT,  KC_SLSH, KC_P4,      KC_P5,   KC_P6,   KC_PLUS,                          _______,  _______,  _______,  _______,  _______,  _______, \
      KC_NLCK,  KC_P0,   KC_P1,      KC_P2,   KC_P3,   LCTL(S(KC_F1)), _______, _______, _______,  _______,  _______,  _______,  _______,  _______, \
      _______,   _______, KC_PDOT,    KC_COMM, _______, _______,        _______, _______, _______,  _______,  _______,  _______,  _______,  _______ \
      )
};

// レイヤー同時押しの対応いらないのでコメントアウト
// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // iPadで使うのでCTLは全部CMDに置き換える
    // case KC_LCTL:
    //   if (record->event.pressed) {
    //     if (is_mac_mode()) {
    //       register_code(KC_LCMD);
    //     }else{
    //       return true;
    //     }
    //   } else {
    //     unregister_code(KC_LCMD);
    //   }
    //   return false;
    //   break;
    // ブラシサイズを切り替えるCtrl+Altキーの定義
    case BURASHI_SIZE:
      if (record->event.pressed) {
        register_code(KC_LCMD);
        register_code(KC_LALT);
      } else {
        unregister_code(KC_LCMD);
        unregister_code(KC_LALT);
      }
      return false;
      break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
      #endif
      break;
  }
  return true;
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
