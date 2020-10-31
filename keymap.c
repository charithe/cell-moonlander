#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_uk.h"  
#include "keymap_contributions.h"
#include "sendstring_uk.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_172_255_255,
  VIM_COMMAND_MODE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           TG(1),                                          KC_NONUS_HASH,  KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_PSCREEN,     
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_EQUAL,                                       KC_MINUS,       KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_NONUS_BSLASH,
    LCTL(KC_LSHIFT),KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_QUOTE,                                                                       KC_DELETE,      KC_H,           KC_J,           KC_K,           KC_L,           LT(2,KC_SCOLON),KC_ENTER,       
    KC_LSPO,        LCTL_T(KC_Z),   KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         RCTL_T(KC_SLASH),KC_RSPC,        
    LCA_T(KC_GRAVE),WEBUSB_PAIR,    KC_LALT,        KC_LEFT,        KC_RIGHT,       KC_ESCAPE,                                                                                                       VIM_COMMAND_MODE,KC_UP,          KC_DOWN,        KC_LBRACKET,    KC_RBRACKET,    KC_LEAD,          
    KC_SPACE,       KC_BSPACE,      KC_LGUI,                        MO(1),          KC_TAB,         KC_SPACE
  ),
  [1] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PGUP,        KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_F12,         
    KC_TRANSPARENT, KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,       KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_PGDOWN,      KC_4,           KC_5,           KC_6,           KC_KP_PLUS,     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,                                        KC_AMPR,        KC_1,           KC_2,           KC_3,           KC_BSLASH,      KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_COMMA,       KC_TRANSPARENT, KC_LCTRL,       HSV_172_255_255,RGB_MOD,                                                                                                        RGB_TOG,        KC_TRANSPARENT, KC_DOT,         KC_0,           KC_EQUAL,       KC_TRANSPARENT, 
    RGB_VAD,        RGB_VAI,        TOGGLE_LAYER_COLOR,                KC_TRANSPARENT, RGB_HUD,        RGB_HUI
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {105,255,255}, {169,120,255}, {14,255,255}, {205,255,255}, {14,255,255}, {87,35,243}, {87,35,243}, {87,35,243}, {205,255,255}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {205,255,255}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {154,255,255}, {87,35,243}, {87,35,243}, {169,120,255}, {249,228,255}, {87,35,243}, {105,255,255}, {87,35,243}, {87,35,243}, {85,203,158}, {205,255,255}, {154,255,255}, {87,35,243}, {87,35,243}, {87,35,243}, {205,255,255}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {87,35,243}, {249,228,255}, {169,120,255}, {169,120,255}, {146,224,255}, {85,203,158} },

    [1] = { {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {195,61,255}, {85,203,158}, {243,222,234}, {152,247,239}, {152,247,239}, {195,61,255}, {85,203,158}, {243,222,234}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {255,220,201}, {255,220,201}, {255,220,201}, {255,220,201}, {152,247,239}, {255,220,201}, {255,220,201}, {255,220,201}, {152,247,239}, {152,247,239}, {255,220,201}, {255,220,201}, {255,220,201}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239}, {152,247,239} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_172_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
      }
      return false;
    case VIM_COMMAND_MODE:
      if (record->event.pressed) {
          SEND_STRING(SS_TAP(X_ESC) ":");
      }
      return false;
  }
  return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // Vim write and quit
    SEQ_ONE_KEY(KC_W) {
        SEND_STRING(SS_TAP(X_ESC) ":wq\n");
    }

    // Vim unicode em-dash
    SEQ_ONE_KEY(KC_QUOTE) {
        SEND_STRING(SS_LCTL("v") "u2014");
    }

    // Gnome unicode em-dash
    SEQ_ONE_KEY(KC_MINUS) {
      SEND_STRING(SS_LCTL(SS_LSFT("u")) "2014\n");
    }
  }
}
