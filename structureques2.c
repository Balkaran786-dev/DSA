#include<stdio.h>
#include<string.h>
typedef struct student{
        int rollnumber;
        char name[20];
        char department[20];
        char course[20];
        int yearOfJoining;
} student;
void fun(student x,student y){
    if(strcmp(x.department,y.department)==0){
        printf("THEY HAVE SAME DEPARTMENT");
        return;
    }
    else{
        printf("THEY HAVE DIFFERENT DEPARTMENT");
        return;
    }
}
int main(){
    student a,b;
    strcpy(a.department,"CSE");
    strcpy(b.department,"EC");
    fun(a,b);
    return 0;
}