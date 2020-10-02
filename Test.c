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

    P1_0 = 0;

    while (1) {
        P1_0 = P4 & 1;
    }
}
