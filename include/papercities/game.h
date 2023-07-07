#ifndef _PC_GAME_H_
#define _PC_GAME_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <papercities/scene.h>

// !! color mappings (defined in game.c) !!
// background
extern uint8_t background_r, background_g, background_b;

// !! global state variables (defined in game.c) !!
// window size
extern int window_w, window_h;
// mouse movement
extern int mouse_x, mouse_y;
// scene order
extern PC_Scene *scenes;

#ifdef __cplusplus
}
#endif

#endif // _PC_GAME_H_