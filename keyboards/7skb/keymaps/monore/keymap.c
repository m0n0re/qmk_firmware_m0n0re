#include QMK_KEYBOARD_H
#include "keymap_jp.h"

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

static bool SFT_PRESSED = false;
static bool LLEFT_ON = false;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _JP_QWETRY,
    _GAME,
    _FN,
    _ADJUST,
    _KAKKO,
    _JP_KAKKO,
    _LLEFT,
    _JP_LLEFT,
    _LRIGHT,
    _JP_LRIGHT
};

enum custom_keycodes {
    RGB_RST = SAFE_RANGE,
    KEY_RST,
    JP_SPL
};


#define KC_SPL LT(_LLEFT,KC_SPC)
#define KC_SPR LT(_LRIGHT,KC_SPC)
#define JP_SPR LT(_JP_LRIGHT,KC_SPC)
// #define JP_SPL LT(_JP_LLEFT,KC_SPC)
#define KC_KK MO(_KAKKO)
#define JP_KK MO(_JP_KAKKO)
#define KC_JP MO(_JP_QWETRY)
#define CHL_JP DF(_JP_QWETRY)
#define CHL_US DF(_QWERTY)
#define CHL_GM DF(_GAME)

#define TABCTL LCTL_T(KC_TAB)
#define ENTCTL LCTL_T(KC_ENT)
#define COPY LCTL(KC_C)
#define CUT LCTL(KC_X)
#define PASTE LCTL(KC_V)
#define ANDO LCTL(KC_Z)
#define REDO LCTL(KC_Y)
#define SAVE LCTL(KC_S)
#define EIJI KC_F13
#define KANA KC_F14

#define  JP_LAYOUT 0
#define  US_LAYOUT 1
#define  GAME_LAYOUT 2
int LAYOUT_STATUS = US_LAYOUT;

#define EN2JP_AT KC_LBRC // JP @
#define EN2JP_CIRC KC_EQL // JP ^
#define EN2JP_AMPR KC_6 // JP &
#define EN2JP_ASTR KC_QUOT // JP *
#define EN2JP_LPRN  KC_8 // JP 
#define EN2JP_RPRN  KC_9 // JP )
#define EN2JP_LBRC KC_RBRC // JP [
#define EN2JP_RBRC KC_NUHS // JP ]
#define EN2JP_LCBR KC_RBRC // JP {
#define EN2JP_RCBR KC_NUHS // JP }
#define EN2JP_COLN KC_QUOT // JP :
#define EN2JP_QUOT KC_7 // JP '
#define EN2JP_PLUS KC_SCLN // JP +
#define EN2JP_EQL KC_MINS // JP =
#define EN2JP_UNDS KC_INT1 // JP _
#define EN2JP_MINS KC_MINS // JP -
#define EN2JP_PIPE KC_INT3 // JP yen
#define EN2JP_BSLH KC_INT1 // JP (backslash)
#define EN2JP_DQO KC_2 // JP "
#define EN2JP_GRV KC_LBRC // JP `
#define EN2JP_TILD KC_EQL   // JP ~


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSLS,KC_GRAVE,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
     KC_LCTRL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LSFT, MO(_FN),
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               KC_LGUI, KC_LALT,   KC_KK,  KC_SPL,               KC_SPC,  KC_SPR,          KC_RGUI, MO(_FN)
          //`---------------------------------------------|   |--------------------------------------------'
  ),
  [_JP_QWETRY] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      _______,    JP_1,    JP_2,    JP_3,    JP_4,    JP_5,        JP_6,    JP_7,    JP_8,    JP_9,    JP_0, JP_MINS,  JP_EQL, JP_BSLS,  JP_GRV,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______,    JP_Q,    JP_W,    JP_E,    JP_R,    JP_T,        JP_Y,    JP_U,    JP_I,    JP_O,    JP_P, JP_LBRC, JP_RBRC,KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      _______,    JP_A,    JP_S,    JP_D,    JP_F,    JP_G,        JP_H,    JP_J,    JP_K,    JP_L, JP_SCLN, JP_QUOT, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______,    JP_Z,    JP_X,    JP_C,    JP_V,    JP_B,        JP_N,    JP_M, JP_COMM,  JP_DOT, JP_SLSH, _______, _______,
  //|--------+--------+--------+-------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, _______,   JP_KK,  JP_SPL,              _______, JP_SPR,          _______, _______
          //`---------------------------------------------|   |--------------------------------------------'
  ),
