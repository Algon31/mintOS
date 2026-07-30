#include "screen.h"
#include "keyboard.h"
#include "input.h"
#include "shell.h"

void kernel_main()
{
    clear_screen();

    print("====================================\n");
    print("        mintOS v0.1\n");
    print("====================================\n\n");

    print("> ");

    while (1)
    {
	char c = keyboard_get_char();

	if (!c)
	    continue;

	if (c == '\b')
	{
	    backspace();
	    input_backspace();
	}
	
	else if (c == '\n')
	{
	    print_char('\n');

	    input_submit();

	    if (input_is_ready())
	    {
	        shell_execute(input_get_buffer());
	        input_clear();
	    }
	}
	else
	{
	    print_char(c);
	    input_add_char(c);
	}
    }
}
