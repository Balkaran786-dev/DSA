#include<stdio.h>
#include<string.h>
int main(){
    typedef struct pokemon{
        int hp;
        int speed;
        int attack;
        char tier;
        char name[50];
    } pokemon;
    typedef struct legendarypokemon{
        int specialattack;
        pokemon normal;
    } legendarypokemon;
    typedef struct godpokemon{
        char specialability[30];
        legendarypokemon legend;
    } godpokemon;

    godpokemon arcieus;
    strcpy(arcieus.specialability,"defence");
    arcieus.legend.specialattack=45;
    arcieus.legend.normal.attack=90;
    arcieus.legend.normal.speed=970;
    arcieus.legend.normal.hp=80;
    arcieus.legend.normal.tier='A'

    return 0;
}