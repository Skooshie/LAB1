#include "mbed.h"
#include <cstdio>
//* Setup Digital Input to Detect Button Press*//


InterruptIn bluebtn(PC_13);
volatile int int_trig = 0;


void bttnFall(){
    int_trig = 1;
}

// main() runs in its own thread in the OS
int main()
{
// Setup the on board leds//

    DigitalOut led(LED1);
    DigitalOut led2(LED2);

    bluebtn.fall(&bttnFall);

    // This loop looks at the input and sends the output to print and the leds
    // The button press turns the led's on and off
    while (true) {
        if(int_trig == 1){
            int_trig = 0;
            printf("Blue Button Pressed \r\n");
           led = !led;
           led2 = !led2;
          
        }
    }
}