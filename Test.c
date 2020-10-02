#include <C_8051F340.h>
#include <Einstellungen.h>

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

#ifdef VSCODE
#define interrupt(x)
#endif

#define POR1 1
#define POR2 2
#define POR3 4
#define POR4 8
#define POR5 16
#define POR6 32
#define POR7 64
#define POR8 128

uint8_t TABLE[8] = {POR1, POR2, POR3, POR4, POR5, POR6, POR7, POR8};

inline void sport(const uint32_t port, const uint8_t input) {
    if (input) {
        P4 |= port;
    } else {
        P4 &= ~port;
    }
}
inline uint8_t port(const uint32_t port) {
    return P4 & port;
}

uint8_t taster[4][3];
uint8_t i = 0, x = 0, stage = 0, wrong = 0;

void proccess() {
    if (!taster[3][2]) {
        stage = 0;
        P1 = 0;
    }

    if (port(POR8)) {
        stage++;
        if (wrong) return;
        if (stage == 4) P1 = 0xFF;
        P1 = stage;
        if (stage == 1 && taster[0][0]) {
            wrong = 1;
        } else if (stage == 2 && taster[1][2]) {
            wrong = 1;
        } else if (stage == 3 && taster[0][2]) {
            wrong = 1;
        }
        while (port(POR8)) continue;
    }
}

void main() {
    Grundeinstellungen();

    P1 = 0;

    while (1) {
        for (i = 0; i < 4; i++) {
            P4 |= 15;
            sport(TABLE[i], 0);
            for (x = 0; x < 3; x++) {
                taster[i][x] = port(TABLE[x + 4]);
            }
        }
        process();
    }
}
