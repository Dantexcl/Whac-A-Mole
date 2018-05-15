#include "msp430.h"
#include <stdlib.h>  // rand(), srand()

#define RXD        BIT2
#define TXD        BIT1

unsigned int score;
volatile unsigned int i = 0;

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
    DCOCTL = 0;
    // Set DCO to 1 MHz
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;
    
    P1DIR = BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6 | BIT7;
    
    
    P2DIR &= ~BIT0;
    P2REN |= BIT0;
    P2DIR &= ~BIT1;
    P2REN |= BIT1;
    P2DIR &= ~BIT2;
    P2REN |= BIT2;
    P2DIR &= ~BIT3;
    P2REN |= BIT3;
    P2DIR &= ~BIT4;
    P2REN |= BIT4;

    
    
    
    // Enable interrupts
    __bis_SR_register(GIE);
    
    unsigned char value;
    unsigned int random;
    while(1)
    {
        P1OUT = 0x00;
        
        if (score == 1) {
            P1OUT |= 0x80;
        } else if (score == 2) {
            P1OUT |= 0x40;
        } else if (score == 3) {
            P1OUT |= 0xC0;
        } else if (score == 4) {
            P1OUT |= 0x20;
        } else if (score == 5) {
            P1OUT |= 0xA0;
        } else if (score == 6) {
            P1OUT |= 0x60;
        } else if (score == 7) {
            P1OUT |= 0xE0;
        } else if (score == 8) {
            for (;;) {
                for (i = 0; i < 5000; i++) {
                    if (i == 0 ) {
                        P1OUT ^= 0x01;
                    }
                    if (i == 2500) {
                        P1OUT ^= 0x40;
                    }
                }
            }
        }
        
        
        __delay_cycles(500000);

        int add = rand() % 1000;
        
        for (int j = 0; j < 1000 + add; j++) {
            if (random > 13) {
                random = 0;
            }
            random += 1;
        }
        
        
        if (random == 0) {
            P1OUT |= 0x01;
            value = 0x01;
        } else if (random == 1) {
            P1OUT |= 0x02;
            value = 0x02;
        } else if (random == 2) {
            P1OUT |= 0x04;
            value = 0x04;
        } else if (random == 3) {
            P1OUT |= 0x08;
            value = 0x08;
        } else if (random == 4) {
            P1OUT |= 0x10;
            value = 0x10;
        } else if (random == 5) {
            P1OUT |= 0x03;
            value = 0x03;
        } else if (random == 6) {
            P1OUT |= 0x05;
            value = 0x05;
        } else if (random == 7) {
            P1OUT |= 0x09;
            value = 0x09;
        } else if (random == 8) {
            P1OUT |= 0x11;
            value = 0x11;
        } else if (random == 9) {
            P1OUT |= 0x06;
            value = 0x06;
        } else if (random == 10) {
            P1OUT |= 0xA;
            value = 0xA;
        } else if (random == 11) {
            P1OUT |= 0x12;
            value = 0x12;
        } else if (random == 12) {
            P1OUT |= 0xC;
            value = 0xC;
        } else if (random == 13) {
            P1OUT |= 0x14;
            value = 0x14;
        } else if (random == 14) {
            P1OUT |= 0x18;
            value = 0x18;
        }
        
        while (P2IN != value);
        
        while (P2IN == value);
        
        score++;
    }
}
//******************************************************************************

