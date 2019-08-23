
#include "main.h"





int main(int argc, char *argv[])
{
    memset(&app, 0, sizeof(App));
    memset(&cursor, 0, sizeof(Cursor));
    memset(&player, 0, sizeof(Entity));
    initSDL();

    cursor.texture = loadTexture(cursor_path);        /* will be in another .c file */
    SDL_Texture* menu_texture = loadTexture(menu_path);
    player.texture =loadTexture(cursor_path) ;
    player.def = 10;
    player.attack = 15;
    player.hp = 5;
    player.stamina;
    atexit(cleanup);

    int position[] = {1,0,1};

    long then;
    float remainder;//i ll get it someday not in the morning

    while (1)
    {


        prepareScene(menu_texture);

        doInput(position);

        prepareCursor(cursor.texture,position);

        preparePlayer(player.texture);//delete it 24

        presentScene();

        //capFrameRate(&then, &remainder);
        SDL_Delay(16);

    }

    return 0;
}
