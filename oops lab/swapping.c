#include <stdio.h>
typedef struct {
    int a;
    int b;
} Numbers;
void swapByValue(Numbers nums) {
    int temp = nums.a;
    nums.a = nums.b;
    nums.b = temp;
}
void swapByReference(Numbers *nums) {
    int temp = nums->a;
    nums->a = nums->b;
    nums->b = temp;
}
void swapByAddress(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    Numbers nums;
    nums.a=4;
    nums.b=5;
    printf("Before swap: a = %d, b = %d\n", nums.a, nums.b);
    swapByValue(nums);
    printf("After swap (call by value): a = %d, b = %d\n", nums.a, nums.b);

    printf("Before swap: a = %d, b = %d\n", nums.a, nums.b);
    swapByReference(&nums);
    printf("After swap (call by reference): a = %d, b = %d\n", nums.a, nums.b);

    printf("Before swap: a = %d, b = %d\n", nums.a, nums.b);
    swapByAddress(&nums.a, &nums.b);
    printf("After swap (call by address): a = %d, b = %d\n", nums.a, nums.b);
    return 0;
}