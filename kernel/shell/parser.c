#include "parser.h"
#include "string.h"
#include "commands.h"


ParsedCommand parse_command(char *input)
{
    ParsedCommand result;

    result.command = input;
    result.argument = 0;

    char *space = strchr(input, ' ');

    if (space)
    {
        *space = '\0';

        result.argument = space + 1;
    }

    return result;
}

void shell_parse(char *input)
{
    ParsedCommand cmd = parse_command(input);

    if (strcmp(cmd.command, "help"))
    {
        cmd_help();
    }
    else if (strcmp(cmd.command, "about"))
    {
        cmd_about();
    }
    else if (strcmp(cmd.command, "version"))
    {
        cmd_version();
    }
    else if (strcmp(cmd.command, "clear"))
    {
        cmd_clear();
    }
    else if (strcmp(cmd.command, "echo"))
    {
         cmd_echo(cmd.argument);
    }
    else
    {
        cmd_unknown();
    }
}
