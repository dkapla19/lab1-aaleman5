/*
 ============================================================================
 Name        : examples.c
 Author      : Andres Aleman
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>       //for printf
#include <stdlib.h>      //srand,rand
#include <string.h>      //for memcpy/strcpy
#include <unistd.h>      //for sleep
#include <time.h>        //for clock

#define ECLIPSE_FLUSH_FIX (1)  //Conditionally Disable Buffering print messages

//Conditionally include example source code
#define ENABLE_EXAMPLE_V0 (1)
#define ENABLE_EXAMPLE_V1 (0)
#define ENABLE_EXAMPLE_V2 (0)
#define ENABLE_EXAMPLE_V3 (0)
#define ENABLE_EXAMPLE_V4 (0)

/**** Function Prototypes ****/

/**
 *  Returns a random number between Lowest and Highest values (inclusive)
 */
int RandomInt(int Lowest, int Highest);

//Prototype for Example Functions
void do_example_v0(int startIndex, int stopIndex);
void do_example_v1(int startIndex, int stopIndex);
void do_example_v2(int startIndex, int stopIndex);
void do_example_v3(int startIndex, int stopIndex);
void do_example_v4(int startIndex, int stopIndex);

/**** Function Definitions ****/

int RandomInt(int Lowest, int Highest)
{
    srand(clock());
    return (rand() % (Highest-Lowest) + Lowest);
}

#if ENABLE_EXAMPLE_V0 == (1)
//Example V0 Source Code

/**
 * @brief Main entry point for Version 0 of our Example v0
 *
 * Loops from startIndex and stopIndex and prints "Hello World"
 *
 * @param startIndex
 * @param stopIndex
 * @return void
 *
 */
void do_example_v0(int startIndex, int stopIndex){
    while(startIndex <= stopIndex){
        printf("Hello World\n");
        startIndex++;
    }
    return;
}
#endif

int main(void) {

#if ECLIPSE_FLUSH_FIX == (1)
	//WARNING: This doesn't like it if you don't have a new line (ie \n)
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
#endif

   //Setup
   int startIndex = 0;
   int stopIndex  = 0;

   startIndex = RandomInt(0, 20);                //used as the seed for the functions
   stopIndex  = startIndex + RandomInt(1,5);     //end index for testing
   printf("startIndex = %d, stopIndex = %d", startIndex, stopIndex);

   while (1)
   {

#if ENABLE_EXAMPLE_V0 == (1)
       printf("\nExample v0\n\r");
       do_example_v0(startIndex, stopIndex);
#endif

#if ENABLE_EXAMPLE_V1 == (1)
       printf("\nExample v1\n\r");
       do_example_v1(startIndex, stopIndex);
#endif

#if ENABLE_EXAMPLE_V2 == (1)
       printf("\nExample v2\n\r");
       do_example_v2(startIndex, stopIndex);
#endif

#if ENABLE_EXAMPLE_V3 == (1)
       printf("\nExample v3\n\r");
       do_example_v3(startIndex, stopIndex);
#endif

#if ENABLE_EXAMPLE_V4 == (1)
       printf("\nExample v4\n\r");
       do_example_v4(startIndex, stopIndex);
#endif

       //throttle this down some for human debug
       sleep(1);
   }

   return EXIT_SUCCESS;
}
