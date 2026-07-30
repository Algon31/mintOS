#include "memory.h"

void *memcpy(void *dest, const void *src, int n)
{
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    while (n--)
    {
        *d++ = *s++;
    }

    return dest;
}

void *memset(void *dest, int value, int n)
{
    unsigned char *d = (unsigned char *)dest;

    while (n--)
    {
        *d++ = (unsigned char)value;
    }

    return dest;
}

int memcmp(const void *a, const void *b, int n)
{
    const unsigned char *x = (const unsigned char *)a;
    const unsigned char *y = (const unsigned char *)b;

    while (n--)
    {
        if (*x != *y)
            return *x - *y;

        x++;
        y++;
    }

    return 0;
}
