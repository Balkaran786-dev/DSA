#include<stdio.h>
int main(){
    typedef struct person{
        int age;
        float weight;
    } person;
    person p1,p2;
    person *x=&p1;
    person *y=&p2;
    (*x).age=21;       //assigning values to structure variables through pointers
    (*x).weight=56.7;
    (*y).age=51;
    (*y).weight=76.1;
    printf("%d\n",p1.age);
    printf("%f\n",p1.weight);
    printf("%d\n",p2.age);
    printf("%f",p2.weight);
    return 0;
}



#include<stdio.h>
typedef struct pokemon{
        int hp;
        int attack;
        int speed;
} pokemon;
void change(pokemon* p){
    (*p).hp=70;      //(*x).something=x->something
    p->attack=500;
    p->speed=100;

}
int main(){
     pokemon pikachu;
     pikachu.hp=30;
     pikachu.attack=200;
     pikachu.speed=700;

     change(&pikachu);

     printf("%d\n",pikachu.hp);
     printf("%d\n",pikachu.attack);
     printf("%d\n",pikachu.speed);

    return 0;
}