#include "brainLed.h"

led_config_t g_led_config = { 
    {
  // Key Matrix to LED Index https://beta.docs.qmk.fm/features/feature_rgb_matrix
    { NO_LED },
    { 64, 63, 62, 61, 60, 59, NO_LED, NO_LED, NO_LED, NO_LED },
    { 58, 57, 56, 55, 54, 53, 52, 51, 50, 49 },
    { 48, 47, 46, 45, 44, 43, 42, 41, 40, 39 },
    { 38, 37, 36, 35, 34, 33, 32, 31, 30, 29 },
    { 28, 27, 26, 25, 24, 23, 22, 21, 20, 19 },
    { 18, 17, 16, 15, 14, 13, 12, 11, NO_LED, 10 },
\
    { NO_LED, NO_LED, NO_LED, NO_LED, 70, 69, 68, 67, 66, 65 },
    { 80, 79, 78, 77, 76, 75, 74, 73, 72, 71 },
    { 90, 89, 88, 87, 86, 85, 84, 83, 82, 81 },
    { 100, 99, 98, 97, 96, 95, 94, 93, 92, 91 },
    { 110, 109, 108, 107, 106, 105, 104, 103, 102, 101 },
    { 119, NO_LED, 118, 117, 116, 115, 114, 113, 112, 111 }
}, {
  // LED Index to Physical Position
    { 0,  1 }, { 0,  2 }, { 0,  3 }, { 0,  4 }, { 0,  5 }, { 0,  6 }, { 0,  0 }, { 0,  0 }, {  0,  0 }, {  0,  0 },
    { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, {  0,  0 }, {  0,  0 },
    { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, {  0,  0 }, {  0,  0 },
    { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, {  0,  0 }, {  0,  0 },
    { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, {  0,  0 }, {  0,  0 },
    { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, {  0,  0 }, {  0,  0 },
    { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, {  0,  0 }, {  0,  0 },
    { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, {  0,  0 }, {  0,  0 },
    { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, {  0,  0 }, {  0,  0 },
    { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, {  0,  0 }, {  0,  0 },
    { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, {  0,  0 }, {  0,  0 },
    { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, {  0,  0 }, {  0,  0 }
}, {
    // LED Index to Flag
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1
} };
