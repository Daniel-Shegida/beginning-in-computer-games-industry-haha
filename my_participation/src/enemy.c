
#include "enemy.h"

/*void load_enemy()
{
    FILE *inFile;
    inFile = fopen("source.txt","r");
    while (!feof(inFile))
    {
        fscanf(inFile, "%d %d %d %d", );
    }
    fclose(inFile);
}
*/

void attack_enemy (struct Entity *head,struct Entity *player )
{
    Entity *atacker = (Entity*)malloc(sizeof(Entity));
    Entity *defender= (Entity*)malloc(sizeof(Entity));
    atacker = head;
    defender = player;
    while(atacker !=NULL)
       {
            printf (" player->hp = %d - (%d -%d) ",defender->hp, atacker->attack ,defender->def );
            defender->hp = defender->hp - atacker->attack + defender->def ;
            printf ("and player.hp is %d ",defender->hp);
            atacker = atacker->next;
       }
}


