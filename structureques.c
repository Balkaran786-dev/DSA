#include<stdio.h>
#include<string.h>
int main(){
    //1.
    typedef struct cricketer{
        char firstname[20];
        char lastname[20];
        int age;
        int noOfmatches;
        int average;
    }cricketer;
    cricketer arr[3];
    for(int i=0;i<3;i++){
        printf("%d\n",i+1);
        scanf("%s",arr[i].firstname);
        scanf("%s",arr[i].lastname);
        scanf("%d",&arr[i].age);
        scanf("%d",&arr[i].noOfmatches);
        scanf(" %d",&arr[i].average);
    }
    for(int i=0;i<3;i++){
        printf("%s %s\n",arr[i].firstname,arr[i].lastname);
        printf("%d\n",arr[i].age);
        printf("%d\n",arr[i].noOfmatches);
        printf("%d\n",arr[i].average);
    }


//    2.
//     typedef struct date{
//         int day;
//         int month;
//         int year;
//     } date;
//     date a,b,c;
//     a.day=12;
//     a.month=8;
//     a.year=2005;

//     b.day=13;
//     b.month=9;
//     b.year=2006;

//     if(a.day==b.day&&a.month==b.month&&a.year==b.year){
//          printf("THE DATES ARE EQUAL");
//     }
//     else{
//         printf("THE DATES ARE NOT EQUAL");
//     }

//     c=a;
//     if(a.day==c.day&&a.month==c.month&&a.year==c.year){
//          printf("THE DATES ARE EQUAL");
//     }
//     else{
//         printf("THE DATES ARE NOT EQUAL");
//     }
}