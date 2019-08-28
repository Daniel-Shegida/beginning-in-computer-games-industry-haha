
#include "main.h"





int main(int argc, char *argv[])
{



    // текущий кадр анимации
    int anim_phase = 0;
    // фаза анимации (бег, стояние на месте ...)
    int anim_type = 0;
    // количество кадров анимации для данного типа
    int anim_phase_max[16] = { 13, 8, 10, 10, 10, 6, 4, 7, 13, 8, 10, 10, 10, 6, 4,
            7 };
    // время с предыдущего кадра анимации
    uint32_t last_frame;
    // время в мс на 1 кадр

    last_frame=SDL_GetTicks();


    //dont forget about them




    Entity *head = NULL;
    Entity *last = NULL;
    int buffer = 0;
    memset(&app, 0, sizeof(App));
    memset(&cursor, 0, sizeof(Cursor));
    memset(&player, 0, sizeof(Entity));
    initSDL();
        // load enemy
        FILE *inFile;
        inFile = fopen("source.txt","r");
        while (!feof(inFile))
        {
            Entity *futureLast = (Entity*)malloc(sizeof(Entity));
            fscanf(inFile, " %d %d %d %d %d", &futureLast->def , &futureLast->attack ,&futureLast->hp ,&futureLast->stamina,&futureLast->place);
            printf(" enemy %d %d %d %d %d", futureLast->def , futureLast->attack ,futureLast->hp ,futureLast->stamina,futureLast->place);
            futureLast->max_hp = futureLast->hp;
            if  (last != NULL)
            {
                last->next = futureLast;
                futureLast->next = NULL;
                last = futureLast;
            }
            else {
                head = futureLast;
              last = futureLast;
            }
            }
        last = find(1,head);
        fclose(inFile);

        // load player
        //char imagePath[] = bandit_path;
        inFile = fopen("source1.txt","r");
        fscanf(inFile, "%d%d%d%d", &player.def , &player.attack ,&player.hp ,&player.stamina);
        fclose(inFile);
        player.max_hp = player.hp;
        printf( "player  %d %d %d %d %d", player.def , player.attack ,player.hp ,player.stamina,player.hp);
        player.texture =load_animation(bandit_path) ;


        cursor.texture = loadTexture(cursor_path);        /* will be in another .c file */
        SDL_Texture* menu_texture = loadTexture(menu_path);

        SDL_Texture* enemy =  load_animation(hero_path);
        SDL_Texture* enemy2 =  load_animation(menu_path2);

    atexit(cleanup);
    // loading from txt ended
    int position[] = {1,0,1};

    SDL_Texture* hp_texture = loadTexture(cursor_path);



    while (1)
    {


        prepareScene(menu_texture);


        if ((SDL_GetTicks()- last_frame) >= frame_time) {
            anim_phase++;
            if (anim_phase >= anim_phase_max[anim_type]) anim_phase = 0;
            last_frame = SDL_GetTicks();
        }


        doInput(position,head,&player);



        prepareCursor(cursor.texture,position);



        preparePlayer(player.texture);//delete it {maybe}

        prepare_enemy(enemy,head,enemy2);

        presentAllHp(hp_texture,head,&player);



        presentScene();



        //capFrameRate(&then, &remainder);
        SDL_Delay(16);

    }

    return 0;
}

