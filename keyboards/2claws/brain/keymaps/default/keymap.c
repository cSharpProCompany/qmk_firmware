/* Copyright 2018 Jack Humbert
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

#define _BASE 0
#define _FN1 1

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _COLEMAK,
    _FN,
    _ADJ
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = LAYOUT(
		KC_7, KC_8, KC_9, KC_Q, KC_W, KC_E, \
		KC_4, KC_5, KC_6, KC_A, KC_S, KC_D, \
		KC_1, KC_2, KC_3, KC_Z, KC_X, KC_C, \
		MO(_FN1), KC_0, KC_ENT, KC_I, KC_O, KC_P \
		),
  
	[_FN1] = LAYOUT(
		KC_TRNS, KC_HOME, KC_PGUP, _______, _______, _______, \
		KC_TRNS, KC_END, KC_PGDN, _______, _______, _______, \
		KC_TRNS, KC_TRNS, KC_TRNS, _______, _______, _______, \
		KC_TRNS, KC_TRNS, KC_DOT, _______, _______, _______ \
	),
};

// настройка порта управления светодиодом D1
void D1_init_ports(void) {
	DDRD |= (1<<7); // OUT
	//led on
	PORTD &= ~(1<<7); // 0 = led on
}

void D1_on(void) {
	PORTD &= ~(1<<7); // 0 = led on
}

void D1_off(void) {
	PORTD |=(1<<7); 
}


// настройка порта управления EXT_LED
void ext_led_off(void) {
	DDRD |= (1<<6); // OUT
	//led on
	PORTD &= ~(1<<6); // 0 = xt_led_off
}

void ext_led_on(void) {
	DDRD |= (1<<6); // OUT
	//led on
	PORTD |= (1<<6); // 1 = xt_led_on
}

// настройка порта управления SEL
void sel_to_port1(void) {
	DDRD |= (1<<5); // OUT
	//led on
	PORTD &= ~(1<<5); // 0 = на LED1_IN
}

void sel_to_port2(void) {
	DDRD |= (1<<5); // OUT
	//led on
	PORTD |= (1<<5); // 1 = на LED2_IN
}


uint16_t d1_timer = 0;        // таймер "штуки"

// мигает светикоом с заданsv тактом (в милисекундах)
void D1_blink(uint16_t takt) {
static bool is_d1 = false;

    if (timer_elapsed(d1_timer) > takt) {
		d1_timer = timer_read();
		if (is_d1) {
			is_d1 = false;
			D1_off();
		}
		else {
			is_d1 = true;
			D1_on();
		}

    } 
}


// в самом начале инициалицации
void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

    D1_init_ports();
	ext_led_on();
	sel_to_port1();

  // Set our LED pins as output
//  setPinOutput(B0);
//  setPinOutput(B1);
//  setPinOutput(B2);
//  setPinOutput(B3);
//  setPinOutput(B4);
}

void matrix_init_kb(void) {
    // put your keyboard start-up code here
    // runs once when the firmware starts up
	    rgblight_enable_noeeprom();
//	oled_init(OLED_ROTATION_0);

//    D1_init_ports();
//    matrix_init_user();
//    rgblight_enable_noeeprom();
//	motor_init_ports();
//	hvb_init_local();
//	hvb_init_extern();
//    rgblight_mode_noeeprom(RGBLIGHT_MODE_RGB_TEST);
//rgblight_setrgb(0x00, 0x00, 0xFF);
//	rgblight_mode_noeeprom(3);
/*	_delay_ms(1000);
	D1_off();
	_delay_ms(1000);
	D1_on();
	_delay_ms(1000);
	D1_off();
	_delay_ms(1000);
	D1_on();
	*/
}

// для проверки rgb led
void rgb_chek(void) {
static uint8_t state = 1;
//dprintf("%d string\n", state);
 switch (state) {
    case 1:	
		rgblight_setrgb(0x00, 0x00, 0x00);
      break;
	case 2: 
		rgblight_setrgb(0x00, 0x00, 0x1F);
      break;
	case 3: 
		rgblight_setrgb(0x00, 0x1F, 0x00);
      break;
	case 4: 
		rgblight_setrgb(0x1F, 0x00, 0x00);
      break;	  
	case 5: 
		// РАЗМЕЩЕНО последним чтобы была возможность успеть нажать ресет до того как выполнение кода сюда доберется
		// ВКЛЮЧЕНИЕ ВСЕХ СВЕТОДИОДОВ НА (0xFF, 0xFF, 0xFF); ПРИВОДИТ К ПРОСАДКЕ НАПРЯЖЕНИЯ ПИТАНИЯ И ЗАВИСАНИЮ
		rgblight_setrgb(0x1F, 0x1F, 0x1F);
      break;

	default:
		state = 0;
	  break;
 }
 state++;
	  
}

// SSD1306 OLED driver logic
#ifdef OLED_DRIVER_ENABLE

static void render_logo(void) {
  static const char PROGMEM rgbkb_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(rgbkb_logo, false);
}

static void render_status(void) {
  // Render to mode icon
  static const char PROGMEM mode_logo[4][4] = {
    {0x95,0x96,0},
    {0xb5,0xb6,0},
    {0x97,0x98,0},
    {0xb7,0xb8,0} };

  if (keymap_config.swap_lalt_lgui != false) {
    oled_write_ln_P(mode_logo[0], false);
    oled_write_ln_P(mode_logo[1], false);
  } else {
    oled_write_ln_P(mode_logo[2], false);
    oled_write_ln_P(mode_logo[3], false);
  }

  // Define layers here, Have not worked out how to have text displayed for each layer. Copy down the number you see and add a case for it below
  oled_write_P(PSTR("Layer: "), false);
  switch (biton32(layer_state)) {
    case _QWERTY:
      oled_write_ln_P(PSTR("QWERTY"), false);
      break;
    case _COLEMAK:
      oled_write_ln_P(PSTR("Colemak"), false);
      break;
    case _FN:
      oled_write_ln_P(PSTR("Function"), false);
      break;
    case _ADJ:
      oled_write_ln_P(PSTR("Adjust"), false);
      break;
    default:
      oled_write_ln_P(PSTR("Undefined"), false);
  }

  // Host Keyboard LED Status
  uint8_t led_usb_state = host_keyboard_leds();
  oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
  oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
  oled_write_ln_P(led_usb_state & (1<<USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
	
//	D1_blink(1000);
//  if (is_keyboard_master()) {
	if (false) {
    render_status();
  } else {
	D1_blink(1000);
    render_logo();
//    oled_scroll_left();
  }
}

#endif

uint16_t test_timer =0;

// эта функция вызывается в главном цикле
void matrix_scan_user(void) {     //# The very important timer. 

//D1_blink(300);
    if (timer_elapsed(test_timer) > 50) {
		test_timer = timer_read();
		
		rgb_chek();
//		motor_chek();
    }
 }
 
/* 
 void matrix_scan_kb(void) {
    // put your looping keyboard code here
    // runs every cycle (a lot)

    matrix_scan_user();
}
*/
