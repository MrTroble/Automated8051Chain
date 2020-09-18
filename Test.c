#include <C_8051F340.h>
#include <Einstellungen.h>

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

#ifdef VSCODE
#define interrupt(x)
#endif

#define MAX_CYCLES 8

uint8_t counter = 0;

void next() {
    if (P0 == 128) {
        P0 = 1;
        return;
    }
    P0 <<= 1;

    if (P1 & 128 == 128) {
        P1 <<= 1;
        P1++;
    } else {
        P1 <<= 1;
    }
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
    TR0 = 1;

    P0 = 1;
    P1 = 7;

    while (1) continue;
}
