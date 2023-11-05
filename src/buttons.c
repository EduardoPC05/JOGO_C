#include "buttons.h"

struct keys {
  int w;
  int a;
  int s;
  int d;
};

ButtonKeys init_keys(){
    ButtonKeys keys;
    keys = malloc(sizeof(struct keys));
    keys->w = 0;
    keys->a = 0;
    keys->s = 0;
    keys->d = 0;
    return keys;
}

int read_keys(ButtonKeys key){
    SDL_Event event;

    while (SDL_PollEvent(&event)){

        if (event.type == SDL_QUIT){
            return (-1);
        }
        
        if (event.type == SDL_KEYDOWN){
            if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w){
                key->w = 1;
            }
            if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s){
                key->s = 1;
            }
            if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d){
                key->d = 1;
            }
            if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a){
                key->a = 1;
            }
        }

        if (event.type == SDL_KEYUP){
            if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w){
                key->w = 0;
            }
            if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s){
                key->s = 0;
            }
            if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d){
                key->d = 0;
            }
            if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a){
                key->a = 0;
            }
        }
    }

    return (0);
}

int get_w(ButtonKeys key){
    return key->w;
}

int get_a(ButtonKeys key){
    return key->a;
}

int get_d(ButtonKeys key){
    return key->d;
}

int get_s(ButtonKeys key){
    return key->s;
}