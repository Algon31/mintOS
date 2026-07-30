#ifndef MEMORY_H
#define MEMORY_H

void *memcpy(void *dest, const void *src, int n);

void *memset(void *dest, int value, int n);

int memcmp(const void *a, const void *b, int n);

#endif
