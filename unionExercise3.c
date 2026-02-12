#include <stdio.h>

union Hybrid
{
    int x;
    unsigned char bytes[sizeof(int)]; // Usamos char para ver cada byte individual
};

int main()
{
    union Hybrid h;
    h.x = 0x87654321; // Un número en hexadecimal para verlo claro

    printf("Tamaño del Union: %zu bytes\n", sizeof(h));
    printf("Valor entero: %X\n", h.x);

    // Recorremos los bytes que componen ese mismo entero
    printf("Recorriendo los bytes en memoria:\n");
    for (int i = 0; i < sizeof(int); i++)
    {
        printf("Byte %d: %02X (en la dirección %p)\n", i, h.bytes[i], (void *)&h.bytes[i]);
    }
    for (int i = 0; i < sizeof(int); i++)
    {
        unsigned char byte = (h.x >> (i * 8)) & 0xFF;
        printf("Byte %d: %02X\n", i, byte);
    }

    return 0;
}