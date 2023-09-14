#include "cmdline.h"
#include "main.h"

int interpretCmd(string cmd) {
    if (cmd == "exit") {
        // set the global variable in main to false to end the game loop
        RUNNING = false;
    } else if (cmd == "new item") {

    } else {
        return 1;
    }

    return 0;
}