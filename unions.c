#include <stdio.h>

/* define the union here */
union IntCharacters
{
    int ints[6];
    char chars[sizeof(int) * 5 + 1];
};

union intParts
{
    int theInt;
    char bytes[sizeof(int)];
};

int main()
{

    union IntCharacters intCharacters = {{1853169737, 1936876900, 1684955508, 1768838432, 561213039, 0}};
    printf("[");
    // only go to 18 because 1 byte is for the terminating 0 and we don't print the last in the loop
    for (int i = 0; i < 19; ++i)
        printf("%c, ", intCharacters.chars[i]);
    printf("%c]\n", intCharacters.chars[19]);

    printf("%s\n", intCharacters.chars);

    union intParts parts;
    parts.theInt = 5968145;
    printf("The int is %i\nThe bytes are [%x, %x, %x, %x]\n",
           parts.theInt, parts.bytes[0], parts.bytes[1], parts.bytes[2], parts.bytes[3]);
}