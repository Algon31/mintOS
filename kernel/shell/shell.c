#include "shell.h"
#include "parser.h"
#include "screen.h"

void shell_execute(char *command)
{
    print("\n");

    shell_parse(command);

    print("\n> ");
}
