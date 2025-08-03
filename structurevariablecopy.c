#include<stdio.h>
#include<string.h>
int main(){
    typedef struct pokemon{
        int hp;
        int attack;
        int speed;
        char tier;
        char name[30];
    } pokemon;
    pokemon a,b,c;
    a.hp=90;
    a.attack=40;
    a.speed=400;
    a.tier='A';
    strcpy(a.name,"Blastoise");

    b=a; // all attributes of a get copied to b..
    // you can change any particular attribute of b .. 
    b.hp=60;
    printf("%d %d",b.hp,a.hp);
    return 0;
}