[_GAME] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      _______,    JP_1,    JP_2,    JP_3,    JP_4,    JP_5,        JP_6,    JP_7,    JP_8,    JP_9,    JP_0, JP_MINS,  JP_EQL, JP_BSLS,  JP_GRV,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______,    JP_Q,    JP_W,    JP_E,    JP_R,    JP_T,        JP_Y,    JP_U,    JP_I,    JP_O,    JP_P, JP_LBRC, JP_RBRC,KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      _______,    JP_A,    JP_S,    JP_D,    JP_F,    JP_G,        JP_H,    JP_J,    JP_K,    JP_L, JP_SCLN, JP_QUOT, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______,    JP_Z,    JP_X,    JP_C,    JP_V,    JP_B,        JP_N,    JP_M, JP_COMM,  JP_DOT, JP_SLSH, _______, _______,
  //|--------+--------+--------+-------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, _______,   JP_KK,  KC_SPC,              _______, JP_SPR,          _______, _______
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_FN] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
  TG(_ADJUST),   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______, KC_PSCR, KC_SLCK,KC_PAUSE,   KC_UP, _______, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______, KC_HOME, KC_PGUP, KC_LEFT,KC_RIGHT, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______,  KC_END, KC_PGDN, KC_DOWN, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               KC_LGUI, _______, _______,    EIJI,                 KANA,    KANA,          KC_STOP, KEY_RST
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_ADJUST] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
  TG(_ADJUST), _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,   RESET,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     RGB_RST, _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     RGB_VAD, RGB_VAI, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
                CHL_JP, _______, _______,  CHL_GM,               CHL_US, _______,          KC_STOP, _______
          //`---------------------------------------------|   |--------------------------------------------'
  ),
  [_KAKKO] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      _______, _______, _______, _______, _______, _______,     _______, KC_LT  , KC_GT  , _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, KC_LPRN, KC_RPRN, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, KC_LCBR, KC_RCBR, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______,              _______, _______  ,        _______, _______
          //`---------------------------------------------|   |--------------------------------------------'
  ),
  [_JP_KAKKO] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      _______, _______, _______, _______, _______, _______,     _______, KC_LT  , KC_GT  , _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, JP_LPRN, JP_RPRN, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, JP_LBRC, JP_RBRC, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, JP_LCBR, JP_RCBR, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______,              _______, _______  ,        _______, _______
          //`---------------------------------------------|   |--------------------------------------------'
  ),
  [_LLEFT] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______, _______, KC_DEL ,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      _______, ANDO   , REDO   , _______, COPY   , PASTE  ,     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_PLUS, KC_MINS, KC_EQL,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, SAVE   , _______, _______, CUT    , _______,     KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_ASTR, KC_SLSH,  KC_UNDS,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______,              KANA, KC_DEL,          _______, _______
          //`---------------------------------------------|   |--------------------------------------------'
  ),
  [_JP_LLEFT] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______, _______,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      _______, ANDO   , REDO   , _______, COPY   , PASTE  ,     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, JP_PLUS, JP_MINS, JP_EQL,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, SAVE   , _______, _______, CUT    , _______,     KC_HOME, KC_PGDN, KC_PGUP,  KC_END, JP_ASTR, JP_SLSH, JP_UNDS,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______,              _______, KC_DEL ,          _______, _______
          //`---------------------------------------------|   |--------------------------------------------'
  ),
  [_LRIGHT] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, KC_BSPC,              _______, _______,          _______, _______
          //`---------------------------------------------|   |--------------------------------------------'
  ),
  [_JP_LRIGHT] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      _______, JP_EXLM,   JP_AT, JP_HASH,  JP_DLR, JP_PERC,     JP_CIRC, JP_AMPR, JP_ASTR, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, _______, EIJI, KC_BSPC,              _______, _______,          _______, _______
          //`---------------------------------------------|   |--------------------------------------------'
  ),
};



//A description for expressing the layer position in LED mode.
layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    switch (get_highest_layer(state)) {
    case _FN:
        //gblight_sethsv_at(HSV_BLUE, 0);
        rgblight_sethsv_at( 50, 50, 50 , 0);
        break;
    case _ADJUST:
        rgblight_sethsv_at(HSV_RED , 0);
        break;
    case _GAME:
        rgblight_sethsv_at(HSV_RED , 0);
        break;
    default: //  for any other layers, or the default layer
        LAYOUT_STATUS == US_LAYOUT ? rgblight_sethsv_at( 0, 0, 0, 0) : rgblight_sethsv_at(HSV_BLUE, 0);
        break;
    }
    rgblight_set_effect_range( 1, 5);
#endif
return state;
}

void UnSftKeyDown(uint16_t keycode){
    unregister_code(KC_LSFT);
    register_code(keycode);
    register_code(KC_LSFT);
}

void UnSftKeyUp(uint16_t keycode){
    unregister_code(KC_LSFT);
    unregister_code(keycode);
    register_code(KC_LSFT);
}

void SftKeyDown(uint16_t keycode){
    register_code(KC_LSFT);
    register_code(keycode);
    unregister_code(KC_LSFT);
}

