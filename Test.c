#include <C_8051F340.h>
#include <Einstellungen.h>

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

#ifdef VSCODE
#define interrupt(x)
#endif

uint8_t counter = 0, i = 0, j = 0;

#define EXTENT 8

uint8_t image[EXTENT][EXTENT] = {
    {0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1},
};

void overflow() interrupt(1) {
    P1 = 0;
    P1 = ~(1 << j);
    for (i = 0; i < EXTENT; i++) {
        P1 |= (image[i][j] & 1) << i;
    }
    j++;
    if (j == 8)
        j = 0;

    TH0 = 0xF8;
    TL0 = 0x4B;
}

void main() {
    Grundeinstellungen();

    TH0 = 0xF8;
    TL0 = 0x4B;

    EA = 1;
    ET0 = 1;
    TMOD = 1;
    TR0 = 1;

    P0 = 0;

    while (1) continue;
}
