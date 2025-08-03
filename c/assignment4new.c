 #include<stdio.h>
 
 int main(){
  /* char ch;
   printf("enter an alphabet:");
   scanf("%c",&ch);

   switch (ch)
   {
    case 'R':
     printf("Red");
     break;

    case 'G':
     printf("Green");
     break;

    case 'W': 
     printf("White");
     break;

    case 'P':
    printf("Pink");
    break;

    case 'B': 
    printf("Blue");
    break;

    default :
    printf("invalid");
    break;

   }


   int n;
   printf("Enter value of n:");
   scanf("%d",&n);

   for(int i=1; i<=n ; i++){
    for(int j=1; j<=i ; j++){
        printf("*");
    }
    printf("\n");
   }

   int amount;
   printf("Enter the value of amount:");
   scanf("%d",&amount);

   if ( amount>5000 ) {
    printf("Discount is 10%");
    printf(" Final amount :%d",amount - amount*10/100);
   } 
   else if ( amount>3000 && amount<5000 ){
    printf("Discount is 5%");
    printf(" Final amount :%d",amount - amount*5/100);
   }
   else {
    printf("Discount is 3%");
    printf("Final amount :%d",amount - amount*3/100);

   }*/

   int ch;
   printf("Enter a character:");
   scanf("%d", &ch);

   if(ch > 65 && ch < 90|| ch> 97 && ch< 122){
    printf("Alphabet");
   } 
   else if(ch> 0 && ch<9) {
    printf("Digit");
   }
   else {
    printf("Special character");
   }
   return 0;
 }