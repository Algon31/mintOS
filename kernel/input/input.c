#include "input.h"

#define INPUT_SIZE 128

static char buffer[INPUT_SIZE];
static int index = 0;
static int ready = 0;

void input_add_char(char c)
{
    if (index >= INPUT_SIZE - 1)
        return;

    buffer[index++] = c;
}

void input_backspace()
{
    if (index > 0)
        index--;
}

int input_is_ready()
{
    return ready;
}

char* input_get_buffer()
{
    buffer[index] = '\0';
    ready = 0;
    return buffer;
}

void input_clear()
{
    index = 0;
    buffer[0] = '\0';
}

void input_submit()
{
    ready = 1;
}
