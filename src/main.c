#include "include/shell.h"
#include <stdio.h>
#include <stdlib.h>

const int width = 900;
const int height = 600;

int main() {
    printf("hello world\n");
    char *prompt = (char *)malloc(1024 * sizeof(char));
    prompt = get_prompt(prompt);

    printf("%s\n", prompt);
}
