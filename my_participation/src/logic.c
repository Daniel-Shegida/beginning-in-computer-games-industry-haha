

#include "logic.h"

 /*void capFrameRate(long *then, float *remainder)  well idk it just doesnt work
{
    long wait, frameTime;

    wait = 16 + *remainder;

    *remainder -= (int)*remainder;

    frameTime = SDL_GetTicks() - *then;

    wait -= frameTime;

    if (wait < 1)
    {
        wait = 1;
    }

    SDL_Delay(wait);

    *remainder += 0.667;

    *then = SDL_GetTicks();
}

*/

struct entity* find(int target,struct entity *last)
{
    Entity *futureLast = (Entity*)malloc(sizeof(Entity));
    futureLast = last ;
    while (futureLast->place != target )
    {
        futureLast = futureLast->next;
    }
    puts("yey");
    printf(" his def is %d  end of it      ",futureLast->def);
    return futureLast;
}
