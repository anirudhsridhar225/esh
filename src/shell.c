#include "include/shell.h"
#include <string.h>

#ifdef _WIN32
#include <lmcons.h>
#include <windows.h>
#else
#include <limits.h>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>
#endif /* ifdef _WIN32 */

char *get_prompt(char *prompt) {
    char hostname[1032];

#ifdef _WIN32
    DWORD size = sizeof(hostname);
    char username[UNLEN + 1];
    DWORD username_len = UNLEN + 1;

    if (!GetComputerName(hostname, &size)) {
        strcpy(hostname, "Unknown");
    }

    if (!GetUserName(username, &username_len)) {
        strcpy(username, "Unknown");
    }
#else
    struct passwd *p = getpwuid(geteuid());
    char username[1024];

    if (gethostname(hostname, sizeof(hostname)) != 0) {
        strcpy(hostname, "Unknown");
    }

    if (p) {
        strcpy(username, p->pw_name);
    } else {
        strcpy(username, "Unknown");
    }
#endif /* ifdef _WIN32 */

    strcat(prompt, "~> ");
    strcat(prompt, "[");
    strcat(prompt, hostname);
    strcat(prompt, "@");
    strcat(prompt, username);
    strcat(prompt, "] ");

    return prompt;
}

int handle_input(char *cmd) {}
