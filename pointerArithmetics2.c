#include <stdio.h>

int main()
{
    int intarray[5] = {10, 20, 30, 40, 50};
    int *parray[5]; // Let's map all 5 this time

    // 1. Populate parray with addresses of intarray in REVERSE
    // Hint: Use pointer arithmetic starting from &intarray[4]
    int length = sizeof(intarray) / sizeof(intarray[0]);
    for (int i = length - 1; i >= 0; --i)
    {
        int inverseIndex = length - 1 - i;
        parray[inverseIndex] = &intarray[i];
    }
    

    for(int i = 0;i < length;++i){
        printf("The address value is %p\n",parray[i]);
        printf("The dobule value is %d\n",*parray[i]);
    }
    printf("--------------\n");

    // 2. Iterate through parray and multiply the values pointed to by 2
    // Hint: Use the dereference operator (*)
    for(int i = 0;i < length;++i){
        *parray[i] = *parray[i] * 2;
    }

    // 3. Print intarray to see the result
    // Expected Output: 20, 40, 60, 80, 100 (but mapped via parray)
    for(int i = 0;i < length;++i){
        printf("The dobule value is %d\n",intarray[i]);
    }

    return 0;
}