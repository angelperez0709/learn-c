#include <stdio.h>

union Data {
    int i;
    char str[4];
};

int main() {
    union Data d;

    // 1. Assign a value to d.i (e.g., 0x41424344 which are Hex codes for 'D','C','B','A')
    d.i = 0x41424344; 

    // 2. Print the size of the union using sizeof(d)
    printf("the size of union is %d\n",sizeof(d));
    
    // 3. Print the characters in d.str[0], d.str[1], etc.
    // Notice how the integer was "sliced" into characters!
    for(int i=0;i < 4;++i){
        printf("number is %d\n",d.str[i]);
    }

    return 0;
}