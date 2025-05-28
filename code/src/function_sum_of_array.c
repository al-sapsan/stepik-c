#include <stdio.h>

int sum_ar(int arr[], int len); // прототип функции

int main(void)
{
    int arr[10];
    // читает из входного потока в массив типа int десять целочисленных 
    // значений, записанных в одну строчку через пробел
    for (int i = 0; i < 10; ++i)
        scanf("%d", &arr[i]);
    int sum = sum_ar(arr, 10);
    printf("%d\n", sum);
    return 0;
}

int sum_ar(int arr[], int len) {
    int sum = 0;
    for (int i = 0; i < len; ++i)
        sum += arr[i];
    return sum;
}