void SftKeyUp(uint16_t keycode){
    register_code(KC_LSFT);
    unregister_code(keycode);
    unregister_code(KC_LSFT);
}

void send_keycode_down(uint16_t keycode){
    switch(keycode){
        case JP_2: SFT_PRESSED ? UnSftKeyDown(EN2JP_AT) : register_code(JP_2); break;
        case JP_6: SFT_PRESSED ? UnSftKeyDown(EN2JP_CIRC) : register_code(JP_6); break;
        case JP_7: SFT_PRESSED ? register_code(EN2JP_AMPR) : register_code(JP_7); break;
        case JP_8: SFT_PRESSED ? register_code(EN2JP_ASTR) : register_code(JP_8); break;
        case JP_9: SFT_PRESSED ? register_code(EN2JP_LPRN) : register_code(JP_9); break;
        case JP_0: SFT_PRESSED ? register_code(EN2JP_RPRN) : register_code(JP_0); break;
        case JP_AT:SFT_PRESSED ? UnSftKeyDown(EN2JP_AT) : register_code(EN2JP_AT); break;
        case JP_MINS:SFT_PRESSED ? register_code(EN2JP_UNDS) : register_code(EN2JP_MINS);  break;
        case JP_EQL:SFT_PRESSED ? register_code(EN2JP_PLUS) : SftKeyDown(EN2JP_EQL); break;
        case JP_BSLS:SFT_PRESSED ? register_code(EN2JP_PIPE) : register_code(EN2JP_BSLH); break;
        case JP_LBRC: SFT_PRESSED ? register_code(EN2JP_LCBR) : register_code(EN2JP_LBRC); break;
        case JP_RBRC: SFT_PRESSED ? register_code(EN2JP_RCBR) : register_code(EN2JP_RBRC); break;
        case JP_SCLN: SFT_PRESSED ? UnSftKeyDown(EN2JP_COLN) : register_code(JP_SCLN); break;
        case JP_QUOT: SFT_PRESSED ? register_code(EN2JP_DQO) : SftKeyDown(EN2JP_QUOT); break;
        case JP_LPRN: SFT_PRESSED ? register_code(EN2JP_LPRN) : SftKeyDown(EN2JP_LPRN); break;
        case JP_RPRN: SFT_PRESSED ? register_code(EN2JP_RPRN) : SftKeyDown(EN2JP_RPRN); break;
        case JP_LCBR: SFT_PRESSED ? register_code(EN2JP_LCBR) : SftKeyDown(EN2JP_LCBR); break;
        case JP_RCBR: SFT_PRESSED ? register_code(EN2JP_RCBR) : SftKeyDown(EN2JP_RCBR); break;
        case JP_PLUS: SFT_PRESSED ? register_code(EN2JP_PLUS) : SftKeyDown(EN2JP_PLUS); break;
        case JP_ASTR: SFT_PRESSED ? register_code(EN2JP_ASTR) : SftKeyDown(EN2JP_ASTR); break;
        case JP_UNDS: SFT_PRESSED ? register_code(EN2JP_UNDS) : SftKeyDown(EN2JP_UNDS); break;
        case JP_CIRC: SFT_PRESSED ? UnSftKeyDown(EN2JP_CIRC) : register_code(EN2JP_CIRC); break;
        case JP_AMPR: SFT_PRESSED ? register_code(EN2JP_AMPR) : SftKeyDown(EN2JP_AMPR); break;
        case JP_GRV:SFT_PRESSED ? register_code(EN2JP_TILD) : SftKeyDown(EN2JP_GRV); break;
    }
}

