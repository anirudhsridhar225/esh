#include "include/shell.h"
#include <iostream>

int main(int argc, char** argv) {

    int i = 1; // 1 indexed because i don't want the executable itself to be
               // counted as one of the arguments

    std::string prompt = get_prompt();
    std::string cmd;

    while (true) {
        std::cout << prompt;
        int result = handle_input(cmd);

        if (result == -1)
            break;
    }

    return 0;
}
