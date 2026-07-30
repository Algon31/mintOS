#ifndef PARSER_H
#define PARSER_H

typedef struct
{
    char *command;
    char *argument;
} ParsedCommand;

ParsedCommand parse_command(char *input);

void shell_parse(char *input);

#endif
