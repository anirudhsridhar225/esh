//
// Created by anirudh on 12/23/25.
//

#ifndef SHELL_H
#define SHELL_H

#include <string>

// returns the prompt
std::string get_prompt();

// reads input, executes command
// returns -1 if exit, 1 otherwise
int handle_input(std::string& cmd);

#endif // SHELL_H
