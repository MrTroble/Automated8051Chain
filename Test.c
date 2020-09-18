#include <C_8051F340.h>
#include <Einstellungen.h>

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

#ifdef VSCODE
#define interrupt(x)
#endif

#define MAX_CYCLES 8

uint8_t counter = 0, i = 0, j = 0;

#define EXTENT 8

uint8_t image[EXTENT][EXTENT] = {
    {0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1},
};

void next() {
}

void overflow() interrupt(1) {
    counter++;
    if (counter == MAX_CYCLES) {
        counter = 0;
        next();
    }
    TH0 = 0;
    TL0 = 0;
}

void main() {
    Grundeinstellungen();

    TH0 = 0;
    TL0 = 0;

    EA = 1;
    ET0 = 1;
    TMOD = 1;
    TR0 = 0;

    for (i = 0; i < EXTENT; i++) {
        for (j = 0; j < EXTENT; j++) {
            P0 = image[i][j];
            P1 = !(image[i][j] & 1);
        }
    }

    while (1) {
    };
}
