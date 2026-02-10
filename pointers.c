#include <stdio.h>

int main()
{
    int number = 4;
    int *pointer = &number;
    
    printf("%d\n", number);
    (*pointer)++;
    printf("%d\n", *pointer);
    printf("%d\n", number);
}
