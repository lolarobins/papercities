#include <papercities/menu.h>

// color definitions (variable by user)
uint8_t background_r = 246, background_g = 250, background_b = 235;

// window size
int window_w = 640, window_h = 480;

// mouse current position
int mouse_x, mouse_y;

// scene order
PC_Scene *scenes;

// global render call
void render(SDL_Renderer *renderer)
{
    // clear background
    SDL_SetRenderDrawColor(renderer, background_r = background_r, background_g, background_b, 255);
    SDL_RenderClear(renderer);

    // render calls to each scene
    if (scenes)
        for (PC_Scene *scene = scenes; scene; scene = scene->next)
            if (scene->render)
                scene->render(scene, renderer);

    // present frame
    SDL_RenderPresent(renderer);
}

// main func :3
int main()
{
    // initialize sdl2
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER);

    // window creation
    SDL_Window *window = SDL_CreateWindow("papercities", // window title
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, // x, y
                                          640, 480, // width, height
                                          SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE); // flags
    if (!window)
    {
        SDL_Quit();
        fprintf(stderr, "err: int main(): SDL_CreateWindow() failed");
        return 1;
    }

    // renderer creation
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (!renderer)
    {
        SDL_DestroyWindow(window);
        SDL_Quit();
        fprintf(stderr, "err: int main(): SDL_CreateRenderer() failed");
        return 1;
    }

    // set scene to menu
    scenes = &menu_scene;

    // loop
    for (uint8_t quit = 0; !quit;)
    {
        // event polling
        for (SDL_Event e; SDL_PollEvent(&e);)
        {
            // global events
            if (e.type == SDL_QUIT)
                quit++;
            else if (e.type == SDL_MOUSEMOTION)
            {
                mouse_x = ((SDL_MouseMotionEvent *)&e)->x;
                mouse_y = ((SDL_MouseMotionEvent *)&e)->y;
            }
            else if (e.type == SDL_WINDOWEVENT && e.window.event == SDL_WINDOWEVENT_RESIZED)
            {
                window_w = ((SDL_WindowEvent *)&e)->data1;
                window_h = ((SDL_WindowEvent *)&e)->data2;
            }

            // pass events to scenes
            if (scenes)
                for (PC_Scene *scene = scenes; scene; scene = scene->next)
                    if (scene->event)
                        scene->event(scene, &e);
        }

        // rendering
        render(renderer);
    }

    // cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
