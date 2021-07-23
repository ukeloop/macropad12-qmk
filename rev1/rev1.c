#include "rev1.h"

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {
    {
        {         NO_LED },
        {  1,  2,  3,  4 },
        {  5,  6,  7,  8 },
        {  9, 10, 11, 12 }
    },
    {
        {  85,  26 }, {  50,  26 }, {  16,  26 }, {  0,  26 },
        {  85,  13 }, {  50,  13 }, {  16,  13 }, {  0,  13 },
        {  85,  0 }, {  50,  0 }, {  16,  0 }, {  0,  0 }
    },
    {
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT
    }
};

void suspend_power_down_kb(void) {
#ifdef OLED_DRIVER_ENABLE
    oled_off();
#endif
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
#ifdef OLED_DRIVER_ENABLE
    oled_on();
#endif
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}

#endif
