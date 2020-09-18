#include <C_8051F340.h>
#include <Einstellungen.h>

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

#if 1
#define interrupt(x)
#endif

void main() {
    Grundeinstellungen();

    P0 = 0xF;
    P1 = 0xF;

    while (1) continue;
}
