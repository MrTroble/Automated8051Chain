#include <C_8051F340.h>
#include <Einstellungen.h>

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;

void rennzeit() {

}

uint8_t counter = 0;

// 2**16 - (10**6 % 2**16) = 48576 [BDC0]
// 10**6 / 2**16 ~= 16
void overflow() interrupt 1 {
    if((++counter) < 17)
        return;
    counter = 0;
    rennzeit();
    TH0 = 0xBD;
    TL0 = 0xC0;
}

void main ()
{
    Grundeinstellungen();
    TH0 = 0xBD;
    TL0 = 0xC0;
}



