#include "screen.h"

char* video = (char*) 0xB8000;

int row = 0;
int column = 0;

char color = 0x03;

static int get_offset(int row, int column)
{
    return (row * 80 + column) * 2;
}

void set_color(char new_color) {
    color = new_color;
}

void clear_screen()
{
    for (int r = 0; r < 25; r++)
    {
        for (int c = 0; c < 80; c++)
        {
            int offset = get_offset(r, c);

            video[offset] = ' ';
            video[offset + 1] = color;
        }
    }

    row = 0;
    column = 0;
}
void scroll_screen()
{
    for (int r = 1; r < 25; r++)
    {
        for (int c = 0; c < 80; c++)
        {
            int from = get_offset(r, c);
            int to = get_offset(r - 1, c);

            video[to] = video[from];
            video[to + 1] = video[from + 1];
        }
    }

    for (int c = 0; c < 80; c++)
    {
        int offset = get_offset(24, c);

        video[offset] = ' ';
        video[offset + 1] = color;
    }

    row = 24;
    column = 0;
}

void print_char(char c)
{
    if (c == '\n')
    {
        row++;
        column = 0;
        return;
    }

    int offset = get_offset(row, column);

    video[offset] = c;
    video[offset + 1] = color;

    column++;

    if (column >= 80)
    {
        column = 0;
        row++;
    }
    if (row >= 25)
	{
    		scroll_screen();
	}
}

void print(const char* str) {
	int i = 0;

    	while (str[i] != '\0')
    	{
        	print_char(str[i]);
        	i++;
    	}
}

void backspace()
{
    if (row == 0 && column == 0)
        return;

    if (column == 0)
    {
        row--;
        column = 79;
    }
    else
    {
        column--;
    }

    int offset = get_offset(row, column);

    video[offset] = ' ';
    video[offset + 1] = color;
}
