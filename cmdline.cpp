#include "cmdline.h"

int interpretCmd(string cmd) {
    if (cmd == "exit") {
        return -1;
    } else if (cmd == "new item") {
        
    } else {
        return 1;
    }

    return 0;
}