#include "keyboard.h"
#include "ports.h"

static const char scancode_table[128] = {
    0,
    27,
    '1','2','3','4','5','6','7','8','9','0',
    '-','=',
    '\b',
    '\t',

    'q','w','e','r','t','y','u','i','o','p',
    '[',']',

    '\n',

    0,

    'a','s','d','f','g','h','j','k','l',
    ';','\'','`',

    0,

    '\\',

    'z','x','c','v','b','n','m',
    ',', '.', '/',

    0,

    '*',

    0,

    ' ',

};

char keyboard_get_char()
{
    unsigned char scancode = inb(0x60);

    // Ignore key release events
	if (scancode & 0x80)
        return 0;
	
	if (!(inb(0x64) & 1))
    	return 0;

	if (scancode >= 128)
        return 0;

    return scancode_table[scancode];
}
