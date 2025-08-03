#include<stdio.h>
struct student{       //to define a student,we made a class of student
     char* name;
     int roll_no;
     int marks[6]   
}s1;

void student_details(struct student s){      //to print the details of a student
          printf("The name of student is: %s \n",s.name);
          printf("The Roll no. of student is: %d \n",s.roll_no);
          printf("The marks of student in each subject are: \n");
          for(int i=0;i<6;i++){
             printf("%d ",s.marks[i]);
          }
          printf("\n");
}
int total_marks(struct student s){   //to return total marks of a student
        int total_marks=0;
        for(int i=0;i<6;i++){
             total_marks+=s.marks[i];
          }
        return total_marks;
}
int main(){
    s1.name="Balkaran singh";
    s1.roll_no=23103027;
    s1.marks[0]=89;
    s1.marks[1]=90;
    s1.marks[2]=89;
    s1.marks[3]=100;
    s1.marks[4]=58;
    s1.marks[5]=89;
    student_details(s1);
    printf("The total marks of the student is: %d", total_marks(s1));
    return 0;
}