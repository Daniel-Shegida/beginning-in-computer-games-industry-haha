
#include "player.h"

void player_attack(struct Entity *head,struct Entity *attacker , int target)
{

    Entity *defender = (Entity*)malloc(sizeof(Entity));
    defender = find(target,head);
    printf ("         ok  /n enemy hp,attack,def = %d - (%d -%d ok          /n) ",defender->hp, defender->attack ,defender->def );
    Entity *player = (Entity*)malloc(sizeof(Entity));
    player = attacker;
    printf ("         ok  /n player hp,attack,def = %d - (%d -%d ok          /n) ",player->hp, player->attack ,player->def );
   // printf (" enemy hp = %d - (%d -%d) ",defender->hp, player->attack ,defender->def );
    int test1 = defender->def;
    int test2 = defender->hp;
    int test3 = player->attack;
    printf (" attack phase  %d - %d + %d ",test2, test3 ,test1);
    test2 = test2 - test3 + test1;
    printf (" aaaaand   %d ",test2);
    defender->hp = test2 ;
    printf ("and enemy hp is %d ",defender->hp);
    attack_enemy(head,attacker);
}


void player_def (struct Entity *head,struct Entity *defender , int target)
{
    Entity *player = (Entity*)malloc(sizeof(Entity));
    player = defender;
    player->def = player->def * mod;
    attack_enemy(head,player);
    player->def = player->def / mod;
}

/*
void player_retreat(struct )
{
    int i;
    for (i = 0; i++;i <3)
    {
       attack_enemy();
    }
    return
}
*/