void send_keycode_up(uint16_t keycode){
    switch(keycode){
        case JP_2: SFT_PRESSED ? UnSftKeyUp(EN2JP_AT) : unregister_code(JP_2); break;
        case JP_6: SFT_PRESSED ? UnSftKeyUp(EN2JP_CIRC) : unregister_code(JP_6); break;
        case JP_7: SFT_PRESSED ? unregister_code(EN2JP_AMPR) : unregister_code(JP_7); break;
        case JP_8: SFT_PRESSED ? unregister_code(EN2JP_ASTR) : unregister_code(JP_8); break;
        case JP_9: SFT_PRESSED ? unregister_code(EN2JP_LPRN) : unregister_code(JP_9); break;
        case JP_0: SFT_PRESSED ? unregister_code(EN2JP_RPRN) : unregister_code(JP_0); break;
        case JP_AT:SFT_PRESSED ? UnSftKeyUp(EN2JP_AT) : unregister_code(EN2JP_AT); break;
        case JP_MINS:SFT_PRESSED ? unregister_code(EN2JP_UNDS) : unregister_code(EN2JP_MINS); break ;
        case JP_EQL:SFT_PRESSED ? unregister_code(EN2JP_PLUS) : SftKeyUp(EN2JP_EQL); break;
        case JP_BSLS:SFT_PRESSED ? unregister_code(EN2JP_PIPE) : unregister_code(EN2JP_BSLH); break;
        case JP_LBRC: SFT_PRESSED ? unregister_code(EN2JP_LCBR) : unregister_code(EN2JP_LBRC); break;
        case JP_RBRC: SFT_PRESSED ? unregister_code(EN2JP_RCBR) : unregister_code(EN2JP_RBRC); break;
        case JP_SCLN: SFT_PRESSED ? UnSftKeyUp(EN2JP_COLN) : unregister_code(JP_SCLN); break;
        case JP_QUOT: SFT_PRESSED ? unregister_code(EN2JP_DQO) : SftKeyUp(EN2JP_QUOT); break;
        case JP_LPRN: SFT_PRESSED ? unregister_code(EN2JP_LPRN) : SftKeyUp(EN2JP_LPRN); break;
        case JP_RPRN: SFT_PRESSED ? unregister_code(EN2JP_RPRN) : SftKeyUp(EN2JP_RPRN); break;
        case JP_LCBR: SFT_PRESSED ? unregister_code(EN2JP_LCBR) : SftKeyUp(EN2JP_LCBR); break;
        case JP_RCBR: SFT_PRESSED ? unregister_code(EN2JP_RCBR) : SftKeyUp(EN2JP_RCBR); break;
        case JP_PLUS: SFT_PRESSED ? unregister_code(EN2JP_PLUS) : SftKeyUp(EN2JP_PLUS); break;
        case JP_ASTR: SFT_PRESSED ? unregister_code(EN2JP_ASTR) : SftKeyUp(EN2JP_ASTR); break;
        case JP_UNDS: SFT_PRESSED ? unregister_code(EN2JP_UNDS) : SftKeyUp(EN2JP_UNDS); break;
        case JP_CIRC: SFT_PRESSED ? UnSftKeyUp(EN2JP_CIRC) : unregister_code(EN2JP_CIRC); break;
        case JP_AMPR: SFT_PRESSED ? unregister_code(EN2JP_AMPR) : SftKeyUp(EN2JP_AMPR); break;
        case JP_GRV:SFT_PRESSED ? unregister_code(EN2JP_TILD) : SftKeyUp(EN2JP_GRV); break;
    }
}

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool result = false;

    if(LAYOUT_STATUS == JP_LAYOUT){
        switch (keycode) {
        case JP_2: case JP_6:  case JP_7: case JP_8: case JP_9: case JP_0:
        case JP_LBRC: case JP_RBRC:
        case JP_LPRN: case JP_RPRN:
        case JP_LCBR: case JP_RCBR:
        case JP_AT: case JP_MINS: case JP_EQL: case JP_BSLS:
        case JP_SCLN: case JP_QUOT:
        case JP_PLUS: case JP_ASTR:
        case JP_UNDS: case JP_CIRC: case JP_AMPR: case JP_GRV:
            record->event.pressed ? send_keycode_down(keycode) : send_keycode_up(keycode); 
            if(LLEFT_ON){
                LLEFT_ON = false;
            } 
            return result;
            break;
        }
    }

  switch (keycode) {
    case KEY_RST:
        if (record->event.pressed) {
            clear_keyboard();
        }
    // JP mode key
    case CHL_JP:
        if (record->event.pressed) {
            LAYOUT_STATUS = JP_LAYOUT;
            // layer_state_set(_JP_QWETRY);
        }
        result= true;
        break;
    // US mode key
    case CHL_US:
        if (record->event.pressed) {
            LAYOUT_STATUS = US_LAYOUT;
            // layer_state_set(_QWERTY);
        } 
        result = true;
        break;
    case CHL_GM:
        if (record->event.pressed) {
            LAYOUT_STATUS = GAME_LAYOUT;
        } 
        result = true;
        break;
    // left Shift
    case KC_LSFT:
        if (record->event.pressed) {
            SFT_PRESSED = true ;
            register_code(KC_LSFT);
        } else {
            SFT_PRESSED = false ;
            unregister_code(KC_LSFT);
        }
        break;
    
    case JP_SPL:
        if(record->event.pressed){
            layer_on(_JP_LLEFT);
            LLEFT_ON = true;
        } else {
            layer_off(_JP_LLEFT);
            if(LLEFT_ON){
                LLEFT_ON = false;
                SEND_STRING(SS_TAP(X_SPC));
            }
        }
        break;
    #ifdef RGBLIGHT_ENABLE
      case RGB_MOD:
          if (record->event.pressed) {
            rgblight_mode(RGB_current_mode);
            rgblight_step();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
      case RGB_RST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
    #endif
    default:
        if(LLEFT_ON){
            LLEFT_ON = false;
        } 
        result = true;
        break;
    }

  return result;
}