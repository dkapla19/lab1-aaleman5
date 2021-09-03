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
#define ENABLE_EXAMPLE_V0 (0)
#define ENABLE_EXAMPLE_V1 (0)
#define ENABLE_EXAMPLE_V2 (0)
#define ENABLE_EXAMPLE_V3 (0)
#define ENABLE_EXAMPLE_V4 (1)

//Message Constraints
#define MAX_MESSAGES      ( 2)
#define MAX_MESSAGE_SIZE  (40)

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

#if ENABLE_EXAMPLE_V1 == (1)
//Example V1 Source Code

static char G_exampleStrings[MAX_MESSAGES][MAX_MESSAGE_SIZE] =
{
        "Hello World",
        "Hello Class"
}; /**< Global var to hold two strings */

/**
 * @brief Assigns exampleStringPtr to a global variable based on even/odd input value
 *
 * If `number` is even, then `exampleStringPtr` will be assigned to the string
 * at index 0 of the `G_exampleStrings` array
 *
 * If `number` is odd, then `exampleStringPtr` will be assigned to the string
 * at index 1 of the `G_exampleStrings` array
 *
 * @param int number - used to select which string to assign to exampleStringPtr
 * @param char **exampleStringPtr - pointer to a char*
 * @return void
 *
 */
void getExampleString_v1(int number, char **exampleStringPtr)
{
    if (number % 2 == 0){
        //even number
        *exampleStringPtr = G_exampleStrings[0]; //G_exampleStrings[0] is a pointer to a char* variable (a string in our case)
    }
    else{
        //odd number
        *exampleStringPtr = G_exampleStrings[1];
    }
    return;
}

/**
 * @brief Main entry point for Example v1
 *
 * Loops from startIndex and stopIndex calls getExampleString_v1 then prints a string
 *
 * This version stores multiple strings in a global multidimensional array
 *
 * @param startIndex
 * @param stopIndex
 * @return void
 *
 */
void do_example_v1(int startIndex, int stopIndex)
{
    char *exampleString = 0;
    int currentIndex;
    for(currentIndex = startIndex; currentIndex <= stopIndex; currentIndex++)
    {
        getExampleString_v1(currentIndex, &exampleString);
        printf("%s\n\r", exampleString);
    }

}
#endif

#if ENABLE_EXAMPLE_V2 == (1)
//Example V2 Source Code


/**
 * @brief data structure to hold messages
 *
 * Contains information on the number of string and the max messages allowed
 */
typedef struct {
    int maxMessages;  /**< Max number of messages allowd. */
    int numMessages;  /**< number of messages in the data structure */
    char messages[MAX_MESSAGES][MAX_MESSAGE_SIZE]; /** < 2d array of strings */
}messages_v2_t;


messages_v2_t G_msgInst_v2 = {
        MAX_MESSAGES, // maxMessages
        2,            // numMessages
        {   //messages
                "Hello World",
                "Hello Class"
        }
}; /**< Global var for the messages data struct */


/**
 * @brief Assigns exampleStringPtr to a global variable based on even/odd input value
 *
 * If `number` is even, then `exampleStringPtr` will be assigned to the string
 * at index 0 of the `G_msgInst_v2.messages` array
 *
 * If `number` is odd, then `exampleStringPtr` will be assigned to the string
 * at index 1 of the `G_msgInst_v2.messages` array
 *
 * @param int number - used to select which string to assign to exampleStringPtr
 * @param char **exampleStringPtr - pointer to a char*
 * @return void
 *
 */
char* getExampleString_v2(int number, char **exampleStringPtr)
{
    if (number % 2 == 0){
        //even number
        *exampleStringPtr = G_msgInst_v2.messages[0];

    }
    else{
        //odd number
        *exampleStringPtr = G_msgInst_v2.messages[1];
    }
    return *exampleStringPtr;
}

/**
 * @brief Main entry point for Example v2
 *
 * Loops from startIndex and stopIndex calls getExampleString_v2 then prints a string
 *
 * This version stores multiple strings in a global array of a structure
 *
 * @param startIndex
 * @param stopIndex
 * @return void
 *
 */
