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

    P1 = 0xFF;
    P2 = 0xFF;

    while (1) continue;
}
