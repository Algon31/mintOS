#ifndef INPUT_H
#define INPUT_H

void input_add_char(char c);
void input_backspace();

void input_submit();

int input_is_ready();

char* input_get_buffer();
void input_clear();

#endif