void do_example_v2(int startIndex, int stopIndex)
{
    int currentIndex;
    for(currentIndex = startIndex; currentIndex <= stopIndex; currentIndex++)
    {
        char *exampleString1 = 0;
        exampleString1 = getExampleString_v2(currentIndex, &exampleString1);
        printf("%s\n\r", exampleString1);
    }

}
#endif

#if ENABLE_EXAMPLE_V3 == (1)
//Example V3 Source Code

/**
 * @brief data structure to hold messages
 *
 * Contains information on the number of string and the max messages allowed
 */
typedef struct {
    int maxMessages;  /**< Max number of messages allowd. */
    int numMessages;  /**< number of messages in the data structure */
    char messages[MAX_MESSAGES][MAX_MESSAGE_SIZE]; /** < 2d array of strings */
}messages_v3_t;


/**
 * @brief Assigns exampleStringPtr to a global variable based on even/odd input value
 *
 * If `number` is even, then `exampleStringPtr` will be assigned to the string
 * at index 0 of the `msgInst->messages` array
 *
 * If `number` is odd, then `exampleStringPtr` will be assigned to the string
 * at index 1 of the `msgInst->messages` array
 *
 * @param messages_v3_t  *msgInst - pointer to struct containing messages
 * @param int number - used to select which string to assign to exampleStringPtr
 * @param char **exampleStringPtr - pointer to a char*
 * @return void
 *
 */
void getExampleString_v3(messages_v3_t *msgInst, int number, char **exampleStringPtr)
{
    if (number % 2 == 0){
        //even number
        *exampleStringPtr = msgInst->messages[0];
    }
    else{
        //odd number
        *exampleStringPtr = msgInst->messages[1];
    }
    return;
}

/**
 * @brief Main entry point for Example v2
 *
 * Declares local variable of type messages_v3_t to store messages.
 * Passed this variable to getExampleString_v3 when called.
 * Loops from startIndex and stopIndex calls getExampleString_v3 then prints a string
 *
 * @param startIndex
 * @param stopIndex
 * @return void
 *
 */
void do_example_v3(int startIndex, int stopIndex)
{

    messages_v3_t msgInst = {
            1, // maxMessages
            2, // numMessages
            {  //messages
                    "Hello World",
                    "Hello Class"
            }
    }; //local variable to contain messages

    int currentIndex;
    for(currentIndex = startIndex; currentIndex <= stopIndex; currentIndex++)
    {
        char *exampleString1 = 0;
        getExampleString_v3(&msgInst, currentIndex, &exampleString1); //pass pointer of msgInst
        printf("%s\n\r", exampleString1);
    }

}
#endif

#if ENABLE_EXAMPLE_V4 == (1)
//Example V4 Source Code

/**
 * @brief data structure to hold messages
 *
 * Contains information on the number of strings, the max messages allowed and max size of message
 */
typedef struct {
    int maxMessages;    /**< Max number of messages allowed. */
    int maxMessageSize; /**< Max size of message */
    int numMessages;    /**< number of messages in the data structure */
    char **messages;    /**< pointer of pointers (ie dynamic 2d array) */
}messages_v4_t;

/**
 * @brief Initialize messages_v4_t variable
 *
 * Allocate memory for the dynamic 2d array
 * @param messages_v4_t  *msgInst - pointer to struct containing messages
 * @param maxMessages - number of messages we can hold
 * @param maxMessageSize - max size of a message
 * @return status = 0 failed, 1 success
 */
int init_messages_v4(messages_v4_t* msgInst, int maxMessages, int maxMessageSize){
    int status = 1;//assume we are good

    msgInst->maxMessages    = maxMessages;
    msgInst->maxMessageSize = maxMessageSize;
    msgInst->numMessages    = 0;

    //References for allocating
    //https://web.archive.org/web/20170831232159/https://www.techiedelight.com/dynamically-allocate-memory-for-2d-array/
    //https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/

    //allocate memory for pointers to other areas - this is number of messages
    msgInst->messages = (char**)malloc(maxMessages*sizeof(char*));

    //loop through and create an areas for the message.  The above pointers will point to this memory
    for(int msgIndex = 0; msgIndex < maxMessages; msgIndex++){
        msgInst->messages[msgIndex] = (char*)malloc(maxMessageSize*sizeof(char));

        if(msgInst->messages == NULL){
            status = 0;
            break;
        }
    }

    return status;
}

