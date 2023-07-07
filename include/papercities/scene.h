#ifndef _PC_SCENE_H_
#define _PC_SCENE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <SDL2/SDL.h>

// self referring
typedef struct PC_Scene PC_Scene;

typedef struct PC_Scene
{
    // double linked list
    PC_Scene *previous, *next;
    // render callback
    void (*render)(PC_Scene *, SDL_Renderer *);
    // event handling callback
    void (*event)(PC_Scene *, SDL_Event *);
    // is in focus?
    uint8_t focus;
} PC_Scene;

#ifdef __cplusplus
}
#endif

#endif // _PC_SCENE_H_