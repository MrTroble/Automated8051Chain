#include <C_8051F340.h>
#include <Einstellungen.h>

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

#if 1
#define interrupt(x)
#endif

void overflow() {
}

void main() {
    Grundeinstellungen();

    P0 = 3;
    P1 = 0;

    while (1) continue;
}