/**
 * @brief Adds a message to a messages_v4_t type variable
 * Increments the number of messages stored internally
 *
 * @param messages_v4_t  *msgInst - pointer to struct containing messages
 * @param message - char array for the message to store
 * @return status = 0 failed, 1 success
 */
int addMessage_v4(messages_v4_t * msgInst, const char * message){
    int status = 0;

    if (msgInst->numMessages < msgInst->maxMessages){
    	status = 1; //we have enough room.. set status to ok

    	//copy the message over.
        strncpy(msgInst->messages[msgInst->numMessages], message, msgInst->maxMessageSize);

        msgInst->numMessages++;  //increment the count for number of messages stored
    }
    return status;
}


/**
 * @brief Assigns exampleStringPtr to a global variable based on even/odd input value
 *
 * If `number` is even, then `exampleStringPtr` will be assigned to the string
 * at index 0 of the `msgInst->messages` array
 *
 * If `number` is odd, then `exampleStringPtr` will be assigned to the string
 * at index 1 of the `msgInst->messages` array
 *
 * @param messages_v3_t  *msgInst - pointer to struct containing messages
 * @param int number - used to select which string to assign to exampleStringPtr
 * @param char **exampleStringPtr - pointer to a char*
 * @return void
 *
 */
int getExampleString_v4(messages_v4_t *msgInst, int number, char **exampleStringPtr)
{
    int status = 0;
    if (number % 2 == 0)
    {
        //even number
        *exampleStringPtr = msgInst->messages[0];
    }
    else
    {
        //odd number
        *exampleStringPtr = msgInst->messages[1];
    }

    return status;
}


/**
 * @brief Main entry point for Example v3
 *
 * Declares two local variable of type messages_v4_t to store messages.
 * Passes the two different variables to getExampleString_v4 when called.
 * Loops from startIndex and stopIndex calls getExampleString_v4 then prints a string
 *
 * @param startIndex
 * @param stopIndex
 * @return void
 *
 */
void do_example_v4(int startIndex, int stopIndex)
{
    int currentIndex;
    messages_v4_t msgInst_daytime;
    messages_v4_t msgInst_nighttime;

    int status = 0;
    status = init_messages_v4(&msgInst_daytime, MAX_MESSAGES,  MAX_MESSAGE_SIZE);
    if(status == 0){
        return;//fail silently for this example
    }

    status = init_messages_v4(&msgInst_nighttime, MAX_MESSAGES,  MAX_MESSAGE_SIZE);
    if(status == 0){
        return;//fail silently for this example
    }

    status = addMessage_v4(&msgInst_daytime, "Hello Day Time World");
    if(status == 0){
            return;//fail silently for this example
    }

    status = addMessage_v4(&msgInst_daytime, "Hello Day Time Class\0");
    if(status == 0){
            return;//fail silently for this example
    }

    status = addMessage_v4(&msgInst_nighttime, "Hello Night Time World\0");
    if(status == 0){
            return;//fail silently for this example
    }

    status = addMessage_v4(&msgInst_nighttime, "Hello Night Time Class\0");

    if(status == 0){
            return;//fail silently for this example
    }
    printf("\n\n\rmsgInst_daytime %d\n\n\r", msgInst_daytime.numMessages);

    for(currentIndex = startIndex; currentIndex <= stopIndex; currentIndex++)
    {
        char *exampleString1 = 0;
        char *exampleString2 = 0;

        //process with msgInst_daytime
        status = getExampleString_v4(&msgInst_daytime, currentIndex, &exampleString1);
        printf("%s\n\r", exampleString1);

        //process with msgInst_nighttime
        status = getExampleString_v4(&msgInst_nighttime, currentIndex, &exampleString2);
        printf("%s\n\r", exampleString2);
    }

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
