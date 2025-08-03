#include<stdio.h>
int main(){
    int n = 0;
    printf("Enter the number of values you wish to enter: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the values: ");
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    int min = arr[0], max = arr[0];
    for(int i=0;i<n;i++){
        if(min > arr[i]){
            min = arr[i];
        }
        if(max < arr[i]){
            max = arr[i];
        }
    }
    printf("Max: %d\nMin: %d", max, min);
    return 0;
}
