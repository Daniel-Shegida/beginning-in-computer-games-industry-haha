

typedef struct {
	SDL_Renderer *renderer;
	SDL_Window *window;
} App;

typedef struct {

    SDL_Texture *texture;
} Cursor;

typedef struct
{
    int def;
    int attack;
    int hp;
    int stamina;
    int place ;
    int max_hp;
    struct Entity *next;
    SDL_Texture *texture;
}Entity;
