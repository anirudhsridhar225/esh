#include "include/shell.h"
#include <stdio.h>
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
        strncpy(hostname, "Unknown", size);
    }

    if (!GetUserName(username, &username_len)) {
        strncpy(username, "Unknown", username_len);
    }
#else
    struct passwd *p = getpwuid(geteuid());
    char username[1024];

    if (gethostname(hostname, sizeof(hostname)) != 0) {
        strncpy(hostname, "Unknown", 1032);
    }

    if (p) {
        strncpy(username, p->pw_name, 1024);
    } else {
        strncpy(username, "Unknown", 1024);
    }
#endif /* ifdef _WIN32 */

    sprintf(prompt, "~> [%s@%s] ", hostname, username);

    return prompt;
}

int handle_input(char *cmd) {}
