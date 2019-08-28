
#include "input.h"

void doInput(int position[],struct Entity *head,struct Entity *attacker)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            exit(0);
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_DOWN:
                if (position[1] )
                {
                    if (position[2]!=3)
                    {
                        position[2]++;
                    }
                    else
                    {
                        position[2] = 1;

                    }
                }
                else
                {
                    if (position[0]!=4)
                    {
                        position[0]++;
                    }
                    else
                    {
                        position[0] = 1;
                    }
                }
                break;

            case SDLK_UP:
                if (position[1] )
                {
                    if (position[2]!=1)
                    {
                        position[2]--;
                    }
                    else
                    {
                        position[2] = 3;
                    }
                }
                else
                {
                    if (position[0]!=1)
                    {
                        position[0]--;
                    }
                    else
                    {
                        position[0] = 4;
                    }
                }
                break;

            case  SDLK_z:
                switch (position[0])
                {
                case 1 :
                    if (position[1])
                    {
                        printf(" position[2]%d(position[2]-1)", (position[2]));
                        player_attack(head,attacker , (position[2]));
                        position[1] = 0;
                        position[0] = 1;
                    }
                    else
                    {
                        position[1] = 1;
                        position[2] = 1;
                    }
                    break;
                case 2 :
                    break;
                case 3 :
                    break;
                case 4 :
                    break;
                }
                break;


                case  SDLK_x:
                    if (position[1])
                    {
                        position[1] = 0;
                        position[0] = 1;
                    }
                    break;
                    break;

            }
        }
    }
}
