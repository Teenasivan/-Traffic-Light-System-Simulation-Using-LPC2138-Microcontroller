#include <lpc214x.h>
#include <stdio.h>

void delay(unsigned int count) {
    unsigned int i = 0, j = 0;
    for (i = 0; i < 1000; i++) {
        for (j = 0; j < 1000; j++);
    }
}



void transmit(unsigned char ch) {
    while (!(U0LSR & 0x20)); //u0lsr contains flags and 0x20 corresponds to THR empty flag
    U0THR = ch;//ch is the character going to be written
}

void uart_init(void) {
    PINSEL0 = 0x00000005;  //configures pin0 and pin1 of uart
    U0LCR = 0x83;    //define data frame and enables divisor latches     
    U0DLM = 0x00;    // to set baud rate      
    U0DLL = 97;        // to set desired baud rate    
    U0LCR = 0x03;          // clears divisor latches after setting baud rate
}

int main(void) {
    unsigned char temp[] = "drive safe";
    int i;

    uart_init(); // Initialize UART

    for (i = 0; temp[i] != '\0'; i++) {
        transmit(temp[i]);//send the charac via uart
        delay(50);          
    }

    while (1){
        if ((IOPIN0 & (1 << 22)) == 0) {
            IOSET0 |= (1 << 19);
            IOCLR0 |= (1 << 7) | (1 << 8) | (1 << 9) | (1 << 10) | (1 << 11) | (1 << 12) | (1 << 13);

            // segment A //9
            IOSET0 |= (1 << 18);
            IOCLR0 |= (1 << 16);
            IOSET0 |= (1 << 25) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 5) | (1 << 6);
            IOCLR0 |= (1 << 4);
            delay(100);
					  

            // segment A //8
            IOSET0 |= (1 << 25) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6);
            delay(100);

            // segment A //7
            IOSET0 |= (1 << 25) | (1 << 1) | (1 << 2);
            IOCLR0 |= (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6);
            delay(100);

            // segment A //6
            IOSET0 |= (1 << 25) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6);
            IOCLR0 |= (1 << 1);
            delay(100);

            // segment A //5
            IOSET0 |= (1 << 25) | (1 << 2) | (1 << 3) | (1 << 5) | (1 << 6);
            IOCLR0 |= (1 << 1) | (1 << 4);
            delay(100);
            IOCLR0 |= (1 << 18);
            delay(100);

            // segment A //4
            IOSET0 |= (1 << 18) | (1 << 1) | (1 << 2) | (1 << 5) | (1 << 6);
            IOCLR0 |= (1 << 25) | (1 << 3) | (1 << 4);
            delay(100);
            IOCLR0 |= (1 << 18);
            delay(100);

            // segment A //3
            IOSET0 |= (1 << 18) | (1 << 14) | (1 << 25) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 6);
            IOCLR0 |= (1 << 4) | (1 << 5);
            delay(100);
            IOCLR0 |= (1 << 18) | (1 << 14);
            delay(100);

            // segment A //2
            IOSET0 |= (1 << 18) | (1 << 14) | (1 << 25) | (1 << 1) | (1 << 3) | (1 << 4) | (1 << 6);
            IOCLR0 |= (1 << 2) | (1 << 5);
            delay(100);
            IOCLR0 |= (1 << 18) | (1 << 14);
            delay(100);

            // segment A //1
            IOSET0 |= (1 << 18) | (1 << 14) | (1 << 1) | (1 << 2);
            IOCLR0 |= (1 << 25) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6);
            delay(100);
            IOCLR0 |= (1 << 18) | (1 << 14);
            delay(100);

            // segment A //0
            IOSET0 |= (1 << 18) | (1 << 14) | (1 << 25) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
            IOCLR0 |= (1 << 6);
            delay(100);
            IOCLR0 |= (1 << 18) | (1 << 14);
            delay(100);

            // YELLOW A
            IOSET0 |= (1 << 17);
            IOCLR0 |= (1 << 25) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6);
            delay(100);
            IOCLR0 |= (1 << 17) | (1 << 19);

            IOSET0 |= (1 << 16);  //redA
            IOCLR0 |= (1 << 25) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6);

            // SEGMENT B //9
            IOSET0 |= (1 << 21);//green
            IOCLR0 |= (1 << 15);
            IOSET0 |= (1 << 7) | (1 << 8) | (1 << 9) | (1 << 10) | (1 << 12) | (1 << 13);
            IOCLR0 |= (1 << 11);
            delay(100);

            // segment B //8
            IOSET0 |= (1 << 7) | (1 << 8) | (1 << 9) | (1 << 10) | (1 << 11) | (1 << 12) | (1 << 13);
            delay(100);

            // segment B //7
            IOSET0 |= (1 << 7) | (1 << 8) | (1 << 9);
            IOCLR0 |= (1 << 10) | (1 << 11) | (1 << 12) | (1 << 13);
            delay(100);

            // segment B //6
            IOSET0 |= (1 << 7) | (1 << 9) | (1 << 10) | (1 << 11) | (1 << 12) | (1 << 13);
            IOCLR0 |= (1 << 8);
            delay(100);

            // segment B //5
            IOSET0 |= (1 << 7) | (1 << 9) | (1 << 10) | (1 << 12) | (1 << 13);
            IOCLR0 |= (1 << 8) | (1 << 11);
            delay(100);
            IOCLR0 |= (1 << 21);
            delay(100);

            // segment B //4
            IOSET0 |= (1 << 21) | (1 << 8) | (1 << 9) | (1 << 12) | (1 << 13);
            IOCLR0 |= (1 << 7) | (1 << 10) | (1 << 11);
            delay(100);
            IOCLR0 |= (1 << 21);
            delay(100);

            // segment B //3
            IOSET0 |= (1 << 21) | (1 << 15) | (1 << 7) | (1 << 8) | (1 << 9) | (1 << 10) | (1 << 13);
            IOCLR0 |= (1 << 11) | (1 << 12);
            delay(100);
            IOCLR0 |= (1 << 21) | (1 << 15);
            delay(100);

            // segment B //2
            IOSET0 |= (1 << 21) | (1 << 15) | (1 << 7) | (1 << 8) | (1 << 10) | (1 << 11) | (1 << 13);
            IOCLR0 |= (1 << 9) | (1 << 12);
            delay(100);
            IOCLR0 |= (1 << 21) | (1 << 15);
            delay(100);

            // segment B //1
            IOSET0 |= (1 << 21) | (1 << 15) | (1 << 8) | (1 << 9);
            IOCLR0 |= (1 << 7) | (1 << 10) | (1 << 11) | (1 << 12) | (1 << 13);
            delay(100);
            IOCLR0 |= (1 << 21) | (1 << 15);
            delay(100);

            // segment B //0
            IOSET0 |= (1 << 21) | (1 << 15) | (1 << 7) | (1 << 8) | (1 << 9) | (1 << 10) | (1 << 11) | (1 << 12);
            IOCLR0 |= (1 << 13);
            delay(100);
            IOCLR0 |= (1 << 21) | (1 << 15);
            delay(100);

            // YELLOW B
            IOSET0 |= (1 << 20);
            IOCLR0 |= (1 << 7) | (1 << 8) | (1 << 9) | (1 << 10) | (1 << 11) | (1 << 12) | (1 << 13);
            delay(100);
            IOCLR0 |= (1 << 20) | (1 << 16);
        }
        else if ((IOPIN0 & (1 << 23)) == 0) {
            IOCLR0 = 0x023FFFFF;  // Clear all bits from 0 to 21a
        }
    }
		return 0;
}