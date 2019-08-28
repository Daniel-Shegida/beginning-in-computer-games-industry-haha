
#include "draw.h"

SDL_Texture* load_animation(char *filename)
{
        SDL_Texture *newTexture;
        // Загружаем изображение
        SDL_Surface* loadedSurface = IMG_Load(filename);
    if (loadedSurface == NULL) {
            puts("Unable to load image %s! SDL_image Error: %s\n");
        }
    newTexture = SDL_CreateTextureFromSurface(app.renderer, loadedSurface);
    return newTexture;
    // Удаляем загруженную поверхность
    SDL_FreeSurface(loadedSurface);

}


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
    SDL_Rect  obj_size ,dest;

    dest.x = 222;

    dest.y  = 222;

    dest.h = 128;
    dest.w = 128;

    obj_size.x = 32 ;//* anim_phase;
    obj_size.y = 32; //* anim_type;
    obj_size.h = 32;
    obj_size.w = 32;

    //SDL_QueryTexture(texture, NULL, NULL &dest.w, &dest.h);

    SDL_RenderCopy(app.renderer, texture, &obj_size, &dest);
}

void prepare_enemy(SDL_Texture *texture,struct Entity *head,SDL_Texture *texture2)
{

    SDL_Rect  obj_size ,dest;

    dest.x = 222;

    dest.y  = 222;

    dest.h = 128;
    dest.w = 128;

    obj_size.x = 150 ;//* anim_phase;
    obj_size.y = 290; //* anim_type;
    obj_size.h = 32;
    obj_size.w = 32;

    Entity *atacker = (Entity*)malloc(sizeof(Entity));
    atacker = head;
    while(atacker !=NULL)
       {
            switch (atacker->place)
            {
            case 1:
                if (atacker->hp >0)
                {
                    dest.x = 900;

                    dest.y  = 70;

                    SDL_RenderCopy(app.renderer, texture, &obj_size, &dest);
                    dest.x = 600;

                    dest.y  = 500;

                    SDL_QueryTexture(texture2, NULL, NULL, &dest.w, &dest.h);
                    SDL_RenderCopy(app.renderer, texture2, NULL, &dest);


                }
                break;
            case 2 :
                if (atacker->hp >0)
                {

                    dest.x = 900;

                    dest.y  = 222;

                    dest.h = 128;
                    dest.w = 128;

                    obj_size.x = 150 ;//* anim_phase;
                    obj_size.y = 290; //* anim_type;
                    obj_size.h = 32;
                    obj_size.w = 32;

                    SDL_RenderCopy(app.renderer, texture, &obj_size, &dest);

                    dest.x = 600;

                                        dest.y  = 550;

                                        SDL_QueryTexture(texture2, NULL, NULL, &dest.w, &dest.h);
                                        SDL_RenderCopy(app.renderer, texture2, NULL, &dest);


                }
                break;
            case 3 :
                if (atacker->hp >0)
                {

                    dest.x = 900;

                    dest.y  = 222;

                    dest.h = 128;
                    dest.w = 128;

                    obj_size.x = 150 ;//* anim_phase;
                    obj_size.y = 290; //* anim_type;
                    obj_size.h = 32;
                    obj_size.w = 32;

                    SDL_RenderCopy(app.renderer, texture, &obj_size, &dest);

                    dest.x = 600;

                   dest.y  = 650;

                    SDL_QueryTexture(texture2, NULL, NULL, &dest.w, &dest.h);
                    SDL_RenderCopy(app.renderer, texture2, NULL, &dest);


                }
                break;
            }
            atacker = atacker->next;
       }
}

void presentAllHp(SDL_Texture *texture,struct entity *last,struct entity *player)
{


    int x = xPLA;
    int y = yPLA;

    showxp(texture,x,y,player);

    Entity *futureLast = (Entity*)malloc(sizeof(Entity));
    futureLast = last ;

    while  (futureLast != NULL)
    {
        switch(futureLast -> place)
        {
        case 1:
            if (futureLast -> hp > 0)
            {
            x = x1;
            y = y1;
            showxp(texture,x,y,futureLast);
            }
            break;
        case 2:
            if (futureLast -> hp > 0)
            {
            x = x2;
            y = y2;
            showxp(texture,x,y,futureLast);
            }
            break;
        case 3:
            if (futureLast -> hp > 0)
            {
            x = x3;
            y = y3;
            showxp(texture,x,y,futureLast);
            }
            break;
        }
        futureLast = futureLast->next;

    }


}

void showxp(SDL_Texture *texture,int x, int y,struct entity *warrior)
{


    SDL_Rect dest;

    dest.x = x;
    dest.y  = y;
    dest.w = 40;
    dest.h = 30;

    int step = 1;

    Entity *futureLast = (Entity*)malloc(sizeof(Entity));
    futureLast = warrior ;
    if (futureLast -> hp > 0)
    {

    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(app.renderer, texture, NULL, &dest);

    while ((futureLast ->hp*10/futureLast ->max_hp)>step)
    {


        step++;

        dest.x = dest.x + 40;


        SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
        SDL_RenderCopy(app.renderer, texture, NULL, &dest);

    }

    }

}
