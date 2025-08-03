#include<stdio.h>
int main(){
    int row1, col1;
    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &row1, &col1);
    int arr1[row1][col1], arr2[row1][col1], arr3[row1][col1], arr4[row1][col1];
    printf("Enter the first matrix:\n");
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("Enter the Second matrix:\n");
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            scanf("%d", &arr2[i][j]);
            arr3[i][j] = arr1[i][j] + arr2[i][j];
            arr4[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
    printf("The addition of the matrices gives:-\n");
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            printf(" %d", arr3[i][j]);
        }
        printf("\n");
    }
    printf("The subtraction of the matrices gives:-\n");
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            printf(" %d", arr4[i][j]);
        }
        printf("\n");
    }
    return 0;
}
