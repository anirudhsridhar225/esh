#include <iostream>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main(int argc, char **argv) {

    int i = 1; // 1 indexed because i don't want the executable itself to be counted as one of the arguments

    while (true) {
        std::cout << argv[i++] << "\n";

        if (i >= argc) {
            break;
        }
    }

    return 0;
}