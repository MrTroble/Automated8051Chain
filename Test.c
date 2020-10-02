#include <C_8051F340.h>
#include <Einstellungen.h>

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

#ifdef VSCODE
#define interrupt(x)
#endif

void main() {
    Grundeinstellungen();

    P4 = 0;

    while (1) {
        P3_4 = 1;
        P4 = P3;
        P1 = P4;
    }
}
