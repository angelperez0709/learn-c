#include <stdio.h>
union Value
{
    int digital;
    float analog;
};
struct Sensor
{
    int type;
    union Value val;
};

void printSensor(struct Sensor s)
{
    switch (s.type)
    {
    case 0:
        printf("%d\n", s.val.digital);
        break;

    case 1:
        printf("%f\n", s.val.analog);
        break;

    default:
        break;
    }
}

int main()
{

    struct Sensor s;
    s.type = 0;
    s.val.digital = 12;
    printSensor(s);
    s.type = 1;
    s.val.analog = 3.4;
    printSensor(s);
    return 0;
}