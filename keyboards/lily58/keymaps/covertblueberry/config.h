/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// https://precondition.github.io/home-row-mods
// https://docs.qmk.fm/#/tap_hold
// https://github.com/qmk/qmk_firmware/pull/9404/files
// https://cdn.discordapp.com/attachments/663573863480950808/757162393209012304/modtap.pdf

// default 200
#define TAPPING_TERM 200
// #define TAPPING_TERM_PER_KEY

// https://precondition.github.io/home-row-mods#ignore-mod-tap-interrupt
#define IGNORE_MOD_TAP_INTERRUPT

// https://precondition.github.io/home-row-mods#tapping-force-hold
// https://docs.qmk.fm/#/tap_hold?id=tapping-force-hold
#define TAPPING_FORCE_HOLD_PER_KEY

// Apply the modifier on keys that are tapped during a short hold of a modtap
// (lets tapping a letter while holding down dual-function mod (for less than tapping term)
// count as a mod+letter, rather than two letters)
// can also do PERMISSIVE_HOLD_PER_KEY to enable e.g. only for shift
// https://precondition.github.io/home-row-mods#permissive-hold
// #define PERMISSIVE_HOLD

// enables long hold and release of a dual-function mod to send the original key
// (likely to cause problems with home row mods)
// https://precondition.github.io/home-row-mods#retro-tapping
// https://docs.qmk.fm/#/tap_hold?id=retro-tapping
// #define RETRO_TAPPING

// #define TAPPING_FORCE_HOLD

// auto shift: hold a key longer to use shifted version
// https://docs.qmk.fm/#/feature_auto_shift

// retro shift: hold the mod-tap longer to get the shifted state
// https://github.com/manna-harbour/qmk_firmware/blob/retro-shift/docs/tap_hold.md#retro-shift
// https://precondition.github.io/home-row-mods#retro-shift
