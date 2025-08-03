#include<stdio.h>
#include<string.h>
int main(){
    typedef struct pokemon{
        char name[20];
        int hp;
        float agility;
    } pokemon;

    pokemon arr[3];       // defined an array of pokemon datatype
    for(int i=0;i<3;i++){
        printf("%d\n",i+1);
        char name[20];
        printf("Enter the name:");
        scanf("%s",&name);
        strcpy(arr[i].name,name);
        printf("Enter The agility:");
        scanf("%f",&arr[i].agility);
        printf("Enter The HP:");
        scanf("%d",&arr[i].hp);
    }
    for(int i=0;i<3;i++){
        printf("The Name:");
        printf("%s\n",arr[i].name);
        printf("The HP:");
        printf("%d\n",arr[i].hp);
        printf("The agility:");
        printf("%f\n",arr[i].agility);
    }

    typedef struct student{
        char name[40];
        char gender[10];
        int marks;
        char grade;
    } student;

    student arr[5];
    for(int i=0;i<5;i++){
        printf("%d\n",i+1);
        printf("Enter the Name:");
        scanf("\n%s",arr[i].name);
        printf("Enter the gender:");
        scanf("\n%s",arr[i].gender);
        printf("Enter the marks:");
        scanf("\n%d",&arr[i].marks);
        printf("Enter the grade:");
        scanf("\n%c",&arr[i].grade);
    }
    for(int i=0;i<5;i++){
        printf("The name:%s\n",arr[i].name);
        printf("The gender:%s\n",arr[i].gender);
        printf("The marks:%d\n",arr[i].marks);
        printf("The grade:%c\n",arr[i].grade);
    }
    return 0;
}