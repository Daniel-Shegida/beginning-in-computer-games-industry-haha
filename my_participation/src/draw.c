
#include "draw.h"




SDL_Texture *loadTexture(char *filename)
{
    SDL_Texture *texture;

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

    texture = IMG_LoadTexture(app.renderer, filename);

    return texture;
}



void prepareCursor(SDL_Texture *texture,int position[])
{
    SDL_Rect dest;

    dest.x = 130 + position[1]*515;
    if (position[1])
    {
        dest.y  = 425 + position[2] * 55 * 1;
    }
    else
    {
        dest.y = 510 + position[0] * 35 ;
    }
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    SDL_RenderCopy(app.renderer, texture, NULL, &dest);
}

void prepareScene(SDL_Texture *texture)
{
	SDL_SetRenderDrawColor(app.renderer, 96, 128, 0, 0);
	SDL_RenderClear(app.renderer);
    SDL_Rect dest;
    dest.x = menu_x;
    dest.y = menu_y;
    dest.w = 30;
    dest.h = 106;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(app.renderer, texture, NULL, &dest);
}



void presentScene(void)
{

	SDL_RenderPresent(app.renderer);
}


void preparePlayer(SDL_Texture *texture) //rubish function j
{
    SDL_Rect dest;

    dest.x = 222;

    dest.y  = 222;

    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    SDL_RenderCopy(app.renderer, texture, NULL, &dest);
}
