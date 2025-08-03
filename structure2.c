#include<stdio.h>
int main(){
    struct pokemon{
        int hp;
        int speed;
        int attack;
        char tier;
    };
    struct legendaryPokemon{
        int specialAttack;
        struct pokemon normal;
    };
    struct legendaryPokemon mewtwo;
    mewtwo.normal.attack=60;
    mewtwo.normal.speed=80;
    mewtwo.normal.hp=20;
    mewtwo.normal.tier='A';
    mewtwo.specialAttack=200;
    
    printf("%d\n",mewtwo.normal.hp);
    printf("%d\n",mewtwo.normal.speed);
    printf("%d\n",mewtwo.normal.attack);
    printf("%c\n",mewtwo.normal.tier);
    printf("%d\n",mewtwo.specialAttack);
    return 0;
}