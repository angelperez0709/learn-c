#include <stdio.h>

int runner()
{
    // whitout static the variable is removed from memory as soon as the function finishes executing, so it will always return 1
    // with static the variable keeps in memory
    static int count = 0;
    count++;
    return count;
}

int sum(int num)
{
    static int total = 0;
    total += num;
    return total;
}

int main()
{
    printf("%d\n", runner());
    printf("%d\n", runner());

    printf("%d\n", sum(200));
    printf("%d\n", sum(30));
    printf("%d\n", sum(12));
    return 0;
}


static void fun(void)
{
    printf("This is a static function.\n");
}