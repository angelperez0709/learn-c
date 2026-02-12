#include <stdio.h>

int main() {
    int intarray[5] = {45, 12, 89, 23, 7};
    int *parray[5];
    
    // 1. Initialize parray normally
    for(int i = 0; i < 5; i++) parray[i] = &intarray[i];

    // 2. Use a double pointer 'pp' to find the min and max
    int **pp = parray;
    int **min_pp = &parray[0];
    int **max_pp = &parray[0];



    // --- YOUR TASK ---
    // Loop through parray using pp. 
    // If **pp < **min_pp, update min_pp to the current pp.
    // If **pp > **max_pp, update max_pp to the current pp.
    for(int i= 0;i < 5;++i){
        if(**(pp + i) < **min_pp){
            min_pp  = pp + i;
        }
        if(**(pp + i) > **max_pp){
            max_pp  = pp + i;
        }
    }
    
    // 3. Swap the content of parray[0] with the content of *min_pp
    // Hint: You are swapping 'int *' types.
    int *temp = parray[0];
    parray[0] = *min_pp;
    *min_pp = temp;
    for(int i= 0;i<5;i++){
        printf("%d\n",*parray[i]);
    }


    return 0;
}