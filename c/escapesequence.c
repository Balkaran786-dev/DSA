#include<stdio.h>

int main()
{   
   /*\n-new line, \b-backspace, \a- sound, \t-horizontal space, \v-vertical space,\f-form feed
      \r-carriage return,\'-single quotation, \"-double quotation,\?-question mark,\\ backslash */

    printf("\"My name is\n\'balkaran\tsingh\' \""); 
    printf("\n \' who are  \b\b you\? \'");
    printf("\n \\ my fav subject is:\v mathematics"); // both \f and \v have same function
    printf("\n kamla \rsi");
    printf(" \n ringtone of my mobile phone is: \a");

    return 0;
}