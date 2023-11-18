#include "../lib/buttons.h"

struct keys{
    int w;
    int a;
    int s;
    int d;
    int e;
    int esc;
};

void init_buttons(ButtonKeys *key){
    ButtonKeys k;
    k = malloc(sizeof(struct keys));
    k->w = 0;
    k->a = 0;
    k->s = 0;
    k->d = 0;
    k->e = 0;
    k->esc = 0;

    if(key != NULL){
        *key = k;
    }else{
        printf("Error, & is NULL - Buttons\n");
    }
}

int read_keys(ButtonKeys *key){
    SDL_Event event;

    while (SDL_PollEvent(&event)){

        if (event.type == SDL_QUIT){
            return (-1);
        }

        if (event.type == SDL_KEYDOWN){
            if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w){
                (*key)->w = 1;
            }
            if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s){
                (*key)->s = 1;
            }
            if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d){
                (*key)->d = 1;
            }
            if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a){
                (*key)->a = 1;
            }
            if (event.key.keysym.sym == SDLK_e){
                (*key)->e = 1;
            }
        }

        if (event.type == SDL_KEYUP){
            if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w){
                (*key)->w = 0;
            }
            if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s){
                (*key)->s = 0;
            }
            if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d){
                (*key)->d = 0;
            }
            if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a){
                (*key)->a = 0;
            }
            if (event.key.keysym.sym == SDLK_e){
                (*key)->e = 0;
            }
        }
    }

    return (0);
}

int get_w(ButtonKeys key){ return key->w; }

int get_a(ButtonKeys key){ return key->a; }

int get_d(ButtonKeys key){ return key->d; }

int get_s(ButtonKeys key){ return key->s; }

int get_e(ButtonKeys key){ return key->e; }

int get_esc(ButtonKeys key){ return key->esc; }

void close_buttons(ButtonKeys *keys){
    if(keys != NULL){
        free(*keys);
    }
}