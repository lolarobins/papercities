#include <papercities/menu.h>

// rectangle shortening to a single line in calls
static SDL_Rect *get_rect(SDL_Rect *rect, int x, int y, int w, int h)
{
    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;
    return rect;
}

// menu render call
static void menu_render(PC_Scene *scene, SDL_Renderer *renderer)
{
    // ____________
    // |    pc    |
    // |   ----   |
    // |   ----   |
    // ------------

    SDL_Rect rect;
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, get_rect(&rect, 5, 5, window_w - 10, window_h - 10));
}

// menu 
static void menu_event(PC_Scene *scene, SDL_Event *event)
{
    switch (event->type)
    {
        case SDL_MOUSEBUTTONDOWN:
    }
}

// menu scene struct
PC_Scene menu_scene = {NULL, NULL, &menu_render, &menu_event, 1};
