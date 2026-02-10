#include <stdio.h>

struct point{
    int x;
    int y;
};

//fastest way to get rid of the definition
typedef struct{
    int width;
    int height;
}rectangle;

int main(){
    struct point p1;
    p1.x = 10;
    p1.y = 20;
    printf("Point p1: (%d, %d)\n", p1.x, p1.y);
    rectangle rect1;
    rect1.width = 5;
    rect1.height = 10;
    printf("Rectangle rect1: width = %d, height = %d\n", rect1.width, rect1.height);
    return 0;
}