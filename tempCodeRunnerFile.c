#include <stdio.h>
int main()
{
    float hardness, cc;
    long rollno = 23112033;
    int grade=0, ts=0;
    printf("The values of hardness, carbon content and tensile strength are:  ");
    scanf("%f %f %d", &hardness, &cc, &ts);
    
    int c1 = (hardness > (rollno % 100)),
        c2 = (cc < (rollno % 10 + 0.5)),
        c3 = (ts > ((rollno % 100) * 100));
    switch (c1 + c2 + c3) {
        case 3:
            grade = 10;
            break;
        case 2:
            if (c1 && c2)
                grade = 9;
            else if (c2 && c3)
                grade = 8;
            else if (c1 && c3)
                grade = 7;
            break;
        case 1:
            grade = 6;
            break;
        case 0:
         grade = 5;
            break;
    }

    printf("Grade: %d", grade);

     return 0;
}