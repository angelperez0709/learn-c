#include <stdio.h>

int main()
{
    int intarray[5] = {20, 40, 60, 80, 100};
    int *parray[5];

    // Quickly fill parray (you already know how to do this!)
    for (int i = 0; i < 5; i++)
    {
        parray[i] = &intarray[i];
    }

    // --- YOUR TASK STARTS HERE ---

    // 1. Declare your double pointer
    int **pp;
    

    // 2. Point pp to the start of parray
    pp = parray;
    printf("size of pp %d\n",sizeof(pp));
    printf("size of parray %d\n",sizeof(parray));

    // 3. Use a loop to print the values.
    // Hint: To get the number, you must "jump" twice: **pp
    // To move to the next pointer, use pp++

    printf("Printing using double pointer:\n");
    while (pp < (parray + 5))
    {
        printf("the pointer is: %p and the value is %d\n",*pp,**pp);
        // Your code here:
        // printf(...);
        pp++;
    }

    return 0;
}