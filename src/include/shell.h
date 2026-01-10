//
// Created by anirudh on 12/23/25.
//

#ifndef SHELL_H
#define SHELL_H

// returns the prompt
char *get_prompt(char *prompt);

// reads input, executes command
// returns -1 if exit, 1 otherwise
int handle_input(char *cmd);

#endif // SHELL_H
