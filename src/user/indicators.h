#pragma once

#include "keyboard.h"
#include <stdint.h>
#include <stdbool.h>

void indicators_start();
void indicators_pre_update();
bool indicators_update_step(keyboard_state_t *keyboard, uint8_t current_step);
void indicators_post_update();

// RGB Control Functions
void rgb_cycle_mode();
void rgb_cycle_color();
void rgb_increase_brightness();
void rgb_decrease_brightness();
