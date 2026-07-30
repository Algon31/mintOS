#include "commands.h"
#include "screen.h"

void cmd_help()
{
    print("Available commands:\n");
    print("help\n");
    print("about\n");
    print("version\n");
    print("clear\n");
}

void cmd_about()
{
    print("mintOS\n");
    print("Written in C and Assembly.\n");
}

void cmd_version()
{
    print("mintOS v0.1\n");
}

void cmd_clear()
{
    clear_screen();
}

void cmd_echo(const char *text)
{
    print(text);
    print("\n");
}

void cmd_unknown()
{
    print("Unknown command.\n");
}
