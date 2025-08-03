// #include<stdio.h>
// int main(){  //matrix multiplication
//     int a[4][2]={1,2,3,4,5,6,7,8};
//     int b[2][3]={1,2,3,4,5,6};
//     int c[4][3];
//     for(int i=0;i<4;i++){
//         for(int j=0;j<3;j++){
//             int ans=0;
//             for(int k=0;k<2;k++){
//                 ans+=a[i][k]*b[k][j];
//             }
//             c[i][j]=ans;
//         }
//     }
//     for(int i=0;i<4;i++){
//         for(int j=0;j<3;j++){
//             printf("%d ",c[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }


    //pascal triangle
#include<stdio.h>
int main(){
    int i,j,space,value=1;
    for(i=1;i<=4;i++){
        for(space=1;space<=(4-i);space++){
            printf(" ");
        }
        for(j=1;j<=i;j++){
            if(i==1||j==1){
                value=1;
            }
            else{
                value=value*(i-j+1)/(j-1);
            }
            printf("%2d",value);
        }
        printf("\n");
    }
    return 0;
}
