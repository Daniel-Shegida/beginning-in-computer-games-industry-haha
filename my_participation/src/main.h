
#include "common.h"

extern void cleanup(void);
extern void initSDL(void);
extern void prepareScene(SDL_Texture *texture);
extern void presentScene(void);

App app;
Cursor cursor;
Entity player;
