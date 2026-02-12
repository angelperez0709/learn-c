    #include <stdio.h>
	
    int main() {
    	int intarray[5] = {10,20,30,40,50};
        //-----------------------^
        int *pointer = &intarray[2];
        printf("%p\n",pointer);
        // Array of 3 pointers
        int *parray[3];

        // Copy last three addresses of intarray into parray
        // Use parray and pointer
        int i;
        int *p;
        for (i = 0; i < 3; i++) {
            p = pointer + i;
            parray[i] = p;
            printf("%p\n",parray[i]);
            
        }

        // Test code
        for (i = 0; i < 3; i++) {
            if (parray[i] == &pointer[i]) {
                printf("Matched!\n");
            } else {
                printf("Fail\n");
            }
        }

        return 0;
    }