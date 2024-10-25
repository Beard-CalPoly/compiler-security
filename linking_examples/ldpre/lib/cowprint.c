#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> /* for fork */
#include <sys/types.h> /* for pid_t */
#include <sys/wait.h> /* for wait */

char str[100];

int printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    vsnprintf(str, 100, format, args);

    pid_t pid=fork();
    if (pid==0) { // child process
        static char *argv[3];
        argv[0] = "cowsay";
        argv[1] = str;
        argv[2] = NULL;
        execv("/usr/games/cowsay",argv);
        exit(127); // only if execv fails
    }
    else { // pid!=0; parent process
        waitpid(pid,0,0); // wait for child to exit
    }

    va_end(args);
    return 0;
}
