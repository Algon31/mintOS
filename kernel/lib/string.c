#include "string.h"

int strlen(const char *str)
{
    int len = 0;

    while (str[len] != '\0')
    {
        len++;
    }

    return len;
}

int strcmp(const char *a, const char *b)
{
    while (*a && *b)
    {
        if (*a != *b)
            return 0;

        a++;
        b++;
    }

    return (*a == '\0' && *b == '\0');
}

char *strcpy(char *dest, const char *src)
{
    char *start = dest;

    while (*src)
    {
        *dest++ = *src++;
    }

    *dest = '\0';

    return start;
}

char *strncpy(char *dest, const char *src, int n)
{
    char *start = dest;

    while (*src && n--)
    {
        *dest++ = *src++;
    }

    *dest = '\0';

    return start;
}
char *strchr(const char *str, char ch)
{
    while (*str)
    {
        if (*str == ch)
        {
            return (char *)str;
        }

        str++;
    }

    return 0;
}

